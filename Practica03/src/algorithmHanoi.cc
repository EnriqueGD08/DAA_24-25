/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 * Práctica 3: Algoritmos Divide y Vencerás
 *
 * @author Enrique Gómez Díaz
 * @date 11 Mar 2025
 * @brief implementation of the AlgorithmHanoi class
 */

#include "algorithmHanoi.h"
#include "solutionHanoi.h"

/**
 * @brief Divide el problema en subproblemas
 * @param num Número de subproblemas
 * @return Vector con los subproblemas
 */
std::vector<Algorithm*> AlgorithmHanoi::Divide(int num) {
  std::vector<Algorithm*> subProblemas;
  if (n_ != 1) {
    subProblemas.push_back(new AlgorithmHanoi(n_ - 1, origen_, aux_, destino_, movimientos_));
    movimientos_.push_back("Disco " + std::to_string(n_) + " de " + origen_ + " a " + destino_);
    subProblemas.push_back(new AlgorithmHanoi(n_ - 1, aux_, destino_, origen_, movimientos_));
    return subProblemas;
  }
  return subProblemas;
}

/**
 * @brief Resuelve el problema cuando es pequeño
 * @param solution Solución del problema
 */
void AlgorithmHanoi::SolveSmall(Solution* solution) {
  std::string moviento = "Disco " + std::to_string(n_) + " de " + origen_ + " a " + destino_;
  movimientos_.push_back(moviento);
  ((SolutionHanoi*)solution)->SetSolution(movimientos_);
}