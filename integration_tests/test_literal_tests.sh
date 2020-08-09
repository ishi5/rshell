#!/bin/sh


echo "This is the test literal test,  input should be test literal test"

g++ ../src/test_literal_test.cpp -o test_literal_tests -std=c++11
./test_literal_tests

rm test_literal_tests
