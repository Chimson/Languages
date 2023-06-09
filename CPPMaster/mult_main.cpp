#include <iostream>

// (header guards stop multiple inclusion, since header2.h includes header1.h

// did not have to path to here using -I
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

/*
Compile and Run:
// mult_main.cpp is now in a different place than multiple-files/main
// -I seaches a new directory for "header2.h"
> cd ~/Languages/CPPMaster
> clang++ mult_main.cpp ./multiple-files/folder1/one.cpp ./multiple-files/folder2/folder2-1/two.cpp -o mult_main -I ./multiple-files/folder2/folder2-1
*/

int main() {
  std::cout << "Hello from ./main/main.cpp" << std::endl;
  
  One o = One(10);
  std::cout << "I can see ./folder1/one.cpp:" << std::endl;
  std::cout << "One object val: " << o.get_int() << std::endl;
  
  Two t = Two("Ben", 20);
  std::cout << "I can see ./folder2/folder2-1/two.cpp:" << std::endl;
  std::cout << t.get_name() << ": " << (t.get_one())->get_int() << std::endl;

} 