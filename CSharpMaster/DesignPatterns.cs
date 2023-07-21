// Inspired by reading Design Patterns .NET 6 3rd Edition
/* 
  LSP: Liskov Substitution
    something that takes a Child type or Parent type, should take both without error 
  ISP: Interface Segregation
    for example: an IPrinter interface that contains, print(), fax(), scan()
    really should split the methods into their own interfaces
    then you can have a class that picks which interfaces it wants
*/

SOLID DESIGN PRINCIPLES
// SRP: Single Responsibility Principle
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
// -----
// OCP: Open-Closed
// open for extension but close for modification
// extendable without modifying and recompiling a class or interface
// used interfaces and classes to add more ways to sort
// IStudentData to check the Year data, Class data, OR of the two, or more ...
// IFilter to return any type of filter: in this case FIRST or MATH
enum Year {FIRST, SECOND, THIRD, FOURTH};
enum Major {MATH, CS, BUSINESS, PSYCH};
interface IStudentData {
  public bool HasData(Student value);
}
interface IFilter {
  IEnumerable<Student> Filter(IEnumerable<Student> stus, IStudentData data);
} 
class Student {
  public Year Year {init; get;}
  public Major Major {init; get;}
  public override string ToString() => 
    $"Year: {this.Year}, Major: {this.Major}";
} 
class YearData : IStudentData {
  public readonly Year Year;
  public YearData(Year yr) {
    this.Year = yr;
  }
  public bool HasData(Student stu) {
    return stu.Year == this.Year;
  }
}
class MajorData : IStudentData {
  public readonly Major Major;
  public MajorData(Major major) {
    this.Major = major;
  }
  public bool HasData(Student stu) {
    return stu.Major == this.Major;
  }
}
class OrData : IStudentData {
  public readonly IStudentData first, second;
  public OrData(IStudentData f, IStudentData s) {
    this.first = f;
    this.second = s;
  }
  public bool HasData(Student stu) {
    return first.HasData(stu) || second.HasData(stu);
  }
}
class SFilter : IFilter {
  public IEnumerable<Student> Filter(IEnumerable<Student> stus, IStudentData data) {
    foreach (Student stu in stus) {
      if (data.HasData(stu)) {
        yield return stu;
      }
    }
  }
} 
class Program {
  static void Main(string[] args) { 
    Student ben = new Student {Year = Year.FIRST, Major = Major.CS};
    Student mags = new Student {Year = Year.SECOND, Major = Major.PSYCH};
    Student finn = new Student {Year = Year.FIRST, Major = Major.BUSINESS};
    Student willie = new Student {Year = Year.THIRD, Major = Major.MATH};
    Student[] stus = {ben, mags, finn, willie};
    IEnumerable<Student> first_or_math_enumer = 
      (new SFilter()).Filter(stus, 
        new OrData(
          new YearData(Year.FIRST), 
          new MajorData(Major.MATH)));
    foreach (Student stu in first_or_math_enumer) { 
      Console.WriteLine(stu);  
    }
  }
}


// TODO: FINISH EXAMPLES FOR SOLID PRINCIPLES
// STOPPED AT PAGE 20 PARAMETER OBJECT