// module declarations, needed to bring modules in scope
mod sepr_file;   // brings sepr_file.rs module into scope
mod first_lvl;   // includes the sec_lvl module scope, with it's decl in first_lvl/mod.rs

use first_lvl::sec_lvl::*;  // brings in whole module
// use first_lvl::sec_lvl::pr_sec_lvl;  // brings in only the one function

mod inline_mod  {
  pub fn pr_inline() {
    println!("Hello from inline_mod!");
  }
}

// run using > cargo run
fn main() {
  inline_mod::pr_inline();   // examples if paths to code
  sepr_file::sf_print();
  first_lvl::pr_fl();
  println!("main calls a pub module ... ");
  first_lvl::sec_lvl::pr_sec_lvl();  // since sec_lvl is a pub mod
  pr_sec_lvl();   // made available by use keyword
}
  