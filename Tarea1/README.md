# Tarea 1 - Dividir y Conquistar

En esta carpeta se encuentran los distintos algoritmos analizados en el informe subido a aula.

# Descripción archivos carpetas
## Carpeta "Algoritmos de Ordenamientos"
* GeneradorDataset.py : Programa python diseñado para poder crear datasets para los algoritmos de ordenamiento, explicado en Informe. Se debe ingresar número de elementos a ordenar.
* SortingBiblio.cpp : Programa en C++ diseñado para poder ordenar un vector usando la función implementada por la librería ..
* SelectionSort.cpp : Programa en C++ diseñado para poder ordenar un vector usando el algoritmo Selection Sort.
* MergeSort.cpp : Programa en C++ diseñado para poder ordenar un vector usando el algoritmo Merge Sort.
* QuickSort.cpp : Programa en C++ diseñado para poder ordenar un vector usando el algoritmo Quick Sort.

* Cada progama posee dos secciones comentadas, una donde se muestra el vector a ordenar y la segunda donde se muestra el vector ordenado, se recomienda no descomentar ya que al poseer grandes cantidades de elementos ocupa todo el espacio en terminal, aún así queda a elección de quién utilice el programa.

## Carpeta "Algoritmos de Multiplicación de Matrices"
* GeneradorDatasetMatriz.py : Programa python diseñado para poder crear datasets para los algoritmos de multiplicación de matrices, explicado en Informe. Se debe ingresar la dimensión de las matrices cuadradas, se asume que el número ingresado será una potencia de 2, restricción de algoritmo de Strassen.
* CubicoTradicional.cpp : Programa en C++ diseñado para multiplicar dos matrices utilizando el algoritmo cúbico tradicional.
* CubicoOptimizado.cpp : Programa en C++ diseñado para multiplicar dos matrices utilizando el algoritmo cúbico optimizado (matriz compuesta).
* Strassen.cpp : Programa en C++ diseñado para multiplicar dos matrices utilizando el algoritmo de Strassen.

- Cada progama posee dos secciones comentadas, una donde se muestran las matrices a multiplicar y la segunda donde se muestra la matriz resultante, se recomienda no descomentar ya que al poseer grandes cantidades de elementos ocupa todo el espacio en terminal, aún así queda a elección de quién utilice el programa.

## Carpeta "Datasets Ordenamiento"
* Carpeta posee datasets en formato ".txt" dados para probar los algoritmos usados para creación de informe, al momento de querer usar un dataset mover a carpeta "Algoritmos de Ordenamientos", si se trata de el archivo "dataset1.txt" modificar y dejar como "dataset.txt", ya que así los lee el programa de cada algoritmo.

## Carpeta "Datasets Matrices"
* Carpeta posee datasets en formato ".txt" dados para probar los algoritmos usados para creación de informe, al momento de querer usar un dataset mover a carpeta "Algoritmos de Multiplicación de Matrices", si se trata de el archivo "dataset1.txt" modificar y dejar como "dataset.txt", ya que así los lee el programa de cada algoritmo.

# Instrucciones de complicaciones
Todos los programas fueron compilados y ejecutados en Ubuntu 22.04.
Para compilar los programas correspondientes a la creación de datasets utilizar el siguiente comando:
* python3 GeneradorDataset.py
* python3 GeneradorDatasetMatriz.py
Para compilar los programas correspondientes a algoritmos utilizar el siguiente comando:
* g++ -o algoritmo algoritmo.cpp
Reemplazando "algoritmo" para el algoritmo a ejecutar, se recomienda mantener los nombres de los ejecutables por nombre de algoritmo para poder comparar los tiempos con el mismo dataset de forma más ordenada.
Luego para ejecutar el programa se utiliza el comando:
* ./algoritmo

## Cualquier duda o sugerencia enviar correo a: geraldine.cornejo@usm.cl
