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

  public static double[,] MatrixMult(in double[,] a, in double[,] b) {
    /*
     Must have the same dimensions and be square (does not check this)
      ex:
      1 2 3     2 4 6       1*2+2*8+3*5 1*4+2*1+3*7 1*6+2*3+3*9
      4 5 6  *  8 1 3   =     ...
      7 8 9     5 7 9         ...
      dot product: k travels across a row of a, and a column of b
      not commutative!
    */
    int N = a.GetLength(0);
    double[,] c = new double[N, N];
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        for (int k = 0; k < N; ++k) {  // dot product
          c[i,j] += a[i,k] * b[k,j]; 
        }
      }
    }
    return c;
  }

  public static double Abs(double x) {
    if (x < 0) {
      return -x;
    }
    else {
      return x;
    }
  }

  public static bool IsPrime(int N) {
    /*
      only need to iterate until i^2 < N
      if N is div by one i then its not prime
      if N is not div by any i than it is prime
      (does not account for when N is negative)
    */
    if (N < 2) {return false;}
    for (int i = 2; i*i <= N; ++i) {
      if (N % i == 0) {return false;}
    }
    return true;
  }

  public static double Sqrt(double c) {
    /*
      Based on Newton's method, derived from Taylor's Theorem
    */
    if (c < 0) {return double.NaN;}
    double err = 1e-15;   
    double temp = c;
    while (Math.Abs(temp - c / temp) > err * temp) {
      temp = (c / temp + temp) / 2.0;
    }
    return temp;
  }

  public static double H(int N) {
    /*
      Harmonic Numbers
      0 + 1/1 + 1/2 + ... 1/N ~ ln(N)
      does not acount for when N < 0
    */
    double sum = 0.0;
    for (int i = 1; i <= N; ++i) {
      sum += 1.0 / i;
    }
    return sum;
  }

  


}
