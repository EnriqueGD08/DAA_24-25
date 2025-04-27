/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Diseño y Análisis de Algoritmos
 * Curso: 3º
 * Práctica 6
 * @autor: Enrique Gómez Díaz
 * @mail: alu0101550329@ull.edu.es
 * @date: 06/05/2025
 * @brief: implementación de la clase GRASP
*/

#include "grasp.h"

/**
 * @brief Resuelve el problema utilizando el algoritmo GRASP.
 * @return void
 */
void GRASP::resolver() {
  auto start = std::chrono::high_resolution_clock::now();

  // Implementación del algoritmo GRASP

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = end - start;
  tiempo_ejecucion_ = elapsed.count();
}