// Inspired by reading Design Patterns .NET 6 3rd Edition
/* 
  OCP: Open-Closed
    open for extension but close for modification
    extendable without modifying and recompiling
    interface/abstract everything
  LSP: Liskov Substitution
    something that takes a Child type or Parent type, should take both without error 
  ISP: Interface Segregation
    for example: an IPrinter interface that contains, print(), fax(), scan()
    really should split the methods into their own interfaces
    then you can have a class that picks which interfaces it wants
*/

SOLID DESIGN PRINCIPLES
// SRP: Single Responsibility
// class has one responsibility, therefore only one reason to change
// can change the format style, without changing the Student class
class Student {
  public string? Name {init; get;}
  public int ID {init; get;}
}
class IDNameFormat {
  public static string FString(Student student) {
    return $"#{student.ID}: {student.Name}";
  }
} 
class NameIDFormat {
  public static string FString(Student student) {
    return $"{student.Name} - {student.ID}";
  }
} 

class Program {
  static void Main(string[] args) { 
    Student ben = new Student {Name = "Ben Harki", ID = 1};
    Console.WriteLine(IDNameFormat.FString(ben));
    Console.WriteLine(NameIDFormat.FString(ben));
  }
}

// TODO: FINISH EXAMPLES FOR SOLID PRINCIPLES
// STOPPED AT PAGE 20 PARAMETER OBJECT