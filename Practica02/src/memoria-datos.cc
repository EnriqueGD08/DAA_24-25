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
 * @brief: implementacion clase MemoriaDatos
*/

#include <iostream>
#include "memoria-datos.h"

/**
 * @brief Guarda un valor en un registro de la memoria de datos.
 * @param valor Valor que se guardará en el registro.
 * @param registro Número de registro en el que se guardará el valor.
 */
void MemoriaDatos::guardar_valor(int valor, int registro) {
  if (registro >= (int)registros_.size()) {
    registros_.resize(registro + 1);
  }
  registros_[registro] = valor;
}

/**
 * @brief Sobrecarga del operador de inserción para la clase MemoriaDatos.
 * @param os Flujo de salida.
 * @param memoria_datos Memoria de datos que se imprimirá.
 * @return Flujo de salida.
 */
std::ostream& operator<<(std::ostream& os, MemoriaDatos& memoria_datos) {
  for (int i = 0; i < (int)memoria_datos.registros_.size(); i++) {
    os << "R" << i << " -> " << memoria_datos.registros_[i] << std::endl;
  }
  return os;
}
