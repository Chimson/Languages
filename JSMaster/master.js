// execution starting point
function Main() {

// TYPES
// primitive types are immutable
// Number, String, Boolean are primitive
// undefined and null are primitive
// Symbol is a primitive type
// undefines and null do not have their own methods
//   but the other primitive types do
// -----
// everything else is an object of Object class, see OBJECT
// object types are mutable
// other Objects include Array, Set, Map, RegExp, Date,  
//   Error 
// functions and classes are specialized objects
// -----
// Number is 64-bit
0xFF    // hex
0b1011  // binary
0o377   // octal
1.47E-32  // scientific notation for float
2**4

// OPERATORS
// Operators: %, +, -, *, **, /, ++, --, +=, ...
// Boolean Operators: ===, !==, <, <=, >, >=, &&, ||, !

// LET and CONST
// variables are declared with let and assigned with =
// immutable values are named with const
// some examples of the different types
let x;
let y = 10;
let z = 4.5, a = 5;   // Numbers can be floats or ints
const x2 = 44; 
let tbool = true;
let fbool = false;
let nval = null;
let uval = undefined;
// -----
// grab a value from a different module
let pi = Math.PI;

// VAR
// TODO: Show these Examples
// var declarations do not have block scope like let
//   they are scoped to the body of the containing function, no matter how deep they are nested
// vars outside of functions are global, and are implemented as properties to the globalThis object
//   this is different from let and const
// you can have multiple declarations of var, unlike let
// var variables are "hoisted" up to the top enclosing function
//   they may be see before defined, if initialization is deep in the function stack
//   in this case the var is given an undefined value, until initialized
var zz = "weird var";


// STRING
// can use "", or '' for strings
let str1 = "string";
let str2 = 'str';
// -----
// here is a formatted string using `` and ${}
let int1 = 300;
let str3 = `this is ${int1}`;
// -----
// You can use any Unicode character
// can also use them variable names
// two versions, one with \uXXXX and one with \u{XXXXXX}
// {} version is expanded to include emojis
let uni1 = "\u00E9";
let uni2 = "\u{1F600}";
console.log(uni1 + ' ' + uni2);

// OBJECTS
// objects are of typee Object and are collections of 
//   properties
// properties have a name and value (value can be primitive)
//    or another object
// create an object on the fly and add properties on the fly
// objects are name value pairs, can access with . or like a dict
// all objects have a default print string
// initialize using initializer expression
let book = {topic: "Javascript", edition:7}; 
console.log(book.topic);
console.log(book["topic"])   
book.author = "Ben Harki";
console.log(book);         
// -----
// empty object
let empty = {};
// ------
// use ? to conditionally access properties
let maybe;
console.log(maybe?.something);   // undefined

// ARRAYS 
// arrays are untyped in that they can have elements of any type
//   and different elements can be of different types
// arrays are dynamic, and can grow or shrink as needed
// arrays can also be sparse
// indexing, assignment, length property, push() 
// TODO: use ... spread operator to place in elements of another array 
let arr = [1.1, 2.2, 3.3, 4.4];   // array literal
let weird = ['a', 1, {'age':1}];   // different types, w/an object
arr.push(5.5);
console.log(arr.length)
console.log(arr[0]);
// -----
// assign to an element by assignment
arr[1] = 5.5;
// -----
// can add a new element by assignment
arr[5] = 6.6;
console.log(arr);
// -----
// sparse array where the missing elements are undefined
let spars = [1,,,4]; 
// of size 2, since there is an optional trailing 
let undefs = [,,];   
// ----- 
let emptyarr = [];

// MULTIDIMENSIONAL ARRAYS
// using an initializer expression
let twodarray = [[1.1, 2.2], [3.3, 4.4]];
// -----
// used in Apps Scripts for Google Sheets
// C way of creating 2d arrays, by arrays of arrays and a double for loop
// reads vals as a 2d grid, double them, return the vals into a new array
// Array() creates arrays with a fixed size
//   values are of undefined, and no indexing is possible
function MYDOUBLEARR(vals) {
  let cols = vals[0].length;
  let rows = vals.length;
  let doublearr = new Array(rows);   // create an array of arrays
  for (i = 0; i < rows; i++) {
    doublearr[i] = new Array(cols);   // sets them as undefined values
  }
  for (i = 0; i < rows; i++) {  
    for (j = 0; j < cols; j++) {
      doublearr[i][j] = 2 * vals[i][j];
    }
  }
  return doublearr;
}

// EXPRESSIONS AND STATEMENTS
// expressions can be evaluated to produce a value
//   they do not alter program state
// statements end in ; and alter the state
// arithmetic, concat, propertie expressions
obj1 = {x:1};
obj1.x + 3;
"H" + "arki"; 
// -----
// you can usually omit semicolons between two statements
//   if they are on seperate lines
let aval = 6
let aval2 = 7
console.log(aval, aval2)
// -----
// omiting ; can potentially cause problems with [], (), /
//   +, - and in general
// treats linebreaks as ; only when it can't parse code
//   unless one is added implicitly
// also when the next nonspace char cannot be be interpreted
//   as the continuation of the current statement
// abad could be a new name for f, but its interpreted
//   as f("concat").length
// return throw, yield, break, continue always treat 
//   next line as a ; 
let f = x => x + x;
let abad = f     
("concat").length
console.log("length of concat:" + abad) // 12, but could be 6
// -----
// TODO: ++ and -- postfix and => have exceptions when using 
//   them and omitting the ; (see page 69)


// EQUALITY
// === and !== checks if their values are equal
let xval = 1, yval = 3;
console.log(xval === yval);   // false
console.log(xval !== yval);   // true

// FUNCTION
// functions can be created on the fly
// arrow functions are lambda functions
console.log(firstfunc(3.14));
let myfunc = function(x) {return x*x;}
console.log(myfunc(2));
let func2 = x => x - 10;
console.log(func2(3)); 
// -----
// with const, and a param list in ()
const cfunc = (x,y) => x + y;
// -----
// traditional function
function firstfunc(param) {
  return param;
}
// -----
// "this" can be used to create a method on the fly
let name = {x:10};
name.divfunc = function(x) {return this.x / x;};
console.log(name.divfunc(2));
// -----
// another example of adding a method to an object
// in this case its an array object
let points = [{x:0, y:0}, {x:1, y:1}];  // an array of objects
points.dist = function() {
  let p1 = this[0];   // this is the points obj, its first element
  let p2 = this[1];   
  let a = p2.x - p1.x;
  let b = p2.y - p1.y;
  return Math.sqrt(a*a + b*b);
}
console.log(`distance is ${points.dist()}`);

// FUNCTIONAL PROGRAMMING
// uses arrow functions, but can also use the function keyword version
// TODO: examples with find(), findIndex(), every(), some(), reduce(), reduceright(), flat(), flatmap(), concat()
let arr1 = [[0, 1, 2], [3, 4, 5], [6, 7, 8]];
arr1.forEach(val => {console.log(val);})
arr1.forEach(
  row => row.forEach(
    col => console.log(col)));
// -----
// map() returns a new array
// TODO: filter() returns a sub-array()
let arr2 = 
  arr1.map(
    row => row.map(
      col => 2 * col));
console.log(arr2);

// CONTROL
// IF
let x1 = 2;
if (x1 % 2 == 0) {
  console.log("It is even");
}
else {
  console.log("It is not even");
}
// TODO: if(){} else if(){} else{} case

// LOOPS
// like a for each loop
let larr = [1, 2, 3, 4, 5];
let sum = 0;
for (let val of larr) {
  sum += val;
}
console.log(sum);
// -----
// for with indices
// mutable
for (i=0; i < arr2.length; i++) {
  larr[i] += 10;
}
console.log(larr);
// -----
// while() {}
// SEE FUNCTIONAL PROGRAMMING for foreach()

// CLASS
// create a class
// constructor() is the constructor
// no return is necessary in the constructor
class Point {
  constructor(x, y) {
    this.x = x;
    this.y = y;
  }
  mysum() {
    return this.x + this.y; 
  }
}
// ------
// construct an object using new, calling constructor
let p = new Point(3, 4);
console.log(p);
console.log(p.mysum());
// ------
// you can define a standalone class in this file, see below
let myint = new MyInt(10);
console.log(myint);

}   // end of Main() function

// standalone class
class MyInt {
  constructor(i) {
    this.i = i;
  }
}

// EXPORT AND IMPORT
// Node.js defines a global exports object that is used to 
//   export classes, functions, properties, etc to another file
// This is not useable in AppsScript Workspace, so it needs commented there
// These need enabled to use to import to another file using Node.js:
exports.Main = Main;
exports.MyInt = MyInt;
// -----
// to import this file in Node.js use require()
// this is code in test.js, that imports this file
// const master = require('./master.js')
// master.Main()



/*
From the textbook Javascript: The Definitive Guide
SKIPPED
  1.4 Example: Character Frequencey Histograms
  2.5.2 Unicode Normalization
    problems when using weird unicode as var names
  3.2.3 Arithmetic in Javascipt
    Math object/module
    has Infinity and -Infinity and NaN and -0
  3.2.4 Binary Floating-Point and Rounding Errors
    issues with binary repr of floating point numbers
  3.2.5 Arbitrary Precision Integers with Big Int
    123000000000n  
  3.2.6 Dates and Times
    Date class with timestamp
STOPPED AT 3.3 Text
*/






