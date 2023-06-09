#ifndef _MODULE1_C
#define _MODULE1_C 1

#include <stdio.h>
#include "myheader.h"   // contains Person struct

// by default this can be accessed in other files, extern by default
void create_person(Person *p, char *f, char *l) {
  p->first = f;
  p->last = l;
}

// EXTERN
// globally defined variable, use extern in other file/files to use this
// extern can only be omitted once (if uninitialized) in a group of compile files
int i;                  // used in modules_main.c, declared extern in myheader.h
char counter = 'b';     // used in modules_main.c
extern int e;          // can be declared extern in all files as long as initialized in one
extern double arr[];    // do not need size with arrays, from modules_main.c
extern int two[][20];   // do not need 1st dimension for 2d arrays

//  access an extern var defined in main;
void hello(void) {
  extern char* from_main;   // brought in from modules_main.c
  printf("%s\n", from_main);
}

#endif
