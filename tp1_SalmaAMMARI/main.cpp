#include <iostream> //inclusion de la bibliothèque iostream
#define PI 3.14  // définition de la constante PI
#define DEBUG 1  //enlever le "//" avant define DEBUG PI si vous voulez tester le cas dont lequel DEBUG est définis


int main() {

    #ifdef DEBUG
        std::cout<<"The macro DEBUG is  define";
    #else
        std::cout<<"The macro DEBUG is not Defined";
    #endif

    return 0;
}
