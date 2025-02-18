/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * @author Esther M. Quintero
 * @date 14 Feb 2024
 * @brief Encabezado de la clase "Parser"
 *        (Principio ESTRATEGIA)
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
#include "instruccion-halt.h"

#include "memoria-programa.h"

enum Opcodes {
  ADD,
  SUB,
  MULT,
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
  Parser() {}; /// Constructor por defecto
  Parser(std::ifstream& file_name);
  virtual ~Parser() {}; /// Destructor por defecto

  MemoriaPrograma programa_parseado() { return MemoriaPrograma(programa_parseado_, etiquetas_);}

 private:
  std::vector<Instruccion*> programa_parseado_;
  std::map<std::string, int> etiquetas_;
  std::map<std::string, Opcodes> opcodes_ = {
    {"ADD", ADD},
    {"SUB", SUB},
    {"MULT", MULT},
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