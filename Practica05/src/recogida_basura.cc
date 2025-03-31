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
 * @brief: fichero de la funcion principal
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include "grafo.h"
#include "nodo.h"
#include "posicion.h"
#include "problema.h"
#include "voraz.h"
#include "algoritmo.h"
#include "solucion.h"

Problema leer_archivo(const std::string& nombre_archivo) {
  std::ifstream archivo(nombre_archivo);
  if (!archivo) {
    throw std::runtime_error("No se pudo abrir el archivo");
  }

  int L1, L2, num_vehicles, num_zones, Lx, Ly, Q1, Q2, V;
  int depot_x, depot_y;
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
  Problema problema(L1, Q1, grafo, deposito);
  for (const auto& nodo : nodos) {
      problema.agregar_nodo(nodo);
  }
  std::cout << problema.obtener_grafo().get_adyacencias().size()<< std::endl;
  return problema;
}

void mostrar_solucion(const Solucion& solucion) {
  std::cout << "Solución encontrada:" << std::endl;
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
    problema.obtener_grafo().print();
    algoritmo.resolver();
    mostrar_solucion(algoritmo.obtener_solucion());
      
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }
  return 0;
}