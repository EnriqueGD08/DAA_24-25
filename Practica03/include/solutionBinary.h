/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 * Práctica 3: Algoritmos Divide y Vencerás
 *
 * @author Enrique Gómez Díaz
 * @date 11 Mar 2025
 * @brief declaration of the SolutionBinary class
 */

#pragma once

#include "solution.h"
#include <iostream>

class SolutionBinary: public Solution {

 public:
  SolutionBinary() {}
  virtual ~SolutionBinary() {}

  void Print() override;
  void MergeSolutions(std::vector<Solution*>) override;

  Solution* GetInstance() override { return new SolutionBinary(); }
  int GetPosition() { return posicion_; }
  void SetSolution(int pos) { posicion_ = pos; }

 private:
  int posicion_ = -1;
};
