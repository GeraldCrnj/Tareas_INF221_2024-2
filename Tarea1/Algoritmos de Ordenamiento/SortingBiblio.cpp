#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>

using namespace std;

int main() {
  vector<int> vec = {38, 27, 43, 3, 9, 82, 10};
  cout << "Vector original: ";
  for (int num : vec) {
      cout << num << " ";
  }
  cout << endl;

  auto start = std::chrono::high_resolution_clock::now();
  sort(vec.begin(), vec.end());
  auto end = std::chrono::high_resolution_clock::now();
  chrono::duration<double> elapsed = end - start;
  cout << "Tiempo de ejecución: " << elapsed.count() << " segundos" << std::endl;

  cout << "Vector ordenado: ";
  for (int num : vec) {
      cout << num << " ";
  }
  cout << endl;

  return 0;
}
