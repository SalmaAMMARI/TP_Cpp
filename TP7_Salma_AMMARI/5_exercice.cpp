#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Etudiant {
private:
    vector<double> notes;
    string name;

public:
    // Constructeur
    Etudiant(string nom, vector<double> notess) {
        name = nom;
        notes = notess;
    }

    // Calcul de la moyenne
    double moyenne() {
        int size = notes.size();
        if (size == 0) return 0;  // Éviter une division par zéro
        double moy = 0;
        for (auto note : notes) {
            moy += note;
        }
        return moy / size;
    }

    // Affichage des informations de l'étudiant
    void display() {
        cout << "Nom: " << name << endl;
        cout << "Notes: ";
        for (auto note : notes) {
            cout << note << " , ";
        }
        cout << "\nMoyenne: " << moyenne() << endl;
    }
};

int main() {
    // Initialisation d'une instance avec un nom et une liste de notes
    vector<double> notesEtudiant = {15,18,12};
    Etudiant etu("Karim", notesEtudiant);

    // Affichage des informations de l'étudiant
    etu.display();

    return 0;
}
