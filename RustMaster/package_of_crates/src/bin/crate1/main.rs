use package_of_crates::LibModule::*;  // found inside lib.rs, contains add()
fn main() {
  println!("Hello from crate1!");
  println!("{}", add(3, 5));
}