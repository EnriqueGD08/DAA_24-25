/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 * Práctica 3: Algoritmos Divide y Vencerás
 *
 * @author Enrique Gómez Díaz
 * @date 11 Mar 2025
 * @brief implementation of the Framework class
 */

#include "framework.h"

/**
 * @brief Divide y Venceras
 * @param algoritmo
 * @param solucion
 * @param profundidad
 */
void Framework::DivideyVenceras(Algorithm* algoritmo, Solution* solucion, int profundidad) {
	profundidad++;
	contadorTotalRecursion_++;
	if (profundidad > nivelMaximoRecursion_) nivelMaximoRecursion_ = profundidad;
	if (algoritmo->IsSmall()) {
		algoritmo->SolveSmall(solucion);
	} else {
		std::vector<Algorithm*> subproblemaas;
		std::vector<Solution*> soluciones;

		subproblemaas = algoritmo->Divide();
		
		for (int i = 0; i < (int)subproblemaas.size(); i++) {
			soluciones.push_back(solucion->GetInstance());
		}

		for (int i = 0; i < (int)subproblemaas.size(); i++) {
			DivideyVenceras(subproblemaas[i], soluciones[i], profundidad);
		}

		solucion->MergeSolutions(soluciones);
	}
}

/**
 * @brief Print Recurrencia
 * @param algoritmo
 */
void Framework::PrintRecurrencia(Algorithm* problema) {
	std::cout << "T(n) = " << problema->GetA() << "T(" << problema->GetB() << ") + " << problema->GetD() << std::endl;
}