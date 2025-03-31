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
 * @brief: Implementacion de la clase PVCDynamic
*/

#include "pvc-dynamic.h"

/**
 * @brief Método que ejecuta el algoritmo dinámico
 * @param graph Grafo sobre el que se va a ejecutar el algoritmo
 */
void PVCDynamic::execute(Graph& graph) {
  auto start = std::chrono::high_resolution_clock::now(); // Tiempo de inicio

  auto nodos = graph.getNodes();
  int n = nodos.size();
  std::map<std::pair<int, int>, int> memo;
  std::map<std::pair<int, int>, int> parent;

  auto dp = [&](int visited, int last, auto& dp) -> int {
    auto now = std::chrono::high_resolution_clock::now(); // Verificar tiempo actual
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(now - start);
    if (elapsed.count() > TIME_LIMIT) {
      throw std::runtime_error("Tiempo límite excedido");
      return -1; // Tiempo excedido
    }

    if (visited == (1 << n) - 1) {
      return graph.getCost(nodos[last], nodos[0]); // Regreso al inicio
    }
    if (memo.count({visited, last})) return memo[{visited, last}];

    int ans = std::numeric_limits<int>::max();
    for (int next = 0; next < n; ++next) {
      if (visited & (1 << next)) continue; // Si next ya fue visitado

      int coste_actual = graph.getCost(nodos[last], nodos[next]);
      if (coste_actual == -1) continue; // Si no hay conexión

      int nextVisited = visited | (1 << next);
      int temp = dp(nextVisited, next, dp) + coste_actual;

      if (temp < ans) {
        ans = temp;
        parent[{visited, last}] = next;
      }
    }

    return memo[{visited, last}] = ans;
  };

  solution_cost_ = dp(1, 0, dp); // Comenzamos desde el nodo 0 con el ya visitado
  if (solution_cost_ == -1) {
    throw std::runtime_error("Tiempo límite excedido");
  }

  // Reconstruyendo el camino
  int visited = 1, last = 0;
  solution_.clear();
  solution_.push_back(nodos[0]);
  while (visited != (1 << n) - 1 && memo.find({visited, last}) != memo.end()) {
    last = parent[{visited, last}];
    visited |= (1 << last);
    solution_.push_back(nodos[last]);
  }
  if (visited == (1 << n) - 1) {
    solution_.push_back(nodos[0]); // Asegurar que solo añadimos el inicio si se completó el ciclo
  } else {
    throw std::runtime_error("Tiempo límite excedido");
  }
}

/**
 * @brief Método que devuelve la solución del algoritmo
 * @return std::vector<std::string> Vector con las ciudades de la solución
 */
std::vector<std::string> PVCDynamic::getSolution() {
  return solution_;
}

/**
 * @brief Método que devuelve el coste de la solución
 * @return int Coste de la solución
 */
int PVCDynamic::getSolutionCost() {
  return solution_cost_;
}