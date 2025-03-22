#include <iostream>
#include "movies.hpp"

int main() {
    Movies movies;
    movies.display();
    std::cout << "=====================================" << std::endl;

    movies.add_movie("Big", "PG-13", 2);
    movies.add_movie("Star Wars", "PG", 5);
    movies.add_movie("Cendrillon", "PG", 7);

    std::cout << "=====================================" << std::endl;
    movies.display();
    std::cout << "=====================================" << std::endl;

    movies.add_movie("Cendrillon", "PG", 7);
    movies.add_movie("L'Âge de glace", "PG", 12);

    std::cout << "=====================================" << std::endl;
    movies.display();
    std::cout << "=====================================" << std::endl;

    movies.increment_watched("Big");
    movies.increment_watched("L'Âge de glace");

    std::cout << "=====================================" << std::endl;
    movies.display();
    std::cout << "=====================================" << std::endl;

    movies.increment_watched("XXX");

    return 0;
}