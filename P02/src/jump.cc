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
 * @brief implementacion de la clase Jgtz
*/

#include "jump.h"

/**
 * @brief ejecuta la instrucción jump
 * @param contexto contiene la memoria de datos, el contador de programa, 
 *        la unidad de salida y la unidad de entrada
 */
void Jump::ejecutar(Contexto& contexto) {
  if (contexto.etiquetas.find(etiqueta_) == contexto.etiquetas.end()) {
    std::cerr << "Error: Etiqueta " << etiqueta_ << " no encontrada" << std::endl;
    throw('e');
  }
  *contexto.contador_programa = contexto.etiquetas.find(etiqueta_)->second;
}

/**
 * @brief parsea la instrucción jump
 * @param instruccion contiene la instrucción a parsear
 */
void Jump::parsear(std::string& instruccion) {
  std::istringstream is(instruccion);
  is >> codigo_ >> etiqueta_;
}