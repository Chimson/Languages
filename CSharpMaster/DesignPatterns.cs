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
// ----
// Dependency Inversion Principle
// code should depend on abstract sturctures, not concrete ones
// having a dependency on concrete structures can force rewriting of the code
//   if the memory design or any other design of the concrete structure changes
// Main is coded to the "interface objs"
// I could change out the concrete types to other types, that implement the same interfaces
//    the for loop code would be unharmed
interface INumber {
  public float Get();
}
class MyInt : INumber {
  public int I {init; get;}
  public float Get() {
    return this.I;
  }
  public override string ToString() {
    return $"{this.I}";
  }
}
class MyFloat : INumber {
  public float F {init; get;}
  public float Get() {
    return this.F;
  }
  public override string ToString() {
    return $"{this.F}";
  }
}
interface IAdd {
  INumber AddNums(INumber num1, INumber num2);
}
class MyAdd : IAdd {
  public INumber AddNums(INumber first, INumber second) {
    return new MyFloat {F = first.Get() + second.Get()};
  }
}
class Program {
  static void Main(string[] args) {   
    INumber i = new MyInt {I = 100};
    INumber f = new MyFloat {F = 3.14f};
    INumber delta = new MyInt {I = 2};
    INumber[] nums = {i, f};
    IAdd adder = new MyAdd();
    foreach (INumber num in nums) {
      Console.WriteLine(adder.AddNums(num, delta)); 
    }
  }
}

// BUILDER
// example of a Simple Builder, with Add, to help in construction
//    Add could also be written to add one at a time
// builders simplify the process of creating a complicated object that cannot
//    be built in a simple constructor call
// flexible enough to add to when needed, could also add a ToString() if you wanted
class FixedStack<Item> {
  // stacks pop in reverse order
  private Item[] items;
  private int N;
  public FixedStack(int size) {
    items = new Item[size];
  }
  public bool IsEmpty() => N == 0;
  public int Size() => N;
  public void Push(Item item) {
    items[N++] = item;
  }
  public Item Pop() {
    return items[--N];
  }
  public IEnumerable<Item> Enum() {
    // top of the stack is on the left
    // in the array it is on the right side
    for (int i = N - 1; i > -1; --i) {
      yield return items[i];
    }
  }
}
class FixedStackBuilder<Item> {
  public FixedStack<Item> Stack {get; private set;}
  public FixedStackBuilder(int size) {
    Stack = new FixedStack<Item>(size);
  }
  public void Add(Item[] items) {
    foreach (Item item in items) {
      Stack.Push(item);
    }
  }
}
class Program {
  static void Main(string[] args) {
    string[] names = {"Ben", "Mags", "Finn", "Willie"};
    FixedStackBuilder<string> names_builder = new FixedStackBuilder<string>(names.Length);
    names_builder.Add(names);
    FixedStack<string> stack = names_builder.Stack;
    foreach (string name in stack.Enum()) {
      Console.WriteLine(name);
    }
  }
}
// -----
// Fluent Builder
// fluent class has methods that return the object, to simplify method call syntax
// use with FixedStack<> class above
// Add returns the object to allow for Add method call chaining
// can construct and build all in one line
class FixedStackBuilder<Item> {
  public FixedStack<Item> Stack {get; private set;}
  public FixedStackBuilder(int size) {
    Stack = new FixedStack<Item>(size);
  }
  public FixedStackBuilder<Item> Add(Item item) {
    Stack.Push(item);
    return this;
  }
}
class Program {
  static void Main(string[] args) {
    FixedStackBuilder<string> names_builder =    
      new FixedStackBuilder<string>(4).Add("Ben").Add("Mags").Add("Finn").Add("Willie");
    FixedStack<string> stack = names_builder.Stack;
    foreach (string name in stack.Enum()) {
      Console.WriteLine(name);
    }
  }
}
// -----
// Static Initialization
// use with FixedStack<> above
// similar to the FluentBuilder, but syntax is a little cleaner
// create a static method Init(), to avoid the "new" syntax on the creation of the builder
// could also have seperate Inits, for seperate versions of the objects
class FixedStackBuilder<Item> {
  public FixedStack<Item> Stack {get; private set;}
  public FixedStackBuilder(int size) {
    Stack = new FixedStack<Item>(size);
  }
  public FixedStackBuilder<Item> Add(Item item) {
    Stack.Push(item);
    return this;
  }
  public static FixedStackBuilder<Item> Init(int size) {  
    return new FixedStackBuilder<Item>(size);
  }
}
class Program {
  static void Main(string[] args) {
    FixedStackBuilder<string> names_builder = 
      FixedStackBuilder<string>.Init(4).Add("Ben").Add("Mags").Add("Finn").Add("Willie");
    FixedStack<string> stack = names_builder.Stack;
    foreach (string name in stack.Enum()) {
      Console.WriteLine(name);
    }
  }
}
// -----
// force the use of a builder, by hiding the Stack constructor
// using private here, but could also use protected (accessible by class and those that subclass it)
// static Create() method is added to the stack class to force the builder to be used
//   rather than Stack constructor 
//   Create is a Factory method
// uses the overloading of the implicit cast operator, so that the Builder is converted directly to
//    to a Stack after creation
// Stack is mutable here by push and pop methods
//   can make it immutable if you make the builder a nested class
//   builder can the use any private properties or fields instead of its public ones
//   may break Single Resposibility Principle and OCP (open closed principle)
class FixedStack<Item> {
  // stacks pop in reverse order
  private Item[] items;
  private int N;
  private FixedStack(int size) {  // constructor is private
    items = new Item[size];
  }
  public bool IsEmpty() => N == 0;
  public int Size() => N;
  public void Push(Item item) {
    items[N++] = item;
  }
  public Item Pop() {
    return items[--N];
  }
  public IEnumerable<Item> Enum() {
    // top of the stack is on the left
    // in the array it is on the right side
    for (int i = N - 1; i > -1; --i) {
      yield return items[i];
    }
  }
  public static FixedStackBuilder<Item> Create(int size) {
    return new FixedStackBuilder<Item>(new FixedStack<Item>(size));
  }
  public static implicit operator FixedStack<Item>(FixedStackBuilder<Item> builder) {
    return builder.Stack;
  } 
}
class FixedStackBuilder<Item> {
  public FixedStack<Item> Stack {get; private set;}
  public FixedStackBuilder(FixedStack<Item> stack) {
    Stack = stack;
  }
  public FixedStackBuilder<Item> Add(Item item) {
    Stack.Push(item);
    return this;
  }
}
class Program {
  static void Main(string[] args) {
    // after the builder obj is done adding, it is implicitly casted to a Stack obj
    FixedStack<string> stack_builder = FixedStack<string>.Create(4)
      .Add("Ben").Add("Mags").Add("Finn").Add("Willie");  
  }
}
// -----
// use Composite Builder for when you need to split up a builder into more builders
//    for more complicated objs, each subbuilder can construct multiple parts,
// protected is used to make accessible within class and those who inherit it
// inheritance is used to preserve the obj ref between PersonBuilder and subbuilders
// could maybe make Person immutable if PersonBuilder is nested in it
// person ref gets passed around in subbuilder constr, which calls the parent constr
//   resets the ref back to itself
// implicit cast to Person operator is overridden so that PersonBuilder can cast directly to a Person
// drawbacks: base class is aware of subclasses, so not easily extendable
//    breaks OCP since PersonBuilder needs adjusted if a new subconstructor is needed
class Person {
  public string? name;
  public string? addr;
  public override string ToString(){
    return $"{name} lives at {addr}";
  }
}
class PersonBuilder {
  protected Person person;
  public PersonBuilder() {
    this.person = new Person();
  }
  public PersonBuilder(Person person) {
    this.person = person;
  }
  public PersonAddressBuilder Address => new PersonAddressBuilder(person);
  public PersonNameBuilder Name => new PersonNameBuilder(person);
  public static implicit operator Person(PersonBuilder pb) {   
    return pb.person;
  }
}
class PersonAddressBuilder : PersonBuilder {
  // one arg constr is needed so that another new obj is not created when calling the other builder
  public PersonAddressBuilder(Person person) : base(person) {}  // using the base() constr will incorrectly make that new obj
  public PersonAddressBuilder At(string addr) {
    person.addr = addr;
    return this;
  }
}
class PersonNameBuilder : PersonBuilder {
  public PersonNameBuilder(Person person) : base(person) {}
  public PersonNameBuilder Of(string name) {
    person.name = name;
    return this;
  }
}
class Program {
  static void Main(string[] args) {
    PersonBuilder pb = new PersonBuilder();
    Person person = pb
      .Name
        .Of("Ben Harki")  // could add more like .Last, .First
      .Address
        .At("Melrose St.");
    Console.WriteLine(person);
  }
}
// STOPPED AT PG 69 Stepwise Builder (Wizard)
