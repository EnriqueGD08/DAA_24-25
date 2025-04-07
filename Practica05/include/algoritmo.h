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
 * @brief: cabecera de la clase Algoritmo
*/

#pragma once

#include "problema.h"
#include "solucion.h"

const float INFINITO = std::numeric_limits<float>::max();

class Algoritmo {
 public:
  Algoritmo(Problema problema) : problema_(problema) {}
  virtual ~Algoritmo() {}
  virtual void resolver() = 0;
  Solucion obtener_solucion() const {
    return solucion_;
  }
 
 protected:
  Problema problema_;
  Solucion solucion_;
  int puede_visitar(Nodo& nodo_actual, Nodo& nodo_destino, float tiempo_actual, float carga_actual);
};