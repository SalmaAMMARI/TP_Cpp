#include <iostream>
#include <vector>
#include <algorithm>

// Définition du foncteur Additionneur
class Additionneur {
private:
    int valeur; // Attribut privé

public:
    // Constructeur
    Additionneur(int v) : valeur(v) {}

    // Surcharge de l'opérateur ()
    void operator()(int x) const {
        std::cout << (x + valeur) << " ";
    }
};

int main() {
    std::vector<int> vecteur{1, 2, 3, 4, 5};

    // Application du foncteur avec std::for_each
    std::for_each(vecteur.begin(), vecteur.end(), Additionneur(10));

    std::cout << std::endl;
    return 0;
}
