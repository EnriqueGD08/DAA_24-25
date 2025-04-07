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
 * @brief: implementación de la clase Algoritmo
*/

#include "algoritmo.h"

/**
 * @brief función que devuelve si se puede visitar un nodo o no
 * @param nodo nodo a visitar
 * @param tiempo_actual tiempo actual
 * @param carga_actual carga actual
 * @return 0 si se puede visitar, 1 si no se puede visitar por carga, 2 si no se puede visitar por tiempo
 */
int Algoritmo::puede_visitar(Nodo& nodo_actual, Nodo& nodo_destino, float tiempo_actual, float carga_actual) {
  float tiempo_total = tiempo_actual + problema_.obtener_grafo().calcular_coste(nodo_actual.get_id(), nodo_destino.get_id()) +
                       problema_.obtener_grafo().calcular_coste(nodo_destino.get_id(), problema_.obtener_IF().get_id()) +
                       problema_.obtener_grafo().calcular_coste(problema_.obtener_IF().get_id(), problema_.obtener_deposito().get_id()) +
                       nodo_destino.get_tiempo();
                      
  if (tiempo_total > problema_.obtener_tiempo_maximo()) {
    return 2; // No se puede visitar por el tiempo
  }
  if ((carga_actual + nodo_destino.get_peso()) > problema_.obtener_peso_maximo()) {
    return 1; // No se puede visitar por la carga
  }
  return 0; // Se puede visitar
}