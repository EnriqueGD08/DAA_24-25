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
 * @brief Interfaz de la estrategia de multiplicación de matrices
*/

#pragma once

#include <vector>

class MatrizMultiplicacionEstrategia {
public:
  virtual std::vector<std::vector<int>> multiplicar(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) = 0;
};