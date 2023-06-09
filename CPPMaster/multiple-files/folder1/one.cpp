#include "header1.h"

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

int One::get_int() {return this->myint;}  
One::One(int _i)
  : myint{_i} {}
