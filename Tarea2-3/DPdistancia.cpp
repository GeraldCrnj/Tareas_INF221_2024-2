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

int DistanciaFuerzaBruta(string S1, string S2){
    if (S1==S2) return 0;
    if (S1 == ""){
        int costo = 0;
        for(char c: S2) costo += costo_ins(c);
        return  costo;
    } else if (S2 == ""){
        int costo = 0;
        for(char c: S1) costo += costo_ins(c);
        return  costo;
    }

    int minCosto = INT_MAX; 

    int insertar = DistanciaFuerzaBruta(S1.substr(1),S2) + costo_ins(S2[0]);
    minCosto = min(minCosto,insertar);
    int eliminar = DistanciaFuerzaBruta(S1.substr(1),S2) + costo_del(S1[0]);
    minCosto = min(minCosto,eliminar);
    int sustituir = DistanciaFuerzaBruta(S1.substr(1),S2.substr(1)) + costo_sub(S1[0],S2[0]);
    minCosto = min(minCosto,sustituir);
    if (S1.length()>1 && S2.length()>1 && ( S1[1]==S2[0] || S1[0]==S2[1])) {
        int transponer = INT_MAX;
        if (S1[1]==S2[0]) transponer = DistanciaFuerzaBruta(S1[0]+S1.substr(2),S2.substr(1)) + costo_trans(S1[0], S1[1]);
        else if (S1[0]==S2[1]) transponer = DistanciaFuerzaBruta(S1.substr(1),S2[0]+S2.substr(2)) + costo_trans(S1[0], S1[1]);
        minCosto = min(minCosto,transponer);
    }
    
    return minCosto;
}

int main(){
    // Cargar los archivos de costos
    cargarCostoVector("costosInsercion.txt", tabla_costo_insercion);
    cargarCostoVector("costosEliminar.txt", tabla_costo_eliminacion);
    cargarCostoMatriz("costosSustituir.txt", tabla_costo_sustitucion);
    cargarCostoMatriz("costosTransponer.txt", tabla_costo_transposicion);

    string S1,S2;
    cout << "Ingresa la primera cadena: ";
    cin >> S1;
    cout << "Ingresa la segunda cadena: ";
    cin >> S2;

    // Calcular la distancia mínima de edición usando fuerza bruta
    int costoMinimo = DistanciaFuerzaBruta(S1, S2);

    // Mostrar el resultado
    cout << "La distancia mínima de edición es: " << costoMinimo << endl;

    return 0;
}