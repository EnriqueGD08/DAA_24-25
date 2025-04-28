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
 * @brief: cabecera de la clase Solucion
*/

#pragma once

#include <iostream>
#include <vector>

#include "error.h"
#include "punto.h"

class Solucion {
 public:
  Solucion() = default;
  Solucion(const std::vector<Punto>& puntos) : puntos_(puntos) { 
    valor_objetivo_ = calcularValorObjetivo(); 
  }
  ~Solucion() = default;
  
  const std::vector<Punto>& getPuntos() const { return puntos_; }
  int getTamanio() const { return puntos_.size(); }
  double getValorObjetivo() const { return valor_objetivo_; }

  void setPuntos(const std::vector<Punto>& puntos) { puntos_ = puntos;
                                                     valor_objetivo_ = calcularValorObjetivo(); }
  
  void pushPunto(const Punto& punto) { puntos_.push_back(punto); 
                                       valor_objetivo_ = calcularValorObjetivo(); }
  double calcularValorObjetivo();
  void clear() { puntos_.clear(); valor_objetivo_ = 0.0; }
  std::string toString() const;

 private:
  std::vector<Punto> puntos_ = {};
  double valor_objetivo_ = 0.0;
};