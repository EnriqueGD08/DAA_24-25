/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Diseño y Análisis de Algoritmos
 * Curso: 3º
 * Práctica 1
 * @autor: Enrique Gómez Díaz
 * @mail: alu0101550329@ull.edu.es
 * @date: 11/02/2025
 * @brief main del análisis de algoritmos
*/

#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include "multiplicador_matrices.h"
#include "multiplicacion_filas.h"
#include "multiplicacion_columnas.h"

/**
 * @brief Genera una matriz de tamaño filas x columnas con valores aleatorios
 * @param filas Número de filas
 * @param columnas Número de columnas
 * @return Matriz generada
 */
std::vector<std::vector<int>> generateRandomMatrix(int filas, int columnas) {
  std::vector<std::vector<int>> matriz(filas, std::vector<int>(columnas));
  for (int i = 0; i < filas; ++i) {
    for (int j = 0; j < columnas; ++j) {
      matriz[i][j] = rand() % 10;
    }
  }

  return matriz;
}

/**
 * @brief Calcula el tiempo de ejecución de la multiplicación de dos matrices
 * @param estrategia Estrategia de multiplicación
 * @param size Tamaño de las matrices
 */
void TiempoEjecucion(MatrizMultiplicacionEstrategia* estrategia, int size) {
  std::vector<std::vector<int>> A = generateRandomMatrix(size, size);
  std::vector<std::vector<int>> B = generateRandomMatrix(size, size);
  MultipicadorMatrices multiplicacion(estrategia);
  
  auto start = std::chrono::high_resolution_clock::now();
  std::vector<std::vector<int>> C = multiplicacion.multiplicar(A, B);
  auto stop = std::chrono::high_resolution_clock::now();
  
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
  std::cout << "Tiempo para matrices " << size << "x" << size << ": " << duration.count() << " ms" << std::endl;
}

/**
 * @brief Función principal
 */
int main() {
  srand(time(0));
  
  MultiplicacionFilas mul_filas;
  MultiplicacionColumnas mul_columnas;
  
  std::cout << "=== Multiplicación por filas ===" << std::endl;
  for (int tamanio = 100; tamanio <= 1000; tamanio += 100) {
    TiempoEjecucion(&mul_filas, tamanio);
  }

  std::cout << std::endl;
  
  std::cout << "=== Multiplicación por columnas ===" << std::endl;
  for (int tamanio = 100; tamanio <= 1000; tamanio += 100) {
    TiempoEjecucion(&mul_columnas, tamanio);
  }
  
  return 0;
}