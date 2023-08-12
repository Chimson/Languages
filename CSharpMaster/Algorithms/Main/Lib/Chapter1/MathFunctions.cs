namespace Lib.Chapter1;

public class MathFunctions {
  public static int GCD(int p, int q) {
    if (q == 0) {
      return p;
    }
    return GCD(q, p % q);
  }
}
/*
GCD(24, 18)
  return GCD(18, 6)
    return GCD(6, 0)
      return 6
*/