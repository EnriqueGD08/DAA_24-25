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
 * @brief declaración de la clase MemoriaDatos
*/

#pragma once

#include <iostream>
#include <vector>

class MemoriaDatos {
 public:
  MemoriaDatos() {}
  ~MemoriaDatos() {};

  int getValor(int indice) {return memoria_[indice];}
  void setValor(int valor) {memoria_[0] = valor;}
  void guardar_valor(int indice, int valor);
  
 private:
  std::vector<int> memoria_ = {0};
};

// std::ostream& operator<<(std::ostream& os, MemoriaDatos& memoria_datos);