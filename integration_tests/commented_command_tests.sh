#!/bin/sh

echo "This is the commented command test,  input should be commented commands"

g++ ../src/commented_command_test.cpp -o commented_command_tests -std=c++11
./commented_command_tests

rm commented_command_tests
