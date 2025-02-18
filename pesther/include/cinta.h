/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * @author Esther M. Quintero
 * @date 13 Feb 2024
 * @brief Encabezado de la clase "Cinta" de la cual heredarán las clases:
 *          - CintaEntrada
 *          - CintaSalida
 */

#ifndef CINTA_H
#define CINTA_H

#include <iostream>
#include <vector>

class Cinta {
  public:
    Cinta() { cabezal_ = 0; };
    ~Cinta() {}; /// Destructor por defecto
    std::ostream& print(std::ostream& os);

  protected:
    std::vector<int> cinta_;
    int cabezal_ = 0;
};

#endif