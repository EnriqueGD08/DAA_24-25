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
 * @brief: main del programa
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "unidad.h"
#include "parser.h"
#include "utilities.h"

std::ifstream programa_entrada;
std::ifstream cinta_entrada;

int main(int argc, char* argv[]) {

  Usage(argc, argv);

  programa_entrada.open(argv[1]);
  cinta_entrada.open(argv[2]);

  if ((!programa_entrada.is_open()) || (!cinta_entrada.is_open())) {
    std::cerr << "Error en la lectura de archivos de entrada." << std::endl;
    return 1;
  }

  std::string cinta_salida_str = std::string(argv[3]);
  Parser parser(programa_entrada);
  Unidad unidad(parser.programa_parseado(), cinta_entrada, cinta_salida_str);

  while (!unidad.HALT) {
    unidad.ejecutar_instruccion();
  }

  return 0;
}