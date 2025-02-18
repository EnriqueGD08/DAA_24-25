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
 * @brief: implementacion clase Cinta
*/

#include <iostream>
#include <vector>
#include "cinta.h"

/**
 * @brief Imprime la cinta
 * @param os: flujo de salida
 * @return os: flujo de salida
 */
std::ostream& Cinta::print(std::ostream& os) {
  for (int elem : cinta_) os << elem << " ";
  return os;
}