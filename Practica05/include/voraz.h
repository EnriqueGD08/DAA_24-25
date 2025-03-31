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
 * @brief: cabecera de la clase Voraz
*/

#pragma once

#include "algoritmo.h"
#include "problema.h"
#include "solucion.h"
#include "nodo.h"
#include <climits>


class Voraz : public Algoritmo {
 public:
  Voraz(Problema problema) : Algoritmo(problema) {}
  ~Voraz() {}
  void resolver() override;

 private:
  int puede_visitar(Nodo& nodo, float tiempo_actual, float carga_actual);
};