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

Arrays
- size of an array must be a constexpr

Pointers
- * prefix means "contents of"
  - eg `char* p = &v[3];` means p points to the 4th element of v (so p is an address)
- & prefix means "address of"
  - eg `char x = *p;` means *p is the object p points to

For loops syntax
- eg `for (auto i=0; i!=10; ++i)`
- Range-for-statement
  - eg `for (auto x : v)`
  - like python's `for item in list`

References (vs pointers)
- &
  - don't need * to access the value
  - cannot be reassigned to a new object
- used in function parameter defintions, to ensure the actual object is passed not a copy of it
  - even if argument is not modified can be useful to increase efficiency (no copying)
    - in these cases use const, eg `void function(const double&)`

Declarator Operators
- &, *, []
  - `T a[n];  // T[n]: array of n Ts`
  - `T* p;    // T*: pointer to T`
  - `T& r;    // T&: reference to T`
  - `T f(a);  // T(A): function with argument type A and result of type T`

C-Style Strings
- zero-terminated array of chars

Nullptr
- shared by all ptr types (types with a *)
  - a nonpointer type object cannot be nullptr (`int x = nullptr // ERROR`)
- older code might use 0 or NULL instead of nullptr

 String vs Character literal
 - "" is string, '' is character

 Switch
 - each case must be a constant expression
 - jumps to the case that matches, then does all actions downward until hitting a break

Self-notes
- it is called Random Access Memory because you can access memory spots in O(1) directly whenever
  - eg (in machine code): 
  ```
  assembly
  mov eax, [0x7ffee2d8a4b0]   ; Load x
  add eax, 7                  ; Add 7
  mov [0x7ffee2d8a4b0], eax    ; Store back
  ```
- Pre-increment vs post-increment
  - `int x = 5; int a = ++x; // a = 6, x = 6`
  - `int x = 5; int a = x++; // a = 5, x = 6`
  - in loops, ++i is better because i++ creates a copy before incrementing (usually ignored by compiler but still)
  - [video](https://www.youtube.com/watch?v=bONciSOJ_N4)

- Pointers explanation -- easy incrementing
  - int var = 7
  - int* ptr = &var
    - now if you do ptr+1, it increments 4 bytes (because int* type)
    - *ptr == var
    - *&var == var

- Looping through C strings
  - check if *p != 0
    - this is not checking for the character zero, but the ASCII value
      - ASCII of character zero is 48
      - ASCII of null terminator is 0
  - could do *p != 87 to stop when finding a "W" character (decimal ASCII value of W)
  - could do *p != 0x57 to stop when finding a "W" character (hex ASCII value of W) 

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