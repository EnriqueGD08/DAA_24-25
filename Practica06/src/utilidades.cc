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

    Problema problema(archivo);
    archivo.close();
    
    std::cout << problema << std::endl;
}

/**
 * @brief Función que ejecuta el programa con una carpeta como parámetro.
 * @param argv Arreglo de argumentos de la línea de comandos.
 * @return void
 */
void ejecutarProgramaCarpeta (char* argv[]) {

}