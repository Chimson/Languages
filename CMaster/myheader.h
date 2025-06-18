// avoid multiple inclusion of this file, especially if its included in another header
#ifndef _MYHEADER_H
#define _MYHEADER_H 1     // sets to 1, if included again is is defined, skips everything after ifndef
// you really don't need the 1 value to define a macro

// can include all commonly used definitions: struct defns, external var declarations, typedef defns, 
//    function prototypes declarations, macros, global var defns

// common to put typedef definitions here
// can be nested, aka can add another include file here
#define MAX(x,y) ((x)>(y) ? (x) : (y))

// for system dependent values
// statements are ignored if UNIX is not defined
#define UNIX 1   // UNIX must be defined before, can use  $ gcc -D UNIX test.c  instead
#ifdef UNIX
#   define HOME "/home/bharki"
#else
#   define HOME "/win11/usr/benso"
#endif

// #if, #elif
#define NUM -5
#if NUM < 0
#   define SIGN "neg"
#elif   NUM > 0
#   define SIGN "pos"
#else
#   define SIGN "zero"
#endif

// if defined()
#define LARGER10 1
#if defined(LARGER10) || defined(POS)
#   define COUNT 10
#else
#   define COUNT -10
#endif

// #undef
#define CST 100
#undef CST    // #ifdef CST or #if defined(CST) will be false

// typedef
typedef int Counter;

// class used in module1.c and main_modules.c
typedef struct {
  char *first;
  char *last;
} Person;

// prototype of function in module1.c
void create_person(Person*, char*, char*);   // definition in module1.c, f's do not need extern

extern int i;                           // global from module1.c


#endif    // _MYHEADER_H





