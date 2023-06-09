THE RUST PROGRAMMING BOOK and CSC-463 Safe Systems Lectures
COMPLETED SECTIONS 1, 3, 4, 5, 6, 7, 9, 10  with possible some subsections skipped
	skipped 10.1
	skipped 6.2, 6.3
	skipped 7.3, 7.4, 7.5
STOPPED AT: Error Handling 84
TAKE A SECOND LOOK AT: 10/10
Rust-By-Example: stopped at 16.2 (have not gone through the other sections)
ALSO SEE Rust Reference

GIT COMMANDS
OTHER RUST TOOLS
VSCODE RUST TASKS
COMPILE AND RUN
FIRST PROGRAM
COMMAND-LINE ARGS
CARGO
FILE MANAGEMENT
BINARY CRATE
LIBRARY CRATE AND MULTIPLE CRATES
RUST-GDB
VARIABLES
CONVERSION
DATA TYPES
STRING LITERALS
STRING
OPERATORS
TUPLES 
ARRAYS
VECTOR
STATEMENTS AND EXPRESSIONS
MATCH
FUNCTIONS
ANOYNMOUS AND CLOSURE
IF
LOOPS
MOVE/COPY TRAIT, OWNERSHIP
REFERENCE/BORROW
SLICE
STRUCT
ENUM, OPTION
TRAIT
GENERIC
ITERATOR
ERROR
MACRO
HEAP AND STACK
LIFETIMES
UNSAFE
MEMORY EXAMPLES
PRINTLN! AND DBG!
THREAD
IO LIBRARY

GIT COMMANDS    
// not rust but just a reminder of git
git add .
git commit -m "463 week 1 stuff"
git push -u origin main

OTHER RUST TOOLS
> rustup doc --help   // shows options below
> rustup doc --book   // open the book offline
> rustup doc --std     // std lib offline
> rustup doc --rust-by-example  // by example offline
> rustup doc --std slice    // specific part
> rustfmt --check src/main.rs   // will format your code the rust way, --check displays what it would look like
> rustfmt -- backup src/main.rs   // creates a backup of the src file
> rust-gdb test  // cmd line debugger, test is a binary executable, there is rust-lldb, but I couldnt get it to work

VSCODE RUST TASKS
// my custom tasks saved in .vscode > tasks in cargo package dir
ctrl + 8  // cargo build
ctrl + 9  // select task
ctrl + 0  // rerun last task
// used CodeLLDB extension for debugging saved in .vscode > launch

COMPILE AND RUN
// without cargo
> rustc main.rs   // compiles to an executable
> .\main 

FIRST PROGRAM
// main is the first code that runs in an executable file
// println! is a macro with ! indicating the macro
fn main() {   // fn declares a function
  println!("Hello World");
}

COMMAND-LINE ARGS
// command line args: executable_name Ben Harki, first arg is the executable name
// consume the iterator
// > cargo run Ben Harki  
fn main() {
  let mut args : std::env::Args = std::env::args();  // args() grabs command line args as an iterator
  if let Some(executable_name) = args.next() {  //  when .next() returns None, jumps to else, similar to while let
    println!("running {executable_name}");
    while let Some(arg) = args.next() {   // breaks on None, see LOOP
      println!("{arg}");
    }
  } 
  else {
    eprintln!("no executable name!");
  }
}


CARGO
// cargo manages rust crates: builds code, downloads libraries
// creates a new directory hello_cargo for the package and initial git repo files, unless already in a git repo
// creates a hello world main.rc file in hello_cargo\src
// cargo build, cargo run is by default in debug mode and adds debug symbols
> cargo new hello_cargo    // --vcs none  // add the flag for no version control or to change it, no flag is git by default 
> cd hello_cargo  // change to the new package
> cargo build   // compiles the src files, creates a target\debug with a ton of stuff, including the .exe
> .\target\debug\hello_cargo    // run executable
// -----
// compile and run
> cargo run    // compiles (if needed) and runs package
> cargo run --verbose   // shows what cargo does to create the overall crate
// -----
// check if it compiles
> cargo check   // makes sure it compiles, but does not produce executable
// -----
// create a release build with optimizations added, executable saved in target\release
// --release removes debug symbols
> cargo build -- release
> cargo run --release   // compiles if necessary and runs the release executable
// -----
// removes the target dir and binaries
> cargo clean
// -----
// if the src/bin folder has multiple .rs files, choose one with --bin, should store binary in target 
> cargo run --bin lang-loop    // lang-loop.rs has main(), run in crate's cargo outer dir
// -----
// add in 3rd-party crate tui-rs to my_crate
// add under [dependencies] in my_crate > Cargo.toml:
tui = "0.17.0"    // version number 
// add in use::tui::*  in my_crate's main.rs file
> cargo build   // in my_crate directory
// now the 3rd party source code is in .cargo/git/checkouts/tui...

FILE MANAGEMENT
// prelude is the set of items that Rust brings into scope from its standard library for every program
// need a use when the library is not included in the prelude
use std::io  // brings standard lib > io library into scope, by its "path"
// -----
// packages can contain multiple binary crates and exactly one library crate
// can extract parts into seperate crates, that become external dependencies
// workspaces are for very large projects that are composed of interrelatted packages
// -----
// module system:
// 		packages: build, test, and share crates
// 		crates: tree of modules that produce executables
//    modules and use: let you control the organization, scope and privacy of paths
//    path: way of naming a stuct, function, module, etc.
// -----
// crate is the smallest amount of code the compiler considers at a time: 
//   contains modules, modules could be found in other files, that get compiled with the crate
//   can be binary: compiled to an exec, must have a main 
//   can be library: no main and don't compile to an exec, define functionality shared with multiple projects
// -----
// packages contain crates with a common functionality
//   contain a Cargo.toml file describing how to build those crates
// 	 src/main.rs is the crate root of a binary crate with the same name as the package
// 	 src/lib.rs is the crate root of the library crate with the same name as the package
// 	 both are built by Cargo
// 	 can have src/bin folder containing multiple seperate binary crates (but only one lib crate), see above
// -----
// rust compiler first looks in the crate root for code to compile: 
// 		either src/main.rs for a binary crate or src/lib.rs for a library crate 

BINARY CRATE
// these examples are of one binary crate with only one main.rs
//    however if there are more binary crates in a package, like inside src/bin/, you need to further "scope" to it
mod first_lvl;   // module declaration
// modules can be declared inline inside the main.rs file, see src/main.rs for inline_mod module	
// modules can be declared in seperate file, see src/sepr_file.rs for sepr_file module
// modules can also be declared in a seperate folder, see src/first_lvl/mod.rs for first_lvl module
// -----
// can declare submodule in any file other than the root, like in a parent module:   
// 		inline in a parent module within brackets (similar to inline_mod, not shown)
// 		in seperate file in parent's folder (not shown)
//				add mod declaration in parent_module/mod.rs
// 		in seperate folder, in its own subfolder inside parent module folder, see src/first_lvl/sec_lvl/mod.rs
//    		add mod declaration in first_lvl/mod.rs
// -----
// pub keywork for module, see file_mgmt/src/first_lvl/mod.rs
pub mod sec_lvl;   // pub is used to enable visibility to all modules outside the parent in the crate, now main call from it
// pub keyword for code, see file_mgmt/src/first_lvl/sec_lvl/mod.rs:
pub fn pr_sec_lvl() {...}   // code must be made public to be called outside of its own module file, even for the parent to call it
// -----
// see paths to modules or other code in file_mgmt/src/main.rs
// use keyword allows shortcuts to code (within module decl scope) to reduce repetition in long paths, when the code is being called
// see use keyword in main.rs:
	use first_lvl::sec_lvl::*;   // allows main to call pr_sec_lvl() in sec_lvl scope, brings in whole module
  use first_lvl::sec_lvl::pr_sec_lvl;  // brings in only the one function
// -----
// multiple modules:
use std::io::{self, Read, Error};

LIBRARY CRATE AND MULTIPLE CRATES
// packages can contain exacly one lib.rs and multiple binary crates (each with a main.rs)
// creates a package with a library crate, that begins as a src/lib.rs file, no main.rs file:
> cargo new package_of_crates --lib   // will add a default library crate, starting as src/lib.rs file
// however you can add a binary crate by adding a src/main.rs in the package
// 		or more than one crate by adding src/bin folder, that con contain folders of crates
// ----
// crate1 is found in src/bin/crate1, and run in:
> cargo run --bin crate1   // can call code from src/lib.rs see src/crate1/main.rs
// crate2 is found in src/bin/crate1, and run in:
> cargo run --bin crate2  // can call code from src/lib.rs see src/crate2/main.rs

RUST-GDB
// in outer carg dir:
> cargo build
// in ./target/debug
> rust-gdb rust_test   // name of the executable
// -----
// commands in (gdb):
// ctrl-p is previous command
// see vector example
(gdb) l (list code), b, r, c, n, s, i (info), f (frame), d (del), p (print), x (examine)   // debugging commands
// print and examine formatting:
(gdb) p/x v, (gdb) p/c v, (gdb) x/s &v, (gdb) x/d &v  // print/examine contents as hex, char, string, decimal
(gdb) tui e   // enablses the source-code inspector
(gdb) p var   // prints value of var  
(gdb) p &var  // prints where var is stored in memory (location of the ref variable itself)
(gdb) x &var  // examine memory at &var's location (ref's value), show's pointer that holds another loc
// -----
// memory is displayed in little endian, using x, gdb gives:
// location: c0 9b 5a 55 55 55 00 00 
// this is the value 0x00005555555a9bc0, which could be an address to somewhere else
(gdb) x/24bx &var // shows 24 bytes of values in memory location held by the ref in hex 
(gdb) x/24b &var   // by default its in hex


VARIABLES
// declare variables using let
// they are immutable by default, mut keyword makes them mutable
fn main() {
  let a = 10;   // immutable
  // a = 11;    // will not compile
  println!("a = {a}");
  let mut b = 100;   
  b = 101;      // has to be assigned something of the type same
  println!("b = {b}");
}
// -----
// const are immutable values, can be constant expressions
// u32 is an unsigned 32-bit integer
fn main() {
  const NUM:u32 = 100 * 5;
  println!("{NUM}");
}
// -----
// shadowing, x is shadowing the previous x in the inner scope
// all vars here are immutable
fn main() {
  let x = 3;
  println!("{x}");    // 3
	{ 
		let x = "Ben";  // can be of a different type
		println!("{x}");    // 4
	}
  println!("{x}");   // 3
}
// -----
// static variables have a static lifetime and represent a precise location in memory
// all references to statics refer to the same location
// statics can be mutable
// consts are never mutable
#[derive(Debug)]
struct MyInt {
  i:i32
}
const c:MyInt = MyInt {i:1}; 
static mut x:MyInt = MyInt{i:100};  // reading or writing a static variable is unsafe

fn see_globals() {
  println!("{:?}", c);
  // println!("{:?}", x);   // even reading static mut are unsafe
  unsafe{println!("{:?}", x)};  // can read it if its in an unsafe block
}
fn main() {
  unsafe{x = MyInt{i:101}};
  see_globals();
  // c = MyInt{i:2};   consts are read only
  // x = MyInt{i:101};   // unsafe, even for static 
}

CONVERSION
// use as or .into to convert primitive types
fn main() {
  let a : i8 = -128;
  // let b : i32 = a; // FAILS
  let c : i32 = a as i32;    // convert/cast to type
  let d : i32 = a.into ();   // also converts/casts
  dbg!(c);
  dbg!(d);
}
// -----
// as allows truncation, .into does not()
// .into does not allow a larger type convert to a smaller type
fn main () {
  let a:i32 = -2000;
  dbg!(a);
  let b:i8 = a as i8;   // truncates when converting into a smaller number
  dbg!(b);
  // let c : i8 = a.into(); // FAILS using .into() conversion from bigger to smaller
}
// -----
// rust will implicitly convert &String to &str, &[u32;5] to &[u32] (arrays to slices)  
// in other words it auto-converts dyn allc types to slices  
// see STRING, ARRAY


DATA TYPES
// integers: u8 is of size 8-bits, etc.
// debug throws a panic on overflow, permitted on --release
// overflow will throw a runtime error (panic) if in debug mode, does wrap around
u8, u16, u32, u64, u128 // unsigned
i8, i16, i32, i64, i128
isize, usize // integers, size of machine word for pointers, that are dependent on the computer archetecture, 64-bit or 32-bit
// floats:
f32, f64
// bool, 1 byte in size:
true, false
let x:bool = true;
// char's are 4 bytes (not bits) in size:
let c:char = 'a';
()  // unit type, size of zero
// Option<T> type, see ENUM
let x:Option<i32> = Some(10);
let n:Option<i32> = None;
// -----
// declaration of a variable with its type
// u32 is unsigned 32-bit integer, i32 is signed 32-bit integer
fn main() {
  let x:u32 = 100;
  println!("{x}");    // this is ok for std types, need println!("{}", obj), see PRINTLN!
}
// -----
// number formats
// decimal, hex, octal, binary, byte
1_000, 0xff, 0o77, 0b1111_0000, b'a'
// -----
// size_of function in package std::mem
// returns the number of bytes of a value of the type
// accounts for alignmnent: address of a type need to be divisible by the size of the type
// (x:i16, y:i32):       x x . . y y y y   (. are unused bytes)                       
fn main() {
  dbg!(std::mem::size_of::<i32>());   // 4
	dbg!(std::mem::size_of::<[i32; 5]>());   // 5 * 4 = 20, fixed array of 5 i32's
	dbg!(std::mem::size_of::<Vec<i32>>());  // always 24 bytes, bc its a  the fat pointer
	dbg!(std::mem::size_of::<&Vec<i32>>());  // 8 bytes, only ta raw pointer (value is an addr that holds fat pointer)
	dbg!(std::mem::size_of::<&[i32]>());   // 16 bytes: pointer + length of slice aka fat pointer
	dbg!(std::mem::size_of::<&str>());  // 16 bytes: pointer + length
	dbg!(std::mem::size_of::<Option<i32>>()); // 8 bytes, adds extra 32 bits info if None or Some from option, SEE MEMORY EXAMPLE
	dbg!(std::mem::size_of::<Box<i32>>());  // Box pointers are 8 bytes
	dbg!(std::mem::size_of::<Rc<i32>>());  // reference count pointer is 8 bytes
	dbg!(std::mem::size_of::<Option<Box<i32>>>());  // no extra information inside an Option<Box<>>
}
// -----
// example of type keyword, define type variables for long types, like a type alias
fn main() {
	type MyType<'a> = &'a mut[Vec<&'a str>; 1];
  let a:MyType = &mut [vec!["Ben"]];
  a[0] = vec!["Harki"];  // bc its mutable
  println!("{:?}", a);
}
// -----
// print_type_of function using: std::any::type_name::<T>()
fn print_type_of<T>(msg:&str, _:T) {
  println!("type of {}: {}", msg, std::any::type_name::<T> ());
}
fn main () {
  let v:Vec<i32> = Vec::from_iter(0..=10);
  print_type_of("v", v);
}

STRING LITERALS
// string literals are immutable, different from String type, 
// can use \, \n, other common escape sequences
// they are also slices, see SLICE
// str = [u8], str slice is like a slice of unsigned 8-bit ints  // &str = &[u8], & adds size of slice in ref value
// &str is a fat pointer, contains addr and size, can only access with a reference &str, never str
// &str is a reference to a slice of char-valid UTF-8's
// 		so you don't own it, only borrow (doesn't drop in out of scope, can't modify) 
// println!() macro needs a string literal as the first arg for formatting
// .as_bytes() returns the byte value of each character
fn main() {
  let s:&str = "Ben Harki";    // type of s is &str, immutable ref to a slice, s pointer lives on stack, string value neither heap nor stack
  println!("{s}");
  println!("{}", s);   // another use of the macro
  let bytes:&[u8] = s.as_bytes();   
  for b in bytes {
    println!("{} : {}", b, (*b) as char);  // need *b since b is a reference to a byte, convert to a char
  }
}
// -----
// parse() interprets the &str value into another type
// _ accounts for the Error from Result<T, Error>
// will also work on String
fn main() {
  let s:&str = "10";
  let v:Result<u8, _> = s.parse();
  println!("{:?}", v);
}
// -----
// &str by default have 'static lifetime: &'static str, see LIFETIME
 
STRING
// "Ben Harki" is a string literal, s is of String type, from standard library
// string literals are immutable, Strings can be mutable
// from is a method from String namespace, grabbed by :: operator
// String  data is allocated on the heap, fat pointer on stack
// String resembles Vec<u8>: String ref has 3 64-bit vals: pointer to heap
//		capacity of buffer, length of used amt of buf
fn main() {
  let mut s = String::from("Ben Harki");   // creates a mutable String from a string literal
  println!("{s}");
  s.push_str(" and Mags Harki!");   // appends on "Ben Harki", s still points to it
  println!("{s}", s);    // macro can accept both styles of String   
}
// -----
// format! macro returns a formatted String (not a string literal)
fn main() {
  let name = String::from("Ben Harki");
  let st = format!("{}, {}", name, 37);  // returns a formatted String
  println!("{}", st);
}
// -----
// string value equality and ptr equality
// .as_bytes(), returns &[u8], slice ref, of the values of chars 
fn main () {
  let s1 : String = String::from ("some string");
  let s2 : String = String::from ("some string");
  println!("{}", s1 == s2);  // true, derefs pointer to its value
  println!("{:?}", s1.as_bytes());   
  println!("{}", std::ptr::eq(&s1, &s2));  // false, same as prev line, by reference 
}
// -----
// with_capacity(), allocates space for 16 UTF8 characters on heap
// when s is dropped the heap allocation is also freed
fn main () {
  let mut s = String::with_capacity(16);
  s.push_str("abc");   // requires arg of &str
}
// -----
// coercsion of String to &str
// coercsion in assignment, argument
// for coercsion in return type see ARRAY
// String implements DeRef trait, for this coercsion
fn read_str(s:&str) {
  println!("{}", s);
}
fn main() {
  let a:String = String::from("Ben Harki");
  let b:&str = &a;    // &String, a borrow, is coerced into &str by assignment 
  read_str(&a);  // &String coerced to &str
}
// -----
// TODO example with .len(), for the length of the string, "inherited" from [u8] slice method

OPERATORS
+, -, *, /, %   // UNFINISHED
:: 		// scoping/pathing operator
?  // error propogation
&&, ||, !  // bool logic
&, |, ^, <<, >> // bitwise

TUPLES
// tuples can live on the stack or heap, &t.0 = &t they point to the same location
// tuples can have mixed types, of fixed length
// can use pattern matching to unpack
// use . to grab elem by index
// can find location of an elem, say &t.0
fn main() {
  let t:(char, f32, i32) = ('a', 3.14, 2022);
  let (x, y, z) = t;            // unpacks to variables, can also add types like above
  println!("({x}, {y}, {z})");
  println!("{}, {}, {}", t.0, t.1, t.2);   
  let _empty = ();  // called a unit
}

ARRAYS
// arrays have a fixed length, each element must be of the same type
// allocated on the stack, can check by checking addr of entries with addr of local variables set near it
// will throw a runtime error (panic) if index is outside of declared array bounds
// use a range: for i in 0..len(arr) see LOOPS
fn main() {
  let mut arr = [0, 1, 2, 3, 4]; 
  arr[0] = 10;   // can assign an entry, if it is mut
  let arr2:[char; 3] = ['a', 'b', 'c'];   // typed and declared version 
  let arr3 = [3; 10];   // an array of 10 3's
  println!("{}", arr[0]);  // 10, access an element by index   
  println!("{}", arr.len());  // 5, length of the array
  println!("{:#p}", &arr);     // location of the array
  println!("{:#p}", &arr[0])   // same as above
}
// -----
// passes an array, to be changed, through ownership
// i in range by default is isize, may be not be 32-bit, so needs converted
fn update_array(mut b:[i32; 5]) -> [i32; 5] {
  for i in 0..(b.len()) {
    b[i] = b[i] + ((i * i) as i32);   
  }
  b
}
fn main () {
  let a = [0; 5];
  let c = update_array(a);
  for (i, n) in c.into_iter().enumerate() {
    println! ("a[{}] = {}", i, n);  // index, value
  }
}
// -----
// an array of arrays
fn main () {
  let a:[[i32; 4]; 3] = [ [1, 2, 3, 4], [ 5, 6, 7, 8 ], [ 9, 10, 11, 12 ] ];
  println!("a[2][3] = {}", a[2][3]);
  for f_l in a {
    for s_l in f_l {
      println!("{}", s_l);
    }
  }
}
// -----
// iterator over an array's values
// iterator over an array's reference's
// compiler automatically derefs, so * is not actually necessary, but it technically scorrect
fn main() {
  let arr:[i32; 5] = [10, 20, 30, 40, 50];
  for a in arr {
    println!("{}", a);
  } 
  for a in &arr {     // equivalent to .iter(), see ITERATOR
    println!("{:p} holds {}", a, *a);   // location, value
  }
}
// -----
// &mut iterator equivalent to .iter_mut() see ITERATOR
fn main() {
  let mut a:[i32;5] = [10;5];
  for e in &mut a { 
    *e += 1;  
  } 
  println!("{:?}", a);   // a's elements have changed
}
// -----
// iterate over ref's to elems, using ref to array
// can also replace array param with a slice &[u8], and still call with an &array
fn find_num_occurrence_array_ref (n:u8, arr_ref:&[u8; 10]) -> usize {
  let mut count = 0; 
  for a in arr_ref {   // a is a reference to the elems of arr_ref
    if n == *a {    // need to deref the ref of the element to access the value
      count += 1;
      // println!("{:p}", a);  this shows the locations of each elements
    }
  }
  return count;
}
fn main() {
  let array = [4,5,6,7,8,9,5,5,6,10];
  for i in 0..10 {
    let count = find_num_occurrence_array_ref(i, &array);
    println!("{i} is in array {count} times");
  }
}
// -----
// array ref is coerced to a ref to a slice
// coercsion in assignment, argument, return type
// does not work the other way around
// slice args can accept arrays vectors (if &[u8], it could accept &str, String)
fn read_slice_pass(a:&[i32]) -> &[i32] {
  println!("{:?}", a);
  a
}
fn main() {
  let a:[i32;5] = [10;5];  
  let b:&[i32] = &a;      // &[i32;5] coerced to &[i32]
  // let c:&[i32;5] = b;  // not the other way around
  read_slice_pass(&a);
} 

VECTOR
// vector is a growable array, on the heap, with push and pop
// all elements are always right next to each other in memory
// vector will allocate more than enough space, fill it when pushing new elements, 
// then reallocates everything to a bigger space when filled
// the vector reference value contains the address|capacity|size, 24 bytes
fn main () {
  let v1: Vec<i32> = vec![10, 20, 30, 40];  // typed w/generic in declaration
  println!("v1: {:?}", v1);
  let mut v2 = Vec::new();   // "empty vector"
  v2.push(10);
  println!("v2: {:?}", v2);
  v2.pop();
  println!("v2: {:?}", v2);
  println!("{}", std::mem::size_of::<Vec<i32>>());  // 24 bytes, only the pointer + data, not the allocated vals
}         
/*
(gdb) p &v1
$2 = (*mut alloc::vec::Vec<i32, alloc::alloc::Global>) 0x7fffffffdd08
(gdb) x/24bx &v1   // examine the contents of the fat pointer
0x7fffffffdd08: 0xa0    0x9b    0x5a    0x55    0x55    0x55    0x00    0x00   // heap location
0x7fffffffdd10: 0x04    0x00    0x00    0x00    0x00    0x00    0x00    0x00  // capacity
0x7fffffffdd18: 0x04    0x00    0x00    0x00    0x00    0x00    0x00    0x00  // size
(gdb) x/16bx 0x00005555555a9ba0 
0x5555555a9ba0: 0x0a    0x00    0x00    0x00    0x14    0x00    0x00    0x00   // 10  20
0x5555555a9ba8: 0x1e    0x00    0x00    0x00    0x28    0x00    0x00    0x00   // 30  40
*/ 
// -----
// prints where the vec values are on the heap
// does not print the rest of the value of the ref, like capacity and size
fn main () {
  let v1: Vec<i32> = vec![10, 20, 30, 40];  // typed w/generic in declaration
  println!{"{:p}", v1.as_ptr()}  
}
// -----
// looping using .len, or an iterator
// accessing an element using index
// also has a capacity method that shows how much space is allocated, but not necessarily filled
fn main () {
  let v1:Vec<isize> = vec![10, 20, 30, 40];
  let mut i = 0;
  for i in 0..v1.len() {
    println!("{}", v1[i]);
  }
  for v in v1.iter() {  // iterator over the slice of values (Vecs can be coerced into a slice, see below)
    println!("{}", v);
  }
  println!("capacity = {}", v1.capacity());
}
// -----
// can convert (coerce) a reference to a vec to a ref to a slice (compiler does this automatically, see ARRAY)
// TODO: show this conversion happens for an argument accepting any slice, giving it a vec, array, etc.
// now you can use only slice operations, but cant change size of allocation
fn main() {
  let v:Vec<i32> = vec![0,1,2,3,4];
  let v_s:&[i32] = &v;    // vector coerced into a slice
  let vsl:&[i32] = &v[1..4];  // part of vector into a slice
  println!("{:?}", vsl);  // slice [1, 2, 3] of vector
}
// -----
// into_boxed_slice() method can turn vectors into Box ref to a slice (on heap)
// into_vec() turns a slice back into a vector
// likely does not need to reallocate space on the heap
fn main() {
  let v:Vec<i32> = vec![0,1,2,3];
  let box_sl_v:Box<[i32]> = v.into_boxed_slice();   // consumes the vector, most into methods do
  let back_to_v:Vec<i32> = box_sl_v.into_vec();    
}

STATEMENTS AND EXPRESSIONS
// statements do not return a value
// expressions evaluate to a resulting value that is returned
// calling a macro, a function, or a new scope using {} is an expression
// lvalues are called place expressions, r-values are called value expressions
// -----
// expressions do not include ending semicolons
// adding a semicolon to an expression turns it into a statement that does not return (returns ())
// let block
fn main() {
  let x = 5 + 6;   // 5 + 6 is an expression, evals to 11, while whole line is a statement
  let y = {       // expression is {} is bound to y in a statement that ends in ;
    let z = 3;
    z + 1       // no ; since it is an expression, returns z+1 to y    
  };
  println!("{y}");    // returns 4, the value of the expression
}
// -----
// if expression
fn main() {
  let i:i32 = 0;
  let res:&str = if i == 1 {"True"} else {"False"};
  println!("{}", res);   // false
}


MATCH
// _ is the wildcard, matches any value but does not bind to it
// -----
// pattern matching on tuples
// match cases has else-if independence
fn main () {
  for i in 0..100 {
    match ((i % 3), (i % 5)) {           // calcs the tuple, to match inside cases below, 
      (0, 0) => println! ("FizzBuzz"),    // if tuple is (0,0) then println!, if not, try other cases
      (0, _) => println! ("Fizz"),        // else if it matches (0, anything)
      (_, 0) => println! ("Buzz"),
      (_, _) => println! ("{}", i),      // print i if none of the above match
    }
  }
}
// -----
// Option and pattern matching
// find bigger of i32 and possible i32 (Option<i32>)
// once the first two cases are exhausted _ => a will match Some(_)
// pattern if => form 
fn max_opt(a:i32, o:Option<i32>) -> i32 {
  match o {
    None => a,     // also covered by _ => a, but written to see None
    Some(b) if b > a => b,   
    _ => a,   // wild card, matches anything, like a default case
  }
}
fn find_max(v:Vec<i32>) -> Option<i32> {
  let mut result:Option<i32> = None;  // like an empty variable initialization
  for n in v {        // if v is empty, this loop doesn't run
    result = Some(max_opt(n, result))
  }
  result
}
fn main() {
  let v = vec![10, 4, 68, 9];
  let ans = find_max(v);
  println!("{:?}", ans);  // :? debug needed since ans is a Some(int)
  println!("{:?}", find_max(vec![]));   // None
} 

FUNCTIONS
// only on stack
// simple function with two parameters
// must declare the type for the parameter
// mutable and immutable arguments
fn print_num(num1:i32, mut num2:i32) {
  // num1 += 1;   // cannot change a mutable local variable
  num2 += 1;  
  println!("{num1}, {num2}");
}
fn main() {
  print_num(100, 200);
}
// -----
// functions return the value of the last expression implicitly
// no ; indicates the line is an expression, with ; can be  a compiler error when a return type is declared
// can also use return keyword
// must declare the return type with ->
// num is immutable
//  () is the unit type, like returning nothing, cannot print
fn return_num_plus(num:i32) -> i32 {
  num + 1     
}  
fn return_num_plusplus(num:i32) -> i32 {
  return num + 2   
}
fn print_num(num:i32) -> () {  // can omit the -> ()
  println!("{num}");    // statements return (), the unit type, which is nothing
}
fn main() {
  let r = return_num_plus(100);
  print_num(r);
  println!("{}", r);   // is visible bc i32 is copied into print_num() not moved (impl Copy Trait)
  let r2 = return_num_plusplus(100);
  print_num(r2);
}
// -----
// empty function, can also accept args
// like pass in Python, allows the setup of infrastructure
fn empty(s:&str, i:i32) {}
fn main() {  
  let s:&str = "This function does nothing";
  empty(s, 100);
}
// -----
// example of .map()
// called on an iterator, adjusts the vals and prints (does not save the changes)
// .map is lazy, only calcs what it needs
// collect is needed to gather as another vector, comes from std::collections 
use std::collections::LinkedList;   // map can be used on many data structure in std lib
fn f(n : i32) -> i32 {
  n + 1
}
fn main () {
  let v : Vec<i32> = vec![1,2,3,4];
  println! ("{:?}", v.clone().into_iter().map(f).collect::<Vec<_>>());
  let res5 = LinkedList::from_iter (v.clone ().into_iter ().map (f));
  println! ("{res5:?}");
}

ANOYNMOUS AND CLOSURE
// see example of closures and their type in: Worksheet4-2-4-2
// functions can be defined in functions
// normal functions cannot see anything in its containing scope
fn f(i:&i32) {
  println!("I am {}, brought into f()", i);
  let x = 20;
  fn g() {
    println!("I'm in g()");
    // println!("{}", x);
  }
  g();  // can only be called within f scope, unless retuned by pointer
}
fn main() {
  let ten = 10; 
  dbg!(f(&ten));
} 
// -----
// functions and closures, anonynomous and named, also with .map()
// closures allow you to capture the state it sits in, x is in closure's containing scope
// closures have unique types that cannot be written out, but they can be coerced into typed functions
// x cannot be mutated during a borrow (x in outer scope is borrowed by f closure)
fn accept_anonym(f:fn(i32)->i32) {
  f(20);
}
fn main () {
  // normal function:
  fn g(i:i32) -> i32 {i}  // normal function definition
  let h:fn(i32)->i32 = g;  // function obj assigned to another variable, typed
  println!("{}", g(10));
  // closure:
  accept_anonym(|y| y-50);  // anonym closure as as an arg, coerced into a fn
  let mut x : i32 = 5;
  let f = |y : i32| -> i32 {   // anonymous closure assigned to a variable (cannot be typed, bc it has unique type)
    x + y   // can see the x in f's containting scope
  };
  // x = x + 1;  // mutation is not allowed because x is borrowed by f
  println!("{}", x);   // it is still readable when f borrows it
  println!("{}", f(3));  // can call f like a function
  let k:fn(i32)->i32 = |x:i32| x*x;   // closure is coerced to a function by compiler
  println!("{}", k(3));
  // .map() 
	let v:Vec<i32> = vec![1,2,3];
  println!("{:?}", Vec::from_iter(v.clone().into_iter().map(f))); // accepting a named closure (needs cloned bc it consumes v)
  println!("{:?}", Vec::from_iter (v.into_iter().map(|z| z-2*z)))  // accepting an anoynm closure
}
// -----
// Cells allow mutation of x, after it is borrowed by a closure
// Cells have a get() and set() methods
use std::cell::Cell;
fn main() {
  let x : Cell<i32> = Cell::new (5);
  let f = |y : i32| -> i32 { 
    x.get() + y
  };
  x.set(x.get() + 1);
  println!("{:?}", x);
}
// -----
// map accepting a closure (anonymous function with outer scope state) as an argument
// closure parameter in |s|, body is s.len()
// map consumes the Option, if &Option it would still deref to Option and consume it
// TODO: Result<T,E> also has .map(), do a similar example
fn main () {
  let o:Option<&str> = Some("Ben Harki");
  let sz:Option<usize> = o.map(|s| s.len());
  println!("{:?}", sz);   // Some(9) chars
}


IF
// if - else if - else, only picks one path, even if conditions are true for more than one
// if - else if's should generally be mutually exclusive
// condition needs to eval to a bool, cannot be a 0 or 1 like C
fn main() {
  let i:i32 = 0;
  if i > 0 {   // can use parens on the condition, but gives a warning
    println!("positive");
  }
  else if i < 0 {
    println!("negative");
  }
  else {
    println!("zero");
  }
}
// -----
// if as an expression, it returns a value, assigned to a variable, see EXPRESSION
// each branch must return of the same type or a compiler error is thrown
fn main() {
  let i:i32 = 0;
  let if_zero = 
    if i == 0 {"zero"}
    else {"non-zero"};   // if expression in an assignment makes a statement
  println!("{if_zero}");
}
// -----
// if let jumps to else on None, extracts from Some, like a match
// similar to while let, see LOOP
fn main() {
  let arr = [Some(0), Some(1), None];
  let mut i = 0;
  loop {  
    if let Some(num) = arr[i] {
      println!("{num}");
      i += 1;
    } 
    else { 
      break;
    }
  }
}
// -----
// TODO: example of if let Ok(n) = ... for Result<n,E>, similar to the if let Option

LOOPS
// traditinal loop with a break and continue and normal usage of ;
// break stops the loop, continue skips the current iteration
fn main() {
  let mut i = 0;
  const N:i32 = 10;
  loop {
    if i == N {break;}   // break returns (), like any statement, so could omit ;
    else if i == 3 {  
      i += 1;
      continue;
    }
    println!("{i}");   // skips 3
    i += 1;
  }   // no ;
}
// -----
// loops are expressions (along with if), in a let it becomes a statement
// break expresion returns (), break i stops the loop but returns i expression 
fn main() {
  let mut i:i32 = 0;
  const N:i32 = 10;
  let my_loop:i32 =   
    loop {
      if i == N {break i}   
      println!("{i}");
      i += 1             // the last value of i (or any expression) is returned and assigned to my_loop
    };   // with ;
  println!("my_loop = {my_loop}");  // loop above executes regardless of whether this is here
}
// -----
// labeled loops
// normally continue and break applies to the inner-most loop
// can use labeled loops to allow continue and break to apply to higher outer loop 
fn main() {
  let mut i = 0; 
  'outer: loop {
    let mut j = 0;
    loop {
      if j == 10 {break}  // breaks the inner most loop
      if i == 5 && j == 5 {break 'outer}   // breaks out of the outer loop
      println!("({i}, {j})");
      j += 1
    }
    i += 1
  }
  println!("outer loop exited");
}
// -----
// while loop, iterating over an array
fn main() {
  let mut i = 0;
  let list1 = [0, 1, 2, 3, 4];
  while i < 5 {
    println!("{}", list1[i]);
    i += 1
  }
}
// -----
// for loop, independent of indices and size of the array
// for loops, like or each loops, are better optimized 
// another for loop using a range 5..10 (from standard lib), includes 5 not the 10
// can loop using iterators and enumerate(),  for (i, n) in arr1.iter().enumerate()
// see ARRAY for in &arr, for over references
fn main() {
  let arr1 = [0, 1, 2, 3, 4];
  for a in arr1 {     // best optimized
    println!("{a}");
  }
	for i in 0..(arr1.len()) {  // using the len() method in an array
		println!("{}", arr1[i]);
	}
  for i in 5..10 {
    println!("{i}");
  }
  for i in 5..=10 {   // includes the last value
    println!("{i}");
  }
}
// TODO: loops with ranges 0..10, ..10, 0.., ..=10, etc. 
// TODO: for _ in 0..3:  for an example see UNSAFE
// -----
// while let is a good replacement for loop{match s {}} 
//    when s is of Option(T): Some(T), None or Result<T, E>: Ok(T), Err(E)
// pattern match and extract, until reaching Nones
fn main() {
  let arr = [Some(0), Some(1), Some(2), Some(3), Some(4), None];
  let mut i = 0;
  while let Some(n) = arr[i] {   // extract n and breaks when hits None
    println!("{}", n);
    i += 1;
  }
}
// -----
// see ARRAY for: for (i, n) in c.into_iter().enumerate() loop
// TODO: add in an example of for in over references, SEE ARRAY



MOVE/COPY TRAIT, OWNERSHIP
// Rust uses compiler ownership rules to manage memory: each value has exactly one owner, and dropped when out of scope 
// once out of scope, Rust calls drop function, std::mem::drop(var), panic when tries to access after drop() call 
// theres a difference between dropping a value a pointer points to and the pointer itself
//		depends on the pointer: &, Box<>, Rc<> all do different things based on ownership of its value (the val it points to)
// see Drop Trait in TRAITS
// makes the need for a garbage collector unnecessary
// -----
// heap vs stack, String::from() allocates &str on the heap,its pointer saved in &String ref
// basic types live on the stack
// Rust automatically invalidates the 1st pointer that points to a heap object, when a 2nd is introduced, Box<> for example
// Rust's invalidation on new pointer (like a shallow copy) is called a move
// both i1 and i2 are valid within the whole scope, i2 is not a "move" of i1, it is a "copy" of i1, since i1 is a basic type on stack (impl Copy Trait)
// copy and move happen implicitly, through assignment
fn main() {
  let i1 = 1;
  let i2 = i1;   // deep copies value of i1 into i2, bc it is not allocated on heap, its on the stack
  let s1 = String::from("Ben Harki");
  println!("{}", s1);   // this is ok, since it is not dropped yet
  let s2 = s1;  // moves the pointer to string data on heap to s2, drops s1
  println!("{}", s2);   // s2 is now a valid pointer and owns the value, but s1 is not valid 
  // println!("{}", s1);    // will not compile, s1 is dropped
  println!("{}, {}", i1, i2);  // however both ints are still alive, since they are copies
}
// -----
// "hello" data lives on the heap, replaced by "world" on the heap, then Rust frees "Hello" by droping it
// pointer lives on the stack, contains the heap mem location it "points to"
// so no mem leaks
fn main() {
  let mut s = String::from("hello");
  s = String::from("world");
}
// -----
// clone() makes a deep copy explicitly: copies all data of one into another place in memory (in this case on the heap)
// creates another pointer on the stack, allocates a new space for char data on heap and copies to it
fn main() {
  let s1 = String::from("Ben Harki");
  let s2 = s1.clone();
	println!("{}, {}", s1, s2);
}
// -----
// some basic types implement the copy trait: all integer types, bool, floats, chars
// types with a copy trait makes a type perform a deep copy on a new assignment, it is not a "move"
// copy does not apply to types allocated on the heap
// objs of types with a copy trait are valid until the end of the scope, not invalidated like move
// cannot implement both copy and drop (deallocation from heap) or copy and move traits at the same time in a type
fn main() {
  let i = 1;
  let j = i;  // i and j are deep copies of the integers
}
// -----
// copy and move via ownership (this is not & reference borrowing, SEE REFERENCE)
// anything allocated on the heap is moved into the function, so it is immediately invalidated
fn name_age(n:String, age:i32) {
  println!("name is: {} of age {}", n, age);  // drop is called (frees heap mem) on n on scope exit, since it is on the heap
}
fn main() {
  let n = String::from("Ben Harki");
  let i:i32 = 37;
  name_age(n, i);
  // println!("{}", n);   // will not compile since n has been moved, since it is on the heap, so it is now invalid
  println!("{}", i);      // i is still valid since it has been copied
}     // i is now out of scope
// -----
// return objects with that have a move trait (aka objects on the heap)
// f1's (on heap) drop is called before main ends when it moves inside the function
// these functions must return in order to continue using the obj, (references do not require a return bc of borrowing, see REFERENCES) 
fn return_last() -> String {
  String::from("Harki")      // transfers ownership, not dangling
}
fn accept_first(f:String) -> String {
  f    
}
fn main() {
  let f1 = String::from("Ben");
  let f2 = accept_first(f1);    // f1 moves into accept_first and then moved into f2 on return
  // println!("{}", f1);      // will not compile because f1 is invalid since it was moved
  println!("{}", f2);         // f2 is valid
  let mut f3 = String::from("Mags");
  f3 = accept_first(f3);       // f3 moves into function and returned back to f3
  println!("{}", f3);
  let f4 = return_last();      // f4 now owns what was created in return_last 
  println!("{}", f4);     
}
// -----
/// accept ownership of a string via move, change its value return ownership back
fn change(mut s:String) -> String {
  s = String::from("Mags");
  s 
}
fn main() {
  let mut s = String::from("Ben Harki");
  s = change(s);
  println!("{}", s);
}
// -----
// field of a struct is moved to a main variable, so the whole obj is now invalid
// can use clone to clone the field directly, preserving x obj  
#[derive(Debug)]
struct S {
  a:String,
  b:String
}
fn main () {
  let s1:String = String::from("the");
  let s2:String = String::from("rain");
  let x:S = S {a:s1, b:s2};     // x lives on the stack
  let s3:String = x.a;    // field moved to another variable
  println!("s3 = {:?}", s3);
  // println!("x = {:?}", x);   // entire obj is now invalid
}
// -----
// use std::mem::replace to replace the field'sString with another String 
// however the obj needs to be mutable
// could also replace with None, if write S fields using Option type: a:Option<String>
#[derive(Debug)]
struct S {
  a:String,
  b:String
}
fn main () {
  let s1:String = String::from("the");
  let s2:String = String::from("rain");
  let mut x:S = S {a:s1, b:s2};  
  let s3:String = std::mem::replace(&mut x.a, String::new());  // places empty String into location
  println!("s3 = {:?}", s3);
  println!("x = {:?}", x);   // now x is valid
}
// -----
// types can implement either Copy or Move trait, this function tests whether built-in types implement Copy or Move
// Function needs_copy has a type parameter T that must implement the Copy trait (see TRAIT), but body does nothing
// Compiler rejects calls to needs_copy with argument of a type that does not implement Copy.
// custom objs via structs do not automatically impl Copy
// immutable references impl Copy, mut ref impl Move  
fn needs_copy<T:Copy> (x:T) {
}
fn main() {
  needs_copy(20 as i32);
  needs_copy([1,2,3] as [i32;3]);
  needs_copy([[1,2,3],[4,5,6]] as [[i32;3];2]);
  needs_copy((10,20) as (i32,i32));   // tuples of copy Types can be copied
  // needs_copy (vec![1,2,3] as Vec<i32>); // Vec implements Move Type
  // needs_copy (Vec::<i32>::new ());      
  // needs_copy (Vec::new () as Vec<i32>); 
  needs_copy(&[1,2,3] as &[i32;3]);  // immutable refereneces/slices implement Copy, not &mut refs
  needs_copy(&[1,2,3] as &[i32]);
  needs_copy(&vec![1,2,3] as &Vec<i32>);
  needs_copy(&vec![1,2,3] as &[i32]);
  needs_copy("hello" as &str);
  // needs_copy (String::from ("hello"));  
  // needs_copy (String::new ());          
  needs_copy(&String::from ("hello") as &String);
  needs_copy(&String::from ("hello") as &str);
  // needs_copy (Box::new (20 as i32));    // Box heap pointers,do not impl copy because they own
  needs_copy(&Box::new (20 as i32));
}
// TODO: add an example with needs_copy(x:&mut T) to see that it would impl Move and not Copy

REFERENCE/BORROW
// "faster" than transferring ownership: reference is fixed on a pointer, changing ownership moves the pointer to a new owner
// using a reference, so the function can "borrow" the object without needing to return to transfer ownership
// references are guaranteed to point to valid data, valid until they are not used anymore in the program
// an immutable reference (aka shared ref) means that the value of the obj the ref points to cannot be changed 
// a mutable reference (aka exclusive ref) means that the value of the obj the ref points to can be changed 
// compiler will catch dangling references: makes sure data dies and does not go out of scope/dropped before the reference
// however the reference itself can be dropped and the obj can still live
// -----
// reference and dereference, dereference redirects to its value
// can deref to read it's value or both read and write if the ref is mut
// for immutable version (but no write) remove mut
// Rust has auto-referencing and dereferencing, also see an example in STRUCT
// can also do a similar example with &mut &mut x double reference
// SEE MEMORY EXAMPLE for memory read-out of &x and &&x in rust-gdb
fn main() {
  let mut x:i32 = 100;        // x is declared mutable
  let xref:&mut i32 = &mut x;  // xref is a mutable ref (can write to x through it)
  // let xref = &mut x;    // can leave off the type on the variable
  println!("{}", xref);
  println!("{}", *xref);   // deref for value, but above line is also ok due to auto-deref
  *xref = 200;             // write to x, through the mut ref
  println!("{}", *xref);
	let xrefref:&&mut i32 = &xref;   //  let xrefref = &&mut x could take a different reference to a different reference via temp references
  println!("{}", **xrefref);  // double deref, directly to value
  println!("{}", xrefref);   // same value as above, due to print's autoderef
}
// label:      x       &x         &(&x)   |   xref   *xref  xrefref  *xrefxref  **xrefxref        
// value:     100  <-  0xA    <-  0xBA    |   0xA     100   0xBA        0xA     100
// location:  0xA      0xBA       0xCBA   |   0xBA          0xCBA
// (note: *&x = 100)
// ----- 
// objs with the Move trait: moving something with a reference makes the reference invalid
// also cannot move via the reference itself
// however objs with the copy trait allow the reference to live
// same idea applies to a mut obj with mut&
fn main () {
  let s = String::from("Ben");   // s is a fat pointer, holds the heap location of &str, capacity size 
  let sref:&String = &s;        // sref holds the location of s
  let t:String = s;  
  // println!("{}", sref);  // s has been moved you can't access it via its ref
  // let t2:String = *sref;
  let x:i32 = 10;
  let y:i32 = *&x;  // allows the copy of x via deref of its ref
}
// -----
// objs with move trait will immediately drop unneeded reference to allow move
// same thing happens in above example, basically its the exact same example, but highlights droppiing of the ref
// non-linear lifetime of the ref
fn main () {
  let s:String = String::from("hello");
  let sref:&String = &s;
  // xref is no longer needed, so can be dropped, and the borrow of s ends.
  let t:String = t;  // // Now x can be moved.
}
// -----
// objs that implement move: can't move while still using a reference
// also the same example, with an added read on sref after the move
fn main () {
  let s:String = String::from("hello");
  let sref:&String = &s;
  // let z:String = x;  // Move of x fails because it is still borrowed because of xref usage below
  println!("sref = {:p}", sref);
}

// -----
// look at the location held by the reference using {:p}
// deref and & operators
// better example in MEMORY EXAMPLE, with &x and &&x
fn main() {
  let x:i32 = 150;
  let xref:&i32 = &x;
  println!("{} is in {:p}", *xref, xref); // using the ref
  println!("{} is in {:p}", *&x, &x);   // using &
}
// -----
// you cannot modify inside a function that accepts an immutable reference (they are immutable by default)
fn find_length(s:&String) -> usize {   
  s.len()    // calls a &str/&[u8] method, returns the length and does not need to transfer ownership to keep object alive
}            // s is now out of scope, but since it is a reference, it is not dropped
// fn cant_modify(s:&String) {       // you can't even write the function without a compiler error
//   s.push_str(" and Mags Harki!");   // attempt to modify, but can't
// }
fn modify(s:&mut String) {    // need a mut ref to be able to modify     
  s.push_str(" and Finn Harki!"); 
}
fn main() {
  let a = String::from("Ben Harki");    // by default a is immutable 
  let l = find_length(&a);    // accepts the ref of a by borrowing   
  println!("{l}");
  println!("{}", a);   // since a is borrowed, it is still valid after the function call
  let mut b = String::from("Mags Harki");
  modify(&mut b);   // b needs to be declared mut
  println!("{}", b);   // autoderefs, see next example
}
// -----
// mutable or immutable objs with mutable or immutable references cases
// when they are valid and how many, and at what order (only the last one declared for mut & case, any number for &)
// in general: you can have only one mutable ref (only ever to a mutable obj) or any number of immutable references
//			// once a mutable reference is introduced (only possible for a mut obj) then only the newest immutable or mutable reference is valid
// can only have one mutable reference to a mut obj at a time, in same scope, prevents data race at compile time
// a data race: two or more refs access same data at the same time, at least one is writing, no data sync mechanism
// for mut obj with 2 mixed refs, basically only one mutable ref is valid (last one) and mutable objs can have more than one immutable ref
// immutable objects can never have mutable refs,  immutable objs can have more than one immutable ref
fn main() {
  let mut a = String::from("a");
  let aref = &mut a;
  let aref2 = &mut a;    // invalidates the prev ref  
  // println!("{}", aref); // compiler error: cannot borrow mutable more than once
  println!("{}", aref2);  
  *aref2 = String::from('b');  // can mutate 
  // ----
  let mut c = String::from("c");
  let cref = &c;
  let cref2 = &mut c;    // invalidates the above ref
  // println!("{}", cref);   // compiler error: cannot borrow mutable, bc it was already borrowed immut
  println!("{}", cref2);     
  *cref2 = String::from("cc");  // can mutate
  // ---
  let mut e = String::from("e");   
  let eref = &mut e;
  let eref2 = &e;        // invalidates the above ref
  // println!("{}", eref);   // compiler error: cannot borrow immutable, since already borrowed mutable
  println!("{}", eref2);    
  // *eref2 = String::from("ee");  // cannot mutate bc the ref is immutable
  // ----
  let mut f = String::from("f");   // now mutable
  let fref = &f;
  let fref2 = &f;    
  println!("{}", fref);    // both compile   
  println!("{}", fref2); 
  // *fref2 = String::from("ee");  // cannot mutate bc the ref is immutable
  // ---- 
  let b = String::from("b");  // now immutable
  // let bref = &mut b;       // compiler error cannot borrow as mutable
  // ----
  let d = String::from("d");   // also immutable
  let dref = &d;
  let dref2 = &d;    
  println!("{}", dref);    // both compile   
  println!("{}", dref2);     
  // *dref2 = String::from("ee");  // cannot mutate bc the ref is immutable
}
// -----
// immutable and mutable variables holding immutable/mutable references
// this is not the difference between mutable vs immutable referencee, SEE ABOVE
// this is only the case with mutable obj 
// last 4 lines fail with immutable String objs, since they cannot have mut refs
// be mindful that these ref variables are subject to ownership rules
fn main() {
  let mut ms = String::from("Ben Harki");
  let mut ms2 = String::from("Mags Harki");
  // -----
  let imm_var_ms = &ms;      // immutable variable to a mutable object that has an immutable ref
  // imm_var_ms = &ms2;      // does not compile since the variable is immutable
  let mut mut_var_ms = &ms;  // mutable variable to a mutable object that has an immutable ref
  mut_var_ms = &ms2;         // ok since the variable is mutable
  // -----
  let imm_var_ms_mut = &mut ms;      // immutable variable to a mutable object that has a mutable ref
  // imm_var_ms_mut = &mut ms2;      // does not compile since the variable is immutable
  let mut mut_var_ms_mut = &mut ms;  // mutable variable to a mutable obj that has a mutable ref
  mut_var_ms_mut = &mut ms2;         // ok since the variable is mutable
}
// -----
// compiler throws on dangling references
// fn dangler() -> &String {
//   let dangle = String::from("dangle dangle");
//   &dangle   // dangling pointer, compiler throws "there is no value for it to be borrowed from"
// }          // dangle would be dropped, so the returned reference woud be invalid
fn pass_through(p:&String) -> &String {
  p   
  // &p  is also valid, bc of auto-deference
}
fn main() {
  let s = String::from("Ben Harki");
  let sref:&String = pass_through(&s);   // &s is necessary, since the function needs a ref
  println!("{}", sref);   // prints Ben Harki, no & needed since it is already a ref
  println!("{}", &sref);  // prints Ben Harki, auto-deref
}
// -----
// .clone() (deep copy) through a reference (auto-deref) and by explicit deref
// clone is an immutable borrow, so it will invalidate a previous mutable ref
// TODO: change sref to immutable, should be able to clone, and still see the immutable ref
fn main() {
  let mut s:String = String::from("Ben");
  let sref:&mut String = &mut s;   
  let mut cl:String = (*sref).clone();   // clone value by deref
  cl = sref.clone();    // clone value by ref
  *sref = String::from("Harki");   // can modify s through sref, unless s is cloned itself
  cl = s.clone();    // immutable borrow after a mutable borrow invalidates the mutable ref
  // *sref = String::from("Harki");   // sref is now invalid, read or write
  // println!("{}", sref);    
}
// -----
// location equality vs value equality, through refs
// == auto derefs to value to compare, std::ptr::eq checks the locations they hold
fn main () {
  let x:i32 = 100;
  let y:i32 = 100;
  println!("{}", x == y);   // true, since their values are the same
  println!("{}", &x == &y);   // weirdly this is also true, same as above, since == auto-dereferences to the value it points to
  println!("{}", *&x == *&y);  // also true, explicit dereference to value
  println!("{}", std::ptr::eq(&x, &y));  // false, checks the locations the refs hold
}
// -----
// r is not alive until assigned
// the reference can only live as long as the value it points
fn main () {
  let r:&i32;  // allows r to be visibile in this outer scope, but only lives as long as x   
  {
    let x:i32 = 10;
    r = &x;  // OK because x is in scope
    println!("{r}"); 
  }  // x is now out of scope 
  // println!("{r}");    // compiler error, bc x does not live, so r is not valid
}
// -----
// can look at an address of an r-value expression 
// C++ does not allow this bc it only allows the address of an l-value
// can also modify the temp location
fn main() {
  let x:i32 = 10;
  let y:i32 = 20;
  let r:&mut i32 = &mut (x + y);
  *r = 50;
  println!("r lives in  {:#p}", &r);
  println!("r ref holds the locations  {:#p}", r);
	println!("r points to the value {}", *r);
}
// -----
// C-style const* and pointer arithmetic: see UNSAFE


SLICE
// slices refers to a contiguous region of memory: could be array, vector, String, string literal, etc
// ex: [i32] is a slice, &[i32] is a ref to a slice (usually just say &[i32] is a slice)
// references to slices are fat pointers and store: 
//   location they point to (8 bytes) and the length of slice (8 bytes) = 16 bytes
// ex: &[i32] could be a slice (ref to a slice) for an array, or vector, or whatever 
// TODO: can use a slice ref as an arg to accept vectors or arrays, also .reverse() in place
//		I did one, see TUPLES/ARRAYS
// -----
// &str is the type for a slice of a string, string literals are slices
// slices like &str, &[i8] are sometimes called a Dynamically Sized Type, DST
// use ranges to designate where in the object to point to, see LOOP for range examples
// String ref is coerced into a &str
// not fixed at compile time, can only reach via pointer, &[i8], it knows the size of the slice in ref value
// see LIFETIME for: fn f() -> &'static str   
fn last(s:&String) -> &str {
  &s[4..]       // can drop the end number to indicate 4 to the end of the String
}
fn pass_first(f:&str) -> &str {    // can accept string literals directly
  f
}
fn main() {
  let s = String::from("Ben Harki");
  let ben_ref:&str = &s[..3];    // can drop the starting index to indicate starting at beginning
  let ben_ref2 = pass_first(ben_ref);
  println!("{}", ben_ref2);
  let harki_ref:&str = last(&s);  // &String coerced to &str
  println!("{}", harki_ref);
  let str_lit = "Mags Harki";    // string literal, not a String
  let fst = pass_first(str_lit);  // str_lit is a by default an &str, do not need &   
  println!("{}", fst) 
}
// -----
// array slices, defining a new one and picking one from an array
// slice reference's type is &[32], slice type is [i32], a slice containing i32s
// arrays are also slices, array type is [i32:size]
// example of &mut[i32], mutable ref to a slice
fn main() {
  let mut arr:[i32; 5] = [0, 1, 2, 3, 4];
  let arr_sl:&mut[i32] = &mut arr[0..3];   // mutable reference to a slice, using ranges
  let arr_sl_eq = &[0, 1, 2];   // reference to this specific array 
  println!("{:?} {:?}", arr_sl, arr_sl_eq);  // they equal in array value
  for i in 0..arr_sl.len() {    // or using arr_sl[i]
    arr_sl[i] = 100;           // can modify via slice ref
    println!("{}", arr_sl[i]);  // all 100's now
  }
  println!("{:?}", arr);  // shows that the elems in full array change
}
// -----
// TODO: example with Box<[i32]>, a box reference to a slice, does own data, unlike &[i32]
//   see example in VECTOR 
// TODO: Rc<[T]> is a reference counting pointer to a slice 

STRUCT
// structs bundle data like a simple class
// uses commas to seperate fields
// use key value pairs to initialize, pairs can be in any order
// -----
// classical example with a constructor (a lot of times std lib uses new(), here its birth())
// methods implicitly borrow "self" object
// can call a method as a function, show explicit borrow using ref
// allocate a Person on the heap using Box<> reference, TODO: also RC<>
// &self is short for self: &Self (Self = Person)
#[derive(Debug)]
struct Person {
  name:String,
  age:u32
}
impl Person {
  fn birth(name:String) -> Self {  // could call this new(), new is not a keyword
    Person{name:name, age:0}
  }
  fn grow_older(&mut self, years:u32) {   
    self.age = self.age + years;
  }
}
fn main() {
  let mut p = Person::birth(String::from ("alice"));
  p.grow_older (2);               // implicit borrow of p
  Person::grow_older(&mut p, 3); // explicit borrow of p
	println!("{p:?}");
	let mut q:Box<Person> = Box::new(Person::birth(String::from("alice")));
	Person::grow_older(&mut *q, 3);   // q contains the heap address, so deref to access Person value
}
// -----
// immutable and mutable declared objects: either all fields cannot be written to or they all can
// struct objs will own the its fields and the data they could point to via move, through ownership tree
// 		fields and their pointers will be moved to the heap, with the obj root pointer on the stack
// the fields are private by default, so if main() is defined in the same module, main() can read/write
// create_person() is a constructor, but not a part of the class's impl methods/functions
struct Person {
  name: String,
  age: i32
}
fn create_person(_name:String, _age:i32) -> Person {  // can use param names that are the same as the field names
  Person {name : _name, age: _age}    // implicitly returns an obj, transfers ownership
}
fn create_person_shorthand(name:String, age:i32) -> Person {
  Person {name, age}    // shorthand to avoid redunant varable names
}
fn main() {             
  let ben = Person {
    name: String::from("Ben Harki"),
    age: 37};
  let mut mags = Person {
    name: String::from("Mags Harki"),
    age: 35};
  // ben.name = String::from("Ben");    // ben is immutable
  mags.name = String::from("Mags");    // ok since it is mutable
  println!("{}", ben.name);
  println!("{}", mags.age);
  let adam = create_person(String::from("Adam Harki"), 42);   // adam accepts ownership of returned obj 
  let finn = create_person_shorthand(String::from("Finnegan Harki"), 2);
  println!("{}", finn.name);  
}
// -----
// String is moved, since it is an object, but i32 is copied since it is an integer type via copy trait
// old objects are invalid if at least one field has been moved
struct Person {
  name: String,
  age: i32
}
fn create_person(name:String, age:i32) -> Person {
  Person {name, age}   
}
fn main() {
  let ben = create_person(String::from("Ben Harki"), 38);   // ben accepts ownership of returned obj 
  let shallow_ben = Person {name: ben.name, age: ben.age};   // ben is now invalid
  let shallow_ben2 = Person {..shallow_ben};                 // easier syntax, any new field data needs created before ..shallow_ben
}
// -----
// default print formats of structs
// implements the Debug trait for the struct via #derive attribute
// {:?} can be used to display all the fields of a struct
// dbg!()  prints to stderr console stream, println! prints to stdout console output
#[derive(Debug)]    // derive is an attribute, Debug is a trait
struct Person {
  name: String,
  age: i32
}
fn create_person(name:String, age:i32) -> Person {
  Person {name, age}   
}
fn main() {
  let ben = create_person(String::from("Ben Harki"), 37);
  println!("ben = {:?}", ben);
  println!("ben = {:#?}", ben);  // better format for structs with more fields
  let x = 10;
  dbg!(x * 30);    // prints line number and x * 30 = 300
  dbg!(&ben);   // dbg needs a ref so it doesn't consume it, prints similar to {:#?}
}
// -----
// methods must be added in impl blocks, can add more than one method in one block, and more than one impl block for a struct
// &self is short for self: &Self, Self is an alias for the type the impl block is for
// methods can also take ownership of self and mutably borrow self (this case immutably borrows it)
// Rust has automatic referencing and dereferencing: automatically adds &, *, or &mut to obj in obj.method
// example with calling methods, but auto-dereference occurs with fields
// example with a constuctor
struct Person {
  name: String,
  age: i32
}
impl Person {       
  fn str_person(&self) -> String {        // for more parameters, place them after &self, &self indicates a method
    format!("[name: {} age: {}]", self.name, self.age)    // transfers ownership of the formatted String via "move"
  }
  fn create_person(name:String, age:i32) -> Self {  // normal constructor(), any function in impl is an associated function
    Self {name, age}     // returns a Person
  }
}
fn main() {
  let ben = Person::create_person(String::from("Ben Harki"), 37);   // called with Person:: for associated functions
  println!("{}", ben.str_person());      // call by the owning variable
  println!("{}", (&ben).str_person());   // auto dereferencing, calls method through its reference
  let ben_ref = &ben;
  println!("{}", (*ben_ref).str_person());  // call by an explicit dereference of a reference
} 
// TODO: can also call method like: (*&ben).str_person()
// -----
// Linked List using Option<Box<>>, None is like null
// loops with pattern matching, on Option type: Some(), None
#[derive(Debug)]
struct Node {
  item:i32,
  next:Option<Box<Node>>
}
fn sum(mut list:Node) -> i32 {
  let mut result = 0;
  loop {
    result = result + list.item;   // accumulates the sum
    match list.next {  // is list.next None or Some
      None => break,
      Some(list2) => list = *list2,  // list2 binds with whatever matches in Some, increment to next Node
    }
  }
  result
}
fn main () {
  let list1:Node = Node {item:3, next:None};
  let list2:Node = Node {item:2, next:Some(Box::new(list1))};
  let list3:Node = Node {item:1, next:Some(Box::new(list2))};  // head of LL
  // list1 and list2 are now moved, invalid variables
  println!("list3 = {:#?}", list3);
  println!("sum = {}", sum(list3));
}   // drops list3 and recursively drops list2, list1 data
// -----
// impl Drop trait to see when it drops: see TRAIT
// dropping a root, drops the entire tree/ll nodes recursively
#[derive(Debug)]
struct Node {
  item:i32,
  next:Option<Box<Node>>
}
impl Drop for Node {
  fn drop(&mut self) {
    println!("dropping S {{ item : {:?}, next : {:?} }} stored at {:016p}", self.item, self.next, std::ptr::addr_of! (self));
  }
}
fn main() {
  let list1:Node = Node {item:3, next:None};
  let list2:Node = Node {item:2, next:Some(Box::new(list1))};
  let list3:Node = Node {item:1, next:Some(Box::new(list2))};  // head of LL
}
// list3 owns list1 and list2, so list1 and and2 ref's are moved out of the stack and into the heap now
// list 3 's ref is only one left the stack, points to list 2  ref on the heap, and so on
// drops list3 then list2 then list1 (in terms of their value)
// -----
// structs do not automatically implement Copy trait
// however compiler can be directed to create one
// Copy trait inherits clone trait, so you can't derive Copy without implementing Clone
#[derive(Debug)]
#[derive(Copy, Clone)]   // derives Copy and Clone, Clone impls.clone()   
struct myInt {
  i:i32  // fields need to have copy traits
}
fn main() {
  let s = myInt{i:20};
  let t = s;
  println!("{:p}", &s);  // location of pointer on stack, s is available bc it was not moved
  println!("{:p}", &t);  
}
// -----
// Linked list with Rc, shared references with count, see HEAP AND STACK
// unexpectedly and unlike &, .clone() on an Rc only duplicates the pointer, have to "manually" clone for deep copy, but does incr the ref count  SEE HEAP AND STACK
// to see how Rc and ther counts are in memory see MEMORY EXAMPLE and HEAP AND STACK
// impl Drop to see when they are dropped
// also notice the difference between dropping a value and dropping its shared ref (Rc in this case)
// TODO: similar example with regular references (borrow), using Option<&Node>: 
// None for the null pointer at the end of the list, Some(n:Node) for a Node
use std::rc::Rc;
#[derive(Debug)]
struct Node {
  item:i32,
  next:Option<Rc<Node>>,
}
impl Drop for Node {
  fn drop (&mut self) {
    println! ("dropping S {{ item : {:#?}, next : {:#?} }}", self.item, self.next) ;
  }
}
fn foo () -> Option<Rc<Node>> {
  let list1  : Option<Rc<Node>> = Some(Rc::new(Node { item : 1, next : None   }));  
  let list2  : Option<Rc<Node>> = Some(Rc::new(Node { item : 2, next : list1  }));
  let list3a : Option<Rc<Node>> = Some(Rc::new(Node { item : 3, next : list2  }));   // list3a and list3b point to a "fatter" pointer that lives the heap and contains the Rc count 
  let list3b : Option<Rc<Node>> = list3a.clone ();        // .clone called on Some(Rc), then on Rc, which clones only the pointer and incr ref count to both
  let list4  : Option<Rc<Node>> = Some(Rc::new(Node { item : 4, next : list3a }));
  let list5  : Option<Rc<Node>> = Some(Rc::new(Node { item : 5, next : list4  })); 
  // println!("{:#?}", list4);   // list3b and list5 refs are the only ones alive, because of moves
  println!("to return from foo");
  list3b     
}    
fn main () {
  let result : Option<Rc<Node>> = foo ();   // drops list5 pted val, list4 pted val, but does not drop list3 or list2 yet 
  println!("to return from main")
}   // drops value pointed in both list3a and list3b refs, then list2, then list1
// -----
// SKIPPED TUPLE STRUCTS AND UNIT-LIKE STRUCTS

ENUM, OPTION
// an enum value can only be one of its defined variants, both treated as a Switch
#[derive(Debug)]
enum Switch {
  ON,
  OFF
}
fn print_status(s:&Switch) {   // accepts either value
  println!("The switch is {:#?}", *s);
}
fn main() {
  print_status(&Switch::ON);
} 
// -----
// enums can only take on one or the other variants, but each variant can be of any type
// enums can also have methods
#[derive(Debug)]
enum Switch {
  ON(String),   // kinda like a function
  OFF(i32)
}
impl Switch {
  fn print(&self) {
    println!("{:?}", self);   // chooses the Debug format
  }
}
fn main() {
  let sw1 = Switch::ON(String::from("This is ON"));
  let sw2 = Switch::OFF(0);
  sw1.print();
  sw2.print();
} 
// -----
// Rust does not have null, but it has an Option type, ex: Option<i32> is either Some(i32) or None
// Option<T> is an enum that can take on either Some<T> or None values, T is a generic parameter
// Option<T> means it hasn't been checked, T means it has been checked and not null
// Option<T> has a lot of methods, like unwrapping to T, see documentation
fn main() {
  let n:Option<i32> = Some(3);
  let e:Option<i32> =  None;
} 
// -----
// match with Option, function with Option params returning Option, SEE MATCH
// this also propages resolving the Option to main(), then delegated out, to another function
// Option<T> can be either Some(T) or None
// None is further interpreted as -1
fn max_opt(a:Option<u32>, o:Option<u32>) -> Option<u32> {
  match a {
    Some(n1) => match o {
      Some(n2) if n1 > n2 => Some(n1), 
      _ => o,    // includes the None case, and other <= cases
      None => None  // written to explicity see it
    },
    None => None   
  }
}
fn handle(n:Option<u32>) -> i32 {
  match n {
    Some(num) => num as i32,
    None => -1     // could throw a panic here, but wanted to handle it like a try-catch
  }
}
fn main() {
  let ret1:Option<u32> = max_opt(Some(0), Some(10));
  let ret2:Option<u32> = max_opt(Some(10), Some(0));
  let ret3:Option<u32> = max_opt(Some(0), None);
  let ret4:Option<u32> = max_opt(None, Some(10));
  println!("{:?}, {:?}, {:?}, {:?}", ret1, ret2, ret3, ret4);  
  let valid1:i32 = handle(ret1);  // I want ownership here to unpack Some(n)
  let valid2:i32 = handle(ret2);
  let valid3:i32 = handle(ret3);  
  let valid4:i32 = handle(ret4);  
  println!("{valid1}, {valid2}, {valid3}, {valid4}");
}
// -----
// delegating possible None back to main(), using ? operator and chaining with other methods
// ? returns a None early from next on panic, other methods are not called
// other chained methods could also return None and have a ?, see a similar use in ERROR with Result<T, E>
fn last_char_of_first_line(text: &str) -> Option<char> {
  text.lines().next()?.chars().last()   // if the text is empty the call to next() could return None
}
fn main() {
  let s:&str = "";
  let ret:Option<char> =  last_char_of_first_line(s);
  let usable:char = match ret {
    Some(st) => st,
    None => 'n'
  };
  println!("returned: {};", usable);  // now we know it is a None
}
// -----
// .is_some() returns true if Some(n)
// .unwrap() on a None, will throw a panic, so check before
// TODO: similar example with is_none()
fn main() {
  let o:Option<String> = Some(String::from("Ben"));
  let valid = if o.is_some() {
    let s:String = o.unwrap();
    s
  } 
  else {
    String::from("RECIEVED NONE")
  };
}
// -----
// &Option<T> in a match, borrows the option rather than consuming it
// uses "match ergonomics"
// .as_ref() converts from &Option<T> to Option<&T>
// TODO: same example with Option<u8> to see that it does consume it
// TODO: an example without match ergonomics using keyword ref (Some(ref) &Some(ref)), see Error Handling > 64
fn main() {
  let o:&Option<u8> = &Some(10);
  let valid = match o {    // match will auto-deref to the Some or None value from &Option
    Some(n) => n,
    None => panic!("recieved None")
  };
  println!("{:?}", o);  // o has not been consumed
  let o1:Option<&u8> = o.as_ref();
  if o1.is_some() {
    println!("{}", *o1.unwrap());  // unwrap returns the &u8, *&u8 to u8 value
  }
}
// -----
// .or() and .and() Option<T> methods
fn main() {
  let o1:Option<u8> = Some(1);
  let o2:Option<u8> = None;
  println!("{:?}", o1.and(o2));  // None is like False
  println!("{:?}", o2.or(o1));   // Some(_) is like True
}
// -----
// Option<T> can be handled with pattern matching, see MATCH
// Option<T> method diagram see Error Handling > 68
// Result<T, E> is also an enum, handled with match, see ERROR
// while let can be used with pattern matching on Option types, see LOOP
// SKIPPED 6.2, 6.3



TRAIT
// calls a function from the trait, implemented by the concrete class
// TODO: traits can provide default definitions or be overridden
trait Create {
  fn new(name:&'static str) -> Self;  
}
struct Person {
  name:&'static str
}
impl Create for Person {
  fn new(n:&'static str) -> Self {  // or -> Person
    Person {name:n}
  }
}
fn main() {
  let p:Person = Create::new("Ben Harki");  // requires a type
}
// -----
// traits are like interfaces that types can implement
// methods declared in traits must be written inside the struct impl block
// pub indicates that other crates can use this too
// coherence or orphan rule states that we can't implement external traits on external types 
// need dyn for dynamic dispatch of specific struct at runtime, on stack, can also use Box<dyn &> for heap
pub trait Print {
  fn str_repr(&self) -> String;
}
struct Name {
  name: String
}
impl Print for Name {
  fn str_repr(&self) -> String {
    format!("{}", self.name)   // format! macro returns a String
  }
}
struct Age {
  age: i32
}
impl Print for Age {
  fn str_repr(&self) -> String {
    format!("{}", self.age)
  } 
}
fn main() {
  let ben:&dyn Print = &Name {name: String::from("Ben Harki")};  // should make a constructor
  let age:&dyn Print = &Age {age:37};
  let prints:[&dyn Print; 2] = [ben, age];
  for p in prints {
    println!("{}", p.str_repr())
  }
} 
// -----
// traits as a parameter for a function which accepts any struct that implements it
// impl trait syntax and trait bound syntax
trait Print {
  fn print(&self) -> ();
}
struct Full {
  full:String
}
impl Print for Full {
  fn print(&self) -> () {
    println!("{}", self.full);
  }
} 
struct Seperate {
  first:String,
  last:String
}
impl Print for Seperate {
  fn print(&self) -> () {
    println!("{}; {}", self.last, self.first);
  }
} 
fn call_print(p:&impl Print) {
  p.print();
}
fn main() {
  let f = Full {full: String::from("Ben Harki")};   // without a constructor
  let s = Seperate {first: String::from("Ben"), last: String::from("Harki")}; 
  call_print(&f);  // two different types of objs
  call_print(&s); 
}    
// -----
// trait bounds use an alternate generic param syntax rather than &impl param synatax 
trait Print {
  fn print(&self) -> ();
}
struct Full {
  full:String
}
impl Print for Full {
  fn print(&self) -> () {
    println!("{}", self.full);
  }
} 
fn call_print<T: Print>(p: &T) {   // <T: Print> and not &impl Print
  p.print();
}
fn main() {
  let f = Full {full: String::from("Ben Harki")};   // without a constructor
  call_print(&f);  // call_print can accept any object that impl Print Trait
}
// -----
// function returns a Print trait object, specificially a Name obj tht impl Trait
// main would not know anything about the struct Name, only that returns_Print returns a Print Trait
// can only ever return one obj that implements the returned Trait
trait Print {
  fn print(&self) -> ();
}
fn returns_print(s:String) -> impl Print {
  struct Name {name:String}
  impl Print for Name {
    fn print(&self) -> () {
      println!("{}", self.name);
    }
  }
  Name {name:s}
}
fn main() {
  let b = returns_print(String::from("Ben"));   // infered type
  b.print();
}
// -----
// same as above example, but with dynamic dispatch using dynamic allocation heap via Box<>
// type of b is known at runtime, at compile time all it knows is that it is an obj that impl Print Trait
// returns a Box pointer that points to an object that implements the trait, not necessarily a concrete obj
// dynamic dispatch in that the exact returned obj is not known until runtime
//   bc it could be any sized struct obj that implements the Trait, so the heap pointer box is sufficient for compile time

trait Print {
  fn print(&self) -> ();
}
fn returns_print(s:String) -> Box<dyn Print> {
  struct Name {name:String}  // define the struct
  impl Print for Name {
    fn print(&self) -> () {
      println!("{}", self.name);
    }
  }
  Box::new(Name {name:s})
}
fn main() {
  let b:Box<dyn Print> = returns_print(String::from("Ben"));   // infered type
  b.print();
}
// TODO: Box<dyn Trait> can also be used as field in a class, when the concrete class is not known at compile time
// -----
// manually impl Drop trait on custom struct, so see when it drop is called, similar example in STRUCT
// print line is added to the Rust drop implementation
#[derive(Debug)]
struct S {
  a:i32,
  b:i32
}
impl Drop for S {
  fn drop(&mut self) {   
    println!("dropping S {{ a : {:?}, b : {:?} }}", self.a, self.b);
  }
}
fn main() {
  let mut s = S {a:5, b:10};
  {
    let t = S {a:6, b:11};
    println!("t = {:?}", t);   // actually drops a=5 struct before moving t to s in next line
    s = t;     
    // println!("t = {:?}", t);  t is moved into s, so t id is invalid
  }
  println! ("s = {:?}", s);   // a = 6 struct from t 
}      // now drops the a=6 struct
// -----
// implement the Display trait for println! representation
use std::fmt::{Display, Result, Formatter};
struct HexArray {
  ha:[i32;3]
}
impl Display for HexArray {
  fn fmt(&self, f:&mut Formatter) -> Result {   // fmt::Result = Result<(), Error>
    // write the formatted string into a buffer, f
    write!(f, "[0x{:X}, 0x{:X}, 0x{:X}]", self.ha[0], self.ha[1], self.ha[2])
  }
}
fn main() {
  let ha:HexArray = HexArray {ha:[100;3]};
  println!("{}", ha);   // calls fmt() from Display trait
}
// -----
// derivable traits are traits automatically created by the compiler
// declared for a stuuct with:
#[derive(Clone, Copy)]
// -----
// more traits:
Eq, PartialEq, Ord, PartialOrd, Hash, Default, Debug 
// -----
// see example of Trait Bounds on generic Error parameter, see ERROR
// -----
// SKIPPED MULTIPLE TRAIT BOUNDS (ex: <T: Print + Display>)
// SKIPPED USING TRAIT BOUNDS TO CONDITIONALLY IMPLEMENT METHODS
// -----

GENERIC
// Generic trait bound
// function with generic type parameter T, accepts a T obj as long as T implements an Iterator of Strings or &str
// same as the COMMAND-LINE example, but wrapped in process() fn
fn process<T : Iterator<Item=String>> (mut args:T) {
  if let Some(executable_name) = args.next() {
    println!("running {executable_name}");
    let mut i:usize = 0;
    while let Some(arg) = args.next() {
      println!("arg {i} = {arg}");
      i = i + 1;
    }
  } 
  else {
    eprintln!("no executable name!");
  }
}
fn main () {
  let args : std::env::Args = std::env::args();  // args() returns Args obj
  process(args);
}
// -----
// generic function and method, struct with a generic field
// call a with ::<T>, however the functions/methods are too simple (everything has a location)
// if some other call is needed inside pass_through, I'll need a trait bound defined on T, see TRAIT
fn pass_through<T>(a:&T) -> &T {
  a
}
struct Container<T> {
  a:T
} 
impl<T> Container<T> {
  fn pass_through_aref(&self) -> &T {
    &self.a
  } 
} 

fn main() {
  let s:String = String::from("Ben Harki");
  let sref:&String = pass_through::<String>(&s);
  let c = Container::<&str> {a:"Ben Harki"};  // concrete definition of T, could be anything
  println!("field ref holds {:p}", c.pass_through_aref());  
  println!("field lives in {:p}", &c.pass_through_aref());  
}
// -----
// example of an Error generic parameter in ERROR, for Result<T, E>
// see example of generic lifetime parameter impl in LIFETIME

ITERATOR
// iterator for a Vector consumes the vector
// iterators expand into match on Option<T>, iterator over Some(T), break on None 
// see iterating over references of an array in ARRAY, with form: for a in &arr
// see "for in" using iterators in ARRAY
fn main() {
  let vtor:Vec<i32> = vec![0,1,2,3,4];
  for v in vtor {    
    println!("{}", v)
  }
  // println!("{:?}", vtor);  // unavailable since the vals were moved (
}
// -----
// custom Iterators must define Item and next(), when impl Iterator Trait
// can use them in for in loops
// also has Iter.take(), Iter.skip()
// return of next must be wrapped in an Option<Self::Item> type, 
  // like Some() to continue, or use None to end iteration
#[derive(Debug)]
struct Fibonacci {
  curr:u32,
  next:u32,
}
impl Iterator for Fibonacci {
  type Item = u32;
  fn next(&mut self) -> Option<Self::Item> {
    if self.next < 20 {
      let new_next = self.curr + self.next;
      self.curr = self.next;
      self.next = new_next;
      Some(self.curr)
    }
    else {
      None
    }
  }
}
fn fibonacci() -> Fibonacci {   // generator, like a default constructor
  Fibonacci { curr:0, next:1 }
}
fn main() {
  let mut f_iter = fibonacci();
  for f in &mut f_iter {    // borrows f_iter
    println!("{:?}", f);
  }
  for f in f_iter {     // for moves/consumes the f_iter
    println!("{:?}", f);   // 1, 1, 2, 3, 5, 8, 13
  }
  // println!("{:?}", f_iter);     // f_iter was consumed by prev for loop
}
// TODO: create one with a custom container like array and a custom .iter() method or seperate custom Iterator stuct for Container struct?
// -----
// slice iterator is of std::slice::Iter<T> type
// slice::iter_mut() allows mutation of array values, returns refs, (but you don't see them due to auro-deref)
// slice::iter() does not move values out of the array, also returns refs
// array::into_iter() moves values out of the array, if they impl Move Trait, 
//    aka they are on heap, like String
// String vars are fat pointers, point to values allocated on heap
// if the values in the array impl Copy, aka primitives, it will copy and not move
fn main() {
  let arr1:[String; 2] = [String::from("Ben"), String::from("Harki")];
  for a in arr1.into_iter() {
    println!("{}", a);
  }
  // println!("{:?}", arr1);  // arr1 has been moved, so this is invalid
  let arr2:[String; 2] = [String::from("Mags"), String::from("Harki")];
  for a in arr2.iter() {
    println!("{}", a);
  }
  println!("{:?}", arr2);   // not moved 
  let mut arr3:[String; 2] = [String::from("Adam"), String::from("Harki")];
  for a in (&mut arr3).iter_mut() {   // a is a ref to each element, similar to: for a in &mut arr, see ARRAY or above
    *a = String::from("XXX");   // must deref
  }
  println!("{:?}", arr3);    // not moved
}
// -----
// args() returns an iterator over the exec_name, cmd-line arg1, etc..., SEE COMMAND-LINE
// collect() gathers each element into a data structure
// > cargo run Ben Harki
fn main() {
  let args:Vec<String> = std::env::args().collect();
  println!("{:?}", args);  // ["target/debug/rust_test", "ben", "harki"]
}
// -----
// types like Vectors or Strings have an into_iter() method since they implement 
//   the IntoIterator trait, TODO: show an example for custom class impl of the Trait

ERROR
// by default panics unwind back up the stack and clean up function data by dropping vars (popping most recent from stack)
// can change this to abort, which will leave the responsibility to clean up to the OS
//		add: [profile.release] panic = 'abort' to Cargo.toml file
// -----
// example of calling panic!, unrecoverable errors
// run with RUST_BACKTRACE=non_zero to print a stack trace, must be built/run in debug
// >  RUST_BACKTRACE = 1 cargo run
fn main () {
  // panic!("custom message");  // shows 3:3, line 3, col 3
  let v = vec![1, 2, 3,];
  v[100];   // buffer overread error
}
// -----
// handle a recoverable error with Result<T, E> Enum type
// anything of a Result type is either Ok(T) or Err(E)
// warning will appear if a Result is left unhandled
use std::fs::File;
use std::io::Error;
fn main() {
  let open_ret:Result<File, Error> = File::open("does_not_exist.txt");
  let myfile:File =    // if it does not throw a panic, this block will return a File
    match open_ret {     // match on open_ret, extract either the file or error message     
      Ok(file) => file,
      Err(error) => panic!("Problem opening the file: {:?}", error)};  // breaks execution
  // now we know myfile is a valid opened file, since there is no panic if the program reaches here
  let metadata = myfile.metadata();   
}
// thread 'main' panicked at 'Problem opening the file: Os { code: 2, 
// kind: NotFound, message: "No such file or directory" }', src/main.rs:10:21
// -----
// resolve the error based on its ErrorKind
use std::fs::File;
use std::io::Error;      // Error objs have .kind() method, that return ErrorKind obj
use std::io::ErrorKind;   // ErrorKind::NotFound is one type
fn main() {
  let open_ret:Result<File, Error> = File::open("hello.txt");
  let myfile:File = match open_ret {
    Ok(file) => file,   // returns a valid opened file, extracted from Ok wrapper
    Err(error) => match error.kind() {   // extract the Error obj, error.kind() can return ErrorKind obj, match on it
      ErrorKind::NotFound => match File::create("hello.txt") {  // if matches NotFound then match on Result<File, Error> returned from create(), check if it creates properly
        Ok(fc) => fc,  // extact the file object, if its a success
        Err(e) => panic!("Problem creating the file: {:?}", e)
      }
      other_error => {   // any other error than ErrorKind::NotFound
        panic!("Problem opening the file: {:?}", other_error);
      }
    }
  };
  let metadata = myfile.metadata();  // reaching here, means myfile is valid
}
// -----
// unwrap() does the match of Ok(File), Err(Error) of Result<File, Error> for you
// returns the File or throws the panic! 
// expect() is similar, but with a custom error message
use std::fs::File;
fn main() {
  let open_file:File = File::open("hello.txt").unwrap();
  let open_file2:File = File::open("hello.txt").expect("hello.txt should be included in this project");
}
// -----
// propagates error to outer scope, handled there
// read_to_string will save the read data into username var
use std::fs::File;
use std::io::{self, Read, Error};
fn read_username_from_file() -> Result<String, io::Error> {
  let username_file_result:Result<File, Error> = File::open("hello.txt");
  let mut username_file:File = match username_file_result {
    Ok(file) => file,
    Err(e) => return Err(e),  // could return this error, if the file can't be read
  };
  // reaching this point means the file was opened succesfully
  let mut username = String::new();
  // returns the result of the match Result<String, Error>, either Ok(any string), Err(Error) 
  match username_file.read_to_string(&mut username) {     // read_to_string reurns Result<String, Error>
    Ok(_) => Ok(username),
    Err(e) => Err(e),
  }    
}
fn main() {
  let read_user_ret:Result<String, Error> = read_username_from_file();
  // now deal with the error
  let usable:String = match read_user_ret {  
    Ok(s) => s,
    Err(e) => panic!("{}", e)   // the error could be from open() or from read_to_String
  };
  // now String is usable: the file was opened and read_to_string was successful
  println!("{}", usable);
}
// -----
// ? propogates errors to outer scope in a simliar way to above example
// open() returns Result<File, Error>, so either Ok(File) or Err(Error)
// instead of using a match, ? tells open: if it returns Ok(n), then return n to username_file, 
//   if it returns Err(Error),then the function it sits in returns Err(Error), so that outer scope deals with it
//	 in general a function that calls f()? in its body must return a Result, Option, or any type that implements FromResidual trait   
// ? difference from match: on returning an Err(e), e is converted to the outer functions returned Result<T, E> E type
use std::fs::File;
use std::io;
use std::io::Read;
use std::io::Error;
fn read_username_from_file() -> Result<String, io::Error> {
  let mut username_file:File = File::open("hello.txt")?;  // if a panic is thrown, outer function returns out Err(Error), to be dealt with in main()
  let mut username = String::new();
  username_file.read_to_string(&mut username)?;  // same as above ?
  Ok(username)    // no Err(Error) was thrown, so wrap in Ok, so error could be dealt with in main
}
fn main() {
  let ret_read_user:Result<String, Error> = read_username_from_file(); 
  let usable:String = match ret_read_user {
    Ok(s) => s,
    Err(e) => panic!("main wants to deal with error, {}", e)
  };
  println!("{}", usable);  // now the String is valid, all errors checked, but they were dealt with in main
}
// -----
// even shorter version of error propogation, chaining ? operator, error push up stack to main
// ? returns Err(Error) if there is one from open() or read_to_string()
// returns Ok(username) for no error bc the Result<String, Error> is dealt with in main()
use std::fs::File;
use std::io;
use std::io::Read;
use std::io::Error;
fn read_username_from_file() -> Result<String, io::Error> {
  let mut username = String::new();
  File::open("hellop.txt")?.read_to_string(&mut username)?;
  Ok(username)
}
fn main() {
  let ret_read_user:Result<String, Error> = read_username_from_file(); 
  let usable:String = match ret_read_user {
    Ok(st) => st,
    Err(e) => panic!("{}", e)
  };
  println!("{}", usable);  // if the program gets to here the file opened and the String is valid
}
// -----
// main can return Result<T, E> (either Ok(T), or Err(E), also ? operator example
// Box<dyn Error> is a trait obj and is interpreted as any kind of error, see TRAIT
// any error in main causes an early return, even if you add more code that could throw different errors
// Result<(), Box<dyn Error>> means main returns 0 on Ok(()) and nonzero for any Err
// main may return any type that implements the std::process::Termination trait
use std::error::Error;
use std::fs::File;
fn main() -> Result<(), Box<dyn Error>> {    // detremin error dynamically at runtime
  let greeting_file = File::open("doesnotexist.txt")?;    // ? exits early on Err(e)
  Ok(())
}
// The terminal process "/usr/bin/bash '-c', 'cargo run'" terminated with exit code: 1. 
// -----
// simple custom error struct
// generic parameter E, so length can handle any error class
// E has a trait bound of Debug, so any error repr by E must have it implemented
//    this is needed for the "{:?}" to throw the panic
// is_ok() returns true if r is an Ok(n), false if Err(E), is_err() is it's opposite
#[derive(Clone, Debug)]
struct MyError {
  err_code:i32
}
fn length03<E : std::fmt::Debug>(r:Result<String,E>) -> usize {
  if r.is_ok () {  
    let s:String = r.unwrap();   // throws panic if it is Err()
    s.len()
  } else {
    panic!("{:?}", r.unwrap_err());  // returns the MyError and panics on it
  }
}
fn length04<E : std::fmt::Debug>(r:Result<String,E>) -> usize {
  if r.is_err() {
    panic!("{:?}", r.expect_err("r should not be Ok in this branch"));
  } 
  else {
    let s:String = r.expect("r should not be Err in this branch");
    s.len()
  }
}
fn main() {
  let ok:Result<String, MyError> = Ok(String::from("Ben Harki"));
  let n:Result<String, MyError> = Err(MyError {err_code:1});   // could type this, but need to "use std::error::Error" to see Error struct
  length03(ok.clone());   // clones because these funnctions consume the Result
  length03(n.clone());  
  length04(ok.clone());
  length04(n.clone()); 
}
// -----
// TODO: An example of &Result<T,E> using .as_ref(), exactly like Option, see OPTION
// TODO: An example of .and() and .or() like exactly like option, see OPTION
// MACROS that panic: unimplemented!, unreachable!, assert!, assert_eq!, assert_ne!
// SKIPPED the 9.2 unwrap_or_else closure version, which cleans up the nested matches in above code


MACRO
// helps reduce amount of code tht needs written
// can take a variable number of params
// expanded before compiler interpretes the meaning of the code, where a function is called at runtime
//	ex: functions can't write a trait, macros can
//      because they need impl at compile time, functions run at runtime 
> cargo expand --bin test.rs    //  view macro expansion
// -----
// library macros seen so far: 
#![allow(dead_code)]   // ! directive, applies to the whole file
#[derive(Debug)]   // applies to code immediately after
format!()  // return a String, &format!() returns a string slice
dbg!(expr)
asserteq!()
println!(), print!() // prints to std out (console) can be piped or redirected to a file
eprint!(), eprintln!()  // writes to stderr, also shown on terminal normally, can be redirected and pipes
panic!("abort!");    // aborts the current thread
vec![0,1,2,3]   // to create vectors from arrays
stringify!()
std::ptr::addr_of!(ptr)
panic!
// -----
// declarative macros start with macro_rules!
// let you write something similar to a match expression
#[macro_export]  // indicates this macro should be available whenver this crate is in scope
macro_rules! HI {
  () => {
    println!("HI");
  };
}
// $ declares macro variables to be used in replacement code 
// ident, ty declare a designator, like a more abstract type for the code
// ident for function or variable names, ty for types
// other designatators: block, expr, literal, stmt
#[macro_export]
macro_rules! CREATE_PR {
  ($my_print:ident, $mytype:ty) => {     
    fn $my_print(num:$mytype) {
      println!("{}", num);
    } 
  };
}
fn main() {
  HI!();
  // create the functions
  CREATE_PR!(print_int, i32);
  CREATE_PR!(print_str, &str);
  print_int(3);
  print_str("Ben Harki")
}
// -----
// overloaded with different argument patterns to catch
#[macro_export]
macro_rules! pr_loc_val{
  ($v:ident VAL) => {
    println!("{} = {}", stringify!($v), $v);
  };
  ($v:ident LOC) => {
    println!("&{} = {:p}", stringify!($v), &$v);
  };
}
fn main() {
  let x:i32 = 10;
  pr_loc_val!(x VAL);
  pr_loc_val!(x LOC);
}
// -----
// macro that takes any number of arguments, seperated by ,
// $() wraps the repeated argument, * for 0 or more times, + for one or more   
// recursive macro 
#[macro_export]
macro_rules! find_min {
  ($x:expr) => ($x);   // base case of the recursion
  ($x:expr, $($y:expr), *) => (
    std::cmp::min($x, find_min!($($y),*))   // call macro again on the tail
  )
}
fn main() {
  println!("{}", find_min!(1));
  println!("{}", find_min!(5,2,3,8,10));
}
// -----
// make your own domain specific language
// eval is a user-made command used in macro, not Rust keyword
#[macro_export]
macro_rules! calculate {
  (eval $e:expr) => {
    {
      let val: usize = $e; // Force types to be integers
      println!("{} = {}", stringify!{$e}, val);
    }
  };
}
fn main() {
  calculate!(eval (4 + 2) / 3);   // (4 + 2) / 3 = 2
}

HEAP AND STACK
// stack places an AR (Activation Record, like for a function) request on top and pops most recent first, FIFO 
// pushing to the stack is faster than allocating to the heap, since it adds on top
// heaps are slow because it can force processors to jump around in memory
// basic types are stored on the stack, objects from std lib classes like String on heap
// on the stack, .'s are bytes, basically stores only 2 numbers on the stack beside each other
// each . is a byte, 8 bits, . . . . is 32 bits, 4 bytes
// in memory:    . . . . . . . . 
//               ^x      ^ y and s   (identifiers, not pointers here)
#[derive(Debug)]
struct SubStack {
  y: isize
}
#[derive(Debug)]
struct Stack {
  x: isize,
  s: SubStack
}
fn main() {
  let stack = Stack {
    x: 100, 
    s: SubStack {  
      y: 200  
    }
  };
  println!("{:?}", stack);
}
// -----
// allocate an int 10 on the heap, using a Box pointer
// do not need to free since the Box is dropped, then the heap data is deallocated 
// Box pointers are not fat pointers, only contain a location
// Box pointers own the pointer, responsible for dropping and deallocating
// can give pointer to another Box, via move
// dropping the Box pointer, the recursively drops what its pointed to through ownership tree
// 		// unlike a reference that is also a pointer but only borrows, so if its dropped the obj is still alive
fn main() {
  let mut p:Box<i32> = Box::new(10);  // allocates i32 integer 10
  *p = *p + 1;  // derefes to increment
  println! ("*p = {}", *p);   // 11
  let mut s : Box<String> = Box::new (String::from ("abcdef"));   // from already allocates to the heap
	println!("{}", *s);    
}
/*
      STACK                HEAP
				s   ->       |     tmp  ->     // basically the tmp fat pointer is on the heap now 
										 |    "abcdef"	
*/	
// -----
// Box can never be null, use Option<Box<T>>, allows for Box<T> to be None
//	value held by Option<Box<i32>>> of value None, is actually 0, for Some(i32) it is a location
fn main() {
  let mut xp:Option<Box<i32>> = None;
  println!("{:?}", xp);
}
// -----
// .clone call on a Box will deep copy everything to another place (unlike Rc, see below)
// data on the heap is duplcated to another place
// Box pointer lives on stack, points to a String ref on the heap
// a new box pointer is created, it points to another String ref on heap, that points to duplicated char data on heap
// however box's do not implement Copy, so need .clone
fn main () {
  let b1 : Box<String> = Box::new (String::from ("hello"));
  let b2 : Box<String> = b1.clone ();   // // b2 = b1 is a Copy trait so use clone
  println! ("b1 = {:?}", b1);    // b1 has not been moved so this is ok
  println! ("b2 = {:?}", b2);		   
}
// -----
// reference count shared pointer keeps a count of how many references are alive for a pointer
// Rc's live on the stack and all point to one singular fatter pointer that lives on heap, made fatter by adding an Rc count
// adds and decr the count, if the count reaches 0 the object it points to is dropped
// sits in between a Box pointer that owns and a shared reference 
// Box's will drop data it points to when the pointer is dropped, references will not, Rc references is in between
// RC's point to data on heap like box a, but add data to keep track of ref count, see MEMORY EXAMPLES
// Rc's are immutable references in that you cannot change the data it points to, see REFERENCE/BORROW 
// unexpectedly, .clone() on an Rc only duplicates the pointer, have to "manually" clone for deep copy, but does incr the ref count
// does not implement Copy trait, bc the ref count needs adjusted
// example with a linked list in STRUCT
use std::rc::Rc;
fn main () {
  let r1:Rc<String> = Rc::new(String::from("hello"));   // both point to a heap pointer and Rc count of 2
  let r2:Rc<String> = r1.clone(); 
  println!("r1 = {:?}", r1);  // r1 was not moved, both r1 and r2 are valid, only one string in mem 
  println!("r2 = {:?}", r2);
}
// -----

LIFETIMES
// lifetimes ensure that references are valid for as long as they need to be
// helps prevent dangling references
// -----
// x has a lifetime of 'b, r of 'a, where 'a > 'b
// borrow checker rejects since r refers to a variable that is dropped before r 
fn main() {
  let r:&isize;
  {
    let x:isize = 5;
    r = &x;
  }       // x is dropped, so its reference in r is invalid
  // println!("r: {}", r);    // will not compile, since r is dangling
}
// -----
// all string literals have 'static lifetimes, for the duration of the program: &'static str
// needs to be staticin return since there is no borrowing a reference as an arg, needs to clear the function as a borrow
fn my_name() -> &'static str {
  "Ben Harki"
}
fn main() {
  my_name();
}
// -----
// some functions need a generic lifetime parameter on references
// functions that follow lifetime elison rules will not need lifetime parameters
// here x or y refs may live longer than the other depending on which is returned, so compiler throws without lifetimes 
// declared on the function signature and on its args, &'a mut atr, is also acceptable for mutable  
// forces the returned ref to be valid for the smaller of the lifetimes of the parameter ref's 
fn longest<'a>(x:&'a str, y:&'a str) -> &'a str {   
  if x.len() > y.len() {
    x
  } 
  else {
    y
  }
}
fn main() {
  let a = "longer";
  let b = "shrt";
  let c = longest(&a, &b);   
  println!("{}", c);
}
// -----
// structs need a generic lifetime parameter applied to fields that are references
// forces the lifetime of the struct object to be no longer than the lifetime of the reference it holds
#[derive(Debug)]
struct Name<'a> {   
  full: &'a str
}
fn main() {
  let n = Name{full: "Ben"};
}
// -----
// methods that have lifetime parameters
// methods themselves do not need 'a, should pass because of lifetime Elison rules
struct Name<'a> {
  full:&'a str
}
impl<'a> Name<'a> {
  fn print_both(&self, b:&Name) {   
    println!("{} and {}", self.full, b.full);
  }
}
fn main() {
  let n1 = Name{full: "Ben Harki"};
  let n2 = Name{full: "Mags Harki"};
  n1.print_both(&n2);
  n2.print_both(&n1);
}
// -----
// returned slice has the same lifetime as the parameter, which is arr, initialized in main
// returns a smaller and smaller slice
fn get_inner_slice<'a>(x:&'a [i32]) -> Option<&'a [i32]> {
  if x.len() < 2 {
    None
  } 
  else {
    Some (&x[1..(x.len () - 1)])
  }
}
fn main () {
  let mut arr : &[i32] = &[1, 2, 3, 4, 5, 6, 7, 8, 9, 10];   // arr_next lives as long as this lifetime: end of main
  println! ("{arr:?}");
  while let Some(arr_next) = get_inner_slice(arr) {  // breaks when returns a slice of size 1, on None return
    arr = arr_next;        // both arr and arr_next live as long as the arr ref 
    println! ("{arr:?}");
  }
}
// -----
// lifetime of the result is the same as the arg
// since n's lifetime is shorter, then res's will be made shorter
// compiler will automatically add the lifetimes if I do
fn f<'a> (r:&'a i32) -> &'a i32 {
  println! ("f: {r}");
  r
}
fn main () {
  let res:&i32;
  {
    let n:i32 = 10;
    res = f(&n);
  }   // n is dead here
  // println!("main: {res}");  // unavailable since res's lifetime is changed by f, to be the same as n's
}
// -----
// lifetimes of both args and return is the same 
// lifetime of a reference is shortened by max function
fn max<'a> (r:&'a i32, s:&'a i32) -> &'a i32 {
  if r > s {
    r
  } else {
    s
  }
}
fn main () {
  let m:i32 = 10;
  let rm:&i32 = &m;
  let res1:&i32;   // lifetime of res begins here for all of main, but is shortened
  {
    let n:i32 = 20;
    let rn:&i32 = &n;
    let res2:&i32 = max(rm, rn);  
    println!("main: {res2}");
    res1 = res2;    // "shorten's the lifetime of res1, since res2's is shortened from max by n"
  }
  println!("main: {rm}");  
  // println! ("main: {res1}");  fails
}
// -----
// SKIPPED LIFETIME ELISON RULES
// SKIPPED  10.3 > Generic Type Parameters, Trait Bounds, and Lifetimes Together

UNSAFE
// convert refs to *const, like C/C++, using transmute
// reads 4 bytes's values from within an unsafe block
// read 4 bytes byte by byte in unsafe block using "pointer arithmetic"
// *mut u64 is a pointer to a mutable location, *const i32 is a pointer to an immutable location 
fn examine_i32 () {
  println! ("examine_i32");
  let x : i32 = 0x11223344;
  println! ("{:016p}", &x);
  let r : &i32 = &x;
  println! ("{:016p}", r);
  let p : *const i32 = r;   // coerces &i32 into *const i32
  println! ("{:016p}", p);
  println! ("{:08x}", unsafe { *p });   // read value of 4 bytes (8 hex digits) pointed to by p (i32 is onl)
  println! ("{:08x}", { let p : *const i32 = &x; unsafe { *p } });   // same as above but without the use of other statements
  // print 4 bytes, byte by byte
  // arithmetic is not defined on Rust pointers, so we have to cast to/from usize first
  let mut q:*const u8 = unsafe { std::mem::transmute (&x) };  // &x:&i32 , converts to a smaller size (the size of an addr)
  for _ in 0..4 {
    println! ("{:02x}", unsafe { *q });
    q = ((q as usize) + 1) as *const u8;   // adds 1 byte to read it
  }
}
fn main () {
  examine_i32 ();
}
// -----
// print 3x64 bits of mem's contents with unsafe block, using "pointer arithmentic"
// uses transmute() to turn a ref into a *const
// finds the fat pointer data from a raw pointer: address it points to, and the size
// derefs byte by byte on the heap, to display its char value
fn examine_string () {
  let mut s:String = String::with_capacity(100);
  s.push_str("hello ");
  s.push_str("world");
  println!("address of String = {:016p}", &s);
  let mut q:*const u64 = unsafe {std::mem::transmute(&s)};   // 8 byte pointer
  // print 3 u64 from memory location pointed to by p
  for _ in 0..3 {  
    println!("contents of memory address {:016p} = {:016x}", q, unsafe { *q });  // look at 8 bytes
    q = ((q as usize) + 8) as *const u64;  // look at the next 8 bytes
  }
  let mut addr_of_char_data : *const u8 = unsafe { 
    let p : *const *const u8 = std::mem::transmute (&s);   // &String into a 1 byte pointer, **u8, so its a pointer to a char array
    *p
  };
  // explicity grab the data that represents the length from the String fat pointer
  // &String = pointer|capacity|size    // in little-endian, 16 bytes is the largest digit
  let len_of_char_data : usize = unsafe {    
    let mut p : *const usize = std::mem::transmute (&s);   
    p = ((p as usize) + 16) as *const usize;  // shift 16 bytes to point at the beginning of size data
    *p   // get its value     
  };
  assert_eq!(len_of_char_data, s.len ());
  // print the u8 value and char value, tjrough ptr arithmetic
  for _ in 0..len_of_char_data {
    let b : u8 = unsafe { *addr_of_char_data };  // derefs the heap address of the raw string
    println! ("{:02x} {}", b, b as char);  
    addr_of_char_data = ((addr_of_char_data as usize) + 1) as *const u8;  // shift to next byte
  }
}
fn main () {
  examine_string ();
}

MEMORY EXAMPLES
// memory examples of &x and &&x
fn main() {
  let x:u8 = 15;
  let xref:&u8 = &x;
  let xrefref:&&u8 = &xref;   //  let xrefref = &&x could take a different reference to a different reference
  println!("           x                 xref              xrefref");
  println!("values:    {:016x}, {:016p}, {:016p}", x, xref, xrefref);   // values they hold
  println!("locations: {:016p}, {:016p}, {:016p}", &x, &xref, &xrefref);  // locations
  println!("for debug");
}
           x                 xref              xrefref
values:    000000000000000f, 0x007fffffffdcff, 0x007fffffffdd00
locations: 0x007fffffffdcff, 0x007fffffffdd00, 0x007fffffffdd08
in rust-gdb:
(gdb) p/x x   // print, in hex, the value of x
$2 = 0xf
(gdb) p &x    // print where x lives
$8 = (*mut u8) 0x7fffffffdcff
(gdb) p xref   // print value xref holds
$3 = (*mut u8) 0x7fffffffdcff
(gdb) p &xref   // print where xref lives
$6 = (*mut *mut u8) 0x7fffffffdd00
(gdb) p xrefref  // print the value xrefxref holds
$4 = (*mut *mut u8) 0x7fffffffdd00
(gdb) p &xrefref  // print where xrefxref lives
$7 = (*mut *mut *mut u8) 0x7fffffffdd08
(gdb) x/b xref   // examine the value at the location xref holds (indirection)
0x7fffffffdcff: 0x0f
(gdb) x &x       // same thing with &
0x7fffffffdcff: 0x0f
(gdb) x/8b xrefref  // examine the value at the location xrefref holds
0x7fffffffdd00: 0xff    0xdc    0xff    0xff    0xff    0x7f    0x00    0x00
(gdb) x/8b &xref   // same thing with &
0x7fffffffdd00: 0xff    0xdc    0xff    0xff    0xff    0x7f    0x00    0x00 
// TODO: do the same thing in terms of *xref/*&x with dereference
// -----
// 4 bits is a hex digit, 1 byte is 2 hex digits or 8 bits
// &x -> x, &x contains the address where x lives 
// &str is a fat pointer
fn main() {
  let x:u32 = 16;
  println!("{:p}", &x);       // 0x7fffffffde34 
  let s:&str = "Ben Harki";
  println!("{:p}", &s);       // 0x7fffffffde38, location on stack, not the addr it holds
  println!("debug complete");
}
// in gdb:
(gdb) p x
10
(gdb) p &x      // location of x on stack
0x7fffffffde34    
(gdb) x/4bx &x   // contents of location of x: 4 bytes, 4x8 = 32 bits in x
0x7fffffffde34: 0x10    0x00    0x00    0x00  // little endian of 0x00000010
(gdb) p s
$1 = "Ben Harki"
(gdb) p &s
$2 = (*mut &str) 0x7fffffffde38
(gdb) x/16bx &s    // &str holds 16 byte value 
0x7fffffffde38: 0x5b    0x10    0x59    0x55    0x55    0x55    0x00    0x00
0x7fffffffde40: 0x09    0x00    0x00    0x00    0x00    0x00    0x00    0x00
(gdb) x/9c 0x000055555559105b
0x55555559105b: 66 'B'  101 'e' 110 'n' 32 ' '  72 'H'  97 'a'  114 'r' 107 'k'
0x555555591063: 105 'i'
// -----
// slice pointer is a fat pointer, so is a Vector
fn main() {
  let sli:&[i32] = &[16, 17, 18];
  println!{"{:?}", sli};
  println!("{:p}", sli);     // 0x55555559105c, addr held by the pointer 
  println!("{:p}", &sli);   // 0x7fffffffdd40, location of the pointer on stack
  println!("debug complete");
 }
// in gdb:
(gdb) p sli
$1 = &[i32](size=3) = {16, 17, 18}
(gdb) p &sli      
$2 = (*mut &[i32]) 0x7fffffffdd40
(gdb) x &sli
0x7fffffffdd40: 0x5559105c
(gdb) x/16bx &sli          // full 16byte fat pointer     
0x7fffffffdd40: 0x5c    0x10    0x59    0x55    0x55    0x55    0x00    0x00
0x7fffffffdd48: 0x03    0x00    0x00    0x00    0x00    0x00    0x00    0x00
(gdb) x/12b 0x000055555559105c       // examine the addr held 
0x55555559105c: 0x10    0x00    0x00    0x00    0x11    0x00    0x00    0x00
0x555555591064: 0x12    0x00    0x00    0x00
// -----
// Box containing a Vector
// sbox holds an addr to the heap that contains the fat pointer to the vector vals in the heap
fn main() {
  let sbox:Box<Vec<i32>> = Box::new(vec![0,1,2,3]);
  println!("{:?}", sbox);   // [0, 1, 2, 3]
  println!("{:p}", &sbox);   // 0x7fffffffdd10, location of the pointer
  println!("{:p}", sbox);    // 0x5555555a7bc0, value held by the pointer
  println!("debug complete");  
}  
// in gdb:
(gdb) p &sbox   // location of the pointer on the stack
$7 = (*mut *mut alloc::vec::Vec<i32, alloc::alloc::Global>) 0x7fffffffdd10
(gdb) x/8bx &sbox   // value held by pointer
0x7fffffffdd10: 0xc0    0x7b    0x5a    0x55    0x55    0x55    0x00    0x00
(gdb) x/24b 0x00005555555a7bc0   // examine the fat pointer value in the heap
0x5555555a7bc0: 0xa0    0x7b    0x5a    0x55    0x55    0x55    0x00    0x00
0x5555555a7bc8: 0x04    0x00    0x00    0x00    0x00    0x00    0x00    0x00   // capacity
0x5555555a7bd0: 0x04    0x00    0x00    0x00    0x00    0x00    0x00    0x00   // size
(gdb) x/16bx 0x00005555555a7ba0    // values in the heap
0x5555555a7ba0: 0x00    0x00    0x00    0x00    0x01    0x00    0x00    0x00  
0x5555555a7ba8: 0x02    0x00    0x00    0x00    0x03    0x00    0x00    0x00
// -----
// arrays on the stack and heap
fn main() {
  let stack_a:[i32; 3] = [0,1,2];
  println!("{:p}", &stack_a);  // location of the array on the stack; 0x7fffffffdd64
  for a in &stack_a {
    println!("{:p}", a);  // prints the locations of each element: 0x7fffffffdd64, dd68, dd6c
  }
  let heap_a:Box<[i32; 3]> = Box::new([3, 4, 5]);
  println!("{:p}", &heap_a);  // heap_a pointer on stack: 0x7fffffffdd58
  println!("{:p}", heap_a);   // value of heap addr held by pointer: 0x5555555a5ba0
  println!("debug complete");
}
(gdb) p stack_a
$1 = [0, 1, 2]
(gdb) p &stack_a   
$2 = (*mut [i32; 3]) 0x7fffffffdd64
(gdb) x/12bx &stack_a
0x7fffffffdd64: 0x00    0x00    0x00    0x00    0x01    0x00    0x00    0x00
0x7fffffffdd6c: 0x02    0x00    0x00    0x00
(gdb) p &heap_a
$2 = (*mut *mut [i32; 3]) 0x7fffffffdd58   //location of pointer on stack
(gdb) p heap_a
$3 = (*mut [i32; 3]) 0x5555555a5ba0   // location on heap held by pointer
(gdb) x/12bx heap_a    // examine the values on the heap
0x5555555a5ba0: 0x03    0x00    0x00    0x00    0x04    0x00    0x00    0x00
0x5555555a5ba8: 0x05    0x00    0x00    0x00
// -----
// move "moves" the fat pointer value to another location on stack
// fat pointer s still lives on stack, but rust avoids access
fn main () {
  let s : String = String::from ("hello");
  let t : String = s; 
  println! ("t = {}", t);
}
(gdb) b 3
(gdb) r
(gdb) p &s
$6 = (*mut alloc::string::String) 0x7fffffffddc8
(gdb) x/24bx &s
0x7fffffffddc8: 0xa0    0x5b    0x5a    0x55    0x55    0x55    0x00    0x00
0x7fffffffddd0: 0x05    0x00    0x00    0x00    0x00    0x00    0x00    0x00
0x7fffffffddd8: 0x05    0x00    0x00    0x00    0x00    0x00    0x00    0x00
(gdb) n
4         println! ("t = {}", t);
(gdb) p &t
$3 = (*mut alloc::string::String) 0x7fffffffdde0
(gdb) x/24bx &t
0x7fffffffdde0: 0xa0    0x5b    0x5a    0x55    0x55    0x55    0x00    0x00  // same fat pointer
0x7fffffffdde8: 0x05    0x00    0x00    0x00    0x00    0x00    0x00    0x00
0x7fffffffddf0: 0x05    0x00    0x00    0x00    0x00    0x00    0x00    0x00
(gdb) p s    
$4 = "hello"
(gdb) x/24bx &s    // s still lives in the stack after move, but inaccessible
0x7fffffffddc8: 0xa0    0x5b    0x5a    0x55    0x55    0x55    0x00    0x00  // same heap pointer to data
0x7fffffffddd0: 0x05    0x00    0x00    0x00    0x00    0x00    0x00    0x00
0x7fffffffddd8: 0x05    0x00    0x00    0x00    0x00    0x00    0x00    0x00
// -----
// Reference count pointers
// pointers both live on the stack, and point to one singular "fatter" String ref:
// adds a weak and strong ref counts to String fat pointer that lives on the heap
use std::rc::Rc;
fn main () {
  let r1:Rc<String> = Rc::new(String::from("hello"));
  let r2:Rc<String> = r1.clone(); 
  println!("r1 = {:?}", r1);  // r1 was not moved, both r1 and r2 are valid, only one string in mem 
  println!("r2 = {:?}", r2);
}
(gdb) p &r1
$3 = (*mut alloc::rc::Rc<alloc::string::String>) 0x7fffffffdd40
(gdb) p &r2
$4 = (*mut alloc::rc::Rc<alloc::string::String>) 0x7fffffffdd60
(gdb) x/8b &r1   // both point to same heap location that contains the "fatter" String pointer
0x7fffffffdd40: 0xe0    0x7a    0x5a    0x55    0x55    0x55    0x00    0x00
(gdb) x/8b &r2
0x7fffffffdd60: 0xe0    0x7a    0x5a    0x55    0x55    0x55    0x00    0x00
(gdb) p r2
$6 = Rc(strong=2, weak=0) = {value = "hello", strong = 2, weak = 0}
(gdb) x/40b 0x00005555555a7ae0   // examine String ref location with added Rc pointer data
0x5555555a7ae0: 0x02    0x00    0x00    0x00    0x00    0x00    0x00    0x00   // strong ref
0x5555555a7ae8: 0x01    0x00    0x00    0x00    0x00    0x00    0x00    0x00  // weak
0x5555555a7af0: 0xa0    0x7b    0x5a    0x55    0x55    0x55    0x00    0x00  // next 3 lines are string ref, this is pointer to heap data
0x5555555a7af8: 0x05    0x00    0x00    0x00    0x00    0x00    0x00    0x00  // capacity
0x5555555a7b00: 0x05    0x00    0x00    0x00    0x00    0x00    0x00    0x00  // size
(gdb) x/5bc 0x00005555555a7ba0     // char data
0x5555555a7ba0: 104 'h' 101 'e' 108 'l' 108 'l' 111 'o'
// -----
// i32's are 4 bytes, wrapped in Some() adds another 4 byte prefix, to indicate Some
fn main() {
  let x:Option<i32> = Some(100);
  println!("{:?}", x);
  let y:Option<i8> = Some(4);
  println!("{:?}", y);
}
(gdb) p &x
$5 = (*mut core::option::Option<i32>) 0x7fffffffde00   // location of x
(gdb) x/8b &x    // examine the 8byte value of x
0x7fffffffde00: 0x01    0x00    0x00    0x00    0x64    0x00    0x00    0x00
(gdb) p &y   
$4 = (*mut core::option::Option<i8>) 0x7fffffffde00
(gdb) x/2b &y  // examine value at y's location
0x7fffffffde00: 0x01    0x04   // adds a byte prefix to indicate Some
// -----
// see Vector example in VECTOR

PRINTLN! AND DBG!
// println! macro and dbg! macro are borrowing 
// can use different syntax for primitives, string literals, and Strings
fn main () {
  println!("Ben Harki");
  let x = 4;
  println!("{x}");  // works for other primitives like floats, types of ints
  let s = "Mags Harki";
  println!("{s}");
  let finn = String::from("Finn");
  println!("{finn}");
}
// -----
// more-often used form, both a string literal and String example
fn main () {
  let s = "Mags Harki";
  let b = String::from("Ben Harki");
  println!("names are {} and {}", s, b);
}  
// -----
// expressions, tuples, structs, and other built-in objects need dbg! or println!("{:?}")
// see FUNCTIONS for dbg!(f(10)), f(10) = 10
// dbg!() will own the obj (consume it), println!() will borrow
#[derive( Debug)]   // need so that myint has a debug format implemented
struct MyInt {
  i: isize
}
fn main() {
  dbg!(3 + 4 * 2);  // shows expression and result
  let t = (0,1);
  dbg!(t);
  let a = [0, 1, 2, 3];
  dbg!(a);   // multi-line version
  println!("a  = {:?}", a);   // shorter, easier to format
  println!("{:#?}", a);   // multi-line, same as dbg!(a), can add formatting
  let myint = MyInt {i:10};
  dbg!(&myint);   // needs to & so dbg doesn't consume
  println!("{:?}", myint);
  println!("{:#?}", myint);
} 
// -----
// all the prints/dbgs, vals, fat pointer applied to a &str (similar to a slice) 
// TODO: there is also a formatted version: "{:016p}" for a pointer, 16 hex digits padded with zeros
fn main() {
  let s:&str = "Ben Harki";
  println!("{}", s);   // Ben Harki
  println!("{}", &s);   // Ben Harki  // "{}" will auto-deref a ref
  println!("{:?}", s);  // "Ben Harki"
  println!("{:p}", &s);  // 0x7fffffffdb10, location of s on stack
  println!("{:p}", s);      // 0x0000555559205b, only addr value held by the fat pointer
  println!("{:p}", s.as_ptr());   // converts to raw pointer val *const u8, 0x0000555559205b,
  println!("{:p}", std::ptr::addr_of!(s));  // location of pointer on stack, 0x7fffffffdb10
  dbg!(s);      // [src/main.rs:6] s = "Ben Harki"
  dbg!(std::mem::size_of::<&str>());  // [src/main.rs:7] std::mem::size_of::<&str>() = 16
  let bs:&[u8] = s.as_bytes();   // int values of the characters
  println!("{:?}", bs);     // [66, 101, 110, 32, 72, 97, 114, 107, 105]  
  println!("{:#?}", bs);    // multi-line form
  println!("debug complete");
}
(gdb) p &s
$3 = (*mut &str) 0x7fffffffdb10  //location of s on stack
(gdb) x/16bx &s   // fat pointer contents: location and size
0x7fffffffdb10: 0x5b    0x20    0x59    0x55    0x55    0x55    0x00    0x00
0x7fffffffdb18: 0x09    0x00    0x00    0x00    0x00    0x00    0x00    0x00
(gdb) x/9bc 0x055555559205b    // examine the addr on heap held by pointer
0x55555559205b: 66 'B'  101 'e' 110 'n' 32 ' '  72 'H'  97 'a'  114 'r' 107 'k'
0x555555592063: 105 'i'
// TODO:  add in example with: Err(e) => eprintln!("error with flush {e:?}"), 

THREADS
// on a panic, values at the top of the stack are dropped, unwinding the whole stack
// after unwinding the the current thread exits
// if no other threads the process exits
// if there are threads they continue
// see error-handling > 40 for threads that loop panic or return


IO LIBRARY
// TODO: add in StdIn and StdOut examples
// from Rat_Lab crate


