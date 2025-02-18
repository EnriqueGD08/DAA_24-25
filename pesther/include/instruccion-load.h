/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * @author Esther M. Quintero
 * @date 14 Feb 2024
 * @brief Encabezado de la clase "InstruccionLOAD"
 *        (Principio ESTRATEGIA)
 */

#ifndef INSTRUCCION_LOAD_H_
#define INSTRUCCION_LOAD_H_

#include <iostream>
#include <string>

#include "instruccion.h"

class InstruccionLOAD : public Instruccion {
 public:
  InstruccionLOAD() {}; /// Constructor por defecto
  InstruccionLOAD(std::string& instruccion) { parsear(instruccion); } /// Constructor por parámetro (parsea la instrucción)
  virtual ~InstruccionLOAD() {}; /// Destructor por defecto
  void ejecutar(Contexto& contexto) override; 
  void parsear(std::string& instruccion) override; 
  std::ostream& write(std::ostream& os, bool debug) const override; 

 private:
  int operando_;
};

#endif