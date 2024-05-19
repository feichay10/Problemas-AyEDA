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

// 3. Escribe un procedimiento C++ que aplique el procedimiento de ordenación
// siguiente: se aplica una iteración del método QuickSort para dividir la 
// secuencia en dos partes y se ordena, la primera parte por inserción y la
// segunda por selección

void printVector(std::vector<int> &vector, int size) {
  for (int i = 0; i < size; i++) {
    std::cout << vector[i] << " ";
  }
  std::cout << std::endl;
}

void Ordenation(std::vector<int> &vector, int size) {
  int i = 0;
  int f = size - 1;
  int piv = vector[(i + f) / 2];

  ///< Una iteracion QuickSort para dividir la secuencia en dos partes.
  while (i <= f) {
    while (vector[i] < piv) i++;
    while (vector[f] > piv) f--;
    if (i <= f) {
      std::swap(vector[i], vector[f]);
      i++;
      f--;
    }
  }

  std::cout << "Primera iteración: " << std::endl;
  printVector(vector, size);
}

int main() {
  std::vector<int> vect = {212, 237, 342, 132, 368, 347, 174, 672, 230, 154};

  std::cout << RED_BOLD << "Secuencia original: " << RESET << std::endl;
  printVector(vect, vect.size());

  // Ordenation(vect, vect.size());

  std::cout << GREEN_BOLD << "\n\nSecuencia final: " << RESET << std::endl;
  printVector(vect, vect.size());
}