using System.Diagnostics;
class Program {
  static void Main(string[] args) { 
    try {
      using (Process myProcess = new Process()) {
        myProcess.StartInfo.UseShellExecute = false;
        // You can start any process, HelloWorld is a do-nothing example.
        myProcess.StartInfo.FileName = "/home/bharki/Repos/Languages/CSharpMaster/Test/trythis.py";
        myProcess.StartInfo.CreateNoWindow = true;
        myProcess.Start();
        // This code assumes the process you are starting will terminate itself.
        // Given that it is started without a window so you cannot terminate it
        // on the desktop, it must terminate itself or you can do it programmatically
        // from this application using the Kill method.
      }
    }
    catch (Exception e) {
      Console.WriteLine(e.Message);
    }
  } 
}
