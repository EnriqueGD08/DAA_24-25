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
 * @brief: implementación de la clase Poda
*/

#include "poda.h"

/**
 * @brief Resuelve el problema de la poda.
 * @return void
 */
void Poda::resolver() {
  auto start = std::chrono::high_resolution_clock::now();
  poda();
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = end - start;
  tiempo_ejecucion_ = elapsed.count();
}

/**
 * @brief Realiza la poda del problema.
 * @return void
 */
void Poda::poda() {
  calcularCotaSuperior();
  calcularCotaInferior();

  std::vector<Punto> puntos_problema = problema_.getPuntos();

  for (const auto& punto : puntos_problema) {
    nodos_creados_++;
    std::vector<Punto> puntos_solucion;
    std::vector<Punto> puntos_restantes = puntos_problema;
    puntos_solucion.push_back(punto);
    puntos_restantes.erase(std::remove(puntos_restantes.begin(), 
                                       puntos_restantes.end(), 
                                       punto), 
                            puntos_restantes.end());
    if (calcularMaximo(puntos_solucion) <= cota_superior_ && calcularMaximo(puntos_solucion) > cota_inferior_) {
      crearNodo(puntos_solucion, puntos_restantes);
    }
  }
}

/**
 * @brief Crea una rama en el árbol de búsqueda.
 * @param puntos_solucion Vector de puntos solución.
 * @return true si se crea la rama, false en caso contrario.
 */
void Poda::crearNodo(std::vector<Punto>& puntos_solucion, 
                     std::vector<Punto>& puntos_restantes) {
  if (puntos_solucion.size() == tamanio_solucion_ - 1) {

    for (const auto& punto : puntos_restantes) {
      nodos_creados_++;
      std::vector<Punto> puntos_solucion_nodo = puntos_solucion;
      puntos_solucion_nodo.push_back(punto);
      Solucion solucion_nodo(puntos_solucion_nodo);
      double valor_objetivo = solucion_nodo.calcularValorObjetivo();
      if (valor_objetivo <= cota_superior_ && 
        valor_objetivo > cota_inferior_) {
        solucion_ = solucion_nodo;
        cota_inferior_ = valor_objetivo;
      }
    }

  } else {
    for (const auto& punto : puntos_restantes) {
      std::vector<Punto> puntos_solucion_nodo = puntos_solucion;
      std::vector<Punto> puntos_restantes_nodo = puntos_restantes;
      puntos_solucion_nodo.push_back(punto);
      puntos_restantes_nodo.erase(std::remove(puntos_restantes_nodo.begin(), 
                                              puntos_restantes_nodo.end(), 
                                              punto), 
                                   puntos_restantes_nodo.end());
      if (calcularMaximo(puntos_solucion_nodo) <= cota_superior_ && calcularMaximo(puntos_solucion_nodo) > cota_inferior_) {
        nodos_creados_++;
        crearNodo(puntos_solucion_nodo, puntos_restantes_nodo);
      }
    }
  }
}

/**
 * @brief Calcula la cota superior del problema.
 * @return void
 */
void Poda::calcularCotaSuperior() {
  cota_superior_ = 0;
  distancia_maxima_ = 0;
  for (int i = 0; i < problema_.getNumeroPuntos() - 1; i++) {
    for (int j = i + 1; j < problema_.getNumeroPuntos(); j++) {
      double distancia = problema_.getPuntos()[i].distancia(problema_.getPuntos()[j]);
      if (distancia > distancia_maxima_) {
        distancia_maxima_ = distancia;
      }
    }
  }
  
  for (int i = 0; i < tamanio_solucion_ - 1; i++) {
    for (int j = i + 1; j < tamanio_solucion_; j++) {
      cota_superior_ += distancia_maxima_;
    }
  }
}

/**
 * @brief Calcula la cota inferior del problema aplicando un algoritmo voraz.
 * @return void
 */
void Poda::calcularCotaInferior() {
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

  solucion_ = Solucion(puntos_solucion);
  cota_inferior_ = solucion_.getValorObjetivo();
}

/**
 * @brief Calcula el máximo de un vector de puntos.
 * @param puntos Vector de puntos.
 * @return El máximo de los puntos.
 */
double Poda::calcularMaximo(const std::vector<Punto>& puntos) {
  double maximo = 0;

  for (size_t i = 0; i < tamanio_solucion_ - 1; ++i) {
    for (size_t j = i + 1; j < tamanio_solucion_; ++j) {
      if (i < puntos.size() && j < puntos.size()) {
        maximo += puntos[i].distancia(puntos[j]);
      } else {
        maximo += distancia_maxima_;
      }
    }
  }
  return maximo;
}


/**
 * @brief Convierte la solución a formato CSV.
 * @return Cadena de texto con la solución en formato CSV.
 */
std::string Poda::toCSV() {
  return std::to_string(problema_.getNumeroPuntos()) + ',' +
         std::to_string(problema_.getDimensiones()) + ',' +
         std::to_string(tamanio_solucion_) + ',' +
         std::to_string(solucion_.getValorObjetivo()) + ',' +
         solucion_.getIndices() + ',' +
         std::to_string(nodos_creados_) + ',' +
         std::to_string(tiempo_ejecucion_);
}