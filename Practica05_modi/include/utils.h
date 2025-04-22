#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include "grafo.h"
#include "nodo.h"
#include "posicion.h"
#include "problema.h"
#include "voraz.h"
#include "grasp.h"
#include "algoritmo.h"
#include "solucion.h"

Problema leer_archivo(const std::string& nombre_archivo);
void mostrar_solucion(const Solucion& solucion);