#include <iostream>
#include "funciones.h"
#include <vector>
#include <string>
#include <climits>  // Para INT_MAX
#include <fstream>  // Para cargar archivos de costos
#include <algorithm>
using namespace std;

/*
int DistanciaDP(string S1, string S2)
    * Parámetros
        - S1: Una cadena de caracteres que representa la primera palabra o secuencia a comparar.
        - S2: Una cadena de caracteres que representa la segunda palabra o secuencia a comparar.
    * Retorno: Retorna un valor entero que representa la distancia de edición mínima entre S1 y S2, considerando los costos de inserción, eliminación, sustitución, y transposición de caracteres.
    * Descripción: Esta función calcula la distancia de edición entre las cadenas S1 y S2 utilizando programación dinámica (DP). Construye una matriz `dp` donde cada posición representa el costo mínimo para convertir una subsecuencia de S1 en una subsecuencia de S2. La función recorre esta matriz llenando cada celda con el costo acumulado mínimo, aplicando las operaciones de inserción, eliminación, sustitución, y transposición. Este enfoque es mucho más eficiente que el método de fuerza bruta, con una complejidad de tiempo de O(m * n), donde m y n son las longitudes de S1 y S2.
*/
int DistanciaDP(string S1, string S2) {
    int n = S1.size();
        int m = S2.size();
        
        // Matriz DP
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        
        // Inicialización de la primera columna
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = (i == 0) ? 0 : dp[i - 1][0] + costo_ins(S2[i - 1]);
        }

        // Inicialización de la primera fila
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = (j == 0) ? 0 : dp[0][j - 1] + costo_del(S1[j - 1]);
        }

        // Llenado de la matriz DP
        for (int row = 1; row <= m; ++row) {
            for (int col = 1; col <= n; ++col) {
                // Caso 1: Si los caracteres coinciden
                if (S1[col - 1] == S2[row - 1]) {
                    dp[row][col] = dp[row - 1][col - 1];
                } else {
                    // Caso 2: Los caracteres no coinciden
                    int sustituir = dp[row - 1][col - 1] + costo_sub(S1[col - 1], S2[row - 1]);
                    int insertar = dp[row][col - 1] + costo_ins(S2[row - 1]);
                    int eliminar = dp[row - 1][col] + costo_del(S1[col - 1]);
                    dp[row][col] = min({sustituir, insertar, eliminar});
                }

                // Caso 3: Transposición de caracteres adyacentes
                if (row > 1 && col > 1 && S1[col - 1] == S2[row - 2] && S1[col - 2] == S2[row - 1]) {
                    int transponer = dp[row - 2][col - 2] + costo_trans(S1[col - 2], S1[col - 1]);
                    dp[row][col] = min(dp[row][col], transponer);
                }
            }
        }
        //DESCOMENTAR SOLO EN CASO DE QUERER VISUALIZAR LA MATRIZ DP
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[m][n];
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
    

    // Calcular la distancia mínima de edición usando dp
    int costoMinimo = DistanciaDP(S1, S2);

    // Mostrar el resultado
    cout << endl << "La distancia mínima de edición es: " << costoMinimo << endl;

    return 0;
}