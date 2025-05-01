#include <iostream>
#include <fstream>
#include <iomanip> // Pour les manipulateurs de formatage

int main() {
    // Création et ouverture du fichier en mode écriture
    std::ofstream outputFile("output.txt");

    // Vérification que le fichier est bien ouvert
    if (!outputFile.is_open()) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier output.txt" << std::endl;
        return 1; // Quitte le programme avec un code d'erreur
    }

    std::cout << "Entrez des nombres flottants (une entrée vide pour terminer) :" << std::endl;

    float number;
    // Boucle de lecture des nombres depuis l'entrée standard
    while (std::cin >> number) {
        // Formatage et écriture dans le fichier :
        // - std::left : justification à gauche
        // - std::setw(10) : largeur de champ de 10 caractères
        // - std::fixed : notation fixe (pas de notation scientifique)
        // - std::setprecision(2) : précision de 2 décimales
        outputFile << std::left << std::setw(10) << std::fixed << std::setprecision(2) << number << std::endl;
    }



    // Fermeture du fichier
    outputFile.close();

    // Message de confirmation
    std::cout << "Les nombres ont ete enregistres dans output.txt avec succes." << std::endl;

    return 0;
}