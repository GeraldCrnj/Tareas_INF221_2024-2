#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include <fstream>

using namespace std;

vector<int> selSort(vector<int> v){
  size_t n = v.size();
  int menor;
  for (int i = 0; i < n; i++){
    menor = i;
    for (int j = i + 1; j < n; j++){
      if (v[j] < v[menor]) menor = j;
      swap(v[menor], v[i]);
    }
  }
  return v;
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
  vec = selSort(vec);
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
