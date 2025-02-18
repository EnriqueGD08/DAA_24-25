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
 * @brief declaración de la clase MemoriaPrograma
*/

#pragma once

#include <iostream>
#include <vector>
#include <map>
#include "instruccion.h"

class MemoriaPrograma {
 public:
  MemoriaPrograma() {}
  MemoriaPrograma(std::vector<Instruccion*> instrucciones, std::map<std::string, int> etiquetas);
  ~MemoriaPrograma() {}

  std::map<std::string, int> get_etiquetas() { return etiquetas_; }
  Instruccion* get_instruccion(int posicion) { return instrucciones_[posicion]; }
  std::vector<Instruccion*> get_instrucciones() { return instrucciones_; }

 private:
  std::vector<Instruccion*> instrucciones_;
  std::map<std::string, int> etiquetas_;
};