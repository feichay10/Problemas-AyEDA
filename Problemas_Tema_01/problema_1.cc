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

int main(int argc, char *argv[]){
  std::string input_string = argv[1];
  std::string output_string;

  for (int i = 0; i < input_string.size(); i++) {
    output_string += input_string[i] + 1;
  }

  std::cout << output_string << std::endl;
}