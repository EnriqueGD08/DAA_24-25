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
 * @brief: implementación de la clase Problema
*/

#include "problema.h"

/**
 * @brief Constructor por defecto de la clase Problema.
 * Inicializa el número de puntos y dimensiones a 0.
 */
Problema::Problema() : numero_puntos_(0), dimensiones_(0) {}

/**
 * @brief Constructor de la clase Problema.
 * Lee los datos de un archivo y los almacena en la clase.
 * @param archivo Archivo de entrada.
 */
Problema::Problema(std::ifstream& archivo) {
  std::string linea;

  std::getline(archivo, linea);
  std::istringstream iss(linea);
  iss >> numero_puntos_;

  std::getline(archivo, linea);
  iss.clear();
  iss.str(linea);
  iss >> dimensiones_;

  if (numero_puntos_ <= 0 || dimensiones_ <= 0) {
    LANZAR_ERROR("Error en el formato del archivo", "El número de puntos o dimensiones es incorrecto");
  }

  while(std::getline(archivo, linea)) {
    std::replace(linea.begin(), linea.end(), ',', '.');

    std::istringstream iss(linea);
    Punto punto;
    for (int i = 0; i < dimensiones_; ++i) {
      double coordenada;
      if (!(iss >> coordenada)) {
        LANZAR_ERROR("Error en el formato del archivo", "Hay menos coordenadas de las esperadas");
      }
      punto.pushCoordenada(coordenada);
    }
    puntos_.push_back(punto);
  }

  if (puntos_.size() != numero_puntos_) {
    LANZAR_ERROR("Error en el formato del archivo", "El número de puntos leídos no coincide con el número esperado");
  }
}

/**
 * @brief Destructor de la clase Problema.
 * Libera la memoria ocupada por los puntos.
 */
Problema::~Problema() {
  puntos_.clear();
  numero_puntos_ = 0;
  dimensiones_ = 0;
}

/**
 * @brief Sobrecarga del operador de salida para imprimir el problema.
 * @param os Flujo de salida.
 * @param problema Problema a imprimir.
 * @return Flujo de salida.
 */
std::ostream& operator<<(std::ostream& os, const Problema& problema) {
  os << "Número de puntos: " << problema.numero_puntos_ << std::endl;
  os << "Dimensiones: " << problema.dimensiones_ << std::endl;
  os << "Puntos:" << std::endl;
  for (const auto& punto : problema.puntos_) {
    os << punto << std::endl;
  }
  return os;
}