/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * @author Esther M. Quintero
 * @date 14 Feb 2024
 * @brief Implementación de la clase "Parser"
 *        (Principio ESTRATEGIA)
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm> /// std::remove
#include <sstream> /// std::istringstream
#include "parser.h"
#include "utilities.h"

/**
 * @brief Constructor de la clase Parser
 * @param[in] input: flujo de entrada
 */
Parser::Parser(std::ifstream& file_name) {
  #ifdef DEPURAR
  std::cout << "Creando parser..." << std::endl;
  #endif
  std::string linea, auxiliar;
  std::pair<std::string, int> etiqueta;
  while (std::getline(file_name, linea)) {
    if (linea[0] == '#' or linea == "") { /// Si la línea es un comentario o está vacía, se ignora
      continue;
    }
    /// Borramos tabulaciones
    linea.erase(std::remove(linea.begin(), linea.end(), '\t'), linea.end());
    /// Ponemos en mayúsculas
    std::transform(linea.begin(), linea.end(), linea.begin(), ::toupper);
    /// Buscamos etiqueta (si es que hay)
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
      case Opcodes::MULT:
        programa_parseado_.push_back(new InstruccionMULT(linea));
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
      case Opcodes::HALT:
        programa_parseado_.push_back(new InstruccionHALT(linea));
        break;
      default:
        std::cerr << RED "Error: Opcode no reconocido" NC << std::endl;
        std::cerr << "--> Parser::Parser(std::ifstream& file_name)" << std::endl;
        std::cerr << "--> Línea 85 de parser.cc" << std::endl;
        break;
    }
    auxiliar.clear();
  }
}