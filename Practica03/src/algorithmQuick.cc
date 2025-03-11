/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 * Práctica 3: Algoritmos Divide y Vencerás
 *
 * @author Enrique Gómez Díaz
 * @date 11 Mar 2025
 * @brief implementation of the AlgorithmQuick class
 */

#include "algorithmQuick.h"

/**
 * @brief divide el problema en subproblemas
 * @param num número de subproblemas
 * @return vector de subproblemas
 */
std::vector<Algorithm*> AlgorithmQuick::Divide(int num = 2) {
  std::vector<Algorithm*> subProblemas;
  int pivote = secuencia_[secuencia_.size() - 1];
  int i = 0;
  for (int j = 0; j < (int)secuencia_.size(); j++) {
    if (secuencia_[j] <= pivote) {
      int aux = secuencia_[j];
      secuencia_[j] = secuencia_[i];
      secuencia_[i] = aux;
      if(i < (int)secuencia_.size() - 1) i++;
    }
  }
  int aux = secuencia_[i];
  secuencia_[i] = secuencia_[secuencia_.size() - 1];
  secuencia_[secuencia_.size() - 1] = aux;

  subProblemas.push_back(new AlgorithmQuick(std::vector<int>(secuencia_.begin(), secuencia_.begin() + i)));
  subProblemas.push_back(new AlgorithmQuick(std::vector<int>(secuencia_.begin() + i, secuencia_.end())));
  return subProblemas;
}

/**
 * @brief resuelve el problema cuando es pequeño
 * @param solucion solución del problema
 */
void AlgorithmQuick::SolveSmall(Solution* solucion) {
  if ((int)secuencia_.size() > 1 && secuencia_[1] < secuencia_[0]) {
    int aux = secuencia_[0];
    secuencia_[0] = secuencia_[1];
    secuencia_[1] = aux;
  }
  ((SolutionQuick*)solucion)->SetSecuencia(secuencia_);
}