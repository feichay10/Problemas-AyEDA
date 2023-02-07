/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Problema 1: Escibra un programa que cambie cada una de las letras
 * presentes en una cadena de texto por la letra siguiente del alfabeto
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

std::string NextLetter(const std::string& input_string) {
  std::string output_string;
  for (int i = 0; i < input_string.size(); i++) {
    if (input_string[i] == 'z') {
      output_string += 'a';
    } else if (input_string[i] == 'Z') {
      output_string += 'A';
    } else {
      output_string += input_string[i] + 1;
    }
  }
  return output_string;
}

int main(int argc, char* argv[]) {
  std::string input_string = argv[1];
  std::string output_string;

  output_string = NextLetter(input_string);

  std::cout << output_string << std::endl;
}