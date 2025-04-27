/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Diseño y Análisis de Algoritmos
 * Curso: 3º
 * Práctica 6
 * @autor: Enrique Gómez Díaz
 * @mail: alu0101550329@ull.edu.es
 * @date: 06/05/2025
 * @brief: Implementacion de la clase Algoritmo
*/

#include "algoritmo.h"

/**
 * @brief Calcula el centro de gravedad de un conjunto de puntos.
 * @return El centro de gravedad como un objeto Punto.
 */
Punto Algoritmo::centroGravedad(const std::vector<Punto>& puntos) {
  if (puntos.empty()) {
    LANZAR_ERROR("Error en el cálculo del centro de gravedad", "El vector de puntos está vacío");
  }
  int dimensiones = puntos[0].getDimensiones();
  std::vector<double> coordenadas(dimensiones, 0.0);
  for (const auto& punto : puntos) {
    if (punto.getDimensiones() != dimensiones) {
      LANZAR_ERROR("Error en el cálculo del centro de gravedad", "Los puntos tienen diferentes dimensiones " + std::to_string(punto.getDimensiones()) + " y " + std::to_string(dimensiones));
    }
    for (int i = 0; i < dimensiones; ++i) {
      coordenadas[i] += punto.getCoordenada(i);
    }
  }
  for (int i = 0; i < dimensiones; ++i) {
    coordenadas[i] /= puntos.size();
  }

  return Punto(coordenadas);
}