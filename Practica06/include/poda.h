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
 * @brief: cabecera de la clase Poda
*/

#pragma once

#include "algoritmo.h"

class Poda : public Algoritmo {
 public:
  Poda(Problema& problema) : Algoritmo(problema) {}
  ~Poda() override = default;

  void resolver() override;
  virtual std::string toCSV() override;

 private:
  void poda();
  void calcularCotaSuperior();
  void calcularCotaInferior();
  double calcularMaximo(const std::vector<Punto>& puntos);
  void crearNodo(std::vector<Punto>& puntos_solucion, 
                 std::vector<Punto>& puntos_restantes);
  int nodos_creados_ = 0;
  double distancia_maxima_ = 0;
  double cota_superior_ = 0;
  double cota_inferior_ = 0;
};