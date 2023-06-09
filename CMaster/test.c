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
