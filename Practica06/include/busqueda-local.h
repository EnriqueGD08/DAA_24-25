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
 * @brief: cabecera de la clase BusquedaLocal
*/

#pragma once

#include "algoritmo.h"

class BusquedaLocal : public Algoritmo {
 public:
  BusquedaLocal(Problema& problema) : Algoritmo(problema) {}
  ~BusquedaLocal() override = default;

  void resolver() override;
};