/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 * Práctica 3: Algoritmos Divide y Vencerás
 *
 * @author Enrique Gómez Díaz
 * @date 11 Mar 2025
 * @brief declaration of the Framework class
 */

#pragma once

#include <vector>
#include <utility>
#include <iostream>
#include "algorithm.h"
#include "solution.h"

class Framework {
  public:
  Framework() {};
  virtual ~Framework() {};
  void DivideyVenceras(Algorithm*, Solution*, int profundidad);
  void PrintRecurrencia(Algorithm*);
  int getNivelMaximoRecursion() { return nivelMaximoRecursion_; };
  int getContadorTotalRecursion() { return contadorTotalRecursion_; };

 private:
  int nivelMaximoRecursion_ = 0;
  int contadorTotalRecursion_ = 0;
};
