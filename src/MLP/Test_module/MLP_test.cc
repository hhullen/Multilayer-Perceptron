#include <gtest/gtest.h>

#include "../Model_module/matrix_implementation/perceptron.h"
using s21::Perceptron;

TEST(perceptron_test_01, constructor) {
  Perceptron p1(784, 2, 26);
  Perceptron p2(784, 3, 26);
  Perceptron p3(784, 4, 26);
  Perceptron p4(784, 5, 26);

  EXPECT_EQ(p1.IsRunning(), false);
}

TEST(perceptron_test_02, save_upload_function) {
  Perceptron p(784, 5, 26);
  Matrix input(784, 1);

  EXPECT_EQ(p.SaveConfig("TEST_"), true);
  EXPECT_EQ(p.UploadConfig("TEST_784_5_26.wcfg"), true);
}

TEST(perceptron_test_03, run_function) {
  Perceptron p(784, 5, 26);

  p.FillWithRandom();
  p.Run();
}

TEST(perceptron_test_04, cross_validation_function) {
  Perceptron p(784, 5, 26);

  EXPECT_EQ(p.CrossValidation("MLP/Test_module/emnist_set.txt", 3), true);
}

TEST(perceptron_test_05, training_function) {
  Perceptron p(784, 5, 26);

  EXPECT_EQ(p.Train("MLP/Test_module/emnist_set.txt",
                    "MLP/Test_module/emnist_set.txt", 1),
            true);
}

TEST(perceptron_test_06, training_function) {
  Perceptron p(784, 5, 26);

  EXPECT_EQ(p.Test("MLP/Test_module/emnist_set.txt", 1), true);
}

TEST(perceptron_test_07, set_input_function) {
  Perceptron p(784, 5, 26);
  Matrix input(784, 1);

  EXPECT_EQ(p.set_input_neurons(input), true);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}