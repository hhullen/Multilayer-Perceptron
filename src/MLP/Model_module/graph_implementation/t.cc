#include "g_perceptron.h"

using s21::GPerceptron;

int main() {
  // GPerceptron g(784, 2, 26);
  GPerceptron g(2, 1, 2);
  vector<double> v;
  v.push_back(0.6);
  v.push_back(0.3);

  g.FillWithRandom();
  // std::cout << g.SaveConfig("cfg_") << "\n";
  // std::cout << g.UploadConfig("cfg_784_2_26.wcfg") << "\n";
  g.Run();
  // g.Train(
  //     "/Users/hhullen/PROJECTS/github/MLP/datasets/emnist-letters/"
  //     "emnist-letters-test.csv",
  //     "/Users/hhullen/PROJECTS/github/MLP/datasets/emnist-letters/"
  //     "emnist-letters-test.csv",
  //     1);

  // g.CrossValidation(
  //     "/Users/hhullen/PROJECTS/github/MLP/datasets/emnist-letters/"
  //     "emnist-letters-test.csv",
  //     10);

  g.Test(
      "/Users/hhullen/PROJECTS/github/MLP/datasets/emnist-letters/"
      "emnist-letters-test.csv",
      1);

  return 0;
}