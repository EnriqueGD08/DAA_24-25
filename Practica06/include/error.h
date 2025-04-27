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
 * @brief: cabecera de la clase Error
*/

#pragma once
#include <string>
#include <iostream>

#define LANZAR_ERROR(mensaje, detalles) \
  throw Error(mensaje, detalles, std::string(__FILE__) + ":" + std::to_string(__LINE__) + " (" + __FUNCTION__ + ")")

class Error : public std::exception {
 public:
  Error(const std::string& mensaje,
        const std::string& detalles = "",
        const std::string& lugar = "")
      : mensaje_(mensaje), detalles_(detalles), lugar_(lugar)
  {
      mensajeCompleto_ = "[ERROR] " + mensaje_;
      if (!detalles_.empty()) {
        mensajeCompleto_ += "\nDetalles: " + detalles_;
      }
      if (!lugar_.empty()) {
        mensajeCompleto_ += "\nLugar: " + lugar_;
      }
  }

  const char* what() const noexcept override {
    return mensajeCompleto_.c_str();
  }

  std::string mensaje() const { return mensaje_; }
  std::string detalles() const { return detalles_; }
  std::string lugar() const { return lugar_; }

 private:
  std::string mensaje_;
  std::string detalles_;
  std::string lugar_;
  std::string mensajeCompleto_;
};