/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * @author Esther M. Quintero
 * @date 14 Feb 2024
 * @brief Implementación de la clase "InstruccionHALT"
 *        (Principio ESTRATEGIA)
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
  #ifdef DEPURAR
  std::cout << "Ejecutando instrucción HALT..." << std::endl;
  #endif
  throw('x'); /// Lanza una excepción para detener la ejecución (opción 0 del main)
}

/**
 * @brief Parsea la instrucción HALT
 * @param instruccion Instrucción a parsear
 */
void InstruccionHALT::parsear(std::string& instruccion) {
  #ifdef DEPURAR
  std::cout << "Parseando instrucción HALT..." << std::endl;
  #endif
  std::istringstream is(instruccion);
  std::string instruccion_;
  is >> opcode_;
}

/**
 * @brief Escribe la instrucción HALT
 * @param os Stream de salida
 * @param debug Modo debug activado
 */
std::ostream& InstruccionHALT::write(std::ostream& os, bool debug) const {
  if (debug) {
    os << "\nOpcode: " << opcode_;
  } else {
    os << opcode_ << " ";
  }
  return os;
}