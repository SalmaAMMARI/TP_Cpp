#include<iostream>
#include<vector>
#include<algorithm>

int main(){
    auto fct = [](int x){return x+5;};
    std::vector<int> lista = {10,12,15,17};
    std::transform(lista.begin(), lista.end(), lista.begin(), fct);
    for (auto & it:lista){
        std::cout<<it<<" ";
    }
return 0;

}