#include <iostream>
#include <thread>

#include "MLP/Model_module/perceptron.h"
using s21::Perceptron;
using std::thread;

void run() {}

int main() {
  // Perceptron p(784, 5, 26);
  // p.FillWithRandom();

  // string bin = "CFG/cfg_42_5_40.bin";
  // std::cout << p.UploadConfig(bin) << " UPLOADED\n";

  // string dataset = "/Users/hhullen/PROJECTS/CPP7_MLP-0/src/emnist_set.txt";
  string dataset =
      "/Users/hhullen/PROJECTS/CPP7_MLP-0/datasets/emnist-letters/"
      "emnist-letters-train.csv";

  string test_datadet =
      "/Users/hhullen/PROJECTS/CPP7_MLP-0/datasets/emnist-letters/"
      "emnist-letters-test.csv";

  Perceptron gg(784, 5, 26);
  thread t(&Perceptron::Test, &gg, test_datadet, 1);
  t.detach();

  // std::cout << gg << "\n";

  // gg->FillWithRandom();

  // p.Train(dataset, test_datadet, 0);
  // p.SaveConfig("cfg_42_5_60_0.01.bin");

  // string bin = "/Users/hhullen/PROJECTS/CPP7_MLP-0/src/cfg_e_4_40.bin";
  // std::cout << p.UploadConfig(bin) << " UPLOADED\n";

  // p.Test(test_datadet, 1);

  // p.CrossValidation(dataset, 10);

  return 0;
}
