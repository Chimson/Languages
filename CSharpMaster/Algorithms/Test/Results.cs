namespace Test;

public class Results {

  public static void Print(in string format) {
    Console.Write(format);
  }

  public static string Title(in string title) {
    return $"\n***** {title} *****";
  }

  public static string ArrStr<T>(in T[] arr) {
    string arrstr = "[";
    int N = arr.Length;
    for (int i = 0; i < N - 1; ++i) {
      arrstr += $"{arr[i]}, ";
    }
    arrstr += $"{arr[N - 1]}]";
    return arrstr;
  }

  public static string TwoDArrStr<T>(in T[,] mat) {
    string matstr = "";
    int M = mat.GetLength(0);
    int N = mat.GetLength(1);
    for (int i = 0; i < M; ++i) {
      matstr += "|";
      for (int j = 0; j < N - 1; ++j) {
        matstr += $"{mat[i,j]} ";
      }
      matstr += $"{mat[i, N-1]}|\n";  
    } 
    return matstr;
  }

  public void TwoDPrintTest() {
    double[,] expected = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Print(Results.TwoDArrStr<double>(expected));
  }

  public static void Log(string msg) {
    Console.WriteLine($"{Title("Debug Log")}\n{msg}\n*********************");
  }

}