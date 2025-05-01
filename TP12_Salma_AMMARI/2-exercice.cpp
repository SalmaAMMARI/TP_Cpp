#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

int main() {
    // 1. Création de data.txt
    {
        std::ofstream dataFile("data.txt");
        dataFile << "Alice 30 50000.50\n"
                 << "Bob 25 42000.75\n"
                 << "Charlie 35 38000.00\n"
                 << "Diana 40 65000.00\n";
    }

    // 2. Génération du rapport
    {
        std::ifstream inFile("data.txt");
        std::ofstream outFile("report.txt");

        // En-tête du rapport
        outFile << std::left
                << std::setw(15) << "Nom"
                << std::setw(10) << "Age"
                << std::setw(15) << "Salaire" << "\n"
                << std::string(40, '-') << "\n";

        std::string line;
        while (std::getline(inFile, line)) {
            std::istringstream iss(line);
            std::string nom;
            int age;
            double salaire;

            if (iss >> nom >> age >> salaire) {
                outFile << std::left << std::setw(15) << nom
                        << std::setw(10) << age
                        << std::fixed << std::setprecision(2)
                        << std::setw(15) << salaire << "\n";
            }
        }
    }

    // 3. Affichage du contenu de report.txt
    std::cout << "\nContenu du rapport:\n";
    std::cout << "-----------------\n";

    std::ifstream reportFile("report.txt");
    std::string reportLine;
    while (std::getline(reportFile, reportLine)) {
        std::cout << reportLine << "\n";
    }

    std::cout << "\nOpération terminée avec succès!\n";
    return 0;
}