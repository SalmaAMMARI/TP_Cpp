#include <iostream>
#include <memory>
using namespace std;

struct MemoryBlock {
    int size;
    // The constructor
    MemoryBlock(int s) {
        size = s;
        cout << "Bloc de memoire alloue de " << size << " unites." << endl;
    }
    // Destructor
    ~MemoryBlock() {
        cout << "Liberation de la memoire." << endl;
    }
};

std::unique_ptr<MemoryBlock> CreateBloc(int bloc) {
    // Création d'un bloc de mémoire de bloc unités
    auto bloc1 = std::make_unique<MemoryBlock>(bloc);
    return bloc1;
}

std::unique_ptr<MemoryBlock> fusionner(std::unique_ptr<MemoryBlock> a, std::unique_ptr<MemoryBlock> b) {
    int size = a->size + b->size;
    auto bloc = std::make_unique<MemoryBlock>(size);
    cout << "Fusion des deux blocs : " << size << " unites." << endl;
    return bloc;
}

int main() {
    auto bloc1 = CreateBloc(100);
    auto bloc2 = CreateBloc(200);

    // Fusionner les deux blocs de mémoire
    auto bloc3 = fusionner(std::move(bloc2), std::move(bloc1));

    // bloc1 et bloc2 ne sont plus valides ici, mais bloc3 a la nouvelle ressource fusionnée
    return 0;
}
