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
    - `std::x` => x found in standard-library namespace
    - can leave out the `std::` if using namespace line
        - ie header line of `using namespace std;`

Functions
- Use more and shorter functions => less errors, less complexity
- function overloading:
  - two functions have the same name but different argument types
    - compiler picks the best matching one
    - remember, compiler ignores argument names, only sees type
    - eg `void print(int); void print(double);`

Type Sizes:
- Char is equal to 1 (minimum size), which is typically 1 byte but not always
  - size(char) is 1

REVIEW
- The type of a function consists of the return type and the argument types. For class member functions, the name of the class is also part of the function type.

C++ standard algorithms:
- find
- sort
- iota



Terminology
- declaration
- type
  - eg bool, char, int, double, unsigned
- object
- value
- variable