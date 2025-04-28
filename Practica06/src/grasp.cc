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
 * @brief: implementación de la clase GRASP
*/

#include "grasp.h"

/**
 * @brief Resuelve el problema utilizando el algoritmo GRASP.
 * @return void
 */
void GRASP::resolver() {
  auto start = std::chrono::high_resolution_clock::now();

  construccion();

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = end - start;
  tiempo_ejecucion_ = elapsed.count();
}

/**
 * @brief Construye la solución inicial utilizando el algoritmo GRASP.
 * @return void
 */
void GRASP::construccion() {
  std::vector<Punto> puntos_solucion;
  std::vector<Punto> puntos_restantes = problema_.getPuntos();

  Punto centro_gravedad = centroGravedad(puntos_restantes);
  double distancia_maxima = 0;
  int indice_punto_mas_alejado = 0;
  while (puntos_solucion.size() < tamanio_solucion_) {
    indice_punto_mas_alejado = 0;
    distancia_maxima = 0;
    std::sort(puntos_restantes.begin(), puntos_restantes.end(),
              [centro_gravedad](const Punto& a, const Punto& b) {
                return centro_gravedad.distancia(a) > centro_gravedad.distancia(b);
              });
    if (LRC_ > puntos_restantes.size()) {
      std::srand(std::chrono::system_clock::now().time_since_epoch().count());
      indice_punto_mas_alejado = std::rand() % puntos_restantes.size();
        } else {
      std::srand(std::chrono::system_clock::now().time_since_epoch().count());
      indice_punto_mas_alejado = std::rand() % LRC_;
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
std::string GRASP::toCSV() {
  return std::to_string(problema_.getNumeroPuntos()) + ',' + std::to_string(problema_.getDimensiones()) + ',' +
         std::to_string(tamanio_solucion_) + ',' + std::to_string(LRC_) + ',' +
         std::to_string(solucion_.getValorObjetivo()) + ',' + solucion_.toString() + ',' +
         std::to_string(tiempo_ejecucion_);
  std::cout << problema_.getNumeroPuntos() << ',' << problema_.getDimensiones() << ',' << tamanio_solucion_ 
            << ',' << LRC_ << ',' << solucion_.getValorObjetivo() << ',' << solucion_.toString() << ','
            << tiempo_ejecucion_;
}