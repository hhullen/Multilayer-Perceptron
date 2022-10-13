#include "perceptron.h"

using s21::Perceptron;

int main() {
  Perceptron mlp(3, 1, 2);
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

  return 0;
}