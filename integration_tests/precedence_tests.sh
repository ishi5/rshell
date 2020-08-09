#!/bin/sh


echo "This is the precedence command test,  input should be precedence commands"

g++ ../src/precedence_test.cpp -o precedence_tests -std=c++11
./precedence_tests

rm precedence_tests
