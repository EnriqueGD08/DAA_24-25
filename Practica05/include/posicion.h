/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Diseño y Análisis de Algoritmos
 * Curso: 2º
 * Práctica 5
 * @autor: Enrique Gómez Díaz
 * @mail: alu0101550329@ull.edu.es
 * @date: 25/03/2025
 * @brief: cabecera de la clase Posicion
*/

#pragma once

#include <algorithm>

class Posicion {
 public:
  Posicion(float x = 0, float y = 0) : x_(x), y_(y) {}
  ~Posicion() {}
  float calcular_distancia(const Posicion& posicion) {
    return abs(static_cast<int>(x_) - static_cast<int>(posicion.x_)) + abs(static_cast<int>(y_) - static_cast<int>(posicion.y_));
  }
  float get_x() const { return x_; }
  float get_y() const { return y_; }

 private:
  float x_;
  float y_;
};