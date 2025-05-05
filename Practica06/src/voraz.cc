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
 * @brief: implementación de la clase voraz
*/

#include "voraz.h"

/**
 * @brief Resuelve el problema utilizando el algoritmo voraz.
 * @return void
 */
void Voraz::resolver() {
  auto start = std::chrono::high_resolution_clock::now();

  construccion();
  
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = end - start;
  tiempo_ejecucion_ = elapsed.count();
}

/**
 * @brief Construye la solución inicial utilizando el algoritmo voraz.
 * @return void
 */
void Voraz::construccion() {
  std::vector<Punto> puntos_solucion;
  std::vector<Punto> puntos_restantes = problema_.getPuntos();

  Punto centro_gravedad = centroGravedad(puntos_restantes);
  double distancia_maxima = 0;
  int indice_punto_mas_alejado = 0;
  while (puntos_solucion.size() < tamanio_solucion_) {
    indice_punto_mas_alejado = 0;
    distancia_maxima = 0;
    for (size_t i = 0; i < puntos_restantes.size(); ++i) {
      double distancia_actual = centro_gravedad.distancia(puntos_restantes[i]);
      if (distancia_actual > distancia_maxima) {
        distancia_maxima = distancia_actual;
        indice_punto_mas_alejado = i;
      }
    }
    puntos_solucion.push_back(puntos_restantes[indice_punto_mas_alejado]);
    puntos_restantes.erase(puntos_restantes.begin() + indice_punto_mas_alejado);
    centro_gravedad = centroGravedad(puntos_solucion);
  }

  solucion_.setPuntos(puntos_solucion);
  solucion_.calcularValorObjetivo();
}

/**
 * @brief Genera un archivo CSV con los resultados de la solución.
 * @return void
 */
std::string Voraz::toCSV() {
  return std::to_string(problema_.getNumeroPuntos()) + ',' +
         std::to_string(problema_.getDimensiones()) + ',' +
         std::to_string(tamanio_solucion_) + ',' +
         std::to_string(solucion_.getValorObjetivo()) + ',' +
         solucion_.getIndices() + ',' +
         std::to_string(tiempo_ejecucion_);
}