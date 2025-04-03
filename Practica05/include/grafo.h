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
    return adyacencias_[vertice1].first.get_posicion().calcular_distancia(adyacencias_[vertice2].first.get_posicion()) * velocidad_;
  }
  float calcular_coste_basura(int vertice1, int vertice2) { return calcular_coste(vertice1, vertice2); }
  float calcular_coste_descarga(int vertice1, int vertice2) { return calcular_coste(vertice1, vertice2); }
  float calcular_coste_deposito(int vertice1, int vertice2) { return calcular_coste(vertice1, vertice2); }

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

  void set_velocidad(int velocidad) {
    velocidad_ = velocidad;
  }
 
 private:
  std::vector<std::pair<Nodo, float>> adyacencias_;
  int velocidad_;
 };