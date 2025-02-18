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
 * @brief: declaración clase Cinta
*/

#pragma once

#include <iostream>
#include <vector>

class Cinta {
  public:
    Cinta() { cabezal_ = 0; };
    ~Cinta() {};
    std::ostream& print(std::ostream& os);

  protected:
    std::vector<int> cinta_;
    int cabezal_ = 0;
};