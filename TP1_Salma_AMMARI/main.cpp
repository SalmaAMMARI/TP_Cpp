#include <iostream> //inclusion de la bibliothèque iostream


#ifndef EXO
#define EXO 1
#endif
int main() {
    #if EXO==1
    //Eexrcice1:Affichage d’un message
     std::cout << "Hello, World!" << std::endl; 
    // Affiche "Hello, World!" suivi d'un retour à la ligne

    std::cout << "Welcome to C++";
        
    #elif EXO==2
        //Exercice 2:Lecture et affichage d’un entier
        int nombre; // Déclaration d'une variable pour stocker le nombre

        // Demande à l'utilisateur d'entrer un nombre
        std::cout << "Entrez un nombre: ";  
        std::cin >> nombre; // Lecture de l'entrée utilisateur

        // Affichage du nombre entré
        std::cout << "Vous avez entré: " << nombre << std::endl;
    #elif EXO==3
        //Exercice3:Opérations mathématique
        double nombre1, nombre2; // Déclaration de deux variables pour stocker les nombres

        // Demande à l'utilisateur d'entrer deux nombres
        std::cout << "Entrez deux nombres: ";
        std::cin >> nombre1 >> nombre2; 

        // Calcul des opérations demandées
        double somme = nombre1 + nombre2;
        double difference = nombre1 - nombre2;
        double produit = nombre1 * nombre2;

        // Affichage des résultats
        std::cout << "Somme: " << somme << std::endl;
        std::cout << "Différence: " << difference << std::endl;
        std::cout << "Produit: " << produit << std::endl;

        // Vérification si le deuxième nombre est différent de zéro avant la division
        if (nombre2 != 0) {
            double quotient = nombre1 / nombre2;
            std::cout << "Quotient: " << quotient << std::endl;
        } else {
            std::cout << "Erreur : Division par zéro impossible." << std::endl;
        }
    #elif EXO==4
    //Exercice 4:
    std::cout << "Entrez un nombre: "; // Ajout du guillemet fermant et du point-virgule
    int nombre; // Déclaration de la variable nombre
    std::cin >> nombre; // Lecture du nombre saisi par l'utilisateur

    std::cout << "Vous avez entré: " << nombre << std::endl; // Ajout du point-virgule
    #elif EXO==5
    //Exercice 5 : Conversion de température   
    double celsius;

    // Demande à l'utilisateur d'entrer une température en Celsius
    std::cout << "Entrez une température en Celsius: ";
    std::cin >> celsius; // Lecture de l'entrée utilisateur

    // Conversion de la température en Fahrenheit
    double fahrenheit = (9.0 / 5.0) * celsius + 32;

    // Affichage du résultat
    std::cout << "Température en Fahrenheit: " << fahrenheit << std::endl;     

        

   
    
    #else
    #error 'Veuillez définir EXO  à1 , 2,3 ou 4 (exemple: -DEXO=1 , -DEXO=2)'
    #endif
    return 0;
}

