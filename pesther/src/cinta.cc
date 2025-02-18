/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * @author Esther M. Quintero
 * @date 13 Feb 2024
 * @brief Implementación de la clase "Cinta" de la cual heredarán las clases:
 *          - CintaEntrada
 *          - CintaSalida
 */

#include <iostream>
#include <vector>
#include "cinta.h"

/**
 * @brief Imprime la cinta
 * @param[in] os: flujo de salida
 * @return os: flujo de salida
 */
std::ostream& Cinta::print(std::ostream& os) {
  for (int elem : cinta_) os << elem << " ";
  return os;
}