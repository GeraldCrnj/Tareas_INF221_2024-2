Tarea 2-3
## Proyecto de Cálculo de Distancia de Edición con Diferentes Algoritmos

Este proyecto implementa dos algoritmos para calcular la distancia de edición mínima entre dos cadenas de caracteres: un algoritmo de programación dinámica y otro de fuerza bruta. Estos algoritmos consideran operaciones con costos específicos, como inserción, eliminación, sustitución y transposición de caracteres. Además, se cargan costos específicos desde archivos de texto, permitiendo una evaluación más personalizada.
Archivos

# DPdistancia.cpp
Implementa el cálculo de distancia de edición utilizando programación dinámica (DP).
    Función principal: int DistanciaDP(string S1, string S2)
        Parámetros: Dos cadenas, S1 y S2, que representan las secuencias a comparar.
        Retorno: Un valor entero que representa la distancia mínima de edición entre S1 y S2.
        Descripción: Usa una matriz dp para almacenar los costos acumulados de convertir cada subsecuencia de S1 en cada subsecuencia de S2. Las operaciones de inserción, eliminación, sustitución y transposición tienen costos específicos, que se cargan desde archivos externos. Este enfoque mejora la eficiencia con una complejidad de tiempo de O(m * n), donde m y n son las longitudes de las cadenas.
        Salida: Muestra la matriz dp y el costo mínimo de edición al completar el cálculo.

# FBdistancia.cpp
Implementa el cálculo de distancia de edición mediante un algoritmo de fuerza bruta.
    Función principal: int DistanciaFuerzaBruta(string S1, string S2)
        Parámetros: Dos cadenas, S1 y S2, que representan las secuencias a comparar.
        Retorno: Un valor entero que representa la distancia mínima de edición entre S1 y S2.
        Descripción: Calcula la distancia de edición probando recursivamente todas las combinaciones posibles de operaciones (inserción, eliminación, sustitución y transposición), seleccionando el costo mínimo en cada paso. Este método tiene una complejidad exponencial, lo que lo hace ineficiente para cadenas largas.
        Salida: El costo mínimo de edición entre las cadenas.

# funciones.h
Este archivo de cabecera contiene las declaraciones de funciones y variables necesarias para el proyecto:
    Declaraciones de funciones:
        cargarCostoVector(const string& nombreArchivo, vector<int>& tabla): Carga los costos de inserción o eliminación desde un archivo.
        cargarCostoMatriz(const string& nombreArchivo, vector<vector<int>>& tabla): Carga los costos de sustitución o transposición entre pares de caracteres desde un archivo.
        costo_ins(char b), costo_del(char a), costo_sub(char a, char b), costo_trans(char a, char b): Obtienen el costo de las operaciones según el carácter o caracteres involucrados.
    Variables globales:
        tabla_costo_insercion, tabla_costo_eliminacion, tabla_costo_sustitucion, tabla_costo_transposicion: Vectores que almacenan los costos de las operaciones, cargados desde archivos.

# funciones.cpp
Contiene la implementación de las funciones definidas en funciones.h.
    Función cargarCostoVector:
        Carga costos de inserción o eliminación desde un archivo en un vector tabla.
    Función cargarCostoMatriz:
        Carga los costos de sustitución o transposición en una matriz tabla, cada celda representa el costo de cambiar un carácter a otro.
    Funciones costo_ins, costo_del, costo_sub, costo_trans:
        Acceden a los costos para las operaciones respectivas entre caracteres.

# Archivos de Costos
Los siguientes archivos contienen los costos de las operaciones para cada carácter:
    cost_insert.txt: Costos de inserción.
    cost_delete.txt: Costos de eliminación.
    cost_replace.txt: Costos de sustitución.
    cost_transpose.txt: Costos de transposición.

## Uso
Compilar los archivos:
```
g++ DPdistancia.cpp funciones.cpp -o DPdistancia
g++ FBdistancia.cpp funciones.cpp -o FBdistancia
```
Ejecutar el programa de distancia de programación dinámica:
```
./DPdistancia
```
El programa solicitará dos cadenas de texto y mostrará la distancia mínima de edición usando programación dinámica.

Ejecutar el programa de distancia de fuerza bruta:
```
./FBdistancia
```
Este programa también solicitará dos cadenas y calculará la distancia de edición mediante fuerza bruta.

Notas Adicionales

Este proyecto proporciona una comparación entre dos enfoques para el cálculo de distancias de edición. El enfoque de DP es más eficiente para cadenas largas, mientras que el enfoque de fuerza bruta es más adecuado para comparar resultados o estudiar el comportamiento del cálculo en cadenas cortas.
