// Inspired by reading Design Patterns .NET 6 3rd Edition

PARAMETER OBJECT
// you can make an parameter class to handle only the parameters
// also this example is like an interface, without actually using "interface"
// here the "interfaced" method is represented a field, that is a named lambda
// example of applying SOLID principles with individual classes and not abstract structures
class BinOperateParams  {
  public float a;
  public float b;
  public Func<float, float, float> Operate;
  public BinOperateParams(Func<float, float, float> operate, 
      float a = 1.0f, float b = 2.0f) {
    this.Operate = operate;
    this.a = a;
    this.b = b;
  }
}
class BinOperate {
  public static float Operate(BinOperateParams bin_params) {
    return bin_params.Operate(bin_params.a, bin_params.b); 
  }
}
class Program {
  static void Main(string[] args) { 
    BinOperateParams[] calcs = {
      new BinOperateParams((a,b) => a * b, 50.5f, 15.3f),
      new BinOperateParams((a,b) => a + b, 25f, 32.33f)};
    foreach(BinOperateParams calc in calcs) {
      Console.WriteLine(BinOperate.Operate(calc));
    }
  }
}

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
// -----
// LSP: Liskov Substitution
// something that takes a Child type or Parent type, should take both without error 
// uncommenting the code would cause ChangeID to not work properly:
//   a "new" Property in a subclass usually will hide the superclass version
//   however here there are two ID's and Change only changes Student's, so MajorStudents is left unchanged
enum Major {CS, PSYCH, MATH};
class Student {
  public int ID {get; set;}
  public string Name {get; set;}
  public Student(int id, string name) {
    this.ID = id;
    this.Name = name;
  }
  public override string ToString() {
    return $"ID:{this.ID}, Name:{this.Name}";
  }
}
class MajorStudent : Student {
  private Major Major;
  // public new int ID {get; set;}
  public MajorStudent(Student student, Major major) 
    : base(student.ID, new String(student.Name.ToCharArray())) { 
      // this.ID = student.ID;
      this.Major = major;
  }
  public override string ToString() {
    return $"ID:{this.ID}, Name:{this.Name}, Major:{this.Major}";
  }
}
class ChangeID {
  public static void Change(Student stu, int id) {
    stu.ID = id;
  }
}
class Program {
  static void Main(string[] args) { 
    Student ben = new Student(1, "Ben");
    MajorStudent mags = new MajorStudent(new Student(2, "Mags"), Major.PSYCH); 
    Console.WriteLine(ben);
    ChangeID.Change(ben, 3);
    Console.WriteLine(ben);
    Console.WriteLine(mags);
    ChangeID.Change(mags, 4);
    Console.WriteLine(mags);
  }
}
// -----
// ISP: Interface Segregation
// better to split the actions of similar classes into their own interfaces
//   rather than have one class, with one interface that has many methods 
// then you can have a class that picks which interfaces it wants, and impl them how they want
// also keeps classes from holding a method it doesn't need: like a CapsMSG() in a LowerMessage class 
// here with composition (owning other objs) and delegation (calling their methods) 
// principle does not have to apply to strictly 
interface IRawMessage {
  public string RawMessage(); 
}
class Message : IRawMessage {
  public string Msg {get; init;} = "Default Message";
  public string RawMessage() => this.Msg;
}
interface ICaps {
  public string CapsMsg();
}
class CapsMessage : IRawMessage, ICaps {
  public IRawMessage RMsg = new Message {};   // composition
  public string RawMessage() => this.RMsg.RawMessage(); 
  public string CapsMsg() => $"{this.RMsg.RawMessage().ToUpper()}";
}
interface ILower {
  public string LowerMsg();
}
interface IAllMessage : IRawMessage, ICaps, ILower {}   // interfaces can inherit other interfaces
class AllMessage : IRawMessage, ILower, ICaps {
  public IRawMessage RMsg = new Message {};   // composition
  public string RawMessage() => this.RMsg.RawMessage();  // delegation: choosing to use another class's method
  public string LowerMsg() => $"{this.RMsg.RawMessage().ToLower()}";  // or can implement their own version
  public string CapsMsg() => $"{this.RMsg.RawMessage().ToUpper()}";
}
class Program {
  static void Main(string[] args) { 
    Message d = new Message {};
    Console.WriteLine(d.RawMessage());
    Message ben = new Message {Msg = "Hello from Ben!"};
    Console.WriteLine(ben.RawMessage());
    CapsMessage bencaps = new CapsMessage {
        RMsg = new Message {
          Msg = "Hello again from caps!"}};
    Console.WriteLine(bencaps.RawMessage());
    Console.WriteLine(bencaps.CapsMsg());
    AllMessage benall = new AllMessage {
      RMsg = new Message {
        Msg = "Hello again from All!"}};
    Console.WriteLine(benall.RawMessage());
    Console.WriteLine(benall.LowerMsg());
    Console.WriteLine(benall.CapsMsg());
  }
}

// STOPPED AT DEPENDENCE INVERSION PRINCIPLE