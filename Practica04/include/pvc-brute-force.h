/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Diseño y Análisis de Algoritmos
 * Curso: 2º
 * Práctica 4
 * @autor: Enrique Gómez Díaz
 * @mail: alu0101550329@ull.edu.es
 * @date: 18/03/2025
 * @brief: Cabecera de la clase PVCBruteForce
*/

#pragma once

#include "pvc-algorithm.h"
#include <chrono>
#include <algorithm>
#include <limits>

class PVCBruteForce : public PVCAlgorithm {
 public:
  void execute(Graph& graph) override;
  std::vector<std::string> getSolution() override;
  int getSolutionCost() override;

 private:
  std::vector<std::string> solution_;
  int solution_cost_;
};