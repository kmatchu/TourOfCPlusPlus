# Chapter 1: The Basics

Procedural Programming

Compiled Language
- source files compiled into object files. Linker combines objects into an executable
  - Executables are not portable between OSs
  - src files are portable

Statically Typed Language
- type must be known at point of use
  - eg variables have type, functions have return type

Core Language Features
- built-in types
  - char
  - int
- loops
  - for
  - while

Standard Library
- containers
  - vector
  - map
- I/O operations
  - <<
  - getline()

Main Function
- `int main(){}`
  - int because returns 0 for success, non-zero for failure
  - linux only might care about this value
- Entire program must have exactly one main


Comments
- // or /**/

Libraries
- `#include <iostream>`
  - `<<` function
    - eg `std::cout << "Hello, World!\n"`
