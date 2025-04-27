#include<iostream>
#include<string>
template <typename T>
T maximum(T a , T b){
    return (a>b)?a:b;
}
template <>
std::string maximum(std::string a , std::string b ){
    return (a.compare(b)>0)?a:b;
}
int main() {
    std::cout << maximum(5, 10) << std::endl; //  10
    std::cout << maximum(3.14, 2.74) << std::endl; // 3.14
   std::cout << maximum(std::string("abc"), std::string("az")) << std::endl; // az
    return 0;
}
