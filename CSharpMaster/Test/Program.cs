// start a process using .NET
// assumes that the process will terminate on its own
// using block ensures the object is disposed after the block, even if an exception is thrown in the block
// can add more objects in using arg, like using(obj1, obj2)
using System.Diagnostics;
class Program {
  static void Main(string[] args) { 
    try {
      using (Process myProcess = new Process()) {
        myProcess.StartInfo.UseShellExecute = false;  // starts without a window
        myProcess.StartInfo.CreateNoWindow = true;
        myProcess.StartInfo.FileName = "python";   // starts python REPL
        myProcess.StartInfo.Arguments = "trythis.py";
        myProcess.Start();
      }
    }
    catch (Exception e) {
      Console.WriteLine(e.Message);
    }
  } 
}
