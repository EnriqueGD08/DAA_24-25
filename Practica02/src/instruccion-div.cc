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
 * @brief: implementacion clase IstruccionDIV
*/


#include "instruccion-div.h"

#include <iostream>
#include <string>
#include <sstream>

/**
 * @brief Método que ejecuta la instrucción DIV
 * @param contexto: contexto de la máquina RAM
 */
void InstruccionDIV::ejecutar(Contexto& contexto) {
  switch (direccionamiento_) {
    case Direccionamiento::DIRECTO:
      if (contexto.memoria_datos->get_valor(operando_) == 0) {
        std::cerr << "Error: División por cero" << std::endl;
        exit(1);
      }
      contexto.memoria_datos->set_valor(contexto.memoria_datos->get_valor(0) / contexto.memoria_datos->get_valor(operando_));
      break;
    case Direccionamiento::INMEDIATO:
      if (operando_ == 0) {
        std::cerr << "Error: División por cero" << std::endl;
        exit(1);
      }
      contexto.memoria_datos->set_valor(contexto.memoria_datos->get_valor(0) / operando_);
      break;
    case Direccionamiento::INDIRECTO:
      if (contexto.memoria_datos->get_valor(contexto.memoria_datos->get_valor(operando_)) == 0) {
        std::cerr << "Error: División por cero" << std::endl;
        exit(1);
      }
      contexto.memoria_datos->set_valor(contexto.memoria_datos->get_valor(0) / contexto.memoria_datos->get_valor(contexto.memoria_datos->get_valor(operando_)));
      break;
  }
  (*(contexto.contador_programa))++;
}

/**
 * @brief Método que parsea la instrucción DIV
 * @param instruccion: string que contiene la instrucción
 */
void InstruccionDIV::parsear(std::string& instruccion) {
  std::istringstream stream(instruccion);
  std::string aux;
  stream >> opcode_ >> aux;
  if (aux[0] == '=') {
    direccionamiento_ = Direccionamiento::INMEDIATO;
    operando_ = stoi(aux.substr(1));
  } else if (aux[0] == '*') {
    direccionamiento_ = Direccionamiento::INDIRECTO;
    operando_ = stoi(aux.substr(1));
  } else {
    operando_ = stoi(aux);
    direccionamiento_ = Direccionamiento::DIRECTO;
  }
}