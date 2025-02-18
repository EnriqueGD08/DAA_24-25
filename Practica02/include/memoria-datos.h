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
 * @brief: declaración clase MemoriaDatos
*/


#pragma once

#include <iostream>
#include <vector>

class MemoriaDatos {
 public:
  MemoriaDatos() {};
  ~MemoriaDatos() {};

  int get_valor(int registro) { return registros_[registro]; };
  void set_valor(int valor) { registros_[0] = valor; };
  void guardar_valor(int registro, int valor);
  friend std::ostream& operator<<(std::ostream& os, MemoriaDatos& memoria_datos);

 private:
  std::vector<int> registros_ = {0};
};