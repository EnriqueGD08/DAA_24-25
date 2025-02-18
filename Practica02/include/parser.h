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
 * @brief: declaración clase Parser
*/


#include <iostream>
#include <string>
#include <vector>

#include "instruccion.h"
#include "instruccion-add.h"
#include "instruccion-sub.h"
#include "instruccion-mult.h"
#include "instruccion-div.h"
#include "instruccion-load.h"
#include "instruccion-store.h"
#include "instruccion-read.h"
#include "instruccion-write.h"
#include "instruccion-jump.h"
#include "instruccion-jgtz.h"
#include "instruccion-jzero.h"
#include "instruccion-mod.h"
#include "instruccion-halt.h"

#include "memoria-programa.h"

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
  MOD,
  HALT
};

class Parser {
 public:
  Parser() {};
  Parser(std::ifstream& file_name);
  virtual ~Parser() {};

  MemoriaPrograma programa_parseado() { return MemoriaPrograma(programa_parseado_, etiquetas_);}

 private:
  std::vector<Instruccion*> programa_parseado_;
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
    {"MOD", MOD},
    {"HALT", HALT}
  };
};