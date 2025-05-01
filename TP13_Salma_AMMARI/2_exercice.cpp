#include<iostream>
#include<functional>
#include<vector>
void filtrage(std::vector<int> lista, std::function<bool(int)>fct){
    for (auto& it :lista){
        if (fct(it)){
            std::cout<<it<<" ";
        }

    }
    std::cout<<std::endl;

}

int main(){
    std::vector lista = {10,15,20,25,30,50,75};
    auto fct = [](int x){return x>20;};
    auto fct1 = [](int x){return x%2==0;};
    filtrage(lista , fct);
    filtrage(lista , fct1);
    return 0;
}