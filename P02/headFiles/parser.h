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
 * @brief declaración de la clase Parser
*/

#pragma once

#include "instruccion.h"
#include "memoria_programa.h"
#include "add.h"
#include "sub.h"
#include "mul.h"
#include "div.h"
#include "read.h"
#include "write.h"
#include "jump.h"
#include "jgtz.h"
#include "jzero.h"
#include "halt.h"
#include "load.h"
#include "store.h"
#include "halt.h"

enum Opcodes {
  ADD,
  SUB,
  MUL,
  DIV,
  LOAD,
  STORE,
  READ,
  WRITE,
  JUMP,
  JGTZ,
  JZERO,
  HALT
};

class Parser {
 public:
  Parser() {}
  Parser(std::ifstream& archivo);
  ~Parser() {}

  MemoriaPrograma parsear() {return MemoriaPrograma(instrucciones_, etiquetas_);};

 private:
  std::vector<Instruccion*> instrucciones_;
  std::map<std::string, int> etiquetas_;
  std::map<std::string, Opcodes> opcodes_ = {
    {"ADD", ADD},
    {"SUB", SUB},
    {"MUL", MUL},
    {"DIV", DIV},
    {"LOAD", LOAD},
    {"STORE", STORE},
    {"READ", READ},
    {"WRITE", WRITE},
    {"JUMP", JUMP},
    {"JGTZ", JGTZ},
    {"JZERO", JZERO},
    {"HALT", HALT}
  };
};
