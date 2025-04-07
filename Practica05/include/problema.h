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
 * @brief: cabecera de la clase Problema
*/

#pragma once

#include "grafo.h"

class Problema {
 public:
  Problema(float tiempo_maximo, float peso_maximo, Grafo grafo, Nodo deposito, float velocidad, Nodo IF, Nodo IF1):
           tiempo_maximo_(tiempo_maximo), peso_maximo_(peso_maximo), grafo_(grafo),
           deposito_(deposito), velocidad_(velocidad), IF_(IF), IF1_(IF1) {grafo_.set_velocidad(velocidad_);}
  ~Problema() {}
  float obtener_tiempo_maximo() const { return tiempo_maximo_; }
  float obtener_peso_maximo() const { return peso_maximo_; }
  Grafo& obtener_grafo() { return grafo_; }
  Nodo obtener_deposito() const { return deposito_; }
  std::vector<Nodo> obtener_nodos() const { return nodos_; }
  Nodo obtener_IF() const { return IF_; }
  Nodo obtener_IF1() const { return IF1_; }
  void agregar_nodo(Nodo nodo) { grafo_.agregar_adyacencia(nodo);
                                nodos_.push_back(nodo); } 

 private:
  float tiempo_maximo_;
  float peso_maximo_;
  float velocidad_;
  Grafo grafo_;
  Nodo deposito_;
  Nodo IF_;
  Nodo IF1_;
  std::vector<Nodo> nodos_;
};
