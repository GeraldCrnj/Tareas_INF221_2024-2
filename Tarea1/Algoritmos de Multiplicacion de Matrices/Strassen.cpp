#include <iostream>
#include <vector>
#include <chrono>

using Matrix = std::vector<std::vector<int>>;
using namespace std;

Matrix strassen(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix A11(n/2, vector<int>(n/2,0));
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
    Matrix C = strassen(A, B);
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
