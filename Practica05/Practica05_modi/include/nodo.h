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
 * @brief: cabecera de la clase Nodo
*/

#pragma once

#include "posicion.h"

class Nodo {
 public:
  Nodo(int id = 0, Posicion posicion = Posicion(), float peso = 0, int tiempo = 0)
      : identificador_(id), posicion_(posicion), peso_(peso), tiempo_(tiempo) {}
  ~Nodo() {}
  float get_id() const { return identificador_; }
  float get_peso() const { return peso_; }
  Posicion get_posicion() const { return posicion_; }
	float get_tiempo() const { return tiempo_; }

  bool operator==(const Nodo& otro) const { return identificador_ == otro.identificador_; }

 private:
  Posicion posicion_;
  float peso_;
  float tiempo_;
  int identificador_;
 };