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
 * @brief: implementación de la clase GASP
*/

#include "grasp.h"

#include <random>

void GRASP::resolver() {
  for (int i = 0; i < 1000; i++) {
    resetear_solucion();
    construccion();
    soluciones_.push_back(solucion_);
  }
  busquedas_locales();
}

void GRASP::construccion() {
  std::vector<Nodo> nodos_visitados;
  std::vector<Nodo> nodos_por_visitar = problema_.obtener_nodos();
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

    int indice_aleatorio = 0;
    if (nodos_por_visitar.size() > LRC) {
      indice_aleatorio = std::rand() % LRC;
    } else {
      indice_aleatorio = std::rand() % (nodos_por_visitar.size());
    }
    Nodo nodo_destino = nodos_por_visitar[indice_aleatorio];
    Nodo nodo_descarga;

    switch (puede_visitar(nodo_actual, nodo_destino, tiempo_actual, carga_actual)) {
    case 0: // Se puede visitar el nodo_actual
      nodo_actual = nodo_destino;
      carga_actual += nodo_actual.get_peso();
      tiempo_actual += problema_.obtener_grafo().calcular_coste(nodo_actual.get_id(), nodo_destino.get_id())
                     + nodo_destino.get_tiempo();
      nodos_visitados.push_back(nodo_actual);
      nodos_por_visitar.erase(nodos_por_visitar.begin());
      break;
    case 1: // Primero se va a la zona de descarga y luego se va al nodo_actual con carga 0
        nodo_descarga = problema_.obtener_grafo().obtener_descarga_carcana(nodo_actual);
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
      carga_actual = 0;
      nodo_actual = problema_.obtener_deposito();
      nodos_visitados.push_back(nodo_descarga);
      nodos_visitados.push_back(nodo_actual);
      tiempo_actual = 0;
      solucion_.agregar_camion();
      subrutas++;
      nodos_visitados.push_back(nodo_actual);
      break;
    default: // Error en la funcion puede_visitar al retornar un valor distinto a 0, 1 o 2
      throw std::runtime_error("Error en la función puede_visitar");
    }
  }

  solucion_.set_nodos(nodos_visitados);
  solucion_.set_subrutas(subrutas);
}

void GRASP::busquedas_locales() {
  Solucion mejor_solucion = soluciones_[0];
  for (Solucion solucion : soluciones_) {
    if (solucion.get_subrutas() < mejor_solucion.get_subrutas())
    mejor_solucion = solucion;
  }
  solucion_ = mejor_solucion;
}

Solucion GRASP::busqueda_local1(Solucion& solucion) { // Intercambio de orden entre dos nodos de la misma ruta

}

Solucion GRASP::busqueda_local2(Solucion& solucion) { // Intercambio de entre dos nodos de diferentes rutas

}

Solucion GRASP::busqueda_local3(Solucion& solucion) { //

}

Solucion GRASP::busqueda_local4(Solucion& solucion) { //

}

// Solucion GRASP::busqueda_local5(Solucion& solucion) {}

void GRASP::resetear_solucion() {
  solucion_.set_nodos({});
  solucion_.set_subrutas(0);
  solucion_.set_camiones(0);
}