#include <iostream>
#include "Model_module/perceptron.h"
using s21::Perceptron;

int main() {
  Perceptron mlp(4, 2, 2);
  mlp.PRINT();
  mlp.FillWithRandom();
  mlp.PRINT();
  bool save = mlp.SaveConfig("file.bin");
  std::cout << save << "SAVED\n";
  mlp.ClearWeights();
  mlp.PRINT();
  bool load = mlp.UploadConfig("file.bin");
  std::cout << load << "LOADED\n";
  mlp.PRINT();
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
