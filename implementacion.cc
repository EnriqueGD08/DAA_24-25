#include "declaraciones.h"

int Algoritmo::puede_visitar(Nodo& nodo, float tiempo_actual, float carga_actual) {
  float coste_ida = problema_.obtener_grafo().calcular_coste(problema_.obtener_deposito().get_id(), nodo.get_id());
  float coste_vuelta = problema_.obtener_grafo().calcular_coste_deposito(nodo.get_id(), problema_.obtener_deposito().get_id());
  float tiempo_total = tiempo_actual + coste_ida + nodo.get_peso() + coste_vuelta;
  if ((carga_actual + nodo.get_peso()) >= problema_.obtener_peso_maximo()) {
    return 2;
  }
  return tiempo_total <= problema_.obtener_tiempo_maximo();
}

void Voraz::resolver() {
  std::vector<Nodo> nodos_visitados;
  std::vector<Nodo> nodos_por_visitar = problema_.obtener_nodos();
  float tiempo_actual = 0;
  float carga_actual = 0;
  int subrutas = 0;
  Nodo nodo_actual = problema_.obtener_deposito();
  int contador = 0;
  std::cout << "Nodos por visitar: " << nodos_por_visitar.size() << std::endl;
  while (!(nodos_por_visitar.size() == 0)) {
    Nodo mejor_nodo;
    float mejor_coste = INFINITO;
    for (auto& nodo : nodos_por_visitar) {
      float coste = problema_.obtener_grafo().calcular_coste(nodo_actual.get_id(), nodo.get_id());
      if (puede_visitar(nodo, tiempo_actual, carga_actual) == 1) {
        mejor_coste = coste;
        mejor_nodo = nodo;
      } else if (puede_visitar(nodo, tiempo_actual, carga_actual) == 2) {
        std::cout << "No se puede visitar el nodo " << nodo.get_id() << " por sobrecarga." << std::endl;
      } else if (puede_visitar(nodo, tiempo_actual, carga_actual) == 0) {
        break;
        std::cout << "No se puede visitar el nodo " << nodo.get_id() << " por tiempo." << std::endl;
      }
    }
    if (mejor_coste == INFINITO) {  // Si no se puede visitar ningún nodo, volvemos al depósito.
      tiempo_actual += problema_.obtener_grafo().calcular_coste_deposito(nodo_actual.get_id(), problema_.obtener_deposito().get_id());
      nodo_actual = problema_.obtener_deposito();
      nodos_visitados.push_back(nodo_actual);
      carga_actual = 0;
      subrutas++;
    } else if (mejor_coste == INFINITO && tiempo_actual >= problema_.obtener_tiempo_maximo()){
      tiempo_actual += problema_.obtener_grafo().calcular_coste_deposito(nodo_actual.get_id(), problema_.obtener_deposito().get_id());
      nodo_actual = problema_.obtener_deposito();
      nodos_visitados.push_back(nodo_actual);
      carga_actual = 0;
      tiempo_actual = 0;
      solucion_.agregar_camion();
      subrutas++;
    } else {
      tiempo_actual += mejor_coste;
      carga_actual += mejor_nodo.get_peso();
      std::cout << std::endl;
      std::cout << "Visitando nodo: " << mejor_nodo.get_id() << std::endl;
      std::cout << "Carga actual: " << carga_actual << std::endl;
      std::cout << "tiempo total: " << tiempo_actual << std::endl;
      std::cout << std::endl;
      nodos_visitados.push_back(mejor_nodo);
      nodo_actual = mejor_nodo;
      nodos_por_visitar.erase(std::remove(nodos_por_visitar.begin(), nodos_por_visitar.end(), mejor_nodo), nodos_por_visitar.end());
    }
  }

  solucion_.set_nodos(nodos_visitados);
  solucion_.set_subrutas(subrutas);
}

Problema leer_archivo(const std::string& nombre_archivo) {
  std::ifstream archivo(nombre_archivo);
  if (!archivo) {
    throw std::runtime_error("No se pudo abrir el archivo");
  }

  int L1, L2, num_vehicles, num_zones, Lx, Ly, Q1, Q2, V;
  int depot_x, depot_y;
  int IF_x, IF_y;
  int IF1_x, IF1_y;
  std::vector<Nodo> nodos;
  
  std::string linea;
  while (std::getline(archivo, linea)) {
    std::istringstream iss(linea);
    std::string clave;
    iss >> clave;

    if (clave == "L1") iss >> L1;
    else if (clave == "L2") iss >> L2;
    else if (clave == "num_vehicles") iss >> num_vehicles;
    else if (clave == "num_zones") iss >> num_zones;
    else if (clave == "Lx") iss >> Lx;
    else if (clave == "Ly") iss >> Ly;
    else if (clave == "Q1") iss >> Q1;
    else if (clave == "Q2") iss >> Q2;
    else if (clave == "V") iss >> V;
    else if (clave == "Depot") iss >> depot_x >> depot_y;
    else if (clave == "IF") iss >> IF_x >> IF_y;
    else if (clave == "IF1") iss >> IF1_x >> IF1_y;
    else {
      int id;
      double x, y;
      float tiempo, demanda;
      if (std::istringstream(linea) >> id >> x >> y >> tiempo >> demanda) {
        nodos.emplace_back(id, Posicion(x, y), demanda);
      }
    }
  }
  Grafo grafo;
  Nodo deposito(0, Posicion(depot_x, depot_y), 0);
  Problema problema(L1, Q1, grafo, deposito, V);
  for (const auto& nodo : nodos) {
      problema.agregar_nodo(nodo);
  }
  std::cout << problema.obtener_grafo().get_adyacencias().size()<< std::endl;
  return problema;
}

void mostrar_solucion(const Solucion& solucion) {
  std::cout << "Solución encontrada:" << std::endl;
  std::cout << "Número de camiones: " << solucion.get_camiones() << std::endl;
  std::cout << "Número de subrutas: " << solucion.get_subrutas() << std::endl;
  std::cout << "Nodos visitados en orden:" << std::endl;
  for (const auto& nodo : solucion.get_nodos()) {
      std::cout << "Nodo " << nodo.get_id() << " en (" << nodo.get_posicion().get_x()
                << ", " << nodo.get_posicion().get_y() << ")" << std::endl;
  }
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "Uso: " << argv[0] << " <archivo_entrada>" << std::endl;
    return 1;
  }

  try {
    Problema problema = leer_archivo(argv[1]);
    Voraz algoritmo(problema);
    algoritmo.resolver();
    mostrar_solucion(algoritmo.obtener_solucion());
      
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }
  return 0;
}