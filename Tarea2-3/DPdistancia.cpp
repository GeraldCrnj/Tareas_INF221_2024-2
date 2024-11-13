#include <iostream>
#include <vector>
#include <string>
#include <climits>  // Para INT_MAX
#include <fstream>  // Para cargar archivos de costos
#include <algorithm>
using namespace std;

const int ALPHABET_SIZE = 26;  // Tamaño del alfabeto inglés en minúsculas

// Tablas de costos globales
vector<int> tabla_costo_insercion(ALPHABET_SIZE); // Costos de inserción
vector<int> tabla_costo_eliminacion(ALPHABET_SIZE); // Costos de eliminación
vector<std::vector<int>> tabla_costo_sustitucion(ALPHABET_SIZE, std::vector<int>(ALPHABET_SIZE)); // Costos de sustitución
vector<std::vector<int>> tabla_costo_transposicion(ALPHABET_SIZE, std::vector<int>(ALPHABET_SIZE)); // Costos de transposición

// Función para cargar un archivo de vector de costos (inserción/eliminación)
void cargarCostoVector(const std::string& nombreArchivo, std::vector<int>& tabla) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
        return;
    }
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        archivo >> tabla[i];
    }
    archivo.close();
}

// Función para cargar un archivo de matriz de costos (sustitución/transposición)
void cargarCostoMatriz(const std::string& nombreArchivo, std::vector<std::vector<int>>& tabla) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
        return;
    }
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        for (int j = 0; j < ALPHABET_SIZE; ++j) {
            archivo >> tabla[i][j];
        }
    }
    archivo.close();
}

// Funciones de costos que utilizan las tablas globales
int costo_ins(char b) {
    return tabla_costo_insercion[b - 'a'];
}

int costo_del(char a) {
    return tabla_costo_eliminacion[a - 'a'];
}

int costo_sub(char a, char b) {
    return tabla_costo_sustitucion[a - 'a'][b - 'a'];
}

int costo_trans(char a, char b) {
    return tabla_costo_transposicion[a - 'a'][b - 'a'];
}

int DistanciaDP(string S1, string S2) {
    int n = S1.length();
    int m = S2.length();

    // Crear la matriz de DP
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));

    // Inicialización de las fronteras (cuando una de las cadenas está vacía)
    for (int i = 0; i < dp.size(); ++i) {
        dp[i][0] = 0;
        for (int k = 0; k < i; ++k) dp[i][0] += costo_del(S1[k]);
    }

    for (int j = 0; j <dp.size(); ++j) {
        dp[0][j] = 0;
        for (int k = 0; k < j; ++k) dp[0][j] += costo_ins(S2[k]);
    }

    // Llenar la matriz de DP
    for (int row = 1; row <= dp.size(); ++row) {
        for (int col = 1; col <= dp[0].size(); ++col) {
            // Cálculo de las operaciones: inserción, eliminación y sustitución
            if(S1[col-1]==S2[row-1]){
                dp[row][col] = dp[row-1][col-1];
            } else{
                dp[row][col]= min ({dp[row][col-1], dp[row-1][col], dp[row-1][col-1]})+1;
            }/*
            dp[i][j] = min({
                dp[i-1][j] + costo_del(S1[i-1]),   // Eliminar
                dp[i][j-1] + costo_ins(S2[j-1]),   // Insertar
                dp[i-1][j-1] + costo_sub(S1[i-1], S2[j-1])  // Sustituir
            });

            // Transposición (si corresponde)
            if (row > 1 && col > 1 && (S1[row-1] == S2[col-2] || S1[row-2] == S2[col-1])) {
                int transponer = dp[row-2][col-2] + costo_trans(S1[row-2], S1[row-1]);
                dp[i][j] = min(dp[row][col], transponer);
            }*/
        }
    }
    
    // El costo mínimo de transformar S1 en S2 estará en dp[n][m]
    return dp[dp.size()-1][dp[0].size()];
}

int main(){
    // Cargar los archivos de costos
    cargarCostoVector("cost_insert.txt", tabla_costo_insercion);
    cargarCostoVector("cost_delete.txt", tabla_costo_eliminacion);
    cargarCostoMatriz("cost_replace.txt", tabla_costo_sustitucion);
    cargarCostoMatriz("cost_transpose.txt", tabla_costo_transposicion);

    string S1,S2;
    cout << "Ingresa la primera cadena: ";
    cin >> S1;
    cout << "Ingresa la segunda cadena: ";
    cin >> S2;
    

    // Calcular la distancia mínima de edición usando fuerza bruta
    int costoMinimo = DistanciaDP(S1, S2);

    // Mostrar el resultado
    cout << endl << "La distancia mínima de edición es: " << costoMinimo << endl;

    return 0;
}