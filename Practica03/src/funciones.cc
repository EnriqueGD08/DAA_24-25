#include <iostream>
#include <vector>
#include <chrono>

template<typename Func>
long long calcularTiempo(Func func) {
  auto start = std::chrono::high_resolution_clock::now();
  func();
  auto end = std::chrono::high_resolution_clock::now();
  return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}