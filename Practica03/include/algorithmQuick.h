/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 * Práctica 3: Algoritmos Divide y Vencerás
 *
 * @author Enrique Gómez Díaz
 * @date 11 Mar 2025
 * @brief declaration of the AlgorithmQuick class
 */

#pragma once

#include "algorithm.h"
#include "solutionQuick.h"

class AlgorithmQuick : public Algorithm {
 public:
  AlgorithmQuick(std::vector<int> secuencia) { secuencia_ = secuencia; }
  ~AlgorithmQuick() {}

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