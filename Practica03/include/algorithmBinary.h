/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 * Práctica 3: Algoritmos Divide y Vencerás
 *
 * @author Enrique Gómez Díaz
 * @date 11 Mar 2025
 * @brief declaration of the AlgorithmBinary class
 */

#pragma once

#include "algorithm.h"
#include "solutionBinary.h"
#include <vector>

class AlgorithmBinary: public Algorithm {

 public:
  AlgorithmBinary(std::vector<int>& secuencia, int pivote, int left, int right, int pos = -1):
                  secuencia_(secuencia), pivote_(pivote), left_(left), right_(right), pos_(pos) {}
  ~AlgorithmBinary() {}
  
  bool IsSmall() override { return (right_ < left_) || (pos_ != -1); }
  std::vector<Algorithm*> Divide(int num) override;
  void SolveSmall(Solution*) override;

  std::string GetA() override { return "1"; }
  std::string GetB() override { return "n/2"; }
  std::string GetD() override { return "1"; }

  private:
  std::vector<int> secuencia_;
  int pivote_;
  int left_;
  int right_;
  int pos_ = -1;
};