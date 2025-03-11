/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 * Práctica 3: Algoritmos Divide y Vencerás
 *
 * @author Enrique Gómez Díaz
 * @date 11 Mar 2025
 * @brief declaration of the AlgorithmMerge class
 */

#pragma once

#include "algorithm.h"
#include "solutionMerge.h"

class AlgorithmMerge : public Algorithm {
 public:
  AlgorithmMerge(std::vector<int> secuencia) { secuencia_ = secuencia; }
  ~AlgorithmMerge() {}

  bool IsSmall() override { return (secuencia_.size() <= 2); }
  bool IsSort() { return true; }
  bool IsSearch() { return false; }
  std::vector<Algorithm*> Divide(int num) override;
  void SolveSmall(Solution*) override;

  std::string GetA() override { return "2"; }
  std::string GetB() override { return "n/2"; }
  std::string GetD() override { return "1"; }

 private:
  std::vector<int> secuencia_;
};