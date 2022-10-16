#include <iostream>

#include "Model_module/perceptron.h"
using s21::Perceptron;

int main() {
  int input_n = 784;
  Perceptron mlp(input_n, 5, 26);
  // mlp.PRINT();
  mlp.FillWithRandom();
  // mlp.PRINT();
  bool save = mlp.SaveConfig("file.bin");
  std::cout << save << "SAVED\n";
  // mlp.PRINT();
  bool load = mlp.UploadConfig("file.bin");
  std::cout << load << "LOADED\n";
  // mlp.PRINT();
  std::cout << "Hello, World!" << std::endl;
  Matrix input(input_n, 1);
  input(0, 0) = 0;
  input(1, 0) = 0;
  input(2, 0) = 00;
  // for (int i = 0; i < input.get_rows(); ++i) {
  //   std::cout << input(i, 0) << "\n";
  // }
  bool is = mlp.set_input_neurons(input);
  std::cout << is << "\n";
  mlp.Run();
  Matrix *mmm = mlp.get_output_neurons();
  for (int i = 0; i < mmm->get_rows(); ++i) {
    std::cout << "mmm" << (*mmm)(i, 0) << "\n";
  }

  return 0;
}
