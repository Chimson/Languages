use package_of_crates::LibModule::*;  // found inside lib.rs, contains add()
fn main() {
  println!("Hello from crate2!");
  println!("{}", add(10,20));
}