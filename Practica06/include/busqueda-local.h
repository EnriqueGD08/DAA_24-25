/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Diseño y Análisis de Algoritmos
 * Curso: 3º
 * Práctica 6
 * @autor: Enrique Gómez Díaz
 * @mail: alu0101550329@ull.edu.es
 * @date: 06/05/2025
 * @brief: cabecera de la clase BusquedaLocal
*/

#pragma once

#include "algoritmo.h"

class BusquedaLocal : public Algoritmo {
 public:
  BusquedaLocal(Problema& problema) : Algoritmo(problema) {}
  ~BusquedaLocal() override = default;

  int getLRC() const { return LRC_; }
  int getMaxIteraciones() const { return max_iteraciones_; }

  void setLRC(int lrc) { LRC_ = lrc; }
  void setMaxIteraciones(int max_iteraciones) { max_iteraciones_ = max_iteraciones; }

  void resolver() override;
  virtual std::string toCSV() override;

 private:
  std::vector<Solucion> soluciones_ = {};
  int LRC_ = 3;
  int max_iteraciones_ = 10;
  void construccion(std::vector<Punto>& puntos_restantes);
  void busquedaLocal(std::vector<Punto>& puntos_restantes);
};