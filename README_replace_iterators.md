# Démonstration: Remplacement de Mots avec les Itérateurs C++

## Vue d'ensemble
Ce projet démontre comment utiliser les **itérateurs C++** pour lire un fichier, trouver et remplacer des mots, puis écrire le résultat dans un nouveau fichier.

## Concepts clés des itérateurs utilisés

### 1. **Itérateurs de conteneur (`string::iterator`)**
```cpp
auto it = s.begin();        // Itérateur au début de la chaîne
auto end = s.end();         // Itérateur après le dernier caractère
while (it != end) { ... }   // Parcourir avec itérateurs
```

### 2. **Itérateurs de flux (`istreambuf_iterator`)**
Permet de lire un fichier entier en une ligne :
```cpp
// Lire un fichier avec des itérateurs de flux
ifstream in(infile, ios::binary);
string content((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
```

### 3. **Fonction `std::search()` avec itérateurs**
Cherche une séquence dans un intervalle d'itérateurs :
```cpp
auto found = search(it, s.end(), from.begin(), from.end());
if (found == s.end()) {
    // Pas trouvé
} else {
    // Trouvé à la position 'found'
}
```

## Fonction principale: `replace_all_using_iterators()`

```cpp
string replace_all_using_iterators(const string& s, const string& from, const string& to) {
    string result;
    auto it = s.begin();                          // Début de chaîne
    
    while (it != s.end()) {
        // Chercher le mot à partir de 'it'
        auto found = search(it, s.end(), from.begin(), from.end());
        
        if (found == s.end()) {
            // Pas de match: ajouter le reste du texte
            result.append(it, s.end());
            break;
        }
        
        // Ajouter le texte AVANT le match
        result.append(it, found);
        
        // Ajouter le remplacement
        result.append(to);
        
        // Avancer l'itérateur APRÈS le mot trouvé
        it = found + static_cast<std::ptrdiff_t>(from.size());
    }
    return result;
}
```

## Flux d'exécution

1. **Lire** le fichier d'entrée avec `istreambuf_iterator`
2. **Compter** les occurrences en parcourant avec `search()` et les itérateurs
3. **Remplacer** tous les mots trouvés avec `replace_all_using_iterators()`
4. **Écrire** le résultat dans le fichier de sortie

## Compilation et exécution

```bash
# Compilation
g++ -std=c++11 -Wall -o replace_iterators replace_iterators.cpp

# Exécution
./replace_iterators sample_input.txt output.txt "hello" "bonjour"
```

### Résultat test:
```
✓ Replaced 5 occurrences of 'hello' with 'bonjour'.

Fichier original:
  hello world! This is a simple file.
  We will replace the word hello by bonjour.
  hello again: hello hello.

Après remplacement:
  bonjour world! This is a simple file.
  We will replace the word bonjour by bonjour.
  bonjour again: bonjour bonjour.
```

## Avantages des itérateurs

✅ **Lecture efficace**: `istreambuf_iterator` lit le fichier en une passe  
✅ **Recherche précise**: `std::search()` avec itérateurs trouve exactement le mot  
✅ **Construction progressive**: `append()` avec itérateurs est efficace  
✅ **Code générique**: Fonctionne avec n'importe quel type de conteneur  
✅ **Pas de copies intermédiaires**: Directement dans `std::string`

## Concepts itérateurs couverts

| Concept | Utilisation |
|---------|------------|
| `begin()` / `end()` | Délimiter un intervalle |
| `std::search()` | Chercher une sous-séquence |
| `istreambuf_iterator` | Lire fichier efficacement |
| `append(it1, it2)` | Copier avec itérateurs |
| Arithmétique itérateur (`+`) | Avancer dans la séquence |
| Comparaison itérateur (`!=`, `==`) | Vérifier fin de séquence |

---

**Fichiers:**
- `replace_iterators.cpp` : le programme source
- `sample_input.txt` : fichier d'exemple
