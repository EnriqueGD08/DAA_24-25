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
 * @brief: declaración clase InstruccionDIV
*/


#pragma once

#include <iostream>

#include "instruccion.h"

class InstruccionDIV : public Instruccion {
 public:
  InstruccionDIV() {};
  InstruccionDIV(std::string& instruccion) { parsear(instruccion); }
  virtual ~InstruccionDIV() {};
  void ejecutar(Contexto& contexto) override; 
  void parsear(std::string& instruccion) override; 

 private:
  int operando_;
};