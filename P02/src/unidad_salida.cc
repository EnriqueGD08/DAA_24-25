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
 * @brief implementacion de la clase UnidadSalida
*/

#include "unidad_salida.h"

/**
 * @brief Constructor de la clase UnidadSalida
 * @param datos vector de enteros
 */
void UnidadSalida::escribir(int valor) {
  datos_.push_back(valor);
}

/**
 * @brief Escribe en un fichero los datos de la salida
 * @param fichero nombre del fichero
 */
void UnidadSalida::escribir_fichero(std::string& fichero) {
  std::ofstream file(fichero);
  imprimir(file);
}