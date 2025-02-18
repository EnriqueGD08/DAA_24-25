/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * @author Esther M. Quintero
 * @date 14 Feb 2024
 * @brief Encabezado de la clase "InstruccionHALT"
 *        (Principio ESTRATEGIA)
 */

#ifndef INSTRUCCION_HALT_H_
#define INSTRUCCION_HALT_H_

#include <iostream>

#include "instruccion.h"

class InstruccionHALT : public Instruccion {
 public:
  InstruccionHALT() {}; /// Constructor por defecto
  InstruccionHALT(std::string& instruccion) { parsear(instruccion); } /// Constructor por parámetro (parsea la instrucción)
  virtual ~InstruccionHALT() {}; /// Destructor por defecto
  void ejecutar(Contexto& contexto) override; 
  void parsear(std::string& instruccion) override; 
  std::ostream& write(std::ostream& os, bool debug) const override; 
};

#endif