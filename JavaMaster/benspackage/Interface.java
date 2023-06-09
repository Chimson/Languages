// interface must be the same name as file, only one public interface per file
// all methods are implicitly public
// variables are static (from the point of view of interface name not the implementing class) and final
// can be used to make variables global to a class that implements the Interface, like final
package benspackage;
public interface Interface {    // public allows access from outside the package
  String BEN = "Ben Harki";     // defines global variables
  void print(String greeting);   // implemented when inhertited by "implementing" keyword, implementation in Master.java
}



