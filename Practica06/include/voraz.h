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
 * @brief: cabecera de la clase Voraz
*/

#pragma once

#include "algoritmo.h"

class Voraz : public Algoritmo {
 public:
  Voraz(Problema& problema) : Algoritmo(problema) {}
  ~Voraz() override = default;

  void resolver() override;
  virtual std::string toCSV() override;

 private:
  void construccion();
};