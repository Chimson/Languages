// from Java The Complete Reference 12th Edition, up to Java SE 11 (JDK 11)

DOES THIS LIST OF SKIPPED NEED UPDATED?

// STOPPED AT: Chp 14 > Creating a Generic Method

// SKIPPED: Chp 8 > Local Variable Type Inference and Inheritance  (var with inheritance)  
// SKIPPED: Chp 9 > Default Interface Methods > Multiple Interface Issues  
// SKiPPED: Chp 11 > Multithreaded Programming
// SKIPPED: Chp 12 > Annotations 
// SKIPPED: Chp 13 > A Word About Compact API Profiles
// SKiPPED: Chp 14 Generics 
// SKIPPED: Chp 15 > Generic Functional Interfaces 
// SKIPPED: Chp 15 > Lambda Expressions and Exceptions
// SKIPPED: Chp 15 > Lambda Expressions and Variable Capture
// SKIPPED: Chp 15 > Method References > Method Reference with Generics
// SKIPPED: Chp 15 > Constructor References (REDO)
// SKIPPED: Chp 16 Modules
// SKIPPED: Chp 19 Collections 
// some additions from SE450 and CSC447


INDEX
/*
	SUMMARY
	NANO TEXT EDITOR
	USEFUL CLASSES
	BASIC PROGRAM
	IMPORTANT KEYWORDS
	PRINT EXAMPLES
	OPERATORS
	LITERALS
	CHAR, STRING, LITERALS, AND ESCAPE
	TYPES
	TYPE WRAPPER
	DECLARE, ASSIGN
	CONVERSION, CASTING, PROMOTION
	CONTROL
	LOOPS
	ARRAYS
	STRING
	METHODS
	CLASS
	CLASS, OBJECT CLASS, STATIC, ACCESS MODIFIERS
	INHERITANCE
	ABSTRACT CLASS
	PACKAGES, ACCESS, AND IMPORT
	INTERFACE
	STATIC OUTER CLASS, STATIC INNER CLASS, INNER CLASS
	FUNCTIONAL INTERFACE, LAMBDA, METHOD REFERENCE
	EXCEPTIONS
	ENUM
	GENERICS
	IO
	NETWORKING
	OLD STUFF
	SUMMARY
*/

SUMMARY
/*
  File needs to contain Class of the same name
  escape char of \
  primitive types are not objects
  automatic and manual boxing and unboxing from primitive type to its wrapper object type
  use valueOf() and typeValue() for manual unboxing/boxing
  auto-boxing/unboxing occurs within function parameter declarations, return values, control statements, and loops
  has var keyword for type inference
  has auto-widening (smaller sized type converts to larger), aka type promotion
  casting is used to manually convert a larger sized type to a smaller sized type
  type promotion can occur in expressions
  if/while statements must accept booleans, no 1 or 0
  has do while and switch cases
  comma operator used like expressions, seen in for loops and while declarations
  Arrays and Strings are implemented as an object for safety
  enhanced for can be used on any Collection (like Arrays)
  has a goto like named-block using :, break, continue
  new allocaties an object in heap
  Strings are immutable
  Object variables are references
  Passed by Value into functions (aka copied)
  Obj refs are also copied, simulated Passed By Reference
  can have a variable number of args, those that vary in type are written first
  can create a java file per class 
  classes automatically create a default constructor that auto-initialzes fields to 0, null, false, etc, using new
  any user-made constructor overrides the no args default constructor (even if the user-made is not no-args)
	primitive vals live on the stack, new values on the heap (references themselves live on the stack)
*/

NANO TEXT EDITOR
//  /usr/share/nano/java.nanorc contains nano text editor coloring

USEFUL CLASSES
import java.util.Random;  // Random class, rand.nextDouble()

BASIC PROGRAM
// to read the command line args see STRING
class Test {  // file needs to be named Test.java, main is public so that JVM can access it
  public static void main(String args[]) {  // begins execution, args[] from cmd line, void is no return val
    System.out.println("Hi");     // args is an array of String, needed for main 
  }
}
// compile:
// compile flags: -g for debug symbols in jdb, -d bin to compile into /bin dir
//		-Xlint: all warnings, 
$ javac Test.java   /* creates bytecode in Test.class */ /** documentation comment */
// run:
// runtime flags: -ea for enabling asserts, -da disables asserts, see EXCEPTIONS
$ java Test


IMPORTANT KEYWORDS  
// access modifiers should begin in a members declaration statement
// no modifer means member is public within its own package only and subclasses
public  // member may be accessed by code outside of its class, including different packages
private // can only be accessed in by code in its class, not accessible by other classes or packages
protected // can be seen outside package but only to classes that subclass your class
static // member can be called without creating an instance of the class, variables are global  
// ***********
// other
void  // does not return a value
break   // breaks out of loops (or inner most neste loop), switch cases, goto form
continue  // ends current iteration and continues to the next
return  // return control back to caller method    
new    // allocates memory for object on heap
final  // prevents its contents from being modified, also used to prevent inheritance of class or method
extends // inheritance, B extends A is B inherits A (B is a subclass of its superclass A)
implements // to inherit an Interface, these only declare a method, no implementation (unless defaulted)
super // access superclass constructor from subclass
abstract  // to create abstract superclasses
package   // contains classes
import    // to bring in classes into file
strictfp  // applies to class, method, or interface; forces the handling truncations for floating point values like old Java
native
// **********
// native declares methods that call methods native to another language other than Java from which Java is employed in 
// uses the JNI, look up in your compiler for more instructions
public native int meth();   // do not define a body

			
PRINT EXAMPLES
// print calls Object.toString() method, can be overridden, see inheritance
System.out.println("Hi"); // prints and then continues next line
System.out.print("Hi");   // no next line
System.out.println("This is " + true + " or " + (1<0) );  // prints booleans and boolean expr results
System.out.println("Hello" + " Ben");
// ***********
// +, converts from int to string, concats, println prints resulting string
class Test {
	public static void main(String args[]) {
		int num = 10;
		System.out.println("Hi " + num);	 
  }
} 

OPERATORS
// assignment   // operates right to left, all others have precendence/l to r
=
// arithmetic
+, -, *, /, %, ++, --    
+=, -=, *=, /=, %=
// relational
==, !=, >, <, >=, <=  // ==, != also on boolean 
==		// for primitives or references (that contain address of the object in memory as a value)
.equals()  // for object values, may need overridden from Object for user classes, otherwise defaults to == from Object class
// short circuit, 
||, &&    // or, and, but does not evaluate right expr when left is enough for T/F val
// ternary
? :   // if else
// **********
// bitwise ops on integer types: long, int, short, char, byte
// all are signed (except char) so negs are twos-complement
 &, |, ^, !    // also work on boolean true/false
&=, |=, ^=, >>=, >>>=, <<=  // with assignment
~,  >>, <<  // be careful with auto type promotion, use a cast
>>>   // right shift zero fill
// **********
// pre vs post decrement
x = 42;
y = ++x;  // x and y are 43 
a = 42;
b = a++;  // b is 42, a is 43
// ***********
// see INHERITANCE and TYPES for instanceof example
instanceof 
 
LITERALS
101
3.14    // assumed double
3.14d   // double, d is unnecessary
4.56D
4.544f  // float
3.33F
012   // 10 in octal, leading zero
0XFF  // hex
0xff      
0x7ff_ffff_ffff_ffffL // Long, largest one, _, __, ...  are ignored
0B11011 // binary
0b1011_1111
6.12e-3 // scientific
3.14E9  
0x12.2P2  // 72.5, floating hex in sci note using binary exponent
0x3p2  //  12
true, false   // not 0 or 1 like in C

CHAR, STRING, LITERALS, AND ESCAPE
'\141'  // a in octal
'\u00ff'  // another char in hex
'\''  // '
'\"'  // double quote
\\  // backslash
\r, \n, \f, \t, \b
"Hello\nWorld"  // no line continuation

TYPES
// Java enforces a strict range for possible values of these types
// primitive types are not objects from a class
byte, short, int, long  // integers
float, double   // floating pt
boolean, char   // char is in Unicode, ASCII is the first 127 
var // for ref type inference
// **********
// examples
char c = 'a';
c++;  // can increment chars
c = 21; // can assign an int to a char
boolean b = true;	  // true is not equivalent to 1
boolean c = false;  // false not equivalent to 0
// **********
// final declares read only variables
final int CONSTANT = 0;
// **********
// transient means the value does not need to persist when an object is stored
// volatile means that the variable could be modified unexpectedly by other parts of the program
//   possible in concurrency, when 2 threads "share the same variable", but actually have their
//   own local copies that sync to a master variable
//   volatile ensures that the compiler uses or syncs to the master variable 
class MyNum {
	transient int a;
	volatile int b;
	MyNum(int a, int b) {
		this.a = a;
		this.b = b;
	}
}
// *********
// instanceof determines if an object is of a specific type
// see INHERITANCE for a better example
String s = "Ben";
System.out.println(s instanceof String);

TYPE WRAPPER
// wrapper classes around primitive types, called boxing, decomposing is unboxing
// can use but less efficient in running time
// all numeric classes inherit Number class, can override toString() method from Object
Byte, Short, Integer, Long, Float, Double, Boolean, Character
// ***********
// manual boxing/unboxing: valueOf() and value() methods
// these methods work for all 8 Wrapper classes  
// valueOf() sets the value in the wrapper, charValue() returns the primitive  
class Test {
  public static void main(String args[]) {
    char a = 'a';
    Character ch2 = Character.valueOf(a);   // copy from a variable
    Character ch1 = Character.valueOf('b');  // use this bc the constructor is depreciated
    char b = ch1.charValue();  
    System.out.println(a + ", " + ch1 + ", " + ch2 + ", " + b);
  }
}
// **********
// autoboxing and autounboxing
// methods will autobox/autounbox parameters/return values
// expressions will perform autoboxing/autounboxing and then type promotion and conversions
// also works in control statements and loops
class Test {
  static Integer box(int i) { // autoboxes an int into an Integer
    return i;
  }
  public static void main(String args[]) {
    Integer i = 100;
    int in = i;   // automatic in initialization
    Integer j = box(in);   // compiler implicit boxes
  }
}

DECLARE, ASSIGN
// names can be upper, lower, _, number(not first char), $
int i;   // uninitialized and compiler will not allow a read until it is initialized
int j = 0;
i = 10;
int a=1, b=2;
int k, l, m=4;
int j = a+b;  // dynamically
// **********
// local var ref type inference, can only be used during init
// only one variable at a time can be declared, no init with null, lambda expr, method refs
// var cannot be used as a name of a Class, interface, enum, annotation, generic, exception type, 
var d = 31.456;   // d is of type double
// *********
// chaining
int x, y, z;
x = y = z = 1;  // assigns in order r to l


CONVERSION, CASTING, PROMOTION
// for primitive types, see INHERITANCE for object types
// auto widening conversion (type promotion) if the dest type is "larger" and compatible
long l = 3;   // converts int to long
double d = 3.456f;  // converts float to double
char c = 3;       // chars can store ints, not the other way around without a cast
// **********
// casting for narrowing conversion
byte x = (byte) 2000;  // 2000 is converted to int via mod range of byte (256) 
int i = (int) 3.456f; // float is trunctated to int
// **********
// automatic type promotion, based on largest mem size of type
byte a = 40;
byte b = 50;
int c = a*b + 256;  // a and b are converted to ints and expr is evaluated
b = (byte) (b*2);   // needs a cast bc b is promoted to int, making result int
float d = (3 + 'a') + ((float)  4.56d);   // 'a' is prom int, dbl casted down to float, result prom float
double dd = 1 + 'b' + 3.14f // everything promoted up until an eventual double     

CONTROL
if (expr) ;   // in one line, need {} for more than one ;
// **********
// difference from C/C++
int a = 1;
if(a == 1)     // cannot do if(a) unlike in C, unless if(expr) contains a boolean
  System.out.println("This is ok");
boolean b = true;
if(b)
  System.out.println("This is ok");  
// ***********
if(expr) ;  // can have empty statements
else  ;    // if nested else refers to closest if
// **********
if(expr2)
  ;
else
  ;
// **********
if (expr) {   // dont need braces if one statement
	;
} else {
	;
}
// **********
if (expr) {   // when one if is true, it executes and skips the remaininf
	;
} else if (expr2) {
	;
} else {  // else is optional
	;
}
// **********	
// ternary
class Test {
  public static void main(String args[]) {
    int num = 1, denom = 0;
    int ratio = (denom == 0 ? 0 : num/denom);
    System.out.println(ratio);    // prints 0
  }
}
// **********
// switch, generally more efficient than if else if, ...
// can be nested .i.e another switch in a case
class Test {
	public static void main(String args[]) {
    char i = 'a';  // expr can resolve to one of integer types, enum, String  
    switch(i){    // only tests i and case on equality
    	case 'a':
    		System.out.println("Hi"); // add braces if there are 2 or more statements here   
    		break;	// optional, breaks out of switch block
    	default:	// optional, executes if no match on case
    		System.out.println("nope");
    } 
 }
} 

LOOPS
while(expr) ;
while (expr) {		// don't need braces if only one statement
	;
}
// **********
// increment and test in expr
class Test {
	public static void main(String args[]) {
    int n = 1;
    while(++n < 10) {
      ;
    }
  }
} 
// **********
do {
	;
} while (expr);	// block is executed at least once
// **********
for (int i = 0; i<10; i++) {  // any of the sections can be omitted
	;
}
// **********
int i;  // can declare and initialize outside
for(i=0; i<N; i++) {  // don't need braces if only one statement
  ;
}
// **********
// using commma
class Test {
	public static void main(String args[]) {
    for(int i=0, j=10; i<j; ++i, --j)   // i<j needs to be true to iterate
      System.out.println(i + " " + j);
  }
} 
// **********
// condition not written using i,j, empty init portion of for loop
class Test {
	public static void main(String args[]) {
    boolean bool = true;
    int i=0, j=10;
    for( ; bool; ++i, --j) {   
      System.out.println(i + " " + j);
      if(i==j) bool=false;
    }  
  }
} 
// **********
// enhanced for can be used on any Collection
// always read only
// any assignment inside the loop, only changes the variable local to the loop
//   not the value in the Collection entry
for (type iteration-var : Collection) {	
	;
}
// **********
// enhanced for on an array with break
class Test {
	public static void main(String args[]) {
    int arr[] = new int[10];
    arr[4] = 1;
    for(int num : arr) {   // num is read only
      if(num==1) break;
      System.out.println(num);    // prints 4 zeros 
    }
  }
} 
// ***********
// enhanced for in 2D array
class Test {
	public static void main(String args[]) {
    int twoD[][] = new int[3][3];
    for(int row[]: twoD) {
      for(int entry: row)
        System.out.print(entry);
      System.out.println();
    }
  }
}
// **********
// for with var keyword
class Test {
	public static void main(String args[]) {
    int arr[] = new int[10];  
    for (var i=0; i<10; i++)  // var detects type  
      arr[i] = i;
    for (var v:arr) 
      System.out.println(v);
  }
}
// ***********
// break as goto using break label, break from a container block 
// outer: at some inner nested block it contains a break outer statement
class Test {
	public static void main(String args[]) {
    outer: 
      for(int i=0; i<10; i++) {  // outer is a label for break
        for(int j=0; j<10; j++) {
          if(j==5) break outer;
          System.out.println(i + " " +  j); // only 0 1 -> 0 4, no i=1,2,...,9
        }
      }
  }
}
// **********
// continue examples
for(int i=0; i<10; i++) {
  if(i==3) continue;    // skips printing 3 but continues to the rest
  System.out.println(i);
}
// **********
// continue out of a container block
class Test {
	public static void main(String args[]) {
    outer: 
			for(int i=0; i<5; i++) {
				for(int j=0; j<5; j++) {
					if(j==2) continue outer;    // once j=2 i changes to the next
					System.out.println(i+" "+j);
				}
			}
  }
}

ARRAYS		
// Class on its own with .length field, unlike C/C++
// new initializes 0's, false, null, or some equiv zero-initializatoin
//  JVM restricts access outside of bounds
double[] a;         	// declares an array (no initialization)
int[] one, two, three;  // three arrays
a = new double[10]; 	// new allocates an array of 0.0's length 10 by default
double[] b = new double[10];	// can declare, create, and initialize in one statement
double[] c = {0.3, 0.6, 0.99, 0.01, 0.5};   // manual initialize
c[0] = 3.14;  // assignment
// **********
double d[];   // another way, like C
double e[] = new double[15];  
// **********
// 2d arrays
int a[][];
a = new int[5][5];
boolean[][] b = new boolean[10][10];	// 2d bool array defaulted to false
int twod[][] = new int[10][10]; // another way
int[][] myNumbers = { {1, 2, 3, 4}, {5, 6, 7} };	// 2D array, each inside can be of diff lengths
int x = myNumbers[1][2];	// access a single number
// can initialize other dim later
int b[][] = new int[2][];
b[0] = new int[5];  // can be of different sizes
b[1] = new int[6];  
// matrix
int mat[][] = {
  {2, 1},
  {3, 4}
};
// *********
// length is a member of Class Array
int[] a = new int[10];
System.out.println(a.length);
// *********
// copies contents of a into new array b (cannot do b = a)
int[] a = new int[10];
double[] b = new double[a.length];
for (int i=0; i < a.length; ++i) {
	b[i] = a[i];
	System.out.println(b[i]);
}
// **********
// var an array, cannot manually init
var arr = new int[10];  // arr is inferred to be int[10] type
// **********
// creates a new array in the argument of the function
public class Testing {		// declares an array and calls in one line
	public static void myfunction(int[] x) {
		System.out.println(x[1]);
	} 
	public static void main(String[] args) { 
		myfunction(new int[] {1,2,3});
	}
}

STRING
// Strings are immutable, so every operation returns a new String
String str = "Hello World";	// iterates over chars in String, using array
System.out.println(str);
String concat = str + " Ben" + " Harki";
// **********
// String array
String[] names = {
  "Mags","Ben","Finn"
};
// **********	
// accesses/prints command line args
// > javac Test.java
// > java Test Ben Harki   // prints only the args
class Test {
  static void print_args(String args[]) {
    for(String str: args) {
      System.out.println(str);
    }
  }
 	public static void main(String args[]) {
    print_args(args);
  }
}
// **********
// String methods
  String str = "Hello";
	str.length(); str.toUpperCase(); str.toLowerCase(); 
	str1.indexOf(str2);
	str1.concat(str2);	// concatenation
  str.toCharArray();
// ***********
// String's are passed by value (copies value in function frame to somethere else), even though it is a object
// can't even look at a String reference in a debugger, Strings are treated like primitives 
// This behavior is also true with Integer, also an object, but they behave like a primitive (CBV)
// this is related to the fact that they are immmutable
// Everything is passed by value in Java. Normally if its a ref it simulates pass by reference, EXCEPT in this case
// String is an object, however it is still passed by value
public class Test {
	static void add(String str) {
		str += "Harki";		  // += does return a new value array for str.value field, but str is not a copy of s
	}
	public static void main (String[] args) { 
		String s = "Ben";			
		add(s);
		System.out.println(s);  // Ben
		s += "Harki";		// s.value field is assigned a new value array
		System.out.println(s);  // BenHarki
	} 
}
// ************
// TODO: make an example comparing String as an arg with a MyObj as an arg


METHODS
// params of primitive types are passed by value (method operates on copies)
// params of objects are passed by reference value, method operates on a copy of the location (simulates pass by ref)
// one caveat: String, Integer, etc. even though objects, are pass by VALUE, they behave like primitives (TODO: CREATE EXAMPLE, see String)
// static methods allow calling the method without an object
class Num {
  int i;
  Num(int i) {    
    this.i = i;
  }
  void swap_w(Num n) {    // operates on actual objs
    int t = this.i; 
    this.i = n.i;
    n.i = t;
  }
  void p_num() {
    System.out.println(i);
  }
}
class Test {
  static void swap(int i, int j) {  // operates on copies
    int t = j;
    j = i;
    i = t;
  }
	public static void main(String args[]) {
    int i = 3, j = 4;
    swap(i,j);  // declared static, so not assoc w/obj
    System.out.println(i + " " + j);  // i and j are not changed
    Num k = new Num(3);
    Num l = new Num(4);
    k.swap_w(l);    // does swap values
    k.p_num();  // k is now 4
    l.p_num();  // l is now 3
  }
}
// ***********
// recursive  // made as a seperate static method here, for class version see CLASS 
class Test {
  static int run_sum(int sum, int N) {
    if(N==0) return sum;
    sum += N;
    return run_sum(sum, N-1);  // sum is updated per iter, N-1 is the iter 
  }
  static int running_sum(int N) {   // aux/helper method
    int sum = 0;
    return run_sum(sum, N);
  }
	public static void main(String args[]) {
    int sum = running_sum(10);
    System.out.println(sum);
  }
}
// **********
// passing an array into a method
class Test {
  public static void main(String args[]) {  
  }
} 
// **********
// variable args method
// can be called with 0 or more args, can be overloaded: add more args, change type etc.
// automatically creates an array of the args you call, can only have one
public class Test {
  static void myprint(int x, String ... sarray) {   // non-variable args needs to be at the end
    System.out.println(x);
    for(String str : sarray) {
      System.out.println(str);
    }
  }
	public static void main (String[] args) { 
    myprint(1, "a", "b", "c", "d");
  } 
}

CLASS
// creates a .class file for each class, could place classes in seperate .java files
// constructors are by default static: no obj needed
class Person {	
	int height;
	int weight;
}
class Test {    // saved in file Test.java since it contains main
	public static void main(String args[]) {
    Person ben = new Person();  // on one line with default constructor, which defaults to 0's, nulls, false
    ben.height = 7;
    ben.weight = 175;
    Person Adam;          // reference to a new object
    Adam = new Person();  // allocates the object in memory
    Person mags =  ben;   // mags points to same obj ben points to (does not copy values)
    ben = null;          // only mags points to it now
  }
}
// **********
// void and return methods, init method with parameters
class Person {	
	double height;
	double weight;
	void init_person(double w, double h) {  // primitives are passed by value (copied)
    height = h;
    weight = w;
	}
  void print_person() {  
    System.out.print(height + "ft, " + weight + "lb\n");
  }
  double height_to_in() {
    return height*12;
  }
}
class Test {
	public static void main(String args[]) {
    Person ben = new Person();   // default constructor zero-initializes
    ben.print_person();
    ben.init_person(175,6.75);  // method with args
    ben.print_person();
    System.out.println(ben.height_to_in() + " in");
  }
}
// ***********
// constructor with params (do not need params)
class Person {	
	double height;
	double weight;
  Person(double h, double w) {    // removes default no-args constructor, but can make one 
    height = h;
    weight = w;
  }
}
class Test {
	public static void main(String args[]) {
    Person ben = new Person(6.75, 175);
  }
}
// ***********
// same constructor with "this", for current obj
Person(double height, double width) { // same name as atrs, if use "this", otherwise local overrides
  this.height = height;
  this.weight = weight;
}  
// **********
// overloaded methods must differ in type or num of params, not return type
// watch for JVM autoconversion of primitive types
// can overload constructors
// overloaded print method (all have the same name)
class Person {	
  String first;
  String last;
  Person(String first, String last) {
    this.first = first;
    this.last = last;
  }
  void print_person() {
    System.out.println("Hi " + first + " " + last);
  }
  void print_person(String greeting) {
    System.out.println(greeting + " " + first + " ");
  }
}
class Test {
	public static void main(String args[]) {
    Person ben = new Person("Ben", "Harki");
    ben.print_person();
    ben.print_person("Hello");
  }
}
// ***********
// method with an object as a parameter, can be done in a constructor too
// objs are passed by ref:
// addr value is copied to local pointer, can access the object in caller scope
boolean same_name(Person other) {   
  if((other.first == first) && (other.last == last))
    return true;
  return false;  
}
// **********
// method returns an object, method copies to create seperate objs 
class Person {
  String first;
  String last;
  Person(String first, String last) {
    this.first = first;
    this.last = last;
  }
  Person replicate() {
    Person p = new Person("unset", "unset");
    p.first = first;
    p.last = last;
    return p;
  }
  void print() {
    System.out.println(first + " " + last);
  }
}
class Test {
	public static void main(String args[]) {
    Person ben = new Person("Ben", "Harki");
    Person clone = ben.replicate();
    clone.first = "Adam"; // to confirm they are in seperate locations
    clone.print();
    ben.print();
  }
}
// ***********
// recursive in a class method (as a static method see METHODS)
class Sum {
  int n;
  Sum() {
    n = 0;
  }
  void running_sum(int N) {
    if(N == 0) return;
    this.n += N;
    this.running_sum(N-1);   
  }
}  
class Test {
	public static void main(String args[]) {
    Sum s = new Sum();
    s.running_sum(10);
    System.out.println(s.n);
  }
}
// ***********
// Heap allocation: fields with references and primitives
// primitives are defaulted to 0 (or 0 like vals), references to null
public class Test {
	static class MyInt {
		int i;		// defaults to 0
	}
	static class A {
		MyInt x;		//	x is reference to a MyInt, defaults to null on heap alloc of A obj 							    
		MyInt y;		// allocated in A() constructor
		A() {
			y = new MyInt();		// now allocates y on the heap, y.i defaults to 0
		}
	}
  public static void main(String args[]) {
		A a = new A();    // a is allocated on the heap
		System.out.println(a);    // Test$A@4b6995df 
		A aa;		// cannot read value, only a declaration, not allocated anywhere
		aa = a;	// now points to the same location as a
	}
}
/*
Location 			Value
a							0x4b6995df (heap) 	// &a is on the stack    
a.x           null
a.y           0x2fc14f68 (heap)      
a.y.i         0         
*/


CLASS, OBJECT CLASS, STATIC, ACCESS MODIFIERS
// each user class automatically inherits Object class, and its methods:
// public String toString(), public boolean equals(Object o)
// some more Object methods: clone(), final getClass(), hashCode()
// override a class's .equals() to check if objects values are equal, otherwise it uses default == of comparing ref locations
public class Test {
	private static class Simple {
		private int x;
		private int y;
		private Simple() {
			this.x = 0;   
			this.y = 0;
		}
		private Simple(int _x, int _y) {
			this.x = _x;
			this.y = _y;
		}
		public String toString() {
			return "(" + x + ", " + y + ")";
		}
		public boolean equals(Object o) {
			Simple other = (Simple) o;
			if(other == null) {return false;}
			if(this.x == other.x && this.y == other.y) {
				return true;
			}
			else {
				return false;
			}
		}
	}
	public static void main(String args[]) {
		Simple s1 = new Simple();
		Simple s2 = new Simple(3, 4);
		Simple s3 = new Simple();
		System.out.println(s1 == s1);			// true, bc refs are the same
		System.out.println(s1 == s2);			// false, bc different obj refs
		System.out.println(s1 == s3);		// false bc different obj refs
		System.out.println(s1.equals(s2));	// false, values are different
		System.out.println(s1.equals(s3));	// true, bc values are the same
	}
}
// ***********
//  class access modifiers
class Pub {
  int i;    // default: is public only to its package
  public int j;   // accessible by code outside of class
  private int k;  // only accessible by inside class or public method
  Pub() {
    i = 1;
    j = 2;
    k = 3;
  }
  void set_k(int num) {
    num = k;
  }
}
class Test {
  private int l = 10; // can only be accessed by inside its class
	public static void main(String args[]) {
    Pub p = new Pub();
    p.i = 4;
    p.j = 5;
    p.set_k(6);
    Test t = new Test();
    t.l = 20;
  }
}
// **********
// static method, static global variable, static block
// all instances of the class share the same static variable
// once Test is loaded all static statements are run first before its main is run or objs are created
// static methods and fields from another class can be called with Class.meth()
class Person {
  static String name = "Ben Harki";
  static void pmeth() {
    System.out.println(name);
  }
}
class Test {
  static int global; 
  int i;    
  static {global = 10;} // static block initializes global
  static void meth() {   // static methods can only call other static methods
    System.out.println(global);   // cannot access non static vars and no this or super
  }
	public static void main(String args[]) {
    meth();  // 10, does not need an object to call
    System.out.println(global);   // 10
    Test t = new Test();
    System.out.println(t.i);    // 0, cannot be accessed without an object
    System.out.println(Person.name); // need class name to access the Person's static/global var
    Person.pmeth();
  }
}
// **********
// final is declared unmodifiable (read only), shown in a class and in a method's local variable 
// private only shields other classes from this classes internal code
// private forces get() and set() methods, unless the field is final, then no set method is possible
class Person {
  public final String name;    // final can be declared in a class and only init in its constructor or here
  private int age;    // forces the need for get(), set()
  // private final int age;   // this makes setAge() unnecessary, since age cannot be modified
  Person() {
    this.name  = "Ben Harki";
    this.age = 37;
  }
  void print(final int _age) { // declare local variable to be final
    // _age = 50;  _age cannot be reassigned   
    // this.name = "ho";  since name is final, so no setName() is possible
    final String MSG = " will never change when printing."; // cannot be changed in method
    System.out.println("My age of " + _age + MSG);
  }
  public int getAge() {return this.age;}
  public void setAge(int _i) {this.age = _i;}
}
public class Test {
	public static void main(String args[]) {
		final int CONSTANT = 10;   // needs to be assigned in declaration
    // CONSTANT = 20;   // can't do this bc of final, reassignment on a primitive 
    final Person ben = new Person();
    ben.print(45);
    Person adam = new Person();
    // ben = adam;   // value of the reference ben cannot be reasigned since its final
    // ben.name = "ho";  // can't assign to field since name is final, but could read it
    ben.getAge();
    ben.setAge(40);   // can be changed through method bc the field is not final, even though ben is final
    // adam.name = "ho:"; cannot change name, since name is final, even though Adam is public and not final
  }
}
// **********
// var usage in class
var name = "Ben Harki";   // var infers String as the class
// ***********
// var in user defined class
class ReallyLongName {
  int i;
}
class Test {
 	public static void main(String args[]) {
    var n = new ReallyLongName();
  }
}

INHERITANCE
// super class vs sub class,  "sub" contains and extends "super", terminology is weird
// can create multiple subclasses as branches, but only one sub can inherit one super
// *********
// Object class
// Object is a superclass for all subclasses, see CLASS, OBJECT CLASS, etc/
// some more Object methods: clone(), equals(), final getClass(), hashCode(), toString()
String str = "Ben";
int[] arr = new int[10];
Object o = str;
o = arr;
// *********** 
// can override toString() for System.out.print functions
// override toString() from Object class
// automatically inherits Object
class Person {
  String first;
  String last;
  Person(String first, String last) {
    this.first = first;
    this.last = last;
  }
  public String toString() {    // overrides Object's version 
    return first + " " + last;
  }
} 
class Test{ 
  public static void main(String args[]) {
    Person ben = new Person("Ben", "Harki");
    System.out.println(ben);    // print automatically calls ben.toString() to print
  }
}
// ********
// method args can be a superclass and accept subclasses, contravariance
// methods can return a subclass of the return type, covariance
public class Test {
	static Object print(Object o) {
		System.out.println(o);
		return Integer.valueOf(1);		// Integer is a subclass of Object
	}
	public static void main(String args[]) {
		int x = 3;
		String s = "Hi from main!";
		System.out.println(print(x));  // "3 \n 1"
		System.out.println(print(s));  // "Hi from main \n 1"
	}
}
// *********
// custom superclass and a subclass that inherits it
class Superclass {
  int x;    // can be accessed via get method
  private double d;   // cannot be accessed by subclass, except by a Superclass public get method
  void print_int() {
    System.out.println(x);
  }
}
class Subclass extends Superclass {
  String name;
  void set_name(String name, int age) {
    this.name = name;
    x = age;             // sets Superclass field
  }
}
class Test{ 
  public static void main(String args[]) {
    Superclass n = new Superclass();  // can access Superclass and fields alone
    Subclass sub = new Subclass();
    sub.x = 10;        // accesses superclass's public member inside its subclass 
    sub.print_int();   // use the superclass's method through subclass obj
    sub.set_name("Ben Harki", 37);
    sub.print_int();
  }
}
// ********
// casting and autocasting: declared vs actual type
// late-binding at runtime for common (overrided by subclass) methods
// casting is checked at runtime
public class Test {
	static class A {
		int x;
		A() {this.x = 1;}
		int getX() {return this.x;}
		public String toString() {
			return "x = " + x;
		}
	}
	static class B extends A {
		byte y;
		B() {this.y = 2;}
		// has A.getX()
		int getY() {return this.y;}
		public String toString() {		// overrides A's version
			return "x = " + x + ", y = " + y;
		}
	}
	public static void main(String args[]) {
		A a = new A();
		B b = new B();
		System.out.println(a);    // calls a.toString();
		System.out.println(b);    // calls b's version
		System.out.println(b.getX());  // b can callan inherited method
		System.out.println(b.getY());
		a = (A) b;    // upcasting is ok, has A declared (static) type and B actual (dynamic) type
    a = b;		// this is auto-casting, same as above
		System.out.println(a.getX());
		// System.out.println(a.getY());  // won't compile, a can only access A methods from b obj		
		System.out.println(a);	// for common methods, it will call B's (a's actual type is B)
		b = (B) a;    // compiles and no run-time exception, since a was already derived from B
    // b = a;      // compiler will not allow autocast, so it needs an explicit cast
    a = new A();	
		// b = (B) a;  // downcasting, compiles but causes run-time exception bc of new A()
    // Integer i = (Integer) "Hello";  // this will not compile since they are unrelated by inhertance
  }
}
// *********
// inheritance with constructors and superclass reference assignment
// constructors are called in order from most superclass to latest subclass
// constructors without the super keyword
// without super either the user-defined no args or default Superclass constructors are used
class Superclass {
  int x; 
  Superclass() {   // need this, unless default constructor is used (when no overloaded one exists)
    x = 0;
  }
  Superclass(int num) { // if this is defined, you need an explicit no-args  constructor for subcl constr 
    x = num;
  }
  void print_int() {
    System.out.println(x);
  }
}
class Subclass extends Superclass {
  String name;
  Subclass(int num, String name) {  // calls default constr for Superclass, make sure one exists
    this.x = num;
    this.name = name;
  }
}
class Test { 
  public static void main(String args[]) {
    Superclass sup = new Superclass(47);
    Subclass sub = new Subclass(37, "Ben Harki");
    sub.print_int();    // sub obj calls superclass public method
    sup = sub;    // can assign a super obj ref a sub class ref
    sup.x = 60;   // but cannot access subclass name field
  }
}
// ***********
// super keyword and constructors
// super can call any of the appropriate superclass constructors, from no args, diff args, ...
// can overload this subclass constructor, can call any of the overloaded supers in each subclass constructor
// only calls most immediate superclass constr
class Superclass {
  private int x;    // obj is only initialized by Superclass constructor
  Superclass(int num) {   // is called by super 
    x = num;
  }
  Superclass(Superclass sup) {    // can call on a subclass obj, see below
    x = sup.x;
  }
}
class Subclass extends Superclass {
  String name;
  Subclass(int num, String name) {   
    super(num);         // calls Superclass constructor, must be first statement 
    this.name = name;
  }
  Subclass(Subclass sub) {
    super(sub);             // calling super on subclass obj, is ok
    this.name = sub.name;
  }
}
class Test{ 
  public static void main(String args[]) {
    Subclass sub = new Subclass(37, "Ben Harki");
    Subclass sub2 = new Subclass(sub);
  }
}
// **********
// super as a ref to superclass, like "this" pointer
// super resolves the hiding the superclass field name of same name
class Superclass {
  int x;
  Superclass() {
    x = 0;
  }
}
class Subclass extends Superclass {
  String name;
  int x;        // same name as Superclass field, resolves by using super
  Subclass() {
    super.x = 10;
    x = 0;            // sets this.x to 0
    name = "Empty";
  }
  void print() {
    System.out.println(name + " " + x + " " + super.x); 
  }
  
}
class Test{ 
  public static void main(String args[]) {
    Subclass sub = new Subclass();
    sub.print();
  }
}
// **********
// subclass overrides (hides) superclass method and super
// only occurs when the names and types are the same, otherwise calls like an overloaded method
class Superclass {
  int x;
  Superclass() {
    x = 10;
  }
  void print() {
    System.out.println(x); 
  }
}
class Subclass extends Superclass {
  int y;       
  Subclass() {
    y = 50;           
  }
  void print() {    // overrides the Superclass version
    super.print();    // calls superclass method
    System.out.println(y); 
  }
}
class Test{ 
  public static void main(String args[]) {
    Subclass sub = new Subclass();
    sub.print();    // prints 10 and then  50, using subclass method 
  }
}
// **********
// dynamic method dispatch - a part of polymorphism, one interface multiple methods
// JVM decides which method is correct when overriding of Superclass method occurs
// inheritance and polymorphism allow for the Superclass to create a general template for
// subclasses: ex:  super class Figure has area method -> subclass Rectangle can override area method
//                                                     -> subclass Triangle can override area method
// can store a subclass ref as a super class, ref.method() will call the actual type's through dynamic dispatch
class Superclass {
  int x;
  Superclass() {
    x = 10;
  }
  void print() {
    System.out.println(x); 
  }
}
class Subclass extends Superclass {
  int y;       
  Subclass() {
    y = 50;           
  }
  void print() {    // overrides the Superclass version
    System.out.println(y); 
  }
}
class Test{ 
  public static void main(String args[]) {
    Superclass sup = new Superclass();
    Subclass sub = new Subclass();
    sup.print();   // 10
    sub.print();   // 50
    Superclass sarr[] = {new Superclass(), new Subclass()};
    for (Superclass s : sarr) {   // 10 50
      s.print();  // will call the "actual" type's method through dynamic dispatch
    }
  }
}
// ************
// final prevents overriding of method
// if there is a subclass with the same method name/type/args then compiler error
class Superclass {   
  int x;              
  final void print() {    // can't be overridden by a subclass
    System.out.println(x);
  }
}
final class Subclass extends Superclass {   // this class cannot be inherited by a future subclass
  int y;     // no void print() function allowed
}
// **********
// instanceof operator
// returns a boolean determining if the object is of a specific type at runtime
// can apply to a subclass  
class A {
  int a = 1;
}
class B extends A {
  int b = 2;
  void print() {
    System.out.println(this.b);
  }
}
class Test {
  public static void main(String args[]) {
    A a1 = new A();
    A a2 = new B();  // ok can always upcast to the superclass (auto cast here)  
    // B b1 = new A();  // cannot downcast to a child class
    B b2 = new B();
    A[] arr = {a1, a2, b2};   // A can hold A's and B's
    for (A a : arr) {
      if (a instanceof B) {
        // a.print();   // won't compile without a cast, since A does not ahve this method
        ((B) a).print();     // only prints the two that are new B's, selects B's method by dynamic dispatch
      }
    }
    if (b2 instanceof A) {
      System.out.println("B can be cast to an A");
    }
    // if ((new A()) instanceof B) {       // does not print
    //   System.out.println("A can be cast to a B");  
    // }  
  }
}
// **********
// can use var with inheritance, see chp. 8

ABSTRACT CLASS
// abstract classes are superclasses that declare a structure without providing a complete implementation 
// any class with one or more abstract methods must be declared abstract
// abstract methods are declared by superclass but implemented by its subclasses
// cannot declare abstract constructors or abstract static methods, or create specific objs, but can refs
abstract class Superclass {   
  int x;              
  Superclass() {
    x = 10;
  }
  abstract void print();    // method declared to be overridden by Subclass
  void print_message() {    // can also have concrete methods
    System.out.println("This is ok");
  }
}
class Subclass extends Superclass {  // inherits abstract class
  int y;       
  Subclass() {
    super();
    y = 50;           
  }
  void print() {    // implements the abstract declaration
    System.out.println(y); 
  }
}
class Test{ 
  public static void main(String args[]) {
    Subclass sub = new Subclass();
    sub.print();
    sub.print_message();    // can call Superclass method
    Superclass sup;   // can declare a reference, but not use constructor
    // Superclass sup2 = new Superclass();
    sup = sub;    // sup is now a subclass obj
    sup.print();  // calls subclass method
    Superclass sup2 = new Subclass();
    Subclass sub2 = new Subclass();
    Superclass sarr[] = {sup2, sub2};
    for (Superclass s: sarr) {   
      s.print();    // calls subclass method from an array of Superclass refs
      s.print_message();
    }
  }
}


PACKAGES, ACCESS, IMPORT
// see benspackage and benspackage/dprpkage dirs
// .java files in the package directory
// compile in that directory and run in its parent dir:
// $ java packagedir.file
// can also set the CLASSPATH variable or use the -classpath option running with $ java and $javac
// ***********
// class access and packages
// no modifer means member is public within its own package only and subclasses
public  // member may be accessed by code outside of its class, including different packages
private // can only be accessed in by code in its class, not accessible by other classes or packages
protected // can be seen outside package but only to classes that subclass your class
// **********
// more details on how a class member is accessible:
private // same class
// no modifier - same class, package subclass, package non-subclass 
protected // same class, package subclass, package non-subclass, different package subclass
public //same class, package subclass, package non-subclass, diff package sub and non-sub class
// *********
// (non-nested) class declaration modifiers, only default (no modifier) and public
//no modifier - only by code within its package
public // class can be accessed outside its package
// can only be one public class declared in the file, and file must be of that class's name
// SEE ACCESS EXAMPLE CHP 9
// **********
// see importpackage/Import.java, and benspackage/Person.java
// if names conflict between packages compiler will throw an error
import benspackage.*;   // imports whole package
import benspackage.Person;    // needs to be after package statement, Person is a public class
import java.lang.*;   // implicitly imported by compiler for all programss
// **********
// imports are optional, can invoke the full class name (with the package it is contained in) without them
Person ben = new benspackage.Person("Ben", "Harki");
// **********
// import static allows you to call static methods and other static members of a class without the full package.name
import static java.lang.Math.pow; 
import static java.lang.System.out;
class Test {
  public static void main(String args[]) {
    out.println(pow(2,3));
  }
}

INTERFACE
// uses polyorphism: one interface many methods, multiple classes can be called by an interface ref
// interfaces methods have no implementation details, just declarations
// makes possible for unrelated classes to implement same interface
// class that implements an interface must define all methods
// *********
// interface must be the same name as file, only one public interface per file
// all methods are implicitly public
// variables initialized inside an interface are static (implementing class cannot change the value) and final
// can be used to make variables global to a class that implements the Interface
// benspackage.Interface.java:
package benspackage;
public interface Interface {    // public allows access from outside the package
  String BEN = "Ben Harki";     // defines global variables (implicitly final)
  void print(String greeting);   // implemented when inhertited by "implementing" keyword, implementation in Master.java
}
// ***********
// ImpInterfaceEx.java imports and has classes that implement benspackage/Interface.java
// ***********
// abstract allows for partial implementation of an interface
// abstract class implementing an interface   // does not implement print() method in Interface.java  
abstract class Person implements Interface {  // see Interface.java                                     
	// must implement the Interface.print(String) method here
}  
// **********
// nested interface
// can also make an interface static, like a nested static class, local to the class
// now have to access Interface with a class name prefix    
class A {
  interface Print {     // can be declared public, private, protected, different from standalone file
    void pr();
  }
}
class B implements A.Print {    
  public void pr() {              // always needs to be public
    System.out.println("Hello");
  }
}
class Test {
  public static void main(String args[]) {
    A.Print a = new B();    // using a Print obj to repr a B obj
    a.pr();               
  }
}
// **********
// an interface can inherit another using extends
interface A {
  void print();
}
interface B extends A {   // class implementing B must implement all of A and B, unless declared abstract
  void print2();    // adds to interface A
}
class Print implements B {
  public void print() {
    System.out.println("Hi");
  }
  public void print2() {
    System.out.println("Hello");
  }
}
class Test{ 
  public static void main(String args[]) {
    Print p = new Print();
    p.print();
    p.print2();
  }
}
// **********
// default methods can be implemented in interfaces, these are not just declarations but impls
// useful for adding to an interface without breaking implementing classes (they would need to add too) 
// bc classes can implement multiple interfaces, with default methods, this is like multiple inheritance
interface Print {
  default void prn() {    // implementing class does not need to override this method, but can
    System.out.println("Hi");
  }
}
class A implements Print {}   // did not need implement the interface here sinceInteface method is declared default
class Test { 
  public static void main(String args[]) {
    (new A()).prn();
  }
}
// **********
// cannot multiple inherit classes but can multiple inherit interfaces
// Uncommenting h or g below causes interface K to fail to compile 
// Assume B extends A is A<-B
// I1<-K and I2<-K, multiple inheritance of interfaces
interface I1 { 
	public void f (); 
	default public void g () { System.out.println ("I1.g"); } 
	//public void h (); 
} 
interface I2 { 
	public void f (); 
	//default public void g () { System.out.println ("I2.g"); } 
	default public void h () { System.out.println ("I2.h"); } 
} 
interface K extends I1, I2 { } 
class C implements K { 
	public void f () { System.out.println ("C.f"); } 
} 
public class Test { 
	public static void main (String[] args) { 
		C c = new C (); 
		c.f (); 
		c.g (); 
		c.h (); 
	} 
} 
// *********
// The Diamond problem, assume B inherits A is A<-B, fixed by interfaces
// you cannot have multiple inheritance of classes, but you can inherit multiple interfaces
// problem: A<-B, A<-C, B<-D, C<-D, so does D call C's or B's overrided f method?
// remember: default gives a default implementation, normally interfaces do not require implementation
// if D inherits B.f() and C.f() and both are defaulted, the compiler will require D to implement its own to avoid confusion
interface A { 
	default public void f() {System.out.println ("A.f()");}
} 
interface B extends A { 	
	// if I comment out B.f(), it will default back to A.f()
	default public void f() {System.out.println ("B.f()");} 	// making this f() default will force its implementation in D
	default public void g() {System.out.println("B.g()");}
}
interface C extends A { 
	// default public void f()	// uncommenting will cause compiler error since it will look for D's impl of C.f()
	default public void h() {System.out.println("C.h()");}
} 
class D implements B, C {} 
public class Test { 
	public static void main (String[] args) { 
		D d = new D();
		d.f();		// B.f(), since default is employed in B
		d.g(); 		// B.g()
		d.h();		// C.h()
	} 
}
// **********
// two classes implementing the same interface, creating their own impl of meth()
// a method callMeth can be made, with an A obj param, and compiler will call the correct class's meth 
public class Test { 
	interface A {public void meth();} 
	static class B implements A {
		public void meth() {System.out.println("B.meth()");}
	}
	static class C implements A {
		public void meth() {System.out.println("C.meth()");}
	}
	static void callMeth(A a) {
		a.meth();
	}
	public static void main (String[] args) { 
		B b = new B();
		C c = new C();
		callMeth(b);			// B.meth(), like late-binding at runtime
		callMeth(c);			// C.meth()
	} 
}  
// **********
// see chp 9 interfaces > multiple inheritance issues for resolving name conflict/overriding of methods 
// and the use of super in an inheriting interface
// **********
// static interface methods do not require instance objs of an implementing class
// these methods are not inherited by a subclass or subinterface
// can actually instantiate an interface obj, normally can only use a reference, with an implementing obj as its value
interface A {
  static void prn() {
    System.out.println("Hi");
  }
}
class Test {
  public static void main(String args[]) {
    A.prn();                                // not implemented by a class or instance of A obj
  }
}
// **********  
// private methods
//  can only be called by a default method or other private methods that reside in an interface
// cannot be used by code outside the interface, including subinterfaces, bc they do not inherit them
// allows default methods to call common code
interface A {
  private void prn() {
    System.out.println("Hi");
  }
}
// **********
// see Annotations, represented by @interface, uses java.lang.annotation
// use to embed supplemental info into the program, does not effect program itself
// usually read by development or deployment tools
@interface name {}

STATIC OUTER CLASS, STATIC INNER CLASS, INNER CLASS
// an outer class is static if it only contains static members (but there is no static keyword for "outer" classes)
// static outer class, bc it has all static members, like a global variable class
// static variables are initialized at the start of execution
// make the constructor private, to ensure this is a proper static class
// no objects can be instantiated of class Print
class Print {
	static String MESSAGE;
	private Print() {;}		// to ensure no objs are instantiated in main()
	static void print() {
		System.out.println(MESSAGE);
	}
}
public class Test {
	public static void main (String[] args) { 
		// Print p = new Print();  // compiler error bc Print() is private
		Print.MESSAGE = "Hello World";		// no objs, but does need class identifier
		Print.print();
	} 
} 
// **********
// inner static class that overrides .equals()
// inner class methods are not visible outside containing class
public class Test {
	public static class MyInt {
		int x;
		MyInt(int _x) {
			this.x = _x;
		}
		public boolean equals(Object o) {		// could also return false if ref is null or some other object to be safe
			MyInt other = (MyInt) o;
			return this.x == other.x;
		}
	}
	public static void main(String[] args) {
		MyInt a = new MyInt(1);
		MyInt b = new MyInt(2);
		System.out.println(a.equals(b));   // false, compares values
		b = a;
		System.out.println(a == b);		// true, compares locations
	}
}
// **********
// static nested class as a member
// can insert outer method here to call an inner method, see next ex
class Test {
  private static int count = 0;
  static class Person {    // static inner-class does not exist independent of outer class
    String first;
    String last;
    Person(String first, String last) {
      this.first = first;
      this.last = last;
      count++;  // can access outer class's static members, even private, not non-static members w/out obj
    }
  }
 	public static void main(String args[]) {
    Person ben = new Person("Ben", "Harki"); 
    Person adam = new Person("adam", "Harki");
    System.out.println(count);    // 2 
  }
}
// **********
// non-static nested class: outer method calls inner method, inner method access's outer field 
// outer class does not have direct access to inner w/out obj
// can also declare a nested class that is local to a block i.e. loop, etc.
class Test {
  int i = 1;
  class Inner {
    int n = 2;
    void display_inn() {  // inner class method accesses outer field
      System.out.println(i);
    }
  }
  void display() {    // outer class method calls inner class method w/obj
    Inner inn = new Inner();  // need an object to access inner class field from outer method
    inn.display_inn();        // only access inner from within outer
    System.out.println(inn.n);  // accesses inner field
  }
 	public static void main(String args[]) {
    Test t = new Test();
    t.display();  // 1 then 2
  }
}
// **********
// inner class and new obj as an arg to a methods
public class Test {
	static class Message {
		String msg;
		Message() {
			this.msg = "Hi!";
		}
		void printMsg() {
			System.out.println(msg);
		}
	}
	static void meth(Message m) {
		m.printMsg();
		System.out.println("Ben!");
	}
	public static void main (String[] args) { 
		meth(new Message());		// Hi! Ben!
	} 
} 
// *********
// anonymous class (Interface in this case) implemented in the arg of method meth
// the interface instead could be replaced by a superclass that is overrided in the arg of meth
public class Test {
	static interface Message {
		public void printMsg();		// needs to be public so that meth can see it 
	}
	static void meth(Message m) {
		m.printMsg();
	}
	public static void main (String[] args) { 
		meth(new Message() {
			public void printMsg() {System.out.println("Hi");}
		});		// end of meth() call	
		meth(new Message() {		// another implementation
			public void printMsg() {System.out.println("Ben");}
		});		// end of meth()
	} 
} 
// **********
// inner class (interface) is implemented inside method meth()
public class Test {
	static interface Message {
		public void printMsg();		// needs to be public so that meth can see it 
	}
	static void meth() {
		Message m = new Message() {
			public void printMsg() {System.out.println("Hi");}
		};
		m.printMsg();
	}
	public static void main (String[] args) { 
		meth();
	} 
} 

FUNCTIONAL INTERFACE, LAMBDA, METHOD REFERENCES
// using a lambda, that accepts one arg, to define an abstract method in an interface
// functional interfaces only specifiy one abstract method
// void printMsg(String) can be implemented on the spot by a lambda to be anything that accepts a String and returns void
public class Test {
	static interface Message {		// functional interface
		void printMsg(String msg);		// implicity abstract (not defaulted, static, or private), can also add the abstract modifer
	}
	public static void main (String[] args) { 
		Message m = (msg) -> System.out.println(msg);		// don't need parens for one arg, (arg1, arg2) for more than one
		m.printMsg("Hi");
	} 
} 
// ***********
// lambda with two args, more than one statement in the body
// could make a CalcandPrint subtract, etc.
public class Test {
	static interface CalcAndPrint {	
		int solve(int a, int b);		
	}
	public static void main (String[] args) { 
		CalcAndPrint add = (a, b) -> {
			int sum = a + b; 
			System.out.println("Sum is " + sum);
			return sum;		// must use return for more than one statement
		};
		int s = add.solve(3,4);		// Sum is 7
		System.out.println(s);		// 7
	} 
}
// ***********
// skipped Generic<> functional interfaces
// ***********
// method accepts a lambda as an arg, two by anonymous, one named as a var
public class Test {
	static interface Calc {	
		int operate(int a, int b);		
	}
	static void printOp(Calc c, int a, int b) {
		System.out.println(c.operate(a, b));
	}
	
	public static void main (String[] args) { 
		printOp((a,b) -> a+b, 3, 4);
		printOp((a,b) -> a*b, 3, 4);
		Calc sub = (a,b) -> a-b;
		printOp(sub, 3, 4);
	} 
} 
// *********
// skipped lambdas and exceptions
// *********
// use of a method reference, using ::
// brings in a method from another class as an argument, wired together by interface 
// printOp accepts an interface obj (really a method), and Add has the same method signature as the interface's method
public class Test {
	static interface Calc {
		int operate (int a, int b);
	}
	static class Add {
		static int add(int a, int b) {return a + b;}
	}
	static void printOp(Calc c, int a, int b) {
		System.out.println(c.operate(a, b));
	}
	public static void main (String[] args) { 
		printOp(Add::add, 3, 4);
	} 
} 
// ***********
// use of a method reference, using ::
// brings in a bound method in via its object, wired together by interface
public class Test {
	static interface Calc {
		int operate (int a, int b);
	}
	static class Add {
		int add(int a, int b) {return a + b;}		// not static anymore, so add is bound to the object
	}
	static void printOp(Calc c, int a, int b) {
		System.out.println(c.operate(a, b));
	}
	public static void main (String[] args) { 
		Add a = new Add();
		printOp(a::add, 3, 4);
	} 
} 
// *************
// TODO: redo this example and add one generics and constructor references
// constructor reference, wired by an interface
// not a great example, but could be used to come up with different-typed constructors
// 	 using generics (example not shown below)
public class Test {
	static interface Calc {
		MyInt func(int a);
	}
	static class MyInt {
		int a;
		MyInt(int _a) {this.a = _a;}
	}
	public static void main (String[] args) { 
		Calc c = MyInt::new; 	// holds the reference to the constructor
		MyInt m = c.func(200);		// calls the constructor through interface
		System.out.println(m.a);		// 200
	} 
} 
// *************
// skipped method reference with generics

EXCEPTIONS    // run time errors
// built in classes Throwable->Exception->RuntimeException
// RuntimeExceptions do not need throws in method declaration, other unchecked Exceptions do
// Exceptions class can be inherited and have its methods overridden for your exception-based classes
// **********
int e = 1/0;  // default exception handler throws java.lang.ArithmeticException, a subclass of Exception
// **********
// once error is found in try, control is transfered to catch
// catch refers to the immediately preceding try block
class Test {
  public static void main(String args[]) {
    try {   // need braces even for one statement
      int p = 1/0;  
      System.out.println("does not get executed"); // not executed bc error occurs before
    }
    catch(ArithmeticException e) {    // e is the .toString() method error string, overridden by Throwable
      System.out.println("Division by 0");
      System.out.println(e);    // print the default runtime error msg, but execution continues
      int p = 0;
    }
  }
}
// **********
// multiple catch statements, executes the first catch block that is detected
class Test {
  public static void main(String args[]) {
    try {   // need braces even for one statement
      int l = args.length;
      int b = 10/l;   // may be an error if no command line args like when running $ java Test
      int a[] = {1};
      a[1] = 5;       // always an error
    }
    catch(ArithmeticException e) {    // e is the .toString() method error string, overridden by Throwable
      System.out.println(e);    // prints system msg(execution is continued)
    } 
    catch(ArrayIndexOutOfBoundsException e) {
      System.out.println(e);    // prints system msg(execution is continued)
    } 
    catch(Exception e) {
      System.out.println(e);    // must place this class here, or it will throw first, making its subclass excpetions unreachable
    }
    
  }
}
// **********
// can be nested: as a try/catch inside another try
try {
  try {
    // ExceptionSubclass2 error here transfers control to outer catch block
    // same execution occurs even if this inner try/catch is moved into a method
  } 
  catch(ExceptionSubclass1 e) {   // ExceptionSubclass1 can be ArithmeticException for example
  }
} 
catch(ExceptionSubclass2 e) {
}
// **********
// NullPointerException
class Test {
  int a;
  public static void main(String args[]) {
    try {
      Test t = null;    
      t.a = 5;          // exception on execution
    } 
    catch(NullPointerException e) {
      System.out.println(e);  // execution continues
    }
  }
}
// *********
// throw    // execution is stopped immediately unless caught, throw forces an error
// must throw of type Throwable or a subclass
// Throwable also has a method getMessage() which will display "demo" String
class Test {
  public static void main(String args[]) {
    try {
      throw new NullPointerException("demo");   // forces an exception, that is immediately caught
    } 
    catch(NullPointerException e) {
      String msg = e.getMessage();
      System.out.println("caught:" + e);  // prints msg with "demo" at end, but execution continues
      System.out.println("msg is again: " + msg); // msg is "demo"
    }
    System.out.println("it continues"); // this is executed since the throw was caught
    try {
      throw new NullPointerException();
    } 
    catch(NullPointerException e) {
      throw e;              // stops execution, any more code after is unreachable
    }
  }
}
// **********  
// throws is necessary for all Exceptions except RuntimeException, Error, and their subclasses
// delegate the exception back to the try in main()
class Test {
  static void throwExc() throws IllegalAccessException {  // can provide a comma seperated list 
    throw new IllegalAccessException("demo");   // this type needs a throws in method declaration
  } 
  public static void main(String args[]) {
    try {
      throwExc();   // no try catch in body of this method, caught in main
    }
    catch(IllegalAccessException e) {
      System.out.println(e);
    }
  }
}
// **********
// finally, allows code to execute after the error is caught, helps continue a method that returns prematurely
// finally block executes whether or not an exception is thrown
// executes even if no catch matches the exception
class Test {
  static void throwExc() {  
    try {   // each try requires at least a catch or finally
      throw new RuntimeException();   // anything after this, inside this block will not execute
    }
    catch(RuntimeException e) { // exception caught here, prints error, control transfers to finally 
      System.out.println(e);
    }   
    finally {   // optional, executes even if no error was caught
      System.out.println("Compiler throws unreachable error here without finally");
      return;
    }
  } 
  public static void main(String args[]) {
    throwExc();
  }
}
// **********
// finally, without a catch until main
// finally always executes before a return, even if ther is a  return is in the try block of a method
class Test {
  static void throwExc() {  
    try {
      throw new RuntimeException();   
    }
    finally {  
      System.out.println("executes on the way out");  // executes before catch in main
    }
  } 
  public static void main(String args[]) {
    try {
      throwExc();
    }
    catch(RuntimeException e) {
      System.out.println("Exception caught, execution continues");
    }
  }
}
// **********
// inherit Exception class for your own exceptions
// can override toString() to create custom messages
class MyException extends Exception {
  int exitcode;
  MyException(int a) {
    exitcode = a;
  }
  public String toString() {
    return "MyException returns " + exitcode;
  }
}
class Test {
  public static void main(String args[]) {
    try {
      throw new MyException(1);
    } 
    catch(MyException e) {  
      System.out.println(e);
    } 
  }
}
// **********
// can chain exceptions
// NullPointerException is thrown with ArithmeticException and a cause message added too
class Test {
  public static void main(String args[]) {
    try {
      NullPointerException e = new NullPointerException();
      e.initCause(new ArithmeticException("insert cause here "));
      throw e;
    }
    catch (NullPointerException e) {
      System.out.println(e);  // Null Pointer error message  
      System.out.println(e.getCause());   // Aritmentic exception with "insert cause here"
    }
  }
}
// **********
// catch multiple exceptions in one catch block
try {
  // two of the exceptions can occur and caught below
}
catch(NullPointerException|ArithmeticException) {
}
// see re-throw for a more precise way
// **********
// assert can be applied to a condition which is always true, for debugging
// assert can be applied to an expression that simplifies to a Boolean
// if the condition is true, execution continues
// if false it is then AssertionError exception is thrown
// run with: > java -ea Test
//   -ea:BensPackage enables for a specific package
//   -da disables assertions, can also disable assertions for a specific package
// can pass it a custom message to display or anything of type non-void 
//    (non-void converts to a string and displayed)
// asserts are not included in released code
class Test {
  public static void main(String args[]) {
    int x = -1;
    assert x < 0;   // assertion passes, so program continues
    // assert -x == (-1)*(-x);  // this is false, so runtime exception is thrown
    assert -x == (-1)*(-x) : "double negative condition fails";   // throws runtime exception with message
  }
}

ENUM
// list of named constants, enum object can only hold the values in the declaration
// like a class: has constructor, methods, and instance vars, but no need for new, use like a primitive type 
// can't be used as a subclass or superclass
// initialize and use in a switch
// has values() to return an array of the enums, and valueOf() methods
class Test {
  enum Level {
    HIGH, MEDIUM, LOW   // each is public static final
  } 
  public static void main(String args[]) {
    Level m = Level.MEDIUM;
    System.out.println(m);    //  MEDIUM
    if(m == Level.MEDIUM) {   // can use operators
      System.out.println("True");
    }
    Level user = Level.HIGH;
    switch(user) {    // use in a switch
      case LOW:
        System.out.println(Level.LOW);
        break;
      case MEDIUM:
        System.out.println(Level.MEDIUM);
        break;
      case HIGH:
        System.out.println(Level.HIGH);          
      default:
        System.out.println("no option");
    }
    Level arr[] = Level.values();   // an array containing the list using .values()
    for(Level l : arr) {
      System.out.println("in array: " + l);
    }
    Level val = Level.valueOf("HIGH");  // using valueOf(String)       
    System.out.println(val);     // HIGH
  }
}
// *********
// enum with constructor, field, and get method
class Test {
  enum Level {
    HIGH(0), MEDIUM(1), LOW(2);   // each calls constructor
    private int i;
    int get_int() {
      return i;
    }
    Level(int num) {    // can create overloaded versions, no args would not have () in list definition
      i = num;
    }
    
  } 
  public static void main(String args[]) {
    System.out.println(Level.MEDIUM.get_int());   
    Level h = Level.HIGH;
    System.out.println(h + " " + h.get_int());
  }
}
// **********
// every enum inherits java.lang.Enum methods: ordinal(), comparteTo(), equals()
class Test {
  enum Level {
    HIGH, MEDIUM, LOW;
  } 
  public static void main(String args[]) {
    Level l1, l2, l3;
    l1 = Level.HIGH;
    l2 = Level.MEDIUM;
    l3 = Level.LOW;
    System.out.println(l1.ordinal());   // 0 for this one,  rank of the constant
    System.out.println(l1.compareTo(l2));   // compares ordinal values
    System.out.println(l2.equals(l3));
  }
}
// ***********
// returning an enum
class Test {
  enum Level {
    HIGH, MEDIUM, LOW;
    Level h() {
      return Level.HIGH;
    }
  } 
  public static void main(String args[]) {
    Level l = Level.MEDIUM;
    System.out.println(l.h());    
  }
}

GENERICS    // unfinished
// generics info:
// collections API contains lists, maps, etc. that work with any object
// generics are classes/methods that contain parameterized types
// generics added type safety - all casts are automatic and implicit
//   two objects of the same generic class with different concrete type parameters are not of the same class
// they are type checked, so one obj of type Integer can't be used for String, etc
// type parameters X and Y are basically replaced by necessary types when employed
// type parameters cannot be primitives, they must be objects with a reference
// can use T.getClass().getName() on Type Parameter to show what concrete type is employed 
// **********
// T as a type parameter in the field type, arg type, and return type 
// T in the field of generic class, return type, and arg type of a method
// MyGen<Integer> is not the same class as MyGen<String>, differ by type parameters
class MyGen<T> {
  private T obj;
  MyGen(T o) {
    this.obj = o;
  }
  T get_field() {
    return this.obj;
  }
}
public class Test {
  public static void main (String[] args) { 
    MyGen<Integer> i = new MyGen<Integer>(3);   // autoboxes 3 to an Integer
    MyGen<String> s = new MyGen<String>("Ben");
    MyGen<Double> d = new MyGen<Double>(3.14);
    System.out.println(i.get_field() + " " + s.get_field() + " " + d.get_field());
  }
}
// **********
// non-generic use of Object, similar to generics, but without type safety
// Object has a toString() method that is overridden by String nd Integer
// dynamic dispatch would call the actual type's .toString() without casting
// other methods or operations would need casting
// written with <> generics would create proper type safety compiler errors instead of run-time errors
class NonGen {
  private Object o;
  NonGen(Object o) {
    this.o = o;
  }
  Object get_o() {
    return this.o;
  }
}
public class Test {
  public static void main (String[] args) { 
    NonGen i = new NonGen(Integer.valueOf(12));
    NonGen s = new NonGen(new String("Ben"));
    NonGen[] nobs = {i, s};
    for(NonGen n: nobs) {
      System.out.println(n.get_o());   // does not need a cast bc of dynamic dispatch: calls actual .toString()
    }
    NonGen i2 = new NonGen(((Integer)i.get_o()) + 10);  // this needs a cast
    System.out.println(i2.get_o());  // 22
    i = s;   
    String sval = (String) i.get_o();   // weird but works, not clear by the code that i holds a String
  }
}
// **********
// can have more than one type parameter
// can use var to help shorten declaration syntax
// can also use the same concrete type for each type parameter
class Person<A, N> {
  private A age;
  private N name;
  Person(A a, N n) {
    this.age = a;
    this.name = n;
  }
  public String toString() {
    return "age: " + this.age + ", name: " + this.name; 
  }
}
public class Test {
  public static void main (String[] args) { 
    Person<Float, String> b = new Person<Float, String>(38.0f, "Ben");
    var m = new Person<Integer, String>(35, "Mags");
    System.out.println(b + "\n" + m);
  }
}
// **********
// type bounds place an "upper" bound on the types that are accepted as type parameters
// all type wrapper classes extend Number, and you cannot use primitive types in generics
// types have to at least inherit/subclass the superclass bound, can call superclass methods
// T can only be Number or a type that inherits Number
// Number contains doubleValue() that converts each subtype to a Double
class Sum<T extends Number> {   // Number must be a superclass of T
  T[] nums;
  Sum(T[] n) {
    this.nums = n;
  }
  Double sum_vals() {
    Double sum = Double.valueOf(0.0);
    for (T t: this.nums) {
      sum += t.doubleValue();   // doubleValue() is in the Number class, overrided by its subclasses
    }
    return sum;
  }
} 
public class Test {
  public static void main (String[] args) { 
    Integer[] ints = {1,2,3,4,5};
    Double[] dbls = {1.0, 2.0, 3.0};
    Sum<Integer> sum_ints = new Sum<Integer>(ints);
    System.out.println(sum_ints.sum_vals());
    Sum<Double> sum_ds = new Sum<Double>(dbls);
    System.out.println(sum_ds.sum_vals());
  }
}
// **********
// classes can use an interface as a bound for a generic
// T must be a type that implements the IPrint interface
interface IPrint {
  void print();
}
class PrintStr implements IPrint {
  String msg;
  PrintStr(String _msg) {
    this.msg = _msg;
  }
  public void print() {
    System.out.println(this.msg);
  }
}
class PrintInt implements IPrint {
  int i;
  PrintInt(int i) {
    this.i = i;
  } 
  public void print() {
    System.out.println(this.i);
  }
}
class Print<T extends IPrint> {  // T must implement IPrint
  T pr;
  Print(T _pr) {
    this.pr = _pr;
  }
  void print() {     // not the impl for interface IPrint but a wrapper with same name
    this.pr.print();
  }
}
public class Test {
  public static void main (String[] args) { 
    PrintStr ps = new PrintStr("Hello from PrintStr!");
    Print<PrintStr> p1 = new Print<PrintStr>(ps);  
    p1.print();
    PrintInt pi = new PrintInt(200);
    Print<PrintInt> p2 = new Print<PrintInt>(pi);
    p2.print();
  }
}
// **********
// class can have a generic bound of two or more classes or interfaces connected with &: called intersection type
// if there is a class bound it most come first
// T must implement all interfaces and subclass all classes listed after extends
// here it is only two interfaces
// TODO: can also use an intersection type in casting
interface GetInt {
  int get();
}
interface IPrint {
  void print();
}
class MyInt implements GetInt, IPrint {
  int i;
  MyInt(int i) {
    this.i = i;
  }
  public int get() {
    return this.i;
  }
  public void print() {
    System.out.println(this.i);
  }
}
class PrintInt<T extends GetInt & IPrint> {
  T pi;
  PrintInt(T pi) {
    this.pi = pi;
  }
  void print_int() {
    pi.print();   // call's T's print() from implementing IPrint
  }
  int get_int() {
    return this.pi.get();
  }
}
public class Test {
  public static void main (String[] args) { 
    PrintInt<MyInt> i = new PrintInt<MyInt>(new MyInt(256));
    i.print_int();
    int val = i.get_int(); 

  }
}
// **********
// ? wildcard type will have the compiler accept any type for T (within bounds)
// ? allows comparing between Sum<Double> and Sum<Integer> and would match any Sum<> obj
// > matches any valid Sum<> type, but is not a bound, see generic bound above above
class Sum<T extends Number> {   // Number must be a superclass of T
  T[] nums;
  Sum(T[] n) {
    this.nums = n;
  }
  Double sum_vals() {
    Double sum = Double.valueOf(0.0);
    for (T t: this.nums) {
      sum += t.doubleValue();   // doubleValue() is in the Number class, overrided by its subclasses
    }
    return sum;
  }
  boolean equal_sum(Sum<?> other) {   // Sum<T> other does not work as a parameter when T is of another typw than the invoking object
    return this.sum_vals().equals(other.sum_vals());   // needs Objects .equals since Double is an object, not a primitive
  }
} 
public class Test {
  public static void main (String[] args) { 
    Integer[] ints = {1,2,3,4,5};
    Double[] dbls = {1.0, 2.0, 3.0, 4.0, 5.0};
    Sum<Integer> sum_ints = new Sum<Integer>(ints);
    Sum<Double> sum_ds = new Sum<Double>(dbls);
    System.out.println(sum_ints.equal_sum(sum_ds));
  }
}
// **********
// bounded wildcard as a method argument: method accepts obj that has a wildcard type parameter with an upper bound 
// Coords<?> can hold any of the three classes
// use Coords<? extends superclass> to limit to any concrete T that has a superclass upper bound
//    ? has to at least inherit/implement the superclass/interface or it could be the bound itself
// use Coords<? super subclass> to limit to any concrete T that is a superclass to subclass
// A <- B <- C    // <? extends B>, B is an upper bound, so only B and C work bc they both are B or inherit it
// A <- B <- C    // <? super B>, B is a lower bound, so only A and B work bc they are superclasses of B or are B
// TODO: could also work with an interface instead of inheritance, but you probably still need an inheritance hierarchy
class OneD {
  float x;    // could make private, but then you need a get()
  OneD(float x) {
    this.x = x;
  }
}
class TwoD extends OneD {
  float y;
  TwoD(float x, float y) {
    super(x);
    this.y = y;
  }
}
class ThreeD extends TwoD {
  float z;
  ThreeD(float x, float y, float z) {
    super(x, y);
    this.z = z;
  }
}
class Coords<T extends OneD> {   // holds a reference to any one of the above classes
  T crd;
  Coords(T crd) {
    this.crd = crd;
  }
}
class PrintCoords {
  static void print2D(Coords<? extends TwoD> c) {  // c has to be Chords<> obj that at least inherits TwoD
    System.out.println("(" + c.crd.x + ", " + c.crd.y + ")");    // c.crd.y will now exist 
  }
  static void print1D(Coords<? super TwoD> c) {    // lower bound, see above
    System.out.println("(" + c.crd.x + ")");
  } 
}
public class Test {
  public static void main (String[] args) { 
    Coords<OneD> one_d = new Coords<OneD>(new OneD(0));
    Coords<TwoD> two_d = new Coords<TwoD>(new TwoD(0,3));   
    Coords<ThreeD> thr_d = new Coords<ThreeD>(new ThreeD(0,1,2));
    // PrintCoords.print2D(one_d);    // compiler error bc of type parameter bound on Chords<> 
    PrintCoords.print2D(two_d);    // T can be exactly the upper bound (inclusive)
    PrintCoords.print2D(thr_d);   // prints the (x, y) of (x, y, z)
    PrintCoords.print1D(one_d);   // (0.0)
    PrintCoords.print1D(two_d);   // (0.0)
    // PrintCoords.print1D(thr_d);   // compiler error bc it is excluded by the lower bound
  }
}
// **********
public class CLASS<?,?>    // wildcard and 2 type params, will match any Class obj
// **********

IO
/*
streams produce or consume information
same classes can apply to different devices like keyboard, disk file, network socket      
two types, byte and character
InputStream and OutputStream are byte stream abstract classes with subclasses, all found in java.io
  subclasses contain read() and write methods(), overridden subclass methods
  ex: FileInputStream, FileOutputStream, BufferedInputStream, BufferedOutputStream, PrintStream
Reader and Writer are abstract classes for Java character Streams
  subclasses include InputStreamReader, BufferedReader and they have overridden read() and write() methods 
  InputStreamReader converts bytes to chars
System is contains predefined variables in, out, and err
  in by default is keyboard, out is console, err is also console, can be redirected to another device  
  System.in is an object of type InputStream, System.out and System.err is of PrintStream
  both are bytestreams and can be wrapped by character streams
InputStreamReader i = new InputStreamReader(System.in) converts byte input from keyboard into chars
BufferedReader b = new BufferedReader(new InputStreamReader(System.in))  creates char stream linked to console through System.in
  b.read() reads a char and returns as int value, 01 at the end of the stream, can throw IOException
*/

// ***********
// char stream BufferedReader for keyboard input, connected to byte stream System.in
// uses read() for char reads
import java.io.*;
class Test {
  public static void main(String args[]) throws IOException {
    char c;
    BufferedReader b = new BufferedReader(new InputStreamReader(System.in));
    do {
      c = (char) b.read();   // cast to char, goes to next line, ent char, press ent goes to next line
      System.out.print(c);
    }
    while(c != 'q');
  }
}
// **********
// uses readLine() for String reads
import java.io.*;
class Test {
  public static void main(String args[]) throws IOException {
    BufferedReader b = new BufferedReader(new InputStreamReader(System.in));
    String line;
    do {
      line = b.readLine();     
      System.out.println(line);
    }
    while(line != "quit");
  }
}
// ***********
STOPPED AT WRITING CONSOLE OUTPUT IN BOOK

NETWORKING
/*
socket is a bidirectional endpoint in a network
port is a numbered socket on a machine, listened to by a Server
Server can listen to multiple clients connecting on a port number, but must be threaded
internet address uniquely identifies the computer on the Net
domain names represent the computer in a name space, like .com for commercial
DNS (Domain Naming Service) maps domain name to IPaddress
Socket is a class to handle a connection from the client to the server
  contains getInputStream() that returns the InputStream (byte) associated 
  contain getOutputStream() that returns the OutputStream (byte) associated
  other methods include connect(), isConnected(), isBound() 
ServerSocket is a server class for listening to client Socket connections
  accept()  returns socket connected to client
    
// getInputStream() and getOutputStream() captures the other's streams
Client
  Socket sock = new Socket("serverName", port)

  // Server Input
  InputStream servIn = sock.getInputStream()  // returns InputStream (byte) of the Server
  InputStreamReader chars = new InputStreamReader(servIn)  // converts to char stream
  BufferedReader fromServer = new BufferedReader(chars)   // creates char stream for client use

  // Server Output
  OutputStream servOut = sock.getOutputStream(); // returns (like console) OutputStream(bytes) of Server
  PrintStream toServer = new PrintStream(servOut);  // creates byte stream for client use
  
Server  
  ServerSock servsock = new ServerSocket("serverName", port)
  sock = servsock.accept()  

  // Client Input
  InputStream clientIn = sock.getInputStream()  // returns InputStream (byte) of the client
  InputStreamReader chars = new InputStreamReader(clientIn)  // converts to char stream
  BufferedReader fromClient = new BufferedReader(chars)   // creates char stream for server use

  // Client Output
  OutputStream clientOut = sock.getOutputStream(); // returns (like console) OutputStream(bytes) of Server
  PrintStream toClient = new PrintStream(ClientOut);  // creates byte stream for client use

Communication
Client                            <->   Server
servIn (converts to char stream)  <-    toClient (byte stream)   
toServer (byte stream)            ->    fromClient (converts to char stream)        

*/  

  
OLD STUFF 
// i/o  
//-------
import java.io.File;  // creates filename.txt in src folder
import java.io.IOException;  
public class Testing {
  public static void main(String[] args) {
    try {
      File myObj = new File("filename.txt");		// "C:\\Users\\...\\filename.txt" for win
      if (myObj.createNewFile()) {	
        System.out.println("File created: " + myObj.getName());
      } else {
        System.out.println("File already exists.");
      }
    } catch (IOException e) {	// throws an exception
      System.out.println("An error occurred.");
      e.printStackTrace();
    }
  }
}
//-------
import java.io.FileWriter;   // creates or overwrites file to write to
import java.io.IOException;  
public class Testing {
  public static void main(String[] args) {
    try {
      FileWriter myWriter = new FileWriter("filename.txt");
      myWriter.write("Files in Java might be tricky, but it is fun enough!");
      myWriter.close();
      System.out.println("Successfully wrote to the file.");
    } catch (IOException e) {
      System.out.println("An error occurred.");
      e.printStackTrace();
    }
  }
}
//-------
import java.io.File;  // reads entire txt line by line, each as a string
import java.io.FileNotFoundException;  // Import this class to handle errors
import java.util.Scanner; // Import the Scanner class to read text files
public class Testing {
  public static void main(String[] args) {
    try {
      File myObj = new File("filename.txt");
      Scanner myReader = new Scanner(myObj);
      while (myReader.hasNextLine()) {
        String data = myReader.nextLine();	// reads line by line
        System.out.println(data);
      }
      myReader.close();
    } catch (FileNotFoundException e) {
      System.out.println("An error occurred.");
      e.printStackTrace();
    }
  }
}	
//-------
// print format method
public class Testing {	
  public static void main(String[] args) {
    int i = 2;
    double r = Math.sqrt(i);
    System.out.format("The square root of %d is %f %n", i, r);	// %n is end line, %d is integer displayed as decimal 
    System.out.format("%2$f, %1$+020.10f", Math.PI, r);  	// 20 total chars, 0s in front, 10 dec places,
  }						//  1$ is the 1st argument index for ordering  // prints sqrt(2) then pi
}
//-------
import java.util.Scanner;  // Save user input as string
public class Testing {
  public static void main(String[] args) {
    Scanner myObj = new Scanner(System.in);  // Create a Scanner object
    System.out.println("Enter username");
    String userName = myObj.nextLine();  // Read user input, saves as a string, also .nextInt(), .nextDouble()
    System.out.println("Username is: " + userName);  // Output user input
  }
}

// Math class
Math.E; Math.PI;
Math.max(num1,num2);
.min(num1,num2); .sqrt(num); .abs(num);
Math.random();	// in [0,1), multiply to get other intervals
.abs(); .sin(); .cos(); .tan(); .asin();  // etc. // in radians
.toDegrees(); .toRadians();
.exp(); .log(); .pow(); .round();
//-------
int num = (int)(Math.random()*101);	// random # between 1 and 100
//-------

// ArrayList		// size can be modified, of same type
					// better to use when adding or removing from ends, accessing random elements
A_list.set(ind,item), .remove(ind), .clear(), 
.size() 
//-------
import java.util.ArrayList;
public class Testing {
  public static void main(String[] args) {
    ArrayList<String> cars = new ArrayList<String>();
    cars.add("Volvo");
    cars.add("BMW");
    System.out.println(cars);
    cars.get(1);	// access an item in the list by index
    for (String i : cars) {	// for-each loop, can also write by index
      System.out.println(i);
    }
  }
}
//-------
import java.util.ArrayList;
import java.util.Collections;  // Import the Collections class for .sort(A_list)
public class Testing {
  public static void main(String[] args) {
    ArrayList<String> cars = new ArrayList<String>();
    cars.add("Volvo");
    cars.add("BMW");
    Collections.sort(cars);  // Sort cars
    for (String i : cars) {
      System.out.println(i);
    }
  }
}
//-------

// LinkedList		// better to use when looping through each element
//-------	
import java.util.LinkedList;
public class Main {
  public static void main(String[] args) {
    LinkedList<String> cars = new LinkedList<String>();
    cars.add("Volvo");
    cars.add("BMW");
    System.out.println(cars);
  }
}
//-------


// HashMap		// can also use a HashSet with unique items
hmap.get(key),.remove(key),.get(key),.size(),
//-------
import java.util.HashMap;	// like dict in Python 
public class Testing {
  public static void main(String[] args) {
    HashMap<String, String> capitalCities = new HashMap<String, String>();
    capitalCities.put("England", "London");		// (key,value) can also do (string,int)
    capitalCities.put("Germany", "Berlin");		// key is the index to the value
    System.out.println(capitalCities);
    System.out.println(capitalCities.get("England"));	// London
    for (String i : capitalCities.keySet()) {
      System.out.println(i);
    }
  }
}
//-------
import java.util.HashMap;	// like dict in Python 
public class Testing {
  public static void main(String[] args) {
    HashMap<String, String> capitalCities = new HashMap<String, String>();
    capitalCities.put("England", "London");		// (key,value) can also do (string,int)
    capitalCities.put("Germany", "Berlin");		// key is the index to the value
    System.out.println(capitalCities);
    System.out.println(capitalCities.get("England"));	// London
    for (String i : capitalCities.keySet()) {
      System.out.println(i);	// prints keys England Germany
    }
    for (String i : capitalCities.values()) {
      System.out.println(i);	// prints values
    }
    for (String i : capitalCities.keySet()) {	// prints both
      System.out.println("key: " + i + " value: " + capitalCities.get(i));
    }
  }
}
//-------
import java.util.HashMap;	// set <key,value> as different types
public class Testing {
  public static void main(String[] args) {
    HashMap<String, Integer> people = new HashMap<String, Integer>();	// <key,value>
    people.put("John", 32);
    people.put("Steve", 30);
    people.put("Angie", 33);
    for (String i : people.keySet()) {
      System.out.println("key: " + i + " value: " + people.get(i));
    }
  }
}	
//-------


// Iterator		// used to loop through collections like ArrayList, HashSet, ...
//-------
import java.util.ArrayList;	
import java.util.Iterator;
public class Testing {
  public static void main(String[] args) {
    ArrayList<String> cars = new ArrayList<String>();
    cars.add("Volvo");
    cars.add("BMW");
    cars.add("Ford");
    Iterator<String> it = cars.iterator();
    System.out.println(it.next());	// prints first item
    while(it.hasNext()) {
      System.out.println(it.next());	// loops through whole collection
    }
  }
}
//-------
import java.util.ArrayList;
import java.util.Iterator;
public class Testing {
  public static void main(String[] args) {
    ArrayList<Integer> numbers = new ArrayList<Integer>();
    numbers.add(12);
    numbers.add(8);
    numbers.add(2);
    Iterator<Integer> it = numbers.iterator();
    while(it.hasNext()) {
      Integer i = it.next();
      if(i < 10) {
        it.remove();	// would not work in for or for-each loops due to changing size 
      }
    }
    System.out.println(numbers);	// prints [12]
  }
}













      
 


