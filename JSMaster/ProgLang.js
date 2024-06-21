// THIS IS A COPY FROM THE PROG LANG CONCEPTS CLASS

/*
Javascript - not related to Java, but went along with the idea that java would
    work nice for browsers
dynamically typed,  first class functions and objects, has both statements and expressions
inspired by scheme
first class means they can be passed as arguments, returned, stored in data structures
undefined is like void in C languages
JS uses lexical (static) scoping
has nested functions
single threaded - any loops will lockup the entire engine/browser, recently can use WebWorkers and WebAssembly for threading
however the browsers are multithreaded
interpreted, so in order to extend, just provide a library, text file loaded by a browser
JQuery defines a useful library - provides a single $ function, provides a wrapper to smooth over early js inconsistancies in early browsers
Underscore and Lodash provide _ object - with lots of functions, map, reduce, ..
Typescript and Flow add types and allow errors to be checked by a compiler
Angular, Vue, and React add component system for describing webpages in pieces
Babel is a JS library that provides an interpreter for JS, allows older browsers to use new JS features that are not supported by the browser themselves
LLVM.js, emscripten, webassembly , allows assembly code to be executed in web browser, for old C programs
NPM and Webpack for developers
Google introduced V8 for chrome browser to address js  slow runtime due to dynamism - V8 gets rid of the dynamism 
*/

/*
runs in browsers, can use JS console in any browser, under dev tools
can type in expressions in the console
webpages are represented in programs using DOM, document object modeling, in an html page
browser renders the DOM
html pages are read into a DOM and then can change over time
JS created to maipulate DOM for dynamic pages
primarily uses event handling for interactive webpages, ex. buttons, ... 
*/

// Examples
> 1+2
 3
> console.log(1+2)
VM74:1 3
 undefined
> function f (x) {
  console.log ("Called with " + x);
  return x + 1;
}
f (5);
VM81:2 Called with 5
6
// **********
// defaults to "a", + concats with strings
console.log (x);
x = x + "b";
console.log (x);
var x = "a";
console.log (x);

// Example - using test.html loaded into browser, copy and call main() in console
// inspect function shows how the dynamic html file is changing on click
// see test.htm
function main () {
  var count = 0;
  var a = document.querySelector('input#a');
  var b = document.querySelector('div#b');
  var c = document.querySelector('div#c');
  for (var x of [b,c]) {
    x.onclick = function (e) {      // listener for mouse click working on b or c
      e.target.outerHTML += "<p>Again! " + count++ + "</p>";        // adds a line and count to wherever you click on it or subelement 
  } }
  a.value = 1 + 2;          // changes value in the box to 3
  c.innerHTML += "<p>I love teletubbies!</p>";          // adds to the end of the page
}
document.addEventListener("DOMContentLoaded", main);

// Example
// surprizing results
> []+[]
''
> [] +{}
'[object Object]'
> {} + []
0
> {} + {}
'[object Object][object Object]'
> xs = ["10", "10", "10"];
(3) ['10', '10', '10']          // (3) is the size
> xs.map(parseInt)      // expect 3 10s but see result
(3) [10, NaN, 2]
> [1,5,20,10].sort()        // sort is weird, it should sort strings, js converts to strings, then string sort
(4) [1, 10, 20, 5]
> undefined + 1
NaN

// == equality can be weird, should use === which has no conversions
// conversions cause the confusion
> '' == '0'
false
> 0 == ''
true
> 0 == '0'
true
> false == 'false'
false
> false == '0'
true
> false == undefined
false
> false == null
false
> null == undefined
true
> ' \t\r\n ' == 0
true

// Hoisting
// hoists variable declarations  to top of the nearest enclosing function
// initialization code is not hoisted
var a = 1;      // global a doesn't change
function f () {
  console.log ("f1: a = " + a);        // prints undefined, bc of hoisting, think var a; (initialized to undefined) here before console.log call
  { var a = 2;      // assignment to a local variable
    console.log ("f2: a = " + a);
  } 
}
function main() {
  console.log ("m1: a = " + a);         
  f ();
  console.log ("m2: a = " + a);
}
undefined
 > main()
VM1380:9 m1: a = 1
VM1380:4 f1: a = undefined
VM1380:6 f2: a = 2
VM1380:11 m2: a = 1
// **********
// equalvalent t0 above
// all variables are initialized to undefined
var a = 1;
function f () {
  var a;        // undefined, simulates the hoisting above
  console.log ("f1: a = " + a);
  { a = 2;
    console.log ("f2: a = " + a);
} }
function main() {
  console.log ("m1: a = " + a);
  f ();
  console.log ("m2: a = " + a);
}
> main()
m1: a = 1
f1: a = undefined
f2: a = 2
m2: a = 1
// ***********
// let does proper block scope
var a = 1;
function f () {
  console.log ("f1: a = " + a);     // with let below, this brings in global, var would be undefined
  { let a = 2;
    console.log ("f2: a = " + a);
} }
function main() {
  console.log ("m1: a = " + a);
  f ();
  console.log ("m2: a = " + a);
}
> main()
m1: a = 1
f1: a = 1
f2: a = 2       // in local f() scope
m2: a = 1     // f() a assign does not effect the global
// ***********
// hoisting happens anywhere, like inside an if block
var a = 1;
function f (b) {
  a = 2;            // always local, see below
  if (b) {
    var a;                  // grabs  2 when true bc hoisted
    a = a + 1; 
  }
  console.log (" f: a = " + a);     // 3 when true, 2 when false
}
function main() {
  f (true);
  console.log ("m1: a = " + a);       // 1, global unchanged
  f (false);
  console.log ("m2: a = " + a);     // 1, global unchanged
}
> main()
 f: a = 3
m1: a = 1
 f: a = 2
m2: a = 1
// ***********
// examples from worksheet
// with and without var declararion in function
var x = "a";
function f () {
  console.log (x);      // undefined, does not take global
  x = x + "b";
  console.log (x);      // undefinedb
  var x = "c";              // without this line x its "a", with it its like adding a var x; undefined
  console.log (x);      // c
}
f ();
// **********
// without var in function
var x = "a";
function f () {
  console.log (x);      // a
  x = x + "b";
  console.log (x);      // ab
}
f ();
// **********
// if with a var in the conditional, does not matter
var x = "a";
function f () {
  console.log (x);      // undefined
  x = x + "b";
  console.log (x);      // undefinedb
  if (false) {                   // even though it may not execute, it acts like var x is declared here       
    var x = "c";
  }
  console.log (x);      // undefinedb
}
f ();
// **********
var x = "a";
function f () {
  console.log (x);      // no var so defaults to a
  x = x + "b";
  console.log (x);      // "ab"
  (function () {        
    var x = "c";
    console.log (x);            // "c"
  }) ();
  console.log (x);      // "ab"
}
f ();
// ***********
// if with let, let is proper static block scope
var x = "a";
function f () {
  console.log (x);      // no var, so "a"
  x = x + "b";
  console.log (x);      // "ab"
  if (false) {
    let x = "c";        // it this was var then a would be undefined like above
  }
  console.log (x);      // "ab"
}
f ();
// **********

// Asynchronous Programming:
// at startup JS will register a bunch of callbacks on the browser, and wait for the browser to call back - which could call more callbacks
// think of wikipedia predicative search
    // register a keyboard key listener, if key is pressed parse it, and send a request or possible completions
    // get back either another keystroke or a response, as more keys are pressed we want new keys used to search
// ***********
// JS collections processing
var xs = [ 11, 21, 31 ];
xs.map (x => (2 * x));
xs.filter (x => x%7===0)
xs.reduce (((z,x) => z+x), 0)
// ***********
// JS has high order functions and mutable state
// recall javac scope issue in Thread example, where an int x = i is added for compiler to be effectively final
// JS does more like python perl, does not need int x = i, but not great results, js is single threaded so use array for example
var funcs = [];
for (var i = 0; i < 5; i++) {
  funcs.push (function () { return i; });       // creates closures for 0,...,4, problem is closing on the variable of i, not the value of i
}
funcs.map (f => f());       // when envoked  look has ended so i=5 for each
// [5,5,5,5,5]
// ***********
// ths does not fix this
var funcs = [];
var x;
for (var i = 0; i < 5; i++) {
  x = i; /* x is shared too! */
  funcs.push (function () { return x; });   // shares x from superscope
}
funcs.map (f => f());
// [4,4,4,4,4]
// **********
// this also doesn't work, with var declaration in the loop, bc of hoisting
var funcs = [];
for (var i = 0; i < 5; i++) {
  var x = i; /* x is still shared! */
  funcs.push (function () { return x; });
}
funcs.map (f => f());
// [4,4,4,4,4]
// ***********
// possible in es6
// block scope variable declared with let fixes this 
var funcs = [];
for (var i = 0; i < 5; i++) {
  let x = i; /* block scope */
  funcs.push (function () { return x; });
}
funcs.map (f => f());
// [0,1,2,3,4]
// **********
// before es6, used an IIFE - immediately invoked function expression
var funcs = [];
for (var i = 0; i < 5; i++) {
  (function () {        // lambda here
    var x = i;          // IIFE here allows a scope for variable x
    funcs.push (function () { return x; });
  }) ();        // immediatel invoked
}
funcs.map (f => f());
// [0,1,2,3,4]
// ***********
// same as previous example with an explicitly named function
var funcs = [];
for (var i = 0; i < 5; i++) {
  var help = function (x) {     // anonymous function is saved in a variable, or just write as a function
    return function () { return x; }        // help is a function that creates functions, function factory, not a literal
  };
  funcs.push (help (i));           // invokes the function here, closure is being pushed into funcs, pushes result of help call
}
funcs.map (f => f());
// **********

JAVASCRIPT OOP
// class declarations are not primitive
// describe objects directly, use js prototypes to find methods, delegation, similar to Self language
// runtime structures resemble vtables in C++
// **********
var empty = {}; /* Object literal with no contents */ 
var person = {  /* Object literal with three properties */      // new instance of object class
  name: "Alice",
  age: 50,
  addr: "243 S Wabash Ave"
};
> [ person.name, person.name.length ]
[ 'Alice', 5 ]
> person.age = person.age + 1       // by default objects are mutable
51
> person.occupation     // no exception
undefined                /* huh???? */
> person.occupation.length     // indexing into undefined does give an exception
Uncaught TypeError: Cannot read property 'length' of undefined
// **********
// dynamically typed
function f (x) {        // function takes an object and prints its fields
  console.log ("1: " + x);
  console.log ("2: " + x.data);
  console.log ("3: " + x.data.length);
}
> f ({ data: [11,21,31] });     // an object with a field labeled data
1: [object Object]      // prints the object x
2: 11,21,31
3: 3
> f ("pizza");
1: pizza
2: undefined
Uncaught TypeError: Cannot read property 'length' of undefined  // similar to above
// ***********
// function takes an array
// no exception until the last case
function f (x) {
  console.log ("1: " + (x / 2));
  console.log ("2: " + (x[0]));
}
> f ([11,21,31]);
1: NaN      // does not make sence to divide whole array by 2
2: 11
> f (8);
1: 4
2: undefined        // does not make sence to grab an element from a non array
> f (undefined);
1: NaN      // think undefined/0
Uncaught TypeError: Cannot read property '0' of undefined       // similar in that acessing a property of undefined throws exception
// **********
// object is a map from strings to values
// dot notation allowed when string key has no spaces
// dynamically add fields after declaration 
var person = { name: "Alice", age: 50, addr: "243 S Wabash Ave" };
person.occupation = "Developer";        // add fields
person["happy place"] = "Home";     // can't use dot bc it has a space
> for (p in person) { console.log (p + ": " + person[p]); }     // person is like an array of key/value pairs, p 's are keys here, person[p] value, field iteration not possible in java
name: Alice
age: 50
addr: 243 S Wabash Ave
occupation: Developer
happy place: Home
> JSON.stringify(person)        // built in
'{"name":"Alice","age":50,"addr":"243 S Wabash Ave","occupation":"Developer","happy place":"Home"}'
// *********
// function as a value of a field (method)
var counter1 = { n: 0, get: function () { return this.n++; } };         // returns then increments
var counter2 = { n: 0, get () { return this.n++; } };       // another way as above line
> [counter1.get(), counter2.get()]
[0, 0]
> [counter1.get(), counter2.get()]
[1, 1]
> [counter1.get, counter2.get]
[ [Function: get], [Function: get] ]
> [counter1.get.toString(), counter2.get.toString()]        // toString() prints out the code of the function
[ 'function () { return this.n++; }', 'get () { return this.n++; }' ]
// ***********
// this is required in JS
var counter1 = { n: 0, get: function () { return this.n++; } };
var counter3 = { n: 0, get: function () { return n++; } };      // no global n, not referencing obj's n without this
> counter1.get()
0
> counter3.get()        // no this in counter3
Uncaught ReferenceError: n is not defined
    at Object.get (repl:1:43)
// ***********
// no private properties
var counter1 = { n: 0, get: function () { return this.n++; } };
> counter1.get()
0
> counter1.n = -2000        // not private so can change it
> counter1.get()
-2000
// **********
// achieve private state
// encapsulation using function closures
function createCounter4 () {
  var n = 0;
  return {          // returns an object that has a get method
    get: function () { return n++; }        // accesses n that was closed at the time of creation, open when create counter, closed around n on return
  };
};
var [c4a,c4b] = [createCounter4(), createCounter4()]        // returns an array of objs
> c4a.get()     // calls get method, which increments after return
0
> [c4a,c4b].map (x => x.get())  // assigns next call/inc to objs
[ 1, 0 ]
> [c4a,c4b].map (x => x.get())
[ 2, 1 ]
// ***********
// closure variables are not fields
// function returns an object with methods, but the methods try to access field n, when n is only a local var to a function
function createCounter5 () {
  var n = 0;
  return {
    get: function () { return this.n++; }       // this.n++ is the difference here, n is not a field of an object
    huh: function () { console.log ("this.n=" + this.n); }
  };
};
var c5 = createCounter5 ();
> c5.get ();
NaN         // increments undefined, remember undefined+1 = NaN   
> c5.huh ();
this.n=undefined      
// *********
// closure vs object
// no objects here only closures
// function returns a function that accesses local var in function
function createCounter6 () {
  var n = 0;
  return function () { return n++; };       
}
var [c6a,c6b] = [createCounter6(), createCounter6()]
> c6a()
0
> [c6a,c6b].map (x => x())
[ 1, 0 ]
> [c6a,c6b].map (x => x())
[ 2, 1 ]
// ************
// binding this
// f() is function context, also Constructor() is constructor context
var o = { getThis () { return this; } };        // method
o.getThis() === o;     // true,     o.method is method context
var fThis = o.getThis; // save method as a variable
fThis() === o          // false --- this=o not closed above, o is not present here, so this is not bound     
fThis() === global     // true (in Node.js)
fThis() === window     // true (in Browswer), window corresponds to te window of the web browser, nonsence meaning of this
// ************
// JS vs scala, in use of "this".
// JS: methods are functions, methods are properties that hold closures, "this" is not bound in closure, needs bound at point when closure is invoked
// JS: closure is returned when accessing the property
// JS: object with a field and method
// Scala: Methods are not functions, scala closes "this" when converting methods to functions
var oJS = { n: -1, next () { this.n += 1; return this.n; }};
var fNext = oJS.next    
fNext() // NaN --- closure does not bind this (on alias), looks for n in global context, not found
// scala creates a closure that contains the n field for the function, js would not 
object oScala { var n = -1; def next() = { this.n += 1; this.n } }
var fNext = oScala.next _       // _ converts a method to a function, _ creates a closure for oScala.next, does bind this to the object in scala
fNext() // 0 --- closure binds this=oScala
// ***********
// Trouble in JS
// function context is seperate from object
var o = {
  v : 5,            // this is not brought in
  add : function (xs) {     // function takes a list
    return xs.map(function(x){ return this.v + x; });   // invokes on function context, not object code, so "this is undefined"
  }
}
o.add([10,20,30]) // [ NaN, NaN, NaN ]
// Old Hack
var o = {
  v : 5,
  add : function (xs) {
    var me = this;      // add this to the functions local variable, closed properly
    return xs.map(function(x){ return me.v + x; });
  }
}
o.add([10,20,30]) // [ 15, 25, 35 ]
// ***********
// es5 fix
var o = {
  v : 5,
  add : function (xs) {
    return xs.map(function(x){ return this.v + x; }.bind(this));        // gives bind operationm binds this inside the function
  }
}
o.add([10,20,30]) // [ 15, 25, 35 ]
// es6 fix, better way
var o = {
  v : 5,
  add : function (xs) {
    return xs.map(x => this.v + x);     //  => deals with this properly, closed within creating context of object
  }
}
o.add([10,20,30]) // [ 15, 25, 35 ]
// ***********
// => and this, => uses current value of "this"
var y = {getThese: function(xs){ return xs.map(x => this)}};        //returns the object for each element, maps to a list, so [y, y, y]
var z = {getThese: function(xs){ return xs.map(function(x){ return this; })}};      // this is not closed here within calling context, obj is not in function context
y.getThese([10,20,30])[0] === y      // true, grab first element        
z.getThese([10,20,30])[0] === global // true (in Node.js), global and window are junk values
z.getThese([10,20,30])[0] === window // true (in Browswer)
// **********
// creating objects: function context
// call with function context, creates and returns an object with a function
// that object has methods next and reset
function createCounter () {
  return {
    n: -1,
    next:  function () { return ++this.n; },
    reset: function () { this.n = -1;      }
  };
}
var c1 = createCounter (); // Function context, seperate closures
var c2 = createCounter (); 
> [c1.next(), c1.next(), c1.next(), c1.reset(), c1.next(), c1.next()]
[ 0, 1, 2, undefined, 0, 1 ]            // undefined because it returns result of an assignment
> [c2.next(), c2.next(), c2.next(), c2.reset(), c2.next(), c2.next()]
[ 0, 1, 2, undefined, 0, 1 ]
// ***********
// constructor, object created with new
// any new object is bound to newly allocated memory
// creates a seperate closure for next and reset
// drawback is double closures for each object, fixed by prototype in below example
function Counter () {
  this.n = -1;
  this.next = function () { return ++this.n; },
  this.reset = function () { this.n = -1; }
}
var c1 = new Counter (); // Constructor context
var c2 = new Counter (); 
> [c1.next(), c1.next(), c1.next(), c1.reset(), c1.next(), c1.next()]
[ 0, 1, 2, undefined, 0, 1 ]
> [c2.next(), c2.next(), c2.next(), c2.reset(), c2.next(), c2.next()]
[ 0, 1, 2, undefined, 0, 1 ]
// ***********
// JS functions are objects, so it can have fields
// prototypes of functions (not like c)
// specifies propeties that the function can take, properties are added to its prototype, not the function directly
// creates another object Counter.prototype, c1.next looks into c1's prototype, c1 and c2 share prototypes
function Counter () { this.n = -1; }
Counter.prototype.next  = function () { return ++this.n; }  // fields to the function object, shared by different instances
Counter.prototype.reset = function () { this.n = -1;     }
var c1 = new Counter ();
var c2 = new Counter ();
> [c1.next(), c1.next(), c1.next(), c1.reset(), c1.next(), c1.next()]
[ 0, 1, 2, undefined, 0, 1 ]
> [c2.next(), c2.next(), c2.next(), c2.reset(), c2.next(), c2.next()]
[ 0, 1, 2, undefined, 0, 1 ]
// ***********
// dynamic, can update or add methods at runtime, cannot do in java/c  compiled languages
// can update prototype dynamically, updates all the counters at once
// how is it implemented:
// each obj has a __proto__ internal property (field), points to another object
// keeps looking up prototype chain until find the definition of object, called delegation-based inheritance
// in js its called prototype based inheritance
// __proto__ != prototype, all objs have __proto__, functions have prototype, prototype is only meaniingful from constructor context
// in constructor new objs's __proto__ is set to the functions prototype
function Counter () { this.n = -1; }
Counter.prototype.next  = function () { return this.n += 1; }
Counter.prototype.reset = function () { this.n = -1;     }
var c1 = new Counter ();
> [c1.next(), c1.next(), c1.next(), c1.reset(), c1.next(), c1.next()]
[ 0, 1, 2, undefined, 0, 1 ]
> Counter.prototype.next  = function () { return this.n += 2; } // update prototype field
> Counter.prototype.reset = function () { this.n = -2;     }
> [c1.next(), c1.next(), c1.next(), c1.reset(), c1.next(), c1.next()]   // immediately updates
[ 3, 5, 7, undefined, 0, 2 ]
// ***********
// prototype implementation
// Foo function is represented as an object, has a prototype which is also an object, 
// Foo's __proto__ points to function.prototype while __proto__ points to 
    // Object.prototype, (eveything eventually points to it), its __proto__ is null 
// Foo's prototype points to Foo.prototype, Foo.prototype points to Object.prototype 
// analagous to traditional inheritance: b is of Foo, which extends Object, except that the prototype/inheritance chain can be changed dynamically
function Foo(y) { this.y = y; }   
Foo.prototype.x = 10;   // adds a new field
Foo.prototype.calculate = function (z) {        // to look for calculate of c or b, use the chain, not in b, go to Foo.prototype
  return this.x + this.y + z;
};
var b = new Foo(20);        // b and c's  __proto__ point to Foo.prototype
var c = new Foo(30);
// ***********
// can change __proto__ at runtime
// updats an instances method, also updates a functions fields
function UpCounter () { this.n = -1; }
UpCounter.prototype.next  = function () { return ++this.n; }
function DownCounter () { this.n = 1; }
DownCounter.prototype.next  = function () { return --this.n; }
var c = new UpCounter ();
c.next ();   // Returns 0
c.next ();   // Returns 1
c.__proto__ = DownCounter.prototype //  c was un upcounter, its __proto__ changed to Downcounter to use its method
c.next ();   // Returns 0
c.next ();   // Returns -1
// ***********
// the delegate object can also delegate
function ResetCounter () { this.reset(); }
ResetCounter.prototype.reset  = function () { this.n = -1; }
var c = new ResetCounter ();
c.next ();   // TypeError: c.next is not a function
function Counter () { this.n = -1; }
Counter.prototype.next  = function () { return ++this.n; }
ResetCounter.prototype.__proto__  = Counter.prototype       // go look for next method in Counter
c.next ();   // Returns 0
c.next ();   // Returns 1

INHERITANCE
// see discussion in javaprogs about interweaving of class methods with and without interface/inheritance
// proper interweaving of class methods
// this is more modern delgation based inheritance, instead of class inheritance like in Java
var A = {
    f (x) {
        console.log ("A.f (" + x + ")")
        return (x == 0) ? this.g () : this.f (x - 1); 
    },
    g ()  { console.log ("A.g ()"); return 0; }
}
var B = {
    f (x) { console.log ("B.f (" + x + ")"); return super.f (x); }, // super here is based on the prototype chain, back to A
    g ()  { console.log ("B.g ()"); return 0; }
}
Object.setPrototypeOf(B, A);
B.f (2);
/*
B.f (2)               
A.f (2)               
B.f (1)       
A.f (1)
B.f (0)
A.f (0) 
B.g ()  
$1 ==> 0
*/
// **********
// from worsheet
function Counter () {
  this.n = 0;
}
Counter.prototype.next  = function () { 
  return this.n++; 
}
var c1 = new Counter ();
var c2 = new Counter ();
c1.next ();
c1.next ();
c2.next ();
<- 0		// c2.next() is 0, seperate from c1.next
// **********
// from worksheet
// converts java's implementation inheritance into JS prototype-based inheritance
function A () {
}
A.prototype.f  = function () { 
  console.log ("A.f ()");
}
function B () {
  A.call (this); // Call to constructor A
}
B.prototype = Object.create (A.prototype); // Creates a new object with =A.prototype= as its prototype
B.prototype.g  = function () { 
  console.log ("B.g ()");
}
var r = new A ();
var s = new B ();
r.f ();
r.g ();   // I had to delete this to run, output below
s.f ();
s.g ();
function getProps (obj) {
  var props = [];
  for (var f in obj) { 
    props.push (f); 
  }
  return props;
}
function getProps2 (obj) {
  var props = [];
  for (var f in obj) { 
    if (obj.hasOwnProperty (f)) { props.push (f); }
  }
  return props;
}
getProps (r);  // Print out properties for r (including properties in the prototype chain)
getProps2 (r); // Print out properties for r (excluding the prototype chain)
getProps (s);  // Print out properties for s (including properties in the prototype chain)
getProps2 (s); // Print out properties for s (excluding the prototype chain)
/*
A.f ()
A.f ()
B.g ()
*/