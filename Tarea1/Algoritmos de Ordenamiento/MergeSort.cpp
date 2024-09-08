#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include <fstream>

using namespace std;

vector<int> mergeSort(vector<int> v){
  int n = v.size();
  if (n <= 1) return v;
  int mid = n / 2;
  vector<int> v1(v.begin(), v.begin() + mid);
  vector<int> v2(v.begin() + mid, v.end());
  v1 = mergeSort(v1);
  v2 = mergeSort(v2);
  vector<int> resultado(v1.size() + v2.size());
  merge(v1.begin(), v1.end(), v2.begin(), v2.end(), resultado.begin());
  return resultado;
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
  vec = mergeSort(vec);
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
