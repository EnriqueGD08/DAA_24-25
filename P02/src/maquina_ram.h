/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Diseño y Análisis de Algoritmos
 * Curso: 2º
 * Práctica 3
 * @autor: Enrique Gómez Díaz
 * @mail: alu0101550329@ull.edu.es
 * @date: 18/02/2025
 * @brief declaración de la clase máquina RAM
*/

#pragma once

#include <vector>

class MaquinaRam {
 public:
  MaquinaRam();
  ~MaquinaRam();

 protected:
  std::vector<std::string> instrucciones_;
  std::vector<std::vector<int>> memoria_;
  int contador_instrucciones_ = 0;
  int contador_programa_ = 0;
};