#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>

using namespace std;

// Replace all occurrences of `from` by `to` using iterators
string replace_all_using_iterators(const string& s, const string& from, const string& to) {
    string result;
    auto it = s.begin();
    while (it != s.end()) {
        auto found = search(it, s.end(), from.begin(), from.end());
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
        cerr << "Usage: " << argv[0] << " <input> <output> <from> <to>\n";
        return 1;
    }

    string infile = argv[1];
    string outfile = argv[2];
    string from = argv[3];
    string to = argv[4];

    ifstream in(infile, ios::binary);
    if (!in) {
        cerr << "Cannot open input file '" << infile << "'\n";
        return 2;
    }

    // Read entire file into a string using stream iterators
    string content((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
    in.close();

    // Count occurrences using iterator-based search
    size_t count = 0;
    auto it = content.begin();
    while (true) {
        auto found = search(it, content.end(), from.begin(), from.end());
        if (found == content.end()) break;
        ++count;
        it = found + static_cast<std::ptrdiff_t>(from.size());
    }

    // Do the replacement (iterator-based)
    string out_content = replace_all_using_iterators(content, from, to);

    ofstream out(outfile, ios::binary);
    if (!out) {
        cerr << "Cannot open output file '" << outfile << "'\n";
        return 3;
    }
    out << out_content;
    out.close();

    cout << "Replaced " << count << " occurrences of '" << from << "' with '" << to << "'.\n";
    return 0;
}
