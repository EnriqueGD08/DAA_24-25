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
#include <chrono>

void Voraz::resolver() {
  auto start = std::chrono::high_resolution_clock::now();
  std::vector<Nodo> nodos_visitados;
  std::vector<Nodo> nodos_por_visitar = problema_.obtener_nodos();
  nodos_por_visitar.erase(nodos_por_visitar.begin());
  nodos_por_visitar.erase(nodos_por_visitar.begin());
  nodos_por_visitar.erase(nodos_por_visitar.begin());
  nodos_por_visitar.erase(nodos_por_visitar.begin());

  solucion_.agregar_camion();
  float tiempo_actual = 0;
  float carga_actual = 0;
  int subrutas = 0;
  Nodo nodo_actual = problema_.obtener_deposito();
  nodos_visitados.push_back(nodo_actual);
  while (!(nodos_por_visitar.size() == 0)) {
    float mejor_coste = INFINITO;
    std::sort(nodos_por_visitar.begin(), nodos_por_visitar.end(), 
          [&](const Nodo& a, const Nodo& b) {
          return problema_.obtener_grafo().calcular_coste(nodo_actual.get_id(), a.get_id()) <
                 problema_.obtener_grafo().calcular_coste(nodo_actual.get_id(), b.get_id());
          });
    
    Nodo nodo_destino = nodos_por_visitar[0];
    Nodo nodo_descarga;
    switch (puede_visitar(nodo_actual, nodo_destino, tiempo_actual, carga_actual)) {
    case 0: // Se puede visitar el nodo_actual
      nodo_actual = nodo_destino;
      carga_actual += nodo_actual.get_peso();
      tiempo_actual += problema_.obtener_grafo().calcular_coste(nodo_actual.get_id(), nodo_destino.get_id()) + nodo_destino.get_tiempo();;
      nodos_visitados.push_back(nodo_actual);
      nodos_por_visitar.erase(nodos_por_visitar.begin());
      break;
    
    case 1: // Primero se va a la zona de descarga y luego se va al nodo_actual con carga 0
        nodo_descarga = problema_.obtener_grafo().obtener_descarga_carcana(nodo_actual);
        problema_.agregar_tarea(nodo_descarga.get_id(), tiempo_actual + 
                                                        problema_.obtener_grafo().calcular_coste(nodo_actual.get_id(), 
                                                                                                 nodo_descarga.get_id()),
                                                        carga_actual);
        tiempo_actual += problema_.obtener_grafo().calcular_coste(nodo_actual.get_id(), nodo_descarga.get_id()) +
                        problema_.obtener_grafo().calcular_coste(nodo_descarga.get_id(), nodo_destino.get_id()) +
                        nodo_destino.get_tiempo();
        carga_actual = nodo_destino.get_peso();
        nodos_por_visitar.erase(nodos_por_visitar.begin());
        nodos_visitados.push_back(nodo_descarga);
        nodo_actual = nodo_destino;
        nodos_visitados.push_back(nodo_actual);
        subrutas++;
      break;

    case 2: // Se aumenta el número de camiones y se resetea el tiempo y la carga
      nodo_descarga = problema_.obtener_grafo().obtener_descarga_carcana(nodo_actual);
      problema_.agregar_tarea(nodo_descarga.get_id(), tiempo_actual + 
                                                      problema_.obtener_grafo().calcular_coste(nodo_actual.get_id(), 
                                                                                               nodo_descarga.get_id()),
                                                      carga_actual);
      carga_actual = 0;
      nodo_actual = problema_.obtener_deposito();
      nodos_visitados.push_back(nodo_descarga);
      nodos_visitados.push_back(nodo_actual);
      tiempo_actual = 0;
      solucion_.agregar_camion();
      solucion_.push_nodos(nodos_visitados);
      nodos_visitados = {};
      subrutas++;
      nodos_visitados.push_back(nodo_actual);
      break;

    default: // Error en la funcion puede_visitar al retornar un valor distinto a 0, 1 o 2
      throw std::runtime_error("Error en la función puede_visitar");
    }
  }
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = end - start;
  std::cout << "Tiempo de ejecución fase constructuva: " << elapsed.count() << " segundos" << std::endl;

  solucion_.push_nodos(nodos_visitados);
  solucion_.set_subrutas(subrutas);

  // Calcular las rutas de transporte
  auto start1 = std::chrono::high_resolution_clock::now();
  calcular_rutas_transporte();
  auto end1 = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed1 = end1 - start1;
  std::cout << "Tiempo de ejecución fase de mejora: " << elapsed1.count() << " segundos" << std::endl;
}