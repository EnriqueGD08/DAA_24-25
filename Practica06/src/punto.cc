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
Punto::Punto() {}

/**
 * @brief Constructor de la clase Punto.
 * Inicializa las coordenadas del punto.
 * @param coordenadas Vector de coordenadas del punto.
 */
Punto::Punto(std::vector<double> coordenadas){
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
}

/**
 * @brief Devuelve la coordenada en la posición i.
 * @param i Índice de la coordenada.
 * @return Coordenada en la posición i.
 */
double Punto::getCoordenada(int dimension) const {
  if (dimension < 0 || dimension >= coordenadas_.size()) {
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
  if (dimension < 0 || dimension >= coordenadas_.size()) {
    LANZAR_ERROR("Error en el índice", "El índice está fuera de rango");
  }
  coordenadas_[dimension] = valor;
}

/**
 * @brief Devuelve el número de dimensiones del punto.
 * @return Número de dimensiones.
 */
int Punto::getDimensiones() const {
  return coordenadas_.size();
}

/**
 * @brief Calcula la distancia entre dos puntos.
 * @param otro Otro punto.
 * @return Distancia entre los dos puntos.
 */
double Punto::distancia(const Punto& otro) const {
  if (coordenadas_.size() != otro.coordenadas_.size()) {
    LANZAR_ERROR("Error en las dimensiones", "Los puntos tienen diferentes dimensiones " + std::to_string(coordenadas_.size()) + " y " + std::to_string(otro.coordenadas_.size()));
  }

  double suma = 0;
  for (int i = 0; i < coordenadas_.size(); ++i) {
    suma += (coordenadas_[i] - otro.coordenadas_[i]) * (coordenadas_[i] - otro.coordenadas_[i]);
  }
  return sqrt(suma);
}

double Punto::distancia(const std::vector<Punto>& puntos) const {
  double distancia_minima = distancia(puntos[0]);
  for (const Punto& punto : puntos) {
    double distancia_actual = distancia(punto);
    if (distancia_actual < distancia_minima) {
      distancia_minima = distancia_actual;
    }
  }
  return distancia_minima;
}


/**
 * @brief Añade una coordenada al punto.
 * @param coordenada Coordenada a añadir.
 */
void Punto::pushCoordenada(double coordenada) {
  coordenadas_.push_back(coordenada);
}

/**
 * @brief Devuelve una representación en cadena del punto.
 * @return Representación en cadena del punto.
 */
std::string Punto::toString() const {
  std::string resultado = "(";
  for (size_t i = 0; i < coordenadas_.size(); ++i) {
    resultado += std::to_string(coordenadas_[i]);
    if (i < coordenadas_.size() - 1) {
      resultado += " | ";
    }
  }
  resultado += ")";
  return resultado;
}

/**
 * @brief Sobrecarga del operador de salida para imprimir el punto.
 * @param os Flujo de salida.
 * @param punto Punto a imprimir.
 * @return Flujo de salida.
 */
std::ostream& operator<<(std::ostream& os, const Punto& punto) {
  os << "(";
  for (int i = 0; i < punto.coordenadas_.size(); ++i) {
    os << punto.coordenadas_[i];
    if (i < punto.coordenadas_.size() - 1) {
      os << " | ";
    }
  }
  os << ")";
  return os;
}

/**
 * @brief Sobrecarga del operador de igualdad para comparar puntos.
 * @param otro Otro punto.
 * @return true si los puntos son iguales, false en caso contrario.
 */
bool Punto::operator==(const Punto& otro) const {
  if (coordenadas_.size() != otro.coordenadas_.size()) {
    return false;
  }
  for (int i = 0; i < coordenadas_.size(); ++i) {
    if (coordenadas_[i] != otro.coordenadas_[i]) {
      return false;
    }
  }
  return true;
}