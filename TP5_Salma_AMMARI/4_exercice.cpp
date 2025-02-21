//Exercice 4
#include <iostream>
#include <unordered_map>  // Pour utiliser std::unordered_map (table de hachage)
#include <vector>         // Pour stocker les mots et leurs fréquences sous forme de paires
#include <algorithm>      // Pour trier les mots par fréquence
#include <sstream>        // Pour manipuler le texte et extraire les mots

// Fonction qui trouve les 3 mots les plus fréquents dans un texte donné
void top_frequent_words(const std::string& text) {
    // Déclaration d'une table de hachage (unordered_map) pour stocker la fréquence des mots
    std::unordered_map<std::string, int> freq;

    // Création d'un flux pour lire les mots du texte un par un
    std::istringstream iss(text);
    std::string word;

    // Parcours du texte et comptage de la fréquence de chaque mot
    while (iss >> word) {
        freq[word]++; // Incrémente la fréquence du mot
    }

    // Conversion de la table de hachage en un vecteur de paires (mot, fréquence)
    std::vector<std::pair<std::string, int>> sorted_words(freq.begin(), freq.end());

    // Tri du vecteur par ordre décroissant de fréquence
    std::sort(sorted_words.begin(), sorted_words.end(), [](const auto& a, const auto& b) {
        return a.second > b.second; // Trie par fréquence décroissante
    });

    // Affichage des 3 mots les plus fréquents
    std::cout << "Top 3 mots les plus fréquents :\n";
    for (int i = 0; i < 3 && i < sorted_words.size(); i++) {
        std::cout << sorted_words[i].first << " -> " << sorted_words[i].second << "\n";
    }
}

int main() {
    std::cout << "Entrer un texte: ";

    // Lecture d'une ligne de texte entrée par l'utilisateur
    std::string str;
    std::getline(std::cin, str);

    // Appel de la fonction pour afficher les mots les plus fréquents
    top_frequent_words(str);

    return 0;
}
