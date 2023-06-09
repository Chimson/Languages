DESIGN PATTERNS

COMPOSITION, AGGREGATION, DEPENDENCY
// composition
// when Class A has a field of type Class B and the relationship 
// to Class B is guaranteed to be an exclusive reference of A
// the instance of Class B is created inside of Class A, 
// and Class A doesn’t share that reference
class FullName {
	private Name firstName;
	private Name lastName;
	FullName(String fname, String lname) {
		this.firstName = new Name(fname);
		this.lastName = new Name(lname);
	}
	public String toString() {
		return firstName.getName() + " " + lastName.getName();
	}
}
class Name {
	private String name;
	Name(String _name) {
		this.name = _name;
	}
	public String getName() {
		return this.name;
	}
}
public class Test {
	public static void main(String[] args) {
		FullName ben = new FullName("Ben", "Harki");
		System.out.println(ben);
	}
}
// *******
// aggregation
 // Class A has a field of type Class B. 
 // Further, the relationship to Class B is not guaranteed to be an exclusive reference.
class FullName {
	private Name firstName;
	private Name lastName;
	FullName(Name fname, Name lname) {
		this.firstName = fname;
		this.lastName = lname;
	}
	public String toString() {
		return firstName.getName() + " " + lastName.getName();
	}
}
class Name {
	private String name;
	Name(String _name) {
		this.name = _name;
	}
	public String getName() {
		return this.name;
	}
}
public class Test {
	public static void main(String[] args) {
		Name fname = new Name("Ben");
		Name lname = new Name("Harki");
		FullName ben = new FullName(fname, lname);
		// FullName ben = new FullName(new Name("Ben"), new Name("Harki"));		// anoyn objs
		System.out.println(ben);
	}
}
// ******
// a dependency: when Class A utilizes Class B in some way, 
// but doesn’t retain a reference to it
// exs: B is returned from an A method, param to an A method
// held as a local var in A method but not in a field in A 


SOLID PRINCIPLES 
// single responsibiliy principle: each package/class/method should 
// 		only do one thing and do it well
// open-closed principle: open for extension, closed for modification
// *********
// SRP: each class is small and simple
// OCP: code does not need changed in Name or main()
// Name can be extended to use new print classes
class Name {
	private String name;
	private IPrint ip;
	Name(String _name, IPrint _ip) {
		this.name = _name;
		this.ip = _ip;
	}
	public String getName() {
		return this.name;
	}
	public void printName() {
		ip.print(this.name);
	}
}
interface IPrint {
	public void print(String str);
}
class PrintHiName implements IPrint {
	public void print(String str) {
		System.out.println("Hi " + str);
	}
}
class PrintHelloName implements IPrint {
	public void print(String str) {
		System.out.println("Hello " + str);
	}
}
public class Test {
	public static void main(String[] args) {
		Name ben = new Name("Ben Harki", new PrintHiName());
		ben.printName();
		Name mags = new Name("Mags Harki", new PrintHelloName());
		mags.printName();
	}
}
// *******
// Liskov substitution principle: for subclass, do not change behavior of superclasses
//		only extend behavior, not replace
// *******
// Interface Segregation Principle: 
//		create seperate interfaces and have it inherit the ones it needs, rather than have	
//		classes, interfaces inherit other interfaces in chain							 	
// ******
// ISP:
// create HAYName class and implement IHowAreYouPrintClient, 
//		rather than have Name class implement it
//    maybe subclasses of Name do not need printHAY 
class Name extends IPrint {
	public String name;
	Name(String _name) {
		this.name = _name;
	}
	public void printHi() {
		System.out.println("Hi " + this.name);
	}
	public void printHello() {
		System.out.println("Hello " + this.name);
	}
}
abstract class IPrint {
	abstract public void printHi();
	abstract public void printHello();
}
class HAYName extends Name implements IHowAreYouPrintClient {
	HAYName(String _name) {
		super(_name);
	}
	public void printHAY() {
		System.out.println("How are you " + this.name + "?");
	}
}
interface IHowAreYouPrintClient {
	public void printHAY();
}
public class Test {
	public static void main(String[] args) {
		HAYName ben = new HAYName("Ben Harki");
		ben.printHAY();
	}
}
// ******
// Dependence Inversion Principle
// prefer dependencies on abstract classes/interfaces than concrete classes
// abstractions should not depend on concrete classes
// ideally high level (abstract) and low level (concrete) modules depend on abstractions
// ******
// two low level concrete classes depend on an interface 
// printName() depends on Interface obj as an arg, calls interfaces method
// dependency injections, are methods for adhering to DIP: method, property, constructor: 
// this is an example of method injection, interface obj injected as an arg in printName
class RegName implements IName {
	private String name = "Ben Harki";
	public String getName() {
		return name;
	}
}
class SpaceName implements IName {
	private String first = "Ben";
	private String last = "Harki";
	public String getName() {
		return last + " : " + first;
	}
}
class PrintName {
	public void printName(IName iName) {
		System.out.println(iName.getName());
	}
}
interface IName {
	public String getName();
}
public class Test {
	public static void main(String[] args) {
		RegName ben1 = new RegName();
		SpaceName ben2 = new SpaceName();
		PrintName printer = new PrintName();
		printer.printName(ben1);
		printer.printName(ben2);		// helps reuse code, solving immobility
	}
}
// *****
// dependecy injections: constructor injection and property injection
// can use lambda in constructor injection
// interface obj as an arg to the constructor, and saved as a field in a class
// the interface field is private final to preserve the dependency
// two different versions of an IPrint
class Name {
	private String name;
	private final IPrint ip;
	public String getName() {
		return this.name;
	}
	Name(IPrint _ip, String _name) {
		this.ip = _ip;
		this.name = _name;
	}
	public void namePrint() {
		ip.print(this);
	}
}
interface IPrint {
	public void print(Name _nm);
}
class HiPrint implements IPrint {
	public void print(Name nm) {
		System.out.println("Hi " + nm.getName());
	}
}
class HelloPrint implements IPrint {
	public void print(Name nm) {
		System.out.println("Hello " + nm.getName());
	}
}
public class Test {
	public static void main(String[] args) {
		HiPrint hp = new HiPrint();
		Name ben = new Name(hp, "Ben Harki");
		ben.namePrint();
		HelloPrint hellpr = new HelloPrint();
		Name adam = new Name(hellpr, "Adam Harki");
		adam.namePrint();
		Name mags = new Name(
			(nm) -> System.out.println("How's " + nm.getName()),
			"Mags Harki");
		mags.namePrint();
	}
}

GANG OF FOUR DESIGN PRINCIPLES
// program to an interface not a concrete class
// favor object composition over class inheritance
// encapsulate concepts that vary

BUILDER
// a ClassBuilder is a class that is used to create an instance of another class
// usually used to create exactly one object then discarded
// mutable NameBuilder creates an immutable class FullName
class Name {
	private String name;
	Name(String _name) {
		this.name = _name;
	}
	public String getName() {
		return this.name;
	}
}
class FullName {
	private final Name firstName;
	private final Name middleName;
	private final Name lastName;
	FullName(Name first, Name middle, Name last) {
		this.firstName = first;
		this.middleName = middle;
		this.lastName = last;
	}	
	public String toString() {
		return "First:" + this.firstName.getName() + " middle:" + 
			this.middleName.getName() + " last:" + this.lastName.getName();
	}
}
class NameBuilder {
	private Name firstName;		
	private Name middleName;
	private Name lastName;
	NameBuilder setFirstName(Name _name) {
		this.firstName = _name;
		return this;
	}
	NameBuilder setMiddleName(Name _name) {
		this.middleName = _name;
		return this;
	}
	NameBuilder setLastName(Name _name) {
		this.lastName = _name;
		return this;
	}
	public FullName toFullName() {
		return new FullName(this.firstName, this.middleName, this.lastName);
	} 
}
public class Test {
	public static void main(String[] args) {
		NameBuilder builder = new NameBuilder();
		builder.setFirstName(new Name("Ben"));
		builder.setMiddleName(new Name("unknown"));
		builder.setLastName(new Name("Harki"));
		FullName ben = builder.toFullName();
		System.out.println(ben);
	}
}

STATIC FACTORY
// creates objs from different classes, hides access to those classes directly
// NameFactory should be public (not shown here), classes package-private
// client code (in main) calls the NameFactory rather than HiName, HelloName constructors
// shortcomming: client has to know concrete class, to call right method
class NameFactory {		// static class
	private NameFactory(){}
	public static IName createHiName(String str) {
		return new HiName(str); 
	}
	public static IName createHelloName(String str) {
		return new HelloName(str);
	}
}
abstract class IName {
	private String name;
	IName(String _name) {
		this.name = _name;
	}
	public String getName() {
		return this.name;
	}
	abstract void print();
}
class HiName extends IName {
	HiName(String _name) {
		super(_name);
	}
	public void print() {
		System.out.println("Hi " + this.getName());
	}
}
class HelloName extends IName {
	HelloName(String _name) {
		super(_name);
	}
	public void print() {
		System.out.println("Hello " + this.getName());
	}
}
public class Test {
	public static void main(String[] args) {
		IName ben = NameFactory.createHiName("Ben Harki");		// no NameFactory obj is necessary since it is static
	  ben.print();
		IName mags = NameFactory.createHelloName("Mags Harki");
		mags.print();
	}
}

FACTORY METHOD
// each class has its own creator method
// clients calls its's ClassCreator, not the class constructor itself
// solves Static factory shortcomming:
// 		client only needs to know the CreatorClass not the concrete class
interface INameCreator {
	public IName createName(String str1, String str2);
}
abstract class IName {
	private String first;
	private String last;
	IName(String _first, String _last) {
		this.first = _first;
		this.last = _last;
	}
	public String getFirst() {return this.first;}
	public String getLast() {return this.last;}
	abstract public void print();
}
class FirstLastCreator implements INameCreator{
	public IName createName(String first, String last) {
		return new FirstLast(first, last);
	}
}
class FirstLast extends IName {
	FirstLast(String _first, String _last) {
		super(_first, _last);
	}
	public void print() {
		System.out.println(this.getFirst() + ", " + this.getLast());
	}
}
class LastFirstCreator implements INameCreator{
	public IName createName(String first, String last) {
		return new LastFirst(first, last);
	}
}
class LastFirst extends IName {
	LastFirst(String _first, String _last) {
		super(_first, _last);
	}
	public void print() {
		System.out.println(this.getLast() + ", " + this.getFirst());
	}
}
public class Test {
	public static void main(String[] args) {
		FirstLastCreator flc = new FirstLastCreator();
		IName ben = flc.createName("Ben", "Harki");  // creation method
		ben.print();
		LastFirstCreator lfc = new LastFirstCreator();
		IName mags = lfc.createName("Mags", "Harki");  
		mags.print();
	}
}

ABSTRACT FACTORY
// create a couple factories tied to one IFactory interface
// for when your static factory has dependencies, in this case a number >100 or <100
// Factories can have constructors that accept dependencies via Dependency Injection
//		static factories cannot accept dependencies bc they have no obj instance
// classes are not directly tied to a factory like factory method
// each Factory is a little more abstact in that they make their own versions of two objs using overrided creation methods  
interface IIntegerFactory {
	public IEven createEven();
	public IOdd createOdd();
}
class UnderHundredFactory implements IIntegerFactory {
	public IEven createEven() {
		return new EvenUH();
	}
	public IOdd createOdd() {
		return new OddUH();
	}
}
class OverHundredFactory implements IIntegerFactory {
	public IEven createEven() {
		return new EvenOH();
	}
	public IOdd createOdd() {
		return new OddOH();
	}
}
interface IEven {
	public int getNumber();
	public void print();
}
interface IOdd {
	public int getNumber();
	public void print();
}
class EvenUH implements IEven {
	private int i = 26;
	public int getNumber() {
		return i;
	}
	public void print() {
		System.out.println(i);
	}
}
class OddUH implements IOdd {
	private int i = 11;
	public int getNumber() {
		return i;
	}
	public void print() {
		System.out.println(i);
	}
}
class EvenOH implements IEven {
	private int i = 126;
	public int getNumber() {
		return i;
	}
	public void print() {
		System.out.println(i);
	}
}
class OddOH implements IOdd {
	private int i = 111;
	public int getNumber() {
		return i;
	}
	public void print() {
		System.out.println(i);
	}
}
public class Test {
	public static void main(String[] args) {
		UnderHundredFactory uh = new UnderHundredFactory();	 // not just a method call like in factory method
		IEven e = uh.createEven();		// this abstract factory can create from classes unlike factory method, which tied to a class
		IOdd o = uh.createOdd();
		e.print();
		o.print();
		OverHundredFactory oh = new OverHundredFactory();
		e = oh.createEven();
		o = oh.createOdd();
		e.print();
		o.print();
	}
}

COMMAND PATTERN
// can encapsulate a method call or action
// command objs are generally unique and are not reused 
// Command wraps up some functionality and all necessary 
		// information into an object to be run at a later time.
interface ICommand {
	public void run();
}
class MyInt {
	private int i;
	MyInt(int _i) {
		this.i = _i;
	}
	public int getInt() {
		return this.i;
	} 
} 
class PrintIntCommand implements ICommand {
	private MyInt mI;
	PrintIntCommand(MyInt _mI) {
		mI = _mI;
	}
	public void run() {
		System.out.println(this.mI.getInt());
	}
}
class AddIntsCommand implements ICommand {
	private MyInt mI1;
	private MyInt mI2;
	AddIntsCommand(MyInt _mI1, MyInt _mI2) {
		mI1 = _mI1;
		mI2 = _mI2;
	}
	public void run() {
		System.out.println("The sum is: " + (mI1.getInt() + mI2.getInt()));
	}
}

public class Test {
	public static void main(String[] args) {
		PrintIntCommand pi = new PrintIntCommand(new MyInt(3));
		AddIntsCommand ai = new AddIntsCommand(new MyInt(3), new MyInt(8));
		System.out.println("do something else ... ");
		ai.run();
		pi.run();
	}
}

STRATEGY PATTERN
// encapsulates behavior, may do part of an algorithm but not all of it
// this is DIP: method injection
// could also save IStrategy objects inside Consumer field (property injection)
// 		or constructor (Constructor injection)
// can be used to encapsulate cases, put a switch in main to decide between the strategies
interface IStrategy {
	public int calculate(int a, int b);
}
class AddStrategy implements IStrategy {
	public int calculate(int a, int b) {
		return a + b;
	}
}
class MultStrategy implements IStrategy {
	public int calculate(int a, int b) {
		return a * b;
	}
}
class Consumer {
	private int a;
	private int b;
	Consumer(int _a, int _b) {
		this.a = _a;
		this.b = _b;
	}
	public void PrintCalc(IStrategy strategy) {
		System.out.println(strategy.calculate(this.a, this.b));
	}
}
public class Test {
	public static void main(String[] args) {
		Consumer cons = new Consumer(3,8);
		cons.PrintCalc(new AddStrategy());
		cons.PrintCalc(new MultStrategy());
	}
}

STATE PATTERN
// similar to strategy pattern
// client class Name manages its state internally (as a private field)
// Name obj uses its state ref and calls its behavior
// different from Strategy where extenal strategies are accepted into class through a class's public method
// difference: strategy is aggregation, state is composition
// has a method in Name that decides its state based on external info, manages the State internally
class Name {
	private String name;
	private IPrintState iPS;
	private static final IPrintState hi = new PrintHiState();
	private static final IPrintState hello = new PrintHelloState();
	Name(String _name) {
		this.name = _name;
	}
	public void print() {
		this.iPS.printBehavior(this.name);
	}
	public void checkMainState(int mainState) {		// state changes internally
		if(mainState == 1) {
			this.iPS = hi;
		}
		else if(mainState == 0) {
			this.iPS = hello;
		}
	}
}
interface IPrintState {
	public void printBehavior(String str);
}
class PrintHiState implements IPrintState {
	public void printBehavior(String str) {
		System.out.println("Hi " + str);
	}
}
class PrintHelloState implements IPrintState {
	public void printBehavior(String str) {
		System.out.println("Hello " + str);
	}
}
public class Test {
	public static void main(String[] args) {
		int mainState = 1;
		Name hiben = new Name("Ben Harki");
		hiben.checkMainState(mainState);
		hiben.print();
		mainState = 0;		// change the state
		hiben.checkMainState(mainState);
		hiben.print();
	}
}

OBSERVER PATTERN
// multiple observer concrete classes and multiple event classes, 
// can make Event classes  dependent on action in main
// notifyObservers is optional
import java.util.*;
interface IObserver {
	public void update();
}
class SayHey implements IObserver {
	public void update() {
		System.out.println("Hey! ... I'm notified");
	}
}
class SayHello implements IObserver {
	public void update() {
		System.out.println("Hello ... I'm notified");
	}
}
interface Event {
	public void registerObserver(IObserver o);
	public void notifyObservers();
}
class Event1 implements Event {
	private ArrayList<IObserver> observers = new ArrayList<IObserver>();
	public void registerObserver(IObserver o) {
		observers.add(o);
	}
	public void notifyObservers() {
		for(var obs : this.observers) {
			obs.update();
		}
	}
}
public class Test {
	public static void main(String[] args) {
		Event1 event1 = new Event1();
		SayHey p1 = new SayHey();
		SayHello p2 = new SayHello();
		SayHello p3 = new SayHello();  // not everyone gets registered
		event1.registerObserver(p1);
		event1.registerObserver(p2);
		event1.notifyObservers();
	}
}

NULL OBJECT PATTERN
// class that creates an object that does nothing
// eliminates the need for null checks in use() or other methods in UseBehavior
interface IBehavior {
  public void behaviorA();
}
class PrintBehavior implements IBehavior {
  public void behaviorA() {
    System.out.println("Hello World!");
  }
}
class NullBehavior implements IBehavior {
  public void behaviorA() {
    // does nothing
  }
}
public class Test { 
	public static void main (String[] args) {   // no need for a null check in main, or some other method/function
    IBehavior a = new PrintBehavior();
    IBehavior b = new NullBehavior();
    a.behaviorA();
    b.behaviorA();    // does nothing
  } 
}

PROXY PATTERN
// proxy class wraps the concrete class, both implementing same interface
// proxy obj calls the common method, and calls the concrete classes method inside
// can inject or create a new HiPrint obj anywhere inside HIPrintProxy class
// proxy class can hold cached or other data about the concrete class
// not good if the concrete class needts to change: then you have to change its proxy, use decorator pattern
interface IPrint {
  public void print();
}
class HiPrint implements IPrint {
  public void print() {
    System.out.println("Hi");
  }
}
class HiPrintProxy implements IPrint {
  public static int count = 0;    // counts how many times the HiPrint count is called via proxy
  public void print() {
    HiPrint h = new HiPrint();		// could write this as a HIPrint constructor, method, or property (field) injection
    h.print();
    ++count;
  }
}
public class Test { 
	public static void main (String[] args) { 
    HiPrintProxy hpp = new HiPrintProxy();  // can't delcare as IPrint obj because it doesn't have count field  
    hpp.print();
    hpp.print();
    System.out.println(hpp.count);   
    HiPrint hp = new HiPrint();
    hp.print();
  } 
}

DECORATOR PATTERN
// extend old class by adding functionality to common method, and calling old class's version inside
// could also have new class implement its own interface that extends the old class's
// could also work with another clas that injects/uses a common interface obj in some way (same as Test class does now)
// recursive wrapping of objects: can do things like 
// 		IPrint p = new IPrint(new OldPrint(new AnotherPrint())), or add more layers
interface IPrint {
  public void hiPrint();
}
class OldPrintA implements IPrint{
  public void hiPrint() {
    System.out.print("Hi");
  }
}
class OldPrintB implements IPrint{
  public void hiPrint() {
    System.out.print("hello");
  }
}
class PrintHiName implements IPrint {   // decorator class
  private final String name;
  private final IPrint old;
  PrintHiName(String _name, IPrint _old) { 
    this.name = _name;
    this.old = _old;
  }
  public void hiPrint() {
    this.old.hiPrint();
    System.out.println(" " + this.name);    // extends functionality
  }
}
public class Test { 
	public static void main (String[] args) { 
    IPrint o = new OldPrintA();   // can use IPrint objs here, unlike proxy pattern
    o.hiPrint();
    System.out.print("\n");
    IPrint ben = new PrintHiName("Ben Harki", o);
    ben.hiPrint();    
    IPrint mags = new PrintHiName("Mags", new OldPrintB());
    mags.hiPrint();
  } 
}

ADAPTER PATTERN
// wraps a third party API, not exactly what we want, with an adapter that calls it 
// adds other functionality
// can replace with other potential Adapters like PrintAdapterB, etc.
// could have PrintAdapter implement IPrint instead
// IMyPrint is nice to help potentially replace A with another adapter with the same additional hello functionality
interface IPrint {
  public void hiPrint();
}
class ThirdPartyPrint implements IPrint {
  public void hiPrint() {
    System.out.println("HI");
  }
} 
interface IMyPrint {    
  public void hiPrint();
  public void helloPrint();
}
class PrintAdapterA implements IMyPrint {
  private final IPrint p;		// use the interface obj here to help extend later
  PrintAdapterA() {
    this.p = new ThirdPartyPrint();
  }
  public void hiPrint() {
    this.p.hiPrint();   // calls 3rd party
  }
  public void helloPrint() {   // new functionality
    System.out.println("Hello");
  }
}
public class Test { 
	public static void main (String[] args) { 
    IMyPrint adapter = new PrintAdapterA();
    adapter.hiPrint();
    adapter.helloPrint();    // if theres a better PrintAdapterB, this code wouldn't change, easy to flip adapters 
  } 
}

SINGLETON PATTERN
// a few versions of the singleton pattern
// singleton pattern makes only one instance of a particular class's object
// create a static instance of itself as field, and make the constructor private 
// wrap access to any data with a method
class Singleton {
  public static final Singleton s = new Singleton();    // final is important, to avoid switching Singleton refs
  private Singleton() {}   // no other class should call this, so its private
  public void printS() {System.out.println("Singleton");}
}
// another way
// theres a static print() method that uses a private static field of its own class to call a private method
//    through the field
class Singleton2 {
  private static Singleton2 s = new Singleton2();  // static field is created once, early in compilation 
  private Singleton2() {}
  public static void print() {    // needs to be static bc s is static
    s.printS2();
  }
  private void printS2() {
    System.out.println("Singleton2");
  }
}
// another way: make s private and return it when needed through getS()
class Singleton3 {
  private static Singleton3 s = new Singleton3();  // private shields it from diret access from other classes
  private Singleton3() {}
  public static Singleton3 getS() {return s;}   // needs to be static bc s is static
  public void printS3() {    // making this static does not help, bc it removes the usage of the s obj
    System.out.println("Singleton3");  
  }
}
// another way: lazy loading
// loads the single instance on first getS() access and cache the result
class SingletonL {
  private static SingletonL s;
  private SingletonL() {}
  public void printL() {
    System.out.println("Lazy Loading");
  }
  public static SingletonL getS() {   // needs to be static to call SingletonL.get() without an obj
    if(s==null) {return new SingletonL();}    // stores one on first access
    else {return s;}
  }
}
public class Test {
  public static void main(String[] argv) {
    Singleton.s.printS();
    Singleton2.print(); 
    Singleton3.getS().printS3();
    SingletonL.getS().printL();
  }
}

COMPOSITE PATTERN
// composite pattern is like a tree of leaves (each leaf could be a subtree)
// can work nicely with the builder pattern that would help build the tree
import java.util.ArrayList;
interface IPrint {
  public void print();
  public void add(IPrint p);    // not necessary in the interface, only really nedded in Tree, but allows IPrnt abstraction  
}
class Leaf implements IPrint {
  private String msg;
  public Leaf(String _msg) {
    this.msg = _msg;
  }
  public void print() {
    System.out.println(this.msg);
  }
  public void add(IPrint p) {}    // does nothing, but does allow main to create IPrint objs without casting
}
class Tree implements IPrint {
  private String msg;
  public Tree(String _msg) {
    this.msg = _msg;
  }
  private ArrayList<IPrint> leaves = new ArrayList<>();
  public void print() {
    System.out.println(this.msg);
    for(IPrint leaf : leaves) {
      leaf.print();
    }
  }
  public void add(IPrint leaf) {
    this.leaves.add(leaf);
  }
}
public class Test {
  public static void main(String[] argv) {
    IPrint root = new Tree("root");
    IPrint subtreeL = new Tree("subtree left");
    IPrint leafR = new Leaf("leaf right");
    IPrint leafLL = new Leaf("leaf left, left");
    IPrint leafLR = new Leaf("leaf left, right");
    subtreeL.add(leafLL);       
    subtreeL.add(leafLR);
    root.add(leafR);
    root.add(subtreeL);
    root.print();   // prints all 5 nodes of the tree
  }
}
// *****
// may not technically be composite, bc it needs a Tree and Leaf class that both implement IPrint
// outer list TreeContainer helps manage the connections
// printing the whole tree, does not print the TreeContainer list
// 		it begins at root, prints a leaf, then its leaf, etc., using recursion
// TC[0] = null, TC[1] = 1 (aka root at pos 1), TC[2] = 2 (Tree.pos 2), ... 
// bottom leaves have empty ArrayLists
// more than just a binary tree, any node can have 0,1,2, ... children
import java.util.ArrayList;
interface IPrint {
  public void print();
  public int getPos();
  public int getParent();
  public void add(IPrint leaf);
}
class TreeContainer {
  private static final ArrayList<IPrint> listNodes = new ArrayList<IPrint>();
  TreeContainer() {
    listNodes.add(0, null);   // first entry is null, root starts at index 1
  }
  public void add(IPrint node) {
    listNodes.add(node.getPos(), node);   // add(index, node)
    this.attach(node);
  }
  private void attach(IPrint node) {
    int nParent = node.getParent();
    IPrint parent = listNodes.get(nParent);
    if(parent == null) {return;}    // the root's parent, listNodes[0], has a null IPrint
    parent.add(node);
  }
  public void print() {
    IPrint root = listNodes.get(1);
    root.print();
  }
}
class Tree implements IPrint {
  private int parent;
  private int pos;
  private ArrayList<IPrint> leaves = new ArrayList<>();
  public Tree(int _parent, int _pos) {
    this.parent = _parent;
    this.pos = _pos;
  }
  @Override
  public void print() {		// this is recursive
    System.out.println("TreeContainer: " + this.pos + ", Parent: " + this.parent);
    for(IPrint leaf : leaves) {
      leaf.print();
    }
  }
  @Override
  public int getPos() {
    return this.pos;
  }
  @Override
  public int getParent() {
    return this.parent;
  }
  @Override
  public void add(IPrint leaf) {
    this.leaves.add(leaf);
  }
}
public class Test {
  public static void main(String[] argv) {
    IPrint root = new Tree(0, 1);   // (parent, pos)
    IPrint L = new Tree(1, 2);
    IPrint M = new Tree(1, 3);    // adding this middle makes it a general tree, and not just a binary tree
    IPrint R = new Tree(1, 4);
    IPrint LL = new Tree(2, 5);
    IPrint LR = new Tree(2, 6);
    TreeContainer treeCont = new TreeContainer();
    treeCont.add(root);
    treeCont.add(L);
    treeCont.add(M);
    treeCont.add(R);
    treeCont.add(LL);
    treeCont.add(LR);
    treeCont.print();
  }
}

FLYWEIGHT PATTERN
// flyweights have vary that data and references to classes that wrap constant data
// helps with memory in that the Constant class data is not created for every instance, unlike other flyweight data
// can help the creation to combine with a static factory pattern or other factory-like patterns:
//   something like Factory.createBen() would return new FlyWeight("HiYa", ben), constant class ref ben is a field in Factory
class FlyWeight {
  private final String hi;    // this will still vary per instance
  private final IConstantName c;    // this can be of a few different classes (not different per instance)
  public FlyWeight(String msg, IConstantName _c) {
    this.hi = msg;
    this.c = _c;
  }
  public void printName() {
    System.out.println(this.hi + " " + c.getName());
  }
}
interface IConstantName {
  public String getName();
}
class ConstantName implements IConstantName {
  private final String name = "Ben Harki";
  public String getName() {return this.name;}
}
class ConstantName2 implements IConstantName {    // can create another constant class
  private final String name = "Mags Harki";
  public String getName() {return this.name;}
}
public class Test {
  public static void main(String[] argv) {
    ConstantName ben = new ConstantName();
    FlyWeight flyBen = new FlyWeight("hi", ben);    
    FlyWeight flyBen2 = new FlyWeight("HI", ben);   // points to same instance of ConstantName    
    FlyWeight flyBen3 = new FlyWeight("hello", ben);  
    FlyWeight flyMags = new FlyWeight("hello", new ConstantName2());
    flyBen.printName();
    flyBen2.printName();
    flyBen3.printName();
    flyMags.printName();
  }
}

// NEED TO ADD PATTERNS FROM WEEK 9






