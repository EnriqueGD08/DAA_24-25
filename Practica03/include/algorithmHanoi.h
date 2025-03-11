/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 * Práctica 3: Algoritmos Divide y Vencerás
 *
 * @author Enrique Gómez Díaz
 * @date 11 Mar 2025
 * @brief declaration of the AlgorithmHanoi class
 */

#pragma once

#include "algorithm.h"
#include "solutionHanoi.h"
#include <vector>

class AlgorithmHanoi: public Algorithm {
 public:
  AlgorithmHanoi(int n, std::string& origen, std::string& destino, std::string& aux, std::vector<std::string> movimientos = {}):
                 n_(n), origen_(origen), destino_(destino), aux_(aux), movimientos_(movimientos) {}
  ~AlgorithmHanoi() {}
  
  bool IsSmall() override{ return n_ == 1; }
  std::vector<Algorithm*> Divide(int num) override;
  void SolveSmall(Solution*) override;

  std::string GetA() override { return "2"; }
  std::string GetB() override { return "n-1"; }
  std::string GetD() override { return "1"; }

 private:
  int n_;
  std::string origen_;
  std::string destino_;
  std::string aux_;
  std::vector<std::string> movimientos_;

};