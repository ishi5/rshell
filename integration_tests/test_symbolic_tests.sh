#!/bin/sh


echo "This is the test symbolic test,  input should be test symbolic test"

g++ ../src/test_symbolic_tests.cpp -o test_symbolic_tests -std=c++11
./test_symbolic_tests

rm test_symbolic_tests
