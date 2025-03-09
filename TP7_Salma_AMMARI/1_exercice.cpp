#include <iostream>
#include<string>
using namespace std;
class joueur{
public:
    std::string name;
    int score;
    void display(){
        cout<<"nom:"<<name<<","<<"score:"<<score<<endl;


    };

};

int main() {
    joueur Alice , Bob ;
    Alice.name="Alice";
    Alice.score=100;
    Bob.name="Bob";
    Bob.score=200;
    Alice.display();
    Bob.display();


    return 0;
}
