#include "movies.hpp"
#include "movie.hpp"
#include <iostream>
#include <string>

// Ajouter un film au vecteur
bool Movies::add_movie(std::string name, std::string rating, int watched) {
    for (const auto &movie : movies) {
        if (movie.get_name() == name) {
            std::cout << name << " existe déjà." << std::endl;
            return false;
        }
    }
    movies.push_back(Movie{name, rating, watched});
    std::cout << name << " ajouté" << std::endl;
    return true;
}

// Incrémenter le nombre de visionnages d'un film
bool Movies::increment_watched(std::string name) {
    for (auto &movie : movies) {
        if (movie.get_name() == name) {
            movie.increment_watched();
            return true;
        }
    }
    std::cout << name << " introuvable" << std::endl;
    return false;
}

// Afficher les informations de tous les films
void Movies::display() const {
    if (movies.size() == 0) {
        std::cout << "Aucun film à afficher" << std::endl;
        return;
    }
    for (const auto &movie : movies) {
        movie.display();
    }
}