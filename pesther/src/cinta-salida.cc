/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * @author Esther M. Quintero
 * @date 13 Feb 2024
 * @brief Implementación de la clase "CintaSalida".
 */

#include <iostream>
#include <vector>
#include <fstream>
#include "cinta-salida.h"

/**
 * @brief Escribe el valor en la cinta
 * @param[in] valor: valor a escribir
 */
void CintaSalida::escribir(int valor) {
  #ifdef DEPURAR
  std::cout << "Escribiendo instrucción en la cinta de salida..." << std::endl;
  #endif
  cinta_.push_back(valor);
}

/**
 * @brief Escribe la cinta en un fichero
 * @param[in] fichero: nombre del fichero
 */
void CintaSalida::escribir_en_fichero(std::string& fichero) {
  #ifdef DEPURAR
  std::cout << "Escribiendo cinta de salida en fichero..." << std::endl;
  #endif
  std::ofstream output(fichero);
  /// Usamos print
  print(output);
}