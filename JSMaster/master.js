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
//   technically it checks whether the lhs obj's prototype is set to some prototype obj
//   which is what a constuctor function (with or without the "constructor" keyword) does implicitly 
// TODO: obj.isPrototypeof(r) can be used when obj is set as a prototype obj for r, especially when
//   r was created by a non-constructor function
// typeof returns the name of the class as a string
let n = new Number(1);
console.log(n instanceof Number);  // true, since it was created with a constructor
nn = 1;
console.log(nn instanceof Number);  // false, no idea why
console.log(typeof 1 === 'number');  // true
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
let smath = `here is some math: ${200 % 2 === 0}`;
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
// console.log() with a template string will by default use toString() and give any object
//   this defaults to [object Object]
// you can use JSON.stringify() for the pretty printing version
//   prints a string that looks like an obj literal
let sobj1 = {'x':1, 'y':2};
console.log(sobj1);   //  { x: 1, y: 2 }
console.log(`${sobj1}`);   // [object Object]
console.log(JSON.stringify(sobj1));  //  {"x":1,"y":2}
// -----
// see tagged template literals using tag functions in FUNCTION
// strings are like read-only arrays, so you can give them to functions that take generic 
//   arrays using the function's .call() version

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
// lhs can be an expression who evals to an obj reference
let finn = {};
finn['name'] = "Finn";
console.log(finn.name);   // still can use .
console.log(finn['name']);
console.log(finn);   
// ------
// another example of defining dynamic properties
// properties can be data or methods
// computed property name on an object, using [expr]
// can dynamically name a property at runtime, evaluating the expression expr
// can also use symbols as properties
// see using a symbol as a property below
// also example of defining a computed property name with shorthand
//   needs a colon
let cprop = {};
function addone(str) {
  return `${str}_prop`;
}
cprop[addone('onehundred')] = 100;
console.log(cprop['onehundred_prop']); // allows any string, even non-normal property names
console.log(cprop.onehundred_prop);   // if the property name is like a normal property
let anothercprop = {
  [addone('two')] : 2
};
console.log(anothercprop.two_prop);
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
let fname = Symbol("Private fname");   // no need for "new"
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
// "this" keyword refers to the current object a method is called on
//   cannot assign to "this"
// toString() returns '[object Object]' by default
// quick way to override toString()
let obj4 = {'x': 0};
console.log(obj4.toString());  // [object Object]
let obj3 = {
  'x': 0, 
  toString: function() {return `x: ${this.x}`}};  // returns overide
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
  mymeth() {return "hi";}   // can use the function keyword, or an arrow function
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
// TODO: use ... spread operator to place in elements of another array or iterable like a string
// TODO: use the delete operator, to make an element of the array undefined
// TODO: use splice() to insert, delete, or replace elements, that changes the length
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
// in operator checks if the element is in the array
let arrc0 = new Array(10);   // Array of Length 10, of undefined
let arrc1 = new Array(0, 1, 2);  // [0, 1, 2]
let arrc2 = Array.of(1);  // [1]
let arrc3 = Array.of(0, 1, 2) // [0, 1, 2]
console.log(1 in arrc3);  // checks if the index is defined as something
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
// commas can make sparse arrays, of size 2, since there is an optional trailing 
// empty array 
// can add elements to the array at any index, the rest are undefined
let spars = [1,,,4]; 
let undefs = [,,];   
let emptyarr = [];
emptyarr[3] = 3;
console.log(emptyarr);
// -----
// length counts undefined elements
// length can be used to shrink or expand the array
// setting elements to undefined, does not change the length of the array
let arr4 = [0, 1, 2];
console.log(arr4.length);  // 3
arr4[2] = undefined;
console.log(arr4.length);   // still 3
arr4.length = 2;  // similar when the length is increased past 3
console.log(arr4, arr4.length);  // [0, 1] 2
arr4 = [,,,,,];
console.log(arr4, arr4.length);  // [<5 empty items>] 5
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
// -----
// ... applied to an iterable, like a string, unpacks each char into
//   as an element of the array
// entries() retrives a [key, value] array pair
let arr5 = [..."Ben-Harki"];
for (let [key, val] of arr5.entries()) {
  console.log(key, val);
}
// -----
// forEach() and for-of loops
// forEach() will not apply function on undefined, for-of loops will not
// forEach() will accept functions of three arguments if you need the index and the whole
//   array per element
let arrs = new Array(5);
for (let val of arrs) {
  console.log(val);  // all undefined
}
arrs.forEach(val => console.log(val));  // prints nothing
arrs = [..."987"];
arrs.forEach((val, ind, arr) => console.log(ind, val, arr));  // prints index, val, full array
// -----
// see LOOPS for iteration of an array by index, and passing functions with 2 or 3 args
// see FUNCTIONAL PROGRAMMING for more functions like forEach
// MULTIDIMENSIONAL ARRAYS
// using an initializer expression
let twodarray = [[1.1, 2.2], [3.3, 4.4]];
// -----
// length property and multi dim arrays
// you can have rows of different lengths;
let marr = [[0,1,2], [3,4,5]];
console.log(marr.length);  // 2, number of rows
console.log(marr[0].length);   // 3, number of cols (if all the rows are of the same length)
console.log(marr[1][2]);  // 5, marr[row, col]
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
// -----
// multidim array of rows of different sizes in a for of loop
// also an indexed loop
// may want to save the lengths in a local variable
//   so they do not need retrieved in each iteration
let mdarr = [[0, 1, 2], [3, 4]];
for (let row of mdarr) {
  for (let val of row) {
    console.log(val);
  }
}
for (let i = 0; i < mdarr.length; ++i) {   // for each row
  for (let j = 0; j < mdarr[i].length; ++j) {  // for val in the row (col val)
    console.log(mdarr[i][j]);
  }
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
  if (10 % ix === 3) {  
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
// function declarations are hoisted in that they are visible
//   at the top of the scope in which they are defined in, 
//   even before they are called
// functions can also be though of as an object on their own, can be invoked
//   through their name, can even be stored in an array and invoked
// functions can act like a namespace, where variables are defined
//   in the body are only visible in the function
// You can even use an anonymous function, if you don't want to define a global 
//   namespace, kind of like an "unamed" namespace, and can be immediately invoked on definition
// functions can be defined in any block, but are only visible in 
//   in that block
// -----
// functions can be created on the fly using function expressions
// can be assigned to a variable, using let, var, const
// arrow functions are lambda functions
// return will return the evaluation of a given expression
// without a return value a function will return undefined\
// can also give a function expression a name
// function expressions are not hoisted like function's defined with 
//   'function' keyword, and cannot be invoked until the expression is evaled
//   however you can use bind() method on a function object to hoist it
console.log(firstfunc(3.14));
let myfunc = function(x) {return x*x;}   
console.log(myfunc(2));
let func2 = x => x - 10;
console.log(func2(3)); 
let func3 = function fname(x) {return x**2;}  // given a name, but only defined in func3's scope
console.log(func3(2)); 
// -----
// long arrow function
// cannot seperate the param list from the body, since JS automatically places ; in new lines
// simple arrow function with const, and a param list in ()
//   can omit the () with only one param, but needs () with no params
// see their usage with map in FUNCTIONAL PROGRAMMING
// cannot be used as constructor functions
let cfunc0 = (x) => {return x;};   // with the {}, return, and inner ;
const cfunc = (x,y) => x + y;   // can omit these
// -----
// traditional function, can be thought of as an expression
function firstfunc(param) {
  return param;
}
// -----
// "this" can be used to create a method on the fly
// this is the object that the method is defined on
// this is not defined on functions that are not a property of an object
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
// functions can be passed as arguments, with arrow or keyword
// can define functions in other functions (nested)
function PrintOp(strval, Binop) {
  function RetNum(val) {return Number(val);}
  let nval = RetNum(strval);
  return console.log(Binop(nval));
}
PrintOp('3', function(x) {return x**2;});  // 9
// -----
// nested functions have access to variables/params in the scope they are defined in 
// this is called the closure of the function
function AFunc(x) {
  function BFunc() {
    console.log(x);
  }
  BFunc();
}
AFunc(1);
// -----
// define and invoke a function in one line
let eleven = (function() {return 10;}()) + 1;
console.log(eleven);
// -----
// can use ['method'] to invoke a method 
let objm = {'print': function(val) {console.log(val);}};
objm['print'](10);
// -----
// invoking a function on few args than params
//   defines the params as "undefined" or other default value
function more_params(x, y, z) {
  console.log(x, y, z);
  return x + y + z;
}
more_params(1);   // 1 undefined undefined
// -----
// you can default parameters to a function
// they can be given a value or an expression
// you can give a defaulted param a previously defined param (to its left)
// this one is defined and invoked in one line
let deffunc = function(x = 0, y = `x: ${x}`) {
  console.log(x, y);
}();
// -----
// you can use ...param in the parameter list to collect
//   an unknown number of args into an array
// rest parameters cannot be defaulted and is never set "undefined"
// rest parameter in the parameter list, spread operator in the call
// rest parameter collects the args into an array, processed by the function
//   spread operator spreads an iterable into the args on the function call
function frest(...rest) {
  for (let val of rest) {
    console.log(val);
  }
}
frest(1, 2, 3, 4, 5);
frest(...[1, 2, 3, 4, 5]);
// -----
// you write a function parameter list that destructures iterables into variables
// can be applied to objects
// you can simulate the named argument functionality of python, using 
//   a destructured obj
// can also default the variables used for destructuring
function destr([a, b, c, d]) {
  return a + b + c + d;
}
function destr2({x, y}) {  // uses shortened obj form
  return `(${x}, ${y})`;
}
console.log(destr([1, 2, 3, 4]));  // 10
console.log(destr2({y:1, x:0}));   // (0, 1), like python's named params
// -----
// functions are objects, so you can add properties to them
//   that store data like "static" variables in other languages
function AddCounter() {
  if (AddCounter.val === undefined) {
    AddCounter.val = 0;
  }
  else {
    ++AddCounter.val;      
  }
}
AddCounter();
console.log(AddCounter.val);  // 0 
AddCounter();
console.log(AddCounter.val);  // 1
// -----
// this function is unnamed and immediately invoked
// sort of like an unamed namespace
// parenthesis on the outside is needed so that a formal function is 
//   not defined
(function() {
  let local = 10;
  console.log(local);
}());
// -----
// all functions in javascript are closures, in that
//   they also have access to variables that are defined
//   in the same scope as the function definition
// this closure data is implicitly visible to the function
//   and can act as private variables
// commonly used with nested functions that are returned
// inner function is returned then invoked in a scope outside of
//   where it is defined, but it knows outer_name anyways
// this is different from passing the string from the nested to the outer
//   then back out again
// function closures capture their own unique version of the state they
//   are defined in, even if other functions share the same state
function outer() {
  let outer_name = "Ben Harki";
  function inner() {
    console.log(outer_name);
  }
  return inner;
}
outer()();  // outer() returns inner and then its invoked
// -----
// closures capture local variables in the same scope as
//   the function definition into their own space private to the function
// can do this in an immediately invoked function that returns another function
//   that when called calls from the private state it has access too
// this is better than saving the state as a function property, that
//   could be accessed or corrupted
let uniqueInteger = (function() { 
  let counter = 0;
  return function() {return counter++;}; 
}());
console.log(uniqueInteger());  // 0 
console.log(uniqueInteger());  // 1
// -----
// a function that returns an object with get and set properties 
// uses the closure of the function, in this case, the parameter
//   to store data instead of a seperate internal property
function counter(n) {
  return {
    get inc() {
      return ++n;
    },
    set reset(m) {
      n = m;
    },
    toString() {
      return `${n}`;
    } 
  }
}
let co = counter(10);
console.log(`${co}`);
co.inc;
console.log(`${co}`);
co.reset = 40;
console.log(`${co}`);
// -----
// closure example where an object is given a get and set method
//   that uses data stored in the function's closure
// uses val and no "this" keyword
// val is closure storage given implicitly to the object
// see LOOPS for an error that can happen when using a var as a local
//   variable in a for loop, that is also a shared closure variable
function GiveVal(obj) {
  let val = undefined;
  obj.getval = function() {return val;};
  obj.setval = function(v) {val = v;};
} 
let clob = {};
GiveVal(clob);
clob.setval(100);
console.log(clob.getval());
console.log(clob.val);   // undefined
// -----
// "this" keyword changes context in the body of a function
// its the global object in a non-method function, and the current obj if it is a method
// when "this" is captured into a nested function's closure:
//   if outer func is non-method, and inner func is non-arrow, then "this" is the global obj
//   if outer func is a method and inner func is non-arrow, "this" is still the global obj
//   if outer func if is non-method and inner func is an arrow, "this" is still the global obj
//   if outer func is a method and inner func is an arrow then "this" is the current obj 
glob = 10; 
function outerf() {
  function innerf() {
    console.log(this);
  }
  return innerf;
}
function arrf() {
  return () => console.log(this);
}
outerf()();   // "this" is the global obj
let eobj = {'outerf': outerf};  
eobj.outerf()();     // still the global obj, not eobj
arrf()();   // the global obj
eobj['arrf'] = arrf;
eobj.arrf()();  // eobj
// -----
// TODO: see yield to create generator functions

// FUNCTIONAL PROGRAMMING
// uses arrow functions, but can also use the function keyword version
// TODO: examples with find(), findIndex(), every(), some(), reduce(), reduceright(), flat(), flatmap(), concat()
//  thes functions can accept other functions of three args, see forEach in MULTIDIMENSIONAL ARRAY
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
// -----
// this is example of a higher ordered function that adds the 
//   capablility of "memoizing" a function
// it will take a function and return one that has an attached
//   closure used to document the function calls
// the cache storage is saved as a Map, like a hashmap or dictionary
// the cached storage helps in performance, so it retrieves
//   a precalculated value, rather than recomputing factorial calls, like dynamic programming
function memoize(f) {
  cache = new Map();   // make this a "let" variable to make it private
  calls = 0;          // count how many function calls factorial makes
  return function(...args) {   // ...args saves all the args into an array to generalize
    calls += 1;
    let key = '';
    for (let val of args) {
      key += `${val},`;
    }
    key = key.slice(0, -1);  // everything but the last char, so no extra ','
    if (cache.has(key)) {
      console.log(`returned stored val: f(${key})`);
      return cache.get(key);
    }
    else {
      let result = f.apply(this, args);
      cache.set(key, result);
      return result;
    }
  }
}
const factorial = memoize(
  function(n) { 
    return (n <= 1) ? 1 : n * factorial(n-1);});
factorial(4);
console.log(cache); // Map(4) { '1' => 1, '2' => 2, '3' => 6, '4' => 24 }
console.log(`number of function calls: ${calls}`);  // 4
calls = 0;
factorial(5);
console.log(cache); // Map(5) { '1' => 1, '2' => 2, '3' => 6, '4' => 24, '5' => 120 }
console.log(`number of function calls: ${calls}`);  // 2, only f(5) * f(4), since f(4) is known

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
// loops with var variables should be avoided, since
//   it makes the variable function scoped
// here i in broken()'s closure is a live variable
//   shared by all the functions in the array, because of var
// after the loop completes i is incremented to 5, so all 
//   i's shared by the functions are 5
// using let instead of var fixes this
function broken() {
  let arr = [];
  for (var i = 0; i < 5; ++i) {
    arr[i] = () => i;
  }
  return arr;
}
let arrb = broken();
console.log(arrb[1]());   // 5
console.log(arrb[2]());   // 5
// -----
// SEE FUNCTIONAL PROGRAMMING for foreach()
// TODO: for has an "await" of version for asynchronous
//   iterators, see page 220 

// CLASS
// -----
// classes use prototype-based inheritance, where if two objects
//   inherit properties from the same prototype object then they are of the same class
// constructors can be created from any function except arrow, async, and generator functions
// class declarations are not hoisted like functions, so you cannot create a class obj before they
//   are declared
//   (this file exports the MyInt class, so when it is run by runmaster.js,
//      so MyInt is predefined before Main() is invoked)
// -----
// old way of creating a class using Object.create, factory method
//   and no "new" syntax or constructor
// return a prototype object, using create(), that 
//   contains properties
// range() is like a factory method (like a constructor), but range is a function/object
//   with a methods property, that stores the prototype
// shows an iterator as a generator function and toString()
// generator function are defined with * in the shorthand
// "this" refers back to the r obj returned from range()
function range(from, to) {
  let r = Object.create(range.methods);  // sets the methods from prototype obj
  r.from = from;
  r.to = to;
  return r;
} 
range.methods = {  // protype obj
  includes(x) {
    return x >= this.from && x <= this.to;  
  },   // commas must seperate properties
  *[Symbol.iterator]() {    // function*() can be used, when not using the syntax
    for(let x = this.from; x <= this.to; ++x) {
      yield x;
    }
  },  
  toString() {
    return `[${this.from}, ${this.to}]`;
  } 
};
let r = range(0, 10);
console.log(r.includes(2));
for (let val of r) {   // uses the iterator
  console.log(val);
}
console.log(`${r}`);  // just r calls the JSON, this calls the toString()
// -----
// another old way of creating a class by defining a constuctor MyInt() 
//   use the "new" keyword, and defining the prototype property 
// constructor function does not return, names are usually capitalized
//   but can have more than one constuctor, where each one points to the
//   same prototype
// "new" implicity creates Object.create() (see previous version of a class)
//   from the user-overridden prototype property 
// all (non-arrow) functions have a prototype property, that when user overriden
//   will turn the function into a constructor for a class
// "this" refers to the current object, since MyInt() is a constructor
// new.target will be defined when the constructor is called with new
//   constructors should be called with new, and the condition enforces it 
// new.target could be defined when this class is subclass
// prototype objs have a default constructor property, here it is overridden
//   to match the MyInt() constructor that invokes it
function MyInt(val) {
  if (new.target === undefined) { 
    return new MyInt(val);   // new is called here, so can call constructor without it
  }
  this.num = val;   
}
MyInt.prototype = {     // overrides the default obj protype
  toString: function() {  // with the function, not the shorthand, since this is old JS 
    return `myint: ${this.num}`;
  },
  inc: function() {return ++this.num;},
  constructor: MyInt
};
let myi = new MyInt(10);
myi.inc();
console.log(`${myi}`);
let myi2 = MyInt(12);  // can invoke without the "new" bc of the condition
console.log(`${myi2}`);
console.log(MyInt.prototype.constructor.name);  // MyInt
// -----
// REQUIRES ES6 (GOOGLE AS DOES NOT SUPPORT ES6: method defined using =)
// create a class with more modern syntax
//   it implicitly defines a class like previous old examples
// constructor() is the constructor and an empty default one is provided
//   if you do not define it
// can add an iterator with a Symbol, see range.methods above
// no return is necessary in the constructor
//   however you can return a new object with a return statement
//   any other return statement, like returning a primitive or nothing
//      will be ignored
// you cannot define properties with name: value pairs,like with objects
//   but you can define computed properties with [expression], methods or properties
// construct an object using new, calling constructor
// can omit the parenthesis on a no args constructor
// you can add more fields in other methods, not just the constructor
class Point {
  constructor(x, y) {   // no need to use commas to seperate properties
    this.x = x;
    this.y = y;
  }
  mysum() {
    return this.x + this.y; 
  }
  ['key']() {return 0;}  
  ['key2'] = function() {return 1;}  // with the function keyword
}
let p = new Point(3, 4);
console.log(p);
console.log(p.mysum());
console.log(p['key']());   
console.log(p.key2());  // can use this, if the name is ok
// -----
// you can use a class definition expression to define a class
// can be named or anonymous
// you can insert another name, after "class" that can only
//   be refered to inside the body of the class, like in function definition expressions
let ClassExp = class {constructor() {this.val = 10;}};  
console.log(new ClassExp());
let ClassExp2 = class SomeName {constructor() {this.val = 10;}};  
// ------
// you can define a standalone class in this file, see below
// this Main() function, which invokes the MyInt() must be called 
//   after the MyInt definition (unless both are exported)
let myint = new MyInt(10);
console.log(myint);
// -----
// you can define "static" methods, aka class methods, called through the class name
//   although technically these are defined as properties of the constructor
// you generally avoid using "this" in static methods
// this is not a property of the WithStatic.prototype obj
class WithStatic {
  static PrintStuff() {
    console.log("stuff");
  }
}
WithStatic.PrintStuff();
// -----
// you can define get and set methods like in an object, see example in OBJECT
// _val is more of a reminder that it should be private
//   but its actually still public 
// no set method is defined, val cannot be assigned too, even if attempted
class MyIntGS {
  constructor(val) {
    this._val = val;
  }
  get val() {
    return this._val;
  }
}
let gs = new MyIntGS(10);
console.log(gs.val);   // 10
console.log(gs._val);  // 10, _val is not technically private
gs.val = 20;     // does nothing, since no set method
console.log(gs);   // 10
// -----
// REQUIRES ES6 (GOOGLE AS DOES NOT SUPPORT ALL OF ES6, fields defined outside constructor)
// you can define object data fields outside of a constructor, without "this"
//   these are not static, or shared, and each object is given their own version
// public fields defined outside the constuctor do need read through an object
// private fields need a # prefix, and must be initialized outside the constuctor
//   they cannot be init inside one, but can be reset
class Fields {
  f1 = 0;   // not static, normal obj field
  #priv;   // private, and undefined by default
  constructor(val) {
    // no this.f1 needed, since it has been initialized
    this.#priv = 100;   // can access private fields inside the class body
  }
  get priv() {return this.#priv;}   // makes #priv read-only, through public priv
}
let fvar = new Fields();
console.log(fvar.f1);  // 0
// fvar.#priv = 29;   // cannot set without error
// console.log(fvar.#priv);   // cannot read without error
console.log(fvar.priv);  // 100
fvar.priv = 29;    // does nothing, since no set with the get
console.log(fvar.priv);  // 100, priv is unchanged
// -----
// REQUIRES ES6 (GOOGLE AS DOES NOT SUPPORT ALL OF ES6, needed for static fields)
// static fields need the "static" keyword and are 
//   properties of the constructor function object (like the class name)
// they are not shared across their objects
// they can be made private with # prefix
class HasStatic {
  static svar = "this is static";
}
console.log(HasStatic.svar);  // this is static
let sobj2 = new HasStatic();
console.log(sobj2.svar);  // undefined
// -----
// you can add properties to any class dynamically, using the class's
//   prototype object
// can add properties to built-in classes, although be careful for name conflicts
//   future or otherwise
// can use "this" to access the current object
Number.prototype.NormalZero = function() {
  if (this.valueOf() === -0) {
    return new Number(0);
  }
  else {
    return this;
  }
}
let nonnegz = Number(-0);
console.log(nonnegz.NormalZero());
// -----
// SUBCLASS
// old way, pre ES6, of creating a primitive subclass by calling
//   Object.create(), and setting the prototype and constructor properties
// this version's superclass is created with a constructor (with no keyword)
//   and a defines a prototype object
// the subclass only inherits the superclass's prototype object template, nothing
//   directly from the superclass constructor
// the subclass does not have its own prototype, only taken from the superclass
function MyInt2(val) {    // superclass constructor
  this.val = val;
}
MyInt2.prototype = {
  val: Number(0),
  toString: function() {return `MyInt2: ${this.val}`;}
};
function NegateInt(val) {   // subclass constructor
  // console.log(this.val);   // 0, inherited from the prototype
  this.val = -1 * val;
}
NegateInt.prototype = Object.create(MyInt2.prototype);
NegateInt.prototype.constructor = NegateInt;
let myi3 = new MyInt2(-2);
console.log(`${myi3}`);
let nmyi = new NegateInt(-2);
console.log(`${nmyi}`);   // NegateInt has the inherited MyInt2 toString() property
// -----
// REQUIRES ES6 (supported by Google AS)
// more modern version uses "extends" to inherit
// can extend builtin classes
// extends in inherits superclass.prototype nd superclass class 
//   properties, which includes static properties
// super represents the superclass, where you can call its constructor
//   or other superclass methods
// you can access the superclass properties through this, once super() has been called
// new.target, defined in the body of a constructor when it was called with new, will
//   change to the subclass
// superclass properties will be overriden in the subclass 
// you may be able to treat superclasses as abstract classes and templates
class MyString {
  constructor(str) {
    this.str = str;
  }
  toString() {
    return `str: ${this.str}`;
  }
} 
class SubMyString extends MyString {
  constructor(str, val) {
    super(str);   // calls the superclass constructor
    this.int = val;
  }
  toString() {
    return `int: ${this.int}, ` + super.toString();  
  }
}
let mystr = new MyString("this string");
console.log(`${mystr}`);
let substr = new SubMyString("this string", 10);
console.log(`${substr}`);


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

console.log("You have reached the end!");
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
  7.8 Array Methods
    so many array methods, see ARRAY for the list
  7.9 Array-Like Objects
    you can define integer keys for an object, to make them array-like, but
      they don't have the Array methods
    some built in functions can accept array-like objects using .call() variation
  8.2.4 Indirect Invocation of a function
    functions are objects, so they methods that can invoke them
    "can invoke any function as a method of any object, even if it is not 
      actually a method of that object" - using call() and apply() methods on a function object
  8.3.3 The Arguments Object
    can be used instead of the ...rest parameter for a function
  8.7 Function Properties
    length, name, prototype, call, apply, bind, toString, Function() constructor
    functions are objects too, so they have method
    call and apply allow you to indirectly invoke a function as thought it were a method
      so some other object
    toString() returns the source code of the function
    functions can be created with the Function() constructor and strings of code for the body
    bind can perform partial application, like function currying
  8.8 Functional Programming
    I have some of this
    usage of map(), reduce(), join
    examples of higher order functions, that accept functions and return modified 
      versions of them
    their versions of partialLeft and partialRight, similar to partial application
      functionality of bind, but can partially apply from the right too
    did an example of memoization of a function, where a function is modified
      to store data about the call in its closure 
  9.2.C Constructor Property
    I did some of this
    constructor functions (as objects) have a prototype property, set to an object, and the prototype obj
      has a constructor property set to the function
    prototype property has as default object, while the constuctor property is undefined by default
  9.3.4 Example
    example of a complex class with public and private properties     
  9.5.3 Delegation instead of Inheritance
    I do what I want
  9.5.4
    a convoluted attempt at mimicing abstact classes

STOPPED AT Chapter 10 Modules:
  I did actually do some of this, with respect to Google Apps Script
  Here are some interesting sections if I ever come back to JS:
    Iterators and Generators
    Async JS
    MetaProgramming
*/





