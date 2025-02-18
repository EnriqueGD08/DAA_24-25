/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * @author Esther M. Quintero
 * @date 14 Feb 2024
 * @brief Encabezado de la clase "InstruccionDIV"
 *        (Principio ESTRATEGIA)
 */

#ifndef INSTRUCCION_DIV_H_
#define INSTRUCCION_DIV_H_

#include <iostream>

#include "instruccion.h"

class InstruccionDIV : public Instruccion {
 public:
  InstruccionDIV() {}; /// Constructor por defecto
  InstruccionDIV(std::string& instruccion) { parsear(instruccion); } /// Constructor por parámetro (parsea la instrucción)
  virtual ~InstruccionDIV() {}; /// Destructor por defecto
  void ejecutar(Contexto& contexto) override; 
  void parsear(std::string& instruccion) override; 
  std::ostream& write(std::ostream& os, bool debug) const override; 

 private:
  int operando_;
};

#endif