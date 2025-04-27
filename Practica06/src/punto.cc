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
 * @brief: implementación de la clase punto
*/

#include "punto.h"

/**
 * @brief Constructor por defecto de la clase Punto.
 * Inicializa el número de dimensiones a 0.
 */
Punto::Punto() : dimensiones_(0) {}

/**
 * @brief Constructor de la clase Punto.
 * Inicializa las coordenadas del punto.
 * @param coordenadas Vector de coordenadas del punto.
 */
Punto::Punto(std::vector<double> coordenadas) : dimensiones_(coordenadas.size()) {
  for (double coordenada : coordenadas) {
    coordenadas_.push_back(coordenada);
  }
}

/**
 * @brief Destructor de la clase Punto.
 * Libera la memoria ocupada por las coordenadas.
 */
Punto::~Punto() {
  coordenadas_.clear();
  dimensiones_ = 0;
}

/**
 * @brief Devuelve la coordenada en la posición i.
 * @param i Índice de la coordenada.
 * @return Coordenada en la posición i.
 */
double Punto::getCoordenada(int dimension) const {
  if (dimension < 0 || dimension >= dimensiones_) {
    LANZAR_ERROR("Error en el índice", "El índice está fuera de rango");
  }
  return coordenadas_[dimension];
}

/**
 * @brief Establece la coordenada en la posición i.
 * @param i Índice de la coordenada.
 * @param valor Valor de la coordenada.
 */
void Punto::setCoordenada(int dimension, double valor) {
  if (dimension < 0 || dimension >= dimensiones_) {
    LANZAR_ERROR("Error en el índice", "El índice está fuera de rango");
  }
  coordenadas_[dimension] = valor;
}

/**
 * @brief Devuelve el número de dimensiones del punto.
 * @return Número de dimensiones.
 */
int Punto::getDimensiones() const {
  return dimensiones_;
}

/**
 * @brief Establece el número de dimensiones del punto.
 * @param dimensiones Número de dimensiones.
 */
void Punto::setDimensiones(int dimensiones) {
  if (dimensiones <= 0) {
    LANZAR_ERROR("Error en el número de dimensiones", "El número de dimensiones debe ser mayor que 0");
  }
  dimensiones_ = dimensiones;
  coordenadas_.resize(dimensiones_);
}

/**
 * @brief Calcula la distancia entre dos puntos.
 * @param otro Otro punto.
 * @return Distancia entre los dos puntos.
 */
double Punto::distancia(const Punto& otro) const {
  if (dimensiones_ != otro.dimensiones_) {
    LANZAR_ERROR("Error en las dimensiones", "Los puntos tienen diferentes dimensiones");
  }

  double suma = 0;
  for (int i = 0; i < dimensiones_; ++i) {
    suma += (coordenadas_[i] - otro.coordenadas_[i]) * (coordenadas_[i] - otro.coordenadas_[i]);
  }
  return sqrt(suma);
}

/**
 * @brief Añade una coordenada al punto.
 * @param coordenada Coordenada a añadir.
 */
void Punto::pushCoordenada(double coordenada) {
  coordenadas_.push_back(coordenada);
  ++dimensiones_;
}

/**
 * @brief Sobrecarga del operador de salida para imprimir el punto.
 * @param os Flujo de salida.
 * @param punto Punto a imprimir.
 * @return Flujo de salida.
 */
std::ostream& operator<<(std::ostream& os, const Punto& punto) {
  os << "(";
  for (int i = 0; i < punto.dimensiones_; ++i) {
    os << punto.coordenadas_[i];
    if (i < punto.dimensiones_ - 1) {
      os << ", ";
    }
  }
  os << ")";
  return os;
}