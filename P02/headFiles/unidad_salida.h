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
 * @brief declaración de la clase UnidadSalida
*/

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "unidad.h"

class UnidadSalida : public Unidad {
 public:
  UnidadSalida() { Unidad(); }
  ~UnidadSalida() {};
  
  void escribir(int valor);
  void escribir_fichero(std::string& nombre_fichero); 
};