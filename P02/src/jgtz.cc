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

#include "jgtz.h"

/**
 * @brief ejecuta la instrucción jgtz
 * @param contexto contiene la memoria de datos, el contador de programa, 
 *        la unidad de salida y la unidad de entrada
 */
void Jgtz::ejecutar(Contexto& contexto) {
  if (contexto.memoria_datos->getValor(0) > 0) {
    if (contexto.etiquetas.find(etiqueta_) == contexto.etiquetas.end()) {
      std::cerr << "Error: Etiqueta " << etiqueta_ << " no encontrada" << std::endl;
      throw('e');
    }
    *contexto.contador_programa = contexto.etiquetas.find(etiqueta_)->second;
  } else {
    *contexto.contador_programa++;
  }
}

/**
 * @brief parsea la instrucción jgtz
 * @param instruccion contiene la instrucción a parsear
 */
void Jgtz::parsear(std::string& instruccion) {
  std::istringstream is(instruccion);
  is >> codigo_ >> etiqueta_;
}