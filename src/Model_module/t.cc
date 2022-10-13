#include "perceptron.h"

using S21::Perceptron;

int main() {
  Perceptron mlp(3, 1, 2);
  bool save = mlp.SaveConfig("file.bin");
  std::cout << save << "SAVED\n";
  bool load = mlp.UploadConfig("file.bin");
  std::cout << load << "LOADED\n";
  return 0;
}