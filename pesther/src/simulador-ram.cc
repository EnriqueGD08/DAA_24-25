/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * @author Esther M. Quintero
 * @date 15 Feb 2024
 * @brief Programa principal que simula el funcionamiento de una máquina RAM
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
bool debug_flag;
char opcion;

int main(int argc, char* argv[]) {

  /// Comprobación de parámetros
  if (argc == 1) { Error(); }
  Usage(argc, argv);

  programa_entrada.open(argv[1]);
  cinta_entrada.open(argv[2]);
  debug_flag = (atoi(argv[4]) == 1) ? 1 : 0;

  if ((!programa_entrada.is_open()) || (!cinta_entrada.is_open())) {
    std::cerr << RED "--> Error en la lectura de archivos de entrada." NC << std::endl;
    return 1;
  }

  std::string cinta_salida_str = std::string(argv[3]);
  Parser parser(programa_entrada);
  Unidad unidad(parser.programa_parseado(), cinta_entrada, cinta_salida_str);

  if (debug_flag == 1) {
    while ((opcion != 'x') && (unidad.HALT == false)) {
      std::cout << BLK "\n----------- Simulador RAM -----------\n" NC
                << "[e]: Ejecutar siguiente instrucción\n"
                << "[v]: Ver siguiente instrucción\n"
                << "[t]: Terminar el programa\n"
                << "[r]: Mostrar la memoria de datos\n"
                << "[i]: Mostrar la cinta de entrada\n"
                << "[o]: Mostrar la cinta de salida\n"
                << "[x]: Salir\n"
                << "--> ";
      std::cin >> opcion;
      switch (opcion) {
        case 'e':
          #ifdef DEPURAR
          std::cout << "Entrando en el case s..." << std::endl;
          #endif
          std::cout << std::endl;
          unidad.mostrar_siguiente_instruccion(std::cout, true);
          unidad.ejecutar_instruccion();
          std::cout << std::endl;
          break;
        case 'v':
          #ifdef DEPURAR
          std::cout << "Entrando en el case v..." << std::endl;
          #endif
          std::cout << std::endl;
          unidad.mostrar_siguiente_instruccion(std::cout, false);
          std::cout << std::endl;
          break;
        case 't':
          #ifdef DEPURAR
          std::cout << "Entrando en el case t..." << std::endl;
          #endif
          while (!unidad.HALT) unidad.ejecutar_instruccion();
          break;
        case 'r':
          #ifdef DEPURAR
          std::cout << "Entrando en el case r..." << std::endl;
          #endif
          std::cout << std::endl << CYN "Contenido de los registros: " NC << std::endl;
          unidad.escribir_memoria_datos(std::cout);
          std::cout << std::endl;
          break;
        case 'i':
          #ifdef DEPURAR
          std::cout << "Entrando en el case i..." << std::endl;
          #endif
          std::cout << std::endl << CYN "Contenido de la cinta de entrada: " NC;
          unidad.escribir_cinta_entrada(std::cout);
          std::cout << std::endl << std::endl;
          break;
        case 'o':
          #ifdef DEPURAR
          std::cout << "Entrando en el case o..." << std::endl;
          #endif
          std::cout << std::endl << CYN "Contenido de la cinta de salida: " NC;
          unidad.escribir_cinta_salida(std::cout);
          std::cout << std::endl << std::endl;
          break;
        case 'x':
          #ifdef DEPURAR
          std::cout << "Entrando en el case x..." << std::endl;
          #endif
          unidad.escribir_en_fichero();
          unidad.HALT = true;
          return 0;
          break;
        default:
          std::cerr << RED "Opción no válida." NC << std::endl;
          std::cerr << "--> int main(int argc, char* argv[])" << std::endl;
          std::cerr << "--> Línea 113 de simulador-ram.cc" << std::endl;
          exit(1);
          break;
      }
    }
  } else {
    #ifdef DEPURAR
    std::cout << "Entrando en el else..." << std::endl;
    #endif
    while (!unidad.HALT) {
      unidad.ejecutar_instruccion();
    }
  }
  return 0;
}