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
 * @brief: implementación de la clase Solucion
*/

#include "solucion.h"

/**
 * @brief calcula el valor objetivo de la solución.
 * @return valor objetivo de la solución.
 */
double Solucion::calcularValorObjetivo() {
  double valor_objetivo = 0.0;
  for (size_t i = 0; i < puntos_.size(); ++i) {
    for (size_t j = i + 1; j < puntos_.size(); ++j) {
      valor_objetivo += puntos_[i].distancia(puntos_[j]);
    }
  }
  return valor_objetivo;
}

/**
 * @brief Sobrecarga del operador de salida para imprimir la solución.
 * @param os Flujo de salida.
 * @param solucion Objeto Solucion a imprimir.
 * @return Flujo de salida.
 */
std::ostream& operator<<(std::ostream& os, const Solucion& solucion) {
  for (const auto& punto : solucion.puntos_) {
    os << punto << " ";
  }
  os << "\nValor objetivo: " << solucion.getValorObjetivo() << std::endl;
  return os;
}