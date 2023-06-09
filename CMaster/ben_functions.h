#ifndef _BEN_FUNCTIONS_
#define _BEN_FUNCTIONS_ 1

#include <stdlib.h>  // EXIT_FAILURE
#include <stdio.h>   // printf

// (should place this in a .c file, and its prototype here, but I got lazy)

// should only give some mem_dump some multiple of bytes to show for now
// can only show lines of 8 bytes at a time
// shows data located at the pointer's value

void mem_dump(void* vptr, int bytes) {
  if (bytes % 8 != 0) {
    printf("You need to give bytes in mem_dump a multiple of 8!");
    exit(EXIT_FAILURE);
  }
  char buff[] = "00000000";  
  unsigned char* cptr = (unsigned char*) vptr;
  for (int i = 0, b_ind = 0; i < bytes; ++i, ++b_ind) {
    if (i % 8 == 0) {
	    if (i != 0) {printf(" %s", buff);}
	    printf("\n%p:  ", &cptr[i]);
	    b_ind = 0;
    }
	  buff[b_ind] =    // store it or replace anything that might not print with a .
      (cptr[i] == 0) || (cptr[i] == '\n') || (cptr[i] == '\r') || (cptr[i] == '\t') || 
          (cptr[i] == 0x0B) || (cptr[i] > 0x7E) ?
        '.' : 
        cptr[i];
    printf("%02X ", cptr[i]);
  }
  printf(" %s\n", buff);
}

void print_arr(const int* const arr, const int size) {
  for (int i = 0; i < size; ++i) {
    printf("%i\n", arr[i]);
  }
}

#endif