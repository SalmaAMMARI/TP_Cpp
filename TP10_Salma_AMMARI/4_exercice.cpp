#include <array>
#include <iostream>
#include <stdexcept>
// Forward declaration for MatrixAdder
template <typename T, int M1, int N1, int M2, int N2>
class MatrixAdder;


//classe Matrix
template <typename T , int M, int N >
class Matrix{
private:
    std::array<std::array<T,N>  , M> mat;
public:
    Matrix()=default ; // the compiler will choose a defult constructor
    void set(int row , int col , const T& data){
        mat.at(row).at(col)=data;

    };
    T get(int row, int col )const{
        return mat.at(row).at(col);
    };
    //add method to add two matrices( add matrice to this matroce)
    //on utilise template avat d implementer add pour que cette fct accepte n importe quelle matrice
    //la verification de compatibilité des tailles est vérifiéé après
    template<int M2,int N2>
    auto add(const Matrix<T,M2,N2>& other)const{
        return MatrixAdder<T,M,N,M2,N2>::add(*this, other);
    }
};
//template that handles non compatible sizes
template <typename T , int M1 , int N1, int M2,int N2>
class MatrixAdder{
public:
    // we declare the return as static because the sum result is not an attribute of the object
    static Matrix<T,M1,N1>add(const Matrix<T,M1,N1>& mat1, const Matrix<T,M2,N2>& mat2){
        // verifie taille compatible
        static_assert(M1==M2 &&N1==N2, "les dimensions des deux matrices doivent etre compatibles");
        Matrix<T, M1, N1> result;
        for (size_t i = 0; i < M1; ++i) {
            for (size_t j = 0; j < N1; ++j) {
                result.set(i, j, mat1.get(i, j) + mat2.get(i, j));
            }
        }
        return result;
    }
};
//specialization if the size is not compatible
template <typename T , int M,int N>
class MatrixAdder<T,M,N,M,N>{
public:
    static Matrix<T,M,N>add(const Matrix<T,M,N>& mat1, const Matrix<T,M,N>& mat2){


        Matrix<T, M, N> result;
        for (size_t i = 0; i < M; ++i) {
            for (size_t j = 0; j < N; ++j) {
                result.set(i, j, mat1.get(i, j) + mat2.get(i, j));
            }
        }
        return result;
    }

};


int main() {
    Matrix<int, 2, 2> m1;
    m1.set(0, 0, 1); m1.set(0, 1, 2);
    m1.set(1, 0, 3); m1.set(1, 1, 4);
    Matrix<int, 2, 2> m2;
    m2.set(0, 0, 5); m2.set(0, 1, 6);
    m2.set(1, 0, 7); m2.set(1, 1, 8);
    auto m3 = m1.add(m2);
    std::cout << m3.get(0, 0) << " , " << m3.get(0, 1) << std::endl; // Affiche 6 8
    std::cout << m3.get(1, 0) << " , " << m3.get(1, 1) << std::endl; // Affiche 10 12
    Matrix<int, 2, 3> m4; // Incompatible
     //m1.add(m4); // Erreur de compilation (static_assert)
    return 0;
}