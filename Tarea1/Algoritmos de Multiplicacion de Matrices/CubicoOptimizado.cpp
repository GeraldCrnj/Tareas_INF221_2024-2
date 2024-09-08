#include <iostream>
#include <vector>
#include <chrono>
#include <fstream> 

using Matrix = std::vector<std::vector<int>>;
using namespace std;

Matrix transponer(const Matrix& B){
    int m = B.size();
    int p = B[0].size();

    Matrix B_T(p, std::vector<int>(m));

    for (int i = 0; i < m; i++){
        for (int j = 0; j < p; j++){
            B_T[j][i] = B[i][j];
        }
    }
    return B_T;
}

Matrix multiplicar_matrices_op(const Matrix& A, const Matrix& B) {
    int n = A.size();
    int m = A[0].size();
    int p = B.size();

    Matrix C(n, std::vector<int>(p,0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            for (int k = 0; k < m; ++k) {
                C[i][j] += A[i][k] * B[j][k];
            }
        }
    }

    return C;
}

Matrix leer_matriz(ifstream& archivo, int& filas, int& columnas) {
    archivo >> filas >> columnas;
    Matrix matriz(filas, std::vector<int>(columnas));
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            archivo >> matriz[i][j];
        }
    }
    return matriz;
}

int main() {
    ifstream archivo("dataset.txt");
    if (!archivo) {
        cerr << "Error al abrir el archivo" << endl;
        return 1;
    }

    int filasA, columnasA, filasB, columnasB;
    Matrix A = leer_matriz(archivo, filasA, columnasA);
    Matrix B = leer_matriz(archivo, filasB, columnasB);

    archivo.close();

    // Imprimir la matriz A
    /*
    cout << "Matriz A: " << endl;
    for (const auto& row : A) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << std::endl;
    }
    // Imprimir la matriz B
    cout << "Matriz B: " << endl;
    for (const auto& row : B) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << std::endl;
    }*/
    
    auto start = std::chrono::high_resolution_clock::now();
    B = transponer(B);
    Matrix C = multiplicar_matrices_op(A, B);
    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Tiempo de ejecución: " << elapsed.count() << " segundos" << std::endl;

    /*
    cout << "Matriz C: " << endl;
    // Imprimir la matriz resultante C
    for (const auto& row : C) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << std::endl;
    }*/
    
    return 0;
}
