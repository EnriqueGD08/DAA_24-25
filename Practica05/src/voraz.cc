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
    float mejor_coste = INFINITO;
    std::sort(nodos_por_visitar.begin(), nodos_por_visitar.end(), 
          [&](const Nodo& a, const Nodo& b) {
          return problema_.obtener_grafo().calcular_coste(nodo_actual.get_id(), a.get_id()) <
                 problema_.obtener_grafo().calcular_coste(nodo_actual.get_id(), b.get_id());
          });

    Nodo nodo = nodos_por_visitar[0];
    float coste = problema_.obtener_grafo().calcular_coste(nodo_actual.get_id(), nodo.get_id());
    switch (puede_visitar(nodo, tiempo_actual, carga_actual)) {
    case 0:
      carga_actual += nodo.get_peso();
      tiempo_actual += coste;
      nodos_visitados.push_back(nodo);
      nodo_actual = nodo;
      nodos_visitados.push_back(nodo);
      nodos_por_visitar.erase(std::remove(nodos_por_visitar.begin(), nodos_por_visitar.end(), nodo), nodos_por_visitar.end());
      break;
    case 1:
      // Primero se va a la zona de descarga y luego se va al nodo con carga 0
      break;
    case 2:
      // Se aumenta el número de camiones y se resetea el tiempo y la carga
      break;
    default: // Error en la funcion puede_visitar al retornar un valor distinto a 0, 1 o 2
      throw std::runtime_error("Error en la función puede_visitar");
    }
     if (mejor_coste == INFINITO){
      tiempo_actual += problema_.obtener_grafo().calcular_coste_deposito(nodo_actual.get_id(), problema_.obtener_deposito().get_id());
      nodo_actual = problema_.obtener_deposito();
      nodos_visitados.push_back(nodo_actual);
      carga_actual = 0;
      tiempo_actual = 0;
      solucion_.agregar_camion();
      subrutas++;
    }
  }

  solucion_.set_nodos(nodos_visitados);
  solucion_.set_subrutas(subrutas);
}