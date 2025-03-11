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

int main(int argc, char* argv[]){
  
  Usage(argc, argv);

  int tamanio = atoi(argv[3]);
  std::vector<int> secuencia_aleatoria = secuenciaAleatoria(tamanio);
  Algorithm* Algorithm;
  Solution* solution;
  int DEBUG = atoi(argv[2]);

  if (DEBUG == 1) {
    std::cout << "\n----- Modo debug -----\n" << std::endl;

    if (std::string(argv[1]) == "--quick" || std::string(argv[1]) == "-q") {
      print(secuencia_aleatoria);
      Algorithm = new AlgorithmQuick(secuencia_aleatoria);
      solution = new SolutionQuick();
    } else if (std::string(argv[1]) == "--merge" || std::string(argv[1]) == "-m") {
      print(secuencia_aleatoria);
      Algorithm = new AlgorithmMerge(secuencia_aleatoria);
      solution = new SolutionMerge();
    } else if (std::string(argv[1]) == "--binary" || std::string(argv[1]) == "-b") {
      int X;
      std::sort(secuencia_aleatoria.begin(), secuencia_aleatoria.end());
      print(secuencia_aleatoria);
      std::cout << "Introduzca el valor a buscar: ";
      std::cin >> X;
      Algorithm = new AlgorithmBinary(secuencia_aleatoria, X, 0, secuencia_aleatoria.size() - 1);
      solution = new SolutionBinary();
    } else if (std::string(argv[1]) == "--hanoi" || std::string(argv[1]) == "-h") {
      std::string origin = "A";
      std::string destination = "C";
      std::string aux = "B";
      Algorithm = new AlgorithmHanoi(tamanio, origin, destination, aux);
      solution = new SolutionHanoi();
    } else { 
      std::cout << "Opción no encontrada." << std::endl;
      std::cout <<  "Pruebe " << argv[0] << " --help para mas información." << std::endl;
      exit(-1);
    }

    Framework* framework = new Framework();
    framework->DivideyVenceras(Algorithm, solution, 0);
    solution->Print();
    framework->PrintRecurrencia(Algorithm);
    std::cout <<  "\n Profundidad máxima: " << 
    framework->getNivelMaximoRecursion() << std::endl;
    std::cout << "Número total de llamadas recursivas: " <<
    framework->getContadorTotalRecursion() << "\n\n";

  } else {
    std::cout << "\n----- Modo ejecución -----\n" << std::endl;
    for (int random = 3; random < 20; random++) {
      secuencia_aleatoria = secuenciaAleatoria(random);
      if (std::string(argv[1]) == "--quick" || std::string(argv[1]) == "-q") {
        Algorithm = new AlgorithmQuick(secuencia_aleatoria);
        solution = new SolutionQuick();
      } else if (std::string(argv[1]) == "--merge" || std::string(argv[1]) == "-m") {
        Algorithm = new AlgorithmMerge(secuencia_aleatoria);
        solution = new SolutionMerge();
      } else if (std::string(argv[1]) == "--binary" || std::string(argv[1]) == "-b") {
        // Buscamos un número al azar en el vector
        int X = secuencia_aleatoria[rand() % secuencia_aleatoria.size()];
        // Ordenamos el vector
        std::sort(secuencia_aleatoria.begin(), secuencia_aleatoria.end());
        Algorithm = new AlgorithmBinary(secuencia_aleatoria, X, 0, secuencia_aleatoria.size() - 1);
        solution = new SolutionBinary();
      } else if (std::string(argv[1]) == "--hanoi" || std::string(argv[1]) == "-h") {
        std::string origin = "A";
        std::string destination = "C";
        std::string aux = "B";
        Algorithm = new AlgorithmHanoi(random, origin, destination, aux);
        solution = new SolutionHanoi();
      } else { 
        std::cout << "Opción no encontrada." << std::endl;
        std::cout << "Pruebe " << argv[0] << " --help para mas información." << std::endl;
        exit(-1);
      }

      Framework* framework = new Framework();
      long long tiempo = calcularTiempo([&] {
        framework->DivideyVenceras(Algorithm, solution, 0);
      });
      std::cout << "Tiempo de ejecución(size = " << random << "): " << tiempo << " ms" << std::endl;
      
    }
  }
}