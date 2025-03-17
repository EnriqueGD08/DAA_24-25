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

  auto cities = graph.getNodes();
  std::set<std::string> nodos_no_visitados(cities.begin(), cities.end());

  if (cities.empty()) return; // Si no hay ciudades, no hay solución.

  std::string nodo_actual = cities[0];
  std::string originCity = nodo_actual;
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

    int nearestDistance = std::numeric_limits<int>::max();
    std::string ciudad_cercana;

    for (int i = 0; i < cities.size(); ++i) {
      if (nodos_no_visitados.find(cities[i]) != nodos_no_visitados.end()) {
      int distance = graph.getCost(nodo_actual, cities[i]);
      if (distance < nearestDistance) {
        ciudad_cercana = cities[i];
        nearestDistance = distance;
      }
      }
    }

    if (nearestDistance < std::numeric_limits<int>::max()) {
      nodo_actual = ciudad_cercana;
      nodos_no_visitados.erase(ciudad_cercana);
      solution_.push_back(ciudad_cercana);
      solution_cost_ += nearestDistance;
    } else {
      // Si no se encuentra una ciudad más cercana, rompe el ciclo.
      break;
    }
  }

  // Después de visitar todas las ciudades, vuelve a la ciudad de origen.
  int returnDistance = graph.getCost(nodo_actual, originCity);
  if (returnDistance != -1) {
    solution_.push_back(originCity);
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