#!/bin/sh

echo "This is the multiple command test,  input should be multiple commands"
g++ ../src/multiple_command_test.cpp -o multiple_command_test -std=c++11
./multiple_command_test

rm multiple_command_test

