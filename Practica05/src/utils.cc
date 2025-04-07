# include "utils.h"

/**
 * @brief Lee un archivo de texto y crea un objeto Problema a partir de él.
 * @param nombre_archivo Nombre del archivo a leer.
 * @return Objeto Problema creado a partir de los datos del archivo.
 */
Problema leer_archivo(const std::string& nombre_archivo) {
  //abrir el archivo de texto
  std::ifstream archivo(nombre_archivo);

  //verificar si el archivo se abrió correctamente
  if (!archivo) {
    throw std::runtime_error("No se pudo abrir el archivo");
  }

  //inicializar variables para almacenar los datos del problema
  int L1; // duración máxima de las rutas de recolección
  int L2; // duración máxima de las rutas de transporte
  int num_vehicles; // número de camiones
  int num_zones; // número de zonas para la recolección
  int Lx, Ly;
  int Q1; // capacidad máxima de los camiones de recolección
  int Q2; // capacidad máxima de los camiones de transporte
  float V; // velocidad de los camiones
  int depot_x, depot_y; // coordenadas del depósito
  int IF_x, IF_y; // coordenadas de la primera instalación de transferencia
  int IF1_x, IF1_y; // coordenadas de la segunda instalación de transferencia
  int dumpsite_x, dumpsite_y; // coordenadas del vertedero
  int epsilon, offset;
  std::vector<Nodo> nodos;
  
  //leer los datos del archivo y almacenarlos en las variables correspondientes
  std::string linea;
  while (std::getline(archivo, linea)) {
    // Se lee cada línea del archivo
    // y se separa en palabras usando un stringstream
    std::istringstream iss(linea);
    std::string clave;
    iss >> clave;

    // Se verifica qué clave se está leyendo y se almacena el valor correspondiente
    if (clave == "L1") iss >> L1;
    else if (clave == "L2") iss >> L2;
    else if (clave == "num_vehicles") iss >> num_vehicles;
    else if (clave == "num_zones") iss >> num_zones;
    else if (clave == "epsilon") iss >> epsilon;
    else if (clave == "Lx") iss >> Lx;
    else if (clave == "Ly") iss >> Ly;
    else if (clave == "Q1") iss >> Q1;
    else if (clave == "Q2") iss >> Q2;
    else if (clave == "V") iss >> V;
    else if (clave == "Depot") iss >> depot_x >> depot_y;
    else if (clave == "Dumpsite") iss >> dumpsite_x >> dumpsite_y;
    else if (clave == "IF") iss >> IF_x >> IF_y;
    else if (clave == "IF1") iss >> IF1_x >> IF1_y;
    else if (std::isdigit(clave[0])) {
      int id;
      double x, y;
      float tiempo, demanda;
      if (std::istringstream(linea) >> id >> x >> y >> tiempo >> demanda) {
        nodos.emplace_back(id, Posicion(x, y), demanda, tiempo);
      }
    } else {
      continue; // Ignorar líneas no relevantes
    }
  }

  //cerrar el archivo
  archivo.close();

  // Crear el grafo a partir de los nodos leídos
  // y construir el objeto Problema
  Grafo grafo;
  Nodo deposito(0, Posicion(depot_x, depot_y), 0);
  Nodo IF(-1, Posicion(IF_x, IF_y), 0);
  Nodo IF1(-2, Posicion(IF1_x, IF1_y), 0);
  Problema problema(L1, Q1, grafo, deposito, V, IF, IF1);
  problema.agregar_nodo(IF1);
  problema.agregar_nodo(IF);
  problema.agregar_nodo(deposito);
  for (const auto& nodo : nodos) {
      problema.agregar_nodo(nodo);
  }

  return problema;
}