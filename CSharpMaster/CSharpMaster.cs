From C# 8.0 and .NET Core 3.0 4th Edition
SKIPPED: Chp 2 > Exploring Console Applications Further
SKIPPED: Chp 3 > Casting and Converting Between Types > Converting From a Binary Obj to a String
							 > Parsing from strings to numbers or dates and times
							 > Checking for Overflow
SKIPPED: Chp 4 > Writing Functions > documenting functions with xml comments
							> debugging during development
							> logging during development and runtime
							> unit testing functions
SKIPPED: Chp 5 > writing and calling methods > combining multiple return values using tuples
SKIPPED: Chp 6 > managing memory types > releasing unmanaged resources
																			 > ensuring that dispose is called 
							 > inheriting from classes > preventing inheritance and overriding
STOPPED AT: Chp 7

COMPILE AND RUN
C# REPL
COMMENTS
FIRST PROGRAM
USING, NAMESPACE, MULTIPLE FILES
ASSIGNMENT
OPERATORS
TYPES
CASTING AND CONVERSION
LITERALS
STRING
ARRAY
NULLABLE
CONTROL
LOOPS
EXCEPTION
FUNCTIONS, METHODS
CLASS
PROPERTY
INDEXER
MEMORY
FUNCTIONAL PROGRAMMING AND DELEGATES
CONST, READONLY, IN
SAFETY
ENUM
GENERICS
OPERATOR OVERLOADING
INTERFACES
INHERITANCE
ATTRIBUTE
.NET PLATFORM
SYSTEM
CONSOLE
MATH
OBJECT
ASSERT
LIST
TUPLE
OS

COMPILE AND RUN
// create a console app and run it
> dotnet new console      // creates /bin, /obj, Program.cs, .csproj file, ..., etc
> dotnet run 
> dotnet run -- cmdarg1 cndarg2   // passing args to current application 

UNIT TESTING
// unit testing library in NUnit.Framework
// using NUnit and console
/*
Overall Structure, as two seperate projects, only some files shown
	/Project
		/Main    
			Program.cs   // contains Main()
			Project.csproj
			/ProjLib     // ProjLib namespace where code is located, but is not a dotnet classlib proj
		/Test    (contains unit test classes and methods)
			UnitTest1.cs
*/
/Project/Test> dotnet new nunit
/Project/Test> dotnet add reference ../Main/Project.csproj   // allows Test proj to see src proj 
/Project/Test> dotnet test   // run unit tests
// add to /Test/UnitTest1.cdd to see the code lib:
using ProjLib; 
// -----
// There are other ways to do this with a dotnet classlib and dotnet sln, see MS documentation

C# REPL
// C# has script files .csx, that can be run in CSI, C# Interactive
// can start the repl with csi.exe in VS Powershell, can also run with a script
// some programs in this file are scripts, without the class Program wrapping needed for .cs files
> csi
> csi script.csx

COMMENTS
// single line
/* 
	multiline
*/

FIRST PROGRAM
// for compiled .cs files
// statements end in ;
using System; 
namespace Basics {     // custom namespace
	class Program {
		static void Main(string[] args) { 
			Console.WriteLine("Hello World!");  
		} 
	}
}

USING, NAMESPACE, MULTIPLE FILES
// "using" brings a namespace into scope
// this means you do not need to have namespace prefixes on code from other libs
// System is a namespace
using System;   // System could be automatically in scope by default
class Program {
  static void Main(string[] args) { 
    Console.WriteLine("hi");
  }
}
// -----
// Console is a class and can be used statically (without a object) by using static
using static System.Console;
class Program {
  static void Main(string[] args) { 
    System.Console.WriteLine("hello");   // System is a namespace, Console a class in the namespace
    WriteLine("hi");
  }
}
// -----
// create a class file
// create folders: Code > Chapter5 > PacktLibrary to hold the class
> dotnet new classlib   // creates /obj, Class1.cs (rename to Person.cs), .csproj
// -----
// create folders: Code > Chapter5 > PeopleApp
> dotnet new console
// add PacktLibrary dependency to PeopleApp.csproj after <PropertyGroup> 
<ItemGroup>
	<ProjectReference Include="../PacktLibrary/PacktLibrary.csproj" />
</ItemGroup>
// now compile, in /PeopleApp
> dotnet build
// -----
// now PacktLibrary has Person.cs, inside PacktLibrary namespace, and contains Person class:
// PacktLibrary/Person.cs:
	// public makes the class accessible from any other code
	// without public, it is internal by default: only accessibly in this file 
	namespace PacktLibrary;
	public class Person {}
// PeopleApp/Program.cs:
	using PacktLibrary;   // brings PacktLibrary namespace into scope, it contains Person class
	class Program {
		static void Main(string[] args) { 
			Person p = new Person(); 
		} 
	}
// -----
// see "using" keyword in OS example
// TODO: figure out how to add multiple .cs files to one class lib, used in one console proj


ASSIGNMENT
// declare and assign
int i = 3;

OPERATORS
// assignemnt
=
//arithmetic
+ - * / %
// mixed
+= -= *= /= %=
// postfix and prefix incrementing
++i; i++;   
// boolean, return bool, applied to bool
& | ^
// conditional, are short-circuiting
&& ||
// bitwise and shift, applied to integral vals
& | ^ << >>
// other
() [] . 

TYPES
// may not be full list
int, uint, short, long, float
double, decimal   // decimal is better for checking equality accuracy than doubles
bool
object
null
// -----
// sizeof() returns num of bytes the type takes up in memory
int b = sizeof(int);  
// -----
// typeof() returns Type
class Program {
  static void Main(string[] args) { 
    Type t = typeof(int);
    Console.WriteLine($"{t}");   // System.Int32
  } 
}
// -----
// nameof() returns the variable name as a string
int age = 32;
string n = nameof(age)   // age
// -----
// MinValue and MaxValue returns the largest and smallest int values
// other similar constants
int.MinValue; int.MaxValue
double.Epsilon, double.NaN, double.Infinity
// -----
// object can hold any type, must cast to use a method
// dynamic can hold any type but does not need a cast
object name = "Ben Harki";
Console.WriteLine("{0}", ((string)name).Length);
dynamic name2 = "Mags";
Console.WriteLine($"{name2.Length}");
// -----
// var has the compiler infer the type
// may be useful to avoid refactoring
var x = 3.14;
// -----
// default() determines the default value for a type
default(int);
// -----
// Parse() will attempt to interpret a string as another type
// TryParse() will do the same and return true if it can, false if not
string s = "54";
int i = int.Parse(s);
int j;
bool b = int.TryParse(s, out int j); 

CASTING AND CONVERSION
// implicit casting is safe
int i = 32;
double d = i;   // no loss of data
// -----
// explicit casting, may have loss of data 
// throws an error, unless you force a cast
double d = 3.14;
int i = (int) d;  
// -----
// System.Convert will round
double d = 3.14;
int i = Convert.ToInt32(d);  // 3
// -----
// see INHERITANCE for casting between subclasses and superclasses, implicit and explicit
// see INHERITANCE for if(is){} block to deal with explicit subtype and supertype casts
// see INHERITANCE for as, as a substitute for an explicit cast in inheritance

LITERALS
char l = 'A';
string s = "Ben";
int mill = 1_000_000;
int b = 0b_1111_1111;
int h = 0x_FF_FF;
bool t = true;
bool f = false;
// -----
// other literals
var l = 31000L;  // long
var d = 3.14M;  // decimal
var f = 3.14F  // float

STRING
// $ allows embedding of variable syntax for string, see CONSOLE
// @ are verbatim strings, \n is not interpreted as escape chars 
int i = 3; double p = 3.14;
string s = $"{i}, {p}"; 
string v = @"i\n";   


ARRAY
// with explicit initialization
// with a reference, allocating space containing default vals
// has .Length field, indexing []
// can declare and initialize an array all on one line
class Program {
  static void Main(string[] args) { 
    int[] a = new int[] {0,1,2,3};   // all on one line, better used as anonym array arg in a method/function
    string[] sarray = {"ben", "finn", "mags"};
    for (int i = 0; i < sarray.Length; ++i) {
      Console.WriteLine($"{sarray[i]}");
    }
    string[] arr_ref;    // reference only
    arr_ref = new string[5];   // allocates space for 5 elems, all " "
    for (int i = 0; i < arr_ref.Length; ++i) {
      Console.WriteLine($"{arr_ref[i]}");  
    }
  } 
}

NULLABLE
// ? on type makes the variable a possible null
// .GetValueOrDefault() returns the types default value on null, or the non-null value
class Program {
  static void Main(string[] args) { 
    int? n = null;
    int? x = 23;
    Console.WriteLine($"{n.GetValueOrDefault()}");   // 0, since n is null
    Console.WriteLine($"{x.GetValueOrDefault()}");   // 23
  } 
}
// -----
// references can be nullable or non-nullable
// can enable always nullable or never nullable in program options file
// ?. returns null, when calling a method on a null ref
// ?? forces the return of another value other than null
class Program {
  static void Main(string[] args) { 
    string? s = null;   // needs ? to possibly hold null
    Console.WriteLine($"{s}");   // ""
		// string x = null;  // non-nullable
    // int x = s.Length;   // throws exception
    int x;
    if (s != null) {   // old C way of checking a null reference
      x = s.Length;
    }
    int? t = s?.Length;     // t is null, does not throw exception
    int z = s?.Length ?? 10;   // since s is null, z is now 10
  }
}
// -----
// TODO: use type? as a parameter type, for a possible null

CONTROL
// if, else if and else are optional
// will not implicitly convert int to bool, like C does
// braces can be omitted if only one line of code in the block, but ill-advised
class Program {
  static void Main(string[] args) { 
    int i = 1;
    int ans;
    if(i > 0) {
      ans = 1;
    }
    else if (i <= 0) {
      ans = 32;
    }
    else {
      ans = 0;
    }
    Console.WriteLine($"{ans}");
  } 
}
// -----
// pattern matching using is
class Program {
  static void Main(string[] args) { 
    object i = 32;
    if (i is int j) {   // j extracts the value of i
      Console.WriteLine($"{j}");
    }
  } 
}
// -----
// switch on the literal values for different cases
// has labels, break, default, goto
class Program {
  static void Main(string[] args) { 
    int[] arr = {0, 1, 2, 3, 5, 4};
    for (int i = 0; i < arr.Length; ++i) {
      switch(i) {
        case 0:
          Console.WriteLine("0");
          break;
        case 1:
          Console.WriteLine("1");
          break;
        case 2:
        case 3:
          goto case 0;
        case 4:
          goto A;
        default:    // always evals last, not matter where it in withing the order of other cases
          Console.WriteLine("no case written");
          break;
      }
    }
    A:
      Console.WriteLine("case 4");
  } 
}
// -----
// switch, where the cases are patterns
class Program {
  static void Main(string[] args) { 
    // int[]? arr = {0,1,2,3};   // first case
    int[]? arr = null;
    switch(arr) {
      case int[]:
        Console.WriteLine("is array");
        break;
      case null:
        Console.WriteLine("null reference");
        break;
    }
  } 
}
// -----
// switch with when in a pattern, when performs more specific matching
class Program {
  static void Main(string[] args) { 
    int[]? arr = {0,1,2}; 
    switch(arr) {
      case int[] when arr.Length == 4:
        Console.WriteLine("array of length 4");
        break;
      case null:
        Console.WriteLine("null reference");
        break;
      default:
        Console.WriteLine("array of another size");
        break;
    }
  } 
}
// -----
// switch expressions, also pattern matching
class Program {
  static void Main(string[] args) { 
    int[]? arr = null;
    string message = arr switch {
      int[] => "is array",
      null => "null reference"
    };
    Console.WriteLine(message);
  } 
}
// -----
// wildcard _ matches everything in a switch expression
// match on an expression of a variable
bool is_even (int num) {
  return (num % 2) switch {
    0 => true,
    _ => false
  };
}
Console.WriteLine($"{is_even(3)}");

LOOPS
// while and do while
class Program {
  static void Main(string[] args) { 
    int i = 0;
    while(i<10) {
      Console.WriteLine($"{i}");
      ++i;
    }
    i = 0;
    do {
      Console.WriteLine($"{i}");
      ++i;
    }
    while(i < 10);
  } 
} 
// -----
// classic for
// foreach is read only, any mutation could cause an Exception
// foreach works on: types with GetEnumerator() that returns an object
//    returned object must have .Current and MoveNext() implemented
//    can implement interfaces IEnumerable and IEnumerable<T>, that formally define these
//    compiler does not require the type to implement the interfaces
class Program {
  static void Main(string[] args) { 
    for (int i = 0; i < 10; ++i) {
      Console.WriteLine($"{i}");
    }
    int[] arr = {0,1,2,3,4,5,6,7,8,9};
    foreach (int i in arr) {
      Console.WriteLine($"{i}");
    }
  }
}
// -----
// example of creating an iterator, making the type usable in the foreach loop
// needs GetEnumerator(), Current, and MoveNext() implemented properly
// MoveNext() is called before the first Current call, so this.pos = -1 initially
// creates a Current field, using the get property
// with a foreach and with equivalent in a while loop
public class MyArray {
  int[] arr;
  int size;
  public int pos;
  public MyArray(int[] arr) {
    this.size = arr.Length;
    this.arr = arr;
    this.pos = -1;
  }
  public MyArray GetEnumerator() {
    return new MyArray(this.arr);
  }
  public bool MoveNext() {            //  size = 4
    if (this.pos < this.size - 1) {   // -1, 0, 1, 2
      ++this.pos;                     // 0, 1, 2, 3 are indices for the elements
      return true;  
    } 
    return false;   // breaks the loop
  }
  public int Current {
    get {
      return this.arr[this.pos];
    }
  }
}
int[] a = {10, 20, 30, 40};
MyArray my_array = new MyArray(a);
foreach (int m in my_array) {
  Console.WriteLine($"{m}");
}
MyArray iter = my_array.GetEnumerator();
while (iter.MoveNext()) {
  Console.WriteLine($"{iter.Current}");
}

EXCEPTION
// basic try catch any exception
class Program {
  static void Main(string[] args) { 
    bool isdiv = true;
    int n = 32;
    int d = 0;
    try {
      int div = n/d;
    }
    catch {
      isdiv = false;
    }
    Console.WriteLine($"{isdiv}");
  }
}
// -----
// handle exception, display message and continue program
class Program {
  static void Main(string[] args) { 
    bool isdiv = true;
    int n = 32;
    int d = 0;
    try {
      int div = n/d;
    }
    catch(Exception ex) {
      isdiv = false;
      Console.WriteLine(ex.Message);
    }
    Console.WriteLine($"{isdiv}");
  }
}
// -----
// catch specific exception System.DivideByZeroException and custom message
class Program {
  static void Main(string[] args) { 
    bool isdiv = true;
    int n = 32;
    int d = 0;
    try {
      int div = n/d;
    }
    catch(DivideByZeroException) {
      isdiv = false;
      Console.WriteLine("You divided by zero!");
    }
    Console.WriteLine($"{isdiv}");
  }
}
// -----
// inheriting from System.Exception to create custom exceptions
// each overloaded constructor calls its corresponding constructor in Exception via base
// only used the custom message constructor here
class MyDivException : Exception {
  public MyDivException() : base() {}     // unused here 
  public MyDivException(string msg) : base(msg) {}
  public MyDivException(string msg, Exception inner) : base() {}   // unused here
}
class Program {
  static decimal MyDiv(decimal n, decimal d) {
    if (d == 0) {
      throw new MyDivException("You divided by zero!");
    }
    return n / d;
  }
  static void Main(string[] args) {  
    try {
      MyDiv(3, 0);
    }
    catch (MyDivException e) {
      Console.WriteLine(e.Message);
    }
  }
}
// -----
// see INHERITANCE for "as" and "is" and how they can avoid writing a try-catch block for checking inheritance casting
// -----
// can use a checked block to force the compiler to check for overflow error and throw an exception
checked {}



FUNCTIONS, METHODS
// static functions are called without an object
// void returns nothing, int would return an int, ... etc
// multiple args with types
class Program {
  static int ret_OH() {
    return 100;
  }
  static void print_sum(int start, int stop, int step) {
    int sum = start;
    for (int i = 0; i < stop; i += step) {
      sum += i;
    } 
    Console.WriteLine(sum);
  }
  static void Main(string[] args) { 
    print_sum(0, 10, 1);
    int i = ret_OH();
  }
}
// -----
// defaulting a function/method
// defaulted (optional) parameters must appear last in the param list 
// also call with param names:can be used to call on params of a different order
// can call with param names to skip a default value
class Program {
  static void PrintHi(string msg1 = "HI", string msg2 = "HELLO") {
    Console.WriteLine($"{msg1}, {msg2}");
  }
  static void Main(string[] args) {   
    PrintHi();
    PrintHi(msg2: "hello");    // default for msg1, using naming
  }
}
// -----
// in_ref is copy by value: copies the value (the addr held by the ref) to the function's local variable
// in_and_out_ref accepts the actual variable z from main(), changes what it points to
// out_ref accepts a declared-only variable or declared-in-arg variable: 
//   both need to be initialized inside the function, outside can also be initialized outside the function
//   neither can be defaulted, function operates on the actual variables in main
// see CONST, READONLY, IN for "in" keyword in parameters
class MyInt {
  int x;
  public MyInt(int x) {
    this.x = x;
  }
  public override string ToString() {
    return $"{this.x}";
  }
  public void set(int x) {
    this.x = x;
  }
}
static void in_ref(MyInt m) {
  // m.set(1);         // changes the value of the data that m points to
  m = new MyInt(1);    // points to another reference temporarily
}
static void in_and_out_ref(ref MyInt m) {
  m = new MyInt(2);    // m is actually z from main
}
static void out_ref(out MyInt outside, out MyInt inside) {
  outside = new MyInt(3);
  inside = new MyInt(4);
}
MyInt z = new MyInt(0);
Console.WriteLine($"{z}");    // z.x = 0
in_ref(z);
Console.WriteLine($"{z}");    // z.x = 0
in_and_out_ref(ref z);
Console.WriteLine($"{z}");    // z.x = 2
MyInt outside;               // outside can be initialized here too
out_ref(out outside, out MyInt inside);
Console.WriteLine($"{outside}, {inside}");   // 3, 4
// -----
// ref returns are values that are returned by reference
// returned ref is stored in a ref local
// helps in performance, avoids the final copying from function back to the caller
class MyInt {
  int i;
  public MyInt(int i){
    this.i = i;
  }
}
class Program {
  static ref MyInt ret_ref(MyInt[] arr, int index) {
    return ref arr[index];
  }
  static void Main(string[] args) {  
    MyInt[] r = {new MyInt(0), new MyInt(1)};
    ref MyInt m = ref ret_ref(r,1);
  }
}
// -----
// see CONST, READONLY, IN for immutable "in" parameters
// see params keyword to make a function accept a list of param as a list


CLASS
// classes are reference types in that their data is on the heap, with a reference to it on the stack
// reference variable on the stack and holds an addr to the data on the heap
// all types inherit System.Object
// explicit inheritance of Object class is seen in both cases
class Dude : System.Object {}
class Person : object {}   // shorthand
class Program {
  static void Main(string[] args) { 
  }
}
// -----
// fields can be private, internal, public, protected, internal protected, private protected 
// private (default): only accessible inside this type
// public: accessible anywhere
// internal: accessible inside type and any type in the same assembly
// protected: accessible inside type and class that inherits it
// internal protected: internal or protected 
// private protected: internal and protected
// -----
// construct on the fly, with public fields
// static field is one field value that is shared across all objects of the class 
class Person {
  public int age;
  public string? name;   
  static public string family = "Harki";
}
class Program {
  static void Main(string[] args) {   
    Person ben = new Person {
      age = 34,
      name = "Ben Harki"
    };
    Console.WriteLine(
      format: "{0} is of age {1}",
      arg0: ben.name,
      arg1: ben.age
    );
  }
}
// -----
// constructors execute before any fields are set by other code
// can have multiple overloaded constructors
// uses anonymous objects 
// readonly allows the fields to be set in the constructor, unlike const
// also uses default keyword or default(type) for a default value of any type, even other classes like List<T>
// a method and how to call it
// methods/constructors can be overloaded: same name but differ in parameter lists or return type
// toString() is called by Console.WriteLine(obj), to print the string repr
class Person {
  private readonly int age;   
  private readonly string? name;
  public Person() {    // no args constructor
    age = default;    // same as default(int)
    name = "XXX";
  }
  public Person(int _age, string _name) {
    age = _age;
    name = _name;
  }
  override public string ToString() {
    return $"{name} is of age {age}";
  }
  public void SayMessage(string msg) {
    Console.WriteLine(msg);
  }
}
class Program {
  static void Main(string[] args) {   
    Console.WriteLine(new Person());
    Console.WriteLine(new Person(38, "Ben Harki"));
    Person ben = new Person(38,"Ben Harki");
    ben.SayMessage("Hello!");
  }
}
// -----
// "this" refers to the current obj
// anonymous obj and 2-arg constructor
// accept a class obj by ref, return the reference
// pass a reference through using ref in arg, return ref, and local ref
// ? checks if the reference is null, if it is then nothing happens
// static methods in a class, cannot be called through an obj, but with class name
class Person {
  int age;
  string name;
  public Person(int age = 0, string name = "XXX") {
    this.age = age;
    this.name = name;
  }
  public static string FieldInfo() {
    return $"All members of Person have an age and a name."; 
  }
  public static ref Person PassThrough(ref Person p) {
    return ref p;      
  }
  override public string ToString() {
    return $"Person(age:{this.age}, name:{this.name})";
  }
}
class Program {
  static void Main(string[] args) {   
    Console.WriteLine(Person.FieldInfo());
    Console.WriteLine((new Person()));
    Person ben = new Person(38, "Ben Harki");
    Console.WriteLine(ben);
    ref Person ben2 = ref Person.PassThrough(ref ben);
    Person? p = null;
    Console.WriteLine(p?.ToString());   // ToString() is unnecessary here, but wanted to illustrate ?
  }
}
// -----
// static classes can only have static fields and static methods 
// constructor must also be static, and static constuctors must have no parameters
// cannot make the constuctor public, it is only private and cannot be called by user
// static constructor likely is called early in the program execution like Java
static class MyStorage {
  private static int[] array;
  static MyStorage() {
    MyStorage.array = new int[32];    // defaulted to 0
  }
  public static int[] RetStr() {
    return MyStorage.array;
  }
}
class Program {
  static void Main(string[] args) {  
    int size = MyStorage.RetStr().Length;   // static constructor does not need called
    for (int i = 0; i < size; ++i) {
      MyStorage.RetStr()[i] = i;
    }
    foreach(int elem in MyStorage.RetStr()) {
      Console.WriteLine(elem);
    }
  }
}
// -----
// static classes with static methods with "this" arg are called extension methods
// this in arg is like python' self, in that it makes the arg variable represent the current obj
// extension makes the static method look like a non-static method call from the "extended" obj
// extension methods cannot replace or override existing instance methods
static class StringExtensions {
  public static string AddHello(this string input) {
    return "Hello " + input;
  }
}
class Program {
  static void Main(string[] args) {  
    string name = "Ben";
    Console.WriteLine(name.AddHello());
  }
}
// -----
// example of constructing a new obj on the fly (anonymous obj) as an arg to a method (when the fields are public)
class MyInt {
  public int i;
  public static void PrintInt(MyInt m) {
    Console.WriteLine($"{m.i}");
  }
}
class Program {
  static void Main(string[] args) {
    MyInt.PrintInt(new MyInt {i = 10});    
  }  
}
// -----
// inner class is also possible, inner class cannot be accessed outside of class that declares it
class Program {
  class MyInt {
    int i; 
    public MyInt(int i) {
      this.i = i;
    }
    public override string ToString() {
      return $"{this.i}";
    }
  }
  static void Main(string[] args) {   
    MyInt m = new MyInt(100);
    Console.WriteLine(m);
  }
}
// -----
// partial class: allows you to split up the creation of a class into multiple files
// Person.cs:
	namespace BenLib;
	public partial class Person {}
// PersonStuff.cs:
	namespace BenLib;
	public partial class Person{ 
		// other stuff
	}
// -----
// see "using" block in OS, to automatically dispose of objects, when the block completes


PROPERTY
// properties are like fields with accessors (like methods) attached to them
// set and get are accessors
// example of auto-implemented accessors
// all properties can be set in constructor, readonly properties (with no set) cannot be set in any other method
// private set accessor could be used in any class method, but nowhere else
class MyInts {
  public int i {get; set;}   // basically pointless bc i can be read and modified already
  public int j {get; private set;}  // makes j readonly (by outside classes only)
  public int k {get;}   // purely readonly, can only set k by constructor
  public int l {get; set;} = 100;  // initialized here, not in constructor
	public MyInts(int i, int j, int k) {
    this.i = i;   // properties are accessible in the constructor
    this.j = j;
    this.k = k;
  }
  public void MakeTen() {
    j = 10;   // j has a private set, so this is ok
    // this.j = 10;    // this is the same thing
  }
}
class Program {
  static void Main(string[] args) { 
    MyInts myints = new MyInts(0,1,2);
    myints.i = 3;
    // myints.j = 4;   // cannot set the property, since it is readonly
    // myints.k = 5;
    myints.MakeTen();
  } 
}
// -----
// init accessor on public propeties I and J, that are attached to private fields
// can be used to construct an object on the fly, and keep it immutable, since no set
// property I inits the private _i field
// "value" is used to represent the value that will be set in the construction
// also an example with lambda notation, for user-implemented get and init
// user-implemented accessors can contain any complicated block of code
// also an example of auto-implemented init and get
class MyInts {
  private int _i;
  private int _j;
  private int _k; 
  public int I {
    get {return this._i;}
    init {this._i = value;}
  }
  public int J {
    get => this._j;
    init => this._j = value;
  }
  public int K {get; init;}  
}
class Program {
  static void Main(string[] args) { 
    MyInts m = new MyInts {I = 1, J = 2, K = 3};
    Console.WriteLine($"_i = {m.I}, _j = {m.J}, _k = {m.K}");
    // m._i = 10;   // cannot modify raw data field
    // m.I = 10;    // property I has no public set, so _i cannt be modified
  } 
}
// -----
// custom Property AddAmt, written as a lambda (can also write as a regular method)
// Property with a constructor and auto-implemented accessors
// Property with an initializer block and user-implemented accessors
// expression-bodied property TypeName that is readonly (get and no set)
class MyInt {
  public int I {get; private set;}  // private so that AddAmt can modify it
  public MyInt(int i) {
    I = i;
  }
  public int AddAmt(int amt) => I += amt;
  public string TypeName => "MyInt";   // readonly expression-bodied member
}
class MyIntA {
  private int _i;
  public int I {
    get => this._i;
    init => this._i = value; 
  }
  public int AddAmt(int amt) => this._i += amt;
}
class Program {
  static void Main(string[] args) { 
    MyInt m = new MyInt(1);
    m.AddAmt(10);
    Console.WriteLine($"{m.I}");
    MyIntA a = new MyIntA {I = 2};
    a.AddAmt(10);
    Console.WriteLine($"{a.I}");
  } 
}
// -----
// see another example of expression bodied property in FUNCTIONAL PROGRAMMING AND DELEGATES

INDEXER
// indexer is a property that allows you to use index notation
// uses lambda notation for properties 
// Length is also a readonly property
// now can use [] indexing notation
class MyIntArray {
  private int[] arr;
  public int Length {get; private set;}
  public MyIntArray(int size) {
    this.arr = new int[size];
    Length = this.arr.Length;
  }
  public int this[int i] {   
    get => arr[i];
    set => arr[i] = value;
  }
  // public int this[int i] => arr[i];   // simplified if you only want a get method
}
class Program {
  static void Main(string[] args) { 
    MyIntArray m = new MyIntArray(5);
    for (int i = 0; i < m.Length; ++i) {
      m[i] = i;
    }
    for (int i = 0; i < m.Length; ++i) {   // can't use foreach unless you implement an iterator, see LOOPS
      Console.WriteLine($"{m[i]}");
    }
  } 
}

MEMORY
// class is on the heap, struct on the stack
// classes are reference types in that their data is on the heap
// reference that lives on the stack and contains an addr to the data on heap
// struct has members and methods like class, only located on the stack
// cannot inherit from a struct
struct MyInt {
  int i;
  public MyInt(int i){
    this.i = i;
  }
  public void print() {
    Console.WriteLine(this.i);
  }
}
class Program {
  static void Main(string[] args) {  
    MyInt m = new MyInt(32);
    m.print();
  }
}
// -----
// finalizer and IDisposable help garbage collector explicitly release memory for your custom class types
// see Chp 6 > managing memory types > releasing unmanaged resources


FUNCTIONAL PROGRAMMING AND DELEGATES
// local function is a nested function
// local functions/methods are only accessible from the local function scope in which they are defined
class Program {
  static int HasLocal(int[] a) {
    int local_sum(int[] arr) {
      int sum = default;
      foreach (int i in arr) {
        sum += i;
      }
      return sum;
    }
    return local_sum(a);
  }
  static void Main(string[] args) {
    int[] a = {0,1,2,3,4};
    int sum = HasLocal(a);
    Console.WriteLine(sum);
  }  
}
// -----
// delegates contain the memory addr of a method that matches the same signature as the delegate
// MyDelegate should have the same params as the method it stands in for
// delegates can be used to implement events
// delagates can point to any method with a matching signature, can change where it points
// delegate can be accepted as a parameter for another method
// delegate is set to an inner function and then returned out to be used in main
public delegate int MyDelegate(int i);
class MyNum {
  public int RetNum(int i) {
    return i;
  }
}
class Program {
  static int RetNumPO(int i) {
    return i + 1;
  }
  static void print_num(MyDelegate deleg, int num) {
    Console.WriteLine(deleg(num));
  }
  static MyDelegate ReturnDelegate(MyDelegate d) {
    int AddTen(int i) {
      return i +=10;
    }
    d = AddTen;
    return d;
  }
  static void Main(string[] args) {  
    MyNum n = new MyNum(); 
    MyDelegate d = new MyDelegate(n.RetNum);  // d points to n.RetNum()
    Console.WriteLine(d(23));   // 23
    d = RetNumPO;   // d now points to RetNumPO
    Console.WriteLine(d(24));    // 25
    print_num(d, 64);    // 65
    MyDelegate d2 = new MyDelegate(n.RetNum);
    print_num(d2, 128);    // 128
    MyDelegate d3 = ReturnDelegate(d2);
    Console.WriteLine(d3(100));   // 110
  }
}
// -----
// named and anonymous lambdas
// accepted as an argument
// as a field in a class called an expression bodied property, see PROPERTY
// also see System.Func<Tin, Tout> delegates
class OpLambda {
  Func<int, int, int> lmb;
  public OpLambda(Func<int, int, int> lmb) {
    this.lmb = lmb;
  }
  public int operate(int i, int j) {
    return this.lmb(i, j);
  }
}
class Program {
  static void print_num(Func<int, int> retnum, int i) {
    Console.WriteLine(retnum(i));
  }
  static string msg => $"Hello";   // expression-bodied property (get but no set)
  static void Main(string[] args) {  
    Console.WriteLine(msg);
    Func<int, int> lmd = i => i;    // "named" lambda    
    Console.WriteLine(lmd(10));
    print_num(i => i, 32);    // print_num accepts a lambda
    print_num(i => 2*i, 64);  // a different lambda
    OpLambda add = new OpLambda((i,j) => i + j);
    Console.WriteLine(add.operate(5,6));
  }
}

CONST, READONLY, IN
// const values must be known at compile time and expressible as a literal string, bool, or number value
// const field needs assigned immediately, cannot be assigned in constructor
class MyInt {
  public const int i = 38;   
}
class Program {
  static void Main(string[] args) {   
    const int i = 32; 
    // i = 100;    // cannot be modified 
    Console.WriteLine(i);
    MyInt m = new MyInt(); 
    // m.i = 11;   // cannot be modified
  }
}
// -----
// readonly class members (cannot have readonly variables)
// however you can have fields in Program that are readonly, to be used in Main()
// use readonly over const for classes: value can be calculated and loaded at runtime
// 		by using a constuctor or field assignment (from within a class)
class Person {
  private readonly int age;   
  public readonly string name = "Ben Harki";
  public Person(int age, string name) {
    this.age = age;
    this.name = name;
  }
  // public void TryModify() {
    // this.age = 40;  // cannot modify internally either
  // }
}
class Program {
  static readonly Person finn = new Person(3, "Finn");
  static void Main(string[] args) {   
    Person ben = new Person(38, "Ben");
    // ben.name = "Mags";  // readonly field cannot be modified
    ben  = new Person(35, "Mags");    // ben is not readonly, since declared locally in main
    // finn = new Person(35, "Mags");    // finn cannot be reassigned
  }
}
// -----
// "in" params are passed by reference but cannot be modified
// if the in param is an obj, then the obj cannot point to another object
//    however, its data could be modified, if the data is not readonly
// since its passed by ref, i.i in main is actually modified 
class MyInts {
  int i;
  readonly int j;
  public MyInts(int i, int j) {
    this.i = i;
    this.j = j;
  }
  public static string IntString(in MyInts m) {
    // m = new MyInt(100);   // m cannot point to another MyInt
    m.i = 101;   // can still modify non-readonly fields
    // m.j = 102;   // cannot modify readonly fields   
    return $"{m.i}, {m.j}";
  }
}
class Program {
  static void Main(string[] args) {   
    MyInts i = new MyInts(10, 20);
    Console.WriteLine(MyInts.IntString(in i));   // 101, 20
  }
}
// -----

SAFETY
// (almost) maximum safety between classes, and methods, readonly data at all levels in the two classes
// always creating new objects and not modifying any old objects, but its not efficient
// immutable class should have not Set() method
// the TwoD object declared in Main can point to other TwoD's, so safety is not found here
// can use readonly in Program to define immutatable objects to be used in Main
// TODO: also add safety in class visibility between files and namespace
class TwoD {
  private readonly MyInt x;
  private readonly MyInt y;
  public TwoD(in MyInt _x, in MyInt _y) {
    this.x = _x;
    this.y = _y;
  }
  public TwoD TranslateAmount(in MyInt amt_x, in MyInt amt_y) {
    return new TwoD(new MyInt(this.x.Get() + amt_x.Get()), 
                    new MyInt(this.y.Get() + amt_y.Get()));
  }
  public override string ToString() {
    return $"({this.x.Get()}, {this.y.Get()})";
  }
}
class MyInt {
  private readonly int i;
  public MyInt(in int _i) {
    // _i = 10;    // cannot modify the local variable
    this.i = _i;   // can set a readonly field in the constructor
  }
  public int Get() {
    return this.i;
  }
}

class Program {
  static readonly string msg = "This program contains immutable classes TwoD and MyInt";
  static void Main(string[] args) {  
    Console.WriteLine(msg);
    TwoD a1 = new TwoD(new MyInt(0), new MyInt(1)); 
    Console.WriteLine(a1);
    MyInt amt_x = new MyInt(2);
    MyInt amt_y = new MyInt(3);
    a1 = a1.TranslateAmount(amt_x, amt_y);
    Console.WriteLine(a1);
  }
}
// -----
// can also create immutable data structures using properties, see PROPERTY

ENUM
// enums limit the possible values it can hold
// values are stored as ints internally, starting with 0
enum Status {
  ON,    //  0
  OFF    // 1
}
class Program {
  static void Main(string[] args) {   
    Status s = Status.ON;
    Console.WriteLine(s);  // ON
  }
}
// -----
// can explicity set the internal value of the enum value
// enums used to flip bits that relate to flags
// can use bytes or other integral types instead of ints
[System.Flags]  // attribute that allows the printing of the flags in a comma seperated list
enum Status : byte {   
  OFF = 0b_0000,    
  ON = 0b_0001,   
  MAYBE = 0b_0010 
}
class Program {
  static void Main(string[] args) {   
    Status s = Status.ON | Status.MAYBE;    // flip both bits: 0b0011
    Console.WriteLine(s);     // ON, MAYBE 
  }
}

GENERICS
// List<T> can cantain elements of any type T, T is the generic parameter
using System.Collections.Generic;
class Program {
  static void Main(string[] args) {   
    List<double> nums = new List<double>();
    nums.Add(3.14);
    nums.Add(2.18);
    foreach(double d in nums) {
      Console.WriteLine(d);
    }
  }
}
// -----
// custom generic class, whose generic parameter type implements a custom interface
// generic class can accept different T types as fields
// "where" describes the interface that T can implement  
// static method that accepts T obj as an argument
interface IPrint {
  void print();
}
class MyInt : IPrint {
  int i;
  public MyInt(int i) {
    this.i = i;
  }
  public void print() {
    Console.WriteLine($"int: {i}");
  }
}
class MyDouble : IPrint {
  double i;
  public MyDouble(double i) {
    this.i = i;
  }
  public void print() {
    Console.WriteLine($"double: {i}");
  }
}
class PrintObj<T> where T : IPrint {
  T obj;
  public PrintObj(T obj) {
    this.obj = obj;
  }
  public void print() {   // wrapper for T's implementation of print()
    obj.print();
  }
  public static void PrintT(T other) {
    other.print();
  }
}
class Program {
  static void Main(string[] args) {  
    MyInt i = new MyInt(3);
    MyDouble d = new MyDouble(3.14);
    PrintObj<MyInt> p1 = new PrintObj<MyInt>(i);
    PrintObj<MyDouble> p2 = new PrintObj<MyDouble>(d);
    p1.print();
    p2.print();  
    PrintObj<MyInt>.PrintT(i);
  }
}
// -----
// generic method 
// the class that contains the method does not need to declare a generic type, only in the method
// generic type T implements a specific interface, IEquatable<T>
// IEquatable<T> contains the method Equals()
class Program {
  static bool MyEqual<T>(T obj1, T obj2) where T : IEquatable<T> {
    return obj1.Equals(obj2); 
  } 
  static void Main(string[] args) {  
    Console.WriteLine(MyEqual<int>(3, 4));     // false
    Console.WriteLine(MyEqual<string>("yes", "yes"));   // true
  }
}

OPERATOR OVERLOADING
// an overloaded operator needs to be public and static
// also needs to be in the class that you are overloading it for
// may be a good idea to also create a method too:
//  in case someone is not aware of the available operator, or op overloading is not supported
class CounterByTwo {
  private int i;
  public CounterByTwo() {
    this.i = 0;
  }
	public override string ToString() {
    return $"Counter at: {this.i}";
  }
  public static CounterByTwo operator ++(CounterByTwo c) {
    return AddTwo(c);
  }
  public static CounterByTwo AddTwo(CounterByTwo c) {
    c.i += 2;
    return c;
  }
}
class Program {
  static void Main(string[] args) {   
    CounterByTwo c = new CounterByTwo();
    ++c;
    Console.WriteLine(c);
    CounterByTwo.AddTwo(c);
    Console.WriteLine(c);
  }
}

INTERFACES
// any class that implements an interface needs to write the implementation of the interface method
// interface reference can hold any object that implements it
// array of Interface refs
public interface IPrintable {   // public to make it visible in other code
  public void PrintNums(int i);   // public is not necessary here, the methods are implicitly public
}
class MyNum : IPrintable {    // IPrintable, IAnother to implement multiple interfaces
  int i;
  public MyNum(int i) {
    this.i = i;
  }
  public void PrintNums(int i) {
    Console.WriteLine($"{this.i}, {i}");
  }
}
class Nums : IPrintable {
  public void PrintNums(int i) {
    Console.WriteLine($"in Nums: {i}");
  }
}
class Program {
  static void Main(string[] args) {  
    IPrintable p = new MyNum(3);
    IPrintable p2 = new Nums();
    IPrintable[] parray = {p, p2};
    foreach(IPrintable per in parray) {
      per.PrintNums(32);    
    }
  }
}
// -----
// default implementation of interface can be created and automatically inherited by class that implements the interface
// useful when trying to add functionality to all classes that implement the interface all at once
//    without having to implement them individually for each class
// if you are calling the default version, you need an interface object
// ToString() is overrided bc Console.WriteLine automatically calls it
public interface IPrint {
  public static void print(IPrint p) {
    Console.WriteLine(p);
  }
}
class MyStr : IPrint {
  string msg;
  public MyStr(string msg) {
    this.msg = msg;
  }
  public override string ToString() {
    return this.msg;
  }
}
class MyInt : IPrint {
  int i;
  public MyInt(int i) {
    this.i = i;
  }
  public override string ToString() {
    return $"{this.i}";
  }
}
class Program {
  static void Main(string[] args) {  
    MyInt m = new MyInt(2);
    // m.print();    // needs an interface obj
    IPrint s = new MyStr("Ben");
    IPrint i = new MyInt(1);
    IPrint[] arr = {s, i};
    foreach (IPrint p in arr) {
      IPrint.print(p);
    }
  }
}
// -----
// abstract cannot be used on fields, but they can be used with classes, methods, properties, indexers, and events
// can have concrete data and constructor, that can be used in the inheriting class
// cannot have abstract class objects, abstract methods must be implemented by concrete inheriting classes
// abstract methods are implicitly virtual methods, cannot have abstract methods in concrete classes
// use override in concrete classes for implementation of abstract methods
// cannot use static or virtual in abstract method declarations
abstract class IIntArray {
  protected int[] array;    // accessible inside this type and inheriting types
  public IIntArray(int[] arr) {
    this.array = arr;
  }
  public abstract int Get(int index); 
}
class MyArray : IIntArray {
  int Length;
  public MyArray(int[] arr) : base(arr) {
    this.Length = arr.Length;
  }
	public override int Get(int index) {
    return this.array[index];
  }
}
class Program {
  static void Main(string[] args) {  
    MyArray m = new MyArray(new int[] {0,1,2,3,4});
    Console.WriteLine($"{m.Get(1)}");
  }
}

INHERITANCE
// all types implicity inherit System.Object
// calling the superclass constructor in subclass constructor 
// new hides the subclass method (non-polymorphic inheritance), when a superclass ref holds a subclass obj addr
// virtual in superclass allows a subclass to override it, subclass uses override (polymorphic inheritance)
// base keyword is used to allow a subclass access members of it superclass
// superclass ref can hold a subclass ref
class Person {
  public string name;    // public so that the child class can access it
  public int age;
  public Person(string name, int age) {
    this.name = name;
    this.age = age;
  }
  public void PrintPerson() {
    Console.WriteLine($"Person(name:{this.name}, age:{this.age})");
  }
  public virtual void PrintPersonVirtual() {
    Console.WriteLine($"Person(name:{this.name}, age:{this.age} (virtual))");
  }
}
class Student : Person {
  int id;
  public Student(string name, int age, int id) : base(name, age) {   // "inherits" the base constructor
    this.id = id;
  }
  public new void PrintPerson() {
    Console.WriteLine($"Student(name:{this.name}, age:{this.age}, id:{this.id} (subclass))");
  }
  public override void PrintPersonVirtual() {
    Console.WriteLine($"Student(name:{base.name}, age:{this.age}, id:{this.id} (virtual))");   // can use either base or this for superclass members
    base.PrintPersonVirtual();   // or can call base.PrintPerson()
  }
}
class Program {
  static void Main(string[] args) {  
    Person p = new Student("Ben", 38, 223234);   // superclass ref of subclass obj, allowed use of override
    p.PrintPersonVirtual();     // calls subclass's method bc of override (dynamic dispatch)
    p.PrintPerson();   // only calls the superclass's method bc of new
  }
}
// -----
// casting in inheritance, implicit and explicit
// all classes implicitly inherit System.Object
// implicit casting is successful when casting a subclass to a superclass ref  
// to cast from a superclass ref to a subclass ref you need an explicit cast
//    explicit cast could throw InvalidCastException at runtime if casting to a different subclass
class Person {
  string name;
  int age;
  public Person(string name, int age) {
    this.name = name;
    this.age = age;
  }
}
class Program {
  static void Main(string[] args) {  
    Person ben = new Person("ben", 38);
    object o = ben;      // implicit casting 
    Person ben2 = (Person) o;  // explict casting
    // string s = (string) o;   // throws exception
  }
}
// -----
// use "is" to check explicit cast before (can also use "is" for check if o is null) 
// another use of explicit cast, to call a specific subclass's method
// use "as" to check if it can be casted to the type, if not it returns null
// using ? two ways: allows p be a null ref, checks if p is a null ref before calling .print()
class Person {
  string name;
  int age;
  public Person(string name, int age) {
    this.name = name;
    this.age = age;
  }
  public void print() {
    Console.WriteLine($"name:{this.name}, age:{this.age}");
  }
}
class Program {
  static void Main(string[] args) {  
    object o = new Person("ben", 38);   // implicit cast, but cannot call the method through o
    // o.print();   // does not work, since print is not a method in Object, and therefore not overrided in Person
    if (o is Person) {
      ((Person) o).print();
    }
    Person? p = o as Person;    // p could be null
    p?.print();                 // cast does not throw, so p is not null, so print() is called
    Person? n = null as Person;
    n?.print();                 // n is null so print is not called
  }
}
// ----- 
// TODO: use "sealed" to prevent your class from being inherited by subclass
// see extension methods in CLASS for adding methods to a class without inheritance


ATTRIBUTE
// see ENUM for an example of using a pre-defined attribute
// to create custom attributes by inheriting System.Attribute:
// 		see Chp 8 > working with types and attributes > creating custom attributes

.NET PLATFORM
// C# runs on variants of .NET, is not a standalone language

SYSTEM
// not the full list, but a few that are important
// namespace with many classes
// System can be automatically in scope, if not use "using"
System.Int32   // int is a shorthand
System.Convert   // see CASTING AND CONVERSION
System.Console
System.Math
System.Object
System.Exception   // see EXCEPTIONS
System.Diagnostics.Debug.Assert
System.DateTime  // struct for the date and time
System.Collections.Generic  // see GENERICS
System.Collection.IEnumerable  // see LOOPS for iterator
System.Func   // delegates for lambda
System.IEquatable<T>   // implements obj.Equals(T obj)
System.IDisposable   // release memory
System.Exception   // inherit to make custom exception classes
System.Attribute   // class you can inherit to create your own attributes
System.EventHandler  // see EVENTHANDLER

CONSOLE
// In System namespace
// formatted console output
Console.WriteLine("Temperature on {0:D} is {1}°C.", DateTime.Today, 23.4);   // adds \r\n at the end
Console.Write("Hello")    // no carrage return
// -----
// enumerate args, or embed them in the string
class Program {
  static void Main(string[] args) { 
    int i = 3;
    double p = 3.14;
    Console.WriteLine("{0}, {1}", i, p);  
    Console.WriteLine("{0}, {1}", arg0: i, arg1: p);  
		Console.WriteLine($"{i}, {p}");  
    Console.WriteLine(
			format: "int i = {0}, double p = {1}",
			arg0: i,
			arg1: p);  
	} 
}

MATH
// in System namespace
Math.Round

OBJECT
// in System namespace
// all classes inherit Object class
object o  = new object();
// -----
// Object class has ToString method, implemented for built-in types 
// see CLASS for overriding ToString method
int i = 32;
Console.WriteLine($"{i.ToString()}");

ASSERT
// System.Diagnostics.Debug.Assert example
using System.Diagnostics;
class Program {
  static void Main(string[] args) { 
    Debug.Assert(10 == 11);  // assertion failed at line 4
  }
}

LIST
// class in System.Collections.Generic
// create a List from an array, Lists can be dynamically resized, unlike arrays
// Count is the size of the List
// can directly modify members of a List with []
// foreach is a readonly loop
class Program {
  static void Main(string[] args) {   
    int[] arr = {0,1,2,3,4};
    List<int> lst = new List<int>(arr);
    for (int i = 0; i < lst.Count; ++i) {
      lst[i] = i + 5;
    }
    foreach (int i in lst) {
      Console.WriteLine(i);
    }
  }
}
// -----
// see example in GENERIC

TUPLE
// see Chp 5 > writing and calling methods > combining multiple return values using tuples

EVENTHANDLER
// in System namespace
// EventHandler is a special delegate
// Program pokes Ben, once he is listening, ben call's Program's Shout
class Person {
  public string Name {get;}
  public EventHandler? Shout;  // delegate, default to null on construction
  public Person(string name) {
    Name = name;
  }
  public void Poke() {
      Shout?.Invoke(this, EventArgs.Empty);   // calling Program_Shout, once Shout is not null
  }
}
class Program {
  private static void Program_Shout(object? sender, EventArgs e) {
    Person? p = sender as Person;
    Console.WriteLine($"{p?.Name} SHOUTS!");
  }
  static void Main(string[] args) {  
    Person ben = new Person("Ben");
    ben.Poke();   // Program is doing other things and ben is not listening
    ben.Poke();
    ben.Shout = Program_Shout;    // now it is listening to Program
    ben.Poke();  // Ben shouts
    ben.Poke();  
    ben.Poke();  
    ben.Poke();  
  }
}
// -----
// similar to above, but with "event" keyword, that can add on other Program methods to Shout event
// Program pokes ben, and when ben is listening, calls Program's Shout and Angry
// += subcribes to more actions, -= unsubscribes
class Person {
  public string Name {get;}
  public event EventHandler? Shout;  // delegate, default to null on construction
  public Person(string name) {
    Name = name;
  }
  public void Poke() {
    Shout?.Invoke(this, EventArgs.Empty);   // calling Program_Shout
  }
}
class Program {
  private static void Program_Shout(object? sender, EventArgs e) {
    Person? p = sender as Person;
    Console.WriteLine($"{p?.Name} SHOUTS!");
  }
  private static void Program_Angry(object? sender, EventArgs e) {
    Person? p = sender as Person;
    Console.WriteLine($"{p?.Name} SAYS I AM ANGRY!");
  }
  static void Main(string[] args) {  
    Person ben = new Person("Ben");
    ben.Poke();   // Program is doing other things and ben is not listening
    ben.Poke();
    ben.Shout += Program_Shout;    // now it is listening to Program
    ben.Poke();  // Ben shouts
    ben.Poke();  
    ben.Shout += Program_Angry;  // now both Program_Shout and Angry are called 
    ben.Poke();  // SHOUTS! and SAYS I AM ANGRY!
    ben.Poke();  
  }
}

OS
// start a process using .NET
// assumes that the process will terminate on its own
// using block ensures the object is disposed after the block, even if an exception is thrown in the block
// can add more objects in using arg, like using(obj1, obj2)
using System.Diagnostics;
class Program {
  static void Main(string[] args) { 
    try {
      using (Process myProcess = new Process()) {
        myProcess.StartInfo.UseShellExecute = false;  // starts without a window
        myProcess.StartInfo.CreateNoWindow = true;
        myProcess.StartInfo.FileName = "python";   // starts python REPL
        myProcess.StartInfo.Arguments = "trythis.py";
        myProcess.Start();
      }
    }
    catch (Exception e) {
      Console.WriteLine(e.Message);
    }
  } 
}
// -----
// "using" declaration is used when the object should be destroyed outside the scope it is declared in
// the using variable is readonly 
class Program {
  static void Main(string[] args) { 
    using StreamReader reader = File.OpenText("./trytext.txt");
    String? line;
    while ((line = reader.ReadLine()) is not null) {
      Console.WriteLine(line);
    }
  } 
}









































