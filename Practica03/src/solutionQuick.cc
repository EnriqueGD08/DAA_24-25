/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 * Práctica 3: Algoritmos Divide y Vencerás
 *
 * @author Enrique Gómez Díaz
 * @date 11 Mar 2025
 * @brief implementation of the SolutionQuick class
 */

#include "solutionQuick.h"

/**
 * @brief Muestra la solución
 */
void SolutionQuick::Print() {
  std::cout << "[ ";
  for (auto elemento : secuencia_) {
    std::cout << elemento << " ";
  }
  std::cout << "]\n";
}

/**
 * @brief Mezcla dos soluciones
 * @param sub_soluciones Vector de punteros a soluciones
 */
void SolutionQuick::MergeSolutions(std::vector<Solution*> sub_soluciones) {
  std::vector<int> first = ((SolutionQuick*)sub_soluciones[0])->GetSecuenca();
  std::vector<int> second = ((SolutionQuick*)sub_soluciones[1])->GetSecuenca();
  first.insert(first.end(), second.begin(), second.end());
  secuencia_ = first;
}