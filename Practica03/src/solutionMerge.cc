/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 * Práctica 3: Algoritmos Divide y Vencerás
 *
 * @author Enrique Gómez Díaz
 * @date 11 Mar 2025
 * @brief implementation of the SolutionMerge class
 */

#include "solutionMerge.h"

/**
 * @brief Muestra la solución
 */
void SolutionMerge::Print() {
  std::cout << "[ ";
  for (auto elemento : secuencia_) {
    std::cout << elemento << " ";
  }
  std::cout << "]\n";
}

/**
 * @brief Fusiona las soluciones
 * @param subSoluciones Vector con las soluciones a fusionar
 */
void SolutionMerge::MergeSolutions(std::vector<Solution*> subsoluciones) {
  if (subsoluciones.empty()) return;

  secuencia_ = ((SolutionMerge*)subsoluciones[0])->GetSecuencia();

  for (size_t k = 1; k < subsoluciones.size(); ++k) {
    std::vector<int> siguiente_secuencia = ((SolutionMerge*)subsoluciones[k])->GetSecuencia();
    std::vector<int> combinaciones;

    int i = 0, j = 0;
    while (i < (int)secuencia_.size() && j < (int)siguiente_secuencia.size()) {
      if (secuencia_[i] <= siguiente_secuencia[j]) {
        combinaciones.push_back(secuencia_[i]);
        i++;
      } else {
        combinaciones.push_back(siguiente_secuencia[j]);
        j++;
      }
    }
    while (i < (int)secuencia_.size()) {
      combinaciones.push_back(secuencia_[i]);
      i++;
    }
    
    while (j < (int)siguiente_secuencia.size()) {
      combinaciones.push_back(siguiente_secuencia[j]);
      j++;
    }
    secuencia_ = combinaciones;
  }
}