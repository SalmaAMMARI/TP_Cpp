#include <iostream>
#include<string>
#include <vector>
using namespace std;


class Object{
private:
    int quantity ;
    std::string name;
public:
    Object(int n , std::string nom){
        quantity = n;
        name=nom;

    }
    void afficher(){
        cout<<"- "<<name <<"(x"<<quantity<<")"<<endl;
    }


};
class Inventaire{
private:
    std::vector<Object*> objects ;// vecteur contenant des pointeurs d=aux elements de type Object


public:
    //Methode pour ajouter un objet
    void ajouter(int n , std::string name){
        objects.push_back(new Object(n, name));
        cout<<"Ajout de :"<<name<<"(x"<<n<<")"<<endl;

    };
    void display(){
        cout<<"Inventaire:"<<endl;
        for (auto obj: objects){
            obj->afficher();
        };

    }

};

int main() {
    Inventaire inv;
    inv.ajouter(3,"Pomme");
    inv.ajouter(4,"Epee");
    inv.display();


    return 0;
}
