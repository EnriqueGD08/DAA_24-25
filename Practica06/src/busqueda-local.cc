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
 * @brief: implementación de la clase BusquedaLocal
*/

#include "busqueda-local.h"

/**
 * @brief Resuelve el problema utilizando el algoritmo de búsqueda local.
 * @return void
 */
void BusquedaLocal::resolver() {
  auto start = std::chrono::high_resolution_clock::now();
  Solucion mejor_solucion;

  for (int i = 0; i < max_iteraciones_; ++i) {
    std::vector<Punto> puntos_restantes = problema_.getPuntos();
    construccion(puntos_restantes);
    busquedaLocal(puntos_restantes);
    if (solucion_.getValorObjetivo() > mejor_solucion.getValorObjetivo()) {
      mejor_solucion = solucion_;
    }
    solucion_.clear();
  }
  solucion_ = mejor_solucion;

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = end - start;
  tiempo_ejecucion_ = elapsed.count();
}

/**
 * @brief Construye la solución inicial utilizando el algoritmo GRASP.
 * @return void
 */
void BusquedaLocal::construccion(std::vector<Punto>& puntos_restantes) {
  std::vector<Punto> puntos_solucion;
  puntos_restantes = problema_.getPuntos();

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
 * @brief Realiza la búsqueda local para mejorar la solución inicial.
 * @return void
 */
void BusquedaLocal::busquedaLocal(std::vector<Punto>& puntos_restantes) {
  std::vector<Punto> puntos_solucion = solucion_.getPuntos();
  double mejor_valor_objetivo = solucion_.getValorObjetivo();

  for (size_t i = 0; i < puntos_solucion.size(); ++i) {
    size_t mejor_indice = -1;

    for (size_t j = 0; j < puntos_restantes.size(); ++j) {
      // Intercambiar el punto de la solución con el punto restante
      Punto punto_intercambiado = puntos_solucion[i];
      puntos_solucion[i] = puntos_restantes[j];

      Solucion nueva_solucion(puntos_solucion);
      nueva_solucion.calcularValorObjetivo();

      if (nueva_solucion.getValorObjetivo() > mejor_valor_objetivo) {
        mejor_valor_objetivo = nueva_solucion.getValorObjetivo();
        mejor_indice = j;
      }

      // Revertir el cambio
      puntos_solucion[i] = punto_intercambiado;
    }

    // Si se encontró una mejora, realizar el intercambio
    if (mejor_indice != -1) {
      Punto punto_intercambiado = puntos_solucion[i];
      puntos_solucion[i] = puntos_restantes[mejor_indice];
      puntos_restantes[mejor_indice] = punto_intercambiado;

      solucion_.setPuntos(puntos_solucion);
      solucion_.calcularValorObjetivo();
    }
  }
}

/**
 * @brief Genera un archivo CSV con los resultados de la solución.
 * @return void
 */
std::string BusquedaLocal::toCSV() {
  return std::to_string(problema_.getNumeroPuntos()) + ',' + std::to_string(problema_.getDimensiones()) + ',' +
         std::to_string(tamanio_solucion_) + ',' + std::to_string(LRC_) + ',' +
         std::to_string(solucion_.getValorObjetivo()) + ',' + std::to_string(max_iteraciones_) + ',' +
         solucion_.toString() + ',' + std::to_string(tiempo_ejecucion_);
}