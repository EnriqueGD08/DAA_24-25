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

#include "parser.h"

/**
 * @brief Constructor de la clase Parser
 * @param archivo archivo de entrada
 */
Parser::Parser(std::ifstream& archivo) {
  std::string instruccion;
  std::string auxiliar;
  std::pair<std::string, int> etiqueta;

  while (std::getline(archivo, instruccion)) {
    if (instruccion[0] == '#' || instruccion.empty()) {
      continue;
    }

    instruccion.erase(std::remove(instruccion.begin(), instruccion.end(), '\t '), instruccion.end());
    for (int iterator = 0; iterator < instruccion.size(); iterator++) {
      instruccion[iterator] = std::toupper(instruccion[iterator]);
    }

    int posicion = instruccion.find(':');
    if (posicion != std::string::npos) {
      std::string etiqueta_aux = instruccion.substr(0, posicion);
      etiquetas_.insert(std::pair<std::string, int>(etiqueta_aux, instrucciones_.size()));
      instruccion = instruccion.substr(posicion + 1, instruccion.size() - 1);
    }
    std::istringstream is(instruccion);
    is >> auxiliar;
    switch (opcodes_.find(auxiliar)->second) {
      case Opcodes::ADD:
        instrucciones_.push_back(new Add(instruccion));
        break;
      case Opcodes::SUB:
        instrucciones_.push_back(new Sub(instruccion));
        break;
      case Opcodes::MUL:
        instrucciones_.push_back(new Mul(instruccion));
        break;
      case Opcodes::DIV:
        instrucciones_.push_back(new Div(instruccion));
        break;
      case Opcodes::LOAD:
        instrucciones_.push_back(new Load(instruccion));
        break;
      case Opcodes::STORE:
        instrucciones_.push_back(new Store(instruccion));
        break;
      case Opcodes::READ:
        instrucciones_.push_back(new Read(instruccion));
        break;
      case Opcodes::WRITE:
        instrucciones_.push_back(new Write(instruccion));
        break;
      case Opcodes::JUMP:
        instrucciones_.push_back(new Jump(instruccion));
        break;
      case Opcodes::JGTZ:
        instrucciones_.push_back(new Jgtz(instruccion));
        break;
      case Opcodes::JZERO:
        instrucciones_.push_back(new Jzero(instruccion));
        break;
      case Opcodes::HALT:
        instrucciones_.push_back(new Halt(instruccion));
        break;
      default:
        std::cerr << "Instrucción no válida" << std::endl;
        throw('e');
        break;
    }
    auxiliar.clear();
  }
}