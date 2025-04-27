#include<vector>
#include<iostream>
template<typename T>
class Conteneur{
private :
    std::vector<T> vecteur;
int length_max;
public:
    Conteneur(int capacity):length_max(capacity){};
    void ajouter(const T& element){
        if (vecteur.size()<length_max){
            vecteur.push_back(element);
        }else{
            std::cerr << "Erreur: Capacite maximale atteinte (" << length_max
                      << "). Impossible d'ajouter l'element." << std::endl;
        }
    };
    T obtenir(int indice)const{
        return vecteur.at(indice);
    }
};
int main() {
    Conteneur<int> c1(3); // Capacité de 3
    c1.ajouter(10);
    c1.ajouter(20);
    c1.ajouter(30);
    c1.ajouter(40); // Capacité dépassée
    std::cout << c1.obtenir(0) << " " << c1.obtenir(1) <<" "<<c1.obtenir(2)<<" "<< std::endl; // Affiche 10 20 30
    Conteneur<std::string> c2(2);
    c2.ajouter("Bonjour");
    c2.ajouter("Monde");
    std::cout << c2.obtenir(0) << " " << c2.obtenir(1) << std::endl; // Affiche Bonjour Monde
    return 0;
}
