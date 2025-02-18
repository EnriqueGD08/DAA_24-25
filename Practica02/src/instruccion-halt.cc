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
 * @brief: implementacion clase InstruccionHALT
*/


#include "instruccion-halt.h"

#include <iostream>
#include <string>
#include <sstream>

/**
 * @brief Ejecuta la instrucción HALT
 * @param contexto Contexto de ejecución
 */
void InstruccionHALT::ejecutar(Contexto& contexto) {
  throw('x');
}

/**
 * @brief Parsea la instrucción HALT
 * @param instruccion Instrucción a parsear
 */
void InstruccionHALT::parsear(std::string& instruccion) {
  std::istringstream is(instruccion);
  std::string instruccion_;
  is >> opcode_;
}