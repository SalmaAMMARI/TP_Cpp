#include <iostream> //inclusion de la bibliothèque iostream
#include <limits> //on va l'utiliser pour accéder au limite maximale de la classe int
using namespace std ;
#define pi  3.14159
#ifndef EXO
#define EXO 1
#endif


//Exercice 3:définition de la fonction  constexpr factorielle récursive
constexpr double factorielle(int n){
    if (n==0 || n==1){
        return 1;
    } else {
        return n*factorielle(n-1);
    }
}
// utilisation de static_assert pour vérifier si le factoriel de 5 est 120 ,
//role de static assert (condition , error): si la condition est fausse il retourne l'erreur
static_assert(factorielle(5) == 120, "Erreur: Factorielle de 5 incorrecte !");

//Exercice 4: déclaration d'une variable globale
int value =100;
//Exercice 6: déclaration de la fonction safeMultiply()
int safeMultiply(int a, int b) {
    // Vérification d'overflow avant la multiplication
    //L'intéret de toutes ces conditions est de vérifier d'abord si me produit dépasse le max qu'un int peut représenter
    //pour ça on doit distinguer entre les 4 cas possibles selon le signe de chaque int
    if (a > 0 && b > 0 && a > numeric_limits<int>::max() / b) {
        cout << "Erreur : un Overflow !" << endl;
        return -1;
    }
    if (a > 0 && b < 0 && b < numeric_limits<int>::min() / a) {
        cout << "Erreur : un Overflow !" << endl;
        return -1;
    }
    if (a < 0 && b > 0 && a < numeric_limits<int>::min() / b) {
        cout << "Erreur : un Overflow !" << endl;
        return -1;
    }
    if (a < 0 && b < 0 && a < numeric_limits<int>::max() / b) {
        cout << "Erreur : un overflow !" << endl;
        return -1;
    }

    return a * b;
}
int main() {
#if EXO==1
    // Exercice 1:Analyse de la mémoire d’un tableau
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    //Affichage de taille totale du tableau en octets en utilisant l'opérateur sizeof
    cout<<"Taille totale du tableau est : "<<sizeof(arr)<<" octet(s)"<<endl;
    cout<<"La taille d'un élément est : "<<sizeof(arr[0])<<" octet(s)"<<endl;
    cout<<"Le nombre d'éléments du tableau est : "<<sizeof(arr)/sizeof(arr[0])<<endl;




#elif EXO==2
    //Exercice 2:Estimation pour le service de nettoyage de tapis
    cout<<"Enter the number of small pieces then the number of large pieces to clean:"<<endl;
    int small;
    int large ;
    cin>>small;
    cin>>large;
    cout<<"Number of small rooms: "<<small<<endl;
    cout<<"Number of large rooms:  "<<large<<endl;
    cout<<"Price per small room: 250dhs "<<endl;
    cout<<"Price per large room: 350ds "<<endl;
    double cost =(small*250 +350*large );
    double tax= 0.6*cost;
    double total = 1.6*cost;
    cout<<"Cost: "<<cost<<"dh"<<endl;
    cout<<"Tax: "<<tax<<"dh"<<endl;
    cout<<"=================================="<<endl;
    cout<<"Total estimate: "<<total<<"dhs"<<endl;
    cout<<"This estimate is valid for 30 days";






#elif EXO==3
    //Exercice 3: Calcul de la factorielle à la compilation avec constexpr

    constexpr int N = 5;
    constexpr long long factoN= factorielle(N); //définition d'une compiletime constant
    //Affichage de la factorielle calculée
    cout<<"Le factoriel de "<<N<<" est : "<<factoN<<endl;




#elif EXO==4
    //Exercice 4: Variables Globales et Locales (Shadowing)
    int value =50;
    //Affichae de la valeur locale
    cout<<"La valeur locale est: "<<value<<endl;
    //Affichage de la valeur globale avec l'opérateur ::
    cout<<"La valeur globale est: "<<::value<<endl;
    


#elif EXO==5
    //Exercice 5: Utilisation avancée des constantes
    const int mois = 12 ;
    constexpr float rayon = 7.0;
    double aire = pi*rayon*rayon;
    //mois=13;
    //rayon=12.0;
    cout<<"Nombre de mois dans cette année: "<<mois<<endl;
    cout<<"Rayon du cercle: "<<rayon<<endl;
    cout<<"Aire du cercle: "<<aire<<endl;





#elif EXO==6
    //Exercice 6 : Détection d’overflow lors d’une multiplication
    int a = 30000, b = 1000;
    int x = 300000, y = 10000;
    cout << "Test 1: " << a<< " * " << b << " = ";
    int result1 = safeMultiply(a, b);
    if (result1 != -1) cout << result1 << endl;

    cout << "Test 2: " << x << " * " << y << " = ";
    int result2 = safeMultiply(x, y);
    if (result2 != -1) cout << result2 << endl;






    #else
    #error 'Veuillez définir EXO  à1 , 2,3 ou 4 (exemple: -DEXO=1 , -DEXO=2)'
#endif
    return 0;
}