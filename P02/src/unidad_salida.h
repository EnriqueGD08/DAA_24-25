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
 * @brief declaración de la clase UnidadSalida
*/

#pragma once

#include "instrucciones/write.h"

class UnidadSalida : protected Write {
 public:
  UnidadSalida();
  ~UnidadSalida();
  void ejecutar();
  // void escribir(); 
};