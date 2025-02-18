/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * @author Esther M. Quintero
 * @date 13 Feb 2024
 * @brief Encabezado de la clase "CintaSalida".
 */

#ifndef CINTA_SALIDA_H
#define CINTA_SALIDA_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "cinta.h"

class CintaSalida : public Cinta {
 public:
  CintaSalida() { Cinta(); };
  ~CintaSalida() {}; /// Destructor por defecto

  void escribir(int valor);
  void escribir_en_fichero(std::string& fichero);
};

#endif