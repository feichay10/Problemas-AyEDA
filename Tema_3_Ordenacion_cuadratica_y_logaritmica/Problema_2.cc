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

#define RED_BOLD "\033[1;31m"
#define GREEN_BOLD "\033[1;32m"
#define CYAN_BOLD "\033[36m\033[1m"
#define PURPLE_BOLD "\033[35m\033[1m"
#define BLUE_BOLD "\033[33m\033[1m"
#define GRAY_BOLD "\033[37m\033[1m"
#define GOLD "\033[33m"
#define ORANGE_BG "\x1B[48;2;255;128;0m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

// 2. Escribe un procedimiento en C++ que ordene de menor a mayor por el método
// de ordenación por inserción los elementos de las posiciones impares entre sí,
// y luego ordene de mayor a menor por el método de ordenación por selección los
// elementos de las posiciones pares, y finalmente mezcle ambas partes.

void printVector(std::vector<int> &vector, int size) {
  for (int i = 0; i < size; i++) {
    std::cout << vector[i] << " ";
  }
  std::cout << std::endl;
}

void Ordenation(std::vector<int> &vector, int size) {
  ///< Menor a mayor - Insercion - Elementos pos impares
  std::cout << BOLD << "\nPrimera parte: " << RESET << std::endl;
  for (int i = 1; i < size; i += 2) {
    int aux = vector[i];
    int j = i - 2;
    while((j >= 0) && (vector[j] > aux)) {
      vector[j + 2] = vector[j];
      j -= 2;
    }
    vector[j + 2] = aux;
  }

  for (int i = 0; i < size; i++) {
    if (i % 2 != 0) {
      std::cout << CYAN_BOLD << vector[i] << " " << RESET;
    } else {
      std::cout << "    ";
    }
  }

  ///< Mayor a menor - Seleccion - Elementos pos pares
  /// En caso de que el iterador se mayor que el size pues que ese iterador sea = al size
  std::cout << BOLD << "\n\nSegunda parte: " << RESET << std::endl;
  for (int i = 0; i < size; i += 2) {
    int max = i;
    for (int j = i + 2; j < size; j += 2) {
      if (vector[j] > vector[max]) {
        max = j;
      }
    }
    std::swap(vector[i], vector[max]);
  }

  for (int i = 0; i < size; i++) {
    if (i % 2 == 0) {
      std::cout << CYAN_BOLD << vector[i] << RESET;
    } else {
      std::cout << "     ";
    }
  }
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
  // std::vector<int> vect = {44, 55, 12, 42, 94, 18, 6, 67};
  std::vector<int> vect = {212, 237, 342, 132, 368, 347, 174, 672, 230, 154};

  std::cout << RED_BOLD << "Secuencia original: " << RESET << std::endl;
  printVector(vect, vect.size());

  Ordenation(vect, vect.size());
  Mezcla(vect, vect.size());

  std::cout << GREEN_BOLD << "\n\nSecuencia final: " << RESET << std::endl;
  printVector(vect, vect.size());
}