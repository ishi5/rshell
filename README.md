# RSHELL project
Ishani Tyagi

# Introduction
Developed a Linux shell from scratch that emulates the linux terminal which reads and implements system calls. This project was done in C++ for the course CS100, Software Construction, at UCR.

# Usage
Commands have the format

```
$ executable [argumentList] [connector] [executable] ...
```

Valid connectors
`||`, `&&` or `;`

The executable can be any executable program located at one of the PATH environment variable locations and the [argumentList] is a list of zero or more arguments separated by spaces.

Anything that appears after a `#` character in the line should be considered a comment

Additionally, the `test` command and it’s symbolic equivalent  `[ ]`  should return 0 (TRUE) if the test succeeds and 1 (FALSE) if the test fails

Parentheses `( )` are implemented as precedence operators to change the precedence of the execution of commands, connectors, and chains of connectors.

# Project Structure

```
├── CMakeLists.txt
├── README.md
├── googletest
├── header
          ├── header_file_1.h
          └── header_file_2.h
├── src
          ├── src_file_1.cpp
          └── src_file_2.cpp
├── unit_tests   
          ├── test_file_1.cpp   
          └── test_file_2.cpp
└── integration_tests
          ├── test_literal_tests.sh
          ├── test_symbolic_tests.sh
          ├── precedence_tests.sh
```

# Installation

```sh
git clone <assignment-repo-url>
cd <assignment-repo-url>
git checkout tags/hw3
git submodule init
git submodule update
```
