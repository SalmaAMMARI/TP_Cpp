#include <string>
#include<iostream>
#include<stdexcept>
//handle negative quantity
class NegativeQuantityException:public std::exception{
public:
    const char* what() const noexcept override{
        return "Erreur:Quantité négative";

    }
};
class InsufficientStockException:public std::exception{
public:
    const char* what() const noexcept override{
        return "Erreur:stock insuffisant";
    }
};
class Inventory{
private:
    int stock;
public:
    Inventory(int initialStock=0){
        if (initialStock<0){
            throw NegativeQuantityException();
        }
        stock=initialStock;
    };
    void add_items(int quantity){
        if (quantity<0){
            throw NegativeQuantityException();
        }
        stock+=quantity;

    };
    void remove_items(int quantity){
        if (quantity<0){
            throw NegativeQuantityException();
        }
        if (quantity>stock){
            throw InsufficientStockException();
        }
        stock-=quantity;

    };
    int get_stock()const{
        return stock;
    }
};

int main(){
    // Test1: Initialisation etajout d'articles
    Inventory inv(100); //Initial stock of100 items
    std::cout<< "Initial stock: "<< inv.get_stock()<< std::endl;
    try {
        inv.add_items(50);
        std::cout <<"After adding 50 items: " <<inv.get_stock()<< std::endl;
    }
    catch (const NegativeQuantityException&ex){
        std::cerr <<ex.what()<< std::endl;
    }
    catch (...){
        std::cerr <<"Unknown error occurred"<< std::endl;
    }
    // Test2: Tentativederetrait excessif
    try {
        inv.remove_items(160); // Should throwInsufficientStockException
        std::cout <<"After removing 160 items: "<<inv.get_stock()<< std::endl;
    }
    catch (const InsufficientStockException&ex){
        std::cerr <<ex.what()<< std::endl;
    }
    catch (...){
        std::cerr <<"Unknown error occurred"<< std::endl;
    }
    // Test3: Tentatived'ajout d'une quantiténégative
    try {
        inv.add_items(-10); //Should throw NegativeQuantityException
        std::cout <<"After adding -10 items: " <<inv.get_stock()<< std::endl;
    }
    catch (const NegativeQuantityException&ex){
        std::cerr <<ex.what()<< std::endl;
    }
    catch (...){
        std::cerr <<"Unknown error occurred"<< std::endl;
    }
    std::cout<< "Program completed" <<std::endl;
    return 0;
}