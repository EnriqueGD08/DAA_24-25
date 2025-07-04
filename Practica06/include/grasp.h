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
 * @brief: cabecera de la clase GRASP
*/

#pragma once

#include "algoritmo.h"

class GRASP : public Algoritmo {
 public:
  GRASP(Problema& problema) : Algoritmo(problema) {}
  ~GRASP() override = default;

  int getLRC() const { return LRC_; }

  void setLRC(int lrc) { LRC_ = lrc; }

  void resolver() override;
  virtual std::string toCSV() override;

 private:
  void construccion();
  int LRC_ = 3;
};