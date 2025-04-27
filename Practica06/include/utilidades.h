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
 * @brief: cabecera de funciones de utilidad
*/

#pragma once

#include <iostream>
#include <fstream>

#include "busqueda-local.h"
#include "error.h"
#include "grasp.h"
#include "problema.h"
#include "voraz.h"

void ussage(int argc, char* argv[]);
void ejecutarProgramaArchivo (char* argv[]);
void ejecutarProgramaCarpeta (char* argv[]);