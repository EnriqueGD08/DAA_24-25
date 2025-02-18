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
 * @brief: declaración clase CintaSalida
*/

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "cinta.h"

class CintaSalida : public Cinta {
 public:
  CintaSalida() { Cinta(); };
  ~CintaSalida() {};

  void escribir(int valor);
  void escribir_en_fichero(std::string& fichero);
};