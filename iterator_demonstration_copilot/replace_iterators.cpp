#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>

// Replace all occurrences of `from` by `to` using iterators
std::string replace_all_using_iterators(const std::string& s, const std::string& from, const std::string& to) {
    std::string result;
    std::string::const_iterator it = s.begin();
    while (it != s.end()) {
        std::string::const_iterator found = std::search(it, s.end(), from.begin(), from.end());
        if (found == s.end()) {
            result.append(it, s.end());
            break;
        }
        // append the chunk before the match
        result.append(it, found);
        // append the replacement
        result.append(to);
        // advance past the matched part
        it = found + static_cast<std::ptrdiff_t>(from.size());
    }
    return result;
}

int main(int argc, char** argv) {
    if (argc != 5) {
        std::cerr << "Usage: " << argv[0] << " <input> <output> <from> <to>\n";
        return 1;
    }

    std::string infile = argv[1];
    std::string outfile = argv[2];
    std::string from = argv[3];
    std::string to = argv[4];

    std::ifstream in(infile.c_str(), std::ios::binary);
    if (!in) {
        std::cerr << "Cannot open input file '" << infile << "'\n";
        return 2;
    }

    // Read entire file into a string using stream iterators
    const std::string content((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
    in.close();

    // Count occurrences using iterator-based search
    std::size_t count = 0;
    std::string::const_iterator it = content.begin();
    while (true) {
        std::string::const_iterator found = std::search(it, content.end(), from.begin(), from.end());
        if (found == content.end()) break;
        ++count;
        it = found + static_cast<std::ptrdiff_t>(from.size());
    }

    // Do the replacement (iterator-based)
    std::string out_content = replace_all_using_iterators(content, from, to);

    std::ofstream out(outfile.c_str(), std::ios::binary);
    if (!out) {
        std::cerr << "Cannot open output file '" << outfile << "'\n";
        return 3;
    }
    out << out_content;
    out.close();

    std::cout << "Replaced " << count << " occurrences of '" << from << "' with '" << to << "'.\n";
    return 0;
}
