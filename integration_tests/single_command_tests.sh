#!/bin/sh

echo "This is the single command test,  input should be a single command"
# g++ ../src/single_command_test.cpp ../header/Tokenizer.h ../header/Executor.h -o single_command_tests -std=c++11
cmake3 .
make
./single_command_tests

rm single_command_tests
