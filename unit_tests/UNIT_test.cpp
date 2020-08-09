#include "gtest/gtest.h"
#include "../unit_tests/parsing_test.cpp"
#include "../unit_tests/executor_test.cpp"
#include "../unit_tests/bracketsToTest_test.cpp"


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


 
