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
 * @brief: implementacion clase Parser
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include "parser.h"
#include "utilities.h"

/**
 * @brief Constructor de la clase Parser
 * @param input: flujo de entrada
 */
Parser::Parser(std::ifstream& file_name) {
  std::string linea, auxiliar;
  std::pair<std::string, int> etiqueta;
  while (std::getline(file_name, linea)) {

    linea.erase(std::remove(linea.begin(), linea.end(), '\t'), linea.end());
    if (linea[0] == '#' or linea == "") {
      continue;
    }
    //linea.erase(std::remove(linea.begin(), linea.end(), '\t'), linea.end());
    std::transform(linea.begin(), linea.end(), linea.begin(), ::toupper);
    std::size_t found = linea.find(":");
    if (found != std::string::npos) {
      std::string etiqueta = linea.substr(0, found);
      etiquetas_.insert(std::make_pair(etiqueta, programa_parseado_.size()));
      linea = linea.substr(found + 1, linea.size() - 1);
    }

    std::istringstream is(linea);
    is >> auxiliar;
    switch (opcodes_.find(auxiliar)->second) {
      case Opcodes::ADD:
        programa_parseado_.push_back(new InstruccionADD(linea));
        break;
      case Opcodes::SUB:
        programa_parseado_.push_back(new InstruccionSUB(linea));
        break;
      case Opcodes::MUL:
        programa_parseado_.push_back(new InstruccionMUL(linea));
        break;
      case Opcodes::DIV:
        programa_parseado_.push_back(new InstruccionDIV(linea));
        break;
      case Opcodes::READ:
        programa_parseado_.push_back(new InstruccionREAD(linea));
        break;
      case Opcodes::WRITE:
        programa_parseado_.push_back(new InstruccionWRITE(linea));
        break;
      case Opcodes::LOAD:
        programa_parseado_.push_back(new InstruccionLOAD(linea));
        break;
      case Opcodes::STORE:
        programa_parseado_.push_back(new InstruccionSTORE(linea));
        break;
      case Opcodes::JUMP:
        programa_parseado_.push_back(new InstruccionJUMP(linea));
        break;
      case Opcodes::JGTZ:
        programa_parseado_.push_back(new InstruccionJGTZ(linea));
        break;
      case Opcodes::JZERO:
        programa_parseado_.push_back(new InstruccionJZERO(linea));
        break;
      case Opcodes::MOD:
        programa_parseado_.push_back(new InstruccionMOD(linea));
        break;
      case Opcodes::HALT:
        programa_parseado_.push_back(new InstruccionHALT(linea));
        break;
      default:
        std::cerr << "Error: Opcode no reconocido" << std::endl;
        std::cout << auxiliar << std::endl;
        break;
    }
    auxiliar.clear();
  }
}