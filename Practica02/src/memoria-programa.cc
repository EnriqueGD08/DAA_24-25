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
 * @brief: implementacion clase MemoriaPrograma
*/

#include "memoria-programa.h"

#include <iostream>
#include <vector>
#include <memory>
#include <map>

/**
 * @brief Constructor de la clase "MemoriaPrograma"
 * @param programa: vector de instrucciones que forman el programa
 * @param etiquetas: mapa con las etiquetas del programa y su posición
 */
MemoriaPrograma::MemoriaPrograma(std::vector<Instruccion*> programa, std::map<std::string, int> etiquetas) {
  programa_ = programa;
  etiquetas_ = etiquetas;
}

/**
 * @brief Método que escribe la memoria de programa en un flujo de salida
 * @param os: flujo de salida
 * @return flujo de salida
 */
std::ostream& MemoriaPrograma::write(std::ostream& os) const {
  for (int i = 0; i < (int)programa_.size(); i++) {
    for (auto etiqueta : etiquetas_) {
      if (etiqueta.second == i) os << etiqueta.first << ":";
    }
    os << programa_[i] << std::endl;
  }
  return os;
}