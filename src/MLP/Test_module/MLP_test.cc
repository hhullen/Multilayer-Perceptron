#include <gtest/gtest.h>

#include "../Model_module/graph_implementation/g_perceptron.h"
#include "../Model_module/matrix_implementation/perceptron.h"
using s21::GPerceptron;
using s21::Perceptron;

TEST(perceptron_test_01, constructor) {
  Perceptron p1(784, 2, 26);
  Perceptron p2(784, 3, 26);
  Perceptron p3(784, 4, 26);
  Perceptron p4(784, 5, 26);

  EXPECT_EQ(p1.IsRunning(), false);
}

TEST(perceptron_test_02, save_upload_function) {
  Perceptron p(784, 2, 26);

  EXPECT_EQ(p.UploadConfig("MLP/Test_module/TEST_784_2_26.wcfg"), true);
  EXPECT_EQ(p.SaveConfig("MLP/Test_module/TEST_"), true);
}

TEST(perceptron_test_03, run_function) {
  Perceptron p(784, 2, 26);

  p.FillWithRandom();
  EXPECT_EQ(p.UploadConfig("MLP/Test_module/TEST_784_2_26.wcfg"), true);
  p.Run();
}

TEST(perceptron_test_04, cross_validation_function) {
  Perceptron p(784, 2, 26);

  EXPECT_EQ(p.UploadConfig("MLP/Test_module/TEST_784_2_26.wcfg"), true);

  EXPECT_EQ(p.CrossValidation("MLP/Test_module/emnist_set.txt", 3), true);
}

TEST(perceptron_test_05, training_function) {
  Perceptron p(784, 2, 26);

  EXPECT_EQ(p.UploadConfig("MLP/Test_module/TEST_784_2_26.wcfg"), true);

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

TEST(graph_perceptron_test_01, constructor) {
  GPerceptron p1(784, 2, 26);
  GPerceptron p2(784, 3, 26);
  GPerceptron p3(784, 4, 26);
  GPerceptron p4(784, 5, 26);

  EXPECT_EQ(p1.IsRunning(), false);
}

TEST(graph_perceptron_test_02, save_upload_function) {
  GPerceptron p(784, 2, 26);

  EXPECT_EQ(p.UploadConfig("MLP/Test_module/TEST_784_2_26.wcfg"), true);
  EXPECT_EQ(p.SaveConfig("MLP/Test_module/TEST_"), true);
}

TEST(graph_perceptron_test_03, run_function) {
  GPerceptron p(784, 2, 26);

  p.FillWithRandom();
  EXPECT_EQ(p.UploadConfig("MLP/Test_module/TEST_784_2_26.wcfg"), true);
  p.Run();
}

TEST(graph_perceptron_test_04, cross_validation_function) {
  GPerceptron p(784, 2, 26);

  EXPECT_EQ(p.UploadConfig("MLP/Test_module/TEST_784_2_26.wcfg"), true);

  EXPECT_EQ(p.CrossValidation("MLP/Test_module/emnist_set.txt", 3), true);
}

TEST(graph_perceptron_test_05, training_function) {
  GPerceptron p(784, 2, 26);

  EXPECT_EQ(p.UploadConfig("MLP/Test_module/TEST_784_2_26.wcfg"), true);

  EXPECT_EQ(p.Train("MLP/Test_module/emnist_set.txt",
                    "MLP/Test_module/emnist_set.txt", 1),
            true);
}

TEST(graph_perceptron_test_06, training_function) {
  GPerceptron p(784, 5, 26);

  EXPECT_EQ(p.Test("MLP/Test_module/emnist_set.txt", 1), true);
}

TEST(graph_perceptron_test_07, set_input_function) {
  GPerceptron p(784, 5, 26);
  vector<double> input(784);

  EXPECT_EQ(p.set_input_neurons(input), true);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
