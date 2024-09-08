#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include <fstream>

using namespace std;

void quickSort(vector<int>& v, int inicio, int final){
  if (inicio < final){
    int pivote = v[final];
    int i = inicio - 1;
    for (int j = inicio; j < final; j++){
      if (v[j] < pivote){
        i++;
        swap(v[i], v[j]);
      }
    }
    swap(v[i+1], v[final]);
    int posicion_pivote = i + 1;
    quickSort(v, inicio, posicion_pivote - 1);
    quickSort(v, posicion_pivote + 1, final);
  }
}

vector<int> readDataset(const string& filename) {
    vector<int> vec;
    ifstream file(filename);
    int num;
    while (file >> num) {
        vec.push_back(num);
    }
    file.close();
    return vec;
}

int main() {
  string filename = "dataset.txt";
  vector<int> vec = readDataset(filename);

  /*cout << "Vector original: ";
  for (int num : vec) {
      cout << num << " ";
  }
  cout << endl;*/

  auto start = std::chrono::high_resolution_clock::now();
  quickSort(vec, 0, vec.size() - 1);
  auto end = std::chrono::high_resolution_clock::now();
  chrono::duration<double> elapsed = end - start;
  cout << "Tiempo de ejecución: " << elapsed.count() << " segundos" << std::endl;

  /*cout << "Vector ordenado: ";
  for (int num : vec) {
      cout << num << " ";
  }
  cout << endl;*/
  return 0;
}
