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

  public static int[] Copy(in int[] from) {
    int N = from.Length;
    int[] to = new int[N];
    for (int i = 0; i < N; ++i) {
      to[i] = from[i];
    }
    return to;
  }

}