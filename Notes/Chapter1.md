# Chapter 1: The Basics

Imperative Programming
- Procedural Programming
  - eg C
- Object Oriented Programming
  - eg C++ (but can do other paradigms too)
Declarative Programming
- Functional Programming

Compiled Language
- source files compiled into object files. Linker combines objects into an executable
  - Executables are not portable between OSs
  - src files are portable
- Compile Time -> Link Time -> Load Time -> Run Time

Statically Typed Language
- type must be known at point of use
  - eg variables have type, functions have return type

Core Language Features
- built-in types
  - eg char, int
- loops
  - eg for, while

Standard Library
- containers
  - eg vector, map
- I/O operations
  - eg <<, getline()

Main Function
- `int main(){}`
  - int because returns 0 for success, non-zero for failure
  - only linux might care about this value
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
  - size(char) is 1, bool is 1, int is 4, double is 8

Type conversion
- Heirarchy of Types: int → unsigned int → long → unsigned long → float → double → long double
- First all arithmetic is performed at highest level of precision
  - eg `7 + 15.2` is calculated as `7.0 + 15.2`
- Then smooshes to the type of the left hand side if possible at the end
  - eg `int i=7; i = 2.34*i`
    - i is still an integer after the multiplication
  - eg `int i=7.99;`
    - i will be 7 (truncates, doesn't round)
  - eg `int i = 7.5 + 7.5`
    - i will be 15 (first do arithmetic (at highest precision), then do type truncating)
- Warning: int etc can be truncated to char

Auto type
- automatically determines type from the righthand side
  - useful for lengthy type names like `vector<double>` etc

Arithmetic
- eg `x+y`, `x-y`, `+x` (unary plus), `-x` (unary minus), `x*y`, `x/y`, `x%y` (remainder for ints)
- eg `x+=y`, `x-=y`, `++x`, `--x`, `x*=y`, `x/=y`, `x%=y`

Comparisons
- eg `x==y`, `x!=y`, `x<y`, `x>y`, `x<=y`, `x>=y`

Logical
- eg `x&&y`, `x||y`

Bitwise
- eg `x&y`, `x|y`, `x^y` (bitwise XOR), `~x` (bitwise complement)
- REVIEW
- Yields a result of the operand type for which the operation has been performed on each bit

Initialization Syntax
- classic `=` operator (allows truncating)
- curly-brace `{ }` (called list initialization)
  - eg `double d2 {2.3}`
  - eg `double d2 = {2.3}` (the = is optional/redundant)
  - doesn't allow truncating. does allow expansion (eg `double d {7}` is fine)

Loops
- Range-For-Statements
  - eg `for (auto x : {10,3,8})`
  - eg `int v1[2] = {0,1}; for (auto x : v1)
- `int v[] = {0,1,2}`
  - cannot be initialized without a value, but the value auto determines array length

Scope
- Local Scope, Class Scope, Namespace Scope, Global Scope

Objects
- Class vs Struct (vs enum class vs lambda)
- Making new ones
  - Unnamed: `auto p = new DVD("Bond", 2006);`
    - on the heap with a pointer p of type DVD*
  - Named: `DVD my_dvd("Bond", 2006);`
    - on the stack
  - Array of objects: `Dvd* p = new Dvd[5];`
    - must here do `delete[] p;`, not `delete p`
    - the pointer points to the first object, but C++ arrays 'hide' the array size prior to the first object
    - `delete[]` knows to check backwards for the array size and how many times to call DVD's deconstructor

Constants
- const
  - immutable, locks the value once set (in compile time or run time)
  - allowed to depend on a non-const value (but then won't be a constexp)
  - eg `int var = rand(); /*set at run time*/ const int dmv = 4*var; /*also set at run time because var not set during compile*/`
- constexpr
  - subtype of const (all constexpr are const, not all const are constexpr). STRICTER
  - Value must be known at compile time
- constexpr functions
  - a function which can be evaluated at compile time
    - ie returns a constexpr if arguments are constexpr
  - eg `constexpr double square(double x){return x*x;}`
    - must be just a return statement for simple calculation
  - these functions can be used regular, just wont evaluate to constexpr with regular arguments
- immutability has design benefits
- compile time evaluation can be good for performance






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