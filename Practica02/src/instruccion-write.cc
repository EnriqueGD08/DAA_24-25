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
 * @brief: implementacion clase InstruccionWRITE
*/


#include "instruccion-write.h"

#include <iostream>
#include <string>
#include <sstream>

/**
 * @brief Método que ejecuta la instrucción ADD
 * @param contexto: contexto de la máquina RAM
 */
void InstruccionWRITE::ejecutar(Contexto& contexto) {
  switch (direccionamiento_) {
    case Direccionamiento::DIRECTO:
      if (operando_ == 0) {
        std::cerr << "Error: no se puede escribir en la dirección 0" << std::endl;
        exit(1);
      }
      contexto.cinta_salida->escribir(contexto.memoria_datos->get_valor(operando_));
      break;
    case Direccionamiento::INMEDIATO:
      contexto.cinta_salida->escribir(operando_);
      break;
    case Direccionamiento::INDIRECTO:
      contexto.cinta_salida->escribir(contexto.memoria_datos->get_valor(contexto.memoria_datos->get_valor(operando_)));
      break;
  }
  (*(contexto.contador_programa))++;
}

/**
 * @brief Método que parsea la instrucción ADD
 * @param instruccion: string que contiene la instrucción
 */
void InstruccionWRITE::parsear(std::string& instruccion) {
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