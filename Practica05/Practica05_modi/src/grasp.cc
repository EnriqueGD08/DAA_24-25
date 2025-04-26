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
 * @brief: implementación de la clase GASP
*/

#include "grasp.h"

#include <random>
#include <chrono>

/**
 * @brief Resuelve el problema utilizando el algoritmo GRASP.
 * @return void
 */
void GRASP::resolver() {
  auto start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < iteraciones_construccion_; i++) {
    resetear_solucion();
    construccion();
    soluciones_.push_back(solucion_);
  }
  busquedas_locales();
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = end - start;
  std::cout << "Tiempo de ejecución fase recolección: " << elapsed.count() << " segundos" << std::endl;
  auto start2 = std::chrono::high_resolution_clock::now();
  problema_.reset_tareas();
  set_tareas();
  calcular_rutas_transporte();
  auto end2 = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed2 = end2 - start2;
  std::cout << "Tiempo de ejecución fase transporte: " << elapsed2.count() << " segundos" << std::endl;
}

/**
 * @brief construcción de la solución inicial.
 * @return void
 * @details Se construye una solución inicial utilizando un algoritmo voraz.
 */
void GRASP::construccion() {
  std::vector<Nodo> nodos_visitados;
  std::vector<Nodo> nodos_por_visitar = problema_.obtener_nodos();
  nodos_por_visitar.erase(nodos_por_visitar.begin());
  nodos_por_visitar.erase(nodos_por_visitar.begin());
  nodos_por_visitar.erase(nodos_por_visitar.begin());
  nodos_por_visitar.erase(nodos_por_visitar.begin());

  solucion_.agregar_camion();
  float tiempo_actual = 0;
  float carga_actual = 0;
  int subrutas = 0;
  Nodo nodo_actual = problema_.obtener_deposito();
  nodos_visitados.push_back(nodo_actual);
  while (!(nodos_por_visitar.size() == 0)) {
    float mejor_coste = INFINITO;
    std::sort(nodos_por_visitar.begin(), nodos_por_visitar.end(), 
          [&](const Nodo& a, const Nodo& b) {
          return problema_.obtener_grafo().calcular_coste(nodo_actual.get_id(), a.get_id()) <
                 problema_.obtener_grafo().calcular_coste(nodo_actual.get_id(), b.get_id());
          });
    
    int indice_aleatorio = 0;
    std::srand(static_cast<unsigned int>(time(nullptr)));
    if (nodos_por_visitar.size() > LRC) {
      indice_aleatorio = std::rand() % LRC; // LRC es la longitud de la lista restringida de candidatos
    } else {
      indice_aleatorio = std::rand() % (nodos_por_visitar.size());
    }
    Nodo nodo_destino = nodos_por_visitar[indice_aleatorio];
    Nodo nodo_descarga;

    switch (puede_visitar(nodo_actual, nodo_destino, tiempo_actual, carga_actual)) {
      case 0: // Se puede visitar el nodo_actual
        nodo_actual = nodo_destino;
        carga_actual += nodo_actual.get_peso();
        tiempo_actual += problema_.obtener_grafo().calcular_coste(nodo_actual.get_id(), nodo_destino.get_id()) + nodo_destino.get_tiempo();
        nodos_visitados.push_back(nodo_actual);
        nodos_por_visitar.erase(
            std::remove(nodos_por_visitar.begin(), nodos_por_visitar.end(), nodo_destino),
            nodos_por_visitar.end()
        );
        break;
      
      case 1: // Primero se va a la zona de descarga y luego se va al nodo_actual con carga 0
        nodo_descarga = problema_.obtener_grafo().obtener_descarga_carcana(nodo_actual);
        tiempo_actual += problema_.obtener_grafo().calcular_coste(nodo_actual.get_id(), nodo_descarga.get_id()) +
                          problema_.obtener_grafo().calcular_coste(nodo_descarga.get_id(), nodo_destino.get_id()) +
                          nodo_destino.get_tiempo();
        problema_.agregar_tarea(nodo_descarga, tiempo_actual, carga_actual);
        carga_actual = nodo_destino.get_peso();
        nodos_por_visitar.erase(
            std::remove(nodos_por_visitar.begin(), nodos_por_visitar.end(), nodo_destino),
            nodos_por_visitar.end()
        );
        nodos_visitados.push_back(nodo_descarga);
        nodo_actual = nodo_destino;
        nodos_visitados.push_back(nodo_actual);
        subrutas++;
        break;
      
      case 2: // Se aumenta el número de camiones y se resetea el tiempo y la carga
        nodo_descarga = problema_.obtener_grafo().obtener_descarga_carcana(nodo_actual);
        carga_actual = 0;
        nodo_actual = problema_.obtener_deposito();
        nodos_visitados.push_back(nodo_descarga);
        nodos_visitados.push_back(nodo_actual);
        tiempo_actual = 0;
        solucion_.agregar_camion();
        solucion_.push_nodos(nodos_visitados);
        nodos_visitados = {};
        subrutas++;
        nodos_visitados.push_back(nodo_actual);
        break;
      
      default: // Error en la funcion puede_visitar al retornar un valor distinto a 0, 1 o 2
        throw std::runtime_error("Error en la función puede_visitar");
    }
  }

  solucion_.push_nodos(nodos_visitados);
  solucion_.set_subrutas(subrutas);
}

/**
 * @brief Busquedas locales para mejorar la solución.
 * @return void
 * @details Se realizan busquedas locales para mejorar la solución.
 */
void GRASP::busquedas_locales() {
  Solucion mejor_solucion;
  mejor_solucion.set_subrutas(std::numeric_limits<int>::max());
  for (Solucion& solucion : soluciones_) {
    int cantidad_subrutas = solucion.get_nodos().size();
    for (int indice_ruta = 0; indice_ruta < cantidad_subrutas; indice_ruta++) { //busquedas locales dentro de la misma ruta
      solucion = busqueda_local1(solucion, indice_ruta);
      solucion = busqueda_local3(solucion, indice_ruta);
      for (int indice_subruta = 0; indice_subruta < cantidad_subrutas; indice_subruta++) { //busquedas locales entre rutas
        if (indice_ruta != indice_subruta) {
          solucion = busqueda_local2(solucion, indice_ruta, indice_subruta);
          solucion = busqueda_local4(solucion, indice_ruta, indice_subruta);
        }
      }
    }
    if (solucion.get_subrutas() < mejor_solucion.get_subrutas()) {
      mejor_solucion = solucion;
    }
  }
  solucion_ = mejor_solucion;
}

/**
 * @brief Busqueda local 1: Intercambio de nodos en la misma ruta.
 * @param solucion Solución a mejorar.
 * @param indice_ruta Índice de la ruta a modificar.
 * @return void
 */
Solucion GRASP::busqueda_local1(Solucion& solucion, int indice_ruta) { // Intercambio de nodos en la misma ruta
  std::vector<Nodo> ruta = solucion.get_nodos()[indice_ruta];
  int tamanio_subruta = ruta.size(); // Para evitar llamar constantemente a la función size()

  Solucion mejor_solucion = solucion;

  for (int nodo1 = 1; nodo1 < tamanio_subruta; nodo1++) {
    for (int nodo2 = (nodo1 + 1); nodo2 < tamanio_subruta; nodo2++) {
      Nodo auxiliar = ruta[nodo1];
      ruta[nodo1] = ruta[nodo2];
      ruta[nodo2] = auxiliar;
      
      Solucion nueva_solucion = mejor_solucion;
      nueva_solucion.cambiar_subruta(indice_ruta, ruta);

      if (nueva_solucion.es_factible(problema_.obtener_tiempo_maximo(), problema_.obtener_peso_maximo()) 
                                  && nueva_solucion.get_subrutas() < solucion.get_subrutas()) {
        mejor_solucion = nueva_solucion;
      } 
    }
  }

  return mejor_solucion;
}

/**
 * @brief Busqueda local 2: Intercambio de entre dos nodos de diferentes rutas.
 * @param solucion Solución a mejorar.
 * @param indice_subruta1 Índice de la primera subruta a modificar.
 * @param indice_subruta2 Índice de la segunda subruta a modificar.
 * @return void
 */
Solucion GRASP::busqueda_local2(Solucion& solucion, int indice_subruta1, int indice_subruta2) { // Intercambio de entre dos nodos de diferentes rutas
  std::vector<Nodo> subruta1 = solucion.get_nodos()[indice_subruta1];
  std::vector<Nodo> subruta2 = solucion.get_nodos()[indice_subruta2];

  Solucion mejor_solucion = solucion;

  //Para evitar llamar constantemente a la función size()
  int tamanio_subruta1 = subruta1.size();
  int tamanio_subruta2 = subruta2.size();
  
  for (int nodo1 = 0; nodo1 < tamanio_subruta1; nodo1++) {
    for (int nodo2 = 0; nodo2 < tamanio_subruta2; nodo2++) {
      Nodo auxiliar = subruta1[nodo1];
      subruta1[nodo1] = subruta2[nodo2];
      subruta2[nodo2] = auxiliar;
      Solucion nueva_solucion = mejor_solucion;
      nueva_solucion.cambiar_subruta(indice_subruta1, subruta1);
      nueva_solucion.cambiar_subruta(indice_subruta2, subruta2);

      if (nueva_solucion.es_factible(problema_.obtener_tiempo_maximo(), problema_.obtener_peso_maximo()) 
                                  && nueva_solucion.get_subrutas() < mejor_solucion.get_subrutas()) {
        mejor_solucion = nueva_solucion;
      }
    }
  }

  return mejor_solucion;
}

/**
 * @brief Busqueda local 3: Inserción de un nodo de una subruta a otra subruta (no intercambio).
 * @param solucion Solución a mejorar.
 * @param indice_ruta Índice de la ruta a modificar.
 * @return void
 */
Solucion GRASP::busqueda_local3(Solucion& solucion, int indice_ruta) { // Inserción de un nodo de una subruta a otra subruta (no intercambio)
  std::vector<Nodo> ruta = solucion.get_nodos()[indice_ruta];
  std::vector<std::vector<Nodo>> subrutas;

  subrutas = obtener_subrutas(ruta);

  int tamanio_subrutas = subrutas.size(); // Para evitar llamar constantemente a la función size()

  Solucion mejor_solucion = solucion;

  for (int subruta1 = 1; subruta1 < tamanio_subrutas; subruta1++) {
    for (int subruta2 = 0; subruta2 < tamanio_subrutas; subruta2++) {
      for (int nodo1 = 0; nodo1 < subrutas[subruta1].size(); nodo1++) {
        for (int nodo2 = 0; nodo2 <= subrutas[subruta2].size(); nodo2++) {
          Nodo nodo_a_mover = subrutas[subruta1][nodo1];
          std::vector<Nodo> copia_subruta1 = subrutas[subruta1];
          std::vector<Nodo> copia_subruta2 = subrutas[subruta2];

          std::vector<Nodo> temp_copia_subruta1 = copia_subruta1;
          std::vector<Nodo> temp_copia_subruta2 = copia_subruta2;

          temp_copia_subruta1.erase(temp_copia_subruta1.begin() + nodo1);
          temp_copia_subruta2.insert(temp_copia_subruta2.begin() + nodo2, nodo_a_mover);

          Solucion nueva_solucion = solucion;
          nueva_solucion.cambiar_subruta(indice_ruta, temp_copia_subruta1);
          nueva_solucion.cambiar_subruta(indice_ruta, temp_copia_subruta2);

          if (nueva_solucion.es_factible(problema_.obtener_tiempo_maximo(), problema_.obtener_peso_maximo()) 
                  && nueva_solucion.get_subrutas() < mejor_solucion.get_subrutas()) {
            mejor_solucion = nueva_solucion;
          }
        }
      }
    }
  }

  return mejor_solucion;
}

/**
 * @brief Busqueda local 4: Inserción de un nodo de una ruta a otra ruta (no intercambio).
 * @param solucion Solución a mejorar.
 * @param indice_ruta1 Índice de la primera ruta a modificar.
 * @param indice_ruta2 Índice de la segunda ruta a modificar.
 * @return void
 */
Solucion GRASP::busqueda_local4(Solucion& solucion, int indice_ruta1, int indice_ruta2) { // Inserción de un nodo de una ruta a otra ruta (no intercambio)
  std::vector<Nodo> ruta1 = solucion.get_nodos()[indice_ruta1];
  std::vector<Nodo> ruta2 = solucion.get_nodos()[indice_ruta2];
  Solucion mejor_solucion = solucion;

  int tamanio_ruta1 = ruta1.size(); // Para evitar llamar constantemente a la función size()
  int tamanio_ruta2 = ruta2.size(); // Para evitar llamar constantemente a la función size()

  for (int nodo1 = 0; nodo1 < tamanio_ruta1; nodo1++) {
    for (int nodo2 = 0; nodo2 <= tamanio_ruta2; nodo2++) { // <= para permitir inserción al final
      Nodo nodo_a_mover = ruta1[nodo1];
      std::vector<Nodo> copia_ruta1 = ruta1;
      std::vector<Nodo> copia_ruta2 = ruta2;

      copia_ruta1.erase(copia_ruta1.begin() + nodo1);
      copia_ruta2.insert(copia_ruta2.begin() + nodo2, nodo_a_mover);

      Solucion nueva_solucion = mejor_solucion;
      nueva_solucion.cambiar_subruta(indice_ruta1, copia_ruta1);
      nueva_solucion.cambiar_subruta(indice_ruta2, copia_ruta2);

      if (nueva_solucion.es_factible(problema_.obtener_tiempo_maximo(), problema_.obtener_peso_maximo()) 
                                  && (nueva_solucion.get_subrutas() < solucion.get_subrutas() ||
                                      nueva_solucion.get_camiones() < solucion.get_camiones())) {
        mejor_solucion = nueva_solucion;
      }
    }
  }

  return mejor_solucion;

}

// Solucion GRASP::busqueda_local5(Solucion& solucion) {}

/**
 * @brief Resetea la solución.
 * @return void
 */
void GRASP::resetear_solucion() {
  solucion_.set_nodos({});
  solucion_.set_subrutas(0);
  solucion_.set_camiones(0);
}