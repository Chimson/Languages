NEW PROJECT
// uses the SwiftPM ro create a swift project
// create a MyCli directory and in the dir:
> swift package init --name MyClI --type executable
// this adds:
// MyCli
//  Sources
//    main.swift      // application entry point
//  .gitignore
//  Package.swift     // metadata and dependencies

RUN, BUILD, REPL
// assume you are in the MyCli dir
// run:
> swift run    // can throw an error if Xcode is not installed
> swift run MyCli   // also works
// build:
> swift build
// repl:
> swift repl

FIRST FILES
// main.swift is the default entry point
// does not need to contain a main function
// main.swift
print("Hello, World")
// define your own entry point using @main in your own file
// Test.swift  (use a different file name)
@main
struct Test {
  static func main() {
    print("Hello, Swift!")
  }
}
// must choose one or the other methods above but not both
// SEE COMMAND-LINE TOOL FOR ADDING DEPENDENCIES, IMPORT
//   AND ARGUMENT PARSING PACKAGE

FUNDAMENTAL TYPES
// numeric or boolean
Int, Double, Bool, String
// ----
// containers
// Array, Set, Dictionary, 

CONSTANTS AND VARIABLES
// let is used to declare constants that cannot change (immutable)
// var is used for variables, who can change (mutable)
let const = 3.14
// const = 6    // throws error
var x = 10
x = 11
print(const)
print(x)
// -----
// declare variable or constant names and initialize
//   them later
// they must have a value before they are read
let const: Int
var name: String
// print(name)    // throws error
const = 10
name = "Ben"
print(const)
print(name)
// -----
// declare or initialize variables or constants in one line using a comma
var x: Int, y = 3, z = 10 
x = 1
print(x, y, z)

// Stopped on The Basics > Type Annotations