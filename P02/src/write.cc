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
 * @brief implementacion de la clase Write
*/

#include "write.h"

/**
 * @brief ejecuta la instrucción write
 * @param contexto contiene la memoria de datos, el contador de programa, 
 *        la unidad de salida y la unidad de entrada
 */
void Write::ejecutar(Contexto& contexto) {
  switch (direccionamiento_) {
    case Direccionamiento::DIRECTO:
      if (operando_ == 0) {
        std::cerr << "Error: Direccionamiento directo no permitido para WRITE con 0" << std::endl;
        throw('e');
        break;
      } else {
        contexto.unidad_salida->escribir(contexto.memoria_datos->getValor(operando_));
      }
    case Direccionamiento::INDIRECTO:
      contexto.unidad_salida->escribir(contexto.memoria_datos->getValor(contexto.memoria_datos->getValor(operando_)));
      break;
    case Direccionamiento::INMEDIATO:
      contexto.unidad_salida->escribir(operando_);
      break;
  }
  *contexto.contador_programa++;
}

/**
 * @brief parsea la instrucción write
 * @param instruccion contiene la instrucción a parsear
 */
void Write::parsear(std::string& instruccion) {
  std::istringstream is(instruccion);
  std::string operando;
  is >> codigo_ >> operando;
  if (operando[0] == '=') {
    direccionamiento_ = Direccionamiento::INMEDIATO;
    operando_ = std::stoi(operando.substr(1));
  } else if (operando[0] == '*') {
    direccionamiento_ = Direccionamiento::INDIRECTO;
    operando_ = std::stoi(operando.substr(1));
  } else {
    direccionamiento_ = Direccionamiento::DIRECTO;
    operando_ = std::stoi(operando);
  }
}