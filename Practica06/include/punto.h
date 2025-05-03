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
 * @brief: cabecera de la clase Punto
*/

#pragma once

#include <iostream>
#include <cmath>
#include <vector>

#include "error.h"

class Punto {
 public:
  Punto();
  Punto(std::vector<double> coordenadas);
  ~Punto();

  double getCoordenada(int i) const;
  void setCoordenada(int i, double valor);

  int getDimensiones() const;
  int getId() const { return id_; }
  void setDimensiones(int dimensiones);
  void setId(int id) { id_ = id; }

  double distancia(const Punto& otro) const;
  double distancia(const std::vector<Punto>& puntos) const;
  void pushCoordenada(double coordenada);
  std::string toString() const;

  friend std::ostream& operator<<(std::ostream& os, const Punto& punto);
  bool operator==(const Punto& otro) const;
 
 private:
  int id_ = 0;
  std::vector<double> coordenadas_ = {};
};