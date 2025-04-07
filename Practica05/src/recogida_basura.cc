/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Diseño y Análisis de Algoritmos
 * Curso: 2º
 * Práctica 5
 * @autor: Enrique Gómez Díaz
 * @mail: alu0101550329@ull.edu.es
 * @date: 25/03/2025
 * @brief: fichero de la funcion principal
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include "grafo.h"
#include "nodo.h"
#include "posicion.h"
#include "problema.h"
#include "voraz.h"
#include "grasp.h"
#include "algoritmo.h"
#include "solucion.h"
#include "utils.h"

int main(int argc, char* argv[]) {
  system("clear");
  std::cout << "--------------------------------------------------------" << std::endl;
  std::cout << "                 RECOGIDA DE BASURA                    " << std::endl;
  std::cout << "--------------------------------------------------------" << std::endl;
  if (argc < 2) {
    std::cerr << "Uso: " << argv[0] << " <archivo_entrada>" << std::endl;
    return 1;
  }

  try {
    Problema problema = leer_archivo(argv[1]);
    Algoritmo* algoritmo;
    std::cout << "                 ALGORITMO VORAZ                       " << std::endl << std::endl;  
    algoritmo = new Voraz(problema);
    algoritmo->resolver();
    algoritmo->mostrar_solucion();

    std::cout << "                 ALGORITMO GRASP                       " << std::endl << std::endl;
    algoritmo = new GRASP(problema);
    algoritmo->resolver();
    algoritmo->mostrar_solucion();
    delete algoritmo;
      
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    
    return 1;
  }
  
  return 0;
}