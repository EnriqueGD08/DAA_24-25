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
 * @brief: declaración clase Maquina
*/


#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "memoria-datos.h"
#include "memoria-programa.h"
#include "cinta-salida.h"
#include "cinta-entrada.h"

class Maquina {
 public:
  Maquina(MemoriaPrograma memoria_programa, std::ifstream& entrada, std::string& salida);
  ~Maquina() {};
  void escribir_en_fichero() { cinta_salida_.escribir_en_fichero(salida_); }
  std::ostream& escribir_cinta_salida(std::ostream& os) { return cinta_salida_.print(os); }
  std::ostream& escribir_cinta_entrada(std::ostream& os) { return cinta_entrada_.print(os); }
  std::ostream& escribir_memoria_datos(std::ostream& os) { return os << memoria_datos_; }

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