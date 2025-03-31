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
#include "pvc-greedy_modi.h"
#include "pvc-dynamic.h"
#include "pvc-greedy.h"
#include <numeric>

/*
template <typename PVC>
std::pair<std::string, std::chrono::microseconds> runSolver(Graph& graph) {
  PVC solver;
  std::chrono::microseconds duration;
  try {
    auto start = std::chrono::high_resolution_clock::now();
    solver.execute(graph);
    auto end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  } catch (const std::runtime_error& e) {
    // duration será el TIME_LIMIT
    std::chrono::microseconds timeLimit(TIME_LIMIT);
    return {"EXCESIVO", timeLimit};
  }
  return {solver.getSolution().size() > 0 ? "OK" : "FALLO", duration};
}

int main() {
  std::ofstream csvFile("tiempos.csv"), mdFile("tiempos.md");
  csvFile << "Tamaño de la instancia, Tiempo de Brute Force, Tiempo de Greedy, Tiempo de Dynamic, Tiempo Modi\n";
  mdFile << "| Tamaño de la instancia | Tiempo de Brute Force | Tiempo de Greedy | Tiempo de Dynamic | Tiempo Modi\n";
  mdFile << "|------------------------|-----------------------|------------------|-------------------|------------\n";

  for (int n = 2; n <= 10; ++n) {
    std::cout << "Ejecutando para n = " << n << std::endl;
    Graph graph;
    graph.generateRandomGraph(n); // Usa esta función para generar el grafo en memoria
    
    auto [bfStatus, bfTime] = runSolver<PVCBruteForce>(graph);
    std::cout << "Brute Force: " << bfStatus << " en " << bfTime.count() << " ms" << std::endl;
    auto [greedyStatus, greedyTime] = runSolver<PVCGreedy>(graph);
    std::cout << "Greedy: " << greedyStatus << " en " << greedyTime.count() << " ms" << std::endl;
    auto [dynamicStatus, dynamicTime] = runSolver<PVCDynamic>(graph);
    std::cout << "Dynamic: " << dynamicStatus << " en " << dynamicTime.count() << " ms" << std::endl;
    auto [greedyModiStatus, greedyModiTime] = runSolver<PVCGreedyModi>(graph);
    std::cout << "GreedyModi: " << greedyModiStatus << " en " << greedyModiTime.count() << " ms" << std::endl;

    csvFile << n << ", " << (bfStatus == "EXCESIVO" ? "EXCESIVO" : std::to_string(bfTime.count())) << ", "
            << (greedyStatus == "EXCESIVO" ? "EXCESIVO" : std::to_string(greedyTime.count())) << ", "
            << (dynamicStatus == "EXCESIVO" ? "EXCESIVO" : std::to_string(dynamicTime.count())) << ", "
            << (greedyModiStatus == "EXCESIVO" ? "EXCESIVO" : std::to_string(greedyModiTime.count())) << "\n";

    mdFile << "| " << n << " | " << (bfStatus == "EXCESIVO" ? "EXCESIVO" : std::to_string(bfTime.count())) << " ms | "
            << (greedyStatus == "EXCESIVO" ? "EXCESIVO" : std::to_string(greedyTime.count())) << " ms | "
            << (dynamicStatus == "EXCESIVO" ? "EXCESIVO" : std::to_string(dynamicTime.count())) << " ms | "
            << (greedyModiStatus == "EXCESIVO" ? "EXCESIVO" : std::to_string(greedyModiTime.count())) << " ms |\n";
  }

  csvFile.close();
  mdFile.close();
  return 0;
}
*/