// stopped at 2.3 Rust By Example: will probably not finish this lol

use std::fmt::{Display, Formatter, Result};

struct HexArray {
  ha:[i32;3]
}
impl Display for HexArray {
  fn fmt(&self, f:&mut Formatter) -> Result {   // fmt::Result = Result<(), Error>
    // write the formatted string into a buffer, f
    write!(f, "[0x{:X}, 0x{:X}, 0x{:X}]", self.ha[0], self.ha[1], self.ha[2])
  }
}

// compiler automatically impl std::fmt::Debug
#[derive(Debug)]
struct Point3D {
  x:i32, y:i32, z:i32
}

fn prints() {
  println!("Hello ... This is Rust Practice!");
  
  // hexadecimal formatting, stringified arg
  println!("65535 in hexadecimal: {:X}", 65535);

  // using std::fmt::Debug, created by compiler
  let p:Point3D = Point3D {x:0, y:0, z:0};
  println!("{:?}", p);
  println!("{:#?}", p);  // pretty print

  // using std::fmt::Display trait impl by HexArray
  let hex:HexArray = HexArray {ha:[15, 256, 65535]}; 
  println!("from Display trait: {}", hex); 
}

fn main() {

  prints();



}