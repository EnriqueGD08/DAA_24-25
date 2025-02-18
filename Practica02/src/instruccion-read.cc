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
 * @brief: implementacion clase InstruccionREAD
*/


#include "instruccion-read.h"

#include <iostream>
#include <string>
#include <sstream>

/**
 * @brief Método que ejecuta la instrucción ADD
 * @param contexto: contexto de la máquina RAM
 */
void InstruccionREAD::ejecutar(Contexto& contexto) {
  switch (direccionamiento_) {
    case Direccionamiento::DIRECTO:
      contexto.memoria_datos->guardar_valor(contexto.cinta_entrada->leer(), operando_);
      break;
    case Direccionamiento::INDIRECTO:
      contexto.memoria_datos->guardar_valor(contexto.cinta_entrada->leer(), contexto.memoria_datos->get_valor(operando_));
      break;
    case Direccionamiento::INMEDIATO:
      std::cerr << "Error: no se puede leer en una dirección inmediata" << std::endl;
      exit(1);
    break;
  }
  (*(contexto.contador_programa))++;
}

/**
 * @brief Método que parsea la instrucción ADD
 * @param instruccion: string que contiene la instrucción
 */
void InstruccionREAD::parsear(std::string& instruccion) {
  std::istringstream stream(instruccion);
  std::string aux;
  stream >> opcode_ >> aux;
  if (aux[0] == '=') {
    std::cerr << "Error: no se puede leer en una dirección inmediata" << std::endl;
    exit(1);
  } else if (aux[0] == '*') {
    direccionamiento_ = Direccionamiento::INDIRECTO;
    operando_ = stoi(aux.substr(1));
  } else {
    operando_ = stoi(aux);
    direccionamiento_ = Direccionamiento::DIRECTO;
  }
}