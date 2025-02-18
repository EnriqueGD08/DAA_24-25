/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * @author Esther M. Quintero
 * @date 13 Feb 2024
 * @brief Encabezado de la clase "Instruccion" de la que heredarán las instrucciones
 *        (Principio ESTRATEGIA)
 */

#ifndef INSTRUCCION_H_
#define INSTRUCCION_H_

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "memoria-datos.h"
#include "cinta-entrada.h"
#include "cinta-salida.h"

/**
 * @brief Contexto de la instrucción.
 *        Datos que necesita la instrucción para ejecutarse.
 */
struct Contexto {
  CintaEntrada* cinta_entrada;
  CintaSalida* cinta_salida;  
  std::map<std::string, int> etiquetas;
  int* contador_programa;
  MemoriaDatos* memoria_datos;
};

/**
 * @brief Tipos de direccionamientos que podemos usar.
 *        INMEDIATO: el operando es un valor concreto.
 *          --> Operando =i
 *        DIRECTO: el operando es una dirección de memoria.
 *          --> Operando i
 *        INDIRECTO: el operando es una dirección de memoria que contiene otra dirección de memoria.
 *          --> Operando *i
 */
enum Direccionamiento {
  INMEDIATO,
  DIRECTO,
  INDIRECTO
};

class Instruccion {
 public:
  Instruccion() {}; /// Constructor por defecto
  virtual ~Instruccion() {}; /// Destructor por defecto
  virtual void ejecutar(Contexto& contexto) = 0; 
  virtual void parsear(std::string& instruccion) = 0; 
  virtual std::ostream& write(std::ostream& os, bool debug) const = 0; 

 protected:
  std::string opcode_; /// Código de operación de la instrucción
  Direccionamiento direccionamiento_ = INMEDIATO; /// Tipo de direccionamiento de la instrucción
};

#endif