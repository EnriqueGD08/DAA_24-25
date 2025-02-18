/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * @author Esther M. Quintero
 * @date 14 Feb 2024
 * @brief Implementación de la clase "InstruccionWRITE"
 *        (Principio ESTRATEGIA)
 */


#include "instruccion-write.h"
#include "utilities.h"

#include <iostream>
#include <string>
#include <sstream>

/**
 * @brief Método que ejecuta la instrucción ADD
 * @param[in] contexto: contexto de la máquina RAM
 */
void InstruccionWRITE::ejecutar(Contexto& contexto) {
  #ifdef DEPURAR
  std::cout << "Ejecutando instrucción WRITE..." << std::endl;
  #endif
  switch (direccionamiento_) {
    case Direccionamiento::DIRECTO:
      if (operando_ == 0) {
        std::cerr << RED "Error: no se puede escribir en la dirección 0" NC << std::endl;
        std::cerr << "--> void InstruccionWRITE::ejecutar(Contexto& contexto)" << std::endl;
        std::cerr << "--> Línea 30 de instruccion-write.cc" << std::endl;
        exit(1);
      }
      /// Sumamos el valor de la dirección de memoria al acumulador
      contexto.cinta_salida->escribir(contexto.memoria_datos->get_valor(operando_));
      break;
    case Direccionamiento::INMEDIATO:
      /// Sumamos el valor inmediato al acumulador
      contexto.cinta_salida->escribir(operando_);
      break;
    case Direccionamiento::INDIRECTO:
      /// Sumamos el valor de la dirección de memoria que contiene otra dirección de memoria al acumulador
      contexto.cinta_salida->escribir(contexto.memoria_datos->get_valor(contexto.memoria_datos->get_valor(operando_)));
      break;
  }
  (*(contexto.contador_programa))++;
}

/**
 * @brief Método que parsea la instrucción ADD
 * @param[in] instruccion: string que contiene la instrucción
 */
void InstruccionWRITE::parsear(std::string& instruccion) {
  #ifdef DEPURAR
  std::cout << "Parseando instrucción WRITE..." << std::endl;
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
std::ostream& InstruccionWRITE::write(std::ostream& os, bool debug) const {
  if (debug) {
    os << "Opcode: " << opcode_;
    os << "Direccionamiento: " << direccionamiento_;
    os << "Operando: " << operando_;
  } else {
    os << opcode_ << " ";
    switch (direccionamiento_) {
      case Direccionamiento::DIRECTO:
        os << operando_;
        break;
      case Direccionamiento::INDIRECTO:
        os << "*" << operando_;
        break;
      case Direccionamiento::INMEDIATO:
        os << "=" << operando_;
        break;
    }
  }
  return os;
}