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
 * @brief: Implementación de la clase PVCBruteForce
*/

#include "pvc-brute-force.h"

/**
 * @brief Método que ejecuta el algoritmo de fuerza bruta
 * @param graph Grafo sobre el que se va a ejecutar el algoritmo
 */
void PVCBruteForce::execute(Graph& graph) {
  auto start = std::chrono::high_resolution_clock::now(); // Iniciar temporizador

  std::vector<std::string> nodes = graph.getNodes();
  std::vector<std::string> bestPath;
  int minPathcoste = std::numeric_limits<int>::max();

  std::sort(nodes.begin(), nodes.end());

  do {
    auto now = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(now - start);
    // std::cout << "Tiempo transcurrido: " << elapsed.count() << " ms" << std::endl;
    // std::cout << "Mejor distancia: " << TIME_LIMIT << std::endl;
    if (elapsed.count() > TIME_LIMIT) {
      throw std::runtime_error("Tiempo límite excedido");
      return;
    }

    int coste_actual = 0;
    bool validPath = true;
    for (size_t i = 0; i < nodes.size() - 1; ++i) {
      int coste = graph.getCost(nodes[i], nodes[i + 1]);
      if (coste == -1) { // No hay camino posible
        validPath = false;
        break;
      }
      coste_actual += coste;
    }

    // Distancia al punto de inicio
    if (validPath) {
      int return_coste = graph.getCost(nodes.back(), nodes.front());
      if (return_coste != -1) {
        coste_actual += return_coste;
        if (coste_actual < minPathcoste) {
          minPathcoste = coste_actual;
          bestPath = nodes;
        }
      }
    }
  } while (std::next_permutation(nodes.begin(), nodes.end()));

  if (minPathcoste != std::numeric_limits<int>::max()) {
    solution_ = bestPath;
    solution_cost_ = minPathcoste;
  } else {
    throw std::runtime_error("Tiempo límite excedido");
    return;
  }
}

/**
 * @brief Método que devuelve la solución del algoritmo
 * @return std::vector<std::string> Vector con las ciudades de la solución
 */
std::vector<std::string> PVCBruteForce::getSolution() {
  return solution_;
}

/**
 * @brief Método que devuelve el coste de la solución
 * @return int Coste de la solución
 */
int PVCBruteForce::getSolutionCost() {
  return solution_cost_;
}