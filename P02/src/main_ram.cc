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
 * @brief main del programa de máquina RAM
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "parser.h"
#include "maquina_ram.h"

/**
 * @brief Muestra el uso correcto del programa
 * @param argc número de argumentos
 * @param argv argumentos
 */
void Usage(int argc, char* argv[]) {
  if (argc != 4) {
    std::cerr << "Error en la llamada al programa" << std::endl;
    std::cerr << "Uso: " << argv[0] << " <fichero_programa> <cinta_entrada> <cinta_salida>" << std::endl;
    exit(1);
  }
}

std::ifstream fichero_programa;
std::ifstream cinta_entrada;

/**
 * @brief funcion principal del programa
 * @param argc número de argumentos
 * @param argv argumentos
 * @return 0 si todo ha ido bien, 1 si ha habido un error
 */
int main(int argc, char* argv[]) {

  Usage(argc, argv);

  fichero_programa.open(argv[1]);
  cinta_entrada.open(argv[2]);

  if (!fichero_programa.is_open() || !cinta_entrada.is_open()) {
    std::cerr << "Error al abrir los ficheros" << std::endl;
    return 1;
  }

  std::string cinta_salida_str = std::string(argv[3]);
  Parser programa_parseado(fichero_programa);

  MaquinaRam maquina(programa_parseado.parsear(), cinta_entrada, cinta_salida_str);
  while (maquina.halt == false) {
    maquina.ejecutar();
  }

  return 0;
}