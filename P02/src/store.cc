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
 * @brief implementacion de la clase Store
*/

#include "store.h"

/**
 * @brief ejecuta la instrucción store
 * @param contexto contiene la memoria de datos, el contador de programa, 
 *        la unidad de salida y la unidad de entrada
 */
void Store::ejecutar(Contexto& contexto) {
  switch (direccionamiento_) {
    case Direccionamiento::DIRECTO:
      contexto.memoria_datos->guardar_valor(contexto.memoria_datos->getValor(operando_), 0);
      break;
    case Direccionamiento::INDIRECTO:
      contexto.memoria_datos->guardar_valor(contexto.memoria_datos->getValor(contexto.memoria_datos->getValor(operando_)), 0);
      break;
    case Direccionamiento::INMEDIATO:
      std::cerr << "Error: Direccionamiento inmediato no permitido para STORE" << std::endl;
      throw('e');
      break;
  }
  *contexto.contador_programa++;
}

/**
 * @brief parsea la instrucción store
 * @param instruccion contiene la instrucción a parsear
 */
void Store::parsear(std::string& instruccion) {
  std::istringstream is(instruccion);
  std::string operando;
  is >> codigo_ >> operando;
  if (operando[0] == '=') {
    std::cerr << "Error: Direccionamiento inmediato no permitido para STORE" << std::endl;
    throw('e');
  } else if (operando[0] == '*') {
    direccionamiento_ = Direccionamiento::INDIRECTO;
    operando_ = std::stoi(operando.substr(1));
  } else {
    direccionamiento_ = Direccionamiento::DIRECTO;
    operando_ = std::stoi(operando);
  }
}