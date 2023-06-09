// From Beginning C++17
// SKIPPED: Chp 7 Working with Strings
// SKIPPED: Chp 8 > Passing Arguments to a Function > String Views
// stopped at Chp 8 > Returning Values From a Function

MEMORY LAYOUT
CHARACTERS
FIRST PROGRAM, COMMAND LINE ARGS
COMMENTS
HEADER FILES
PREPROCESSOR
DEFINITION
LIFETIME, SCOPE
FUNDAMENTAL TYPES
LITERALS
C STRINGS
CASTING
OPERATORS
DECISION MAKING
C ARRAY
LOOPS
POINTERS
CONST
REFERENCES
HEAP, STACK
FUNCTION
NAMESPACE
ENUMERATIONS
CLASS
TEMPLATE

STANDARD LIBRARY
IOSTREAM
IOMANIP
CMATH
LIMITS
CCTYPE
ARRAY
VECTOR
MEMORY
CSTRING
STRING


MEMORY LAYOUT
// addresses are a numbering of bytes (8-bits) of memory
// most machines are little-endian
// little endian ->   addr: 0x00 0x01 0x02 0x03    
//                   value: 0xFF 0x10 0xAB 0xAA  represents  0xAAAB10FF 
// little endian stores least-significant bytes at smallest addresses

CHARACTERS
// ASCII - 7-bit chars, so 128 of them
// Latin-1 is 8-bit ASCII, 255 of them
// UTF-8, UTF-16, UTF-32 are char encodings for Unicode
// there are 96 chars in the basic source character set, to write code in
// you can add in Unicode chars
// -----
// contains a unicode char as a variable
// /Udddddddd is another hex format for unicode
int \u30AD = 42;   
// -----
// escape sequence
\n, \t, \v, \b, \r, \f, \a, \\, \single-quote, \dbl-quoste
// -----
// everything inside the first " and last " is sent to the output stream
// these chars are a string literal, the quotes are delimiters they are not part of the string
// each escape sequence is converted to the character by the compiler
std::cout << "\n\t \"Hello\"" << std::endl;
// -----
// char literal
'a'
char c {33};   // ASCII '!', although encoding depends on compiler
// -----
// 3 digits is in octal
'\101'   // A or 65 in ASCII, in octal
'\x41'   // A ASCII in hex  
// -----
// can apply integer operations:
++, --, +=, etc
char ch {'A'};
char c = ch + 5;
++ch
// -----
// can also static_cast<int>() to an int, see CASTING 
// -----
// wide characters of wchar_t use L prefix
wchar_t w {L'A'};
L'Z'   // wchar_t
L'\x0438'   // hexadecimal escape version of an extended character
// -----
// UTF-16 literals use u
char16_t c {u'B'};
u'\x0438'
// -----
// UTF-32 literals use U
char32_t c {U'B'};
U'\x044f'
// -----
// in boolean expressions
char a {'a'}, z {'z'};
bool b = a < z;   // true by ASCII int incoding values

FIRST PROGRAM, COMMAND LINE ARGS
// compile:
// > cl /EHsc /W4 /std:c++17 test.cpp   // /MDd for _DEBUG, /EHsc for exceptions, /W4 for warning level
// run:
// > ./test
#include <iostream>   // contains std::cout and std::endl;
int main() {    // execution always starts here, in this main function
	std::cout << "Hello" << std::endl;   // endl flushes the stream, ensures data is sent to console immediately
	return 0;   // can return nonzero to indicate an abnormal exit, return for main() is optional
}	
// -----
// preprocessor replaces #includes with the header file contents and resolves the other directives
// .cpp is transformed into an object file that contains machine code
// linker combines object files and possibly other libraries into an executable program
// you can compile source .cpp files seperately into seperate obj files
// -----
// main with arguments sent from the command line
// compile and then run with command:
// > ./test Ben Harki
// can only have these parameters or none at all
// argv is an array of pointers, each is assumed to point to a C-String 
// argv[0] is the name of the program, argv[argc] is nullptr (which does not print as a char* value)
#include <iostream>
int main(int argc, char* argv[]) {  
  std::cout << "argc is " << argc << std::endl;  // argc is 3 so argv has 4 elements when including nullptr
  for (int i {}; i <= argc; ++i) {   // argv has argc+1 elements when including nullptr
    std::cout << argv[i] << std::endl;
  }
}

COMMENTS
// single line comment
/* multi-line
   comment    */

HEADER FILES
// contains function prototypes and definitions for classes and templates
 
PREPROCESSOR
// preprocessor directives cause the source code to be modified in some way before compilation
// #include directives are replaced with the contents of the file they include
#include <iostream> 

DEFINITION
// variable names can contain a...z, A..Z, 0..9, _
// variables must begin with a letter or _
// cannot use vars that begin with __, underscore uppercase like: _A_bad_var,
// cannot use vars that begin with underscore in global namespace
// these names could clash with compiler generated names
// in C++17, you can used braced initialization to initialize with a single value
// 		as long as you do not also combine it with an assignment
// ----- 
// a variable is named portion of memory that stores a value
// braced initializer with {} called uniform initialization
// braced initializer with {} called uniform initialization
// everything is initialized in nearly the same way using uniform initialization
int i {32};   // defined and initialized
// -----
// variable is definied, not assigned, contains junk value
// zero initialization with {}, for any fundamental type
int i;   
int j {};   // initializes with 0, or equivalent
// -----
// initial value can be an expression
int i{0};
int j{1};
int k{i + j};
// -----
// compiler will try to convert the type if they are not the same
// narrowing conversion, since the decimal portion is truncated
// {} will give at least a warning, maybe an error, on narrowing conversion
float f{3.14};
int i{f};
// -----
// initialzers with functional notation and assignment notation
// do not usually detect narrowing conversion
int i(32);
int i = 64;
// -----
// multiple declarations/initializations on one line
int i{0}, j{1}, k;
// -----
// compiler will perform narrowing conversion can also happen in assignment
int i {};
double j {5.5};
i = j;   //  i is 5, may issue a warning
// -----
// auto asks the compiler to deduce the type
// can also use assignment and functional notation for initialization
auto m  = 10;  // integer, with no suffixes
auto s = 3.14;  // double with no suffixes
auto n = 200000UL  // unsigned long by suffixes
// -----
// should generally avoid using an initializer list with auto, unless you are definitely using c++17
auto x {10}   // std::initializer_list<int> in c++14, int in c++17
auto l = {1,2,3}  // std::initializer_list<int> in both
auto d {1,2,3}   // std::initializer_list<int> in c++14, does not compile in c++17
// -----
// using can define type alias
// easier syntax to remember than typedef below
using BigOnes = unsigned long long;   // if BigOnes needs to change, you only need to change it here
BigOnes b {};   // uses the new alias
// -----
// typedef is a carryover from C that also defines an alias
typedef unsigned long long BigOnes;
// -----
// empty or null statements are allowed mostly everywhere, 
// can lead to errors when incorrectly combined with valid statments, see DECISION MAKING
#include <iostream>
int main() {  
  ;;;;;;;
}

LIFETIME, SCOPE
// lifetime is the period of time in which the variable is alive, scope is how long it is valid to use in the program
// local variables (also called automiatic variables) have block scope
// non-static variables defined in a block are destroyed at the end of the block }
int main() {
	int i {1};   
}
// -----
// static variables exist at the point they are defined and destroyed at the end of the program
// dynamic allocation of a variable at runtime is destroyed by the user-defined
// thread_local is related to the storage of a variable in a thread
// -----
// global variables have global scope, or global namespace scope
// defined outside all functions, can be accessed by all functions, throught the entire source file
// they have static storage so their lifetime the start of the program until the end
// they are zero-initialized by default, not garbage valued, before the execution of main
// global variables are hidden when another variable of the same name is used in local function scope
// use global namespace :: to see the hidden global variable if this is the case
// can also mutate globals if they are not const
#include <iostream>
void see_globals();
const int global {};  // best to make globals constant
int my_mutable {};  // 0
int main() {  
  std::cout << "in main(): " << global << std::endl;
  see_globals();
  const int global {3};  // hides the original global, since it has the same name
  std::cout << "in main(): global = " << global << std::endl;  // 3, since orig was hidden
  std::cout << "in main(): global = " << ::global << std::endl;   // 0,  now orig is visible and incremented
  ++my_mutable;
  std::cout << my_mutable << std::endl;  // 1
}
const int global2 {2};   // only visible in functions defined afterward
void see_globals() {
  std::cout << "in see_globals(): " << global << ", " << global2 << std::endl;
}
// -----
// scoping example with no globals, and with hiding
// hiding can "nest", in that you can hide a variable in any outer scope 
//   by redeclaring with the same name in amy nested inner scope
#include <iostream>
int main() {  
  int x {};
  std::cout << "x = " << x << std::endl;   // 0
  {
    int x {1};  // hides previous
    int y {2}; 
    std::cout << "x = " << x << std::endl;   // 1
    std::cout << "y = " << y << std::endl;   // 2
    {
      std::cout << "x = " << x << std::endl;  // 1, outer scope var is visible, but only closest
      std::cout << "y = " << y << std::endl;  // 2 
      {
        int y {3};  // hides y from two scopes back
        std::cout << "x = " << x << std::endl;  // 1
        std::cout << "y = " << y << std::endl;  // 3
      }
    }
  }
  // std::cout << "y = " << y << std:endl;   // y is out of scope
  std::cout << "x = " << x << std::endl;  // 0, only outer scope is visible, as inner scope vars are destroyed
}

FUNDAMENTAL TYPES
// signed integers and typical sizes
// signed keyword is optional to everything except char
// char is signed or unsigned, depending on the compiler, can check the CHAR_MIN in climits to tell
signed char,     // 1 byte
short, short int, signed short, signed short int    // 2 bytes
int, signed, signed int     // 4 bytes
long, long int, signed long, signed long int   //   4 or 8 bytes
long long, long long int, signed long long, signed long long int   // 8 bytes 
// -----
// integers can also be unsigned
// have the same sizes as above
unsigned char, unsigned short, unsigned (unsigned int), unsigned long, unsigned long long
// -----
// size_t is defined in <cstddef>, designed to work in any compiler
// generally <cstddef> is already included in other headers like <iostream>, so it does not usually need a seperate #include
// it is an alias for a universal unsigned integer
size_t  
// -----
// sizeof obtains the number of bytes of memory occupied by a type, variable, or result of expression
// returns a size_t value
#include <iostream>
int main() { 
  unsigned short i {32};
  std::cout << sizeof(long long) << std::endl;   // 8 bytes
  std::cout << sizeof i << std::endl;  // can also use () if you want
  std::cout << sizeof(const int *const) << std::endl;  // 4 bytes
}
// -----
// floating point types:
float, double, long double   // they are never unsigned
// precision and range are dependent on compiler and processor
// most compilers use IEEE standard of precision: 
// float 7 decimal digits, double nearly 16 digits, long double is about 18 or 19 digits
// beware of catastrophic cancelation which occurs in subtracting nearly identical values, differ in a small decimal digit 
// avoid working with values that differ by many orders of magnitude: 10e8f + 1f
// any fraction with an odd denom cannot be represented exactly as a binary floating point value  
// -----
// implict conversions occur in binary arithmetic operands 
// value of more limited type is converted to the other
// ex: 3.4 + 3, converts 3 to a double
// all char types are at least converted to an int
// ranking of types, from more limited to less limited:
int, unsigned int, long, unsigned long, long long, unsigned long long, float, double, long double
// -----
// overflow and underflow is undefined, so the result is dependent on compiler
// here an implicit conversion leads to underflow
// int 30 converts to unsigned int: 20 - 30 
// this is a negative unsigned int 2^32 - 10, so it wraps around to largest unsigned int side  
#include <iostream>
int main() {
  unsigned int x {20u};
  int y {30};
  std::cout << x - y << std::endl;   // int implicity converted to unsigned
}
// -----
// see CHARACTER
wchar_t  // wchar_t stores all members of the largest extended character set in a given implementation  
char16_t  // UTF-16 better for international characters
char32_t  // UTF-32 
// -----
// boolean type
// can use std::boolalpha to print true, false instead of 1, 0
// can also static_cast to an int, or to a bool (non-zero's to true, zero to false)
bool t {true}, f {false};
bool f1 {};   // false using brace default initialization
std::cout << t << ", " << f << std::endl;  // 1, 0 since they are int values by default
std::cout << std::boolalpha << t << ", " << f << std::endl;   // true, false
std::cout << static_cast<int>(t) << std::endl; 
bool x = 3;   // implicit conversion by compiler to true

LITERALS
// literals are constant values
// -----
// without suffixes any whole numbers are by default an int
// integer literal suffixes:
u U, l L, ll LL,   // unsigned, long, long long
// -----
// base-10 examples
// compiler will convert to the variable type
// may throw an error or warning if there is narrowing conversion 
// literals are needed for auto keyword, if you want a specific type
-123ULL  // can have +, -, prefix
2'333'000LU   // can use ' for readability of large integers
short s {32};  // 32 is by default an int, converted to a short by compiler
int i {32U};   // compiler will convert unsigned int to signed int, if there is no narrowing conversion  
unsigned char {2000};  // narrowing conversion, largest char is 255
auto j {32U};  
// -----
// hexadecimals are written with digits 0,...,9,a,...,f or A,...,F
// 0xFF is one byte, 8-bits, 0b1111'1111 
// hexadecimal integers have prefixes:
0x, 0X
// suffixes of:
u U, l L, ll LL,   // unsigned, long, long long
// -----
// hex examples:
0Xaaa
0xAA'EA'99UL  // unsigned long 
// -----
// octal has an 0 prefix and suffixes:
u U, l L, ll LL
077U  // unsigned example
// -----
// binary has prefixes 0b, 0B, and suffixes:
u U, l L, ll LL
0b1111'1010'1111ULL   // unsigned long long, can use '
// -----
// float literals are double by default with no suffixes
// suffixes:
f F, l L
// ------
// examples, including scientific notation with E, e
3.14f, 1.41L, 3.14e5, 2.5e-2L, .333
// -----
// conversion, possible narrowing conversion
float f {3.14};   // double is automatically converted to a float by compiler
float f2 {1.4142135623730950488L};   // narrowing conversion, > 7 digits
// -----
// a/0, 0/0, +-infinity, NaN
// example of some of these "values"
// these are created from divisions of zero, see LIMITS 
#include <iostream>
int main() {
  double a{1.5}, b{}, c{};
  double result {a / b};
  std::cout << a << "/" << b << " = " << result << std::endl;    // 1.5/0 = inf
  std::cout << result << " + " << a << " = " << result + a << std::endl;  // inf + 1.5 = inf
  result = b / c;
  std::cout << b << "/" << c << " = " << result << std::endl;   // 0/0 = -nan(ind)
}  
// -----
// see CHARACTER for char and wchar_t literals
// -----
// bool literals
true, false

C STRINGS
// terminate with '\0' null
// initializations of C-String
#include <iostream>
int main() {
  char n[10] {};    // all null chars
  char name[10] {'B', 'e', 'n'};   // remaining are null chars  
  char no_null[3] {'B', 'e', 'n'};   // no null chars, not a C-string
  char no_null2[] {'B', 'e', 'n'};   // compiler does not add a null, when initialized like this
  char name2[10] {"Ben"};  // with a string literal, that automatically adds null chars for remaining
  // char name3[3] {"Ben"};   // no null char, some compilers consider this an error
  char name4[] {"Ben"};   // compiler sets the size, with a null char
  // std::cout << name3 << std::endl;   // array bounds overflow, since no /0
  std::cout << name4 << std::endl;   // print using the pointer
}
// ------
// loop terminating using the \0 char
// also uses indices and not the pointer, two versions
#include <iostream>
int main() {
  char name[] {"Ben Harki"};
  for (int i {0}; name[i] != '\0'; ++i) {
    std::cout << name[i] << std::endl;
  }
  for (int i {}; name[i]; ++i) {   // '\0' converts to bool false
    std::cout << name[i] << std::endl;
  }
}
// -----
// array of C-Strings (multidimensional char array)
// 2 rows, 10 cols
// std:size() determines how many C-Strings, access by an index
// range-for loop
#include <iostream>
int main() {
  char names[][10] {"Ben Harki", "Magdalene"};
  for(auto name: names) {
    std::cout << name << std::endl;
  }
  std::cout << "There are " << std::size(names) << " names" << std::endl;  
  std::cout << names[1] << std::endl;
}
// -----
// initialize a C-string with a char*
// pname contains the address of the first char 
// string literal is const so this is const !-> non-const (cant' convert from const to nonconst)
#include <iostream>
int main() {
  // char* pn {"Ben Harki"};   // string literal is const, so char* should point to a const
  // *pn = 'X';  // will actually compile but freezes in MSVC, runtime error
  const char* pname {"Ben Harki"};  // proper way to initializa with string literal
  // *pname = 'X'   // pname points to 'B', try to chane the char, but is properly const now
  std::cout << pname << std::endl;
}


CASTING
// implicit conversion by the compiler is in DEFINITION
// static cast is an explicit cast at compile time, can take variables or expressions
// if the statement was i = d instead, it would be an implicit narrowing conversion, with a warning
// static_cast allows you to tell the compiler that the conversion is intensional
// chars can be cast to int to see their ASCII
#include <iostream>
int main() {
  int i {};
  double d {3.14};
  i = static_cast<int>(d);   // does not affect the value of d, returns a temporary value converted appropriately
  std::cout << i << std::endl;   // 3
  std::cout << static_cast<int>(3.14 - 6.778 * 2.11) << std::endl;  // -11
  std::cout << static_cast<int>('A') << std::endl;
}
// -----
// C-Style cast, should not be used ever
// covers all of C++ casts, bu difficult to differentiate which one it uses
#include <iostream>
int main() {
  int i {};
  double d {3.14};
  i = (int) (d);   // C cast
  std::cout << i << std::endl;   // 3
}

OPERATORS
// most operators are left to right under equal precidence
// unary operators, assignment operator, and operator ?: are right to left under equal precidence
// -----
// bitwise operators
// can apply to any integer type, including char types
// can also be used in if conditionals, see DECISION MAKING
// in general you should apply >> to unsigned bc the program is undefined when applied to signed: 
// 		could back fill on the left with 0's or 1's depending on compiler using >>, could mess with left-most sign bit
// all have an op= assignment
&, |, ^, <<, >>, ~
// -----
// technically no bitwise ops exists for integer types smaller than int
// so they are implicitly cast to int by compiler on evaluation of expression
// is cast back to a short
#include <iostream>
int main() {  
  unsigned short x {0x9};   // 0b1001
  auto r = static_cast<unsigned short> (x << 1);   // 0b10010 = 0x12, avoids compiler warning
  std::cout << std::hex << "0x" << r << std::endl;
}
// -----
// xor is false when the bools have the same truth value
// like or except that when both are true, ^ is false 
// xor accepts anything that is convertible to bool
// bools are implicitly converted to ints for ^, then back to a bool for boolalpha
#include <iostream>
int main() {
  bool t {true}, f {false};   
  std::cout << std::boolalpha << std::endl;
  std::cout << (t ^ t) << std::endl;  // 0
  std::cout << (t ^ f) << std::endl;  // 1
  std::cout << (f ^ t) << std::endl;  // 1
  std::cout << (f ^ f) << std::endl;  // 0
}
// -----
// arithmetic
+, -, *, /, %
// -----
int i {3/2};  // i = 1, integer division, so it is truncated
// -----
// assignment operator =
int i{16}, j{};
j = i * 2   // i*2 is evaled and assigned to j
// -----
// multiple assignment in one line
// right to left
int a{}, b{}, c{5}, d{4};
a = b = c*c - d*d   // stored into b theninto a
// -----
// op= assignment
+=,, -=, *=, /=, %=
i += 1   // same as i = i + 1
// -----
// ++, -- prefix form
// incr/decr of value executes before any other binary arithmetic operator does 
++i  // like i += 1
int count{0};
sum = ++count + 6;  // sum = 7  
// -----
// ++, -- postfix form
// incr/decr after it applies its value in the expression
// sum = count++ + 6 is equivalent to sum = count + 6; ++count; 
#include <iostream>
int main() {
  int count{0}, sum{};
  sum = count++ + 6;  // sum = 6, count = 1
  std::cout << "sum = " << sum << std::endl;  // 6
  std::cout << "count = " << count << std::endl;  // 1
} 
// -----
// undefined when incr/decr the same variable more than once in an expression
// generally do not want to read a variable again after it has been modified in the same expression
sum = count++ + 6 + ++count
k = k++ + 1   // used to be undefined, but is now defined in c++17 (rhs side effects are committed before lhs assignment)
// -----
// relational operators, by default it returns bool
<, <=, >, >=, ==, !=,   
bool t {true}, f {false};
int i {0}, j {1};
bool b {i < j};   // i < j is an expression that return a bool 
std::cout << (j < i) << std::endl;  // parens are necessary 
// -----
// logical operators return a bool (cout prints as an integer), accepts anything convertible to a bool
// has short-circuit property, see DECISION MAKING
&&, ||, !   
int t {'t'};
if (t == 't' || t == 'f') {
	std::cout << "convert to bool" << std::endl;
}
// -----
// logical operators can be applied to integers
0 && 1    // 0, same as false
0 || 2    // 1, same as true
// -----
// conditional operator (ternary operator) ?: returns a value from either branch, depending on the condition
// can be used in assignment, or as an unnamed expression
// condition will also accept anything that converts to a bool, like an int
// can also nest conditional expressions in the if or else blocks of another conditional expression
#include <iostream>
int main() {
  int t {1}, f {0};
  int b = t > f ? t : f; 
  std::cout << b << std::endl;
	std::cout << (t > f ? "true" : "false") << std::endl; 
}
// -----
// conditional operator
// in relation to a division calculation
// if bottom is zero then undefined operation div by 0 is skipped
#include <iostream>
int main() {
  int top {1}, bottom {};
  int result = bottom ? (top / bottom) : 0;
  std::cout << "dividing by zero, returned: " << result << std::endl;
}
// -----
// comma operator can be used anywhere an expression is used
// combines two expressions into a single expression
// left associative: ((++i, ++i), ++i)
// returns the value of the righthand expr
#include <iostream>
int main() {
  int i {};
  int three = (++i, ++i, ++i);
  std::cout << three << std::endl;    // 3
}
// -----
// see POINTERS for & addr-of operator and * indirection
*
->  // indirect member selection operator
// -----
// & on lhs is a reference, & on the rhs is the addr of operator, see REFERENCES
int i {};
int* pi {&i};   // addr of
int& ri {i};   // reference
// -----
// see HEAP, STACK
new, delete

DECISION MAKING
// executes statement inside if block, when the boolean condition is true
// if block {} are optional if there is only one statement in it
// can also nest if's, like if (cond1 && cond2 && ...)
#include <iostream>
int main() {  
  char letter {'a'};
  if (letter == 'a') {
    std::cout << "Hello!" << std::endl;  
  } 
}
// -----
// be careful with null statements, they can mess with if()
// ; here makes cout statement always execute, instead of conditionally execute 
char letter {'a'};
// if (letter == 'A'); std::cout << letter << std::endl;
// -----
// if applied to a bool condition
bool tru = true;
if (!tru) std::cout << "false" << std::endl;
// -----
// compiler will convert if condition into a bool
int value {3};   // any non-zero is converted to true
if (value) std::cout << true << std::endl;
// -----
// if-else, can be nested, should use braces, to avoid else-attachment confusion
// else is always attached to the closest if, as long as that if does not already have an else
int v {1};
if (v) {
	std::cout << "true" << std::endl;
}
else {
	std::cout << "false" << std::endl;
}
// -----
// if else if, when the cases/conditions are mutually exclusive
int val {213};
if (val % 3 == 0) {
	std::cout << "LOW" << std:endl;
}
else if (val % 3 == 1) {
	std::cout << "MED" << std::endl;
}
else {
	std::cout << "HI"<< std::endl;
}
// -----
// using ||, !, && operators, (comparisons return bool)
// these operators have the ability to only need to partially evaluate the condition expression:
//    when the truth value from the condition can be infered early
int one {1}, ten {10}, zero {};
if (one < ten && zero < one) {    // one < ten && zero < one = true && true = true
	std::cout << "this prints!" << std::endl;
}
if (one > ten && zero < one && 0 < ten) {  // shorts circuits the eval of condition, returns false after one > ten
	std::cout << "this will not print"<< std::endl;
}
// -----
// can use bitwise &, |, ^ but it involves a few implicit conversions
// does not have the short-circuit property of logical operators &&, ||
int one {1}, ten {10}, zero {};
if (one < ten & zero < one) {    // one < ten & zero < one = true & true = 1 & 1 = 1 = true
	std::cout << "this prints!" << std::endl;
}
// -----
// switch statement with braces and without
// cases are determined by integer or enum values
// can only switch on values of enums or integral (integer-like types) including chars
// or those that convert to ints, like a bool or snum
// cannot switch on strings or other type then described above
// defaults can appear in anywhere among the cases, or does not need to appear at all
// with no default the switch will do nothing when a case does not match
// break automatically breaks out of the entire switch block, no matter how nested
// in a case without a break, execution will bleed into the next case
// can also exit the case block with a return
// switches can also use initialization statements, see a similar if-else example below
#include <iostream>
enum class Level {HIGH, MED, LOW};
int main() {
  Level choice {Level::LOW};
  int result {};
  switch (choice) {   // simple one without braces
    case Level::HIGH:
      std::cout << "on" << std::endl;
      break;
    case Level::LOW:
      std::cout << "off" << std::endl;
      break;
    default:
      std::cout << "incorrect option" << std::endl;
      break;   // don't technically need a break in the default case
  }
  switch (choice) {
    case Level::HIGH: {   
      result = 100;
      break;      // break can also go in line outside the brace, in same column as case
    }
    case Level::MED: {
      result = 50;
      break;
    }
    case Level::LOW: {
      result = 10;
      break;
    }
    default: {
      result = 0;
      break;
    }
  }
  std::cout << result << std::endl;
}
// -----
// case values must at least be constant expressions, like const or literals (which are const by default)
// all case values must be of the same type
// cases must have unique case values, but can have the same action in the multiple cases's
// cases without a break, execution falls through to the next block
#include <iostream>
int main() {
  const int three {3}; 
  int num = 4;
  switch (num) {
    case three:    // three variable must be const, or this does not compile
      std::cout << "You guessed the const variable" << std::endl;
      break;
		case 1: 
      std::cout << "You guessed the literal" << std::endl;
      break;
    case 100: 
      [[fallthrough]];   // fallthrough attribute may quiet any compiler warnings of fallthrough cases 
    case 12/3:       // can also add [[fallthrough]] here, but not required
    case (1+3)/2:
      std::cout << "You guessed the const expression" << std::endl;
      break;
    default:
      std::cout << "NOPE" << std::endl;
      break;
  }
}
// -----
// if there is no subscope declared in a case block using braces, then initialization can be rejected by the compiler
// initialization in the default case, without braces, is ok, if default is the last case
#include <iostream>
int main() {
  int num = 1;
  switch (num) {
		case 1: 
      // int i {0};   // needs braces or initiialization could be bypasses, since it is not in a nested scope
      // std::cout << i << std::endl;
      break;
    case 2: {
      int i {0};
      std::cout << i << std::endl;
      break;
    }
    default:
      int j {1};   // no braces here is ok, even without braces
      std::cout << j << std::endl;
      break;
  }
}
// -----
// i is in scope after the if, when it is not needed afterwards, so it is limited with another scope inside {}
// can use an initialization statement in c++17 to do the same thing
// variables in the initialization statement can be used in the condition and in the block
// init statement vars are defined first, and are local to the if or if-else block
// TODO: can also similarily use initialization statement in switch
// can have multiple initializations as a list, see for loop example in LOOPS
#include <iostream>
int main() {
  {
    int i {1};
    if (i == 1) {
      std::cout << i << std::endl;
    }
  }  // i is destroyed here
  if (int j {2}; j == 1) {   // if with an initialization statement
    std::cout << j << std::endl;
  }
  else {
    std::cout << j << std::endl;  // init statements can also be used in the else 
  }
}


C ARRAY
// variable that represents a sequence of memory locations
// size of array must be at the very least a  constant integer expression that is evaled at compile time
//   like consts or literals, or an expression of literals, etc.
// initalizer list must be of the same size as the array size (or the size is left blank)
#include <iostream>
int arr[4];    // defined globally zero-initialized them
int main() {
  int grades[100];    // contains garbage vals  
  grades[0] = 95;   // replace the garbage value at index 0
  std::cout << grades[0] + 5 << std::endl;
  unsigned int heights[6] {26, 37, 47, 55, 62, 75};   // initialization list
  unsigned int heights2[6] {26, 37, 55};   // the remaining 3 are zero-initalized
  unsigned int zero_heights[6] {};  // entire array of zeros
  const unsigned int const_heights[] {26, 37, 47, 55, 62, 75};   // without [], values cannot be changed
  // const_heights[0] = 2;   // error
}
// -----
// can find the size of an array using std::size
// technically std::size() is in the <iterator> header, which is included in <iostream>
// you don't to need add <iterator>
// <iterator> is a part of <array> and others, so it makes sense to add <array> too, but its also not necessary
// also C style size calculation using sizeof()
//   num of bytes of entire array / num of bytes of one element   
#include <iostream>
#include <array>
int main() {
  int nums[] {1,2,3,4,5,6};   // [] with size() avoids intitializing with too many
  std::cout << std::size(nums) << std::endl;
  std::cout << sizeof(nums) / sizeof(nums[0]) << std::endl;  // C-style size
}
// -----
// counts how any within a threshold of an array, without using an if
// < returns a bool, of 1 when true, count is then incremented by 1
#include <iostream>
int main() {
  const unsigned N {3};
  const unsigned heights[N] {90, 92, 86};
  unsigned count {};
  for(size_t i {}; i < N; ++i) {
    count += (heights[i] < 92); 
  }
  std::cout << count << std::endl;
}
// -----
// multi-dimensional array, [][] is [rows][cols]
// set in memory row by row:
//     size [2][3] , elements: [0][0], [0][1], [0][2], [1][0], [1][1], [1][2]
// uses size() and not literals in the loop condition
// mult_array is a pointer
#include <iostream>
int main() {
  int num {};
  const int I{3}, J{4}, K{5};
  double mult_array[I][J][K] {};   // 3 x 4 x 5 = 60 elements, all initialzed to 0
  for (unsigned i {0}; i < std::size(mult_array); ++i) {
    for (unsigned j {0}; j < std::size(mult_array[0]); ++j) {   // also a pointer, size of the 1st row array (# of cols)
      for (unsigned k {0}; k < std::size(mult_array[0][0]); ++k) {   // also a pointer
        mult_array[i][j][k] = num;
        ++num;
        std::cout << mult_array[i][j][k] << std::endl;
      }
    }
  }
}
// -----
// manually initialize multi-dim array using {{}}
// can also initialize in one big initializer list, places them one after another in memory
// if the dimension sizes of the initialization lists and declaration differ
//   then the remaining are zero-initalized 
// can leave for the compiler determine a dimension, but only the left most sizeof a multi-dimensional array
//    basically it knows takes unknown explcitly from the init list
// see another example of a multi-dim array as a function parameter, see FUNCTION
#include <iostream>
void print_arr(int I, int arr[][2][3]) {
  for (int i {0}; i < I; ++i) {
    for (int j {0}; j < 2; ++j) {
      for (int k {0}; k < 3; ++k) {
        std::cout << arr[i][j][k] << ' ';
      }
    }
  }  
  std::cout << std::endl;
}
int main() {
  const int I{2}, J{2}, K{3};
  int marr[I][J][K] {
    {
      {0, 1, 2},     
      {3, 4}     // any elemes left out are zero-intialized
    },
    {
      {6, 7, 8}, 
      {9, 10, 11}
    }
  };
  print_arr(I, marr);
  int marr2[I][J][K] {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9};   // remaining are zeros
  print_arr(I, marr2);
  int marr3[][J][K] {
    {
      {0, 1, 2},     // K = 3, J = 2  
      {3}
    },
    {
      {6}   // without this, it assumes i = 1, adds another "row" of zeros
    }
  };
  print_arr(I, marr3);   // initializes 
}
// -----
// pointers and arrays are not exactly the same thing, but similar
// array name behaves like a pointer when using cout, in that it displays the addr of the first elem
// however nums is not a true pointer since you cannot give it another address, see POINTERS
#include <iostream>
int main() {
  int num {32};
  int nums[10] {};
  int* pnums {nums};   // no need for & operator for array
  std::cout << nums << std::endl;  // addr of first int
  std::cout << pnums << std::endl;  // same addr
  // nums = &num;   // cannot store another addrs in nums
}
// -----
// see index notation vs deref pointer notation in POINTERS

LOOPS
// for loop has init expr, condition, incr
// can omit any of the three above but still needs ;
// init happens only once, at the beginning, condition is checked, if true, for block executes
//   then incr/decr, then condition check ... when condition is false, execution continues after for block 
// can access values outside of the array bounds, but should not since it could lead to an error 
// don't need braces if the for block is one statement
#include <iostream>
int main() {
  const size_t N = 5;  
  int arr[N] {1, 2, 3, 4, 5};   // N needs to be const
  for(size_t i {0}; i < N; ++i) {  // size_t  is a universal unsigned
    std::cout << arr[i] << std::endl;
  }
  // std::cout << arr[5] << std::endl;  // outside the bounds, will compile with no warning/error
  size_t i {};   // i will be in scope after the loop
  for( ; i < N; ++i) {
    std::cout << arr[i] << std::endl;
  } 
  std::cout << i << std::endl;  // 5, since 5 !< N 
}
// -----
// tradiitional sum and a sum through the incr of a for loop
// needs postfix i++, since it needs sum[i] needs read first, then incremented
// also a floating point loop, with a non-int increment
// be careful with a condition based on a float: 2.00000000001 from a calculation could make it shortcut a <= 2 condition 
//   in general be careful with ==, <=, and >= conditions for the same reason
#include <iostream>
#include <array>
int main() {
  int sum1 {}, sum2 {};
  const int nums[] {1,2,3,4,5,6};   // [] with size() avoids intitializing with too many
  const size_t N {std::size(nums)};
  for(int i {}; i < N; ++i) {
    sum1 += nums[i];
  }
  for(int i {}; i < N; sum2 += nums[i++]) {}   // can also write by replacing {} with ;
  std::cout << sum1 << ", " << sum2 << std::endl;
  std::cout << "[ ";
  for(double i {1}; i < 2; i += 0.1) {  
    std::cout << i << " ";
  } 
  std::cout << "]" << std::endl;
}
// -----
// backwards through an array
// if unsigned instead of int then for loop is infinite
//   decr: i = 5,...,0,0xFFFFFFFF -> never under 0
#include <iostream>
int main() {
  int nums[] {0,1,2,3,4,5};
  for (int i {std::size(nums)-1}; i >= 0; --i) {
    std::cout << nums[i] << std::endl;
  }
}
// -----
// multiple inits in for loop, using comma operator
// must be of the same type, similar in if and switch see DECISION MAKING
#include <iostream>
int main() {
  const unsigned nums[] {0, 1, 2};
  const unsigned N {std::size(nums)};
  for(size_t i {}, running_sum {}; i < N; ++i) {
    running_sum += nums[i]; 
    std::cout << "sum is now: " << running_sum << std::endl;
  }
}
// -----
// for loop, using the comma op on the incr
// body of the for block for a sum is now in the incr
// the incr expression is executed for the first time after the first iteration of the loops body
// to see more comma operator see OPERATORS
#include <iostream>
int main() {
  const int nums[] {1, 2, 3, 4, 5};
  int sum {};
  for(unsigned i {}; i < std::size(nums); sum += nums[i], ++i);
  std::cout << sum << std::endl;
}
// -----
// range-based for loop, for containers
// can obviously use auto
// local variable is local to for, so modifying n will not modify the array
// n is assigned a copy of the value from the array, and is not the actual value in the array
// n is redefined on each iteration and initialzed with the current element
#include <iostream>
int main() {
  int nums[] {0, 1, 2, 3, 4, 5};
  for(int n : nums) {   // n is a local variable, that copies the num element value into n
    std::cout << n << std::endl;
    n += 10;  // only modifies the local n, not the vals in the array
  }
  for(auto n : nums) {std::cout << n << " " << std::endl;}   // same as above, nums is unmodified
  for(auto x: {10, 20, 30}) {
    std::cout << x << std::endl;
  }
}
// -----
// range-based for with reference, can be more efficienent, since it does not copy the value like above
// normally you cannot modify the entries in nums (only the local var in the loop)
// using a reference you can modify the vals in nums
// using a const & does not allow you to modify nums or the local loop variable
#include <iostream>
int main() {  
  int nums[] {0,1,2,3,4,5};
  for (int& ri : nums) {  // can modiy
    ri += 10;  
  }
  for (const int& ric : nums) {  // cannot modify, even locally in the loop, very efficient
    // ric += 10;  
    std::cout << ric << std::endl;  
  }
}
// -----
// while loop
// condition is checked, if true, enters the while block, checks condition again ...
// when its false, execution resumes after the while block
// condition must evaluate to a bool, or can be implicitly converted to one (like an int or char)
// increment/decrement in body or condition
#include <iostream>
int main() {
  char chs[] {'a', 'z', 'A', 'Z'};
  const int N {std::size(chs)};
  int i {-1};    // i is visible after the loop
  while(++i < N) {   // increment in condition
    std::cout << static_cast<unsigned>(chs[i]) << " ";
  }
  std::cout << std::endl;
  char c {'A'};
  while(c <= 'z') {   
    std::cout << c++;   // increment in body
  }
  std::cout << std::endl;
  // surrounding braces keeps j from being available after the ending } (like a for loop)
  {
    int j {};   
    while(j < N) {
      std::cout << chs[j] << " ";
      j += 1;  
    }
    std::cout << std::endl;
  }
  int k{6};
  while(k) {   // k is converted to bool
    std::cout << k-- << " ";
  }
}
// -----
// do while is for code that you wnt to execute at least once, maybe more
// block executes, condition is checked, if true back to the beginning of the block
// if false continue with program
#include <iostream>
int main() {
  char c {};
  do {
    std::cout << "do you want to continue (y/n)? ";
    std::cin >> c;
  }
  while (c != 'n');
}
// -----
// any loop can be nested in any other type of loop
// multiplication table 
#include <iostream>
#include <iomanip>
int main() {
  const int N {10};
  for(int i {1}; i <= N; ++i) {
    for(int j {1}; j <= N; ++j) {
      std::cout << std::setw(3) << i * j << " ";
    }
    std::cout << std::endl;
  }
}
// -----
// infinite loop examples
// basically any loop where the condition is always true
for(;;) {}
while(true) {}
// -----
// weird infinite loop
// unsigned chars go from 0...255, but at the last iteration it wraps back to 0
// < makes it end, or replacing unsigned char with int
#include <iostream>
int main() {
  for (unsigned char ch {}; ch <= std::numeric_limits<unsigned char>::max(); ++ch) { 
  }
}
// -----
// continue: skips to the end of the current iteration, check condition, possibly continue
// this skips the last iteration
#include <iostream>
int main() {
  int i {0};
  while (i <= 11) {
    if(i == 11) {
      ++i;
      continue;
    } 
    std::cout << i << std::endl; 
    ++i;
  }
  std::cout << i << std::endl;
}
// -----
// break
// infinite loop stops at i = 0.79999..., cout may round output to 0.8 anyway
#include <iostream>
#include <iomanip>
int main() {
  double i {1};
  while (true) {
    std::cout << std::fixed << std::setprecision(16) 
              << i << std::endl;
    if (i < 0.8) {
      std::cout << std::fixed << std::setprecision(16) 
                << i << std::endl;
      break;
    }
    i -= 0.01;
  }
}
// -----
// see IOMANIP for a for loop using: if(++linecount == 3)
// see C STRING for a range-for loop

POINTERS
// a pointer is a variable that holds an address of a for another variable
// nullptr is used to indicate an empty pointer
// helps to read from right to left
#include <iostream>
int main() {
  // int* error;   // should not initialize with a garbage value ever
  int* pnull {};   // zero-initialize with {}, so this is nullptr
  int *p1 {}, *p2 {};   // two null pointers, both need *
  std::cout << "pointers on this machine have size " 
            << sizeof(p1) << " bytes" << std::endl;  // 4 bytes for 32 bit machine
}
// -----
// & is the address of operator, when & is applied on rhs
// can use auto or auto* to have the compiler deduce the type
#include <iostream>
int main() {
  int num {32};   // 0x20
  int* pnum {&num};
  auto* pnum2 {&num};    // auto* requires an addr for initi
}
/*
variable:  num       pnum
location:  0x01  ... 0xA0
value:     0x20      0x01
*/
// -----
// * dereference/indirection operator
// use it to write (if non const) or read the value, at the addr held by pointer
// both the addr held by the pointer and the value at that address
#include <iostream>
int main() {
  int num {32};   // 0x20
  int* pnum {&num};
  std::cout << *pnum << std::endl;  // look at value at the addr held by pnum
  *pnum = 64;  // change the value at the addr held by pnum
  std::cout << pnum << std::endl;    // address held by pnum
  std::cout << *pnum << std::endl;   // value at the address held by pnum
  std::cout << ++(*pnum) << std::endl;  // 65  
} 
// -----
// pointers to numerical values compared with char*
// cout treats pointers differently
#include <iostream>
int main() {
  int num {32};
  int* pnum {&num};
  char* name {"Ben"};
  std::cout << pnum << std::endl;    // addr held by pnum
  std::cout << *pnum << std::endl;   // 32, value at the addr help by pnum
  std::cout << name << std::endl;    // string literal value "Ben" (not the addr)
  std::cout << *name << std::endl;   // value at the addr held by name, 'B'
}
// -----
// an array of pointers, char* in this case
// can access using index notation[] (can also use range-based for)
#include <iostream>
int main() {
  const char* names[] {"Harki", "Ben", "Finn", "Mags"};
  int N {std::size(names)};
  std::cout << "There are " << N << " names" << std::endl;
  for(int i {}; i < N; ++i) {
    std::cout << names[i] << std::endl; 
  }
}
// -----
// pointer arithmetic assumes that you are pointing to an array
// can add and subtract integers from addrs, compare addr held by pointers
// can add and subtract addrs held by pointers   
// any arithmetic depends on the size of the type, ex: p += 1 is addr += 1*sizeof(int)
// can take the addr of an array element, as a value for a pointer
// deref notation vs index notation
// void pointer from C and sizeof()
#include <iostream>
int main() {
  const int N {51};
  int a[N] {};   // a is not a true pointer, but does output address of the first element
  int num {};
  for (int i {}; i < N; ++i) {  // initialize with 0..50  (value of 50 is the stopping point)
    a[i] = num++;
  }
  for (int* pa {a}; *pa != 50; ++pa) {  // need a true pointer pa, prints each element in array
    std::cout << *pa << std::endl;
  }
  int* pa = a;   // reset to the beginning of the array a[0]
  pa += 1;   // same as addr += 1*sizeof(int) which is addr += 4 bytes, pa holds a new addr
  std::cout << *pa << std::endl;  // 1
  int* pa_25 = &a[24];   // points to the 25th element
  std::cout << *pa_25 << std::endl;  // 24
  pa_25 += 5;  // moves 5 ints up in array
  std::cout << *pa_25 << std::endl;   // 29
  int* pa29 {&a[29]};
  std::cout << *(pa29 + 1) << ", " << a[30] << std::endl;    // both are value 30 , does not change a[29] 
  *pa29 = *(pa29 + 11);   // deref to assign and access a value, same as a[29] = a[40] = 40
  std::cout << *pa29 << std::endl;  // 40, but is really at a[29]
  std::cout << (pa29 > pa) << std::endl;   // 1, which is true since pa29 is further in memory
  std::cout << *(++pa29) << std::endl;  // 30, at a[30]
}
// -----
// array names are almost pointers, except that their value can never change
// array name contain the addr of the first element, arithmetic can be applied
//   array name variable cannot be mutated or reused
#include <iostream>
int main() {
  int nums[] {0,1,2,3,4,5,6,7};
  const int N {std::size(nums)};
  int copy[N] {};
  for (int i {}; i < N; ++i) {
    *(copy + i) = *(nums + i);
  } 
  for (int num: copy) {
    std::cout << num << std::endl;
  }
}
// -----
// subtraction of pointers makes sense in contiguous memory
// returns universial std::ptrdiff_t in <cstddef> header
// returns the raw integer addr subtraction divided by sizeof(type)
// basically it finds number of elements from nums[0] to start of nums[5] (5 ints)
#include <iostream>
int main() {
  int nums[] {0, 1, 2, 3, 4, 5};
  int* pn1 {&nums[5]};
  int* pn2 {&nums[0]};
  std::ptrdiff_t diff = pn1 - pn2;
  std::cout << diff << std::endl;  // 5, subtracting addrs held by pointers here, not raw addr int 
  std::cout << ((int) pn1 - (int) pn2)/sizeof(int) << std::endl;  // 5, subtracting raw addr in int
}
// -----
// C-Style void*
// use of a void* for C-like generic programming, can be cast to any pointer type
// void* must be cast to a concrete pointer type (in C++) before it can be dereferenced
// void* must be cast to an int to add to the raw integer address
// start at the beginning of an array, add sizeof(int) bytes to raw addr, see second element
// C-style casts could be static_cast<int>, tells the compiler to not give warnings
#include <iostream>
int main() {
  int num[] {32, 64};
  void* vn {num};
  int rawaddr {((int) vn) + ((int) sizeof(int))};
  int* vn1 {(int*) rawaddr};
  std::cout << *vn1 << std::endl;
}
// -----
// void* array
// arr is an array of void pointers that point to an int, unsigned, long
// a function that accepts addr of an array of void pointers
#include <iostream>
int sum(void** parr, int N) {   // parr accepts the addr held by arr
  int s {};
  for (int i {}; i < N; ++i) {
    int* pi = static_cast<int*>(parr[i]);
    s += *pi;
  }
  return s;
}
int main() {
  int num1 {32};
  unsigned num2 {64};
  unsigned long num3{128};
  void *vn1 {&num1}, *vn2 {&num2}, *vn3 {&num3};
  void* arr[] {vn1, vn2, vn3};   // array of void*'s
  const int N {std::size(arr)};
  std::cout << sum(arr, N) << std::endl;
}
// -----
// vector pointer always holds an addr on the heap where the data lives
// the pointer itself could live on the stack or heap
// vector<> pointer is a "fat pointer" in that it contains more than just an addr to the heap for the allocated data
// (*). and -> syntax for calling a method/member, works with either case
#include <iostream>
#include <vector>
int main() {
  char c {'c'};  // useful to tell the difference in stack/heap addrs, c lives on stack
  char* pc {&c};   // holds an addr on the stack like: 0x00f8f8....
	std::vector<char> svec {'x', 'x', 'x', 'x'};    // pointer lives on the stack, svec is a "fat pointer" that eventually holds a heap addr for data 
	std::vector<char>* psvec {&svec};     // holds an addr on the stack like: 0x00f8f8....
	std::vector<char>* hvec {new std::vector<char> {'h', 'h', 'h', 'h'}};  // pointer lives on the stack, contains a heap addr to the location of the fat pointer
  std::vector<char>** phvec {&hvec};  // holds an addr on the stack like: 0x00f8f8....
  psvec->push_back('x');
  (*hvec).push_back('x');
  hvec->push_back('x');
}
// -----
// see pointers and const in CONST
// see pointers in array in C ARRAY
// see pointers and string literalss in C STRING
// for smart pointers see MEMORY

CONST
// value of the variable cannot be changed
const int i{32};
// i = 64;   // i cannot be changed
// -----
// values are copied in initialization on creation
// since they are seperate locations, and operating on copies, compiler will allow all
#include <iostream>
int main() { 
  const int ci {32};
  int i {ci};
  int j {64};
  const int jc {j};  
}
// -----
// values of array are const
const unsigned int const_heights[] {26, 37, 47, 55, 62, 75};   // values cannot be changed
// const_heights[0] = 2;   // error
// -----
// char* initalized with const string literals should be declared const, see C STRING
// value at addr help by the pointer is const, pointer holds addr of first char
const char* name {"Ben Harki"};
// *name = 'X';   // should not be able to change 'B' in the string literal
// -----
// const value and const pointer
// helps to read type from right to left
// both the value at the addr held by ptr and the addr held by pointer can be constant
// starting with non-const int vars, see next example with const variables
// remember that it is an error to ever have char* point to a non-const value
#include <iostream>
int main() {
  int num {32};
  int num2 {64};
  int num3 {128};
  int num4 {256};
  // -----
  const int* pnum {&num};
  // *pnum = 64;   // cannot change the value at the addr held by pointer
  pnum = &num2;   // can change the addr held by pointer
  // -----
  int* const pnum2 {&num2};
  *pnum2 = 32;   // can change the value at the addr held by pointer
  // pnum2 = &num;   // cannot change the addr held by pointer
  // -----
  const int* const pnum3 {&num3};
  // *pnum3 = 256;   // cannot change value at addr held by ptr
  // pnum3 = &num;     // cannot change addr held by ptr
  // -----
  int* pnum4 {&num4};
  *pnum4 = 257;   // can do either
  pnum4 = &num3;   
}
// -----
// const pointers from const variables
// cannot convert from const to non-const (const !-> non-const)
// compiler will generally convert anything to const, but not convert from const to unconst
#include <iostream>
int main() {
  const int num {32};
  const int num2 {64};
  const int num3 {128};
  const int num4 {256};
  // -----
  const int* pnum {&num};
  // *pnum = 64;   // cannot change the value at the addr held by pointer
  pnum = &num2;   // can change the addr held by pointer
  // -----
  // int* const pnum2 {&num2};    // const !-> non-const
  // -----
  const int* const pnum3 {&num3};
  // *pnum3 = 256;   // cannot change value at addr held by ptr
  // pnum3 = &num;     // cannot change addr held by ptr
  // -----
  // int* pnum4 {&num4};   // const !-> non-const
}
// -----
// alternative syntax for the const at the value, at the addr the pointer holds
// basically can be type before cast, instead of const before type
#include <iostream>
int main() {
  int const num {32};  // type before const  
  const int* const pnum {&num};  // I'll likely use this
  int const* const pnum2 {&num};  // same as previous
}
// -----
// array of char* pointers
// array of pointers where the value at the addr is const, not pointer addr
// remember that pointer to non-const containing const literals should not ever exist (const !-> non-const)
//  so there is no char* const names3 case
#include <iostream>
int main() {
  const char* names[] {"Ben", "Mags", "Finn"};
  // *names[0] = 'A';  // value at addr is const
  names[0] = "Adam";  // addr in pointer has been changed to one that contains 'A' in "Adam" str
  const char* const names2[] {"Adam", "Mom", "Dad"};
  // *names2[0] = 'A';     // neither can be changed
  // names2[0] = "Adam"; 
  int N {std::size(names)};
  for (int i {}; i < N; ++i) {
    std::cout << names[i] << std::endl;   // each is a char*, so cout displays the string value, see CSTRING, IOSTREAM
  }
}
// -----
// references are like *const, but they are only aliases to a variable
// they do not live in a location like a pointer, SEE REFERENCES
// *const is like &
// const & means that the value in the variable it refers to is immutable
#include <iostream>
int main() {  
  int i {32};  
  int& ri {i};
  int* const cpi {&i};   // similar in that they both cannot refer to any other variable
  ri = 64;
  *cpi = 32;  // however you can modify the value they refer/point to
  const int& ric {i};
  const int* const cpic {&i};   // similar in that you cannot also modify value in the location they both refer to
  // ric = 128;
  // *cpic = 128;
}
// -----
// generally can upgrade a var to a const &, but not downgrade
// example showing how you cannot downgrade, see above for upgrade
#include <iostream>
int main() {  
  const int i {32};
  const int& ric {i};   // equivalent in const
  // int& ri {i};   // const int !-> int 
}
// -----
// const (at the value level) in function parameter list, inside an array and as a singular value
// size does not need to be const in since it only contains a copy of the value from N 
// size is its own variable, local to the function
// size could be declared const:
//   but that only stops the function from modifying the parameter inside the function alone
// value at the addr held by pointer (array values themselves) should be const: 
//   to avoid having the function modifying the array in main
// arr is declared const, because arr is really a pointer, contains the addr of the first value
// const is useful bc you may want to ensure the function cannot modify values inside the array,
// to see passing arrays by &, see FUNCTION
#include <iostream>
void print_arr(const int arr[], int size) {
  for (int i {}; i < size; ++i) {
    std::cout << arr[i] << std::endl;
  }
}
void print_arr_ptr(const int* arr, const int size) {    // now the values int the array cannot be changed in te function or main()
  for (const int *pa {arr}, *end {arr + size}; pa < end; ++pa) {  // const bc arr is const (values not pointers) (const !-> nonconst)
    std::cout << *pa << std::endl;
  }
}
int main() { 
  const int nums[] {0,1,2,3,4,5,6,7,8,9};
  const int N {std::size(nums)};  // const only with respect to main
  print_arr(nums, N);   // still accepts N, even though size param is not const, bc size is its own copy of N and there is no conversion
  print_arr_ptr(nums, N);
}
// -----
// cannot initialize a non-const ref in the function parameter from a const variable 
// generally cannot downgrade, but always upgrade
#include <iostream>
void p_cr(const int& i) {     
  std::cout << i << std::endl;
}
void p_r(int& i) {       // cannot accept const int variables
  std::cout << i << std::endl;
}
int main() {
  int i {32};
  const int ic {64};
  p_cr(i);
  // p_r(ic);   // const !-> non-const is illegal
}
// -----
// implicit conversion between types from arg to parameter related to const &
// conversion is allowd with const & and not non-const &
// making the & const, allows for the compiler to convert from int -> const double&
// creation of temporaries, used in conversion is generally not allowed for non-const &
#include <iostream>
void pr_d(double& d) {    // does not allow type conversion to int
  std::cout << d << std::endl;
}
void pr_d_c(const double& d) {  // allows it
  std::cout << d << std::endl;
}
int main() {  
  int i {3};
  // pr_d(i);  // will not do the conversion from int to double&
  pr_d_c(i);   // const will allow it
  const int j {4};
  // pr_d(j);  // will not compile, bc of above and also because const !-> non-const
  pr_d_c(j);  
}

REFERENCES
// a reference is a name that is an alias for another variable
// & on lhs is a reference, & on the rhs is the addr of operator
// a reference is completely equivalent to the original variable, even in usage syntax
// it is another name for a variable, even referes to the same location in memory
// you cannot declare a reference without initializing it
// cannot mutate the reference to refer to something else
// no dereference necessary
#include <iostream>
int main() {  
  int i {32}, j {128};
  int& ri {i};
  ri = 64;  // i now contains 64, no need to dereference
  std::cout << i << ", " << ri << std::endl;  // both are 64 
  std::cout << &ri << ", " << &i << std::endl;   // same location
  ri = j;   // copy value of j into i, through the alias ri
  std::cout << i << std::endl;  // 128
}
// -----
// reference vs pointer
// can store the addr of a reference in a pointer
// non *const pointers can point to other variables, no equivalent in reference
// & are similar to *const except that pointers actually live in a location in memory
// cannot modify a value in a variable that a const & refers to, SEE CONST
#include <iostream>
int main() {  
  int i {32}, j {128};	
  int& ri {i};
  int* p {&ri};   // &ri is the same as the addr of i, or &i
  ri = j;   // copies the value of j into i through ri
  *p = j;   // does the same thing through the pointer
  std::cout << i << ", " << j << std::endl;   // 128 for both
  p = &j;   // pointer points to another variable, cannot do this with a ref
  int* const pj {&j};   // pj actually has its own location and holds &j, &pj != &j
  int& rj {j};          // similar to above, but rj is only an alias, does not live in memory, &rj == &j
  std::cout << std::boolalpha;
  std::cout << ((int) &rj == (int) &j) << std::endl;  // true, locations are the same
  std::cout << ((int) &pj == (int) &j) << std::endl;  // false, locations are different
  const int& ci {i};
  // ci = 4;  // now cannot modify i through its ci alias
}

HEAP, STACK
// new allocated variables on the free store a part of which is called the heap
// new dynamically allocates memory during runtime
// if there is not enough memory new will throw an exception
// delete releases this memory during execution of the program so it can be reused by the program or other programs running simultaneously
// once the program ends this memory is freed automatically, otherwise it is a memory leak
// any variable allocated without new (or malloc-like functions from C) is allocated on stack at compile time
// variables allocated on the stack are automatically released when their lifetime ends, see LIFETIME, SCOPE
// try not to allocate a large amount of small allocations to avoid fragmentation
// generally easier and less buggy to use std:vector<> and smart pointers (see MEMORY) over manual new and delete
// Modern C++ should avoid new and delete, but will encounter in legacy code
// -----
// use Visual Studio memory leak check _CrtDumpMemoryLeaks()
// compile with /MDd to define _DEBUG:
// > cl /EHsc /W4 /std:c++17 /MDd test.cpp
// a memory leak is reported as true
// pointer that hold the heap address should not be const, so that it cn be reset to nullptr when freed
#include <iostream>
int main() {
  const double* dval {new double {3.14}};  // initialize the value and the pointer immediately
  std::cout << *dval << std::endl;
  std::cout << std::boolalpha << "mem leaks: " 
            << (bool) _CrtDumpMemoryLeaks() << std::endl;  // true, a leak is found
  delete dval;   // now it is free;
	dval = nullptr;  // pointer is reset
	std::cout << std::boolalpha << "mem leaks: " 
					<< (bool) _CrtDumpMemoryLeaks() << std::endl;  // false, leak is gone
}
// -----
// all ptrs should be initialzed with a valid addr or nullptr
// freed ptrs by delete should be immediately nulled by nullptr
#include <iostream>
int main() {
  double* pnum {};  // nullptr
  pnum = new double {};    // give it a pointer to memory with its value zero-initialized
  std::cout << *pnum << std::endl;   // 0
  double* pnum2 {new double};  // garbage double in a free-store initialized pointer; 
  delete pnum; pnum = nullptr;  // avoid dangling ptr
  delete pnum2; pnum2 = nullptr;  
  std::cout << std::boolalpha << "mem leaks: " 
            << (bool) _CrtDumpMemoryLeaks() << std::endl;  // false
  return 0;
}
// -----
// memory leak, dangling pointer, multiple deallocations
// memory leaks could slow the program down, when memory usage is high or fragmented
// freed pointers should be immediately nulled by nullptr
// dangling pointer: when you dereference an address that has been freed
// also an error to deref a nullptr
// all the free errors also apply to delete[]
// every new must be paired with a delete and every new[] must be paired with a delete[] (otherwise undefined behavior)
#include <iostream>
int main() {
  double* pnum {new double {}};  // pnum points to a location that holds 0
  // pnum = new double {1.0};  // location that holds 0 is leaked and forever lost
  delete pnum;
  // std::cout << *pnum << std::endl;    // pnum has been freed, invalid location, so it is dangling
  // delete pnum;     // multiple deallocation, also an error
  pnum = nullptr;  // avoids dangling ptr and multiple dealloc error
  std::cout << pnum << std::endl;   // ok bc the addr is nullptr or 0x00000000
  // std::cout << *pnum << std::endl;   // error bc its a deref of a nullptr 
  // delete[] pnum;   // error since pnum is not an array
  delete pnum;   // no error when calling delete on nullptr
  // if (pnum) {delete pnum; pnum = nullptr;}   // no need for this check since delete on a nullptr is ok
	// if (1) {
  //   double* d {new double {3.14}};   // memory leak since d is not deleted before it goes out of scope  
  //   return 0;  // watch for returning early before deleting, or during exceptions
  // }
	std::cout << std::boolalpha << "mem leaks: " 
					<< (bool) _CrtDumpMemoryLeaks() << std::endl;  // false
  return 0;
}
// -----
// create an array on the free store
// some compilers will not automatically deterine size of the dynamic array
// free using delete[]
#include <iostream>
int main() {
  double* garb {new double[50]};   // garbage values in array
  double* darr {new double[50] {}};  // zero-initialize values in array
  double* maybe_error {new double[] {1.1, 1.2}};   // compiler may automatically determine size
  double* darr2 {new double [25] {3.14, 6.28}};  // remaining are zero-initialized
  delete[] garb; delete[] darr; delete[] maybe_error; delete[] darr2;
  garb = nullptr; darr = nullptr; maybe_error = nullptr; darr2 = nullptr;
  std::cout << std::boolalpha << "mem leaks: " 
            << (bool) _CrtDumpMemoryLeaks() << std::endl;  // false
  return 0;
}
// -----
// allocate multidimensional arrays on the heap 
// has strange (*nums) syntax, like a pointer to one long array of nums
// this is on the heap as one long array of ints
// only requires a delete[] to free
#include <iostream>
int main() {
  const int R {3};
  const int C {4};
  int (*nums)[C] {new int[R][C] {}};   // can use auto to make declaration syntax easier
  int count {};
  for(int i {}; i < R; ++i) {
    for (int j {}; j < C; ++j) {
      nums[i][j] = count++;
    }
  }
  for(int i {}; i < R; ++i) {
    for (int j {}; j < C; ++j) {
      std::cout << nums[i][j] << " ";
    }
    std::cout << std::endl;
  }
	// delete nums;   // error/undefined since nums is an array
  delete[] nums; nums = nullptr;
  std::cout << std::boolalpha << "mem leaks: " 
        << (bool) _CrtDumpMemoryLeaks() << std::endl;  
}
// -----
// another multidim array on the free-store
// not as efficient since rows are not guaranteed to be contiguous
// you have to delete[] each array pointer
#include <iostream>
int main() {
  const int R {3};
  const int C {4};
  int** nums {new int*[R] {}};  // a pointer to an array of nullptrs
  for (int i {}; i < R; ++i) {
    nums[i] = new int[C] {1, 1, 1, 1};   // each element is a pointer to an array of 1's
  }
  for (int i {}; i < R; ++i) {
    delete[] nums[i];  // delete each pointer inside the array
  }
  delete [] nums;   // delete the outer array
  std::cout << std::boolalpha << "mem leaks: " 
        << (bool) _CrtDumpMemoryLeaks() << std::endl;  // false
}
// -----
// std::vector<> already allocates on the free-store, so there is no need for new

FUNCTION
// {} is a statement block, can contain other blocks, like a compound statement
// main exists in the global mainspace ::
// call stack keeps track of where in memory a function is called or returned to
// function names follow the same rules as variable names see DEFINITION
// function header contains the return type, name, parameter list, body 
// function signature is the function name and the parameter list, 
	// used by compiler to determine which function is called, used to determine which overloaded function
int main() {   // function header
	std::cout << "Hello" << std::endl;   // statements end in ;
	return 0;  // return is optional in main() function and in functions returning void, otherwise it is required
}
// -----
// functions with two parameters or no parameters, and returning a value, or returning void
//   functions that return void cannot be used in most expressions
// called in main with literals and with variables 
// i and j are arguments (in the call), start and stop are parameters (in the body)
// parameters are initialized with the argument values at the start of the function
// if the types do not match, the compiler will try an implicit conversion, same as in initialization and assignment, see DEFINITION 
//  compiler may issue a narrowing conversion warning if there is a loss of data in the conversionS
// to see how const & affects parameter implicit conversions see const
// all parameters are local to the function, so you can reuse their names in other functions
#include <iostream>
int sum_ints(int start, int stop) {   // parameter list (int start, int stop)
  int sum {};   
  for (int i {start}; i < stop + 1; ++i) {
    sum += i;
  }
  return sum;    // parameter variables do not exist after the function stops executing
}
void print_sum_to_ten() {      // return is optional in functinos returning void
  std::cout << sum_ints(1,10) << std::endl;
}
int main() {  
  std::cout << sum_ints(1, 3) << std::endl;   // 6
  int i {1}, j {10};
  std::cout << sum_ints(i, j) << std::endl;  // 55
  print_sum_to_ten();  // 55
  std::cout << sum_ints(1.0f, 10.0f) << std::endl;  // compiler converts to ints, narrowing conversion
} 
// -----
// can have multiple return statements
// can return expressions
// return only returns a copy of the value inside the "returned" variable
#include <iostream>
#include <array>
bool istrue(int i) {
  if (i) {
    return true;
  }
  else {
    return false;
  }
}
int ret_int(int j) {
  return j;    
}
int ret_expr() {
  int i {1}, j {2}, k {3};
  return i + j + k;  // copy of the val of the expression is returned
}
int main() {  
  std::cout << std::boolalpha << istrue(100) << std::endl;
  int i {100};
  int res {ret_int(i)};
  std::cout << res << std::endl;  // value of i is copied into j, j is copied back to res  
  std::cout << ret_expr() << std::endl; 
}
// -----
// functions are defined top to bottom in a source file
// if A() calls B(), then B() needs defined before A() (including main()) 
// function prototypes (also called func declarations) allow you to write functions in any order (mostly)
// A() calls B() and B() calls A() are mutually recursive functions
// a simple prototype is the function header, but can differ from one somewhat
// protypes can also help when functions are divided into multiple source files
// prototypes can also help with mutually recursive functions
// prototypes can include the param vars, or other names for those vars
// header files tend to hold the function prototypes
#include <iostream>
int sum_forward(int beginning, int final);   // prototype with different param names
void print(int);   // without param names
int main() {  
  std::cout << sum_forward(1,10) << std::endl;
  print(100);
} 
void print(int i) {
  std::cout << i << std::endl;
}
int sum_forward(int start, int end) {   // can be defined under main bc of prototype
  int sum{};
  for (int i {start}; i < end + 1; ++i) {
    sum += i;
  }
  return sum;
}
// -----
// pass by value
// arguments of a function call are copied into the parameter local variables
// function operates on these copies and not on the original variables
// you can pass and return to the same mutable variable to change it
// you can name a variable in the function scope the same as name as one in the scope it is called in
//  the called scope's version is hid when inside the function's body
#include <iostream>
void no_swap(int x, int y) {
  int temp {y};
  y = x;
  x = temp;   // only swaps x and y valies locally, not i and j's in main
}
int add_ten_by_value(int i) {   // local parameter i hides main's i
  return i + 10;
}
int main() {  
  int i {1}, j {0};
  no_swap(i, j);   // values of i and j args are copied into local function params x and y
  std::cout << i << ", " << j << std::endl;  // unchanged 1, 0
  i = add_ten_by_value(i);    // value of i copied to local i and then copied back to main's i
  std::cout << i << std::endl;  // i's value is now 11
}
// -----
// pass by value with a pointer can modify the caller's variables
// be careful not to swap the pointer variables locally, see no_swap
// you could write both a swap and a no_swap for int**, int***, etc ..
#include <iostream>
void swap(int* x, int* y) {
  int temp {*y};
  *y = *x;
  *x = temp;   
}
void no_swap(int* x, int* y) {  // addrs held by the pointers are swapped, locally
  int* temp {y};
  y = x;
  x = y;
}
int main() {  
  int i {1}, j {0};
  swap(&i, &j);   // locations of i and j are copied and set as values to the pointer vars x and y   
  std::cout << i << ", " << j << std::endl;  // changed 0, 1
  no_swap(&i, &j);  // addr of i and j are copied into x and y ptrs, but only the addrs held by ptrs are swapped, not the values at the addrs
  std::cout << i << ", " << j << std::endl;  // unchanged from previous: 0, 1
}
// -----
// pass by reference (so it does not copy the value to another variable in the function)
// function accepts a variable but binds a reference to it locally, to use in the body
// the reference is an alias so modifying the reference modifues the variable, see REFERENCE
// syntax is the same as handling the original variable and since it is not a pointer
// compiler mostly compilers references in the same way it compiles pointers
void swap(int& i, int& j) {
  int temp {j};
  j = i;
  i = temp;
}
#include <iostream>
int main() {
  int i {1}, j {0};
  swap(i, j);     // pass the variable, not the address 
  std::cout << i << ", " << j << std::endl;   // swapped, 1, 0
}
// -----
// array names return the address of the first element, so you can never pass all elements directly
// the addr is copied to the functions array variable as it's addr value
// basically the array value is passed into a pointer parameter no matter what, even if the parameter is: int nums[]
// N is needed since nums is only the addr of the first elem
// N cannot be replaced by std::size(nums) or sizeof(nums) inside the function, size() only works properly in the same scope as the array definition
// cannot have a range-based for loop
// can write using [] or * notation, can literally use the body of one for the other, they are exactly equivalent
// both function prototypes are considered identical by the compiler, so they are interchangable (although it would be weird to do)
#include <iostream>
void print_arr_ptr(const int nums[], int N);  // notice that its by pty, yet has [] for the prtotype, and it still compiles and runs
void print_arr(const int nums[], int N) {     // nums is actually a pointer here, even though an array name is not technically a pointer, SEE C ARRAY
  std::cout << '[';  
  for (int i {}; i < N-1; ++i) {    // cannot be range-based for
    std::cout << nums[i] << ' ';    
  }
  std::cout << nums[N-1] << ']' << std::endl;
}
void print_arr_ptr(const int* nums, int N) {    // const only applies to the values in the array, not the addr held by ptr
  std::cout << '[';  
  for (const int *pn {nums}, *end {nums + (N-1)}; pn < end; ++pn) {    // must be const bc of const in nums declaration
    std::cout << *pn << ' ';    
  }
  std::cout << *(nums + (N-1)) << ']' << std::endl;
}
int main() {  
  int ns[] {0,1,2,3,4,5};
  print_arr(ns, std::size(ns));  // ns is the addr of the array, copied to nums array var
  print_arr_ptr(ns, std::size(ns));
}
// -----
// adding a size to the parameter does not actually restrict the array or access to all its elements in the function
// should never use explicit sizes in the parameter when declaring a local array
// compiler still only treats the function signature as: void print_arr(int nums[], const int N)
#include <iostream>
void print_arr(int nums[3], int N) {  // this still accepts an array of any size and access to all of its elements
  std::cout << '[';  
  for (int i {}; i < N-1; ++i) {  
    std::cout << nums[i] << ' ';    
  }
  std::cout << nums[N-1] << ']' << std::endl;
}
int main() {  
  int ns[] {0,1,2,3,4,5};
  print_arr(ns, 12);  // reads beyond the bounds of the array, even with the explicit size on the array parameter
}
// -----
// passing an array by &, must use parens like: int (&nums)[3]
// compiler will now magically check the size of the array declared in the function signature
// can make the array const too, to ensure the functoin cannot modify the values
// int& nums[3] tries to make an array of references, which is also a compiler error
// reference also allows sizeof and std::size() functions to be called, so no need for N parameter
// & also allows range-based for loops
#include <iostream>
void print_arr(int (&nums)[3], const int N) {    // notice the &
  std::cout << '[';  
  for (int i {}; i < N-1; ++i) {  
    std::cout << nums[i] << ' ';    
  }
  std::cout << nums[N-1] << ']' << std::endl;
}
void print_arr_better(int (&nums)[6]) {
  const size_t  N {std::size(nums)};  // with a ref, I can now use std::size() and sizeof()
  std::cout << '[';  
  for (unsigned i {}; i < N-1; ++i) {  
    std::cout << nums[i] << ' ';    
  }
  std::cout << nums[N-1] << ']' << std::endl;
}
int main() {  
  const int N {6};
  int ns[N] {0,1,2,3,4,5};
  // print_arr(ns, N);  // will not compile
  print_arr_better(ns);
}
// -----
// function that accepts a multi-dim array
// left-most dimension is unnecessary in siginature, but you need the others to be explicit
// left most explicit dimension, if added, does notthing, like in a 1d array
// however the compiler will reject if the other dimensions are incorrect
// function will accept multi-dim arrays with any size of rows, and specifically 4 col
// you cannot replace 4 with std::size(arr[i]) and the inner-loop cannot be a range-based for
//  std::size can only be used in the same scope as the declaration of orig array
//  also cannot do either for the outer loop  
// TODO: can write with pointers, but the syntax is messy
// TODO: add a & to parameter, enables compiler check of all dimensions, range-based for, and sizeof() and std::size() (see above)
#include <iostream>
void print_multi_dim(const int arr[][4], const int R) {
  for (int i {}; i < R; ++i) {
    for (int j {}; j < 4; ++j) {   // can't be range-based
      std::cout << arr[i][j] << ' ';
    }
    std::cout << std::endl;
  }
}
int main() {  
  const int R {3};
  const int C {4};
  int nums[R][C] {0,1,2,3,4,5,6,7,8,9,10,11};
  print_multi_dim(nums, R);
  int nums2[2][C] {{0,1,2,3}, {4,5,6,7}};  // function will accept any row size but col size of 4
  print_multi_dim(nums2, 2);
  int err[2][3] {0,1,2,3,4,5};
  // print_multi_dim(err, 2);   // col dimension is incorrect, compiler error
}
// -----
// default values for an argument can be added to functions
// only need to call with an argument if you want something different from the default
// you can default an arg in the function definition or in prototype
// const is the same for function parameters
// default value needs to be convertible to the type in the function parameter
// multiple args, needs to keep default values on the right
// once one arg is ommitted then args to the right all mus t be ommitted
#include <iostream>
void print_name(const char* n = "Ben");
void print_hi(const char* h = "hi") {
   std::cout << h << std::endl; 
}
void print_i(const int& i = 3.0f) {  // stupid here, but works, needs to be a const & and not & to convert, see CONST
  std::cout << i << std::endl;
}
void print_dec23d(int d, int m = 12, int year = 2023) {  // multiple defaults placed on the right
  std::cout << m << "/" << d << "/" << year << std::endl;
}
int main() {  
  print_hi();
  print_hi("hello");  // call with something different
  print_name();
  print_i();
  print_dec23d(20);
  print_dec23d(21, 10);
  print_dec23d(22, 11, 1984);  
}
void print_name(const char* n) {
  std::cout << n << std::endl;
}
// -----
// for const in function parameter lists see CONST

NAMESPACE
// namespaces prevents name collision
// without a namespace declaration, variables live in a global namespace, with no name
// main() live in global namespace
// std example from  Standard Library namespace
// :: is the scope resolution operator
std::cout << "Hello" << std::endl;   // std is the standard namespace
// -----
// user-defined namespace
#include <iostream>
namespace ben {
  const char *const name = "Ben";
}
int main() { 
  std::cout << ben::name << std::endl;  // needs namespace prefix
	return 0;
}	
// -----
// using, eliminates the need for a namespace qualifier
#include <iostream>
using std::cout, std::endl;  // need /std:c++17
int main() { 
  cout << "Hello" << endl;
}	
// -----
// using directive imports every name from a namespace
// could cause collision, if you don't know all the names in the namespace
#include <iostream>
using namespace std;
int main() { 
  cout << "Hello" << endl;
}	

ENUMERATIONS
// enumerated data type
// limits to an object to specific set of values called enumerators
// enumerators are automatically assigned to a fixed int, starting at 0, 1, ...
// can cast to an int to see its assigned value
// can assign specific >=0 values to any number of them, dont need to be unique, next is always +1 from the previous
// can also define an enumerator based on previously defined enumerators 
// values for enumerators must be compile-time constants: literals, previous enumerators, const variables  
// can also specify a different integer type, like char
#include <iostream>
enum class Switch {High, Med, Low};   // default values of 0, 1, 2
enum class Another {High = 10, Higher, Highest};   // values now start at 10, then 11, 12, ...
enum class More {High, H = High, Low, L = Low, h = 0, l = h + 1};   // High = H = h, Low = L = l 
enum class Punctuation : char {Comma = ',', Question = '!'};
int main() {  
  const Switch s {Switch::High};  
  std::cout << static_cast<int>(s) << std::endl;  // 0
  std::cout << static_cast<char>(Punctuation::Comma) << std::endl;  // ,
  Switch n = s;  // copy value into n
  // n = 0;  // cannot directly assign the int value
}
// -----
// see CMaster for obsolete C enum syntax:
// these easily convert to other integral values or floating point types without a cast
// can lead to errors
enum Switch {High, Low};

CLASS
// defines a data type
// an item from a class is an object

TEMPLATE
// a template is a recipe that you create, used by the compiler, to generate code automatically
// used for a class or function to customize them for a particular type or types

STANDARD LIBRARY

IOSTREAM
// cout from std namspace and iostream header file, prints to the console
std::cout << "Hello" << std::endl;   // std is the standard namespace
// -----
// cin reads from the keyboard
// cannot read and store spaces with >>
// also reading a numerical value with >> into a char variable only stores the first digit of character code
// executes left to right
// expression (cin >> i) >> j first one is executed, returns cin and becomes cin >> j
#include <iostream>
int main() { 
  int i{}, j{}, k{};
  std::cout << "enter 3 numbers: ";
  std::cin >> i >> j >> k;     // each >> terminates at a space
  std::cout << i << ", " << j << ", " << k << std::endl;
}	
// -----
// steam manipulators, remain in effect until you change it
// all in std namespace
// example of a stream manipulator, that changes the formatting of output
#include <iostream>
int main() {
  std::cout << std::hex << "0x" << 0b11111111 << std::endl;
}  
// -----
// more manipulators:
fixed, scientific, defaultfloat, dec, hex, oct, showbase, left, right
boolalpha, noboolalpha
// functions
std::cin.getline()
// -----
// see LOOPS for cin do-while example
// std::cout treats pointers differently, see POINTERS

// -----
// output streams for wchar_t
// there are no special streams for char16_t or char32_t, see CHARACTER
std::wcout, std::wcin

IOMANIP
// more ways to format the output
// in std namespace
// fixed causes setprecision(n) to be interpreted as displaying n decimal places
#include <iomanip>
#include <iostream>
int main() {
  std::cout << std::fixed << std::setprecision(4) << 1.0/3 << std::endl;  // 0.3333
}
// -----
// displaying in rows of 3, using setw() to lineup columns
// setw() increases the space that each print holds
// default is right aligned so so space is filled in to the left of the obj 
#include <iostream>
#include <array>
#include <iomanip>
int main() {
  unsigned linecount {};
  for(double i {1}; i < 2; i += 0.1) {
    std::cout << std::setw(5) << i;
    if(++linecount == 3) {  
      std::cout << std::endl;
      linecount = 0;
    }
  } 
  std::cout << std::endl;
}
// -----
// more examples
setw(), setfill()  


CMATH
// contains booleans on infinity or nan results from a computation, like 1.5/0 = inf
#include <cmath>
std::isinf(), std::isnan()
// -----
// all in std namespaces, so they require std:: prefix
// contains:
abs(), ceil(), floor, exp(), log(), log10(), pow(), sqrt(), round() 
cos(), sin(), tan(), acos(), asin(), atan()
round(), lround(), llround()

LIMITS
// limits includes the extreem value for each type
// in the standard library namespace
#include <iostream>
#include <limits>
int main() {
  std::cout << std::numeric_limits<double>::max() << std::endl;
}
// -----
// more examples:
std::numeric_limits<double>::min(), std::numeric_limits<double>::lowest()
std::numeric_limits<double>::digits  // number of bits for used for the type
double neg_inf = -std::numeric_limits<double>::infinity();
std::numeric_limits<double>::quiet_NaN();

CCTYPE
// header in standard library to help classify characters
#include <cctype>
std::isupper(), islower(), isalpha(), isdigit(), isxdigit(),
isalnum(), isspace(), isblank(), ispunct(), isprint(), iscntrl(), 
isgraph(), tolower(), toupper()

ARRAY
// std::array<T, N> is a container, T and N are template params
// T for elem type, N for size
// N must be a constant or a literal
// mimic's C arrays in that you can zero-initialize, garbage initialize
// manual initialization is the same as C array
// can use range-based for loop
// index [] notation does not check bounds, but .at() does and could throw an exception
// can be elements in other containers, like a vector
// checks the dimensions of an array for function paramter with or without &, see FUNCTION (need & for reg arrays)
#include <iostream>
#include <array>
int main() {
  std::array<int, 10> arr {};   // zero initialize
  arr.fill(1);   // all filled with one's
  std::cout << arr.size() << std::endl;
  std::cout << arr[0] << std::endl;
  std::cout << arr.at(1) << std::endl;  // check array bounds 
  arr.front(); arr.back();
}
// -----
// these operators can be appied to two arrays if they have the same size and type
==, !=, >, <, = (assignment) 
// -----
// legacy functions that accept C arrays can use std::array using .data()
std::array<int, 10> arr {};
arr.data(), arr.empty();

VECTOR
// vectors<T> do not need a size, only a type param, and grows automatically
// does not allocate with garbage values, always zero-initializes by default
// can specify a starting size that does not need to be const
// can use [index] to access existing elements (does not check bounds), but only push_back to add new ones
// at() does check the array bounds
#include <iostream>
#include <vector>
int main() {
  std::vector<double> v;  // no allocation made yet
  v.push_back(314);
  std::vector<double> names(10);    // starting size of vector is 10
  std::vector<double> ages(100, 25);  // 100 ages initialzed with 25
  std::vector<double> dec {1.0, 1.1, 1.2};  // init with specific values
  dec[0] = 0.9;
  dec.at(1) = 1.3;
}
// -----
// also has:
vec.size(), vec.front(), vec.back(), < <= > >= == !=, copy assignment with =, vec.assign()
vec.clear(), vec.empty(), vec.pop_back()
// -----
// see HEAP, STACK for an example on allocation of the pointer on heap or stack

MEMORY
#include <memory>
// smart pointers will handle freeing a pointer, so no need for a manual free or delete call
// removes the possibility for many free-store errors, see HEAP, STACK
// can be stored in array<T,N> and vector<T>
// contains smart pointers in std namespace like:
std::unique_ptr<T>, std::shared_ptr<T>, std::weak_ptr<T>
// -----
// weak_ptr<>: linked to a shared_ptr<> and contains the same addr
	// does not increment the ref count, so it does not prevent the memory to be released when the ref count is 0
	// compiler forces you to create a shared_ptr when ref count is zero, making it valid again 
	// if the memory has already been released then shared_ptr<> contains a nullptr
	// used to prevent reference cycles: x contains a shared_ptr<> to y, which contains a shared_ptr to x
		// situation prevents x or y to be destroyed 
// -----
// unique_ptr<>: can only be one unique_ptr obj that contains any one address, pointer owns the address
	// location cannot be copied to another unique_ptr, but can be .move(), which will make the first empty
// unique_ptr<> should use std::make_unique<> to prevent other more subtle memory leaks
// do not need to call delete, deref is the same
// array, .get(), .reset(), .release()
// should always capture the return of .release(), otherwise it is another memory leak
#include <iostream>
#include <memory>
int main() {
  {
    std::unique_ptr<double> pd1 {new double {3.14}};   // old syntax
    std::unique_ptr<double> pd2 {std::make_unique<double>(3.14)};  // better 
    std::unique_ptr<int[]> ia {std::make_unique<int[]>(10)};  // array of size 10 of zeros
    std::cout << *pd2 << std::endl;
    std::cout << pd2.get() << std::endl;   // raw address
    std::cout << ia[0] << std::endl;   // access an element in an array using []
    pd1.reset();   // pointer holds nullptr address. prev addr is freed
    std::cout << pd1.get() << std::endl;   // 00000000
    pd1.reset(new double {6.28});  // resets the pointer to point to a new place that contains 6.28, old place is freed
    double* dumb = pd1.release();  // turns the smart pointer back to a C-Pointer, pd1 contains nullptr again, should always capture return in a var
    delete dumb;  // needed since it is a C-Pointer
  }
  std::cout << std::boolalpha << "mem leaks: " 
      << (bool) _CrtDumpMemoryLeaks() << std::endl;   // false, no leaks,  since the smart pointers release when out of scope
}
// -----
// shared pointer allocates on the heap, no need for delete
// only need when multiple parts of a program share the same obj
// shared_ptr<>: allows any number of shared_ptrs to contain a single addr
// has a reference counter in the ptr per unique addr
	// reference count is incremented on new shared_ptr 
	// decremented when the variable lifetime is over or assigned a different addr
	// location is freed when shared_ptr ref count is 0
// shared pointer can use make_shared<>() to allocate on the heap more efficeiently
// copy assignment would not be allowed in unique_ptr<>
// can also use standard initialization syntax
// can be used in vector<>, array<>, as elements or hold the pointer  
#include <iostream>
#include <memory>
#include <vector>
int main() {  
  std::shared_ptr<double[]> pa {new double[3] {1.1, 1.2, 1.3}};  // old style syntaz
  std::shared_ptr<double> pd {std::make_shared<double>(3.14)};  // more efficient
  *pd = 4.1;
  std::cout << *pd << std::endl;
  std::shared_ptr<double> pd1 = pd;  // copies the addr in the pointer to pd1, incr the ref count 
  std::shared_ptr<std::vector<double>> pv {std::make_shared<std::vector<double>> ()};
  pv->push_back(3.14);  // pv is a pointer on the stack that contains the addr of the vector fat ptr on the heap
}

CSTRING
#include <cstring>
// contains functions to manipulate C Strings
// C-Strings end in '/0', see C Strings
// inheriantly unsafe, <string> is a safer option

STRING
#include <string>
// dynamic string, better safer than C String
// in the standard namespace
std:string empty;
// see Chp 7 in Beginning C++

STRING VIEW
#include <string_view>
// in std namespace
// better than <string> in that there is no copying of input string args to parameters in a function