#include<iostream>
#include<vector>
#include <chrono>
using namespace std;

typedef vector<vector<int>> matrix;

matrix add(const matrix &A, const matrix &B, int size) {
    matrix C(size, vector<int>(size, 0));
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

matrix subtract(const matrix &A, const matrix &B, int size) {
    matrix C(size, vector<int>(size, 0));
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

matrix strassen(const matrix &A, const matrix &B, int size) {
    if (size == 1) {
        matrix C(1, vector<int>(1, 0));
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    int newSize = size / 2;
    matrix A11(newSize, vector<int>(newSize, 0));
    matrix A12(newSize, vector<int>(newSize, 0));
    matrix A21(newSize, vector<int>(newSize, 0));
    matrix A22(newSize, vector<int>(newSize, 0));
    matrix B11(newSize, vector<int>(newSize, 0));
    matrix B12(newSize, vector<int>(newSize, 0));
    matrix B21(newSize, vector<int>(newSize, 0));
    matrix B22(newSize, vector<int>(newSize, 0));

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

    matrix M1 = strassen(add(A11, A22, newSize), add(B11, B22, newSize), newSize);
    matrix M2 = strassen(add(A21, A22, newSize), B11, newSize);
    matrix M3 = strassen(A11, subtract(B12, B22, newSize), newSize);
    matrix M4 = strassen(A22, subtract(B21, B11, newSize), newSize);
    matrix M5 = strassen(add(A11, A12, newSize), B22, newSize);
    matrix M6 = strassen(subtract(A21, A11, newSize), add(B11, B12, newSize), newSize);
    matrix M7 = strassen(subtract(A12, A22, newSize), add(B21, B22, newSize), newSize);

    matrix C(size, vector<int>(size, 0));
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
            C[i][j + newSize] = M3[i][j] + M5[i][j];
            C[i + newSize][j] = M2[i][j] + M4[i][j];
            C[i + newSize][j + newSize] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
        }
    }

    return C;
}

int main() {
    int size;
    cout << "Ingrese el tamaño de la matriz (debe ser una potencia de 2): ";
    cin >> size;

    matrix A(size, vector<int>(size, 0));
    matrix B(size, vector<int>(size, 0));

    cout << "Ingrese los elementos de la matriz A:" << endl;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            cin >> A[i][j];

    cout << "Ingrese los elementos de la matriz B:" << endl;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            cin >> B[i][j];

    auto start = std::chrono::high_resolution_clock::now();
    matrix C = strassen(A, B, size);
    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Tiempo de ejecución: " << elapsed.count() << " segundos" << std::endl;

    cout << "Resultado de la multiplicación:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }

    return 0;
}

/*
REFERENCIAS:
Este código está basado en recursos educativos y ejemplos del algoritmo de Strassen disponibles en línea. Se ocuparon los siguientes enlaces:

    Referencia detallada del código y explicación del algoritmo: https://www.geeksforgeeks.org/strassens-matrix-multiplication/
    Explicación matemática del algoritmo: https://en.wikipedia.org/wiki/Strassen_algorithm
*/