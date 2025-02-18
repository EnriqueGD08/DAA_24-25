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
 * @brief: declaración clase MemoriaPrograma
*/


#pragma once

#include "instruccion.h"
#include <iostream>
#include <vector>
#include <memory> 
#include <map>

class MemoriaPrograma {
 public:
  MemoriaPrograma() {};
  MemoriaPrograma(std::vector<Instruccion*> programa, std::map<std::string, int> etiquetas); 
  ~MemoriaPrograma() {};

  inline std::map<std::string, int> get_etiquetas() { return etiquetas_; };
  std::vector<Instruccion*> get_programa() { return programa_; };
  Instruccion* get_instruccion(int posicion) { return programa_[posicion]; };
  std::ostream& write(std::ostream& os) const;

 private:
  std::vector<Instruccion*> programa_;
  std::map<std::string, int> etiquetas_;
};