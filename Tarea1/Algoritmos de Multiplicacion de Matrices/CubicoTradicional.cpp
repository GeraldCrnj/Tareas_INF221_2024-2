#include <iostream>
#include <vector>
#include <chrono>

using Matrix = std::vector<std::vector<int>>;
using namespace std;

// Función para multiplicar matrices usando el algoritmo cúbico tradicional
Matrix multiplicar_matrices(const Matrix& A, const Matrix& B) {
    int n = A.size();
    int m = A[0].size();
    int p = B[0].size();
    
    Matrix C(n, std::vector<int>(p, 0)); // Matriz de resultado inicializada en 0
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            for (int k = 0; k < m; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    return C;
}

int main() {
    // Ejemplo de matrices A y B
    Matrix A = {{1, 2, 3}, 
                {4, 5, 6}};
                
    Matrix B = {{7, 8},
                {9, 10},
                {11, 12}};

    // Imprimir la matriz A
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
    }
    
    auto start = std::chrono::high_resolution_clock::now();
    Matrix C = multiplicar_matrices(A, B);
    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Tiempo de ejecución: " << elapsed.count() << " segundos" << std::endl;

    
    cout << "Matriz C: " << endl;
    // Imprimir la matriz resultante C
    for (const auto& row : C) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << std::endl;
    }
    
    return 0;
}
