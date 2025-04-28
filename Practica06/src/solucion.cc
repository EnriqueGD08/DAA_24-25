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
  valor_objetivo_ = 0.0;
  for (size_t i = 0; i < puntos_.size(); ++i) {
    for (size_t j = i + 1; j < puntos_.size(); ++j) {
      valor_objetivo_ += puntos_[i].distancia(puntos_[j]);
    }
  }

  return valor_objetivo_;
}

/**
 * @brief devuelve una representación en cadena de la solución.
 * @return representación en cadena de la solución.
 */
std::string Solucion::toString() const {
  std::string resultado = "";
  for (const auto& punto : puntos_) {
    resultado += punto.toString() + ' ';
  }
  return resultado;
}