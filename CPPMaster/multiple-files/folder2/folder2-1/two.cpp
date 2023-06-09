#include "header2.h"

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

char *Two::get_name() {
  return this->name;
}

One *Two::get_one() {
  return this->o;
}

Two::Two(char *_name, int _i) 
  :name{_name}, o{new One{_i}} {}
