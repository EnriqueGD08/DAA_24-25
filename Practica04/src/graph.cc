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
 * @brief: Implementación de la clase Graph
*/

#include "graph.h"

/**
 * @brief Constructor por defecto de la clase Graph
*/
Graph::Graph() {}

/**
 * @brief Genera un grafo aleatorio
 * @param number_nodes Número de nodos del grafo
*/
void Graph::generateRandomGraph(int number_nodes) {
  number_nodes_ = number_nodes;
  srand(time(NULL));

  for (int inicio = 0; inicio < number_nodes; ++inicio) {
    for (int final = 0; final < number_nodes; ++final) {
      int cost = rand() % 100 + 1;
      // importante para que sea fácil de implementar el grafo no dirigido
      adjacency_list_[std::to_string(inicio)][std::to_string(final)] = cost;
      adjacency_list_[std::to_string(final)][std::to_string(inicio)] = cost;
    }
  }
}

/**
 * @brief Escribe un grafo aleatorio en un fichero
 * @param number_nodes Número de nodos del grafo
 * @param file_name Nombre del fichero
*/
void Graph::writeRandomGraph(int number_nodes, const std::string& file_name) {
  generateRandomGraph(number_nodes);
  saveFile(file_name);
}

/**
 * @brief Devuelve los nodos del grafo
 * @return std::vector<std::string> Nodos del grafo
*/
std::vector<std::string> Graph::getNodes() {
  std::vector<std::string> nodes;
  for (auto& node : adjacency_list_) {
    nodes.push_back(node.first);
  }
  return nodes;
}

/**
 * @brief Devuelve el número de nodos del grafo
 * @return int Número de nodos del grafo
*/
int Graph::getNumberNodes() {
  return number_nodes_;
}

/**
 * @brief Devuelve el coste entre dos nodos
 * @param node1 Nodo 1
 * @param node2 Nodo 2
 * @return int Coste entre los nodos
*/
int Graph::getCost(std::string& node1, std::string& node2) {
  return adjacency_list_[node1][node2];
}

/**
 * @brief Lee un grafo desde un fichero
 * @param file_name Nombre del fichero
*/
void Graph::readFromFile(const std::string& file_name) {
  std::ifstream file(file_name);
  std::string line;
  std::string node1, node2;
  int cost;
  int number_nodes;

  file >> number_nodes;
  number_nodes_ = number_nodes;

  while (file >> node1 >> node2 >> cost) {
    adjacency_list_[node1][node2] = cost;
    adjacency_list_[node2][node1] = cost;
  }

  file.close();
}

/**
 * @brief Guarda un grafo en un fichero
 * @param file_name Nombre del fichero
*/
void Graph::saveFile(const std::string& file_name) {
  std::ofstream file(file_name);
  file << number_nodes_ << std::endl;

  for (auto& inicio : adjacency_list_) {
    for (auto& destino : inicio.second) {
      file << inicio.first << " " << destino.first << " " << destino.second << std::endl;
    }
  }

  file.close();
}

/**
 * @brief Sobrecarga del operador <<
 * @param os Flujo de salida
 * @param graph Grafo
 * @return std::ostream& Flujo de salida
*/
std::ostream& operator<<(std::ostream& os, Graph& graph) {
  for (auto& inicio : graph.adjacency_list_) {
    for (auto& destino : inicio.second) {
      os << inicio.first << " " << destino.first << " " << destino.second << std::endl;
    }
  }
  return os;
}