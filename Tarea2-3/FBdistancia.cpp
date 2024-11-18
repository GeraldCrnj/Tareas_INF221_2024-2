#include <iostream>
#include "funciones.h"
#include <vector>
#include <string>
#include <climits>  // Para INT_MAX
#include <fstream>  // Para cargar archivos de costos
#include <algorithm>
#include <chrono> 
using namespace std;

/*
int DistanciaFuerzaBruta(string S1, string S2)
    * Parámetros
        - S1: Una cadena de caracteres que representa la primera palabra o secuencia a comparar.
        - S2: Una cadena de caracteres que representa la segunda palabra o secuencia a comparar.
    * Retorno: Retorna un valor entero que representa la distancia de edición mínima entre S1 y S2, considerando los costos de inserción, eliminación, sustitución, y transposición de caracteres.
    * Descripción: Esta función calcula la distancia de edición entre las cadenas S1 y S2 utilizando un enfoque de fuerza bruta. Evalúa las posibles operaciones entre los caracteres de las cadenas (inserción, eliminación, sustitución y transposición) y selecciona el costo mínimo en cada paso. La función es recursiva y calcula la distancia mínima probando cada operación posible, lo que puede ser ineficiente para cadenas largas debido al tiempo de ejecución exponencial.
*/
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

    int insertar = DistanciaFuerzaBruta(S1,S2.substr(1)) + costo_ins(S2[0]);
    int eliminar = DistanciaFuerzaBruta(S1.substr(1),S2) + costo_del(S1[0]);
    int sustituir = DistanciaFuerzaBruta(S1.substr(1),S2.substr(1)) + costo_sub(S1[0],S2[0]);
    minCosto = min({sustituir, insertar, eliminar});
   
    if (S1.length()>1 && S2.length()>1 && ( S1[1]==S2[0] && S1[0]==S2[1])) {
        int transponer = DistanciaFuerzaBruta(S1.substr(2),S2.substr(2)) + costo_trans(S1[0], S1[1]);
        minCosto = min(minCosto,transponer);
    }
    
    return minCosto;
}

int main(){
    // Cargar los archivos de costos
    cargarCostoVector("cost_insert.txt", tabla_costo_insercion);
    cargarCostoVector("cost_delete.txt", tabla_costo_eliminacion);
    cargarCostoMatriz("cost_replace.txt", tabla_costo_sustitucion);
    cargarCostoMatriz("cost_transpose.txt", tabla_costo_transposicion);

    string S1,S2;
    cout << "Ingresa la primera cadena: ";
    getline(cin, S1);
    cout << "Ingresa la segunda cadena: ";
    getline(cin, S2);
   // Medir tiempo de ejecución
    auto start = chrono::high_resolution_clock::now();
    int costoMinimo = DistanciaFuerzaBruta(S1, S2);
    auto end = chrono::high_resolution_clock::now();

    // Calcular duración en milisegundos
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    // Mostrar resultados
    cout << "La distancia mínima de edición es: " << costoMinimo << endl;
    cout << "Tiempo de ejecución: " << duration << " ms" << endl;
    return 0;
}
