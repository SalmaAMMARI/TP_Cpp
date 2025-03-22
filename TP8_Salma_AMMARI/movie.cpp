#include "movie.hpp"
#include <string>
#include <iostream>

// Constructeur
Movie::Movie(std::string name, std::string rate, int watched)
    : name{name}, rating{rate}, watched{watched} {}

// Setters
void Movie::set_name(std::string nom) {
    name = nom;
}

void Movie::set_rating(std::string rate) {
    rating = rate;
}

void Movie::set_watched(int watch) {
    watched = watch;
}

// Getters
std::string Movie::get_name() const {
    return name;
}

std::string Movie::get_rating() const {
    return rating;
}

int Movie::get_watched() const {
    return watched;
}

// Incrémenter le nombre de visionnages
void Movie::increment_watched() {
    ++watched;
}

// Afficher les informations du film
void Movie::display() const {
    std::cout << name << ", " << rating << ", " << watched << std::endl;
}