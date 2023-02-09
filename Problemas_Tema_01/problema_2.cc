/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Problema 2: Escriba un programa que solicite al usuario una cantidad
 * de números cccccccccy calcule su media
 * @file main.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2023-02-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <string>
#include <vector>

float AverageNumbers(int items, std::vector<float>items_contain) {
  float result = 0;
  for (int i = 0; i < items; i++) {
    result += items_contain[i];
  }
  return result / items;
}

int main(int argc, char* argv[]) {
  int items = std::stoi(argv[1]);
  std::vector<float> items_contain(items);
  float average;

  std::cout << "Enter 5 items: " << std::endl;
  for (int i = 0; i < items; i++) {
    std::cin >> items_contain[i];
  }

  average = AverageNumbers(items, items_contain);

  std::cout << "Average: " << average << std::endl;
}