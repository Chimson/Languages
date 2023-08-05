// asynchronous programming is like the "making breakfst analogy"
// you would start cooking the bacon, while its cooking work on something else ...
// different that parallel programing in that, you have multiple "cooks" or "threads" that are blocked to their task
class MySleep {
  public int Time {init; get;}
  public static async int StartSleep(int i) {
    await Thread.Sleep(i);   // in System.Threading
    return i;
  }
}
class Program {
  static void Main(string[] args) {   
    Console.WriteLine("Hi");
    MySleep one = new MySleep {Time = 20}; 
    
  }
}





