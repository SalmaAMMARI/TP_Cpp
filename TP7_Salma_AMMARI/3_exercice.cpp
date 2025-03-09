#include <iostream>
#include <string>
using namespace std;
class joueur{
private:
    int score ;
    std::string name;
public:
    joueur(int n , std::string nom){
        cout<<"constructeur appelé"<<endl;

        score=n;
        name=nom;



    };
    void display(){
        cout<<"nom:"<<name<<" , score:"<<score<<endl;
    };
    ~joueur(){
        cout<<"deconstructeur appelé";
    };

};

int main() {
    joueur Alice(100 , "Alice");
    Alice.display();
    return 0;
}
