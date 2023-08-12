namespace Test;

public class Results {

  public static void Print(in string format) {
    Console.Write(format);
  }

  public static string Title(in string title) {
    return $"\n***** {title} *****";
  }

}