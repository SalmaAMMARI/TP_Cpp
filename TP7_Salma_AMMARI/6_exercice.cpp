#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Fichier {
private:
    fstream* flux;  // Pointeur vers un flux de fichier
    string nomFichier;

public:
    // Constructeur
    Fichier(const string& nom) {
        nomFichier = nom;
        flux = nullptr;  // Initialise le pointeur à nullptr
    }

    // Méthode pour sauvegarder des données dans le fichier
    void sauvegarder(const string& contenu) {
        cout << "Sauvegarde des données..." << endl;
        flux = new fstream(nomFichier, ios::out);  // Ouvrir en écriture

        if (flux->is_open()) {
            *flux << contenu;  // Écrire le contenu dans le fichier
            flux->close();
        } else {
            cout << "Erreur lors de l'ouverture du fichier en écriture !" << endl;
        }

        delete flux;  // Libérer la mémoire
        flux = nullptr;
    }

    // Méthode pour charger et afficher les données du fichier
    void charger() {
        cout << "Lecture des données..." << endl;
        flux = new fstream(nomFichier, ios::in);  // Ouvrir en lecture

        if (flux->is_open()) {
            cout << "Contenu du fichier : " << endl;
            string ligne;
            while (getline(*flux, ligne)) {
                cout << ligne << endl;  // Afficher chaque ligne
            }
            flux->close();
        } else {
            cout << "Erreur lors de l'ouverture du fichier en lecture !" << endl;
        }

        delete flux;  // Libérer la mémoire
        flux = nullptr;
    }

    // Destructeur
    ~Fichier() {

        delete flux;
        cout << "Mémoire du flux libérée." << endl;

    }
};

// Fonction principale
int main() {
    Fichier fichier("test.txt");

    // Sauvegarde du contenu dans le fichier
    fichier.sauvegarder("Bonjour, ceci est un test.");

    // Lecture du fichier et affichage du contenu
    fichier.charger();

    return 0;
}
