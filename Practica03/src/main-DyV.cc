/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 * Práctica 3: Algoritmos Divide y Vencerás
 *
 * @author Enrique Gómez Díaz
 * @date 11 Mar 2025
 * @brief 
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <algorithm>
#include <fstream>

#include "funciones.cc"
#include "framework.h"
#include "algorithmHanoi.h"
#include "algorithmMerge.h"
#include "algorithmQuick.h"
#include "algorithmBinary.h"
#include "solutionHanoi.h"
#include "solutionMerge.h"
#include "solutionQuick.h"
#include "solutionBinary.h"

void Usage(int argc, char* argv[]) {
  if (argc != 4) {
    std::cout << "Error en la llamada al programa." << std::endl;
    std::cout << "Uso: " << argv[0] << " <modo> <debug> <número>" << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para mas información." << std::endl;
    exit(-1);
  }
  if (std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h") {
    std::cout << "Uso: " << argv[0] << " <modo> <debug> <número>" << std::endl;
    std::cout << "Modos: " << std::endl;
    std::cout << "  --quick, -q: Algoritmo QuickSort" << std::endl;
    std::cout << "  --merge, -m: Algoritmo MergeSort" << std::endl;
    std::cout << "  --binary, -b: Algoritmo BinarySearch" << std::endl;
    std::cout << "  --hanoi, -h: Algoritmo Torres de Hanoi" << std::endl;
  
    std::cout << "Debug: " << std::endl;
    std::cout << "  0: Modo ejecución" << std::endl;
    std::cout << "  1: Modo debug" << std::endl;
    exit(0);
  }
}

std::vector<int> secuenciaAleatoria(int tamanio) {
  srand(time(NULL));
  std::vector<int> secuencia;
  for (int i = 0; i < tamanio; i++) {
    secuencia.push_back(rand() % 100);
  }
  return secuencia;
}

void print(std::vector<int> secuencia) {
  std::cout << "[ ";
  for (auto elemento : secuencia) {
    std::cout << elemento << " ";
  }
  std::cout << "]\n";
}

void ejecutarAlgoritmo(std::string modo, std::vector<int>& secuencia, int tamanio, int debug) {
  Algorithm* Algorithm;
  Solution* solution;

  if (modo == "--quick" || modo == "-q") {
    Algorithm = new AlgorithmQuick(secuencia);
    solution = new SolutionQuick();
  } else if (modo == "--merge" || modo == "-m") {
    Algorithm = new AlgorithmMerge(secuencia);
    solution = new SolutionMerge();
  } else if (modo == "--binary" || modo == "-b") {
    int X = debug ? 0 : secuencia[rand() % secuencia.size()];
    std::sort(secuencia.begin(), secuencia.end());
    if (debug) {
      std::cout << "Introduzca el valor a buscar: ";
      std::cin >> X;
    }
    Algorithm = new AlgorithmBinary(secuencia, X, 0, secuencia.size() - 1);
    solution = new SolutionBinary();
  } else if (modo == "--hanoi" || modo == "-h") {
    std::string origin = "A";
    std::string destination = "C";
    std::string aux = "B";
    Algorithm = new AlgorithmHanoi(tamanio, origin, destination, aux);
    solution = new SolutionHanoi();
  } else {
    std::cout << "Opción no encontrada." << std::endl;
    std::cout << "Pruebe --help para mas información." << std::endl;
    exit(-1);
  }

  Framework* framework = new Framework();
  framework->DivideyVenceras(Algorithm, solution, 0);
  solution->Print();
  framework->PrintRecurrencia(Algorithm);
  std::cout << "\nProfundidad máxima: " << framework->getNivelMaximoRecursion() << std::endl;
  std::cout << "Número total de llamadas recursivas: " << framework->getContadorTotalRecursion() << "\n\n";
}

/*
int main(int argc, char* argv[]) {
  Usage(argc, argv);

  int tamanio = atoi(argv[3]);
  std::vector<int> secuencia_aleatoria = secuenciaAleatoria(tamanio);
  int DEBUG = atoi(argv[2]);

  if (DEBUG == 1) {
    std::cout << "\n========== Modo debug ==========\n" << std::endl;
    std::cout << "Secuencia aleatoria: ";
    print(secuencia_aleatoria);
    std::cout << std::endl << "Secuencia ordenada:  ";
    ejecutarAlgoritmo(argv[1], secuencia_aleatoria, tamanio, DEBUG);
  } else {
    std::cout << "\n========== Modo ejecución ==========\n" << std::endl;
    for (int random = 3; random < 20; random++) {
      secuencia_aleatoria = secuenciaAleatoria(random);
      long long tiempo = calcularTiempo([&] {
        ejecutarAlgoritmo(argv[1], secuencia_aleatoria, random, DEBUG);
      });
      std::cout << "Tiempo de ejecución(size = " << random << "): " << tiempo << " ms" << std::endl;
    }
  }
  return 0;
}
*/

int main(int argc, char* argv[]) {

  const std::string file_out_csv = "Tabla_resultados.csv";
  const std::string file_out_txt = "Tabla_resultados.txt";
  if (argc > 1) {
    std::freopen(file_out_txt.c_str(), "w", stdout);
  }
  std::ofstream out_csv(file_out_csv);

  out_csv << "Tamaño del vector, Profundidad del merge, Tiempo del Merge, Profundidad del Quick, Tiempo del Quick\n";
  // std::cout << "| Tamaño del vector" << " | Profuncidad del merge" << " | Tiempo del Merge" << " | Profundidad del Quick" << " | Tiempo del Quick\n";

  for (int size = 10; size < 5000; size += 10) {
    std::vector<int> seuencia_aleatiora = secuenciaAleatoria(size);

    // Ordenación por Merge
    int max_level_merge = 0;
    auto mergeSortTime = calcularTiempo([&]() {
      Algorithm* problemMerge = new AlgorithmMerge(seuencia_aleatiora);
      Solution* solutionMerge = new SolutionMerge();
      Framework* frameworkMerge = new Framework();
      frameworkMerge->DivideyVenceras(problemMerge, solutionMerge, 0);
      max_level_merge = frameworkMerge->getNivelMaximoRecursion();
      delete problemMerge;
      delete solutionMerge;
      delete frameworkMerge;
    });

    // Ordenación por Quick
    int max_level_quick = 0;
    auto quickSortTime = calcularTiempo([&]() {
      Algorithm* problemQuick = new AlgorithmQuick(seuencia_aleatiora);
      Solution* solutionQuick = new SolutionQuick();
      Framework* frameworkQuick = new Framework();
      frameworkQuick->DivideyVenceras(problemQuick, solutionQuick, 0);
      max_level_quick = frameworkQuick->getNivelMaximoRecursion();
      delete problemQuick;
      delete solutionQuick;
      delete frameworkQuick;
    });

    out_csv << size << ',' << max_level_merge << ',' << mergeSortTime << ',' << max_level_quick << ',' << quickSortTime << "\n";
    // std::cout << "| " << size << " | " << max_level_merge << " | " << mergeSortTime << " | " << max_level_quick << " | " << quickSortTime << "\n";
  }
  return 0;
}
