#include <iostream>
#include <vector>
#include <cmath>
#include <omp.h>
#include <chrono>
#include <fstream>

using namespace std;

const int UMBRAL = 64;  // Umbral para usar la multiplicación cúbica

// Función para multiplicar matrices de forma cúbica (tradicional)
vector<vector<int>> multiplicarMatricesCubicamente(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

// Función para sumar matrices
vector<vector<int>> sumarMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    #pragma omp parallel for
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

// Función para restar matrices
vector<vector<int>> restarMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    #pragma omp parallel for
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

// Algoritmo de Strassen
vector<vector<int>> strassen(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();

    // Usar la multiplicación cúbica tradicional para matrices pequeñas
    if (n <= UMBRAL) {
        return multiplicarMatricesCubicamente(A, B);
    }

    int newSize = n / 2;
    vector<vector<int>> A11(newSize, vector<int>(newSize));
    vector<vector<int>> A12(newSize, vector<int>(newSize));
    vector<vector<int>> A21(newSize, vector<int>(newSize));
    vector<vector<int>> A22(newSize, vector<int>(newSize));
    
    vector<vector<int>> B11(newSize, vector<int>(newSize));
    vector<vector<int>> B12(newSize, vector<int>(newSize));
    vector<vector<int>> B21(newSize, vector<int>(newSize));
    vector<vector<int>> B22(newSize, vector<int>(newSize));

    // Dividir las matrices en submatrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];
            
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Calcular los productos intermedios (M1 a M7)
    vector<vector<int>> M1 = strassen(sumarMatrices(A11, A22), sumarMatrices(B11, B22));
    vector<vector<int>> M2 = strassen(sumarMatrices(A21, A22), B11);
    vector<vector<int>> M3 = strassen(A11, restarMatrices(B12, B22));
    vector<vector<int>> M4 = strassen(A22, restarMatrices(B21, B11));
    vector<vector<int>> M5 = strassen(sumarMatrices(A11, A12), B22);
    vector<vector<int>> M6 = strassen(restarMatrices(A21, A11), sumarMatrices(B11, B12));
    vector<vector<int>> M7 = strassen(restarMatrices(A12, A22), sumarMatrices(B21, B22));

    // Combinar las submatrices para obtener el resultado
    vector<vector<int>> C11 = sumarMatrices(restarMatrices(sumarMatrices(M1, M4), M5), M7);
    vector<vector<int>> C12 = sumarMatrices(M3, M5);
    vector<vector<int>> C21 = sumarMatrices(M2, M4);
    vector<vector<int>> C22 = sumarMatrices(restarMatrices(sumarMatrices(M1, M3), M2), M6);

    // Unir las submatrices en la matriz resultante
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }

    return C;
}

// Función para leer matrices desde un archivo de texto
vector<vector<int>> leerMatrizDesdeArchivo(ifstream &file, int &n, int &m) {
    file >> n >> m;
    vector<vector<int>> matriz(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            file >> matriz[i][j];
        }
    }
    return matriz;
}

// Función principal
int main() {
    ifstream file("dataset.txt");
    int n, m;

    // Leer la primera matriz A
    vector<vector<int>> A = leerMatrizDesdeArchivo(file, n, m);

    // Leer la segunda matriz B
    vector<vector<int>> B = leerMatrizDesdeArchivo(file, n, m);

    // Verificar si las dimensiones son compatibles
    if (A[0].size() != B.size()) {
        cerr << "Dimensiones incompatibles para la multiplicación de matrices." << endl;
        return -1;
    }

    auto start = chrono::high_resolution_clock::now();
    // Multiplicar las matrices usando Strassen
    vector<vector<int>> C = strassen(A, B);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Tiempo de ejecución: " << elapsed.count() << " segundos" << endl;

    // Imprimir la matriz resultante
    /*cout << "Matriz Resultante C:" << endl;
    for (const auto& row : C) {
        for (const auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }*/

    return 0;
}


/*
REFERENCIAS:
Este código está basado en recursos educativos y ejemplos del algoritmo de Strassen disponibles en línea. Se ocuparon los siguientes enlalos siguientes enlaces:

    Referencia detallada del código y explicación del algoritmo: https://www.geeksforgeeks.org/strassens-matrix-multiplication/
    Explicación matemática del algoritmo: https://en.wikipedia.org/wiki/Strassen_algorithm
*/