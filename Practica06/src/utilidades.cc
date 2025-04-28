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
 * @brief: implementación de funciones de utilidad
*/

#include "utilidades.h"

/**
 * @brief Función que muestra el uso del programa.
 * @param argc Número de argumentos de la línea de comandos.
 * @param argv Arreglo de argumentos de la línea de comandos.
 * @return void
 */
void ussage(int argc, char* argv[]) {
  if (argc == 2 && std::string(argv[1]) == "-h") {
    std::cout << "Uso: " << argv[0] << " -a|-c" << " <archivo/carpeta>" << std::endl;
    std::cout << "-a: Ejecutar el programa con un archivo como parámetro." << std::endl;
    std::cout << "-c: Ejecutar el programa con una carpeta como parámetro." << std::endl;
    exit(EXIT_SUCCESS);
  }
  if (argc != 3) {
    std::cerr << "Error: Número de argumentos incorrecto." << std::endl;
    std::cerr << "Uso: " << argv[0] << " -a|-c" << " <archivo/carpeta>" << std::endl;
    std::cerr << "Para más información, use: " << argv[0] << " -h" << std::endl;
    exit(EXIT_FAILURE);
  }
  if (std::string(argv[1]) != "-a" && std::string(argv[1]) != "-c") {
    std::cerr << "Error: Opción no válida." << std::endl;
    std::cerr << "Uso: " << argv[0] << " -a|-c" << " <archivo/carpeta>" << std::endl;
    std::cerr << "Para más información, use: " << argv[0] << " -h" << std::endl;
    exit(EXIT_FAILURE);
  }
}

/**
 * @brief Función que ejecuta el programa con un archivo como parámetro.
 * @param argv Arreglo de argumentos de la línea de comandos.
 * @return void
 */
void ejecutarProgramaArchivo (char* argv[]) {
    std::ifstream archivo(argv[2]);
    if (!archivo.is_open()) {
      LANZAR_ERROR("No se pudo abrir el archivo", "El archivo que se intenta abrir es: " + std::string(argv[2]));
    }

    std::ofstream salida_voraz("salida_voraz.csv");
    std::ofstream salida_grasp("salida_grasp.csv");
    std::ofstream salida_busqueda_local("salida_busqueda_local.csv");

    Problema problema(archivo);
    archivo.close();

    Algoritmo* algoritmo;
    
    algoritmo = new Voraz(problema);
    algoritmo->resolver();
    salida_voraz << std::string(argv[2]) << ',' << algoritmo->toCSV() << std::endl;

    algoritmo = new GRASP(problema);
    dynamic_cast<GRASP*>(algoritmo)->setLRC(3);
    algoritmo->resolver();
    salida_grasp << std::string(argv[2]) << ',' << algoritmo->toCSV() << std::endl;

    algoritmo = new BusquedaLocal(problema);
    algoritmo->resolver();
    salida_busqueda_local << std::string(argv[2]) << ',' << algoritmo->toCSV() << std::endl;

    delete algoritmo;
}

/**
 * @brief Función que ejecuta el programa con una carpeta como parámetro.
 * @param argv Arreglo de argumentos de la línea de comandos.
 * @return void
 */
void ejecutarProgramaCarpeta (char* argv[]) {
  std::filesystem::path carpeta(argv[2]);
  if (!std::filesystem::is_directory(carpeta)) {
    LANZAR_ERROR("No se pudo abrir la carpeta", "La carpeta que se intenta abrir es: " + std::string(argv[2]));
  }
  std::ofstream salida_voraz("salida_voraz.csv");
  std::ofstream salida_grasp("salida_grasp.csv");
  std::ofstream salida_busqueda_local("salida_busqueda_local.csv");

  for (const auto& archivo : std::filesystem::directory_iterator(carpeta)) {
    if (archivo.is_regular_file()) {

      try {
        std::ifstream archivo_entrada(archivo.path());
        if (!archivo_entrada.is_open()) {
          LANZAR_ERROR("No se pudo abrir el archivo", "El archivo que se intenta abrir es: " + archivo.path().string());
        }

        Problema problema(archivo_entrada);
        archivo_entrada.close();

        Algoritmo* algoritmo;
        
        algoritmo = new Voraz(problema);
        algoritmo->resolver();
        salida_voraz << archivo.path().filename() << ',' << algoritmo->toCSV() << std::endl;
        
        for (int lrc = 2; lrc <= 5; lrc++) {
          algoritmo = new GRASP(problema);
          dynamic_cast<GRASP*>(algoritmo)->setLRC(lrc);
          algoritmo->resolver();
          salida_grasp << archivo.path().filename()<< ',' << algoritmo->toCSV() << std::endl;
        }

        for (int lrc = 2; lrc <= 5; lrc++) {
          for (int iteraciones = 10; iteraciones <= 50; iteraciones += 10) {
            algoritmo = new BusquedaLocal(problema);
            dynamic_cast<BusquedaLocal*>(algoritmo)->setMaxIteraciones(iteraciones);
            dynamic_cast<BusquedaLocal*>(algoritmo)->setLRC(lrc);
            algoritmo->resolver();
            salida_busqueda_local << archivo.path().filename() << ',' << iteraciones << ',' << algoritmo->toCSV() << std::endl;
          }
        }

        delete algoritmo;
      } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
      }
    }
  }

}