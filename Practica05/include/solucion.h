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
 * @brief: cabecera de la clase Solucion
*/

#pragma once

#include <vector>
#include "nodo.h"

class Solucion {
 public:
  Solucion() : subrutas_(0) {}
  ~Solucion() {}

  void agregar_camion() { camiones_++; }

  void set_nodos(const std::vector<Nodo>& nodos) { nodos_ = nodos; }
  void set_subrutas(int subrutas) { subrutas_ = subrutas; }
  void set_camiones(int camiones) { camiones_ = camiones; }
  const std::vector<Nodo>& get_nodos() const { return nodos_; }
  int get_subrutas() const { return subrutas_; }
  int get_camiones() const { return camiones_; }
 
 private:
  std::vector<Nodo> nodos_;
  int subrutas_;
  int camiones_ = 0;
 };