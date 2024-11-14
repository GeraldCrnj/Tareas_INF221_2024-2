#include <vector>
#include <string>
using namespace std;

// funciones.h
#ifndef FUNCIONES_H // Directiva para evitar inclusiones múltiples
#define FUNCIONES_H

// Declaración de las variables globales como `extern` para que sean accesibles en otros archivos
extern vector<int> tabla_costo_insercion;
extern vector<int> tabla_costo_eliminacion;
extern vector<vector<int>> tabla_costo_sustitucion;
extern vector<vector<int>> tabla_costo_transposicion;

void cargarCostoVector(const string& nombreArchivo, vector<int>& tabla);
void cargarCostoMatriz(const string& nombreArchivo, vector<vector<int>>& tabla);
int costo_ins(char b);
int costo_del(char a);
int costo_sub(char a, char b);
int costo_trans(char a, char b);
// Declara aquí todas las demás funciones que deseas reutilizar

#endif
