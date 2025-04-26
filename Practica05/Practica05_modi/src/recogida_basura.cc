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
#include <ctime>
#include <filesystem>
#include "grafo.h"
#include "nodo.h"
#include "posicion.h"
#include "problema.h"
#include "voraz.h"
#include "grasp.h"
#include "gvns.h"
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

  std::ofstream salida("salida.txt", std::ios::out);
  if (!salida.is_open()) {
    std::cerr << "Error: No se pudo abrir el archivo de salida." << std::endl;
    return 1;
  }
  std::streambuf* cout_buf = std::cout.rdbuf();
  std::cout.rdbuf(salida.rdbuf());

  try {
    std::filesystem::path carpeta(argv[1]);
    if (!std::filesystem::is_directory(carpeta)) {
      std::cerr << "Error: " << argv[1] << " no es una carpeta válida." << std::endl;
      return 1;
    }

    for (const auto& archivo : std::filesystem::directory_iterator(carpeta)) {
      if (archivo.is_regular_file()) {
        std::cout << "Procesando archivo: " << archivo.path().filename() << std::endl;

        try {
          Problema problema = leer_archivo(archivo.path().string());
          Problema problema2 = problema;
          Algoritmo* algoritmo;

          // std::cout << "                 ALGORITMO VORAZ                       " << std::endl << std::endl;  
          // algoritmo = new Voraz(problema);
          // auto start = std::chrono::high_resolution_clock::now();
          // algoritmo->resolver();
          // auto end = std::chrono::high_resolution_clock::now();
          // std::chrono::duration<double> elapsed = end - start;

          // std::cout << "Nodos: " << algoritmo->obtener_problema().obtener_nodos().size() - 4 << std::endl;
          // std::cout << "Camiones recolección: " << algoritmo->obtener_solucion().get_camiones() << std::endl;
          // std::cout << "Camiones descarga: " << algoritmo->obtener_solucion().get_camiones_transporte().size() << std::endl;
          // std::cout << "Tiempo de ejecución: " << elapsed.count() << " segundos" << std::endl;
          // delete algoritmo;

          // std::cout << "                 ALGORITMO GRASP                       " << std::endl << std::endl;
          // int lrc = 3;
          // for (int i = 0; i < 3; i++) {
          //   std::cout << "LRC: " << lrc << std::endl;
          //   for (int j = 0; j < 3; j++) {
          //     std::cout << "Iteracion: " << j + 1 << std::endl;
          //     problema = problema2;
          //     algoritmo = new GRASP(problema);
          //     dynamic_cast<GRASP*>(algoritmo)->set_LRC(lrc);
          //     auto start = std::chrono::high_resolution_clock::now();
          //     algoritmo->resolver();
          //     auto end = std::chrono::high_resolution_clock::now();
          //     std::chrono::duration<double> elapsed = end - start;

          //     std::cout << "Nodos: " << algoritmo->obtener_problema().obtener_nodos().size() - 4 << std::endl;
          //     std::cout << "Camiones: " << algoritmo->obtener_solucion().get_camiones() << std::endl;
          //     std::cout << "Tiempo de ejecución: " << elapsed.count() << " segundos" << std::endl;
          //     delete algoritmo;
          //   }
          //   lrc += 1;
          // }

          std::cout << "                 ALGORITMO GVNS                        " << std::endl << std::endl;
          int max_k = 3;
          for (int i = 0; i < 3; i++) {
            std::cout << "Max_k: " << max_k << std::endl;
            for (int j = 0; j < 3; j++) {
              std::cout << "Iteracion: " << j + 1 << std::endl;
              problema = problema2;
              algoritmo = new GVNS(problema);
              dynamic_cast<GVNS*>(algoritmo)->set_max_k(max_k);
              auto start = std::chrono::high_resolution_clock::now();
              algoritmo->resolver();
              auto end = std::chrono::high_resolution_clock::now();
              std::chrono::duration<double> elapsed = end - start;
              std::cout << "Nodos: " << algoritmo->obtener_problema().obtener_nodos().size() - 4 << std::endl;
              std::cout << "Camiones: " << algoritmo->obtener_solucion().get_camiones() << std::endl;
              std::cout << "Tiempo de ejecución: " << elapsed.count() << " segundos" << std::endl;
              delete algoritmo;
            }
            max_k += 1;
          }

        } catch (const std::exception& e) {
          std::cerr << "Error procesando archivo " << archivo.path().filename() << ": " << e.what() << std::endl;
        }

        std::cout << "--------------------------------------------------------" << std::endl;
      }
    }
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }
  
  return 0;
}