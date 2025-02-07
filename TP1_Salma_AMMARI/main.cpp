#include <iostream> //inclusion de la bibliothèque iostream
#define PI 3.14  // définition de la constante PI
#define DEBUG 1  //enlever le "//" avant "define DEBUG PI "si vous voulez tester l'autre cas

#ifndef EXO
#define EXO 6
#endif
namespace salma{
    int age=19;
}
int main(int argc, char* argv[]) {
    #if EXO==1
        //Exercice1:Utilisation des directives du préprocesseur
        #ifdef DEBUG
            std::cout<<"The macro DEBUG is  defined"<<std::endl;
        #else
            std::cout<<"The macro DEBUG is not Defined";
        #endif
    #elif EXO==2
        //Exercice 2:Utilisation de la fonction main
       
        if (argc > 1) {
            // Afficher les arguments passés en ligne de commande
            for (int i = 1; i < argc; ++i) {
                std::cout << "Argument " << i << ": " << argv[i] << std::endl;
            }
        } else {
            std::cout << "No arguments passed" << std::endl;
        }
    #elif EXO==3
        //Eexercice3:
        //sans utiliser "using namespace"
        std::cout<<"I am "<<salma::age<<" years old"<<std::endl;
        //Avec utilisation de 'using namespace'
        using namespace salma ;
        std::cout<<"I am "<<age<<" years old"<<std::endl;
    #elif EXO==4
        // Demander à l'utilisateur d'entrer un entier
        std::cout << "entrer un entier:" << std::endl;
        int entier; // Variable pour stocker l'entier
        std::cin>>entier;
        // Demander à l'utilisateur d'entrer un nombre décimal
        std::cout << "entrer un decimal:" << std::endl;
        double decimal;  // Variable pour stocker le nombre décimal 
        std::cin>>decimal;
        // Afficher les valeurs saisies
        std::cout<<"valeurs saisies "<<entier<<" et "<<decimal<<std::endl;
        

        

   
    
    #else
    #error 'Veuillez définir EXO  à1 , 2,3 ou 4 (exemple: -DEXO=1 , -DEXO=2)'
    #endif
    return 0;







    
}
