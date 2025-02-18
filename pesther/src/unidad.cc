/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * @author Esther M. Quintero
 * @date 14 Feb 2024
 * @brief Implementación de la clase "Unidad"
 *        (Principio ESTRATEGIA)
 */

#include <iostream>
#include "unidad.h"

/**
 * @brief Constructor de la clase Unidad
 * @param[in] memoria_programa: memoria de programa
 * @param[in] entrada: flujo de entrada
 * @param[in] salida: flujo de salida
 */
Unidad::Unidad(MemoriaPrograma memoria_programa, std::ifstream& entrada, std::string& salida) {
  #ifdef DEPURAR
  std::cout << "Creando unidad..." << std::endl;
  #endif
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
    #ifdef DEPURAR
    std::cout << "Ejecutando instrucción..." << std::endl;
    #endif
    memoria_programa_.get_instruccion(contador_programa_)->ejecutar(contexto_);
    #ifdef DEPURAR
    std::cout << "Instrucción ejecutada." << std::endl;
    #endif
  } catch (char x) {
    if (x == 'x') {
      escribir_en_fichero();
      HALT = true;
    }
  }
}

/**
 * @brief Método que muestra la siguiente instrucción
 * @param[in] os: flujo de salida
 * @param[in] contador_programa: contador de programa
 */
std::ostream& Unidad::mostrar_siguiente_instruccion(std::ostream& os, bool debug) {
  return memoria_programa_.get_instruccion(contador_programa_)->write(os, debug);
}
