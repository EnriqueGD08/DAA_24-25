/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * @author Esther M. Quintero
 * @date 14 Feb 2024
 * @brief Encabezado de la clase "InstruccionJUMP"
 *        (Principio ESTRATEGIA)
 */

#ifndef INSTRUCCION_JUMP_H_
#define INSTRUCCION_JUMP_H_

#include <iostream>
#include <string>

#include "instruccion.h"

class InstruccionJUMP : public Instruccion {
 public:
  InstruccionJUMP() {}; /// Constructor por defecto
  InstruccionJUMP(std::string& instruccion) { parsear(instruccion); } /// Constructor por parámetro (parsea la instrucción)
  virtual ~InstruccionJUMP() {}; /// Destructor por defecto
  void ejecutar(Contexto& contexto) override; 
  void parsear(std::string& instruccion) override; 
  std::ostream& write(std::ostream& os, bool debug) const override; 

 private:
  std::string etiqueta_;
};

#endif