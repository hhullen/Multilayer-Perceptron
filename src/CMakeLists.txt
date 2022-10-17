cmake_minimum_required(VERSION 3.22)
project(Multilayer_Perceptron)

set(CMAKE_CXX_STANDARD 17)

set(PROJECT_SOURCES
  MLP/include/matrix/matrix.cc
  MLP/include/matrix/matrix.h
  MLP/Model_module/perceptron.cc
  MLP/Model_module/perceptron.h
  MLP/Model_module/perceptron_layer.h
)

add_executable(Multilayer_Perceptron main.cc ${PROJECT_SOURCES})
