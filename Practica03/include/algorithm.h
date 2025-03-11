/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 * Práctica 3: Algoritmos Divide y Vencerás
 *
 * @author Enrique Gómez Díaz
 * @date 11 Mar 2025
 * @brief declaration of the Algorithm class
 */

#pragma once

#include <vector>
#include <utility>
#include <iostream>
#include "solution.h"

class Algorithm {
 public:
	Algorithm() {};
	virtual ~Algorithm() {};

	virtual bool IsSmall() = 0;
	virtual std::vector<Algorithm*> Divide(int num = 2) = 0;
	virtual void SolveSmall(Solution*) = 0;
	virtual std::string GetA() = 0;
	virtual std::string GetB() = 0;
	virtual std::string GetD() = 0;
};