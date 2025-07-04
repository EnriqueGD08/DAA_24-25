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
 * @brief: Implementacion de la clase PVCGreedy
*/

#include "pvc-greedy.h"

/**
 * @brief Método que ejecuta el algoritmo greedy
 * @param graph Grafo sobre el que se va a ejecutar el algoritmo
 */
void PVCGreedy::execute(Graph& graph) {
  auto start = std::chrono::high_resolution_clock::now();

  auto nodes = graph.getNodes();
  std::set<std::string> nodos_no_visitados(nodes.begin(), nodes.end());

  if (nodes.empty()) return; // Si no hay ciudades, no hay solución.

  std::string nodo_actual = nodes[0];
  std::string nodo_origen = nodo_actual;
  nodos_no_visitados.erase(nodo_actual);
  solution_.clear();
  solution_.push_back(nodo_actual);

  solution_cost_ = 0;

  while (!nodos_no_visitados.empty()) {
    auto now = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(now - start);
    if (elapsed.count() > TIME_LIMIT) {
      throw std::runtime_error("Tiempo límite excedido");
      return; // Sale del método si se supera el tiempo límite.
    }

    int costes_cercanos = std::numeric_limits<int>::max();
    std::string nodos_cercanos;

    for (int i = 0; i < nodes.size(); ++i) {
      if (nodos_no_visitados.find(nodes[i]) != nodos_no_visitados.end()) {
      int distance = graph.getCost(nodo_actual, nodes[i]);
      if (distance < costes_cercanos) {
        nodos_cercanos = nodes[i];
        costes_cercanos = distance;
      }
      }
    }

    if (costes_cercanos < std::numeric_limits<int>::max()) {
      nodo_actual = nodos_cercanos;
      nodos_no_visitados.erase(nodos_cercanos);
      solution_.push_back(nodos_cercanos);
      solution_cost_ += costes_cercanos;
    } else {
      // Si no se encuentra una ciudad más cercana, rompe el ciclo.
      break;
    }
  }

  // Después de visitar todas las ciudades, vuelve a la ciudad de origen.
  int returnDistance = graph.getCost(nodo_actual, nodo_origen);
  if (returnDistance != -1) {
    solution_.push_back(nodo_origen);
    solution_cost_ += returnDistance;
  }
}

/**
 * @brief Método que devuelve la solución del algoritmo
 * @return std::vector<std::string> Vector con las ciudades de la solución
 */
std::vector<std::string> PVCGreedy::getSolution() {
  return solution_;
}

/**
 * @brief Método que devuelve el coste de la solución
 * @return int Coste de la solución
 */
int PVCGreedy::getSolutionCost() {
  return solution_cost_;
}