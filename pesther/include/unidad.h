/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * @author Esther M. Quintero
 * @date 14 Feb 2024
 * @brief Encabezado de la clase "Unidad"
 *        (Principio ESTRATEGIA)
 */

#ifndef UNIDAD_H_
#define UNIDAD_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "memoria-datos.h"
#include "memoria-programa.h"
#include "cinta-salida.h"
#include "cinta-entrada.h"

class Unidad {
 public:
  Unidad(MemoriaPrograma memoria_programa, std::ifstream& entrada, std::string& salida); /// Constructor por defecto
  ~Unidad() {}; /// Destructor por defecto
  void escribir_en_fichero() { cinta_salida_.escribir_en_fichero(salida_); }
  std::ostream& escribir_cinta_salida(std::ostream& os) { return cinta_salida_.print(os); }
  std::ostream& escribir_cinta_entrada(std::ostream& os) { return cinta_entrada_.print(os); }
  std::ostream& escribir_memoria_datos(std::ostream& os) { return os << memoria_datos_; }
  std::ostream& mostrar_siguiente_instruccion(std::ostream& os, bool debug);

  bool HALT = false;
  void ejecutar_instruccion();

 private:
  int contador_programa_ = 0;
  MemoriaPrograma memoria_programa_;
  MemoriaDatos memoria_datos_;
  CintaEntrada cinta_entrada_;
  CintaSalida cinta_salida_;
  std::string salida_;
  Contexto contexto_;
};

#endif