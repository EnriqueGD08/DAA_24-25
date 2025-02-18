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
 * @brief implementacion de la clase Unidad
*/

#include "unidad.h"

/**
 * @brief imprime los datos de la cinta
 * @param os flujo de salida
 */
std::ostream& Unidad::imprimir(std::ostream& os) {
  for (int i = 0; i < datos_.size(); i++) {
    os << datos_[i] << " ";
  }
  return os;
}