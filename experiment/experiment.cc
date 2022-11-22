#include <thread>

#include "../src/MLP/Model_module/graph_implementation/g_perceptron.h"
#include "../src/MLP/Model_module/matrix_implementation/perceptron.h"
using s21::GPerceptron;
using s21::Perceptron;
using std::thread;

void matrix_implementation(int r);
void graph_implementation(int r);

int main() {
  thread *m_thread10;
  thread *m_thread100;
  thread *m_thread1000;
  thread *g_thread10;
  thread *g_thread100;
  thread *g_thread1000;

  m_thread10 = new thread(matrix_implementation, 10);
  m_thread100 = new thread(matrix_implementation, 100);
  m_thread1000 = new thread(matrix_implementation, 1000);
  g_thread10 = new thread(graph_implementation, 10);
  g_thread100 = new thread(graph_implementation, 100);
  g_thread1000 = new thread(graph_implementation, 1000);
  m_thread10->join();
  g_thread10->join();
  m_thread100->join();
  g_thread100->join();
  m_thread1000->join();
  g_thread1000->join();
  delete m_thread10;
  delete g_thread10;
  delete m_thread100;
  delete g_thread100;
  delete m_thread1000;
  delete g_thread1000;
  return 0;
}

void matrix_implementation(int r) {
  Perceptron m_p(784, 2, 26);

  auto start = std::chrono::high_resolution_clock::now();
  m_p.UploadConfig("../cfg/cfg_130_2_60.wcfg");
  for (int i = 1; i <= r; ++i) {
    m_p.Test("../datasets/emnist-letters/emnist-letters-test.csv", 1);
  }
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> dt = end - start;
  std::cout << ((size_t)dt.count()) / 3600 << " h " << ((size_t)dt.count()) / 60
            << " m " << ((size_t)dt.count()) % 60 << " s " << r << " times\n";
}

void graph_implementation(int r) {
  GPerceptron g_p(784, 2, 26);

  auto start = std::chrono::high_resolution_clock::now();
  g_p.UploadConfig("../cfg/cfg_130_2_60.wcfg");
  for (int i = 1; i <= r; ++i) {
    g_p.Test("../datasets/emnist-letters/emnist-letters-test.csv", 1);
  }
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> dt = end - start;
  std::cout << ((size_t)dt.count()) / 3600 << " h " << ((size_t)dt.count()) / 60
            << " m " << ((size_t)dt.count()) % 60 << " s " << r << " times\n";
}