cmake_minimum_required(VERSION 3.22)
project(Multilayer_Perceptron)

set(CMAKE_CXX_STANDARD 17)

set(PROJECT_SOURCES
  include/matrix/matrix.cc
  include/matrix/matrix.h
  include/container/vector.h
  Model_module/perceptron.cc
  Model_module/perceptron.h
  Model_module/perceptron_layer.h
)

add_executable(Multilayer_Perceptron main.cc ${PROJECT_SOURCES})
