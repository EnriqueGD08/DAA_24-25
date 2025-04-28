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
 * @brief: cabecera de la clase Algoritmo
*/

#pragma once

#include <iostream>
#include <chrono>

#include "error.h"
#include "solucion.h"
#include "problema.h"

class Algoritmo {
 public:
  Algoritmo(Problema& problema) : problema_(problema) {}
  virtual ~Algoritmo() = default;

  Problema getProblema() const { return problema_; }
  Solucion getSolucion() const { return solucion_; }
  double getTiempoEjecucion() const { return tiempo_ejecucion_; }

  void setProblema(const Problema& problema) { problema_ = problema; }
  void setSolucion(const Solucion& solucion) { solucion_ = solucion; }
  void setTamanioSolucion(int tamanio) { tamanio_solucion_ = tamanio; }

  virtual void resolver() = 0;
  Punto centroGravedad(const std::vector<Punto>& puntos);
  virtual std::string toCSV() = 0;

 protected:
  Problema problema_;
  Solucion solucion_;
  int tamanio_solucion_ = 2;
  double tiempo_ejecucion_ = 0;
};