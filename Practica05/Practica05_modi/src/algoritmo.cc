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
 * @brief: implementación de la clase Algoritmo
*/

#include "algoritmo.h"

/**
 * @brief función que devuelve si se puede visitar un nodo o no
 * @param nodo nodo a visitar
 * @param tiempo_actual tiempo actual
 * @param carga_actual carga actual
 * @return 0 si se puede visitar, 1 si no se puede visitar por carga, 2 si no se puede visitar por tiempo
 */
int Algoritmo::puede_visitar(Nodo& nodo_actual, Nodo& nodo_destino, float tiempo_actual, float carga_actual) {
  float tiempo_total = tiempo_actual + problema_.obtener_grafo().calcular_coste(nodo_actual.get_id(), nodo_destino.get_id()) +
                       problema_.obtener_grafo().calcular_coste(nodo_destino.get_id(), problema_.obtener_IF().get_id()) +
                       problema_.obtener_grafo().calcular_coste(problema_.obtener_IF().get_id(), problema_.obtener_deposito().get_id()) +
                       nodo_destino.get_tiempo();
                      
  if (tiempo_total > problema_.obtener_tiempo_maximo()) {
    return 2; // No se puede visitar por el tiempo
  }
  if ((carga_actual + nodo_destino.get_peso()) > problema_.obtener_peso_maximo()) {
    return 1; // No se puede visitar por la carga
  }
  return 0; // Se puede visitar
}

/**
 * @brief Muestra la solución encontrada en la consola.
 * @param solucion Objeto Solucion que contiene la solución a mostrar.
 * @return void
 */
void Algoritmo::mostrar_solucion() const {
  std::cout << "Solución encontrada:" << std::endl;
  std::cout << "Número de camiones: " << solucion_.get_camiones() << std::endl;
  std::cout << "Número de subrutas: " << solucion_.get_subrutas() << std::endl << std::endl;
  std::cout << "Nodos visitados en orden:" << std::endl;
  bool salida = false;
  for (const auto& nodos : solucion_.get_nodos()) {
    bool inicio_ruta = false;
    for (const Nodo nodo : nodos) {
      switch (static_cast<int>(nodo.get_id())) {
      case 0:
        if (inicio_ruta == false) { std::cout << "Depósito -> "; inicio_ruta = true; }
        else { std::cout << "Depósito"; inicio_ruta = false; }
        break;

      case -1:
        std::cout << "IF -> ";
        break;

      case -2:
        std::cout << "IF1 -> ";
        break;
      
      default:
        std::cout << nodo.get_id() << " -> ";
        break;
      }
    }
    std::cout << std::endl;
  }
  std::cout << "No quedan zonas por visitar." << std::endl;
  std::cout << "--------------------------------------------------------" << std::endl;
  std::cout << "                 FIN DE LA SOLUCIÓN                    " << std::endl;
  std::cout << "--------------------------------------------------------" << std::endl;
  std::cout << std::endl;
}

/**
 * @brief Obtiene las subrutas de la solución.
 * @param nodos_visitados Vector de nodos visitados.
 * @return std::vector<std::vector<Nodo>> Vector de subrutas.
 */
std::vector<std::vector<Nodo>> Algoritmo::obtener_subrutas(std::vector<Nodo>& nodos_visitados) {
  std::vector<std::vector<Nodo>> subrutas;
  std::vector<Nodo> subruta;
  for (const Nodo& nodo : nodos_visitados) {
    if (nodo.get_id() == 0) {
      if (!subruta.empty()) {
        subrutas.push_back(subruta);
        subruta.clear();
      }
    }
    subruta.push_back(nodo);
  }
  if (!subruta.empty()) {
    subrutas.push_back(subruta);
  }
  return subrutas;
}

/**
 * @brief crea las tareas a partir de la solución.
 * @return void
 */
void Algoritmo::set_tareas() {
  std::vector<std::vector<Nodo>> nodos = solucion_.get_nodos();

  for (int i = 0; i < nodos.size(); ++i) {
    std::vector<Nodo> subruta = nodos[i];
    float tiempo = 0;
    float peso = 0;
    for (int j = 1; j < subruta.size() - 1; ++j) {
      if (subruta[j].get_id() != 0 && subruta[j].get_id() != -1 && subruta[j].get_id() != -2) {
        tiempo += problema_.obtener_grafo().calcular_coste(subruta[j - 1].get_id(), subruta[j].get_id()) +
                  subruta[j].get_tiempo();
        peso += subruta[j].get_peso();
      } else if (subruta[j].get_id() == -1 || subruta[j].get_id() == -2) {
        tiempo += problema_.obtener_grafo().calcular_coste(subruta[j - 1].get_id(), subruta[j].get_id());
        peso = 0;
        problema_.agregar_tarea(subruta[j], tiempo, peso);
      }
    }
  }
}

/**
 * @brief Calcula las rutas de transporte.
 * @return void
 */
int Algoritmo::ChooseVehicle(const Tareas& tarea) {
  int vehiculo = -1;
  float mejor_tiempo = INFINITO;
  for (int camion = 0; camion < solucion_.get_camiones_transporte().size(); ++camion) {
    float tiempo;
    if (solucion_.get_camiones_transporte()[camion].second + tarea.peso < problema_.obtener_peso_maximo_transporte()) {
      tiempo = problema_.obtener_grafo().calcular_coste(solucion_.get_nodos_transporte()[camion].back().get_id(), tarea.Zona_descarga.get_id());
    }
    else {
      Nodo nodo_descarga = problema_.obtener_grafo().obtener_descarga_carcana(solucion_.get_nodos_transporte()[camion].back());
      tiempo = solucion_.get_camiones_transporte()[camion].first + 
      problema_.obtener_grafo().calcular_coste(solucion_.get_nodos_transporte()[camion].back().get_id(), nodo_descarga.get_id()) +
      problema_.obtener_grafo().calcular_coste(nodo_descarga.get_id(), tarea.Zona_descarga.get_id());
    }
    if (tiempo < mejor_tiempo && solucion_.get_camiones_transporte()[camion].first + tiempo + 
        problema_.obtener_grafo().calcular_coste(tarea.Zona_descarga.get_id(), problema_.obtener_vertedero().get_id()) < problema_.obtener_tiempo_maximo()) {
      mejor_tiempo = tiempo;
      vehiculo = camion;
    }

  }

  return vehiculo;
}

/**
 * @brief Calcula las rutas de transporte.
 * @return void
 */
void Algoritmo::calcular_rutas_transporte() {
  std::vector<Tareas> tareas = problema_.obtener_tareas();
  
  // Ordenar las tareas por el orden de llegada
  std::sort(tareas.begin(), tareas.end(), [](const Tareas& a, const Tareas& b) {
    return a.tiempo < b.tiempo;
  });
  std::vector<Tareas> tareas_ordenadas = tareas;

  // Asignar uno por uno las rutas para cada camión
  for (Tareas& tarea : tareas_ordenadas) {
    int camion = ChooseVehicle(tarea);
    if (camion != -1) {
      // Asignar la tarea al camión
      if (solucion_.get_camiones_transporte()[camion].second + tarea.peso < problema_.obtener_peso_maximo_transporte()) {
        solucion_.set_peso_transporte(camion, solucion_.get_camiones_transporte()[camion].second + tarea.peso);
        solucion_.set_tiempo_transporte(camion, solucion_.get_camiones_transporte()[camion].first +
                                                problema_.obtener_grafo().calcular_coste(solucion_.get_nodos_transporte()[camion].back().get_id(), tarea.Zona_descarga.get_id()));
        solucion_.push_nodos_transporte(camion, tarea.Zona_descarga);
      }
      else {
        Nodo nodo_descarga = problema_.obtener_grafo().obtener_descarga_carcana(solucion_.get_nodos_transporte()[camion].back());
        solucion_.set_tiempo_transporte(camion, solucion_.get_camiones_transporte()[camion].first +
                                                problema_.obtener_grafo().calcular_coste(solucion_.get_nodos_transporte()[camion].back().get_id(), problema_.obtener_vertedero().get_id()) +
                                                problema_.obtener_grafo().calcular_coste(problema_.obtener_vertedero().get_id(), tarea.Zona_descarga.get_id()));
        solucion_.set_peso_transporte(camion, tarea.peso);
        solucion_.push_nodos_transporte(camion, nodo_descarga);
        solucion_.push_nodos_transporte(camion, tarea.Zona_descarga);
      }
    } else {
      // Si no hay camiones disponibles, se crea uno nuevo
      float tiempo = problema_.obtener_grafo().calcular_coste(problema_.obtener_vertedero().get_id(), tarea.Zona_descarga.get_id());
      solucion_.push_camiones_transporte({ tiempo, tarea.peso });
      
      solucion_.push_nodos_transporte(solucion_.get_nodos_transporte().size() - 1, problema_.obtener_vertedero());
      solucion_.push_nodos_transporte(solucion_.get_nodos_transporte().size() - 1, tarea.Zona_descarga);
    }
  }
}