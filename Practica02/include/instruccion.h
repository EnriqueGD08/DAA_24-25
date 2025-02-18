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
 * @brief: declaración clase Instruccion
*/


#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "memoria-datos.h"
#include "cinta-entrada.h"
#include "cinta-salida.h"

struct Contexto {
  CintaEntrada* cinta_entrada;
  CintaSalida* cinta_salida;  
  std::map<std::string, int> etiquetas;
  int* contador_programa;
  MemoriaDatos* memoria_datos;
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
  std::string opcode_;
  Direccionamiento direccionamiento_ = INMEDIATO;
};