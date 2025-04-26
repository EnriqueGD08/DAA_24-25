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
 * @brief: cabecera de la clase Grafo
*/

#pragma once

#include <iostream>
#include <vector>
#include "nodo.h"

class Grafo {
 public:
  Grafo() {}
  Grafo(int velocidad): velocidad_(velocidad) {}
  ~Grafo() {}
  float calcular_coste(int vertice1, int vertice2) {
    return (adyacencias_[vertice1 + 3].first.get_posicion().calcular_distancia(adyacencias_[vertice2 + 3].first.get_posicion()) / velocidad_ * 60);
  }
  float calcular_coste_basura(int vertice1, int vertice2) { return calcular_coste(vertice1, vertice2); }
  float calcular_coste_descarga(int vertice1, int vertice2) { return calcular_coste(vertice1, vertice2); }
  float calcular_coste_deposito(int vertice1, int vertice2) { return calcular_coste(vertice1, vertice2); }

  Nodo obtener_descarga_carcana(Nodo& nodo) { 
    if (calcular_coste(nodo.get_id(), -3) < calcular_coste(nodo.get_id(), -2)) {
      return adyacencias_[0].first;
    } else {
      return adyacencias_[1].first;
    }
   }

  void agregar_adyacencia(const Nodo& nodo) {
    adyacencias_.emplace_back(nodo, 1);
  }

  std::vector<std::pair<Nodo, float>>& get_adyacencias() {
    return adyacencias_;
  }

  void print() const {
    std::cout << "Grafo:" << std::endl;
    for (const auto& adyacencia : adyacencias_) {
      std::cout << "Nodo: " << adyacencia.first.get_id() << ", Peso: " << adyacencia.first.get_peso() << std::endl;
    }
  }

  void set_velocidad(float velocidad) {
    velocidad_ = velocidad;
  }
 
 private:
  std::vector<std::pair<Nodo, float>> adyacencias_;
  float velocidad_;
 };