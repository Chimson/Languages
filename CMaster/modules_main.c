// TO COMPILE AND RUN 
// compile this modules_main.c together with module1.c, all in the same folder
// can also use a MakeFile: see MAKEFILE in this dir
// > gcc module1.c modules_main.c -o modstest
// > ./modstest

// SEE MAKEFILE
#include <stdio.h>
#include "myheader.h"   // contains Person struct and create_person() proto, extern int i;

// can include prototypes (here or on .h file) of function in another .c file
// this is so compiler doesn't make assumptions on type of return/args if compiled seperately
void hello(void);

// static function, only called in this file, without static the functions is extern by default
static void hi(void) {
  printf("I can only be called in this file: modules_main.c\n");
}

// EXTERN
extern char counter;                    // from module1.c
char *from_main = "Hello from main!";   // used as an extern in hello in module1.c
extern int e = 15;   // can initialize e defined in module1.c, but compiler does give a warning
double arr[20];     // used in module1.c
int two[20][20];

// STATIC
static int a = 10;  // global, but "local" only to this file, not accessible by extern in another

int main(void) {
  printf("%i\n", i);  // i is declared extern in myheader.h, global on module1.c
  printf("%c\n", counter);
  hello();                  // hello in module1.c but uses from_main defined in this file
  printf("%i\n", e);

  // function found in module1.c
  Person p;
  Person *ben = &p;
  create_person(ben, "Ben", "Harki"); // defined in module1.c, proto in myheader.h
  printf("Hi %s %s!\n", ben->first, ben->last);
  hi(); 
  return 0;
}
