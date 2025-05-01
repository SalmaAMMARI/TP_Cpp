#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class Livre {
private:
    std::string titre;
    int pages;

public:
    // Constructeur
    Livre(const std::string& t, int p) : titre(t), pages(p) {}

    // Accesseurs pour titre et pages
    std::string getTitre() const { return titre; }
    int getPages() const { return pages; }

    // Définition de l'opérateur << comme ami pour l'affichage
    friend std::ostream& operator<<(std::ostream& os, const Livre& livre) {
        os << livre.titre << " - " << livre.pages << " pages";
        return os;
    }
};

int main() {
    // Création d'un vecteur de livres avec des titres et des nombres de pages
    std::vector<Livre> livres = {
            Livre("C++ Moderne", 350),
            Livre("Apprendre Python", 500),
            Livre("Algorithmique", 450)
    };

    // Affichage initial des livres
    std::cout << "À partir des livres :\n";
    for (const auto& livre : livres) {
        std::cout << livre << std::endl;
    }

    // Tri du vecteur de livres selon le titre (ordre alphabétique)
    // et le nombre de pages (ordre décroissant)
    std::sort(livres.begin(), livres.end(), [](const Livre& a, const Livre& b) {
        // D'abord comparer les titres (ordre alphabétique)
        if (a.getTitre() == b.getTitre()) {
            // Si les titres sont égaux, trier par nombre de pages (ordre décroissant)
            return a.getPages() > b.getPages();
        }
        return a.getTitre() < b.getTitre(); // Comparaison lexicographique des titres
    });

    // Affichage après le tri
    std::cout << "\nTri par titre :\n";
    for (const auto& livre : livres) {
        std::cout << livre << std::endl;
    }

    // Affichage après tri par nombre de pages décroissant
    std::cout << "\nTri par nombre de pages décroissant :\n";
    std::sort(livres.begin(), livres.end(), [](const Livre& a, const Livre& b) {
        return a.getPages() > b.getPages();
    });

    for (const auto& livre : livres) {
        std::cout << livre << std::endl;
    }

    return 0;
}

