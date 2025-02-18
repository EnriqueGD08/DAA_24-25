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
 * @brief: implementacion clase CintaSalida
*/

#include <iostream>
#include <vector>
#include <fstream>
#include "cinta-salida.h"

/**
 * @brief Escribe el valor en la cinta
 * @param valor: valor a escribir
 */
void CintaSalida::escribir(int valor) {
  cinta_.push_back(valor);
}

/**
 * @brief Escribe la cinta en un fichero
 * @param fichero: nombre del fichero
 */
void CintaSalida::escribir_en_fichero(std::string& fichero) {
  std::ofstream output(fichero);
  print(output);
}