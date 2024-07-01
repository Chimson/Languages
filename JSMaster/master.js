// execution starting point
function Main() {

// OPERATORS
// Operators: %, +, -, *, **, /, ++, --, +=, ...
// Boolean Operators: ===, !==, ==, !=, <, <=, >, >=, &&, ||, !
// Keyword Operators: delete, typeof, void, instanceof, in
//   ??, ?:
// Bitwise Operators: ~, &, ^, |, <<, >>, >>>, &=, ...
// ----
// in checks if properties exist, or if its an index of a defined element in an array
let sobj = {x:1};
console.log('x' in sobj);  // true
// -----
// instanceof is more particular
// objects need to be checked against classes with constructor
// typeof returns the name of the class as a string
let n = new Number(1);
console.log(n instanceof Number);  // true, since it was created with a constructor
nn = 1;
console.log(nn instanceof Number);  // false, no idea why
console.log(typeof 1 == 'number');  // true
// -----
// ?? evaluates to the first defined variable's value
defx = 10;
undefx = 0;   // converts to boolean false in ||, but defined as 0 in ??
console.log(undefx ?? defx);  // 0
console.log(undefx || defx);  // 10 
// -----
// comma operator creates expressions
// left operand value is discarded and right
//   operand value is returned
// multiple assignment that returns 3
//   generally should use let, var, or const for declaration
//   see VAR
ival=1, jval=2, kval=3;    // returns 3

// TYPES
// primitive types are immutable
// Number, String, Boolean are primitive
// undefined and null are primitive
// Symbol is a primitive type
// undefined and null do not have their own methods
//   but the other primitive types do
// typeof() returns the type
console.log(typeof(null));   // object
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
// -----
// Booleans
// these values convert to false:
// undefined, null, 0, -0, NaN, ""
// all other values convert to true 
true.toString();   // to explicitly convert to a string
// -----
// null is a language keyword
// null is the absense of an object, type(null) == 'object'
// null can be used to indicate that there is no number or other primitive
// -----
// undefined is the value of variables that have not been initialized
// also indicates the value of some method or property that does not exist
// undefined is returned when a function as no explicit return value
// undefined is a predefined global object, who is the sole member of the undefined class
let undef;
console.log("undef = " + undef);
// -----
// null and undefined have no methods or properties, and when trying to invoke 
//   any raise a TypeError
// -----
// Number's toString() be given a value to display a different base
console.log(Number(127).toString(16));   // to hexadecimal 7f
// -----
// Number also has toFixed(), toExponential(), toPrecision methods
//   to control float formatting
// Also has parseInt() and parseFloat() that both take strings
//   and try to convert to a number 
// -----
// grab a value from a different module/object
let pi = Math.PI;
// -----
// global object in Node.js contains globally defined identifiers available
//   to a JS program
console.log(globalThis);
// -----
// falsy values that will convert to false implicitly
null, undefined, false, 0, -0,'', NaN


// LET and CONST
// block scoped, so only visible in the block of code that 
//   they are declared in
// variables are declared with let and assigned with =
// immutable variables are named with const
// const requires initialization, let can be declared 
// when a declaration is made outside of all blocks in a file then
//   it is considered a global variable, whose scope is the file
//   it is declared in
// if it is in a <script> in HTML then it is visible in all scripts
//   in the HTML file
let x;   // declared but assigned undefined by default
let y = 10;
const x2 = 44; 
let tbool = true;
let uval = undefined;
// -----
// you cannot use the same var name with more than one let or const
//   declaration in the same scope
// you can in a nested scope, like in an if or loop, or in other braces
let x4 = 100; {
  let x4 = 101;
}
// -----
// let variables are visible in further nested scopes,
// let variable does not affect the same variable in its parent's scope
// this is the same with var actually
function f1() {
  let nval1 = "Ben";
  let nval2 = "Mags";
  function f2() {
    let nval2 = "Finn";  
    console.log(nval1);  // Ben 
    console.log(nval2);  // Finn
  }  
  f2();
  console.log(nval2);   // Mags
}
// console.log(nval1); // not visible
f1();
// -----
// an attempt to hoist like var, but it throws exception
function nohoist() {
  // console.log(hval);    // uncomment for hoist attempt, but ReferenceError
  let hval = 100;   // replace with var and hval above is hoisted
  console.log(hval);   // 100
}
nohoist();


// VAR
// you can have multiple declarations of same var names in the same scope, unlike let
var wvar;
var wvar;
let wvar2;
// let wvar2;    // throws a SyntaxError
// -----
// var declared in other scopes than functions
//   will make the variable visible in containing scopes
// this is not true for let
let arr3 = [0, 1, 2, 3];
for (var val of arr3) {
  val = 10;
}
console.log(val);
// -----
// var outside of functions are global
// they are implemented as properties to the globalThis object
//   this is different from let and const
// If I try to read it with console.log() it doesn't print it
//   since this is defined inside Main
// In the node repl it does
var globv = "global";
console.log(Object.hasOwn(globalThis, globv));  // true
// -----
// var variables are "hoisted" up to top of current enclosing function
//   they may be seen before defined, if initialization is deep in the function stack
// var is given an undefined value, until initialized
// hoisting can also occur in deeper nested non-function scopes
function hoistdemo() {
  console.log(hval);    // undefined, but visible bc of hoisting
  var hval = 100;
  console.log(hval);   // 100
}
console.log(hval);  // undefined, since hval is hoisted in below line
var hval;    // if this line is not included the above line throws a ReferencerError
hoistdemo();
console.log(hval);  // still undefined, even though assignment in hoistdemo()
// -----
// variables declared without let, const, or var
//   are global variables, even if defined in nested scopes/functions
// bad idea in general, should use let, const, or var
x = 3;
console.log(globalThis);  // this does actually work unlike above, even in Main() function

// DESTRUCTURING ASSIGNMENT
// values from within an array or other iterable object (like a string) 
//   from the right are extracted to variables on the left
// you can have extra vars on the left or values on the right
// can use them to assign via an expression
// can be used to easily return arrays from functions
// Object.entries() returns an array of [key, value] property arrays
// can be used in variable declarations in for loops
// works with nested arrays and nested objects
let [ax, ay, az] = [2, 4, 6];
[ax, ay, az] = [ax + 1, az, ay];
console.log(ax, ay, az);   // 3, 6, 4
let obj2 = {x:1, y:2};
console.log(Object.entries(obj2));   
let [ox, oy] = Object.entries(obj2);   // extraction from an obj
console.log(ox, oy);
// -----
// ... will collect the remaining values into the variable
let [frst, ...rem] = [0, 1, 2, 3, 4, 5];
console.log(frst, rem);  // 0 [1, 2, 3, 4, 5]
// -----
// extract straight out of an object
let {xob, yob} = {x:1, y:2};
// -----
// you can use destructuring to make it easier to use members
//   from another namespace
// any variable from the left that does not exist in the module
//   is assigned undefined
// can use : to temporarily rename a member in a module
const {sin, cos, tan: tangent} = Math;    
console.log(sin(3.14));   // close to 0
console.log(tangent(3.14));  // close to 0

// STRING
// immutable sequences of Unicode 16-bit chars
// can use "", or '' for strings
// they are iterable by character, use 0-indexing
// no char type, just a string of size one
// can use \n for next line, where \ is an escape char
let str1 = "string";
let str2 = 'str';
let str3len = str1.length;
// -----
// here is a formatted string using `` and ${}
// these are called template literals
// anything inside ${} is a JS expression
// adds new lines and you can use escape sequences
let int1 = 300;
let str3 = `this is ${int1}`;
let smath = `here is some math: ${200 % 2 == 0}`;
console.log(smath);
let str5 = `this prints
as it 
looks`;
console.log(str5);
// -----
// You can use any Unicode character
// can also use them variable names
// two versions, one with \uXXXX and one with \u{XXXXXX}
// {} version is expanded to codepoints >16 bits (emoji's for ex) 
let uni1 = "\u00E9";
let uni2 = "\u{1F600}";
console.log(uni1 + ' ' + uni2);
// -----
// long strings written across multiple lines
let str4 = 'this is\
displayed\
on one line';
// -----
// escape sequences
'\n\b\t\v\f\r\'';
'\uAABB'  // 16-bit unicode
'\xAF'   // 8-bit unicode
// -----
// concat with +
let cc = "ben" + "Harki";
// -----
// other operators: <, >, <=, >=, ===, !==
// methods: .slice(), .split(), .substring(), etc.
// strings are immutable so the methods return new strings
let ben = "Ben";
ben.slice(0,1);
// -----
// can use [] to read a char, like arrays
let mags = "Magdalene";
console.log(mags[3]);
// -----
// see tagged template literals using tag functions in FUNCTION


// OBJECTS
// objects are of type Object and are unordered collections of 
//   properties
// properties have a name and value (value can be primitive)
//    or another object
// create an object on the fly and add properties on the fly
// objects are name value pairs, can access with . or like a dictionary with []
// all objects have a default print string
// initialize using initializer expression
// Object literals can be nested
let book = {topic: "Javascript", edition: 7};   // Object literal/initializer
book.author = "Ben Harki";
console.log(book.topic);
console.log(book);
book.author = "XXX";   // objects are mutable;
console.log(book);
// ------
// can use [expression] to read/write properties
let finn = {};
finn['name'] = "Finn";
console.log(finn.name);   // still can use .
console.log(finn['name']);
console.log(finn);     
// -----
// empty object
let empty = {};
// ------
// null and undefined do not have properties so if they
//   are attempted access then a TypeError is thrown
// you can use ? or ?. to avoid the error
// if the value exists for the property, then it is returned
// optional chaining can short circuit execution, avoiding an error
//   when a property does not exist, and ? returns undefined,
//   then any other properties are skipped and undefined is returned withour error
let maybe = {x: null};
console.log(maybe.x);   // null
// console.log(maybe.x.val);  // throws a TypeError 
console.log(maybe.x?.val);  // no error, but returns undefined
console.log(maybe['y']);  // undefined
// console.log(maybe['y']['z']);  // TypeError
console.log(maybe['y']?.['z']);  // undefined
console.log(maybe.x?.y.z.q.e);   // optional chaining
// -----
// Symbol is used to also define private properties for an object
// can only access the property with [], not a dot 
// Symbol() returns a unique Symbol value, to avoid property conflicts
let person = {};
let fname = Symbol("Private fname");
person[fname] = "Ben";   // assign a value
console.log(person[fname]); 
console.log(person[Symbol("Private fname")]);  // undefined, since its unique from fname 
// -----
// Symbol.for is used for public properties
// always returns the same value, based on the key
let ben2 = {};
let fname2 = Symbol.for("fname");
ben2[fname2] = "Ben";
console.log(ben2[fname2]);
console.log(ben2[Symbol.for("fname")]);  // Ben, since it is public

// ARRAYS 
// arrays are untyped in that they can have elements of any type
//   and different elements can be of different types
// arrays are dynamic, and can grow or shrink as needed
// arrays can also be sparse
// indexing, assignment, length property, push() 
// TODO: use ... spread operator to place in elements of another array 
let arr = [1.1, 2.2, 3.3, 4.4];   // array literal (aka array initializer)
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
// empty array 
let emptyarr = [];
// -----
// use Array.from() to deep copy arrays
let ar = [0, 1, 2, 3, 4, 5];
let arcopy = Array.from(ar);
console.log(ar === arcopy);   // false, since they are seperate objs

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
// arithmetic, concat, property expressions
// any literal is a primary expression 
// JS keywords that are primary exp: true, false, null, this
"H" + "arki"; 
/regex/;   // regular expression encloded in / /
// -----
// expression involving an object
obj1 = {x:1};
obj1.x + 3;
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
// -----
// label statements can be used in statements
//   that have bodies, like loops or conditionals
// break and continue are the only JS statements
//   that use statement labels
// statement labels are only used within the statement
//   they are defined
// labeled statements may themselves be labeled
// they have their own rules for namespace, but basically
//   can conflict in names, unless neither is nested in the other
// labeled breaks are useful when you want to escape an entire statement
//   that contains more than one loop and not just the current loop
// labeled breaks do not travel across function boundaries
let ix = 0;
ploop : while(++ix < 10) {
  if (10 % ix == 3) {  
    console.log(ix);    // 7
    break ploop;
  }
  else {
    continue ploop;
  }
}

// EQUALITY AND CONVERSION
// === is strict equality
// === and !== checks if their values are equal or not-equal
let xval = 1, yval = 3;
console.log(xval === yval);   // false
console.log(xval !== yval);   // true
// -----
// == considers null and undefined the same, while === says they are different
// -----
// objects are reference types, so under === their 
// references are compared not the values of their properties
let o1 = {x:1, y:0};
let o2 = {x:1, y:0};
console.log(o1 === o2);  // false
o2 = o1;
console.log(o1 == o2); // true
// -----
// == returns true if one can can be converted to the other
//   and they are the same value
// the only exception is the implicit conversion to booleans
//   of all objects
console.log(0 == "0");   // true
console.log(undefined == false);   // false even though this conversion does happen implicitly in if()
// -----
// all types will try to convert to another
let val2 = 10 + "11 + 12";
console.log(typeof(val2));    // string
// -----
// explicit conversion of primitive types using Type function
// do not use "new" like a constructor, this is a wrapper type
//   leftover from old JS
let pi2 = Number("3.14");
console.log(typeof(pi2));   // number
// -----
// operators will perform implicit type conversions
console.log(typeof(100 + ""));   // string
console.log(typeof(+"100"));  // number 

// FUNCTION
// functions can be created on the fly
// arrow functions are lambda functions
// return will return the evaluation of a given expression
// without a return value a function will return undefined
console.log(firstfunc(3.14));
let myfunc = function(x) {return x*x;}
console.log(myfunc(2));
let func2 = x => x - 10;
console.log(func2(3)); 
// -----
// with const, and a param list in ()
const cfunc = (x,y) => x + y;
// -----
// traditional function, can be thought of as an expression
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
// -----
// you can pass template literals into tag functions by using
//   functions names as a prefix to the `` string
// these are called tagged template literals
// this is when a function expression is followed by a template literal, and then 
//   function is invoked
// first arg is an array of substrings of the template literal substrings around each ${}
// other args (which are not necessary) can be of any type, 
//   and are the ${} interpolated values  
// can return any type, so you can use strings to parse and return any data or object
function MultStr(arrstrs, val1, val2) {
  return `${val1} ${arrstrs[1][1]} ${val2} = ${val1 * val2}`; 
}
console.log(MultStr`${3} x ${4}`);
// -----
// conditionally invoke a function or method using ?.()
// when the function variable name is null or undefined
// can still throw a type error if the var is defined, but not a function
// also short-circuiting so any expression arg would not compute
//   see OBJECT
let nofunc = undefined;
// nofunc();   // Throws a TypeError
nofunc?.();   // no exception and evals to undefined
// -----
// TODO: see yield to create generator functions


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
// can take expressions that eval to something that can be implicitly converted to a boolean
// should use {} to enclose body since else will always 
//   be attached to the nearest if
// don't forget about the difference between ==, != and ===, !== 
//   see EQUALITY
let x1 = 2;
if (x1 % 2 === 0) {
  console.log("It is even");
}
else {
  console.log("It is not even");
}
// -----
// if if is given a "falsy value", or an expression that evals
//   to one, then execution proceeds to the false branch
// see Types for "falsy values" 
// literally has to be defined undefined (declared) for next to work
if (0) {;} else {console.log("false branch");}
let undef2;   // without this line a ReferenceError is thrown
if (undef2) {;} else {undef2 = "now its defined";}
console.log(undef2);
// -----
// simple if, else if
let i = 2;
if(i===0){;} else if(i===1) {;} else{console.log("you found it");} 
// -----
// switch is a better version of if, else if
// It will not revaluate the condition expression in each case like if
// the condition and the cases can be described by expressions
// comparison of their evaluation uses ===
// default is optional, if not there and other cases do not match
//   then nothing happens
// without break, execution can fall through the cases, when
//   the expression evals to the same value
let nval3 = 12;
switch(nval3 % 2) {   // this evals to 0
  case nval3 % 4:
    console.log(`${nval3} is divisible by 4`); 
  case nval3 % 6:
    console.log(`${nval3} is divisible by 6`);
    break;
  default:
    console.log(`${nval3} is not divisible by them`);
    break;
} 

// LOOPS
// like a for each loop
// for of itertates over an iterable object
// can also use const, where the local variable cannot change 
//    within an iteration
// for's initialize, test, increment can all be expressions 
// can also use the empty statement ;, for example for(;;) is an infinite loop
// break exits the loop and continue skips the next iteration
let larr = [1, 2, 3, 4, 5];
let sum = 0;
for (let val of larr) {
  sum += val;
}
sum = 0;
for (const val of larr) {
  sum += val;
}
console.log(sum);
// -----
// for of loops also work with Object.keys(obj)
//    Object.values(obj) and Object.entries(obj), all return arrays
// [key, val] is destructuring, not an array, even though
//    Object.entries returns an array of [key, val] arrays
//    see DESTRUCTURING ASSIGNMENT
let forobj = {x:1, y:2, z:3};
for (let [key, val] of Object.entries(forobj)) {
  console.log(`[${key}, ${val}]`);
}
// ----
// TODO: Map and Set have iterators
//   Map iterator returns a key value pair, like Object.entries() for loop example
// -----
// for in loops can be used to read/write properites in an object
// does not accept . notation to read properties
// will also skip private Symbols
// there are other properties that are not enumerable with a for
//   in, like toString, but those you create are enumerable by default
// if fobj is undefined the loop is not executed
let fobj = {x:0, y:undefined, z:2};
priv = Symbol('private');
fobj[priv] = 3;
for (let prop in fobj) {
  // prop = 'XXX'; fobj[prop] = 'nothing yet';  // writes to the props
  console.log(`${prop}: ${fobj[prop]}`);
}
// -----
// for with indices
// mutable
for (i=0; i < arr2.length; i++) {
  larr[i] += 10;
}
console.log(larr);
// -----
// common use of comma expression in a for loop
for(let i=0,j=10; i < j; i++,j--) {
    console.log(i+j);
}
// -----
// for with an empty statement
for (let i = 0; i < 3; console.log(i), ++i) ;
// -----
// for loops can accept expressions that eval to something suitable for the 
//   the local variable
// copies the property names of the obj to the array
let o = {x:1, y:2, z:3};
let a = [];
let k = 0;
for (a[k++] in o);
console.log(a);   // [x, y, z];
// -----
// for in loops applied to arrays with assign
//   the indices to the local variable
for (i in [10, 20, 30]) {  
  console.log(i);   // 0, 1, 2
} 
// -----
// while condition can be an expression that evals
//   to a boolean, or can be implicitly converted to one 
// comma expressions return the right operand 
//   so when it is flipped, it is an infinite loop
let count = -1;
while (++count, count < 10) {
  console.log(count);
}
// -----
// do while will guarantee the body executes
//   at least once
// checks the expression at the end of each iteration
let count2 = 0;
do {
  console.log(++count2);   
}
while(count2 < 1);
// -----
// SEE FUNCTIONAL PROGRAMMING for foreach()
// TODO: for has an "await" of version for asynchronous
//   iterators, see page 220 

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

// EXCEPTIONS
// throw can accept a value of any type like a string or a number
// throw can also except an expression that evals to a type
// throw "an issue";
// -----
// using the Error class
throw Error("an error has occurred")
// -----
// try-catch-finally
// when code throws an error in a try block
//    it is handled in the catch block
// finally block executes regardless if a an error is present

}   // end of Main() function

// Test a standalone class
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
  3.3.5 Pattern Matching
    strings have methods that accept RegExp string args 
  3.9.3 Object to Primitive Conversions
    includes how to convert from objects to primitives
  4.10 Logical Expressions
    all the rules for when ||, &&, handle "truthy" or "falsy" values
  4.11 Assignment Expressions
    +=, etc,
  4.12 Evaluation Expressions
    eval("") like in Python, but could be a security issue
  4.13 Miscellaneous Operators
    typeof, delete, await, void, comma
STOPPED AT 5.5.6 throw
*/





