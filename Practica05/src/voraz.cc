/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Diseño y Análisis de Algoritmos
 * Curso: 2º
 * Práctica 5
 * @autor: Enrique Gómez Díaz
 * @mail: alu0101550329@ull.edu.es
 * @date: 25/03/2025
 * @brief: implementación de la clase Voraz
*/

#include "voraz.h"

void Voraz::resolver() {
  std::vector<Nodo> nodos_visitados;
  std::vector<Nodo> nodos_por_visitar = problema_.obtener_nodos();
  float tiempo_actual = 0;
  float carga_actual = 0;
  int subrutas = 0;
  Nodo nodo_actual = problema_.obtener_deposito();
  int contador = 0;
  std::cout << "Nodos por visitar: " << nodos_por_visitar.size() << std::endl;
  while (!(nodos_por_visitar.size() == 0)) {
    Nodo mejor_nodo;
    float mejor_coste = INFINITO;
    for (auto& nodo : nodos_por_visitar) {
      float coste = problema_.obtener_grafo().calcular_coste(nodo_actual.get_id(), nodo.get_id());
      if (puede_visitar(nodo, tiempo_actual, carga_actual) == 1) {
        mejor_coste = coste;
        mejor_nodo = nodo;
      } else if (puede_visitar(nodo, tiempo_actual, carga_actual) == 2) {
        std::cout << "No se puede visitar el nodo " << nodo.get_id() << " por sobrecarga." << std::endl;
      } else if (puede_visitar(nodo, tiempo_actual, carga_actual) == 0) {
        std::cout << "No se puede visitar el nodo " << nodo.get_id() << " por tiempo." << std::endl;
      }
    }
    if (mejor_coste == INFINITO) {  // Si no se puede visitar ningún nodo, volvemos al depósito.
      tiempo_actual += problema_.obtener_grafo().calcular_coste_deposito(nodo_actual.get_id(), problema_.obtener_deposito().get_id());
      nodo_actual = problema_.obtener_deposito();
      nodos_visitados.push_back(nodo_actual);
      carga_actual = 0;
      tiempo_actual = 0;
      subrutas++;
    } else {
      tiempo_actual += mejor_coste;
      carga_actual += mejor_nodo.get_peso();
      std::cout << std::endl;
      std::cout << "Visitando nodo: " << mejor_nodo.get_id() << std::endl;
      std::cout << "Carga actual: " << carga_actual << std::endl;
      std::cout << std::endl;
      nodos_visitados.push_back(mejor_nodo);
      nodo_actual = mejor_nodo;
      nodos_por_visitar.erase(std::remove(nodos_por_visitar.begin(), nodos_por_visitar.end(), mejor_nodo), nodos_por_visitar.end());
    }
  }

  solucion_.set_nodos(nodos_visitados);
  solucion_.set_subrutas(subrutas);
}

int Voraz::puede_visitar(Nodo& nodo, float tiempo_actual, float carga_actual) {
  float coste_ida = problema_.obtener_grafo().calcular_coste(problema_.obtener_deposito().get_id(), nodo.get_id());
  float coste_vuelta = problema_.obtener_grafo().calcular_coste_deposito(nodo.get_id(), problema_.obtener_deposito().get_id());
  float tiempo_total = tiempo_actual + coste_ida + nodo.get_peso() + coste_vuelta;
  if ((carga_actual + nodo.get_peso()) >= problema_.obtener_peso_maximo()) {
    return 2;
  }
  return tiempo_total <= problema_.obtener_tiempo_maximo() && (carga_actual + nodo.get_peso()) <= problema_.obtener_peso_maximo();
}