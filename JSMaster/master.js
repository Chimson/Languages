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
//   will return true, even if the property is set to undefined
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
// there is really no reason to use var anymore, since let is available
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
// console.log() with a template string will by default use toString() given an object
//   this defaults to [object Object]
// you can use JSON.stringify() for the pretty printing version
//   prints a string that looks like an obj literal
let sobj1 = {'x':1, 'y':2};
console.log(sobj1);   //  { x: 1, y: 2 }
console.log(`${sobj1}`);   // [object Object]
console.log(JSON.stringify(sobj1));  //  {"x":1,"y":2}
// -----
// see tagged template literals using tag functions in FUNCTION



// OBJECTS
// mutable
// objects are of type Object and are unordered collections of 
//   properties
// properties have a name (as a string) and value (value can be primitive)
//    or another object, or some expression that evals to either
//    each value to a propeties is evaled each time an object literal is evaled
// objects are name value pairs, can access with . or like a dictionary with []
//    [] makes objects like an associative array (hash, map or dictionary) 
// all objects have a default print string
// all objects inherit the prototype object, Object.prototype
//   non-inherited properties are called "own properties"
// Objects created with "new" and {} also inherit its specific
//    classe's prototype property, seperate from Object.prototype
//    this system is called the prototype chain
// all own properties have have these attributes: 
//   writable (set the value of the propety), enumerable (returned by a for-in loop), 
//   configurable (whether the property can be deleted and its attributes altered)
// some built in object's properties may not have some of these attributes disabled
// no object can have two properties of the same name
//   functions and attrs cannot have the same name, since they are both propeties
// -----
// Objects are mutable and can be modfied through their reference
// defined using the string key, access using the .
// object referenced by obj is modified through xobj reference
let obj = {"x":0, "y":1};
let xobj = obj;   // x is a ref to the same object obj refers to
xobj.x = 10; 
console.log(obj); // {x:10, y:1}  
// -----
// initialize using initializer expression, like an object literal
// Object literals can be nested
// create an object on the fly and add properties on the fly (loose typing)
// lhs can be an expression who evals to an aboj reference
let book = {topic: "Javascript", edition: 7};   // Object literal/initializer
book.author = "Ben Harki";
console.log(book.topic);
console.log(book);
book.author = "XXX";   // objects are mutable;
console.log(book);
console.log(book.nope);   // undefined
// ------
// can use [expression] to read/write properties
//   expression in brackets must eval to a string or a Symbol ref
// allows for dynamic creation of objects
// lhs can be an expression who evals to an obj referencex
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
// -----
// Object Inheritance
// Object.create() allows you to create a new object
//   from another class prototype (like using "new") or object (unlike "new")
// the resulting object inherits from the object or prototype
let unitcircle = {r: 1}; 
let c = Object.create(unitcircle);
c.x = 1; c.y = 1; 
console.log(`c.r = ${c.r}`);  // 1
c.r = 2;  // overrides the inherited propertie, unitcircle is unchanged
console.log(`c.r = ${c.r}`);  // 2
// -----
// JSON, JavaScriptObjectNotation is built in to the language
// JSON.stringify() takes an object and returns its JSON string 
//   only serializes "own properties"
// JSON.parse() takes a string and returns the object
let jobj = {'a':0, 'b':1, 'person':{'first': 'Ben', 'last': 'Harki'}};
console.log(typeof(jobj));   // object (from a literal)
let strobj = JSON.stringify(jobj);
console.log(typeof(strobj));  // string
let jobj2 = JSON.parse(strobj);
console.log(typeof(jobj2));   // object
// -----
// toString() returns '[object Object]' by default
// quick way to override toString()
let obj4 = {'x': 0};
console.log(obj4.toString());  // [object Object]
let obj3 = {'x': 0, toString: function() {return `x: ${this.x}`}};  // returns overide
console.log(obj3);
// -----
// can override toString() automatically with JSON
// can override toJSON(), that is called by JSON.stringify()
// using the obj in a template string will return toString()
//   now it replaces [object Object] with its JSON
let jobj3 = {'a':0, 'b':1, 'person':{'first': 'Ben', 'last': 'Harki'}};
jobj3.toJSON = function() {return `a: ${this.a}, b: ${this.b}, person: ${this.person.last}`}; 
jobj3.toString = function() {return JSON.stringify(jobj3)};   // or toJSON()
console.log(`${jobj3}`);
// -----
// define a method quickly without the function keyword
let nofuncc = {
  'a': 0, 
  'b':1,
  mymeth() {return "hi";}
};
console.log(nofuncc.mymeth());
// -----
// you can define get and set methods for a property 
//   in an object, called accessor methods, which can be inherited
// get methods are called when you want to read the property
// set methods are called to write to the property
// you can write them with or without a backing internal
//   data property
// backing data property could be public or private
//   _ is a hint that the property is private, but it is not enforced
// can choose to only read or write by removing one of them
let accobj = {
  xint: 0,   // like public, read/wrrie
  get x() {return this.xint;},
  set x(val) {this.xint = val;},
  _ypriv: 1,
  get y() {return this._ypriv;},
  set y(val) {this._ypriv = val;}
};
accobj.x = 10;
console.log(accobj.x);
console.log(accobj.xint);   // public, but should be accessed through x
accobj.y = 20;
console.log(accobj.y);
console.log(accobj._ypriv); // still can see it
// -----
// objects can be created with "new" and its class constructor, see class
// delete operator removes properties from an object
// hasOwnProperty() method can determine if a property
//   is an "own property" or something inherited from a prototype
// propertyIsEnumerable(), checks if it is an own property and is enumerable
// you can use Symbols as method names, but need to call it using the 
//   property array notation

// ARRAYS 
// arrays are untyped in that they can have elements of any type
//   and different elements can be of different types
// arrays are dynamic, and can grow or shrink as needed
// arrays can also be sparse
// indexing, assignment, length property, push() 
// can use an expression to define a value in an array
//   expression can eval to a string index value
// TODO: use ... spread operator to place in elements of another array 
// can create arrays with Array constructor
let arr = [1.1, 2.2, 3.3, 4.4];   // array literal (aka array initializer)
let weird = ['a', 1, {'age':1}];   // different types, w/an object
arr.push(5.5);
console.log(arr.length);
console.log(arr[0]);
// -----
// you can create an array with Array constructor 
// can also use Array.of() to ensure that the arg/args
//   are elements you want to place in an Array
let arrc0 = new Array(10);   // Array of Length 10, of undefined
let arrc1 = new Array(0, 1, 2);  // [0, 1, 2]
let arrc2 = Array.of(1);  // [1]
let arrc3 = Array.of(0, 1, 2) // [0, 1, 2]
console.log(arrc0, arrc1, arrc2, arrc3);
console.log(arrc0[0]);
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
// can also give Array.from() some iterable
// can also give Array.from() a function, that is applied to each element
//   as the array is being created, like map()
let ar = [0, 1, 2, 3, 4, 5];
let arcopy = Array.from(ar);
console.log(ar === arcopy);   // false, since they are seperate objs
let arc = [0, 1, 2, 3];
let ar2 = Array.from(arc, (x) => x**2);
console.log(ar2);  // [0, 1, 4, 9]
// -----
// arrays are like objects in that you can add properties
// any property that is named by a non-neg integer is 
//   an index
let warr = [0];
warr['prop'] = '2';
console.log(warr);  // [0, prop: '2']
console.log(warr.length);  // 1, since there is only one element tied to an index
warr[-2] = 10;  // creates '-2' as a property
warr['3'] = 14;  // sets the 4th element to 14, with unset assigned undefined
console.log(warr);  

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
// -----
// function declarations are hoisted in that they are visible
//   at the top of the scope in which they are defined in, 
//   even before they are called
// -----
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
//   they can be their "own" or inherited properties
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
// throw "an issue";   // throwing a string message
// -----
// using the Error class
// throw Error("an error has occurred")
// -----
// try-catch-finally
// can use a try-finally without a catch
// when code throws an error in a try block
//    it is handled in the catch block
// catch can accept an argument, but can be called without it
// finally block executes regardless if a an error is present in the try
//    used to clean up anything when an error triggers in the try block
//    will also execute just before a jump from a return, break, etc. in try 
let den = 0;
let num = 100;
let result = undefined;
try {
  if (den === 0) {
    throw new Error("You divided by 0!");
  }
  result = num/den;
}
catch(e) {
  console.log(e);   // print the error
}
finally {
  result = 0;
  console.log(result);
}


}   // end of Main() function

// Test a standalone class
class MyInt {
  constructor(i) {
    this.i = i;
  }
}

// EXPORT, IMPORT, MODULE
// a module is a JS file with its own global namespace
//   independent of other modules
// Node.js defines a global exports object that is used to 
//   export classes, functions, properties, etc to another file
// This is not useable in AppsScript Workspace, so it needs commented there
// These need enabled to use to import to another file using Node.js:
exports.Main = Main;
exports.MyInt = MyInt;
// -----
// to import this file in Node.js you can use require()
// this is code in some other file (runmaster.js), that imports this file master.js
// const master = require('./master.js')
// master.Main()
// -----


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
  5.6.1 with
    with is depreciated, but it allows you to create variables from
      properties of an object
  5.6.2 debugger
    debugger keyword is available when running a debugger
  5.6.3 use strict
    forces a js script function or file to run in strict mode
    strict mode restricts the usage of JS language in specific ways
  5.7.4 import and export
    I couldn't get these keywords to work in Node.js, but I used
      the exports global object
  6.4 Deleting Properties
    the delete operator removes own properties, does not destroy the value
  6.6 Enumerating Properties
    difference between properties that are enumerable and when own or
    inherited enumerable properties are returned from for-in loop
  6.6.1 Property Inheritance Order
    order at which they iterate through in for-in or JSON.stringify
  6.7 Extending Objects
    Object.assign() allows the copying of one object's properties to 
      another
  6.9.2 The toLocaleString() Method
    returns a class specific toString() method
  6.9.3 The valueOf() Method
    object.valueOf() returns the primitive value conversion (other than
      a string) of the object, can be overridden
  6.10 Extended Object Literal Syntax
    I did get some of this, like the get and set properties of object
    simple way to add properties, saved to variables to objects (shorthand properties)
    can use [expression], to define a property in an object, where expression
      can dynamically return a string to set the prop name
    can also use symbols, saved to a ref, as properties and the [symbolref]
      syntax
    spread operator ... in an object literal to spread an object's properties
      in the creation of another object
  7.1.2 Array Spread Operator
    place elements from one array into another using ..., creates shallow copy
    can apply ... to any iterable object, like a string
STOPPED AT 7.3 Sparse Arrays

*/





