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
 * @brief declaración de la clase máquina RAM
*/

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "unidad_salida.h"
#include "unidad_entrada.h"
#include "memoria_programa.h"
#include "memoria_datos.h"

class MaquinaRam {
 public:
  MaquinaRam(MemoriaPrograma instrucciones, std::ifstream& cinta_entrada, std::string& cinta_salida);
  ~MaquinaRam() {};

  void ejecutar();
  bool halt = false;

 private:
  MemoriaPrograma instrucciones_;
  MemoriaDatos datos_;
  UnidadSalida unidad_salida_;
  UnidadEntrada unidad_entrada_;
  int contador_instrucciones_ = 0;
  Contexto contexto_;
  std::string salida_;
};