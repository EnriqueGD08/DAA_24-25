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
 * @brief: cabecera de la clase Solucion
*/

#pragma once

#include <vector>
#include "nodo.h"

class Solucion {
 public:
  Solucion() : subrutas_(0) {}
  ~Solucion() {}

  void agregar_camion() { camiones_++; }
  void push_nodos(const std::vector<Nodo>& nodos) {
    nodos_.push_back(nodos);
  }
  void push_nodos_transporte(const int camion, const Nodo& nodos) {
    nodos_transporte_[camion].push_back(nodos);
  }
  void push_camiones_transporte(const std::pair<float, float>& camiones) {
    camiones_transporte_.push_back(camiones);
    nodos_transporte_.push_back({});
  }
  void agregar_tarea(const int indice, const float tiempo, const float peso) {
    camiones_transporte_[indice].first += tiempo;
    camiones_transporte_[indice].second += peso;
  }
  void cambiar_subruta(int subruta, const std::vector<Nodo>& nodos) {
    nodos_[subruta] = nodos;
  }
  bool es_factible(float tiempo, float peso) const;

  void set_nodos(const std::vector<std::vector<Nodo>>& nodos) { nodos_ = {}; nodos_ = nodos; }
  void set_subrutas(int subrutas) { subrutas_ = subrutas; }
  void set_camiones(int camiones) { camiones_ = camiones; }
  void set_peso_transporte(int camion, float peso) { camiones_transporte_[camion].second = peso; }
  void set_tiempo_transporte(int camion, float tiempo) { camiones_transporte_[camion].first = tiempo; }
  const std::vector<std::vector<Nodo>>& get_nodos() const { return nodos_; }
  int get_subrutas() const { return subrutas_; }
  int get_camiones() const { return camiones_; }
  std::vector<std::vector<Nodo>>& get_nodos_transporte() { return nodos_transporte_; }
  const std::vector<std::pair<float, float>>& get_camiones_transporte() const { return camiones_transporte_; }

 
 private:
  std::vector<std::vector<Nodo>> nodos_;
  std::vector<std::vector<Nodo>> nodos_transporte_;
  std::vector<std::pair<float, float>> camiones_transporte_; //tiempo y peso
  int subrutas_;
  int camiones_ = 0;
 };