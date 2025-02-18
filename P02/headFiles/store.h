/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Diseño y Análisis de Algoritmos
 * Curso: 2º
 * Práctica 2
 * @autor: Enrique Gómez Díaz
 * @mail: alu0101550329@ull.edu.es
 * @date: 18/02/2025
 * @brief declaración de la clase instrucción store
*/

#pragma once

#include "instruccion.h"

class Store : public Instruccion {
 public:
  Store() {};
  Store(std::string& instruccion) { parsear(instruccion); }
  virtual ~Store() {};
  void ejecutar(Contexto& contexto) override;
  void parsear(std::string& instruccion) override;

 private:
  int operando_;
};