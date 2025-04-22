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

struct Tareas {
  Nodo Zona_descarga;
  float tiempo;
  float peso;
};

class Problema {
 public:
  Problema(float tiempo_maximo, float peso_maximo, Grafo grafo, Nodo deposito, float velocidad,
           Nodo IF, Nodo IF1, float peso_maximo_transporte, Nodo vertedero, float offset):
           tiempo_maximo_(tiempo_maximo), peso_maximo_(peso_maximo), grafo_(grafo),
           deposito_(deposito), velocidad_(velocidad), IF_(IF), IF1_(IF1),
           peso_maximo_transporte_(peso_maximo_transporte), offset_(offset) {grafo_.set_velocidad(velocidad_);}
  ~Problema() {}
  
  void agregar_nodo(Nodo nodo) { grafo_.agregar_adyacencia(nodo);
                                nodos_.push_back(nodo); }

  float obtener_tiempo_maximo() const { return tiempo_maximo_; }
  float obtener_peso_maximo() const { return peso_maximo_; }
  float obtener_peso_maximo_transporte() const { return peso_maximo_transporte_; }
  Grafo& obtener_grafo() { return grafo_; }
  Nodo obtener_deposito() const { return deposito_; }
  std::vector<Nodo> obtener_nodos() const { return nodos_; }
  Nodo obtener_IF() const { return IF_; }
  Nodo obtener_IF1() const { return IF1_; }
  Nodo obtener_vertedero() const { return vertedero_; }
  void agregar_tarea(const Nodo& zona_descarga, float tiempo, float peso) {
    Tareas tarea;
    tarea.Zona_descarga = zona_descarga;
    tarea.tiempo = tiempo;
    tarea.peso = peso;
    tareas_.push_back(tarea);
  }
  std::vector<Tareas> obtener_tareas() const { return tareas_; }
  void reset_tareas() { tareas_.clear(); }

 private:
  float tiempo_maximo_;
  float peso_maximo_;
  float peso_maximo_transporte_;
  float velocidad_;
  float offset_;
  Grafo grafo_;
  Nodo deposito_;
  Nodo IF_;
  Nodo IF1_;
  Nodo vertedero_;
  std::vector<Nodo> nodos_;
  std::vector<Tareas> tareas_;

};
