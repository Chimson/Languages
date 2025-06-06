/*
This file is a series of notes and programs I wrote while reading
Programming in C, Stephan Kochan, 4th Edition (gcc)
Its possible that some of these programs may be directly from the book, however
	it should only be a few
It may includes other programs that I wrote while working on other projects
I last checked most of these programs with Visual Studio C
	- Ben Harki
*/

USEFUL HEADERS
COMPILING
MAIN FUNCTIONS, EXIT, GOTO
DECLARING VARIABLES
DATA TYPES AND MODIFIERS
CONVERSION/CASTING
OPERATORS
PRINTF AND FORMAT STRING
ESCAPE CHARS
SCANF
LOOP AND LOOP KEYWORDS
DECISION MAKING
ARRAYS
FUNCTIONS
CHAR ARRAYS
STRUCTS/UNIONS
ARRAY OF STRUCTS
STRUCT OF STRUCTS
POINTERS
MACROS
INCLUDES, HEADERS, CONDITIONAL COMPILATION
ENUMS
TYPEDEF
FILE I/O
CALLOC, MALLOC, SIZEOF, FREE
OTHER UNIX UTILITES
MEMORY DUMP PROGRAM

$ /media/bharki/361E7C251E7BDC75/Users/Benso/Programming/Personal/masterC.c

USEFUL HEADERS
#include <stdio.h>  	// printf, ...
#include <stdlib.h>   // EXIT_FAILURE, EXIT_SUCCESS, calloc(), malloc(), ...
#include <stddef.h>   // size_t
#include <stdbool.h>	// bool, true, false, ...
#include <math.h>     // M_Pi, sqrt(), ...
#include <limits.h>   // INT_MAX, ....
#include <float.h>    // FLT_MAX, FLT_DIG, ...
#include <string.h>   // NULL, memcpy, ...
#include <wchar.h>   //  wchar_t

COMPILING
// see Makefile for compiling multiple files
// **********
// using gcc compiler 
$ gcc test.c
// *********
// flags to add
-o test  // generates executable named "test"
// linking libraries
-lm math.h, -llib mylib   
// define symbol for preprocessor, either 1 by default or with value given after =
-D UNIX, -D HOME=/home/bharki, -D DEBUG    
-c test.c  // generates test.o
-g, -Wall   // debug info added, display all errors   
// **********
// with multiple modules, see modules_main.c
> gcc module1.c modules_main.c -o modstest 
// **********
// execute
$ ./test
// *********
// compile/run in Clang
C:\> clang test.c -o test.exe
C:\> test.exe
// *********
// compile/run in Visual Studio C Clang
> cl test.c
> ./test

MAIN FUNCTIONS, EXIT, GOTO 
int main(void) {
  return 0;  // return system status to OS
}
// **********
// read command line args for main and print them:
// argc is arg count, argv is an array strings
// prints executable file name and the args
// will read one null pointer when reading past the argv array, then unauthorized reads
#include <stdio.h>
int main(int argc, char* argv[]) {  
  printf("%i args in argv\n", argc);
  for (int i=0; i<argc; i++)    // accessing anything past the size array returns a NULL pointer, see below
    printf("%s ", argv[i]);  // program name 
  printf("\n");
  return 0;
}
// $ ./test Ben Adam Finn Mags   // prints exactly these 5 values
// **********
// main with **char 
// **char is like an array of pointers
// run with command line args: > ./test Ben Harki 
// see below for memory output and to see what happens after you access past the pointer array
// see MEMORY DUMP PROGRAM for same example using mem_dump(), which will print each byte
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int main(int argc, char** argv) {
  if(argc != 3) {
    printf("You have to give the program 2 cmd line args!");
    exit(EXIT_FAILURE);
  }
  printf("%p: %p\n", &argv, argv);
  printf("%p: %p\n", argv, *argv);
  printf("%p: %p\n", argv + 1, *(argv + 1));  // one sizeof(ptr) over
  printf("%p: %p\n", argv + 2, *(argv + 2));
  printf("%p: %c\n", *argv, **argv);   // first char of first string: C,
  printf("%p: %c\n", *(argv + 1), **(argv + 1));    // first char of 2nd string: B
  printf("%p: %c\n", *(argv + 2), **(argv + 2));    // first char of 3rd string: H 
  printf("%p: %s\n", *argv, *argv);   // print the 1st string value
  printf("%p: %s\n", *(argv + 1), *(argv + 1));    // print the 2nd string value
  printf("%p: %s\n", *(argv + 2), *(argv + 2));    // print the 3rd string value
  printf("*****\n");
  int i = 0;
  for (char** ptr = argv; i++ < argc; ++ptr) {
    printf("%p: %s\n", *ptr, *ptr);
  }
  return 0;
}
/*
00F3FB90: 011992C8
011992C8: 011992D8
011992CC: 01199319
011992D0: 0119931D
011992D8: C
01199319: B
0119931D: H
011992D8: C:\Users\Benso\Programming\Languages\CMaster\Test\Debug\Test.exe
01199319: Ben
0119931D: Harki
*****
011992D8: C:\Users\Benso\Programming\Languages\CMaster\Test\Debug\Test.exe
01199319: Ben
0119931D: Harki
****
// this is from the debugger
0x011992C8  d8 92 19 01  Ø’..
0x011992CC  19 93 19 01  .“..
0x011992D0  1d 93 19 01  .“..
0x011992D4  00 00 00 00  ....   <- pointer past the 3rd char* to Harki is NULL
0x011992D8  43 3a 5c 55  C:\U   <- two pointers past is actually the string data
0x011992DC  73 65 72 73  sers
*/
// **********
// exit on bad input
int main(void) {
  int i;
  scanf("%i", &i)
	if(i==1)
		return 1;	// nonzero indicates error
	return 0;
}
// **********
// exit(n), any open files are closed, n is the same as return status
// EXIT_FAILURE  and EXIT_SUCCESS are defined in stdio.h
exit(1); exit(EXIT_FAILURE); exit(EXIT_SUCCESS);  // immediately terminates program, unlike return
// **********
#include <stdio.h>
#include <stdlib.h>  // for the exit macros
int main(void) {
  fprintf(stderr, "this program fails");
  exit(EXIT_FAILURE); // defines the exit status for use by another program
}
// check the status in PowerShell
// > $LastExitCode
// 1
// **********
// goto: branches immediately to the place marked by label: 
#include <stdio.h>
int main(void) {
  goto end;
  printf("This won't print!");
  end:
  return 0;
}

DECLARING VARIABLES
// must begin with letter or _ and can be followed by nums
int i;
int i, j;
int i = 1;
int i = 1, j = 2, k;
// **********
// initializing reserving bits using bit fields
#include "ben_functions.h"
#include <stdio.h>
struct packed {       //  8 bits defined by partitioning bits
  unsigned int  :3;    // unnamed reservation of 3 bits, maybe used for alignment
  unsigned int b:4;   // b is assigned 4 bits
  unsigned int c:1;   // c is assigned only 1 bit, in least significant bit
};
int main(void) {
  struct packed p;  // garbage
  p.c = 1;    // if too large, only low-order bits are assigned
  p.b = 10;
  printf("%i\n", p.c);  // 1
  mem_dump(&p, 8);     // D0 00 ... -> 0xD0 = 1101 000 -> 1 in lsb and 1010 in next higher 4 bits 
  return 0;
}

DATA TYPES AND MODIFIERS
// unsigned/signed char when needed sys portability, see sign extension 
_Bool, _Complex, _Imaginary
char, short, int, long, long long  // integral, from smallest to larger size
unsigned, signed  // can add to any of the above (alone its applied to an int)
float, double, long double  // floating point
size_t   // unsigned integer defined in stddef.h, size type for counts, mem addr 
// *********
auto  // for local vars that stay in function, compiler does this by default
const int i = 3;	// i cannot be changed, set in read only mem
// **********
// type qualifiers
register int i;   // requests the storing of i in a register, cannot further apply & to i
volatile int j;   // specifies that value will change, for optimization
restrict char *name;   // hint to compiler, name is the only reference to name's value in its scope
// **********
// literals, bases
12000  // int
050  // base 8
0xFF // hex
15U  // unsigned 
120000L, 120000LL // long, long long
1200000ULL   // combo
12.5f, 12.5, 12.5L   // float, double, long double
1e+3f // scientific float
0x1.3p	// hex floating pt
'a'  // ASCII 97
'z';  // ASCII 122
'0'  // ASCII 48
4    // also a char
bool, true, false // _Bool
0, 1  // _Bool, any non-zero is also 1



CONVERSION/CASTING
// int to float by assignment, implicit conversion
float j;
int i = 2;
j = i;
// **********
// by casting
float j;
int i = 2;
j = (float) i;  // conversion by explicit cast
// **********
// without an explicit cast, compiler casts to more complex type by each step
// f float, i int, l long int, s short
f*i+l/s   // (float)+(long int) = float


OPERATORS
+, -, *, /, %, +=, ...
==, <, >, <=, >=, !=  // >, <, >=, <= also works on chars
++i, i++, --i, i--
&&, ||
&, *, ->   // addr of, dereference, access member via pointer
&, |, ^, ~, <<, >>  // bit operators
,  // comma operator
// **********
// using the comma operator
#include <stdio.h>
int main(void) {
  int last[5] = {5,4,3,2,1}, num[5];
  int i = 0;
  while(i<5)
    num[i]  = last[i], i++ ;   // comma operator evals left to right, do not need braces
  return 0;
}

PRINTF AND FORMAT STRING
// putc(), puts() also writes to terminal by line
printf("number %i\n", 1);    // first arg is actually a pointer to that string char*
printf("number: %i\n",  // use next line via comma
	2)
printf("%i\n", 'a') // prints ASCII using %i
%i, %d,    // convert to decimal
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
// see chp. 15 for more printf options

ESCAPE CHARS
// use in strings "", ex: "\n"
\0,   // null character
\n, \b, \r, \t, \f, \v   // output formatting 
\\, \"", \'', \?  // print these specific chars
\a,   // audible alert 
\nnn   // ASCII character as octal number code in nnn form
\xnn   // ASCII character as code in hex
// see documentation for wchar_t chars
// **********
// ASCII hex code of '-'
#include <stdio.h>
int main(void) {
  printf("\x2D");    // -
}

SCANF
// always skips any leading entered whitespace by user
// returns number of fields read and assigned, need to give & or pointer arg
// reads up to a blank, tab, or end of line
// getc(), gets() also reads from the terminal by line
#include <stdio.h>
#include "ben_functions.h"
int main(void) {
  char name[5];    // should read into a buffer (do not give a pointer), but can overwrite past it
  printf("Enter your first name: ");
  int num_chars = scanf("%s", name);
  printf("read %i fields: %s", num_chars, name);
  mem_dump(name, 24);
}
// **********
// have user enter the number in this format
#include <stdio.h>
int main(void) {
  int num = 0;
  scanf("-%i-", &num);  
  printf("%i", num);
  return 0;
}
// **********
// terminates each string with '\0', could overflow the strings if > 10
#include <stdio.h>
int main(void) {
  char str1[10], str2[10], str3[10];
  scanf("%s%s", str1, str2);   
  scanf("%s", str3);  
  return 0;
}
// **********
// scan a preset number of chars using formated string
char name[4];
scanf("%3c", name); // reads only 3 chars and stores them adding a \0 in name
// *********
// getchar()
char c = getchar(); // reads a single char into c
// **********
// always stops at field width if supplied, or at invalid char
char text[6];
scanf("%5c", text);   // scans 5 chars and stores in text
// **********
// always stops at field width if supplied, or at invalid char
#include <stdio.h>
int main(void) {
  char text[6];
  scanf("%5c", text);   // scans only 5 chars from user, adds \0 and stores in text
  printf("%s\n", text);
  return 0;
}
// **********
// see chp 15 for more options


LOOPS 
// standard for loop 
// commas can be in either of the 3 loops, must eval to an expression (right-most statements)
#include <stdio.h>
int main (void) {
  char str[6] = "abcde";
  for (int i = 0; i < 6; ++i) {  // includes the "\0"
    printf("%c\n", str[i]);  
  } 
  char c;
  for (int i = 0; c = str[i], c++, i < 6; ++i) { // 
    printf("%c\n", c);   // prints ASCII code + 1 of each char in str
  }
  return 0;
}
// *********
// using a comma: must be of the same type in the first section
for(int i=0, j=0; i<10; i++) {  // commas in either of 3 sections connected with "and"
}
// **********
// null statement, i carried into next loop
int i = 0;
for(i; i<10;i++)
  ; // null statement
for(i; i<20; i++)
  ;
// *********
// while with a continue and break
// print even numbers
#include <stdio.h>
int main (void) {
  int i = -1;
  while (++i < 20) {
    if (i % 2 == 1) {
      continue;   // skip to the next iteration
    }
		else if (i == 16) {
      break;     // exit the loop immediately
		}
    printf("%i", i);   // 0, 2, ..., 14
  }
  return 0;
}
// **********
// basic do-while
int i = 0;
do {
  i++;
}
while (i<10);

DECISION MAKING
// if(bool condition or integral)
if (1) {	// also true for any nonzero
}
// *********
// if-else
if (1) {
}
else {
}
// **********
// this is the same as if(){} else{if(){} else{}}, independent cases (partition)
// also the same as switch below
int i;   // reads garbage
if (i<0) {
  printf("neg\n");
}
else if (i==0) {
  printf("zero\n");
}
else {
  printf("pos\n");
}
// **********
// switch on any integral value or boolean expression
#include <stdio.h> 
int main (void) {
  int k;
  switch (k % 4) {	
  case 0:
    printf("zero\n");
    break;	// omitting break will run into next case
  case 1:
  case 2:  // both cases execute "one or two"
    printf("one or two\n");
    break;
  default:
    printf("three\n");
    break;
  }
  char status = 'o';
  switch(status) {
    case 'o': {
      printf("on\n");
      break;
    } 
    case 'f': {
      printf("off\n");
      break;
    }
    default: {
      printf("invalid choice\n");
      break;
    }
  }
  return 0;
}
// **********
// ternary if-else
// add more ?: for else if
int x;
int y = (x % 2) ? printf("odd") : printf("even");	// ternary if then

ARRAYS
// *********
// initialize with integer literal or a macro (since it replaces with text)
// cannot initialize with variable, even if declared const
// if defined outside of main and all functions, then they are initialized to 0 by the compiler
// if defined locally in a function (including main) this picks up garbage ints, musr set each elem individually to init
// can read and access past the array bounds, elems are contiguous in memory
#include <stdio.h> 
#include "ben_functions.h"   // print_arr()
#define SIZE 10 
int zeros[SIZE];   
int main (void) {
	int garbage[10];    // grabs whatever was already in memory
  int nonzeros[10] = {1,2,3,4,5,6,7,8,9,10};   
  print_arr(zeros, SIZE);
  print_arr(nonzeros, SIZE);
  return 0;
}
// *********
 // assign by index
int nums[10];  // picks up garbage
nums[0] = 20;   // assign first elem the value 20
// **********
// partial and [] initialization 
int nums[10] = {0,1,2,3,4};    // rest of the elems are set to 0, no matter where it is defined
int nums2[10] ={[2]=2, [4]=4}; // in different order
int nums3[] = {0,1,2,3,4};  		 // only initalizes the elems shown
// **********
// multi-dim array 
int M[4][5];
// **********
// can omit row braces
int M[2][2] = {{0,1}, {2,3}};  
// **********
// partial initialization
int M[5][5] = {{0,1}, {2,3}};  // rest are set to 0s
int N[[4][5] = {[0][0]=1, [3][2]=4};  // rest are zero


FUNCTIONS
// compiler implicitly converts to parameter type in definition/prototype
// if type is left out of these, in return or parameter types, compiler may assume int or float
void function(void) {
}
int add(int x, int y, ...){ // variable number of args
}
// **********
// with prototype
#include <stdio.h>
int add(int, int);  // prototype needed since add is called in sum before it is defined
int sum(int n) {   // value of args from call are copied into local param variables
  float s = 0;
  for (int i=0; i<n; i++) {
    s = add(s,i);
  }
  return s;   // compiler will automatically cast return val as an int of return type
}
int add(int x, int y) {
  return x+y;
}
int main(void) {   // if no return type compiler assumes int
  printf("%.2i\n",sum(10));
  return 0;
}
// ***********
// with arrays (array name is a pointer to the first element)
// compiler does not copy the elems into the function's local space, only the pointer
#include <stdio.h>
//                       vals[][10]  // in multidim you need at least column size here
#define N 10
double sum(int n, double vals[]) {   // can explicitly define size of vals here, but is unnecessary
  double s = 0;
  for(int i=0; i<n; i++) {
    s += vals[i];
  }
	return s;
}
double sub(double array[N], double sum) {  // can use var size in array arg, as a macro or literal
  double s = sum;
  for(int i=0; i<N; i++) {
    sum -= array[i];
  }
  return sum;
}
int main(void){
  int n = 10;
  double vals[10] = {2.3, 6.7, 8.9};  // rest are 0s
  double s = sum(N, vals);
  printf("sum = %f\n", s);
  printf("sub = %f\n", sub(vals, s));
  return 0;
}
// **********
// global var used in count_zeros, defaults to 0 unlike local vars, 0's for arrays
#include <stdio.h>
int gcount;   // global var
void count_zeros(int n, int arr[]) {  // modifies global var
  for(int i=0; i<n; i++) {
    if(arr[i] == 0)
      gcount++;
  }
}
int main(void){
  int arr[10]= {[2]=4, [5]=9, [4]=10};
  count_zeros(10, arr);  // modifies without returning
  printf("%i\n",gcount);
  return 0;
}
// **********
// static vars do not reinitialize values, carry the current into future function calls
#include <stdio.h>
void count(void) {
  static int cnt;  // initalized only once to 0;
  const static int fixed = 100; // good here for performance, when fixed will never be changed
  cnt++;
  printf("%i\n",cnt);
}
int main(void){
  for(int i=0; i<10; i++) {
    count();  // prints 1,...,10
  }
  return 0;
}
// ***********
// global, static makes it "local" to only this file
#include <stdio.h>
static int counter = 10;
int main(void) {
  printf("%i\n", counter);
  return 0;
}

CHAR ARRAYS
// should always use '\0' the null char to end the string
// same initialization rules as arrays
char n = "";  // null string,  automatically adds \0
char ben[] = {'B', 'e', 'n'};    
char ben[] = {'B', 'e', 'n', '\0'};  // ideal, and equiv to below two lines
char ben[] = {"Ben"}; // includes null  
char ben[] = "Ben";   // includes null  
char ben[4] = "Ben";  // leaves space for null
char ben[3] = "Ben";  // no null
// **********
char ben[10] = {'b', 'e', 'n'};  // null chars are added for the remaining elems
char ben[3] = {'b','e','n'};     // null char is not added at the end here
char ben[4] = {'b', 'e', 'n'};   // adds null at end
// **********
// more printf
printf("Ben\n");  // full string is Ben\n\0, string adds null, print stops at next null
// **********
// does not set a null char at end
// printf will all chars up to the \0
// if the string is not null terminated, it will keep printing (depending on compiler)
#include <stdio.h>
#include "ben_functions.h"
int main(void){
  char ben[3] = {'b','e','n'};
  char adam[4] = {'a','d','a','m'};
  printf("%c\n",ben[3]);    // prints 'a'
  printf("%s\n", ben);   // prints "BenAdam" on some compilers
  mem_dump(ben, 24);
  return 0;
}
// **********
// similar to arrays, where each elem must be set individ
int N = 3;
char ben[N];    // picks up garbage
ben[0] = 'b'; ben[1] = 'e'; ben[2] = 'n';
// *********
// const string so that it is not changed in funct
// technically accepts the pointer to char array
#include <stdio.h>
void print_by_char(int N, const char string[]) {  // can rewrite without size using null char
  for(int i=0; i<N; i++) {
    printf("%c",string[i]);
  }
  printf("\n");
}
int main(void){
  int N = 3;    // no null char is set so size is needed
  char ben[3] = {'b', 'e', 'n'};
  print_by_char(N, ben);
  return 0;
}
// **********
// no size needed for char array
// accepts string as a pointer (not pass by value)
void print_by_char(const char string[]) { 
  for(int i=0; string[i]!='\0'; i++) {
    printf("%c",string[i]);
  }
  printf("\n");
}
// **********
// does not copy, operates on actual string bc var name is a pointer
#include <stdio.h>
void change(char name[]) {
  name[0]='a';
}
int main(void){
  char ben[10] = "Ben";
  change(ben);  // ben is a pointer to 1st char
  printf("%s\n",ben);   // prints "aen", %s requires pointer to first element, %c is the value
  return 0;
}
// **********
// string literals, concat and escape char example
char letters[] = {"abcd\   // using escape  \ in strings
efg"};
char letters[] = {"abcd" "efgh\n"});  // concats them
char letters[] = {"abcd"
                  "efgh\n"});   // also concats
// **********
// array names are like pointers to the first element
//    except that you cannot apply pointer arithmetic to them
// copy using a null statement and using pointers
// be careful not to printf("%s\n",to_ind) since to_ind points to \0 after the loop
#include <stdio.h>
int main(void){
  char to[6];  // allocate with garbage  
  char* to_ind = (char*) to;  // cast to allow ptr arith 
  char* from = "Harki";  // read only string
  while ((*to_ind++ = *from++) != '\0')  // should also copy \0 to to
    ;
  printf("%s\n", to);  // "Harki"
}
/*
  // same as above loop
  while(*from != '\0') {   // or the same with *to
    *to_ind = *from;
    to_ind++; 
    from++;
  }
*/
// **********
// initialize a char and a char pointer in the same line
char to[6], *tptr = to;
// **********
// some useful string functions
strlen(), strcmp(), strcat(), strcpy(), atoi(), isupper(), islower()
isalpha(), isdigit() 

STRUCTS/UNIONS
// simple struct where you can define objects with the definition
#include <stdio.h>
struct Person {
  char* name;
  int age;
} ben, mags = {"mags", 37};  // ben fields initialed to 0, mags is initialized
void print_person(struct Person p) {
  printf("%s: %i\n", p.name, p.age);
}
int main(void){
  ben.name = "Ben";
  ben.age = 39;
  print_person(ben);
  print_person(mags);
}
// **********
// structs can be defined inside a function
#include <stdio.h>
void print_person() {
  struct Person {
    char* name;
    int age;
  }; 
  struct Person mags = {"mags", 37};  
  printf("%s: %i\n", mags.name, mags.age);
}
int main(void){
  print_person();
}
// **********
// initializations of fields in a struct obj
// everything is allocated on the stack, pass by value
#include <stdio.h>
#include <stdbool.h>
#include "ben_functions.h"
struct bday {
  int month;  // defaults to 0 outside of all functions
  int day;
}; 
struct bday init(int month, int day) {
  struct bday name;   // creates an obj in local stack allocation for init
  name.month = month;
  name.day = day;
  return name;   // return a copy of the data to another location on stack (inside main)
}
bool isOct(struct bday name) {   // no pointer, so it operates on copy
  if(name.month==10)
    return true;
  return false;
}
int main(void){   // different ways to initialize
  struct bday ben;   // fields have garbage data
  struct bday adam = init(9, 23);
  struct bday mags = {6, .month=23};  // two  ways to initialize, can leave some empty
  struct bday finn;
  finn = (struct bday) {10, .day=20};  // assignment as a cast
  ben.month = 10; // should try not to inita field like this, maybe use a set or constructor function
  ben.day = 23;
  printf("%i/%i\n", ben.month, ben.day);
  printf("%i/%i\n", adam.month, adam.day);
  printf("%i/%i\n", mags.month, mags.day);
  printf("%i/%i\n", finn.month, finn.day);
  printf("%i\n", isOct(ben));
  return 0;
}
// **********
// unions   // store in the same memory area
union mixed {   // syntax identical to structs
  char c;       // not distinct atrs but a single member that could be "casted" as float, int, char
  int i;
  float f;
}
union mixed x;
x.c = 'K';    // only one value of either .c, .i, .f can be stored in x at a time
union mixed y = {'!'};  // is assigned in first listed, so y.c
union mixed z = {.f = 2.3;}; // can select "type" at init
// **********
// array defined using union
// unnamed struct that defines only one obk from it
#include <stdio.h>
#include "ben_functions.h"
#define N 2
enum Type {INT, CHAR};
struct {  // an array where each entry could be an int or char, labeled by type
  enum Type t;
  union {
    int i;
    char c;
  } data;
} table[N];
int main(void) {
  table[0].data.i = 0xFF;
  table[1].data.c = 'b';
  mem_dump(table, 16);
}
/*
00007FF790532C90:  00 00 00 00 FF 00 00 00  ........
00007FF790532C98:  00 00 00 00 62 00 00 00  ....b...
*/

ARRAY OF STRUCTS
#include <stdio.h>
struct bday {
  int month;
  int day;
}
print_bdays(int N, struct bday bs[N]) {   
  for(int i=0; i<N; i++) {
    printf("%i/%i\n",bs[i].month,bs[i].day);
  }
}
int main(void){   // different ways to initialize
  int N = 10;
  // can also drop the inner braces, rest are 0s
  struct bday bs[10] = {{10, 23}, {10, 20}, {6, 23}, [4].day=20,  [7]={9,23}};
  print_bdays(N, bs);
  return 0;
}

STRUCT OF STRUCTS
#include <stdio.h>
struct bday {   // structs can have arrays as atrs
  int month;
  int day;
};
struct weight {
  int wt;
};
struct person {
  struct bday birth;
  struct weight lbs;
};
int main(void){   // different ways to initialize
  struct person ben = {{10, 23}, {175}};  // can also use .weight=175
  printf("bday is %i/%i and weight %i lbs\n",ben.birth.month, ben.birth.day, ben.lbs.wt);
  return 0;
}

POINTERS
// need initialized to addr on heap or stack) use
#include <stdio.h>
int main(void){
  int* bad;    // addr is a garbage value, needs set by malloc or by a stack var like below
  int num = 10;
  int* nptr = &num; // holds location of num on stack, changing num changes value at the addr nptr points to
  printf("%i at %p\n", *nptr, nptr);   // *nptr dereference to read the value at addr nptr holds
  return 0;
}
// **********
// access struct values via pointer by  (*). or ->
#include <stdio.h>
struct name {
  char first[20];
  char last[20];
};
int main(void){
  struct name ben = {"Ben", "Harki"};  // on stack
  struct name *ben_ptr = &ben;
  printf("%s %s\n", (*ben_ptr).first, ben_ptr->last);
  return 0;
}
// **********
// assignment via (*). or ->
#include <stdio.h>
struct person {
  int age;
  int weight;
};
int main(void){
  struct person dude;     // garbage vals
  struct person *ptr = &dude; // pointers need initialized via stack or heap
  (*ptr).age = 37;
  ptr->weight = 175;
  printf("%i, %i\n", (*ptr).age, ptr->weight);
  return 0;
}
// **********
// fields are pointer
#include <stdio.h>
struct person {
  int* age;
  int* weight;
};
int main(void){
  struct person ben;
  int a = 37;
  int w = 175;
  ben.age = &a;
  ben.weight = &w;
  printf("%i, %i\n", *(ben.age), *(ben.weight));
  return 0;
}
// **********
// linked list - on stack
#include <stdio.h>
struct item {
  int n;
  struct item *next;
};
int main(void) {
  struct item first;  // garbage
  struct item sec;
  first.n = 1;        // initialize
  first.next = NULL;  // NULL pointer, can also cast 0 as (struct item *)
  sec.n = 2;
  sec.next = NULL;
  first.next = &sec;
  printf("%i\n", first.n);
  printf("%i\n", (first.next)->n);  // no need for parens bc . and -> are performed left to right
  struct item *root = &first;   // save first item
  while(root != NULL) {
    printf("%i\n",root->n);
    root = root->next;
  }
}
// **********
// const and pointers
#include <stdio.h>
int main(void) {
  int num = 10;
  int num2 = 0xF;
  // *****
  // const pointer:  pointer value is const (addr it holds is const)
  int* const cptr = &num;   
  // cptr = &num2;   // cannot change the addr the pointer holds
  *cptr = 0xFF;     // can change the value at the addr the pointer holds
  // *****
  // const value: value at addr held by pointer is const
  const int* cvptr = &num;    
  cvptr = &num2;  // can change the addr the ptr holds
  // *cvptr = 0xFF;  // cannot change the value the pointer points to
  // *****
  // both
  const int* const cvcptr = &num;  
  // cvcptr = &num2;   // pointer value (addr it holds) cannot change 
  // *cvcptr = 0xFF;   // the value it points to cannot change
  return 0;
}
// **********
// functions accepting pointers
// swaps the values the pointers point to, but not the addr they point to
// pointers are copied into local function variable as const pointers 
#include <stdio.h>
void swap(int* const x, int* const y) {   // copies the addrs to local pointers
  int t = *y;  // copies the val at the addr held by y into t
  *y = *x;   // y = x would make y hold the addr x holds, won't compile bc they are const 
  *x = t;
}
int main(void) {
  int x = 10, y = 20; // on stack
  int *xp = &x, *yp = &y;
  swap(xp,yp);
  printf("%i, %i\n", x, y);   // 20, 10
  swap(&x, &y);
  printf("%i, %i\n", x, y);   // 10, 20
  return 0;
}
// **********
// function that returns a pointer
// the pointer from main passes through the function
// should not return a pointer intiialized in a function
//    the location would be dealloc'd on function return
// params that accept pointers, can be called on & addrs
#include <stdio.h>
int* add(int* x, int* y, int* s) {
  *s = *x + *y;  // access values by derefs
  return s;    // return out the pointer
}
int main(void) {
  int x = 10, y = 15, s = 0;  // s is will be filled with sum
  int* sp = &s;
  sp = add(&x, &y, sp);  // addr held by sp does not change, it passes though the function
  printf("%i\n", *sp);
  return 0;
}
// ***********
// pointers and arrays
#include <stdio.h>
int main(void) {
  int arr[10] ={1,2,3};
  int *ap = arr;  // array names are pointers to the first element of array
  ap = &arr[0];  // address of first value
  printf("%i, %i, %i\n", *arr, *(arr+1), *(arr+2));  // add of 1 int over, address of 2 ints over
  *(arr+3) = 4; // 4 is set
  printf("%i, %i, %i, %i\n", *arr, *(arr+1), *(arr+2), *(arr+3));  // add of 1 int over, address of 2 ints over
  ap++;
  printf("%i\n", *(ap));   // 2
  return 0;
}
// **********
// loop using pointer arithmetic, which is faster sequentially than indexing
#include <stdio.h>
int sum(int N, int arr[N]) {
  int *const end = arr + N; // pointer is const, defined for optimzation
  int sum = 0;
  for(int *ptr=arr; ptr<end; ptr++) {
    sum += *ptr;
  }
  return sum;
}
int main(void) {
  int arr[10] = {1,2,3,4,5,6,7,8,9,10};
  printf("%i\n", sum(10, arr));
  return 0;
}
// ********** 
// above sum args as a pointer instead of array, they are equivalent
int sum(int N, int *arr) { // can use arr instead, operates on copy of arr pointer, not values
  int *const end = arr + N;
  int sum = 0;
  for(  ; arr<end; arr++) {   // 1st is left blank
    sum += *arr;
  }
  return sum;
}
// **********
// char array/pointer loop
#include <stdio.h>
void copy(char *from, char *to) {
  for(  ; *from!='\0'; from++, to++) {
    *to = *from;
  }
  *to = '\0';
}
int main(void) {
  char *from = "ABCDEF";  // used pointer form, could not do this is assignment if from is a char array
  char to[10];    // garbage
  char another[10];
  copy(from, to); // can use "ABCDEF" as an arg
  copy("1234", another);  // constant string "1234" is a pointer and is passed into copy
  printf("%s %s\n", from, to);
  wprintf("%s\n", another);
  return 0;
}
// **********
// constant strings, pointers, arrays
#include <stdio.h>
int main(void) {
  char ben[] = "Ben"; // ok in init but not assignment
//  ben = "name";    // fails
  char *adam = "adam";
  adam = "harki";    // ok bc "harki" is a pointer
  char *days[] = {"Monday", "Tuesday"}; // array of pointers to strings
  printf("%s\n", days[1]);  // print accepts pointers to strings
  return 0;
}
// **********
// pre vs post increment and pointers
#include <stdio.h>
int main(void) {
  int i = 0;
  printf("%i\n", i++); // 0, incremented after set as arg for print
  printf("%i\n", i);  // 1
  i = 0;
  printf("%i\n", ++i);  //  0, incremented then set as an arg
  printf("%i\n", i);    //  1
  char *ben = "Ben";
  printf("%c\n",*(ben++));    // B
  ben = "ben";
  printf("%c\n", *(++ben));   // e
  ben = "Ben";
  printf("%s\n", ben++);    // Ben, %s requires pointer not value like %c does
  ben = "ben";
  printf("%s\n", ++ben);   // en
  return 0;
}
// ***********
// versions of copy function modified using increment pointers
void copy(char *from, char *to) {
  for(  ; *from!='\0'; ) {
    *to++ = *from++;    // for each letter, assign then increment
  }
  *to = '\0';
}
void copy(char *from, char *to) {
  while(*from)  // if char is null, thn loop breaks
    *to++ = *from++;
  *to = '\0';
}
// **********
// sub pointers gives index or number of elements
char *harki = "Harki";
char *k = harki+3;    // k or 'h'+ 3 chars
printf("%c\n",*k);
printf("%li\n", k-harki);  // index of 3, needs li bc diff of addrs could be big
// **********
// pointer to a function
#include <stdio.h>
int add(int x, int y) {
  return x+y;
}
int multiply_by_2(int x, int (*fptr)(int,int)) {
  return fptr(x,x);
}
int main(void) {
  int (*fptr) (int, int); // declaration, no parens is a function returning a pointer
  fptr = add;             //function name is a pointer like an array name, can also use &add
  printf("%i\n", multiply_by_2(10,add));  // 20
  printf("%i\n", fptr(3,4));    // can use pointer to call function
  return 0;
}
// -----
// see CPPNOTES.cpp > POINTER for void* example

MACROS
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
// **********
// NULL pointer and PI
#include <stdio.h>
#include <math.h> // contains M_PI
int main(void) {
  int r = 4;
  int area = M_PI*r*r;
  int *ptr = NULL;    // NULL included in header stddef.h
  return 0;
}
// **********
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
// **********
//#define for program portability
#include <stdio.h>
#define DIR "/home/bharki/test.c"
int main(void) {
  printf(DIR);
  printf("\n");
  return 0;
}
// **********
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
// **********
// one #define in another
#define TWO 2     // can actually reverse these, but not advised
#define VAL TWO*x
// **********
// multiple line #define
#include <stdio.h>
#define SIGN if(x>0) {printf("pos\n");} \
            else {printf("neg\n");}
int main(void) {
  int x=-5;
  SIGN
  return 0;
}
// **********
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
// **********
// #define with >1 args    // parens avoid any issues in evals when inserting exprs, or used inside expr
#include <stdio.h>
#define MAX(x,y) ((x)>(y) ? (x) : (y))
int main(void) {
  int x = 18, y = 9;
  printf("%i\n", MAX(x+1,y-1)*100); // 1900
  return 0;
}
// **********
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
// see myheader.h
// for system dependent code, debugging, etc.
// can include all commonly used definitions: struct defns, external var declarations, typedef defns, 
//    function prototypes declarations, macros, global var defns
// **********
// conditional compilation keywords
#ifdef, #undef, #ifndef, #elif, #else, #endif
#if defined(), #error
// **********
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
// **********
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
// **********
// # error via preprocessor
#error An error has occured
// **********
// can also use a macro see debugPrint() above
// see #line for another preprocessor command
// #pragma action   // perform some compiler implementation defined action
// __LINE__, __FILE, __DATE__, __TIME__   // compiler info
// **********
// see modules_main.c, module1.c and MAKEFILE, for compiling multiple modules

ENUMS
// store only one value from a collection
// associates a name to an integer, can only change in initialization
// in practice treat as distinct data types, not integers
// want names to be unique in scope
#include <stdio.h>
int main(void) {
  enum month {JAN, FEB, MAR, APR, MAY}; // definition, can use lowercase vars //  JAN is 0, FEB is 1, ...
  enum month thismonth = FEB;
  printf("%i\n", thismonth);  // 1
  int days = 0;
  switch(thismonth) {
    case JAN:
    case MAR:
    case MAY:
      days = 31;
      break;
    default:
      printf("not 31 days or check other 7 months\n"); 
      break;
  }
  return 0;
}
// *********
// set the values manually
#include <stdio.h>
int main(void) {
  enum nums {ONE=1, TWO, THREE, FIVE = 5, SIX};  // not starting at 0, but 1 
  enum nums num1 = SIX, num2;
  num2 = (enum nums) (num1-1);    // assign as a cast
  printf("%i\n" , num2);
  printf("%i, %i, %i\n", ONE, TWO, SIX);    // 1, 2, 6
  return 0;
}
// *********
//  unnamed enum, declaration and assignment at end like struct
// follows normal scope rules
#include <stdio.h>
enum {east, west, north , south} direction = west; // direction is declared and init of unnamed type, global
int main(void) {
  printf("%i\n", direction);  // 0
  return 0;
}

TYPEDEF
// creates custom type names, provides more flexibility than using #define
#include <stdio.h>
int main(void) {
  typedef int Counter;
  Counter i = 0;            // declaration and initialization
  typedef int Array[10];    // if use #define it would not be equivalent
  Array num1 = {1,2,3};
  typedef char *Strptr;
  Strptr string = "Ben";    // string is a pointer
  printf("%s\n", ++string); // en
  typedef double Dubs[15];
  Dubs anoth;               // declaration, no init
  anoth[0] = 10;
  printf("%f, %f\n", anoth[0], anoth[9]);   // 10, 0
  return 0;
}
// **********
// in structs and functions
// creates custom datatypes, provides more flexibility than using #define
#include <stdio.h>
#include "myheader.h"   // can include typedef definitions
typedef struct {
  char* first;
  char* last;
} Person;
void print_name(Person *p) {  // p is a pointer to Person
  printf("%s %s\n", p->first, p->last);
}
int main(void) {
  Person ben;          // on stack
  ben.first = "Ben";
  ben.last = "Harki";
  Person people[25];  // array of 25 people
  print_name(&ben);
  Counter i = 1;    // in myheader.h
  return 0;
}
// **********
// another way for typedef structs
struct Dude {
  char* first;
  char* last;
};
typedef struct Dude Person;   // now named Person

FILE I/O
// redirect printf statements in UNIX writes to a file
#include <stdio.h>
int main(void) {
  int num;
  printf("Enter a number: ");
  scanf("%i", &num);
  prinf("i\n", num)
  return 0;
}
$ ./io > io.txt   // user types 458485 and enter,  overwrites or creates new io.txt
$ cat io.txt
$ Enter a number: 458485
// **********
// load from a text file
// load.txt contains an int
$./io < load.txt    // prints to console
$(./io < load.txt) > io.txt // loads data, print result to io.txt, don't need ()
// *********
// end of file is a single \n on its own line
// EOF is defined in stdio.h as an int
#include <stdio.h>
int main(void) {
  int c;    // int ensures that the character is unique, see sign extension
  while( (c=getchar())!= EOF ) {    // gets char from terminal input
    putchar(c);   // prints each char in terminal
  }
  return 0;
}
$ ./test < load.txt   // echos load.txt on terminal
3344889
// **********
// fopen() returns a FILE* or NULL if fails
// write and append creates a new file if it dne, read is an error 
FILE *readfile = fopen("load.txt", "r");  // "w" is write, "a" is append
// "r+", "w+", "a+" are update modes, can perform both reading and writing, "rb" is read binary in win
// *********
// open file and check if it was successful
#include <stdio.h>
int main(void) {
  FILE* readfile;
  if( (readfile=fopen("load.txt", "r"))==NULL ) 
    printf("File was not read");
  fclose(readfile);
  return 0;
}
// **********
// getc() from input and putc() to output
FILE *readfile = fopen("load.txt", "r");  // "w" is write, "a" is append
int c = getc(readfile)  ;  // reads a char from file, returns EOF at end of file 
FILE *output = fopen("output.txt", "w")
putc('\n', output); // writes newline to file 
fclose(readfile); fclose(output);   // performs houskeeping/flushing of buffer
// **********
// reads from load2.txt and copies into output.txt
#include <stdio.h>
int main(void) {
  FILE *readfile, *outfile;
  if( (readfile=fopen("load2.txt", "r"))==NULL ) {
    printf("File was not opened to read");
    return 1;
  }
  if( (outfile=fopen("output.txt", "w"))==NULL ) {
    printf("File was not opened to write");
    return 2;
  }
  int c;
  while( (c = getc(readfile))!=EOF ) {
    putc(c, outfile);
  }
  fclose(readfile);
  fclose(outfile);
  return 0;
}
// **********
// feof() // test if you are reading  past the end of the file
FILE *readfile;
readfile = fopen("load.txt", "r");
if(feof(readfile)) {  // returns nonzero if you are reading past the end, not at end
  printf("no more data in file");
  return 1;
}
// *********
// fprinf(), fscanf(), write formatted string to file, scan formatted string from file 
#include <stdio.h>
char buf[100];  // initializes buf with nulls
int main(void) {
  FILE *outfile = fopen("output.txt", "w");
  char* sent = "I have a boy named Finn.";
  fprintf(outfile, "%s", sent);   // write sent of format to outfile
  fclose(outfile);
  FILE *readfile = fopen("output.txt", "r");
  fscanf(readfile, "%25c", buf);   // read from readfile using format into anoth 
  printf("%s\n", buf);
  fclose(readfile);
  return 0;
}
// **********
// fgets() read a lines of a file, reads until newline or n
FILE* readfile = fopen("load2.txt", "r"); 
char store[50];
fgets(store, 25, readfile);   // reads max 25 chars from a line in readfile, store it in store 
// places /0 in store, returnsstroe ir NULL if unsuccessful
// **********
// fputs() writes a line of chars to a file
FILE* outfile = fopen("output.txt", "w");
fputs(store, outfile);    // writes until \0 char of store but does not write the \0
// **********
// rename(), remove()
rename("output.txt", "newname.txt");  // deletes file,  returns nonzero on failure
remove("newname.txt");   // deletes file

STDIN, STDOUT, STDERR
const FILE *stdin, *stdout, *stderr;  // opened automatically on execution of program, in stdio.h
// **********
// stdin, stdout are associated to the terminal 
fscanf(stdin, fstring, store);   // same as scanf(string, store); reads terminal input
fprintf(stdout, fstring)    // same as printf(fstring); // printf to terminal
// **********
// stderr
FILE *readfile;
if( (readfile = fopen("dne.txt", "r"))== NULL ) {
  fprintf(stderr, "File does not exist!\n"); // prints error to console
}
// check out perror() // reports errors from standard lib routines
// **********
// getchar from input, using a null statement
#include <stdio.h>    // inclues EXIT_FAILURE, EXIT_SUCCESS
char text[20];    // initializes to 0's
int main(void) {
  char* tptr = text;
  while ( (*tptr++ = getchar()) != '\n' )
      ;
  printf("%s", text);
  return 0;
}
// *********
// other loops scanning chars/printing chars using null statement
char c;
for (  ; (c = getchar()) != EOF;  putchar(c) )  //  char from input and prints
  ;
for(int count = 0;  getchar()!= EOF;  ++count ) //  // counts character from input
  ;

CALLOC, MALLOC, SIZEOF, FREE
// sizeof(), returns # of bytes, args can be a var, array name, type, expression
// use sizeof to avoid hard-coding or calculating byte sizes
sizeof(int);  // returns number of bytes of an integer
int x[100]; sizeof(x);  // number of bytes to store array
sizeof(struct Person);   // number of bytes to store a Person
sizeof(x)/sizeof(x[0]);   // # of elements in the array x
// **********
// calloc and malloc, dynamcally store on the heap
// both return void* type, cast to type you need, will return NULL if not enough mem
#include <stdio.h>
#include <stdlib.h> // for calloc, malloc
int main(int argc, char *argv[]) {
  char *moremem = (char *) calloc(100, sizeof(char)); // to store 100 chars, initializes mem to 0
  char *evenmore = (char *) malloc(100*sizeof(char)); // does not initialize
  free(moremem);
  free(evenmore);
  return 0;
}
// **********
// using with structs, typedef
#include <stdlib.h>
struct Person {
  char *first;
  char *last;
};
typedef struct {
  int month;
  int day;
} Date;
int main(void) {
  struct Person *people = (struct Person *) malloc(100*sizeof(struct Person));  // room for 100 ppl
  Date *calendar = (Date *) calloc(365, sizeof(Date));  // 365 Dates, calendar points to the first 
  free(people); // arg of free should always be the beginning of the allocated mem
  free(calendar);
  return 0;
}
// **********
// can also use realloc()


OTHER UNIX UTILITIES
/*
see  Makefile
CVS - Concurrent Versions System
  helps avoid conflict if more than one programmer edits the same source file
  programmers can be at multiple locations and all work on the same source code over a network
ar
  compiles your libraries
grep
  $ grep Ben modules_main.c   // searches Ben in modules_main.c
  $ grep -n Person *.c *.h    // searches all .h and .c  and displays results with line nums (-n)
gdb // debuggng program
  see ch. 17 for gdb info
*/

MEMORY DUMP PROGRAM
// example of using mem_dump
#include <stdio.h>
#include "ben_functions.h"
int main(void) {
  int i = 9;
  int* pi = &i;
  mem_dump(&i, 8);   // &i : 9
  mem_dump(&pi, 8);  // &pi: pi  (where pointer var lives: addr it holds as a value)
  mem_dump(pi, 8);   // pi: *pi  (addr value the pointer holds: value at that addr)
}
// **********
#include <stdlib.h>
#include <stdio.h>
// run main with > ./test Ben Harki
// mem_dump is defined in ben_functions.h
int main(int argc, char** argv) {
  if(argc != 3) {
    printf("You have to give the program 2 cmd line args!");
    exit(EXIT_FAILURE);
  }
  mem_dump(&argv, 8);
  mem_dump(argv, 24);
  mem_dump(*argv, 8);
  mem_dump(*(argv + 1), 8);
  mem_dump(*(argv + 2), 8);
  return 0;
}
/*
0000005D76DBFBC8:  E0 AE 2C 43 F6 01 00 00  α«,C÷☺..
000001F6432CAEE0:  00 AF 2C 43 F6 01 00 00  .»,C÷☺..
000001F6432CAEE8:  36 AF 2C 43 F6 01 00 00  6»,C÷☺..
000001F6432CAEF0:  3A AF 2C 43 F6 01 00 00  :»,C÷☺..
000001F6432CAF00:  43 3A 5C 55 73 65 72 73  C:\Users
000001F6432CAF36:  42 65 6E 00 48 61 72 6B  Ben.Hark
000001F6432CAF3A:  48 61 72 6B 69 00 00 00  Harki...
*/





















































































