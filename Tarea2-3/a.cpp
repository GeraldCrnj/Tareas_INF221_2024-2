#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
using namespace std;

// Funciones de costo que devuelven el costo de cada operación específica
int cost_ins(char c);
int cost_del(char c);
int cost_sub(char c1, char c2);
int cost_trans(char c1, char c2);

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        // Matriz DP para almacenar los costos mínimos de conversión
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        
        // Inicialización de la primera columna (transformación de cadena vacía a prefijo de word2)
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = (i == 0) ? 0 : dp[i - 1][0] + cost_ins(word2[i - 1]);
        }

        // Inicialización de la primera fila (transformación de prefijo de word1 a cadena vacía)
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = (j == 0) ? 0 : dp[0][j - 1] + cost_del(word1[j - 1]);
        }

        // Llenado de la matriz DP
        for (int row = 1; row <= m; ++row) {
            for (int col = 1; col <= n; ++col) {
                // Caso 1: Si los caracteres coinciden, no hay costo adicional
                if (word1[col - 1] == word2[row - 1]) {
                    dp[row][col] = dp[row - 1][col - 1];
                } else {
                    // Caso 2: Los caracteres no coinciden
                    int sustituir = dp[row - 1][col - 1] + cost_sub(word1[col - 1], word2[row - 1]);
                    int insertar = dp[row][col - 1] + cost_ins(word2[row - 1]);
                    int eliminar = dp[row - 1][col] + cost_del(word1[col - 1]);
                    dp[row][col] = min({sustituir, insertar, eliminar});
                }

                // Caso 3: Transposición de caracteres adyacentes
                if (row > 1 && col > 1 && word1[col - 1] == word2[row - 2] && word1[col - 2] == word2[row - 1]) {
                    int transponer = dp[row - 2][col - 2] + cost_trans(word1[col - 2], word1[col - 1]);
                    dp[row][col] = min(dp[row][col], transponer);
                }
            }
        }
        for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl; // Nueva línea al final de cada fila
    }
        // El último elemento de la matriz contiene la distancia mínima de edición
        return dp[m][n];
    }
};

// Implementación de las funciones de costos (para ejemplo, puedes ajustar según necesidad)
int cost_ins(char c) {
    // Define el costo de insertar el carácter `c` (aquí se usa un valor de ejemplo)
    return 1;
}

int cost_del(char c) {
    // Define el costo de eliminar el carácter `c` (aquí se usa un valor de ejemplo)
    return 1;
}

int cost_sub(char c1, char c2) {
    // Define el costo de sustituir `c1` por `c2` (aquí se usa un valor de ejemplo)
    return (c1 == c2) ? 0 : 2;
}

int cost_trans(char c1, char c2) {
    // Define el costo de transponer `c1` y `c2` (aquí se usa un valor de ejemplo)
    return 1;
}


int main() {
    Solution solution;
    string S1,S2;
    cout << "Ingresa la primera cadena: ";
    cin >> S1;
    cout << "Ingresa la segunda cadena: ";
    cin >> S2;
    int distancia = solution.minDistance(S1, S2);
    std::cout << "La distancia mínima de edición es: " << distancia << std::endl;

    return 0;
}
