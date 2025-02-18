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
 * @brief implementacion de la clase MemoriaDatos
*/

#include "memoria_datos.h"

/**
 * @brief guarda un valor en una dirección de memoria
 * @param valor valor a guardar
 * @param direccion dirección de memoria
*/
void MemoriaDatos::guardar_valor(int valor, int direccion) {
  if (direccion >= 0 && direccion < memoria_.size()) {
    memoria_[direccion] = valor;
  } else if (direccion >= memoria_.size()) {
    memoria_.resize(direccion + 1);
    memoria_[direccion] = valor;
  } else {
    std::cerr << "Error: Dirección de memoria no válida" << std::endl;
    throw('e');
  }
}