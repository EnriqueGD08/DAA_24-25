/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * @author Esther M. Quintero
 * @date 14 Feb 2024
 * @brief Implementación de la clase "InstruccionSTORE"
 *        (Principio ESTRATEGIA)
 */


#include "instruccion-store.h"
#include "utilities.h"

#include <iostream>
#include <string>
#include <sstream>

/**
 * @brief Método que ejecuta la instrucción ADD
 * @param[in] contexto: contexto de la máquina RAM
 */
void InstruccionSTORE::ejecutar(Contexto& contexto) {
  #ifdef DEPURAR
  std::cout << "Ejecutando instrucción STORE..." << std::endl;
  #endif
  switch (direccionamiento_) {
    case Direccionamiento::DIRECTO:
      /// Sumamos el valor de la dirección de memoria al acumulador
      contexto.memoria_datos->guardar_valor(contexto.memoria_datos->get_valor(0), operando_);
      break;
    case Direccionamiento::INDIRECTO:
      /// Sumamos el valor de la dirección de memoria que contiene otra dirección de memoria al acumulador
      contexto.memoria_datos->guardar_valor(contexto.memoria_datos->get_valor(0), contexto.memoria_datos->get_valor(operando_));
      break;
    case Direccionamiento::INMEDIATO:
      std::cerr << RED "Error: no se puede guardar en una dirección inmediata" NC << std::endl;
      std::cerr << "--> void InstruccionSTORE::ejecutar(Contexto& contexto)" << std::endl;
      std::cerr << "--> Línea 37 de instruccion-store.cc" << std::endl;
      exit(1);
      break;
  }
  (*(contexto.contador_programa))++;
}

/**
 * @brief Método que parsea la instrucción ADD
 * @param[in] instruccion: string que contiene la instrucción
 */
void InstruccionSTORE::parsear(std::string& instruccion) {
  #ifdef DEPURAR
  std::cout << "Parseando instrucción STORE..." << std::endl;
  #endif
  std::istringstream stream(instruccion);
  std::string aux;
  stream >> opcode_ >> aux;
  if (aux[0] == '=') {
    std::cerr << RED "Error: no se puede guardar en una dirección inmediata" NC << std::endl;
    std::cerr << "--> void InstruccionSTORE::parsear(std::string& instruccion)" << std::endl;
    std::cerr << "--> Línea 58 de instruccion-store.cc" << std::endl;
    exit(1);
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
std::ostream& InstruccionSTORE::write(std::ostream& os, bool debug) const {
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