/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 * Práctica 3: Algoritmos Divide y Vencerás
 *
 * @author Enrique Gómez Díaz
 * @date 11 Mar 2025
 * @brief implementation of the SolutionHanoi class
 */

#include "solutionHanoi.h"

/**
 * @brief Muestra la solución
 */
void SolutionHanoi::Print() {
  for (auto movimientos : movimientos_) {
    std::cout << movimientos << std::endl;
  }
}

/**
 * @brief Mezcla dos soluciones
 * @param sub_soluciones Vector de punteros a soluciones
 */
void SolutionHanoi::MergeSolutions(std::vector<Solution*> sub_soluciones) {
  for (auto sub_solucion : sub_soluciones) {
    std::vector<std::string> sub_movimientos = ((SolutionHanoi*)sub_solucion)->GetMovimientos();
    for (auto movimiento : sub_movimientos) {
      movimientos_.push_back(movimiento);
    }
  }
}