/**
 * @file Problema_1.cc
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-06-28
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <vector>

// 1. Escribe un procedimiento en C++ que ordene la primera mitad de la
// secuencia o vector por el método de selección de menor a mayor, luego
// ordene la segunda mitad también por el método de inserción, pero de mayor a
// menor, y finalmente mezcle ambas mitades de forma que el vector quede
// ordenado de mayor a menor ordenada.

void Ordenation(std::vector<int> &vector, int size) {
  ///< Primera mitad seleccion 
  int min;
  int mitad = size / 2;
  for (int i = 0; i < mitad; i++) {
    min = i;
    for (int j = i + 1; j < mitad; j++) {
      if (vector[j] < vector[min]) {
        min = j;
      }
    }
    std::swap(vector[i], vector[min]);
  }

  std::cout << "Primera parte: " << std::endl;
  for (int i = 0; i < size; i++) {
    std::cout << vector[i] << " ";
  }

  ///< Segunda mitad insercion
  for (int i = mitad; i < size; i++) {
    int aux = vector[i];
    int j = i - 1;
    while ((j >= mitad) && (vector[j] < aux)) {
      vector[j + 1] = vector[j];
      j--;
    }
    vector[j + 1] = aux;
  }

  std::cout << "\n\nSegunda parte: " << std::endl;
  for (int i = 0; i < size; i++) {
    std::cout << vector[i] << " ";
  }
}

void Mezcla(std::vector<int> &vector, int centro) {
  int i = centro;
  int j = centro + 1;
  std::vector<int> aux(vector.size() + 1);

  for (int k = 0; i <= vector.size(); k++) {
    if (vector[i] > vector[j]) {
      aux[k] = vector[i];
      i--;
    } else { 
      aux[k] = vector[j];
      j++;
    }
  }

  for (int k = 0; k <= vector.size(); k++) {
    vector[k] = aux[k];
  }
}

int main() {
  std::vector<int> vect = {44, 55, 12, 42, 94, 18, 6, 67};

  Ordenation(vect, vect.size());
  Mezcla(vect, (vect.size() / 2) - 1);
  std::cout << "\n\nSecuencia final: " << std::endl;
  for (int i = 0; i < vect.size(); i++) {
    std::cout << vect[i] << " ";
  }
}