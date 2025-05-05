/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Diseño y Análisis de Algoritmos
 * Curso: 3º
 * Práctica 6
 * @autor: Enrique Gómez Díaz
 * @mail: alu0101550329@ull.edu.es
 * @date: 06/05/2025
 * @brief: archivo principal del programa
*/

#include "utilidades.h"

/**
 * @brief Función principal del programa.
 * @param argc Número de argumentos de la línea de comandos.
 * @param argv Arreglo de argumentos de la línea de comandos.
 * @return 0 si el programa se ejecuta correctamente, otro si hay un error.
 */
int main (int argc, char* argv[]) {
  ussage(argc, argv);

  try {
    if (std::string(argv[1]) == "-a") {
      ejecutarProgramaArchivo(argv);
    } else {
      ejecutarProgramaCarpeta(argv);
    }
  } catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
      
    return EXIT_FAILURE;
  }

  return 0;
}