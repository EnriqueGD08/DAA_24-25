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
 * @brief: Cabecera de la clase Graph
*/

#pragma once

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

class Graph {
 public:
  Graph();
  void generateRandomGraph(int number_nodes);
  void writeRandomGraph(int number_nodes, const std::string& file_name);

  std::vector<std::string> getNodes();
  int getNumberNodes();
  int getCost(std::string& node1, std::string& node2);
  
  void readFromFile(const std::string& file_name);
  void saveFile(const std::string& file_name);

  friend std::ostream& operator<<(std::ostream& os, Graph& graph);

 private:
  std::map<std::string, std::map<std::string, int>> adjacency_list_;
  int number_nodes_;

};
