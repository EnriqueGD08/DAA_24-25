/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 28 Ene 2024
 * @brief Archivo: utilities.h     
 * 
 * @details 
 *    28/01/2024 - Creación del fichero
 *    28/01/2024 - Añadidas las declaraciones de las funciones
 */

#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"
#define BLK "\033[1m"

void Usage(int argc, char *argv[]);
void Error();

#endif