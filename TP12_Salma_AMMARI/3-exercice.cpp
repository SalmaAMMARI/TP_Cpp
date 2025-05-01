#include <iostream>
#include <fstream>
#include <string>

void printFile(const std::string& filename) {
    std::ifstream file(filename);
    std::cout << "\nContenu de " << filename << ":\n";
    std::cout << "----------------------------------------\n";
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << "\n";
    }
    std::cout << "----------------------------------------\n";
}

int main() {
    // 1. Création de input.txt , avec mot secret pour l utilisier comme keyword
    {
        std::ofstream inputFile("input.txt");
        inputFile << "Première ligne standard\n"
                  << "Ligne avec le mot SECRET\n"
                  << "Une autre ligne banale\n"
                  << "SECRET trouve encore\n"
                  << "Dernière ligne\n";
    }

    //  Demande du mot-clé
    std::string keyword;
    std::cout << "Entrez le mot-clé à filtrer: ";
    std::getline(std::cin, keyword);

    //  copie
    {
        std::ifstream inFile("input.txt");
        std::ofstream outFile("output.txt");

        std::string line;
        int count = 0;

        while (std::getline(inFile, line)) {
            if (line.find(keyword) != std::string::npos) {
                outFile << line << "\n";
                count++;
            }
        }

        std::cout << count << " lignes avec '" << keyword << "' ont été copiées.\n";
    }

    // 4. Affichage des fichiers
    printFile("input.txt");
    printFile("output.txt");

    return 0;
}