#include "../src/MLP/Model_module/matrix_implementation/perceptron.h"
using s21::Perceptron;

void matrix_implementation();

int main() {
  Perceptron m_p(784, 2, 26);
  thread *m_thread;

  m_thread = new thread(matrix_implementation);
  m_thread->join();
  delete m_thread;
  return 0;
}

void matrix_implementation() {
  ofstream file("matrix_implementation.txt", std::ios_base::app);
  Perceptron m_p(784, 2, 26);

  m_p.FillWithRandom();
  auto start = std::chrono::high_resolution_clock::now();
  for (int i = 1; i <= 1000; ++i) {
    if (i == 10) {
      auto end = std::chrono::high_resolution_clock::now();
      std::chrono::duration<double> dt = end - start;
      file.write(string(to_string(dt.count()) + " 10 times\n").data(),
                 to_string(dt.count()).size() + 10);
    } else if (i == 100) {
      auto end = std::chrono::high_resolution_clock::now();
      std::chrono::duration<double> dt = end - start;
      file.write(string(to_string(dt.count()) + " 100 times\n").data(),
                 to_string(dt.count()).size() + 11);
    } else if (i == 1000) {
      auto end = std::chrono::high_resolution_clock::now();
      std::chrono::duration<double> dt = end - start;
      file.write(string(to_string(dt.count()) + " 1000 times\n").data(),
                 to_string(dt.count()).size() + 12);
    }
    m_p.Test("../datasets/emnist-letters/emnist-letters-test.csv", 1);
  }
  file.close();
}