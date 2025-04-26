#include "solucion.h"

bool Solucion::es_factible(float tiempo, float peso) const {
  for (const auto& subruta : nodos_) {
    float tiempo_subruta = 0;
    float carga_subruta = 0;
    for (const auto& nodo : subruta) {
      tiempo_subruta += nodo.get_tiempo();
      carga_subruta += nodo.get_peso();
    }
    if (tiempo_subruta > tiempo || carga_subruta > peso) {
      return false;
    }
  }
  return true;
}