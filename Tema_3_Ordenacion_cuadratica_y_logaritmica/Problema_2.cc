/**
 * @file Problema_2.cc
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-06-28
 *
 * @copyright Copyright (c) 2023
 *
 */

// 2. Escribe un procedimiento en C++ que ordene de menor a mayor por el método
// de ordenación por inserción los elementos de las posiciones impares entre sí,
// y luego ordene de mayor a menor por el método de ordenación por selección los
// elementos de las posiciones pares, y finalmente mezcle ambas partes.

#include <iostream>
#include <vector>

void printVector(std::vector<int> &vector, int size) {
  for (int i = 0; i < size; i++) {
    std::cout << vector[i] << " ";
  }
}

void Ordenation(std::vector<int> &vector, int size) {
  ///< Primera parte Insercion los elementos de las posiciones impares entre sí,
  ///< menor a mayor
  for (int i = 1; i < size; i += 2) {
    int aux = vector[i];
    int j = i - 2;
    while ((j >= 0) && (vector[j] > aux)) {
      vector[j + 2] = vector[j];
      j -= 2;
    }
    vector[j + 2] = aux;
  }

  // 44 18 12 42 94 55 6 67
  std::cout << "Primera parte: " << std::endl;
  printVector(vector, size);

  ///< Segunda parte Seleccion los elementos de las posiciones pares, mayor a
  ///< menor
  int max;
  for (int i = 0; i < size - 1; i += 2) {
    max = i;
    for (int j = i + 2; j < size; j += 2) {
      if (vector[j] > vector[max]) {
        max = j;
      }
    }
    std::swap(vector[i], vector[max]);
  }
  // 94 18 44 42 12 55 6 67
  std::cout << "\n\nSegunda parte: " << std::endl;
  printVector(vector, size);
}

///< Mezclar las dos subsecuencias de menor a mayor
///< Primera subsecuencia: elementos impares
///< Segunda subsecuencia: elementos pares
void Mezcla(std::vector<int> &vector, int size) {
  int i = 0;            // Elementos pares
  if (size % 2 == 0) {  // Caso que el vector se de tamaño impar
    i = size - 2;
  } else {
    i = size - 1;
  }
  int j = 1;  // Elementos impares
  std::vector<int> aux(size);

  for (int k = 0; k < size; k++) {
    if (i >= 0 && (j > size - 1 || vector[i] < vector[j])) {
      aux[k] = vector[i];
      i -= 2;  // Decrementamos para que vaya de mayor a menor
    } else {
      aux[k] = vector[j];
      j += 2;  // Incrementamos para que vaya de menor a mayor
    }
  }

  for (int k = 0; k < size; k++) {
    vector[k] = aux[k];
  }
}

int main() {
  std::vector<int> vect = {44, 55, 12, 42, 94, 18, 6, 67};

  Ordenation(vect, vect.size());
  Mezcla(vect, vect.size());
  std::cout << "\n\nVector ordenado: " << std::endl;
  printVector(vect, vect.size());
}