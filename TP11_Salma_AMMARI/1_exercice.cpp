#include<iostream>
#include<stdexcept>
#include<string>
//classe d'exception pour la division par zéro qui hérite de la classe exception
class DivideByZeroException:public std::exception{
public:
    const char* what() const noexcept override{
        return "Erreur:Division by Zero!!!";

    }
};
//INvalide operation erreur
class InvalidOperationException: public std::exception{
public:
    const char* what() const noexcept  override {
        return "Erreur:invalid operation(valid operations:+ - / *)!!";
    }
};
//function to calculate
double calculate(double x , double y , char op ){
    switch(op){
        case '+':
            return x+y;
        case '-':
            return x-y;
        case '*':
            return x*y;
        case '/':
            if (y==0){
                throw DivideByZeroException();
            }
            return x/y;
        default:
            throw InvalidOperationException();
    }
}

int main() {
    double num1, num2;
    char operation;
    std::cout << "Enter first number:";
    std::cin >> num1;
    std::cout << "Enter second number:";
    std::cin >> num2;
    std::cout << "Enter operation (+, -, *, /): ";
    std::cin >> operation;
    try {
        double result = calculate(num1, num2, operation);
        std::cout << "Result:" << result << std::endl;
    }
    catch (const DivideByZeroException& ex) {
        std::cerr << ex.what() << std::endl;
    }
    catch (const InvalidOperationException& ex) {
        std::cerr << ex.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
    }
    std::cout << "Program completed" << std::endl;
    return 0;
}