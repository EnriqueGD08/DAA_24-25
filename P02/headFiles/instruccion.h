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
 * @brief declaración de la clase instrucción halt
*/

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

#include "memoria_datos.h"
#include "unidad_entrada.h"
#include "unidad_salida.h"

struct Contexto {
  MemoriaDatos* memoria_datos;
  int* contador_programa;
  UnidadSalida* unidad_salida;
  UnidadEntrada* unidad_entrada;
  std::map<std::string, int> etiquetas;
};

enum Direccionamiento {
  INMEDIATO,
  DIRECTO,
  INDIRECTO
};

class Instruccion {
 public:
  Instruccion() {};
  virtual ~Instruccion() {};
  virtual void ejecutar(Contexto& contexto) = 0;
  virtual void parsear(std::string& instruccion) = 0;

 protected:
  std::string codigo_;
  Direccionamiento direccionamiento_ = INMEDIATO;
};