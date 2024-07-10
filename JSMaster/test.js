// try-catch-finally
// when code throws an error in a try block
//    it is handled in the catch block
// finally block executes regardless if a an error is present
let den = 0;
let num = 100;
try {
  if (den == 0) {
    throw new Error("You divided by 0!");
  }
}
catch(e) {
  alert(e.);
}