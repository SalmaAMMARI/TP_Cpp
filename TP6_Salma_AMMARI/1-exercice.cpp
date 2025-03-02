#include <iostream>
using namespace std;



//fonction pour allouer dynamiquement une matrice m*n
int** allouer(int row , int col){
    int** matrice = new int*[row];//allouer  un tableau de pointers(de tableaux)
    for (int i=0;i<row;i++){
        matrice[i]= new int[col]; // allouer un des tableau dans le tableau matrice
    }
    return matrice;
}

void initialiser(int**mat , int row , int col){
    int val=1;
    for (int i=0;i<row;i++){
        for (int j=0; j<col ; j++){
            mat[i][j]=val++; //on initilise la matrice par des valeurs croissantes
        }
    }

}
void afficher(int**mat , int row ,int col){
    for (int i=0;i<row;i++){
        for (int j=0; j<col ; j++){
            cout<<mat[i][j]<<"   ";
        }
        cout<<"\n";
    }

}
int** transpose(int**mat ,int row , int col){
    int** trans = allouer(col , row);
    for (int i=0;i<row;i++){
        for (int j=0; j<col ; j++){
            trans[j][i]=mat[i][j];

        }

    }
    return trans;



}
void libérer(int** mat , int row){

    for (int i=0 ; i<row;i++){
        delete[] mat[i];
    }
    delete[] mat;
}

int main() {
    int row , col;
    cout<<"Entrez le nombre de ligne:"<<endl;
    cin>>row;
    cout<<"Entrez le nombre de colonne:"<<endl;
    cin>>col;
    int** matrice = allouer(row , col);
    initialiser(matrice , row , col);
    cout<<"Matrice initiale:"<<endl;
    afficher(matrice ,row , col);
    int** trans= transpose(matrice , row , col);
    cout<<"Matrice Transposée:"<<endl;
    afficher(trans ,  col , row);
    libérer(matrice , row);
    libérer(matrice , col);
    return 0;





}
