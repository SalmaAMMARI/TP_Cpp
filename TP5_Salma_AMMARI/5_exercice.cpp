#include <iostream>
#include <map>        // Pour utiliser std::multimap
#include <sstream>    // Pour utiliser std::istringstream

// Fonction qui trie les mots d'un texte par leur longueur
void sort_by_length(const std::string& text) {
    // Déclaration d'un multimap qui associe la longueur du mot au mot lui-même
    std::multimap<int, std::string> map;

    // Création d'un flux de lecture à partir de la chaîne d'entrée
    std::istringstream stream(text);
    std::string word;

    // Extraction des mots un par un
    while (stream >> word) {
        // Insertion dans le multimap avec la longueur du mot comme clé
        map.insert({word.size(), word});
    }

    // Affichage des mots triés par longueur
    std::cout << "Tri par longueur : ";
    for (const auto& pair : map) {
        std::cout << pair.second << " ";
    }
    std::cout << "\n";
}

int main() {
    std::cout << "Entrer un texte: ";

    // Déclaration d'une chaîne pour stocker l'entrée utilisateur
    std::string str;
    std::getline(std::cin, str); // Lecture d'une ligne complète de texte

    // Appel de la fonction de tri
    sort_by_length(str);

    return 0;
}