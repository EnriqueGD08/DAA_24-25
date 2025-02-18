/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * @author Esther M. Quintero
 * @date 14 Feb 2024
 * @brief Implementación de la clase "InstruccionLOAD"
 *        (Principio ESTRATEGIA)
 */


#include "instruccion-load.h"

#include <iostream>
#include <string>
#include <sstream>

/**
 * @brief Método que ejecuta la instrucción ADD
 * @param[in] contexto: contexto de la máquina RAM
 */
void InstruccionLOAD::ejecutar(Contexto& contexto) {
  #ifdef DEPURAR
  std::cout << "Ejecutando instrucción LOAD..." << std::endl;
  #endif
  switch (direccionamiento_) {
    case Direccionamiento::DIRECTO:
      /// Sumamos el valor de la dirección de memoria al acumulador
      contexto.memoria_datos->set_valor(contexto.memoria_datos->get_valor(operando_));
      break;
    case Direccionamiento::INMEDIATO:
      /// Sumamos el valor inmediato al acumulador
      contexto.memoria_datos->set_valor(operando_);
      break;
    case Direccionamiento::INDIRECTO:
      /// Sumamos el valor de la dirección de memoria que contiene otra dirección de memoria al acumulador
      contexto.memoria_datos->set_valor(contexto.memoria_datos->get_valor(contexto.memoria_datos->get_valor(operando_)));
      break;
  }
  (*(contexto.contador_programa))++;
}

/**
 * @brief Método que parsea la instrucción LOAD
 * @param[in] instruccion: string que contiene la instrucción
 */
void InstruccionLOAD::parsear(std::string& instruccion) {
  #ifdef DEPURAR
  std::cout << "Parseando instrucción LOAD..." << std::endl;
  #endif
  std::istringstream stream(instruccion);
  std::string aux;
  stream >> opcode_ >> aux;
  if (aux[0] == '=') {
    direccionamiento_ = Direccionamiento::INMEDIATO;
    operando_ = stoi(aux.substr(1));
  } else if (aux[0] == '*') {
    direccionamiento_ = Direccionamiento::INDIRECTO;
    operando_ = stoi(aux.substr(1));
  } else {
    operando_ = stoi(aux);
    direccionamiento_ = Direccionamiento::DIRECTO;
  }
}

/**
 * @brief Método que escribe la instrucción ADD
 * @param[in] os: flujo de salida
 * @param[in] debug: booleano que indica si se quiere escribir en modo debug
 * @return flujo de salida
 */
std::ostream& InstruccionLOAD::write(std::ostream& os, bool debug) const {
  if (debug) {
    os << "\nOpcode: " << opcode_;
    os << "\nDireccionamiento: " << direccionamiento_;
    os << "\nOperando: " << operando_;
  } else {
    os << opcode_ << " ";
    switch (direccionamiento_) {
      case Direccionamiento::DIRECTO:
        os << operando_;
        break;
      case Direccionamiento::INMEDIATO:
        os << "=" << operando_;
        break;
      case Direccionamiento::INDIRECTO:
        os << "*" << operando_;
        break;
    }
  }
  return os;
}