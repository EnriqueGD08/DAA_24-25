/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * @author Esther M. Quintero
 * @date 13 Feb 2024
 * @brief Implementación de la clase "CintaEntrada".
 */

#include <iostream>
#include <vector>
#include <fstream>
#include "cinta-entrada.h"

/**
 * @brief Constructor de la clase CintaEntrada
 * @param[in] input: flujo de entrada
 */
CintaEntrada::CintaEntrada(std::ifstream& input) {
  int valor;
  /// @note: Editar esto para aceptar vector (getline)
  while (input >> valor) {
    cinta_.push_back(valor);
  }
}

/**
 * @brief Lee la instrucción de la cinta
 * @return instrucción leída
 */
int CintaEntrada::leer() {
  #ifdef DEPURAR
  std::cout << "Leyendo instrucción de la cinta..." << std::endl;
  #endif
  cabezal_++;
  return cinta_[cabezal_ - 1];
}