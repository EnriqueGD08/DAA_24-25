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
 * @brief: implementacion clase Unidad
*/

#include <iostream>
#include "unidad.h"

/**
 * @brief Constructor de la clase Unidad
 * @param memoria_programa: memoria de programa
 * @param entrada: flujo de entrada
 * @param salida: flujo de salida
 */
Unidad::Unidad(MemoriaPrograma memoria_programa, std::ifstream& entrada, std::string& salida) {
  cinta_entrada_ = CintaEntrada(entrada);
  cinta_salida_ = CintaSalida();
  salida_ = salida;
  memoria_programa_ = memoria_programa;

  contexto_.contador_programa = &contador_programa_;
  contexto_.cinta_entrada = &cinta_entrada_;
  contexto_.cinta_salida = &cinta_salida_;
  contexto_.memoria_datos = &memoria_datos_;
  contexto_.etiquetas = memoria_programa.get_etiquetas();
}

/**
 * @brief Método que ejecuta la instrucción actual
 */
void Unidad::ejecutar_instruccion() {
  try {
    memoria_programa_.get_instruccion(contador_programa_)->ejecutar(contexto_);
  } catch (char x) {
    if (x == 'x') {
      escribir_en_fichero();
      HALT = true;
    }
  }
}
