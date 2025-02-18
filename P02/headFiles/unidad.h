/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Diseño y Análisis de Algoritmos
 * Curso: 2º
 * Práctica 2
 * @autor: Enrique Gómez Díaz
 * @mail: alu0101550329@ull.edu.es
 * @date: 18/02/2025
 * @brief declaración de la clase Unidad
*/

#pragma once

#include <iostream>
#include <vector>

class Unidad {
 public:
  Unidad() {cabezal_ = 0;}
  ~Unidad() {};
  std::ostream& imprimir(std::ostream& os);

 protected:
  std::vector<int> datos_;
  int cabezal_;
};