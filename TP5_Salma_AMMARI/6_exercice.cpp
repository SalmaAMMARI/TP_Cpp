//Exercie 5

#include <iostream>
using namespace std;
#include <regex>
#include <string>

// Déclaration d'un objet de type smatch pour stocker le résultat de la recherche regex
std::smatch match;

// Fonction qui vérifie si une chaîne contient une adresse email
bool contains_email(const std::string& text) {
    // Expression régulière pour détecter un email valide
    std::regex reg(R"([a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+)");

    // Recherche d'une correspondance dans le texte
    return std::regex_search(text, match, reg);
}

int main() {
    cout << "Entrer un texte: ";
    std::string text;

    // Lecture d'une ligne de texte entrée par l'utilisateur
    std::getline(std::cin, text);

    // Vérification de la présence d'une adresse email dans le texte
    if (contains_email(text)) {
        // Affichage de l'adresse email détectée
        cout << "Adresse mail détectée : " << match[0];
    } else {
        // Affichage d'un message si aucune adresse email n'est trouvée
        cout << "Aucune adresse n'est détectée";
    }

    return 0;
}
