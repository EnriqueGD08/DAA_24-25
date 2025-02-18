/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * @author Esther M. Quintero
 * @date 13 Feb 2024
 * @brief Encabezado de la clase "MemoriaDatos"
 *        Posee una serie de registros indexados R0, R1, R2, …, Rn para almacenar datos. 
 *        El registro R0 es un registro especial llamado acumulador, el cual ayuda en la 
 *        realización de operaciones aritméticas, lógicas y de control.
 */

#ifndef MEMORIA_DATOS_H
#define MEMORIA_DATOS_H

#include <iostream>
#include <vector>

class MemoriaDatos {
 public:
  MemoriaDatos() {}; /// Constructor por defecto
  ~MemoriaDatos() {}; /// Destructor por defecto

  int get_valor(int registro) { return registros_[registro]; };
  void set_valor(int valor) { registros_[0] = valor; };
  void guardar_valor(int registro, int valor);
  friend std::ostream& operator<<(std::ostream& os, MemoriaDatos& memoria_datos);

 private:
  std::vector<int> registros_ = {0};
};

#endif