/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 28 Ene 2024
 * @brief Archivo: utilities.cc
 *        Contiene las siguientes funciones auxiliares:
 *              usage: Comprueba que el pograma está siendo usado de forma correcta
 *              error: Muestra un error en caso de uso incorrecto del programa        
 * 
 * @details 
 *    28/01/2024 - Creación del fichero
 *    28/01/2024 - Constantes para colores
 *    28/01/2024 - Mensaje de ayuda
 *    28/01/2024 - Función usage
 *    28/01/2024 - Función error
 */

#include "utilities.h"

const std::string kMensajeHelp = BLK 
"\n--------------------------------------------- Simulador RAM ---------------------------------------------\n\n\
Uso: ./simulador-ram programa.ram cinta_entrada.txt cinta_salida.txt [debug] | [--help] | [--instruccion]\n\
\nLa máquina posee un conjunto de instrucciones, cada una de ellas formada por OPERADOR + OPERANDO.\n\
Las instrucciones disponibles en nuestra máquina RAM serán las siguientes:\n\
            - LOAD op\n\
            - STORE op\n\
            - ADD op\n\
            - MUL op\n\
            - DIV op\n\
            - READ op\n\
            - WRITE op\n\
            - JUMP op\n\
            - JZERO op\n\
            - JGTZ op\n\
            - HALT\n\n\
----------------------------------------------------------------------------------------------------------\n";

const std::string kLoadHelp = BLK "\nLOAD: Carga en el acumulador el valor de la posición de memoria indicada por el operando.\n\
    - Modos de direccionamiento: directo, indirecto, inmediato.\n\
        - Ejemplo: LOAD 5\n\
        - Ejemplo: LOAD *5\n\
        - Ejemplo: LOAD =5\n"; 

const std::string kStoreHelp = BLK "\nSTORE: Almacena el valor del acumulador en la posición de memoria indicada por el operando.\n\
    - Modos de direccionamiento: directo, indirecto.\n\
        - Ejemplo: STORE 5\n\
        - Ejemplo: STORE *5\n";

const std::string kAddHelp = BLK "\nADD: Suma al acumulador el valor de la posición de memoria indicada por el operando.\n\
    - Modos de direccionamiento: directo, indirecto, inmediato.\n\
        - Ejemplo: ADD 5\n\
        - Ejemplo: ADD *5\n\
        - Ejemplo: ADD =5\n";

const std::string kMulHelp = BLK "\nMUL: Multiplica al acumulador el valor de la posición de memoria indicada por el operando.\n\
    - Modos de direccionamiento: directo, indirecto, inmediato.\n\
        - Ejemplo: MUL 5\n\
        - Ejemplo: MUL *5\n\
        - Ejemplo: MUL =5\n";

const std::string kDivHelp = BLK "\nDIV: Divide al acumulador el valor de la posición de memoria indicada por el operando.\n\
    - Modos de direccionamiento: directo, indirecto, inmediato.\n\
        - Ejemplo: DIV 5\n\
        - Ejemplo: DIV *5\n\
        - Ejemplo: DIV =5\n";

const std::string kReadHelp = BLK "\nREAD: Lee un valor de la cinta de entrada y lo almacena en la posición de memoria indicada por el operando.\n\
    - Modos de direccionamiento: directo, indirecto.\n\
        - Ejemplo: READ 5\n\
        - Ejemplo: READ *5\n";

const std::string kWriteHelp = BLK "\nWRITE: Escribe el valor de la posición de memoria indicada por el operando en la cinta de salida.\n\
    - Modos de direccionamiento: directo, indirecto, inmediato.\n\
        - Ejemplo: WRITE 5\n\
        - Ejemplo: WRITE *5\n\
        - Ejemplo: WRITE =5\n";

const std::string kJumpHelp = BLK "\nJUMP: Salta a la instrucción indicada por el operando.\n\
    - Modos de direccionamiento: directo, indirecto.\n\
        - Ejemplo: JUMP 5\n\
        - Ejemplo: JUMP *5\n\
        - Ejemplo: JUMP etiqueta\n";

const std::string kJzeroHelp = BLK "\nJZERO: Salta a la instrucción indicada por el operando si el acumulador es 0.\n\
    - Modos de direccionamiento: directo, indirecto.\n\
        - Ejemplo: JZERO 5\n\
        - Ejemplo: JZERO *5\n\
        - Ejemplo: JZERO etiqueta\n";

const std::string kJgtzHelp = BLK "\nJGTZ: Salta a la instrucción indicada por el operando si el acumulador es mayor que 0.\n\
    - Modos de direccionamiento: directo, indirecto.\n\
        - Ejemplo: JGTZ 5\n\
        - Ejemplo: JGTZ *5\n\
        - Ejemplo: JGTZ etiqueta\n";

const std::string kHaltHelp = BLK "\nHALT: Finaliza la ejecución del programa.\n";

/** 
 *  @brief Muestra el modo de uso correcto del programa
 *  @param[in] argc Número de parámetros.
 *  @param[in] argv Vector con los parámetros.
 *  @return (void) Pero termina el programa si no existe
 */
void Usage(int argc, char *argv[]) {
  if (argc > 5) {
    std::cout << RED << argv[0] << ": Ha introducido más de 4 parámetros." << std::endl;
    std::cout << RED "Pruebe " << argv[0] << " --help para mas información." << std::endl;
    exit(EXIT_FAILURE);
  }
  std::string parametro{argv[1]};
  if (parametro == "--help") {
    std::cout << kMensajeHelp << std::endl;
    exit(EXIT_SUCCESS);
  } else if (parametro == "--load") {
    std::cout << kLoadHelp << std::endl;
    exit(EXIT_SUCCESS);
  } else if (parametro == "--store") {
    std::cout << kStoreHelp << std::endl;
    exit(EXIT_SUCCESS);
  } else if (parametro == "--add") {
    std::cout << kAddHelp << std::endl;
    exit(EXIT_SUCCESS);
  } else if (parametro == "--mul") {
    std::cout << kMulHelp << std::endl;
    exit(EXIT_SUCCESS);
  } else if (parametro == "--div") {
    std::cout << kDivHelp << std::endl;
    exit(EXIT_SUCCESS);
  } else if (parametro == "--read") {
    std::cout << kReadHelp << std::endl;
    exit(EXIT_SUCCESS);
  } else if (parametro == "--write") {
    std::cout << kWriteHelp << std::endl;
    exit(EXIT_SUCCESS);
  } else if (parametro == "--jump") {
    std::cout << kJumpHelp << std::endl;
    exit(EXIT_SUCCESS);
  } else if (parametro == "--jzero") {
    std::cout << kJzeroHelp << std::endl;
    exit(EXIT_SUCCESS);
  } else if (parametro == "--jgtz") {
    std::cout << kJgtzHelp << std::endl;
    exit(EXIT_SUCCESS);
  } else if (parametro == "--halt") {
    std::cout << kHaltHelp << std::endl;
    exit(EXIT_SUCCESS);
  }
  if (argc != 5) {
    std::cout << RED << argv[0] << ": Faltan parámetros." << std::endl;
    std::cout << RED "Pruebe " << argv[0] << " --help para mas información." << std::endl;
    exit(EXIT_FAILURE);
  }
}

/** 
 *  @brief Comprueba si hay parámetros
 *  @return (void) Pero termina el programa si los parámetros están mal
 */
void Error() {
  std::cout << RED "No se han introducido parámetros." << std::endl;
  std::cout << RED "Pruebe --help para mas informaciÓn." << std::endl;
  exit(EXIT_FAILURE);
}