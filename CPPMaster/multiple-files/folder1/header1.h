#ifndef _HEADER1_H
#define _HEADER1_H 1

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

class One {
  private:
    int myint;
  public:
    int get_int();
    One(int _i);
}; 


#endif