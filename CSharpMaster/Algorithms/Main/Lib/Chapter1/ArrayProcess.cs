namespace Lib.Chapter1;

public class ArrayProcess {

  public static double Max(in double[] arr) {
    // find the maximum of an array
    // could be unsorted
    // needs at least one element, or IndexxOutOfRange exception
    double max = arr[0];
    for (int i = 1; i < arr.Length; ++i) {
      if (arr[i] > max) {
        max = arr[i];
      }
    }
    return max;
  } 

  public static double Average(in double[] arr) {
    int N = arr.Length;
    double sum = 0.0;
    for (int i = 0; i < N; ++i) {
      sum += arr[i];            
    }
    return sum / N;
  }

  public static double[] Copy(in double[] from) {
    int N = from.Length;
    double[] to = new double[N];
    for (int i = 0; i < N; ++i) {
      to[i] = from[i];
    }
    return to;
  }

  public static void Reverse(double[] arr) {
    int N = arr.Length;
    for (int i = 0; i < N/2; ++i) {
      double temp = arr[i];
      int rind = N - 1 - i;
      arr[i] = arr[rind]; 
      arr[rind] = temp;
    }
  }

}