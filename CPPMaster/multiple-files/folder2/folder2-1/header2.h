#ifndef _HEADER2_H
#define _HEADER2_H 1

#include "../../folder1/header1.h"

/*
.
├── folder1
│   ├── header1.h
│   └── one.cpp      // #include "header1.h" 
├── folder2
│   └── folder2-1
│       ├── header2.h  // #include "../../folder1/header1.h"
│       └── two.cpp   //  #include "header2.h"
└── main
    └── main.cpp    // #include "../folder2/folder2-1/header2.h"  
*/

class Two{
  private:
    char *name;
    One *o;
  public:
    char *get_name();
    One *get_one();
    Two(char *_name, int _i);
}; 


#endif