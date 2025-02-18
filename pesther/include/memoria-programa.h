/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * @author Esther M. Quintero
 * @date 13 Feb 2024
 * @brief Encabezado de la clase "MemoriaPrograma"
 *        Guarda el conjunto de instrucciones de un programa. 
 *        Esta memoria no es modificable.
 */

#ifndef MEMORIA_PROGRAMA_H_
#define MEMORIA_PROGRAMA_H_

#include "instruccion.h"
#include <iostream>
#include <vector>
#include <memory> 
#include <map>

class MemoriaPrograma {
 public:
  MemoriaPrograma() {}; /// Constructor por defecto
  MemoriaPrograma(std::vector<Instruccion*> programa, std::map<std::string, int> etiquetas); 
  ~MemoriaPrograma() {}; /// Destructor por defecto

  inline std::map<std::string, int> get_etiquetas() { return etiquetas_; };
  std::vector<Instruccion*> get_programa() { return programa_; };
  Instruccion* get_instruccion(int posicion) { return programa_[posicion]; };
  std::ostream& write(std::ostream& os) const;

 private:
  std::vector<Instruccion*> programa_;
  std::map<std::string, int> etiquetas_;
};

#endif