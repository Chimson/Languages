namespace Lib.Chapter1;

public class Rand {

  private static Random random = new Random(); 

  public static double Uniform(in double a, in double b) {
    // random number in [a, b)
    return a + random.NextDouble() * (b - a);
  }

  public static int Discrete(in double[] a) {
    // entries in a must sum to 1;
    // random int in drawn from discrete distribution 
    double r = random.NextDouble();
    double sum = 0.0;
    for (int i = 0; i < a.Length; ++i) {
      sum += a[i];
      if (sum >= r) {
        return i;
      } 
    }
    return -1;
  }

  public static void Shuffle(in double[] a) {
    int N = a.Length;
    for (int i = 0; i < N; ++i) {
      int r = i + random.Next(N - i); 
      double temp = a[i];
      a[i] = a[r];
      a[r] = temp;
    }
  }


}