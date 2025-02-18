/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * @author Esther M. Quintero
 * @date 14 Feb 2024
 * @brief Implementación de la clase "InstruccionJZERO"
 *        (Principio ESTRATEGIA)
 */


#include "instruccion-jzero.h"
#include "utilities.h"

#include <iostream>
#include <string>
#include <sstream>

/**
 * @brief Método que ejecuta la instrucción ADD
 * @param[in] contexto: contexto de la máquina RAM
 */
void InstruccionJZERO::ejecutar(Contexto& contexto) {
  #ifdef DEPURAR
  std::cout << "Ejecutando instrucción JZERO..." << std::endl;
  #endif
  if (contexto.memoria_datos->get_valor(0) == 0) {
    if (contexto.etiquetas.find(etiqueta_) == contexto.etiquetas.end()) {
      std::cerr << RED "Error: Etiqueta no encontrada" NC << std::endl;
      std::cerr << "--> void InstruccionJZERO::ejecutar(Contexto& contexto)" << std::endl;
      std::cerr << "--> Línea 30 de instruccion-jzero.cc" << std::endl;
      exit(1);
    }
    *contexto.contador_programa = contexto.etiquetas.find(etiqueta_)->second;
  } else {
    (*(contexto.contador_programa))++;
  }
}

/**
 * @brief Método que parsea la instrucción ADD
 * @param[in] instruccion: string que contiene la instrucción
 */
void InstruccionJZERO::parsear(std::string& instruccion) {
  #ifdef DEPURAR
  std::cout << "Parseando instrucción JZERO..." << std::endl;
  #endif
  std::istringstream is(instruccion);
  std::string instruccion_;
  is >> opcode_ >> etiqueta_;
}

/**
 * @brief Método que escribe la instrucción ADD
 * @param[in] os: flujo de salida
 * @param[in] debug: booleano que indica si se quiere escribir en modo debug
 * @return flujo de salida
 */
std::ostream& InstruccionJZERO::write(std::ostream& os, bool debug) const {
  if (debug) {
    os << "\nOpcode: " << opcode_;
    os << "\nDireccionamiento: " << direccionamiento_;
    os << "\nOperando: " << etiqueta_;
  } else {
    os << opcode_ << " ";
    switch (direccionamiento_) {
      case Direccionamiento::DIRECTO:
        os << etiqueta_;
        break;
      case Direccionamiento::INMEDIATO:
        os << "=" << etiqueta_;
        break;
      case Direccionamiento::INDIRECTO:
        os << "*" << etiqueta_;
        break;
    }
  }
  return os;
}