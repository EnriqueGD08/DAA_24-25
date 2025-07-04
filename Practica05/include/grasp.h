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
 * @brief: cabecera de la clase GRASP
*/

#pragma once

#include "algoritmo.h"

class GRASP : public Algoritmo {
 public:
  GRASP(Problema problema) : Algoritmo(problema) {}
  ~GRASP() {}
  void resolver() override;
  void set_iteraciones_construccion(int iteraciones_construccion) {
    iteraciones_construccion_ = iteraciones_construccion;
  }
  void set_LRC(int lrc) { LRC = lrc; }

 private:
  std::vector<Solucion> soluciones_;
  int iteraciones_construccion_ = 15000;
  int LRC = 3; // Longitud de la lista restringida de candidatos

  void resetear_solucion();
  void construccion();
  void busquedas_locales();
  Solucion busqueda_local1(Solucion& solucion, int indice_subruta);
  Solucion busqueda_local2(Solucion& solucion, int indice_subruta1, int indice_subruta2);
  Solucion busqueda_local3(Solucion& solucion, int indice_ruta);
  Solucion busqueda_local4(Solucion& solucion, int ruta1, int ruta2);
  // Solucion busqueda_local5(Solucion& solucion);
};