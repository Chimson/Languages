// mod sec_lvl;  // private, so only parent module can call it
pub mod sec_lvl;   // now any module in the crate can access it, in this example main can call it

pub fn pr_fl() {
  println!("Hi from first_lvl module!");

  println!("first_lvl calls submodule ...");
  sec_lvl::pr_sec_lvl();
}