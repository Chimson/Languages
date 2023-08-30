namespace Lib.Chapter1;

public class MathFunctions {
  
  public static int GCD(in int p, in int q) {
    /* 
      This is not a complete version of GCD, with
      regards to its full mathematical definition
      This version, Euclid's version, should only accept natural numbers and 0
    */
    /*
    GCD(24, 18)
      return GCD(18, 6)
        return GCD(6, 0)
          return 6
    */
    if (q == 0) {
      return p;
    }
    return GCD(q, p % q);
  }

}
