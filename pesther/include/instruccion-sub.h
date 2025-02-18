/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * @author Esther M. Quintero
 * @date 14 Feb 2024
 * @brief Encabezado de la clase "InstruccionSUB"
 *        (Principio ESTRATEGIA)
 */

#ifndef INSTRUCCION_SUB_H
#define INSTRUCCION_SUB_H

#include <iostream>
#include <string>

#include "instruccion.h"

class InstruccionSUB : public Instruccion {
 public:
  InstruccionSUB() {}; /// Constructor por defecto
  InstruccionSUB(std::string& instruccion) { parsear(instruccion); } /// Constructor por parámetro (parsea la instrucción)
  virtual ~InstruccionSUB() {}; /// Destructor por defecto
  void ejecutar(Contexto& contexto) override; 
  void parsear(std::string& instruccion) override; 
  std::ostream& write(std::ostream& os, bool debug) const override; 

 private:
  int operando_;
};

#endif