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
 * @brief implementacion de la clase Halt
*/

#include "halt.h"

/**
 * @brief ejecuta la instrucción halt
 * @param contexto contiene la memoria de datos, el contador de programa, 
 *        la unidad de salida y la unidad de entrada
 */
void Halt::ejecutar(Contexto& contexto) {
  exit(0);
}

/**
 * @brief parsea la instrucción halt
 * @param instruccion contiene la instrucción a parsear
 */
void Halt::parsear(std::string& instruccion) {
  std::istringstream is(instruccion);
  is >> codigo_;
}