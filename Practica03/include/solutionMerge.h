/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 * Práctica 3: Algoritmos Divide y Vencerás
 *
 * @author Enrique Gómez Díaz
 * @date 11 Mar 2025
 * @brief declaration of the SolutionMerge class
 */


#pragma once

#include "solution.h"
#include <vector>

class SolutionMerge : public Solution {
 public:
  SolutionMerge() {}
  ~SolutionMerge() {}
  void Print() override;
  void MergeSolutions(std::vector<Solution*>) override;
  Solution* GetInstance() override { return new SolutionMerge(); }
  inline std::vector<int> GetSecuencia() { return secuencia_; }
  void SetSecuencia(std::vector<int> secuencia) { secuencia_ = secuencia; }

 private:
  std::vector<int> secuencia_;
};
