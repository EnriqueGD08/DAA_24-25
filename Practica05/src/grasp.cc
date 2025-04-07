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

// void GRASP::resolver() {
//   std::vector<Nodo> nodos_visitados;
//   std::vector<Nodo> nodos_por_visitar = problema_.obtener_nodos();
//   float tiempo_actual = 0;
//   float carga_actual = 0;
//   int subrutas = 0;
//   Nodo nodo_actual = problema_.obtener_deposito();
//   int contador = 0;
//   std::cout << "Nodos por visitar: " << nodos_por_visitar.size() << std::endl;

//   std::random_device rd;
//   std::mt19937 gen(rd());

//   while (!(nodos_por_visitar.size() == 0)) {
//     std::vector<Nodo> candidatos;
//     for (auto& nodo : nodos_por_visitar) {
//       if (puede_visitar(nodo, tiempo_actual, carga_actual) == 1) {
//         candidatos.push_back(nodo);
//       } else if (puede_visitar(nodo, tiempo_actual, carga_actual) == 2) {
//         std::cout << "No se puede visitar el nodo " << nodo.get_id() << " por sobrecarga." << std::endl;
//       } else if (puede_visitar(nodo, tiempo_actual, carga_actual) == 0) {
//         std::cout << "No se puede visitar el nodo " << nodo.get_id() << " por tiempo." << std::endl;
//       }
//     }

//     if (candidatos.empty()) {  // Si no se puede visitar ningún nodo, volvemos al depósito.
//       tiempo_actual += problema_.obtener_grafo().calcular_coste_deposito(nodo_actual.get_id(), problema_.obtener_deposito().get_id());
//       nodo_actual = problema_.obtener_deposito();
//       nodos_visitados.push_back(nodo_actual);
//       carga_actual = 0;
//       tiempo_actual = 0;
//       subrutas++;
//     } else {
//       std::uniform_int_distribution<> distrib(0, candidatos.size() - 1);
//       Nodo nodo_seleccionado = candidatos[distrib(gen)];

//       float coste = problema_.obtener_grafo().calcular_coste(nodo_actual.get_id(), nodo_seleccionado.get_id());
//       tiempo_actual += coste;
//       carga_actual += nodo_seleccionado.get_peso();
//       std::cout << std::endl;
//       std::cout << "Visitando nodo: " << nodo_seleccionado.get_id() << std::endl;
//       std::cout << "Carga actual: " << carga_actual << std::endl;
//       std::cout << std::endl;
//       nodos_visitados.push_back(nodo_seleccionado);
//       nodo_actual = nodo_seleccionado;
//       nodos_por_visitar.erase(std::remove(nodos_por_visitar.begin(), nodos_por_visitar.end(), nodo_seleccionado), nodos_por_visitar.end());
//     }
//   }

//   solucion_.set_nodos(nodos_visitados);
//   solucion_.set_subrutas(subrutas);

//   // finalizar implementación
// }