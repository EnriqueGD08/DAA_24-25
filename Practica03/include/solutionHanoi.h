/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 * Práctica 3: Algoritmos Divide y Vencerás
 *
 * @author Enrique Gómez Díaz
 * @date 11 Mar 2025
 * @brief declaration of the SolutionHanoi class
 */

#pragma once

#include "solution.h"
#include <iostream>

class SolutionHanoi: public Solution {

 public:
  SolutionHanoi() {}
  virtual ~SolutionHanoi() {}

  void Print() override;
  void MergeSolutions(std::vector<Solution*>) override;

  Solution* GetInstance() override { return new SolutionHanoi(); }
  std::vector<std::string> GetMovimientos() { return movimientos_; }
  void SetSolution(std::vector<std::string> movimientos) { movimientos_ = movimientos; }

 private:
  std::vector<std::string> movimientos_;
};