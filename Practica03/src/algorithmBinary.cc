/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 * Práctica 3: Algoritmos Divide y Vencerás
 *
 * @author Enrique Gómez Díaz
 * @date 11 Mar 2025
 * @brief implementation of the AlgorithmBinary class
 */

#include "algorithmBinary.h"
#include "solutionBinary.h"

/**
 * @brief divide el problema en subproblemas
 * @param num número de subproblemas
 * @return vector de subproblemas
 */
std::vector<Algorithm*> AlgorithmBinary::Divide(int num) {
  int mid = (left_ + right_) / 2;
  std::vector<Algorithm*> sub_problemas;

  if (secuencia_[mid] == pivote_) {
    pos_ = mid;
    sub_problemas.push_back(new AlgorithmBinary(secuencia_, pivote_, left_, right_, pos_));
    return sub_problemas;
  } else {
    if (secuencia_[mid] > pivote_) {
      right_ = mid - 1;
      sub_problemas.push_back(new AlgorithmBinary(secuencia_, pivote_, left_, right_, pos_));
    } else {
      left_ = mid + 1;
      sub_problemas.push_back(new AlgorithmBinary(secuencia_, pivote_, left_, right_, pos_));
    }
  }
  return sub_problemas;
}

/**
 * @brief resuelve el problema cuando es pequeño
 * @param solution solución del problema
 */
void AlgorithmBinary::SolveSmall(Solution* solucion) {
  ((SolutionBinary*)solucion)->SetSolution(pos_);
}