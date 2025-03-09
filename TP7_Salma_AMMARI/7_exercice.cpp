#include <iostream>

template <typename T>
class SharedPtr {
private:
    T* ptr;
    int* ref_count;

public:
    // Constructeur
    explicit SharedPtr(T* p = nullptr) : ptr(p), ref_count(new int(1)) {
        if (p) {
            std::cout << "Création d'un SharedPtr vers " << *ptr << "\n";
            std::cout << "Nombre de références : " << *ref_count << "\n";
        }
    }

    // Constructeur de copie
    SharedPtr(const SharedPtr& other) : ptr(other.ptr), ref_count(other.ref_count) {
        (*ref_count)++;
        std::cout << "Création d'une copie\n";
        std::cout << "Nombre de références : " << *ref_count << "\n";
    }

    // Destructeur
    ~SharedPtr() {
        (*ref_count)--;
        if (*ref_count){
            std::cout << "Destruction d'un SharedPtr\n";
            std::cout << "Nombre de références : " << *ref_count << "\n";

        }else{
            delete ptr;
            delete ref_count;
            std::cout << "Objet supprimé\n";
        }
    }

    // Opérateur d'accès
    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }
};

int main() {
    {
        SharedPtr<int> sp1(new int(10));
        {
            SharedPtr<int> sp2 = sp1; // Copie
        }
        // Ici, sp2 est détruit, le compteur doit diminuer
    }
    // Ici, sp1 est détruit, l'objet doit être supprimé
    return 0;
}
