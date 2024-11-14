#include <iostream>
#include <vector>
#include <string>
#include <climits>  // Para INT_MAX
#include <fstream>  // Para cargar archivos de costos
#include <algorithm>
using namespace std;

const int ALPHABET_SIZE = 26; 

// Tablas de costos globales
vector<int> tabla_costo_insercion(ALPHABET_SIZE); // Costos de inserción
vector<int> tabla_costo_eliminacion(ALPHABET_SIZE); // Costos de eliminación
vector<vector<int>> tabla_costo_sustitucion(ALPHABET_SIZE, vector<int>(ALPHABET_SIZE)); // Costos de sustitución
vector<vector<int>> tabla_costo_transposicion(ALPHABET_SIZE, vector<int>(ALPHABET_SIZE)); // Costos de transposición


/*
void cargarCostoVector(const string& nombreArchivo, vector<int>& tabla)
    * Parámetros
        - nombreArchivo: Una cadena de texto con el nombre del archivo que contiene los costos de inserción o eliminación.
        - tabla: Un vector de enteros donde se almacenarán los costos de cada carácter del alfabeto.
    * Retorno: Esta función no retorna nada (void), pero modifica el vector tabla pasado por referencia.
    * Descripción: Esta función abre un archivo de texto con los costos de inserción o eliminación y carga estos valores en
                   el vector tabla. Cada índice del vector corresponde a un carácter (del 'a' al 'z') y contiene el costo 
                   asociado a ese carácter.
*/
void cargarCostoVector(const string& nombreArchivo, vector<int>& tabla) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return;
    }
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        archivo >> tabla[i];
    }
    archivo.close();
}

/*
void cargarCostoMatriz(const string& nombreArchivo, vector<vector<int>>& tabla)
    * Parámetros
        - nombreArchivo: Una cadena de texto con el nombre del archivo que contiene los costos de sustitución o transposición.
        - tabla: Una matriz (vector de vectores) de enteros donde se almacenarán los costos entre pares de caracteres.
    * Retorno: Esta función no retorna nada (void), pero modifica la matriz tabla pasada por referencia.
    * Descripción: Esta función abre un archivo de texto que contiene los costos de sustitución o transposición entre pares 
                   de caracteres del alfabeto y carga estos valores en la matriz tabla. Cada celda [i][j] representa el costo 
                   de cambiar el carácter i al carácter j.
*/
void cargarCostoMatriz(const string& nombreArchivo, vector<vector<int>>& tabla) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return;
    }
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        for (int j = 0; j < ALPHABET_SIZE; ++j) {
            archivo >> tabla[i][j];
        }
    }
    archivo.close();
}

/*
int costo_ins(char b)
    * Parámetros
        - b: Un carácter en minúscula que representa el carácter que se quiere insertar.
    * Retorno: Retorna un valor entero que representa el costo de insertar el carácter b.
    * Descripción: La función utiliza el carácter b para buscar en tabla_costo_insercion el costo de inserción correspondiente.
                   Este costo es almacenado en el índice del carácter en tabla_costo_insercion.
*/
int costo_ins(char b) {
    return tabla_costo_insercion[b - 'a'];
}

/*
int costo_del(char a)
    * Parámetros
        - a: Un carácter en minúscula que representa el carácter que se quiere eliminar.
    * Retorno: Retorna un valor entero que representa el costo de eliminar el carácter a.
    * Descripción: Esta función devuelve el costo de eliminar el carácter a usando el vector tabla_costo_eliminacion. 
                   El costo se obtiene accediendo a la posición correspondiente a a en el vector.
*/
int costo_del(char a) {
    return tabla_costo_eliminacion[a - 'a'];
}

/*
int costo_sub(char a, char b)
    * Parámetros
        - a: Un carácter en minúscula que representa el carácter original.
        - b: Un carácter en minúscula que representa el carácter al que se quiere sustituir a.
    * Retorno: Retorna un valor entero que representa el costo de sustituir el carácter a por el carácter b.
    * Descripción: Esta función busca en tabla_costo_sustitucion el costo de cambiar el carácter a por el carácter b. 
                   Este costo se encuentra en la posición [a][b] de la matriz tabla_costo_sustitucion.
*/
int costo_sub(char a, char b) {
    return tabla_costo_sustitucion[a - 'a'][b - 'a'];
}

/*
int costo_trans(char a, char b)
    * Parámetros
        - a: Un carácter en minúscula que representa el primer carácter de un par a transponer.
        - b: Un carácter en minúscula que representa el segundo carácter de un par a transponer.
    * Retorno: Retorna un valor entero que representa el costo de transponer los caracteres a y b.
    * Descripción: Esta función obtiene el costo de transponer los caracteres a y b en tabla_costo_transposicion. 
                   Accede a la posición [a][b] en la matriz para obtener este costo.
*/
int costo_trans(char a, char b) {
    return tabla_costo_transposicion[a - 'a'][b - 'a'];
}
