/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * @author Esther M. Quintero
 * @date 13 Feb 2024
 * @brief Encabezado de la clase "CintaEntrada".
 */

#ifndef CINTA_ENTRADA_H
#define CINTA_ENTRADA_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "cinta.h"

class CintaEntrada : public Cinta {
 public:
  CintaEntrada() { Cinta(); };
  CintaEntrada(std::ifstream& input);
  ~CintaEntrada() {}; /// Destructor por defecto

  int leer();
};

#endif