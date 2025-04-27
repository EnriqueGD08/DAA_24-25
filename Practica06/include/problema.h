/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Diseño y Análisis de Algoritmos
 * Curso: 3º
 * Práctica 6
 * @autor: Enrique Gómez Díaz
 * @mail: alu0101550329@ull.edu.es
 * @date: 06/05/2025
 * @brief: cabecera de la clase Problema
*/

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

#include "error.h"
#include "punto.h"

class Problema {
 public:
  Problema();
  Problema(std::ifstream& archivo);
  ~Problema();

  int getNumeroPuntos() const { return numero_puntos_; }
  int getDimensiones() const { return dimensiones_; }
  const std::vector<Punto>& getPuntos() const { return puntos_; }

  friend std::ostream& operator<<(std::ostream& os, const Problema& problema);

 private:
  std::vector<Punto> puntos_ = {};
  int numero_puntos_ = 0;
  int dimensiones_ = 0;
};