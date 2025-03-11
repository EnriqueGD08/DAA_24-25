/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 * Práctica 3: Algoritmos Divide y Vencerás
 *
 * @author Enrique Gómez Díaz
 * @date 11 Mar 2025
 * @brief declaration of the Solution class
 */

#pragma once

#include <vector>
#include <utility>
#include <iostream>

class Solution {
 public:
	Solution() {};
	virtual ~Solution() {};

	virtual void Print() = 0;
	virtual void MergeSolutions(std::vector<Solution*>) = 0;
	virtual Solution* GetInstance() = 0;
};