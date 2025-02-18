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
 * @brief implementacion de la clase UnidadEntrada
*/

#include "unidad_entrada.h"

/**
 * @brief Constructor de la clase UnidadEntrada
 * @param fichero fichero de entrada
*/
UnidadEntrada::UnidadEntrada(std::ifstream& fichero) {
  int dato;
  while (fichero >> dato) {
    datos_.push_back(dato);
  }
}

/**
 * @brief Lee un dato de la entrada
 * @return dato leido
*/
int UnidadEntrada::leer() {
  cabezal_++;
  return datos_[cabezal_];
}