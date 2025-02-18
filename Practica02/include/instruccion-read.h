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
 * @brief: declaración clase InstruccionREAD
*/


#pragma once

#include <iostream>
#include <string>

#include "instruccion.h"

class InstruccionREAD : public Instruccion {
 public:
  InstruccionREAD() {};
  InstruccionREAD(std::string& instruccion) { parsear(instruccion); }
  virtual ~InstruccionREAD() {};
  void ejecutar(Contexto& contexto) override; 
  void parsear(std::string& instruccion) override; 

 private:
  int operando_;
};