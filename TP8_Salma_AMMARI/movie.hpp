#ifndef MOVIE_H
#define MOVIE_H

#include <string>

class Movie {
private:
    std::string name;
    std::string rating;
    int watched;

public:
    // Constructeur
    Movie(std::string name, std::string rate, int watched);

    // Setters
    void set_name(std::string nom);
    void set_rating(std::string rate);
    void set_watched(int watch);

    // Getters
    std::string get_name() const;
    std::string get_rating() const;
    int get_watched() const;

    // Incrémenter le nombre de visionnages
    void increment_watched();

    // Afficher les informations du film
    void display() const;
};

#endif // MOVIE_H