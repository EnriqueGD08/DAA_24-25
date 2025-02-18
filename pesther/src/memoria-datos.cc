/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * @author Esther M. Quintero
 * @date 13 Feb 2024
 * @brief Implementación de la clase "MemoriaDatos"
 *        Posee una serie de registros indexados R0, R1, R2, …, Rn para almacenar datos. 
 *        El registro R0 es un registro especial llamado acumulador, el cual ayuda en la 
 *        realización de operaciones aritméticas, lógicas y de control.
 */

#include <iostream>
#include "memoria-datos.h"

/**
 * @brief Guarda un valor en un registro de la memoria de datos.
 * @param[in] valor Valor que se guardará en el registro.
 * @param[in] registro Número de registro en el que se guardará el valor.
 */
void MemoriaDatos::guardar_valor(int valor, int registro) {
  #ifdef DEPURAR
  std::cout << "Guardando valor en registro " << registro << "..." << std::endl;
  #endif
  if (registro >= (int)registros_.size()) {
    /// Ampliamos la memoria de datos si el registro no existe.
    registros_.resize(registro + 1);
  }
  registros_[registro] = valor;
}

/**
 * @brief Sobrecarga del operador de inserción para la clase "MemoriaDatos".
 * @param[out] os Flujo de salida.
 * @param[in] memoria_datos Memoria de datos que se imprimirá.
 * @return Flujo de salida.
 */
std::ostream& operator<<(std::ostream& os, MemoriaDatos& memoria_datos) {
  for (int i = 0; i < (int)memoria_datos.registros_.size(); i++) {
    os << "R" << i << " -> " << memoria_datos.registros_[i] << std::endl;
  }
  return os;
}
