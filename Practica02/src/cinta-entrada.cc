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
 * @brief: implementacion clase CintaEntrada
*/


#include <iostream>
#include <vector>
#include <fstream>
#include "cinta-entrada.h"

/**
 * @brief Constructor de la clase CintaEntrada
 * @param input: flujo de entrada
 */
CintaEntrada::CintaEntrada(std::ifstream& input) {
  int valor;
  while (input >> valor) {
    cinta_.push_back(valor);
  }
}

/**
 * @brief Lee la instrucción de la cinta
 * @return instrucción leída
 */
int CintaEntrada::leer() {
  cabezal_++;
  return cinta_[cabezal_ - 1];
}