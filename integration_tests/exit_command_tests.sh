#!/bin/sh

echo "This is the exit command test,  input should be exit commands"
g++ ../src/exit_command_test.cpp -o exit_command_tests -std=c++11
./exit_command_tests

rm exit_command_tests



