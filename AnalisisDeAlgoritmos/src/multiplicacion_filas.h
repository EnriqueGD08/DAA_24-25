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
 * @brief Estrategia de multiplicación de matrices por filas
*/

#pragma once

#include <vector>
#include "matriz_multiplicacion_estrategia.h"

class MultiplicacionFilas : public MatrizMultiplicacionEstrategia {
public:

  /**
   * @brief Multiplica dos matrices por filas
   * @param A Matriz A
   * @param B Matriz B
   * @return Matriz resultante de la multiplicación
   */
  std::vector<std::vector<int>> multiplicar(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) override {
    int tamanio_a = A.size();
    int tamanio_columna_b = B[0].size();
    int tamanio_b = B.size();
    std::vector<std::vector<int>> C(tamanio_a, std::vector<int>(tamanio_columna_b, 0));
    
    for (int i = 0; i < tamanio_a; ++i) {
      for (int j = 0; j < tamanio_columna_b; ++j) {
        for (int k = 0; k < tamanio_b; ++k) {
          C[i][j] += A[i][k] * B[k][j];
        }
      }
    }
    return C;
  }
};