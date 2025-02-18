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
 * @brief implementacion de la clase MaquinaRam
*/

#pragma once

#include "maquina_ram.h"

/**
 * @brief Constructor de la clase MaquinaRam
 * @param instrucciones contiene las instrucciones de la máquina RAM
 * @param cinta_entrada contiene la cinta de entrada
 * @param cinta_salida contiene la cinta de salida
 */
MaquinaRam::MaquinaRam(MemoriaPrograma instrucciones, std::ifstream& cinta_entrada, std::string& cinta_salida) {
  unidad_entrada_ = UnidadEntrada(cinta_entrada);
  unidad_salida_ = UnidadSalida();
  salida_ = cinta_salida;
  instrucciones_ = instrucciones;

  contexto_.memoria_datos = &datos_;
  contexto_.unidad_entrada = &unidad_entrada_;
  contexto_.unidad_salida = &unidad_salida_;
  contexto_.etiquetas = instrucciones.get_etiquetas();
  contexto_.contador_programa = &contador_instrucciones_;
}

void MaquinaRam::ejecutar() {
  instrucciones_.get_instruccion(contador_instrucciones_)->ejecutar(contexto_);
}