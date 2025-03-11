/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 * Práctica 3: Algoritmos Divide y Vencerás
 *
 * @author Enrique Gómez Díaz
 * @date 11 Mar 2025
 * @brief implementation of the SolutionBinary class
 */

#include "solutionBinary.h"

/**
 * @brief Imprime la solución
 */
void SolutionBinary::Print() {
  if (posicion_ == -1) {
    std::cout << "El elemento no se encuentra en la secuencia." << std::endl;
  } else {
    std::cout << "El elemento se encuentra en la posición " << posicion_ << std::endl;
  }
}

/**
 * @brief Fusiona las soluciones
 * @param soluciones Vector con las soluciones a fusionar
 */
void SolutionBinary::MergeSolutions(std::vector<Solution*> soluciones) {
  for (auto* solucion : soluciones) {
    if (solucion != nullptr && ((SolutionBinary*)solucion)->GetPosition() != -1) {
      posicion_ = ((SolutionBinary*)solucion)->GetPosition();
      return;
    }
  }
}