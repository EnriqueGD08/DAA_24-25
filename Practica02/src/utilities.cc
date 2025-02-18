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
 * @brief: Funciones que se usan en el programa
*/

#include "utilities.h"

const std::string MensajeHelp = "uso: ./programa test/testn.tam cinta_entrada.txt cinta_salida.txt";

/** 
 *  @brief Muestra el modo de uso correcto del programa
 *  @param argc Número de parámetros.
 *  @param argv Vector con los parámetros.
 */
void Usage(int argc, char *argv[]) {
  if (argc > 5) {
    std::cout << argv[0] << ": Ha introducido más de 4 parámetros." << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para mas información." << std::endl;
    exit(EXIT_FAILURE);
  }
  std::string parametro{argv[1]};
  if (parametro == "--help") {
    std::cout << MensajeHelp << std::endl;
    exit(EXIT_SUCCESS);
  }
  if (argc != 4) {
    std::cout << argv[0] << ": Faltan parámetros." << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para mas información." << std::endl;
    exit(EXIT_FAILURE);
  }
}