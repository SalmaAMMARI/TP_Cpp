#include<vector>
#include<memory>
#include<iostream>
#include<string>
class PaireBase{
public:
    virtual ~PaireBase() = default;
    virtual void afficher() const =0;
};
template<typename T , typename U>
class Paire:public PaireBase{
protected:
    T premier ;
    U second ;
public:
    Paire(T p , U s):premier(p), second(s){};
    void afficher()const override{
        std::cout<<"Paire: ";
        afficherPrem();
        std::cout<<" ";
        afficherSec();
        std::cout<<std::endl;

    };
    virtual void afficherPrem()const{
        std::cout<<premier<<" , ";
    };
    virtual void afficherSec()const{
        if constexpr(std::is_same_v<U,bool>){
            std::cout<<(second? "vrai":"faux");
        }else{
            std::cout<<second;

        }
    }
};
//U=int
template <typename T>
class Paire<T , int>:public PaireBase{
protected:
    T premier;
    int second;
public:
    Paire(T p , int s):premier(p), second(p){};
    void afficher()const override {
        std::cout << "Paire avec type entier: ";
        afficherPrem();
        std::cout << " ," << second << " [entier]" << std::endl;

    };
    virtual void afficherPrem()const{
        std::cout<<premier;

    };
};
//use unique ptr to create paires
template<typename T , typename U>
std::unique_ptr<Paire<T ,U>> createPaire(T p, U s){
    return std::make_unique<Paire<T,U>>(p,s);

}
int main() {
   std::vector<std::unique_ptr<PaireBase>> paires;
    paires.push_back(std::make_unique<Paire<double, int>>(3.14, 42));
    paires.push_back(std::make_unique<Paire<int, bool>>(10, true));
    paires.push_back(std::make_unique<Paire<std::string, double>>("Test", 2.71));
    for (const auto &p: paires) {
        p->afficher();
    };
    return 0;
}