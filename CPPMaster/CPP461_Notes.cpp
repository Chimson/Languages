// Mainly from CSC461 and C++ Primer
// more current than CSC461 version

TOPICS:
FIRST PROGRAM
COMPILE RUN
DECLARE, ASSIGN 
HEADERS
LITERALS
TYPES, CONVERSION
ESCAPE CHARS
OPERATORS
PRINTF AND FORMAT STRING
CONTROL
LOOPS
REFERENCES
POINTERS
CONST, &, POINTERS
POINTERS, ARRAYS, AND C STRINGS
FUNCTIONS, POINTERS, REFERENCES 
CLASS
THIS
HEAP, NEW
ENUM
OPERATOR OVERLOADING
TEMPLATE
INHERITANCE
MACROS
INCLUDES, HEADER., CONDITIONAL COMPILATION
STANDARD LIBRARY
C++ STRINGS
VECTORS
EXCEPTIONS
LAMBDAS
SMART POINTERS
CIN, COUT

FIRST PROGRAM
// std is a namespace, to avoid collisions of names of variables between libraries
// :: is scope operator, to determine the namespace the obj is in
#include <iostream>
int main() {
  std::cout << "Hello" << std::endl;
  return 0;
}
// *****
// exit on bad input
int main(void) {
  int i{1};
	if(i==1)
		return 1;	// nonzero indicates error
	return 0;
}
// *****
// in windows, you can read how the OS interprets the return from main()
// 0 is true, non-zero is false
> echo $? 

COMPILE RUN
// Run MSVC (MS Visual Studio Compiler) in any PS within VSCode 
> cd C:\"Program Files"\"Microsoft Visual Studio"\2022\Community\Common7\Tools
> .\Launch-VsDevShell  
> cd C:\Users\Benso\Languages\CPPMaster
// *****
// same as above, inside MSVC PS
// opens VSCode with MSVC cl commands enabled
> code .
// *****
// build and run command in MSVC
//EHsc for exception handling, /Wall for all warnings /W4 for a lot of warnings
> cl /EHsc /W4 test.cpp  
> ./test

DECLARE, ASSIGN
// C style 
int i;
int i, j;
int i = 1;
int i = 1, j = 2, k;
// *****
// C++ style
int j{};
int j{0};   // list initialization
int j(0);
int j{0}, k{1}, l;
int j = {0};
// *****
// for built-in types {} will not allow initialization if leads to loss of data
double p{3.14};
int i {p};  // error, narrowing conversion
int i = {p}; // error, narrowing conversion
int i(p); int i = p;   // no error, but truncation
// *****
// default initialization through declaration
// built-in declared outside of functions default to "0"
// built-in declared inside a function are garbage, undefined
// classes can define their declarations, some give default value , some throw an error
#include <iostream>
#include <string>
int i;     // default initialized to 0 for ints
int main() {
  std::string s{};   // class initializes to empty string
  std::cout << i << s << i << std::endl;
  int j;    // uninitialized garbage data, even reading is an error
  return 0;
}
// *****
// extern is used to bring into scope variables defined in other files, headers or cpp
// see mod1.cpp and header1.h
// cannot initialize any extern in function 
// see masterC.c for more examples
// a variable can be declared extern in all finals as long as it initialized in one
int i{1};   // global in header1.h, declares and initializes here
extern int i;      // in mod1.cpp brings into scope from header1.h
// *****
// identifier rules:
// use letters, digits, underscore
// must begin with letters or underscore
// no __name, no _A..., anywhere
// no _name outside of functions 
// *****
// global, local scope, and hiding
// global scope has no name, see ::global
#include <iostream>
int global = 42; //  has global scope
int main() {
  int local = 0; // has block scope
  std::cout << global << " " << local << std::endl;
  int global = 0; // hides global variable
  std::cout << global << " " << local << std::endl;   // local version
  std::cout << ::global << " " << local << std::endl;  // explicit request of global version
  return 0;
}

HEADERS
// see MasterC.c for more specific on contents
// see multiple-files folder to show how to compile multiple files/multiple headers/multiple folders
// standard library headers have <> and not .h, " " for non std lib

LITERALS
// suffixes override the defaults of assignment of literals 
// raw sting literals allow you to avoid escape chars
1'000'000    // use ' for readability 
0b11101111   // binary
0B11101111  
050  // 50 in base 8 octal
0xff  // hex
0XFF  // hex
1e+3  // scientific
1E-2
0x1.3p	// hex floating pt
bool, true, false // _Bool
'A'
'abcd'   // multicharacter literal 0x61626364
u8'a' u8"hi"  // char
u'a', u"hi"  // char16_t
U'a', U"hi"  // char32_t
L'a', L"hi"  // wchar_t
R"\Hello"		// raw string literal, also has u8R, LR, uR, UR. unescaped \ 
"Hello"s    //  std::string, can have u8, L, u, U prefixes
R"\Hello"s  // std::string raw, unescaped \, has u8R, LR, uR, UR prefixes 
32U, 32u  // unsigned
32L, 32l  // long
32ll, 32LL  // long long
3.14f, 3.14F   // float
3.14l, 3.14L   // long double
32ul, 32UL   // unsigned long
32ull, 32ULL  //unsigned long long
nullptr //  memory location "0"

TYPES, CONVERSION
// types determine how many bits are used and how to interprete them
// byte is 8 bits (one char), a word is 32 or 64 bits (4 bytes or 8 bytes)
// memory addresses are numbered by bytes
// signed char or unsigned  can be used for tiny integers
void, bool
char, signed char, unsigned char,   // compiler chooses char to be either unsigned char or signed char
short, int, long, long long,    
signed, unsigned  // unsigned defaults to unsigned int, both can be applied to short, int, long, long long
float, double, long double
wchar_t, char16_t, char32_t,    // for extended character sets
// *****
// assigning too large a value for a signed type is undefined
// unsigned types, take % size
// implicit conversion by assignment, demotion or promotion, truncation
signed char = 20000;   // undefined
unsigned char c = 1000;   // unsigned char goes up to 255, out of range, so this is 1000%255
int i = 3.14;   // i is 3
// *****
// compiler applies conversions when it a construct is given one type but expects a number
if(42){;}
// *****
// signed int vs unsigned int auto converstion issue, when negative is involved
// don't mix, signed are automatically converted to unsigned
//  4292967264 (32-bit unsigned int), since int is converted to unsigned and wrapped around in neg direction to largest int vals
unsigned u = 10, v = 100;
int i = -42;
cout << u + i << endl;  
cout << u - v << endl;    // also wraps around
// *****
// bad infinite loop with unsigned
// --u, when u == 0, wraps around to largest unsigned, so it is never neg, never breaks loop
for(unsigned u = 10; u >= 0; --u)  
	std::cout << u << std::endl;
// *****
// implict conversion cases in expressions
// expressions involving smaller integral types smaller than int are promoted to int, if the results fit into an int
// otherwise the value is promoted to unsigned int (unsigned)
short i = 10; int j = 11; i+j;  // i is promoted to an int  
// in other relational and arithmetic expressions, values are converted to a common type
3.14L + 'a'; // 'a' promote to int, then to long double
(short) 3 + 'a'; // both converted to int 
'a' + 4.1L;  // char converts to a Long
(int) ival + (unsigned long) ulval;  // ival concerted to unsigned long
(unsigned short) usval + (int) ival;  // converts to unsigned if unsigned type is same size or larger 
// *****
// typedef and alias declaration
// typedefs are C's aliases for long compound types
// using with = is an alias declaration from c++11
#include <iostream>
int main() { 
  typedef double *const Array; 
  Array a[10] = {0};   
  using Zero_Array = const double *const;
  Zero_Array z[10] = {0};
  return 0;
}	
// *****
// be careful with consts and pointers
#include <iostream>
int main() { 
  typedef char* MyString;
  const MyString s = "Ben Harki";  // like char *const
  // s = nullptr;  // pointer value can not be changed
  s[0] = 'A';  // can be mutated
  typedef const char *const CString;
  CString mags = "Mags Harki";
  // mags = s;    // can't change the pointer's value (an addr)
  // mags[0] = 'A';    // can't change the value at that addr
  return 0;
}	
// *****
// auto tells the compiler to deduce the type
// needs an initializer
// can use auto for multiple variables in one line, but must be able to be deduced rom one type
#include <iostream>
int main() { 
  auto c = {'a', 'b', 'c'};
  auto i = 0, *pi = &i;
  return 0;
}	

// CASTING
// explicit casts - see also const_cast, dynamic_cast
// const_cast relates only to the constness of a type, dynamic_cast  for inheritance
// *****
// static cast is for reversing a well defined implict cast
// here smaller type convert to a larger type
int i,j;
double div = static_cast<double>(i)/j;    // forces floating point division
// also to convert between pointer types
char d;
void* p = &d;   // p is a raw memmory address
double *dp = static_cast<double*>(p);   // p is now cast as a double*    
// *****
// reinterpret_cast
// forces the reinterpretation of an int as a char, can be dangerous
int *ip;
char *pc = reinterpret_cast<char*>(ip);   // int* to char*, should not modify *pc as a char
// *****
// C Style casting
// compiler will choose static_cast or const_cast first, if doesn't apply it chooses reinterpret_cast
int *ip
char *pc = (char*) ip;    // still unsafe bc it chooses reinterpret_cast

ESCAPE CHARS
\0, \n, \b, \r, \t, \\, \"", \ooo, \xhhh  
\a, \f, \v, \'', ?, \?, \nnn, \unnnn, \Unnnnnnnn, \xnn
// *****
// examples of generalized escape sequences
// number is the numerical value of the character (in octal)
\12   // \n
\x4d  // 'M' 
std::cout << "\x4d O \115\012";  // M (in hex), O, M (in octal), \n   

OPERATORS
= :: & ;
+ - * / %   
+= -= ...
< <= > >=
== != && || <=>
++ --
. ()

PRINTF AND FORMAT STRING
// from masterC.c
// printf is faster than cout
// putc(), puts() also writes to terminal by line
printf("number %i\n",1);    // first arg is actually a pointer to that string
printf("number: %i\n",  // use next line via comma
	2)
printf("%i\n", 'a') // prints ASCII
%i, %d,
%o, %#o, %x, %#x,  // base
%f, %e, %g, %a   // floating point, scientific
%p  // pointer address
%c, %s          // char, string
%li, %lo, %lx, %lli, %llx, %llo, %Lf, %Le, %Lg   // long qualifiers
%hi, %ho, %hx  // short qualifiers
%u, %hu, %llu,   // unsigned
%%
printf("%2i",9);  // 2 spaces  right justified (leading space) for 9
printf("%-5i", 25); // 5 spaces left justified (trailing space) 
printf("%.2f",0.333333)  // 2 dec places
printf("%*i\n", 5, 10);   // * indicates justification size in next arg, *  can represent other flags
// *********
// putchar() prints one char at a time
#include <stdio.h>
int main(void) {
  putchar('a'); // prints to console
  putchar('\n');
  return 0;
}

CONTROL
if() {
}
else if() {
}
else {
}
// *****
// this is the same as if(){} else{if(){} else{}}, independent cases (partition)
// anything that evaluates to 0 is false, non-zero is true
#include <iostream>
int main() {
  for(int i{0}; i<2; ++i) {
    if(i) {
      std::cout << i << ": true" << std::endl; 
    }
    else {
      std::cout << i << ": false" << std::endl; 
    }
  }
	return 0;
}
// *****
// in-line
( ? : );
// *****
// switch example
char c{'a'};
switch(c) {
  case 'a': {
    cout << "a" << endl;
  }
  break;
  case 'b': {
    cout << "b" << endl;
  }
  break;
  default: 
    ;
}

LOOPS
// while loops with +=, ++
// all from 0 to 9
#include <iostream>
int main() {
  int i{0}, n{10};
  while(i < n) {
    std::cout << i << std::endl;
    i += 1;
  }
  std::cout << std::endl;
  i = -1;
  while(++i < n) {     // i++ is 0 to 10
    std::cout << i << std::endl;
  } 
  std::cout << std::endl;
  i = 0;
  while(i < n) {
    std::cout << i++ << std::endl;
  } 
  return 0;
}
// ******
do {
} 
while();
// *****
// for loops, indexed scoped inside or outside the loop
// increment by char pointer, '\0' condition on deref
#include <iostream>
int main() {
  for(int i{0}; i<10; ++i) {
    std::cout << i << std::endl;
  }
  std::cout << std::endl;
  // *****
  int j{0};
  for(j; j<10; ++j) {
    std::cout << j << std::endl;
  }
  std::cout << j << std::endl;   // 10
  std::cout << std::endl;
  // *****
  char* s = "Ben Harki";   // c string literals automatically add a null char
  for(; *s != '\0'; ++s) {  // do not need all parts of a for loop
    std::cout << *s; 
  }
}
// *****
// range for is only good for read only, need indices for assignment
// range for in a function with &args
// with and without pointer
#include <iostream>
#include <vector>
using namespace std;
void printA(vector<int> &vec) {   // with &srg
  for(int v : vec) 
    cout << v << " ";
  cout << endl;
}
void printB(vector<int>* vec) {   // with *
  for(int v : *vec) 
    cout << v << " ";
  cout << endl;
}
int main() {
  vector<int> vec{0,1,2,3,4};
  printA(vec);    // 0 1 2 3 4
  printB(&vec);   // 0 1 2 3 4
  return 0;
}
// ADD for(auto &var: collection) or for(auto *var: collection) example

REFERENCES
// & reference declarations are aliases, bound to an existing object (not copied)
// references are not an obj like a pointer, and do not have an address
// once a reference of an object is defined, it is impossible to make it refer to another object
// must always initialize bc it has to point somewhere (can never be nullptr)
// remember that after declaring a &var, var is the value, &var again is the address of the obj it is an alias to
// cannot be bound to a literal, or result of expression (unless const, see CONST)
#include <iostream>
int main() {
	int i = 1024, &ri = i;   // declare a reference all in one line 
  int x{10};
	// int &xRef;   // error, needs initialized
  int &xr = x;   // xr is bound to x, not copied into it
  ri = xr;   // you can bind a nonconst ref to the obj through its alias (SEE CONST & {POINTERS)
  std::cout << ri << std::endl;
	std::cout << &x << std::endl;       // addr of x
  std::cout << &xr << std::endl;    // same as x addr
  std::cout << xr <<std::endl;    // 10, through alias
	// int &t = 10;  // cannot bound to a literal (rhs of = must be an lvalue itself)   
	// compiler uses temp var for 10, and then makes a ref to the temp var, so temp should be const
	return 0;  
}
// *****
// All operations on that reference are actually operations on the object to which the reference is bound
// assignment to a reference assigns to orig obj it refers to
// references do not have addresses
// cannot define a reference to a location
#include <iostream>
int main() {
  int x{10};
  int &xr = x;   
	int s = xr;   // copies value of x into s
  std::cout << s << std::endl;  // 10
  xr = 100;   // change value of x through reference
  std::cout << &x << ": " << x << std::endl;   // x is now 100
  std::cout << &s << ": " << s << std::endl;   // s is seperate from x, so still 10
  int &xr2 = xr;
  std::cout << xr2 << std::endl;  // another alias for x, 100
  // int &xrr = &xr;  // cannot define a reference to a location
  return 0;  
}
// *****
// & declarations and accepting and passing a ref
// also ref <-> ptr declarations
#include <iostream>
int& passRef(int &r) {
   return r;
}
int main() {
  int x{10};
  int &xRef = x;   // xRef is bound to x, not copied into it
	int* xp = &x;    // conversion of an alias to a location
  int &xr = *xp;    // create a ref from deref a pointer
  int &y = passRef(xRef); 
  int s = xRef;         // copies value of x into s
  std::cout << s << std::endl;       
  int z = passRef(x);       // copies value of x into z
  std::cout << z << std::endl;      // 10 in a diff address
  std::cout << &x << std::endl;       // addr of x
  std::cout << &y << std::endl;       // same x addr
  return 0;  
}

POINTERS
// pointers are objs, unlike references, references are only aliases
// pointers hold the address of another obj as their value
// pointers can point to another address, unlike a reference
// & in the rhs is the address of operator (not a reference)
// any uninitialized pointer is an error
#include <iostream>
int main() {
  int x, *px;  // can be declared
  int y{32}, *py{&y};  // initialized in one line
  int i{64};
  int* pi = &i;   // uses the address of operator &
  std::cout << &pi << ": " << pi << std::endl;     // pointer at address holds an address value
  int* pi2 = pi;  // copies the addr value of pi into new location pi2
  std::cout << &pi2 << ": " << pi2 << std::endl;
	pi = &y;   // pi now contain's y's address 
	std::cout << &pi << ": " << pi << std::endl;
	return 0;  
}
// *****
// dereference a pointer to access its value and reassign
#include <iostream>
int main() {
  int i{32};
  int* pi{&i};
  std::cout << pi << ": "<< *pi << std::endl;  // addr held by pointer, value at that addr
  *pi = 64;
  std::cout << pi << ": "<< *pi << std::endl; 
	return 0;
}
// *****
// declaration vs expression of pointer, deref, reference, addr of
#include <iostream>
int main() {
  int i{32};
  int &ri = i;  // reference declaration
  int* pi = &i;  // pointer declaration, addr expr
  *pi = 64;  // deref expr
  int &ri2 = *pi;   // ref decl, deref expr  
	return 0;
}
// *****
// null pointers
// cannot assign an int variable to a pointer, even if its value is 0
// should always initialze a pointer, even if you can only initialize to nullptr
#include <iostream>
#include <cstdlib> 
int main() {
  int* n{nullptr};   // can be converted to any pointer type
  n = NULL;   // from C
  n = 0;
  int zero{0};
  // int* pz = zero;  // cannot assign an int val from a var to a pointer
	return 0;
}
// *****
// can use pointers in conditions, where valid non-nullptr is true (ill advised)
// == and != check the value held by the pointer
#include <iostream>
int main() {
  int i{32};
  int* pi{&i};
  int* pi2 = &i;
  if(pi) {
    std::cout << "not nullptr" << std::endl;
  } 
  std::cout << std::boolalpha;
  std::cout << (pi == pi2) << std::endl;  // need parens 
  return 0;  
}
// *****
// void* can hold the address of any object, but the type is unknown
// can only compare void* to another pointer and assign it to another void*
// TODO: can also pass and return from functions
// cannot operate on an object it points to
#include <iostream>
int main() {
  int i{32}, *pi{&i};
  char* s = "Ben Harki";
  void* v = pi;  //copy addr value held by pi into v
	v = s;  // now copy s's pointer val to v
	std::cout << std::boolalpha << (v != pi) << std::endl;  // false, compare void* to other pointers
  void* v2 = &s;
	v = v2;  // copies val held by void ptr to another void ptr   
	return 0;
}
// *****
// helps to interpret double pointer
// can do ** but not &(&x) bc & requires an l-value
#include <iostream>
using namespace std;
int main() {  
  int x{1};
  int* px{&x};
  int** ppx{&px};
  cout << "in terms of addr operator and pointer value:"  << endl;
	cout << &x << ": " << x << endl;   // addrs of pointer holds an address value
  cout << &px << ": " << px << endl;
  cout << &ppx << ": " << ppx << endl;
  cout << "in terms of dereference operator from ppx:" << endl;
  cout << *ppx << ": " << **ppx << endl;    
  cout << ppx << ": " << *ppx << endl;   // addr held by ppx, value at that addr
  cout << &ppx << ": " << ppx << endl;   
  cout << "in terms of dereference operator from px:" << endl;
  cout << px << ": " << *px << endl;    
  cout << &px << ": " << px << endl;   // addr held by ppx, value at that addr
  cout << &ppx << ": " << ppx << endl;   
  return 0;
}
// *****
// can do a reference to a pointer 
// not a pointer to a reference, since references do not have locations, they are aliases
// read type right to left, vars left to right
#include <iostream>
int main() {  
  int i = 32;
  int &ri = i;
  int *pi = &i;   // & is address of operator, not reference
  int *&rpi = pi;   // ref (alias) to the pointer is ok
  // int &*pri = &ri;   // pointer to a ref (cannot find location of ref) 
  return 0;
}

CONST, &, POINTERS
// const declarations need initialized
// copy assignment is ok, copygin does not change the object
// int -> const int is ok
#include <iostream>
using namespace std;
int main() {
	// const int n;   // needs initialized
  const int cx = 3;    // value-const
  // cx = 4;    // ERROR, BC value is const
  int i = cx;    // this is ok, copies value of cx into j which is non const
  int j = 32;
  const int cj = j;   // can copy into a const variable
	return 0;
} 
// *****
// const var are local to the file, see extern in header1.h, mod1.h
// need extern in initialization and declaration
// can also initialize in main.cpp and then used in .h
header1.h:
	extern const int N = 100;   // definied and initialized ine one file
mod1.cpp:	
	extern const N;    //  brought into scope in another
// *****
// with refs, cannot have nonconst refs of const objs
// "const refs" are really just references to const vals, const only refers to what we can do with the obj
// can never make refs refer to another object by definition
// const int !-> int
#include <iostream>
int main() {
	const int &ri = 64;  // can initialize a const ref to a literal
  const int cx = 32;
  const int &crx = cx;  // const alias for cx
  // crx = 10;    // ERROR bc cx's value is const and shouldn't be changed via ref  
  int &rx = cx;  // ERROR bc can't have nonconst ref to a const obj
	return 0;
}
// *****
// refs to consts do not allow mutation through its ref
// can be modified from non const refs
#include <iostream>
int main() {
  int i = 32;
  int &ri = i;
  const int &ric = i;
  ri = 64;   // can mutate through nonconst ref
  // ric = 16;   // cannot mutate through const ref
  std::cout << ri << std::endl;  // 64
  std::cout << ric << std::endl;   // 64 bc the obj was modified elsewhere
  return 0;
}
// *****
// pointer to const value
// (const int* !-> int*) but (int* -> const int*) is ok 
// cannot modify through the * to const, but it may be modified elsewhere
// & is location here not reference
#include <iostream>
int main() {
  const int i = 10;
  const int* pic = &i;    // value at the addr the pointer holds is constant
  // *pic = 32;   // cannot change the value through deref pointer
  // int* pi = &i;   // cannot make a non-const pointer to a const val
	int j = 32;
  const int* pjc = &j;  // this is ok
  j = 64;   // modified elsewhere
  std::cout << *pjc << std::endl;   // 64
	pjc = &i;    // value held by the pointer can change
	return 0;
}
// *****
// constant pointer value
// constant pointer to constant value
// can always upgrade to a const, but never downgrade from one
// pointer value must be initialized, like normal consts
#include <iostream>
int main() {
  int i = 32;
  int j = 64;
  int *const cpi = &i;
  // cpi = &j;   // cannot change the value held by the pointer
  *cpi = 128;   // can change the value at the addr held 
  int n = 16;
  const int *const cpic = &n;   // addr held by pointer and the value at that addrr is const 
  // *n = 4;  // can't change the value at the addr
  // cpic = &i;   // can't change the addr the pointer holds
  return 0;
}
// ***** 
// conversion between levels of const (all consts must be initialized)
// top-level const is a const in the addr the pointer holds: *const
// top-level generally ignored in initialization from other cont combinations
// low-level const is the const on the value at the addr the pointer holds: const int
// initialization from other consts combinations requies sme low-level const or a valid conversion (int -> cont int)
// there are a ton of possibilities, these are only a few 
// references are considered low-level consts
#include <iostream>
int main() {
  int i = 0;      
  const int *const cpic = &i;   // ok bc there is a conversios from int -> const int
  const int ci = 32;
  // int *const cpi = &32;    // const int !-> int 
  const int &ric = i;
  const int &ric2 = ric;  // ok because low-level consts match
  // int &ri = ric;   // const !-> int
	return 0;
}
// *****
// use constexpr to be more explicit on when consts are constant expressions
// constexpr variables require explicit constexpr initializer values from functions
// constexpr explicitly ask compiler to verify if it is const 
// consts initialized from constant expressions are constant expressions
#include <iostream>
int size() {
  return 10;
}
constexpr int c_size() {
  return 10;
}
int main() {
  const int N = 1 + 2 + 3 + 4;  
  int s = c_size();   // ok even if it doesn't return constexpr
  constexpr int s1 = c_size(); 
  // constexpr int s2 = size();   // s2 is const_expr, so size must return it
}
// *****
// with pointers and refs
#include <iostream>
int main() {  
  int cx = 32;
  // int* xp = &x;  // ERROR bc can't convert from  value-const to non value-const
  const int* xp = &cx;  // fixes pointer 1st error
  // *xp = 10;   // ERROR  in the same way
  // *****
  int y = 4;
  const int* yp = &y;  // value-const, conversion from *const to * (since & = *const)
  int const* yp2 = &y;  // pointer-const, no conversion
  const int* const yp3 = &y;   // both, no conversion
  int &const yr = y;   // WARNING bc it is redundant
  // const int &yr = y;    // both value and ref of yr are const (& ref is const by default)
  const int &yr3 = *yp;   
	return 0;
}
// *****
// constexpr and pointer
// constexpr applies value of the pointer variable (value at the addr it points to)
#include <iostream>
int main() { 
  int i = 32;
  constexpr  int* pic = &i; 
  // pic = &j;   // addr pic holds cannot change
  *pic = 128;  // can change the value at the addr
  constexpr const int* picc = &i;   // similar to const int *const
  // picc = &i;   // val of pointer can't change
  // *picc = 4;   // val the pointer points to can't change
  // *****
  constexpr int j = 64;
  // constexpr  int* pjc = &j;    // error bc j value is const, and pjc is not a pointer to a const
  constexpr const int* pjcc = &j;   // this is ok, bc const indicates the pointed value is const
  // picc = &i;   // val of pointer can't change
  // *picc = 4;   // val the pointer points to can't change
}	



// *const is like  &, * pointers can be nullptr, & will never be
// &var as a rhs in an expression, is an address 
// also void*, mainly used to deal with memory locations, never its values
#include <iostream>
using namespace std;
int main() {
  int i{0};
  int *const icp = &i;  // no conversion
  // icp = nullptr   // ERROR since the pointer is declared const
  int* ip = &i;   // converts & to a non-const pointer   
  ip += 1;    // ip addr can be changed
  void* v = &i;   // holds the address of any object
  return 0;  
}
// *****
// using const, const only applies to the reassignment of a value here
// using reference, pointer, local temporary variable
#include <iostream>
using namespace std;
void do_not_change(const int &x, const int* y, const int z) {
  // x += 1; // compiler will not allow reassignment
  // *y += 1; // same here
  // z += 1;  // same here
  y += 1;  // however, I can adjust the pointer location
  cout << y << endl;    // 0x...
}
int main() { 
  int x{1};
  int y{2};
  int z{3};
  do_not_change(x, &y, z);
  return 0;
}	
// *****
// disables pointer arithmetic by second const
// no assignment allowed by first const
#include <iostream>
using namespace std;
void do_not_change(const int *const px) {
  // ++px;   // pointer cannot move
  // *px += 1;  // value cannot change
  cout << *px << endl; 
}
int main() { 
  int x{1};
  do_not_change(&x);    // 1
  return 0;
}

POINTERS, ARRAYS, AND C STRINGS
// pointer arithmetic and array index notation, arr[i] = *(arr+i) and arr+i = &arr[i]
// pointer to an array on the stack 
// adds a macro bc compiler rejects arr[N], when N is a variable
#include <iostream>
#define N 10   
using namespace std;
void set_array(int* arr) {  // with pointer arithmetic
  for(int i{0}; i<N; i++, arr++) { 
    *arr = i;   // derref to access value
  }
}
void print(int* arr) {    // with array index notation
  for(int i{0}; i<N; i++)
    cout << arr[i] << " ";    // access value
  cout << endl;
}
int main() {  
  int arr[N];
  set_array(arr);
  print(arr);   // 0 1 2 3 4 5 6 7 8 9
  cout << arr << " " << arr+1 << " " << arr+2 << endl;  // 0x... addresses to 1st three elems
  cout << &arr[0] << " " << &arr[1] << " " << &arr[2] << endl;   // 0x... addresses to 1st three elems
  cout << *arr << " " << *(arr+1) << " " << *(arr+2) << endl;   // 0 1 2
  cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;   // 0 1 2
  return 0;
}
// *****
// simple C strings (char arrays)
// prints using pointer arithmetic and '\0'
// also uses '\n'
// C strings should end in '\0'
// use '\0' to cut the string into two;
#include <iostream>
using namespace std;
int main() {  
  cout << '\0' << endl;   // blank
  char* name = "BenHarki";
  for( ; *name!='\0'; ++name) {   // prints by char
    cout << *name;
  }
  cout << endl;   // Ben Harki
  char nameA[] = "Mags Harki";
  char* pname = nameA;    // needs an actual pointer for arithmetic
  pname += 4;
  *pname = '\0';
  cout << nameA << endl;  // Mags
  cout << pname+1 << endl;  // Harki
  cout << "Ben\nFinn" << endl;  // uses next line
  return 0;
}
// *****


FUNCTIONS, POINTERS, REFERENCES
// TODO: add pointers and refs to functions
// pass by value
// can be overloaded (same name, different parameter types/quantity)
// *****
// pass by value, does not swap, but operates on copies
#include <iostream>
using namespace std;
void swap(int x, int y) {   // any function operates in an activation record
  int t{y};   // initializes t with the value of y
  y = x;
  x = t;
}
int main() { 
  int x{1}; // anything in main is stored on the stack in main's AR
  int y{0};
  swap(x, y);
  cout << "x = " << x << " and y = " << y << endl;  // x=1 and y=0
  return 0;
}	
// *****
// C style pointer use in a function
// pointers are objects so they can change, & refs are not
// function accepts a pointer and returns a pointer (also adds one to value)
// &  can convert to  *const, *px accesses the value held by the pointer px
#include <iostream>
using namespace std;
int* pointer(int* px) {
  *px += 1;
  return px;
}
int main() { 
  int* p;   // pointer allocated to stack, but points to garbage value
  int x{1};
  int* px = &x;   // address of x
  int* y = pointer(px);   // *y = *&x = 1
  cout << *y << endl;   // 2
  cout << *pointer(&x) << endl;  // 3  
  return 0;
}	
/*
location value
x 1
px &x
y &x
pointer(&x) &x
*/     
// *****
// C++ & reference use in a function, (& hides the pointer notation)
// when a var is declared &var, var is now the value, accessed by reference (not an address)
// &var in an expression is address
// function accepts a reference and returns nothing
#include <iostream>
using namespace std;
void change(int &px) {
  px += 1;    // changes actual px, notice no */& notation
}
int main() { 
  int x{1};
  change(x);    // no &x needed
  cout << x << endl;   // 2
  return 0;
}	
/*
location value
x 1
x 2
*/
// *****
// needs a prototype if functions are not in order 
// defaulted parameters, one in prototype, one in function defintion
// all defaults on the right-wise params
// prototype of function with & param, also needs a & param
#include <iostream>
using namespace std;
void print2(int &, int=2, int=3);   // prototype
void print(int &x, int y = 2, int z = 3) {
  cout << x << y << z << endl;
}
int main() { 
  int x{1};
  print(x);
  print2(x);
}	
void print2(int &x, int y, int z) {
  cout << x << y << z << endl;
}
// *****
// global and static
// global variables can be accessed anywhere, static refers to local variable value inside a function
#include <iostream>
using namespace std;
void change_global() {
  num1 +=1 ;		// changes actual global num1 (since num1 is not passed in)
}
void static_var () {			
  static int num2 {2};	// static holds on to current num2 value, preserves for future calls
  num2 += 1;				// without static num2 is reinitialized to 2
  cout << "num2 = " << num2 << endl;	
}
int num1{1};	// global is declared outside of main
int main () {
  change_global();	
  cout << "num1 = " << num1 << endl;		// num1 = 2
  static_var();	// num2 = 3
  static_var();	// num2 = 4
  return 0;
}
// *****
// change_array uses array variable name, which is a pointer to the first element of the array
// display array copies entire array locally and displays it
#include <iostream>
using namespace std;
void change_array(int* array, int i) {  // accesss actual array
  array[i] = 100;
}
void display_array(int array[], int stop) {		// local copy of array
  for(int i{0}; i<stop; i++) 
    cout << array[i] << " ";	
  cout << endl;						
}
int main() {
  int N{8};
  int array[] = {0,1,2,3,4,5,6,7};
  display_array(array, N);		// 0 1 2 3 4 5 6 7 
  change_array(array, 3);     
  display_array(array, N);    // 0 1 2 100 4 5 6 7
  return 0;					
}

CLASS
// private means that fields/methods can only be accessed by this class (or friends)
// public can be accessed by any class
// class method can be declared outside of a class
// an attribute is allocated on the heap and one instance is one the heap
// use -> to access a method/attribute though a pointer 
// destructor is called on closing AR for a function (like variables out of scope on main's stack frame) and on delete of a heap pointer
// has a delegating constructor
// *****
// Example of Big Four that the compiler always implements
// prototypes in class in .h
Order();
~Order();
Order(const Order &old);    // copy constructor
Order& operator=(const Order &rhs);  // copy assignment
// *****
// default the copy constructor in .cpp file or .h file
Order::Order(const Order &old) = default;
// delete in .h prototype
ColdNode(const ColdNode &old) = delete;
// *****
#include <iostream>
#include <string>
using namespace std;
class Person {
  private:        // with no keywords then private by default
    int age;     
  public:           
    string first;
    string last;
    int* weight;
    Person() : first{"X"}, last {"X"}, age{0}, weight{nullptr} {   // uses initializer list, better performance
      cout << "Calling no args constructor" << endl;
    }   
    Person(string first, int age) : Person{first, "harki", age, 160} {}   // delegates to 4 arg constructor
    Person(string f, string l, int a, int w) {   // constructor
      first = f;
      last = l;
      age = a;
      weight = new int; // allocate on the heap
      *weight = w;
    }
    ~Person() {     // destructor for allocation on the heap
      cout << "destructor called for " << first << endl;
      delete weight;
    }
    int get_age() {return age;}
    void set_age(int n) {age = n;}
    void print_person();      // prototype for method written outside of class code
  
};
void Person::print_person() {
  cout << first << " " << last << " " << "is " << age << " yrs old at "  
    << *weight << " lbs" << endl;
}
using namespace std;
int main() {
  Person ben("Ben", "Harki", 37, 184);   // calls 2-arg constructor, can use {} instead
  ben.print_person(); 
  Person mags;
  mags.first = "Mags";
  mags.last = "Harki";
  mags.set_age(35);
  int w = 150;
  mags.weight = &w;
  mags.print_person();
  Person *finn = new Person("Finn", "Harki", 2, 27);    // on the heap
  finn->print_person();   // access a method through a pointer
  cout << (*finn).get_age() << endl;
  Person gary("Gary", 50);
  gary.print_person();
  delete finn;    // whole obj was allocated on heap, so it needs deleted
  return 0;
}
// *****
// more simplified defaulted constructor
// also a shared static member
// uses {} for obj instance
// if constructor is written outside of class code, then you would default its prototype inside the class code
#include <iostream>
#include <string>
#define PP print_person   // because I'm lazy
using namespace std;
class Person {
  private:        // with no keywords then private by default
    int age;     
  public:           
    string first;
    string last;
    Person(string f="X", string l="X", int a=0) 
      : first{f}, last{l}, age{a} {  
    }
    int get_age() {return age;}
    void set_age(int n) {age = n;}
    void print_person();      // prototype for method written outside of class code
  
};
void Person::print_person() {
  cout << first << " " << last << " " << "is " << age << " yrs old" << endl;
}
int main() {
  Person none;
  none.PP();
  Person ben{"Ben"};
  ben.PP();
  Person mags{"Mags", "Harki"};
  mags.PP();
  Person finn{"Finn", "Harki", 2};
  finn.PP();
  return 0;
}
// *****
// static class member, one member shared among all objects
// initialized like a global variable, but cannot be declared in a class
#include <iostream>
#include <string>
using namespace std;
class Person {
  public:         
    static int count;   // like a singular member shared by all objects
};
int Person::count{0};    // initialized outside of main, not in class
int main() {
  Person ben;
  cout << ben.count << endl;  // 45
  Person mags;
  mags.count = 50;
  cout << mags.count << endl;   // 50
  cout << ben.count << endl;    // 50, changing it through mags affects all members
  return 0;
}


THIS
// this is a const pointer to a non-const member object of the class 
// this can point to garbage at first, so make sure to initialize its fields before applying any methods to this its self
Class *const this; 
// ****
// const member method and this pointer 
// const here indicates that "this" points to an object who's attributes are const (remember that the pointer this is already const itself) 
// const methods cannot change the values of the object on which they are called
// const objs, refs, pointers may only call const member functions
#include <iostream>
using namespace std;
class Person {
  public:
    Person();
    int getAge() const;   // both need const
  private:
    int age;
};
Person::Person() 
  :age{37} {}
int Person::getAge() const {   
  // this->age = 500;   // ERROR
  return this->age;
}
int main() { 
  Person ben;
  cout << ben.getAge() << endl;
  return 0;
}
// *****
// const in function returns
#include <iostream>
using namespace std;
class Person {
  public:
    int age;
    Person();   
    const Person* passThroughPointer();
    Person* const Person::passThroughPointer2();
    const Person* const Person::passThroughPointer3();
};
Person::Person() 
  :age{37} {}
const Person* Person::passThroughPointer() {   // const here indicates that the returned obj's atr values cannot be changed
  return this;    // remember that "this" is: Person *const this
}
Person* const Person::passThroughPointer2() {   // const here indicates that the returned obj's atr values cannot be changed
  return this;    // remember that "this" is: Person *const this
}
const Person* const Person::passThroughPointer3() {   // const here indicates that the returned obj's atr values cannot be changed
  return this;    // remember that "this" is: Person *const this
}
int main() { 
  Person ben;
  const Person* ben2 = ben.passThroughPointer();  // value is const
  // ben2->age = 54;    // ERROR, cannot reassign an attribute
  Person* const ben3 = ben.passThroughPointer2();    // ptr is const
  // ben3 = nullptr;    // ERROR, cannot change the pointer
  const Person* const ben4 = ben.passThroughPointer3();   // both are const
  return 0;
}
  
HEAP, NEW
// allocate an array on the heap using new
// delete pointer to deallocate from heap only
#include <iostream>
using namespace std;
int* allocate_array(int size) {
  int* array = new int[size]; // allocates on heap, returns a pointer  
  return array;               // not a dangling pointer bc of heap
} 
void set_values(int* array, int size) {   // accesses new array amd adds squares
  for(int i{0}; i<size; i++) 
    array[i] = i*i;
}
void print_array(int* array, int size) {
  for(int i{0}; i<size; i++) 
    cout << array[i] << endl;
}
int main() { 
  int N{10};
  int* new_array = allocate_array(N);
  set_values(new_array, N);
  print_array(new_array, N);    // 0 1 4 9 16 25 36 49 64 81
  delete [] new_array;
  return 0;
}
// *****
// placement new
// allows us to construct an object at a specific, preallocated memory address.
// preallocated memory can be on stack too
// can also use to construct arrays in allocation space
#include <iostream>
using namespace std;
class MyInt {
  public:
    int num;
    MyInt(){}
    MyInt(int n) :num{n} {}
};
int main() { 
  MyInt in;   // stack allocation
  new (&in) MyInt(100);   // uses one arg constructor, returns &in
  cout << in.num << endl; // 100
  return 0;
}

ENUM
// TODO: Add unscoped 
// this is a scoped enum, using class
#include <iostream>
using namespace std;
enum class Type :uint8_t {  // :uint8_t specifies size of each member  
	FREE,
	USED   
};
int main() {
  Type t = Type::FREE;
  return 0;
}


OPERATOR OVERLOADING
// can be non-member defined or class member defined, differ in the number of parameters
// for example: nonmember binary overloaded operator has 2 parameters, member operator has 1 and includes this pointer from the class object 
// operator= should be a member
// compound operators like += should be defined after + and =,s should be members
// ++, -- should be members
// symmetric operators (like +, ==, relational, bitwise) should be nonmember
// TODO: add an example 

TEMPLATE
// for programming in generic types
// <typename/class T> is a tempate parameter list, can have more seperated by commas
// can use be applied to inline or constexpr functions
// headers typically include template definitions in addition to declarations
// also can create templates with non-type parameters that represent values and not types 
// example: template<unsigned M unsigned N>
// *****
// function template that returns and accepts type T
// you have to instantiate the type
#include <iostream>
#include <string>
using namespace std;
template<typename T> T compare(T a, T b) {
  if(a <= b)    // should try to replace <= with a less_equal() that can bee extended to many more types
    return a;
  else
    return b;
}
int main() {
  string first{"Ben"}, last{"Harki"};
  cout << compare<string>(first, last) << endl;   // Ben, bc B<H
  cout << compare<int>(3,1) << endl;    // 1, bc 1 is smaller
  return 0;
}
// *****
// class template
// class templates methods ad fields can also be defined outside of class definition code
// classes are completely implemented by compiler are completely seperate
#include <iostream>
#include <string>
using namespace std;
template <typename T> class Number {
  public:
    T num;
};
int main() {
  Number<int> n;
  n.num = 10;
  Number<string> name;
  name.num = "ten";
  cout << n.num << endl;
  cout << name.num << endl;
  return 0;
}

INHERITANCE
// accessing a virtual method through a pointer gives dynamic dispatch
// in dynamic dispatch, if A->B, B derived from A, when A obj holds a B, A calls B's virtual methods 
// TODO: add protected
#include <iostream>
#include <string>
using namespace std;
class Animal { 
  public: 
    virtual string to_string() { 
      return "Animal";
    }
};
class Bird: public Animal {   // can also use private, protected here
  public: 
    virtual string to_string() {  
      return "Bird"; 
    }
};
int main() {
  Bird *b = new Bird;
  Animal *a = b;   // Bird and Cat on the heap
  cout << a->to_string() << endl;   // Bird
  delete b;
  return 0;
}

MACROS
// this is from masterC.c
// #define a constant text pattern aka macro  // can appear nearly anywhere in a program
// like a search and replace via preprocessor, before compilation(why theres no ; end)
// preprocessor will replace trigraph seq by correct symbol
#include <stdio.h>
#define TRUE 1   // not a variable
#define FALSE 0   // cannot use like char val[] = "FALSE" but can be used in just about any other way
int  isEven(int x) {
  if(x%2==0)
    return TRUE;
  return FALSE;
}
void print_even(int x) {
  if(isEven(x)) {
    printf("%i is even\n", x);
    return;
  }
  printf("%i is odd\n", x);
}

int main(void) {
  print_even(18);
  print_even(9);
  return 0;
}
// *****
// NULL pointer and PI
#include <stdio.h>
#include <math.h> // contains M_PI
int main(void) {
  int r = 4;
  int area = M_PI*r*r;
  int *ptr = NULL;    // NULL included in header stddef.h
  return 0;
}
// *****
// #define in an array size and type
#include <stdio.h>
#define SIZE 10
#define TYPE int
#define TF "%i"
void print_array(TYPE arr[SIZE]) {
  for(int i=0; i<SIZE; i++) {
    printf(TF, arr[i]);
    printf("\n");
  }
}
int main(void) {
  TYPE arr[SIZE] = {1,2,3};
  print_array(arr);
  return 0;
}
// *****
//#define for program portability
#include <stdio.h>
#define DIR "/home/bharki/test.c"
int main(void) {
  printf(DIR);
  printf("\n");
  return 0;
}
// *****
// defined as a partial statement or expression
#include <stdio.h>
#define IFCHECK if(x==0)
#define MULT x+3*4*5
int main(void) {
  int x = 0;
  IFCHECK
  {printf("HI\n");}
  x = MULT;
  printf("%i\n", x);
  return 0;
}
// *****
// one #define in another
#define TWO 2     // can actually reverse these, but not advised
#define VAL TWO*x
// *****
// multiple line #define
#include <stdio.h>
#define SIGN if(x>0) {printf("pos\n");} \
            else {printf("neg\n");}
int main(void) {
  int x=-5;
  SIGN
  return 0;
}
// *****
// #define with args, more commonly called macros
// uses more memory space but functions have more call overhead
#include <stdio.h>
#define PRINTINT(I) printf("%i\n",I); // cannot have space between name and arg of macro
#define SQUARE(x) (x*x)   // no type needed, can use parens on outside
#define SQBETTER(x) ((x)*(x))
int main(void) {
  PRINTINT(10);
  int y = 3;
  PRINTINT(SQUARE(y));  // SQUARE(y+1) = y+1*y+1 = 7 != 16, so be careful, fix with parens
  PRINTINT(SQBETTER(y+1));  // 16
  return 0;
}
// *****
// #define with >1 args    // parens avoid any issues in evals when inserting exprs, or used inside expr
#include <stdio.h>
#define MAX(x,y) ((x)>(y) ? (x) : (y))
int main(void) {
  int x = 18, y = 9;
  printf("%i\n", MAX(x+1,y-1)*100); // 1900
  return 0;
}
// *****
//#define with variable args
#include <stdio.h>
#define debugPrint(...) printf("DEBUG: " __VA_ARGS__);  // del printf... to undefine macro to ; 
int main(void) {
  int i = 1, j = 2;
  debugPrint("i = %i, j = %i\n", i, j);   // printf with 2 constant strings i and j args
  return 0;
}
// *********
// # operator adds "" around macro var
#include <stdio.h>
#define string(x) #x
#define printint(count) printf(#count " = %i\n", count);  
int main(void) {
  printf(string(hello people\n));
  int count = 100;
  printint(count);  // count = 100 // used as a string and var in same printf line
}
// *********
// # # operator joins tokens
#include <stdio.h>
#define printx(n) printf( "x%i = %i\n", n, x ## n )
int main(void) {
  int x20 = 20;
  printx(20);
  return 0;
}

INCLUDES, HEADERS, CONDITIONAL COMPILATION
// This is from masterC.c, see myheader.h in CMaster
// for system dependent code, debugging, etc.
// can include all commonly used definitions: struct defns, external var declarations, typedef defns, 
//    function prototypes declarations, macros, global var defns
// *****
// conditional compilation keywords
#ifdef, #undef, #ifndef, #elif, #else, #endif
#if defined(), #error
// *****
// to avoid multiple inclusion of a file from a #include
#ifndef HEADER    // if HEADER is not defined continue and define it, otherwise skip
#define HEADER
...
#endif
// *****
// each include replaces the statement with the file contents
#include "myheader.h"   // "" looks in one or more file dirs, like same folder, then system folders
#include <stdio.h>  // preprocessor looks in system dependent special dirs like usr/include
int main(void) {
  printf("%i\n", MAX(4,3));   // max in myheader.h
  printf("%s\n", HOME);       // system dependent vals
  printf("%s\n", SIGN);
  printf("%i\n", COUNT);
  return 0;
}
// *****
// as a debug tool
#include <stdlib.h>
#include <stdio.h>
#define DEBUG // this enables DEBUG statements, removing/commenting disables
int main(void) {
  int N = 10;
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      ;
#ifdef DEBUG
      printf("(%i,%i)\n", i, j);
#endif
    }
  }
  return 0;
}
$ gcc -D DEBUG test.c -o test // enables DEBUG, no need for #ifdef DEBUG line
// *****
// # error via preprocessor
#error An error has occured
// *****
// can also use a macro see debugPrint() above
// see #line for another preprocessor command
// #pragma action   // perform some compiler implementation defined action
// __LINE__, __FILE, __DATE__, __TIME__   // compiler info

STANARD LIBRARY

C++ STRINGS
// C++ string examples and methods, strings are mutable
// uses for each loop
#include <iostream>
#include <string>
using namespace std;
void print_by_char(string &name) {  
  for(char c: name) {
    cout << c;
  }
  cout << endl;
}
int main() {  
  string first{"Ben"};
  string last{"Harki"};
  string name{};
  name = first + " " + last;
  cout << name << endl; // Ben Harki
  cout << name[2] << " " << name.at(2) << endl;   // n n
  print_by_char(name);  // Ben Harki
  cout << "string has length " << name.length() << endl;  // string has length 9
  cout << name.find("Harki") << endl;   // "Harki" starts at index 4 
  cout << name.find('e') << endl;   // 'e' is at index 1
  cout << name.substr(2,6) << endl; // n Hark
  cout << name.insert(9, " Mags") << endl;  // Ben Harki Mags
  name[1] = 'A';
  print_by_char(name);  // BAn Harki Mags
  int i {342};
  cout << to_string(i) << endl;   // 342
  string s{"342"};
  cout << stoi(s)+1 << endl;    // 343
  return 0;
}

VECTORS
// C++ vectors are mutable
#include <iostream>
#include <vector>
#include <string>
using namespace std;
string vec_str(vector<int> &vec) {
  string s;
  for(int x : vec) {
    string e = to_string(x);
    s = s + e + " ";
  }
  return s;
}
int main() {  
  vector<int> vec{0,1,2,3,4};
  cout << vec_str(vec) << endl;   // 0 1 2 3 4
  vec[2] = 100;
  cout << vec_str(vec) << endl;   // 0 1 100 3 4
  vec.push_back(6);
  cout << vec_str(vec) << endl;   // 0 1 100 3 4 6
  cout << "vec has size " << vec.size() << endl;  // vec has size 6
  return 0;
}

EXCEPTIONS
// try, catch, throw
// runtime_error class contains a what method
#include <iostream>
#include <stdexcept>
using namespace std;
int main() {
  int n{4}, d{0};
  try {
    if(d==0)
      throw runtime_error("Cannot divide by zero");
    else
      cout << n/d << endl;
  }
  catch(runtime_error err) {  // catches thrown runtime exception
    cout << err.what() << endl;   // what() method contains "Cannot divide by zero"
  }
  return 0;
}

LAMBDAS
// function returns a lambda with proper closure of enclosing function
// [x,y] is a capture clause, can capture by value or reference, [] is no capture
// [=] captures all by value, [&] all by reference
// mutable allows an enclosing variable to be reassigned
#include <iostream>
#include <functional>   // to use function class, otherwise auto will deduce it
#include <algorithm>    // for_each, that accepts a lambda
#include <vector>
using namespace std;
auto sum_of_sum(int x, int y, int a, int b) {
  auto f = [&, y] (int a, int b) {return x + y + a + b;};   // lambda, captures x by reference, y by value
  return f; 
}
int main() {
  auto f = sum_of_sum(1, 2, 3, 4);
  cout << f(3,4) << endl;   // 10
  auto g = sum_of_sum(5, 6, 7, 8);    
  cout << g(7,8) << endl;   // 5+6+7+8 = 26
  cout << f(3,4) << endl;   // 10
  int j{10};
  cout << [&] (int i) mutable {return j+=i;} (5) << endl;   // 15, immediately invoked on 5
  cout << j << endl;    // 15
  function<int (int)> h = [] (int x) {return x;};
  cout << h(90) << endl;    // 90
  vector<int> v {1, 2, 3, 4};
  for_each(v.begin(), v.end(), [] (int &x) {cout << x;});    // 1234, lambda as an argument
  return 0;
}

SMART POINTERS
// smart pointers are automatically deleted 
// pass the smart pointer a raw pointer
// see also shared_ptr, to create multiple pointer variables for one location
#include <iostream>
#include <memory>   // for unique_ptr
#include <vector>
using namespace std;
void display(vector<int> &vec) {
  for(int &v : vec)     // accesses by reference
    cout << v;
  cout << endl;
}
int main() {
  unique_ptr<vector<int>> vec(new vector<int>({1,2,3,4,5}));   // new int[N] is a raw pointer on the heap to an int array
  display(*vec);    // 12345
  vec->push_back(6);
  display(*vec);    // 123456  
  return 0; 
}

CIN, COUT
// cin and 4 different output streams, all print to console
// simple input/output without using std namespace
// endl is next line and flushes the buffer
// flushing the buffer insures that all the data is written to out put and not sitting in the buffer
#include <iostream>
int main() {
  std::cout << "Type 2 ";
	std::cout << "chars: " << std::endl;   
  char c{}, d{};   // can leave out the braces
  std::cin >> c >> d;
  std::cout << "You typed " << c << " " << d <<  std::endl;
  std::cerr << "No error has occured " << std::endl;
  std::clog << "For general logging purposes" << std::endl;
  return 0;
}
// *****
// streams with << output operator return lhs of lhs << rhs
// same for >> streams
// this is an expression
// parens first, returns cout stream, then simplifies to next lhs << rhs
#include <iostream>
int main() {
  std::cout << "Ben Harki, " << "Mags Harki\n";   // returns the lhs stream obj
  (std::cout << "Ben Harki, ") << "Mags Harki\n";  // parens first, returns cout stream, then simplifies to next lhs << rhs
  return 0;
}
// redirect output to a text file:
> ./test.exe  > output.txt 
// *****
// while you can continue reading from the input stream
// input ends at '/n'
// while tests cin, tests its state, false when stream is at EOF, or has input error
// EOF is ctrl+z on Win, ctrl+d on Unix 
// TODO: write an if(std::cin>>value) program
#include <iostream>
int main() {
  int sum{0}, value{0};
  while (std::cin >> value)   
    sum += value; // equivalent to sum = sum + value
  std::cout << "Sum is: " << sum << std::endl;  
  return 0;
}
// send user text file as user input into this program
> get-content user.txt | ./test


OTHER TOPICS TO INCLUDE:
Operator Overloading
Copy/Move Constructors
Pointers to Functions
Reading and Writing Files
Examples using Standard Library
Containers
namespace
header files and multiple cpp files
<iterator>
<algorithm>
list