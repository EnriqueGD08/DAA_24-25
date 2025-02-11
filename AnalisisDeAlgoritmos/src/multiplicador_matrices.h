/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Diseño y Análisis de Algoritmos
 * Curso: 3º
 * Práctica 1
 * @autor: Enrique Gómez Díaz
 * @mail: alu0101550329@ull.edu.es
 * @date: 11/02/2025
 * @brief Clase que multiplica dos matrices según una estrategia
*/

#pragma once

#include <vector>
#include "matriz_multiplicacion_estrategia.h"

class MultipicadorMatrices {
 private:
  MatrizMultiplicacionEstrategia* estrategia;
 public:
  MultipicadorMatrices(MatrizMultiplicacionEstrategia* estrategia) : estrategia(estrategia) {}
  
  /**
   * @brief Multiplica dos matrices
   * @param A Matriz A
   * @param B Matriz B
   * @return Matriz resultante de la multiplicación
   */
  std::vector<std::vector<int>> multiplicar(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    return estrategia->multiplicar(A, B);
  }
};