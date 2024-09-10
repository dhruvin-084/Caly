# Caly - A C Compiler

Caly is a C compiler being developed from scratch. It features a custom-built lexer and parser, with LLVM as the backend for code generation. The goal is to provide an efficient and modern C compiler for learning and exploring compiler construction concepts.

## Features

- [TODO] **Custom Lexer**: Tokenizes the C code, handling identifiers, literals, keywords, and operators.
- [TODO] **Custom Parser**: Constructs abstract syntax trees (AST) based on C's grammar.
- [TODO] **LLVM Backend**: Uses LLVM to generate optimized machine code from the AST.
- [TODO] **Cross-Platform**: Works on major platforms supported by LLVM.


### Building

1. Clone the repository:
    ```bash
    git clone https://github.com/dhruvin-084/Caly.git
    cd Caly
    ```

2. Generate build files and compile:
    ```bash
    mkdir build
    make
    ```

3. Run the compiler:
    ```bash
    ./caly input.c
    ```