/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 * Práctica 3: Algoritmos Divide y Vencerás
 *
 * @author Enrique Gómez Díaz
 * @date 11 Mar 2025
 * @brief implementation of the AlgorithmMerge class
 */

#include "algorithmMerge.h"

/**
 * @brief Divide el problema en subproblemas
 * @param num Número de subproblemas
 * @return Vector con los subproblemas
 */
std::vector<Algorithm*> AlgorithmMerge::Divide(int num = 2) {
  std::vector<Algorithm*> subproblemas;
  for (int i = 0; i < num; i++) {
    std::vector<int>::iterator inicio = secuencia_.begin() + secuencia_.size() * i / num;
    std::vector<int>::iterator final = secuencia_.begin() + secuencia_.size() * (i + 1) / num;
    subproblemas.push_back(new AlgorithmMerge(std::vector<int>(inicio, final)));
  }
  return subproblemas;
}

/**
 * @brief Resuelve el problema pequeño
 * @param solucion Puntero a una solución
 */
void AlgorithmMerge::SolveSmall(Solution* solucion) {
  if ((int)secuencia_.size() > 1 && secuencia_[1] < secuencia_[0]) {
    int aux = secuencia_[0];
    secuencia_[0] = secuencia_[1];
    secuencia_[1] = aux;
  }
  ((SolutionMerge*)solucion)->SetSecuencia(secuencia_);
}

