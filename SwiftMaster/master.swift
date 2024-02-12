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
// if you want your own entry point, other than main.swift
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