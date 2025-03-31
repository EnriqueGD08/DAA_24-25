
/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Diseño y Análisis de Algoritmos
 * Curso: 2º
 * Práctica 4
 * @autor: Enrique Gómez Díaz
 * @mail: alu0101550329@ull.edu.es
 * @date: 18/03/2025
 * @brief: programa principal
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <numeric>
#include <filesystem>
#include "graph.h"
#include "pvc-brute-force.h"
#include "pvc-dynamic.h"
#include "pvc-greedy.h"
#include "pvc-greedy_modi.h"
#include <numeric>

namespace fs = std::filesystem;

std::map<int, std::vector<double>> BruteForce_results;
std::map<int, std::vector<double>> Dynamic_results;
std::map<int, std::vector<double>> Greedy_results;

/**
 * @brief Resuelve una instancia del problema del TSP y escribe los resultados en un archivo
 * @param filepath Ruta del archivo con la instancia del problema
 * @param timeLimit Límite de tiempo en segundos
 * @param mdFile Archivo de salida en formato Markdown
 * @param csvFile Archivo de salida en formato CSV
 */

void solveInstance(const std::string& filepath, int timeLimit, std::ofstream& mdFile, std::ofstream& csvFile) {
  std::cout << "\n--> File: " << filepath << std::endl;
  Graph graph;
  graph.readFromFile(filepath);

  std::vector<std::pair<std::string, PVCAlgorithm*>> solvers = {
    {"Fuerza Bruta", new PVCBruteForce()},
    {"Prog. Dinámica", new PVCDynamic()},
    {"Voraz", new PVCGreedy()},
    {"Voraz Modificado", new PVCGreedyModi()}
  };

  std::string filename = fs::path(filepath).filename();
  mdFile << "\n### " << filename << "\n";
  mdFile << "| Algoritmo | Valor | Tiempo (ms) | Tamaño |\n";
  mdFile << "|-----------|-------|-------------|--------|\n";

  csvFile << filename;

  for (auto& solver : solvers) {
    auto start = std::chrono::high_resolution_clock::now();
    try {
      solver.second->execute(graph); // Intenta resolver el problema
    } catch (const std::runtime_error& e) {
      std::cout << solver.first << " Error: " << e.what() << std::endl;
      mdFile << "| " << solver.first << " | Error: " << e.what() << " | - |\n";
      csvFile << ",Error," << e.what();
      continue; // Continúa con el siguiente solucionador
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;

    std::string result = std::to_string(solver.second->getSolutionCost()) + " | " + std::to_string(elapsed.count());

    // Añadimos el tiempo a la lista correspondiente 
    // Si el número de nodos (first) ya existe, lo añadimos a su lista de tiempos
    // Si no, creamos una nueva entrada
    if (solver.first == "Fuerza Bruta") {
      int nodos = graph.getNumberNodes();
      BruteForce_results[nodos].push_back(elapsed.count());
    } else if (solver.first == "Prog. Dinámica") {
      int nodos = graph.getNumberNodes();
      Dynamic_results[nodos].push_back(elapsed.count());
    } else if (solver.first == "Voraz") {
      int nodos = graph.getNumberNodes();
      Greedy_results[nodos].push_back(elapsed.count());
    } else if (solver.first == "Voraz Modificado") {
      int nodos = graph.getNumberNodes();
      Greedy_results[nodos].push_back(elapsed.count());
    }
      

    std::cout << solver.first << ": ";
    for (auto& city : solver.second->getSolution()) {
      std::cout << city << " ";
    }
    std::cout << "| " << result << std::endl;

    mdFile << "| " << solver.first << " | " << solver.second->getSolutionCost() << " | " << elapsed.count() << "ms" << graph.getNumberNodes() << "|\n";
    csvFile << "," << solver.second->getSolutionCost() << "," << elapsed.count();

    delete solver.second;
  }

  csvFile << "\n";
  
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cout << "Uso: " << argv[0] << " <directorio de instancias>" << std::endl;
    return 1;
  }

  std::string path = argv[1];
  int timeLimit = 300; // 5 minutos expresados en segundos

  std::ofstream mdFile("resultados.md");
  std::ofstream csvFile("resultados.csv");

  mdFile << "# Resultados TSP\n";
  csvFile << "Instancia,Fuerza Bruta Valor,Fuerza Bruta Tiempo (ms),Prog. Dinámica Valor,Prog. Dinámica Tiempo (ms),Voraz Valor,Voraz Tiempo (ms)\n";

  for (const auto& entry : fs::directory_iterator(path)) {
    solveInstance(entry.path().string(), timeLimit, mdFile, csvFile);
  }

  mdFile.close();
  csvFile.close();

  // Mostramos la media de los resultados por número de nodos
  std::cout << "\nMedia de tiempos por número de nodos" << std::endl;
  std::cout << "------------------------------------" << std::endl;
  for (const auto& elem : BruteForce_results) {
    std::cout << "Fuerza Bruta: " << elem.first << " nodos -> " << std::accumulate(elem.second.begin(), elem.second.end(), 0.0) / elem.second.size() << "ms" << std::endl;
  }
  std::cout << "------------------------------------" << std::endl;
  for (const auto& elem : Dynamic_results) {
    std::cout << "Prog. Dinámica: " << elem.first << " nodos -> " << std::accumulate(elem.second.begin(), elem.second.end(), 0.0) / elem.second.size() << "ms" << std::endl;
  }
  std::cout << "------------------------------------" << std::endl;
  for (const auto& elem : Greedy_results) {
    std::cout << "Voraz: " << elem.first << " nodos -> " << std::accumulate(elem.second.begin(), elem.second.end(), 0.0) / elem.second.size() << "ms" << std::endl;
  }
  

  return 0;
}
