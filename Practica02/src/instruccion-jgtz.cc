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
 * @brief: implementacion clase InstruccionJGTZ
*/


#include "instruccion-jgtz.h"

#include <iostream>
#include <string>
#include <sstream>

/**
 * @brief Método que ejecuta la instrucción ADD
 * @param contexto: contexto de la máquina RAM
 */
void InstruccionJGTZ::ejecutar(Contexto& contexto) {
  if (contexto.memoria_datos->get_valor(0) > 0) {
    if (contexto.etiquetas.find(etiqueta_) == contexto.etiquetas.end()) {
      std::cerr << "Error: Etiqueta no encontrada" << std::endl;
      exit(1);
    }
    *contexto.contador_programa = contexto.etiquetas.find(etiqueta_)->second;
  } else {
    (*(contexto.contador_programa))++;
  }
}

/**
 * @brief Método que parsea la instrucción ADD
 * @param instruccion: string que contiene la instrucción
 */
void InstruccionJGTZ::parsear(std::string& instruccion) {
  std::istringstream is(instruccion);
  std::string instruccion_;
  is >> opcode_ >> etiqueta_;
}