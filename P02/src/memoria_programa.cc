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
 * @brief implementacion de la clase MemoriaPrograma
*/

#include "memoria_programa.h"

/**
 * @brief constructor de la clase MemoriaPrograma
 * @param instrucciones vector de instrucciones
 * @param etiquetas mapa de etiquetas
 */
MemoriaPrograma::MemoriaPrograma(std::vector<Instruccion*> instrucciones, std::map<std::string, int> etiquetas) {
  instrucciones_ = instrucciones;
  etiquetas_ = etiquetas;
}