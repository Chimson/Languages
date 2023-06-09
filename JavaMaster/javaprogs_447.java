THIS IS FROM: CSC 447 CONCEPTS IN PROGRAMMING LANGUAGES 

SAFETY
// Java has some safety feature, including array bounds checking
Object[] bs = new Object[4];
Object b = bs[-1];    // throws ArrayIndexOutOfBounds exception
// ***********
// checked casts
class A { int x; }
class B extends A { float y; }
class C extends A { char c; }
class Typing05 {
  static void f (B b) {
    A a = b;       // casting up to superclass is ok
  }
  static void g (A a) {
    B b = (B) a;   // casting down  subclass must be checked
  }
  public static void main (String[] args) {
    f(new B());
    g(new C());    // throws ClassCastException 
  }  
}
// ************
// check cast in an array assignment
// this is a design flaw of java
class A { int x; }
class B extends A { float y; }
class C extends A { char c; }
class Typing03 {
  public static void main (String[] args) {
    B[] bs = new B[1];
    A[] as = bs;      // pointing to the same array
    as[0] = new C();    // ArrayStoreException, assigning a C inside an A array, downcasting, need checked
    B b = as[0];      // safe, since B's can be A's, upcasting
  }
}

DYNAMIC/STATIC TYPES
// java is both dynamic and static
// static error example
int a = 5;
String b = "hello";  
System.out.println ("Result = " + (a - b));   // throws bad operand for types error
// ***********
// converted to dynamic error by casting
// compiler is fine but ClassCastException thrown at run using $ java
// n is upcast (superclass) to Object and then downcast (subclass) to int, so dynamic check
int a = 5;
String b = "hello";
System.out.println ("Result = " + (a - (int)(Object)b));    // strings cannot be cast as ints
// **********
// java infers most precise type using var, here it is an int
var a = 5;      
a = "hello";    // compiler/static error, Scala would accept this
// **********
// static type checking is conservative
// for example, ths may not return String, but compiler throws error anyways
int f (int i, String s) {
  return true ? i : s;
}

SCALA INTRODUCTION
// obj is final, but its fields are not
final List<Integer> xs = new List<> ();
xs.add (4); 
xs.add (5); 
xs.add (6); // mutating list OK
xs = new List<> ();                 // reassignment fails
// **********
// java class representing a tuple 
// tuples are in scala
public class Pair<X,Y> {  // X and Y are type parameters, to be replaced by real type
  final X x;
  final Y y;
  public Pair (X x, Y y) { this.x = x; this.y = y; }
  static void f () {    // uses pair class
    Pair<Integer, String> p = new Pair<Integer, String> (5, "hello"); // employ types
    Pair<Integer, String> q = new Pair<> (5, "hello"); // infer type params
    int x = p.x;
  }
}
// **********

SCHEME LOOPS AND TAIL RECURSION
// will cause an exception StackOverFlowError on large enough numbers
// have too many recursive calls on stack activation records
static int countDown (int x) {
  if (x == 0) {
    return 0;
  } else {
    return 1 + countDown (x - 1);
  }
}

SCALA CLASSES
// static example
class C {
  int f1;     // needs an object to access, fails with C.f1
  int m1 () { return f1; }
  static int f2;   // stored not in an object but with the class itself
  static int m2 () { return f2; }
}
class Test {
  public static void main(String[] args) {
    C c = new C();
    System.out.println(c.f1); // access through object
    System.out.println(c.m1());
    System.out.println(C.f2); // no obj needed, but through class directly
    System.out.println(C.m2());
  }
}

SCOPE AND LIFETIME
// shadowing of local variables is illegal in java
public class C {
  static void f () {
    int x = 1;
    {
      int y = x + 1;
      {
        int x = y + 1;    // x is shadowwed, error: variable already defined in f()
        System.out.println ("x = " + x);
      }
    }
  }
}
// ***********
// fields can be shadowed
public class C {
  static int x = 1;
  static void f () {
    int y = x + 1;
    {
      int x = y + 1;    // x was defined as a field above, but is a local var to f here
      System.out.println ("x = " + x);
    }
  }
  public static void main (String[] args) {
    f ();
  }
}

CLOSURES
// java 8 supports nested functions, with proper closure
import java.util.function.IntConsumer;
public class NestedFunc1 {
  static IntConsumer f (int x) {
    IntConsumer g = y -> System.out.format ("x = %d, y = %d%n", x, y);  // java lambda function
    g.accept (1);
    return g;
  }
  public static void main (String[] args) {
    IntConsumer h = f (10);
    h.accept (2);
    f (20); 
    h.accept (3);
  }
}
$ javac NestedFunc1.java 
$ java NestedFunc1
x = 10, y = 1
x = 10, y = 2
x = 20, y = 1
x = 10, y = 3 // safe to call h, created with x=10, GOOD!
// ***********
// more nested function, using Javas Function type and lambda function
import java.util.function.Function;
public class NestedFunc2 {
  static Function<Integer,String> f (int x) {
    Function<Integer,String> g = y -> {   // lambda notation
      System.out.format ("x = %d, y = %d%n", x, y); 
      return "dummy";
    };
    g.apply (1);      // Function method
    return g;
  }
  public static void main (String[] args) {
    Function<Integer,String> h = f (10);
    h.apply (2);    //  h is g, which is nested in f
    f (20); 
    h.apply (3);
  }
}
// **********
// java 8 includes more Functional Programming stuff
import java.util.List;
import java.util.stream.Stream;
import static java.util.stream.Collectors.toList;
public class NestedFunc4 {
  static <X> void print (List<X> list) {
    list.forEach (x -> System.out.print (x + " "));   // java's for each
    System.out.println();
  }
  public static void main (String[] args) {
    List<Integer> input = Stream.of(args).map(Integer::parseInt).collect(toList());
    print (input);
    Stream<Integer> output = input.stream().map (x -> x + 1);
    print (output.collect(toList()));
  }
}    
// ************
// from Closures Worksheet, class compilation in worksheet
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;
public class Threads1Solution {
  public static void main (String[] args) {
    try {
      final String[] messages = new String[] { "the", "rain", "in", "Spain", "falls", "mainly", "on", "the", "plain" };
      final BlockingQueue<Runnable> q = new LinkedBlockingQueue<> ();
      Runnable sender = new Runnable () {
        public void run () {
          try {
            System.out.println ("Sender started");
            for (int i = 0; i < messages.length; i++) {
              final String message = messages[i];
              Thread.sleep (1000);
              q.put (new Runnable () {public void run () {System.out.println (message);}});   // nested anonymous, with overrided run function
            }
          } 
          catch (InterruptedException e) {
          // ignore interruptions
          }
        }
      };      // nested anonymous function
      new Thread (sender).start ();
      while (true) {
        q.take ().run ();
      }
    } 
    catch (InterruptedException e) {
    // ignore interruptions
    }
  }
}
// *********
// from CLOSURES worksheet
// uses FP stream and Function classes as nested classes
import java.util.*;
import java.util.function.Function;
import java.util.stream.*;
public class Nested {
  public static void main (String[] args) {
    List<Integer> l = new ArrayList<> ();
    Stream<Integer> s = l.stream();
    l.add (1); l.add (2); l.add (3);
    s.map (x -> x + 1)    // map method on Stream class
     .collect (Collectors.toList ())
     .forEach (x -> System.out.format ("%2d ", x));   // forEach with lambda
  }
}
public class Nested {
  public static void main (String[] args) {
      List<Integer> l = Arrays.asList (new Integer[] {1,2,3});
    l.add (1); l.add (2); l.add (3);
    Function<Integer,Integer> f;
    f = new Function<Integer,Integer> () { // anonymous inner class
      public Integer apply (Integer x) { return x + 1; }
    };
    l.stream ().map (f)   // map calles inner function
     .collect (Collectors.toList ())
     .forEach (x -> System.out.println (x));    // forEach with a lambda
  }
}

L-VALUE
// computation in an l-value
// arr could be a complicated expression
arr[n+2] =  3 // l-values may require r-mode evaluation
// **********
// obj lvalues can involve evals, can be nested, same in scala
obj.m1().f1[n+2].m2().f2 = 3;

ARGUMENT PASSING
// java calls pointers references,
// not as expansive as C pointers
// must  point to heap allocated, no stack allocated, no primitives
// can't point to some address and claim itis something different (cast) like in C (C is unsafe)
// all objects are dealt with as a reference
// java is a CBV language but objects are always references -> CBR with objects
// **********
// CBR for primitives can force it into a field of a class(obj) or array and update via reference
class IntRef { int n; }
public class Ref {
    static void g (IntRef r) { r.n = r.n + 1; }
    public static void main (String[] args) {
        IntRef s = new IntRef (); s.n = 1;
        g (s);      // passes the reference to the object by value (copies the address)
        System.out.println (s.n);       // 2
    }
}
// ***********
// similar to classic swap (that doesn't actually swap) example, but with Integer objects
// still does not swap
// proof that it is natively CBV - looks like its CBR, but it its not
class Test {
    private static void swapRef(Integer x, Integer y) {
        Integer oldX = x;       // copies the references and swaps locally, but not in main
        Integer oldY = y;
        x = oldY;
        y = oldX;
    }
    public static main(String args[]) {
        Integer a = 0;      // a->i0->0,  a contains a reference to an object holding 0
        Integer b = 1;
        swapRef(a,b);       // does nothing
    }
}
// *********
// from worksheet -> compare to Scala tuples fibanacci example
// compare to immutable pair in worksheet - remove new objects and final
import java.math.BigInteger;
class Pair<X,Y> {
  final X x;
  final Y y;
  Pair (X x, Y y) {
    this.x = x;
    this.y = y;
  }
}   
public class Fib1 {
  static Pair<BigInteger,BigInteger> fibaux (BigInteger n) {
    if (n.compareTo (BigInteger.ZERO) <= 0) {
      return new Pair<> (BigInteger.ZERO, BigInteger.ONE);
    } else if (n.equals (BigInteger.ONE)) {
      return new Pair<> (BigInteger.ONE, BigInteger.ONE);
    } else {
      Pair<BigInteger, BigInteger> p = fibaux (n.subtract (BigInteger.ONE));
      return new Pair<> (p.y, p.x.add (p.y));
    }
  }
  static BigInteger fib (BigInteger n) {
    return fibaux (n).x;
  }
  public static void main (String[] args) {
    for (int i = 0; i < 71; i++) {
      System.out.println (fib (BigInteger.valueOf (i)));
    }
  }
}

MORE SCOPE
// similar to C scope undefined program
class C {    
    public static void main (String[] args) {
        int x = 1 + x;      // 2nd x is not initialized so, throws error
        System.out.printf ("x = %08x\n", x);
    }    
}

NESTED CLASSES
// works fine, but a lot of plumbing
// Java Graphics 1.0
public class Swing1 extends Frame {
  public static void main (String[] args) { new Swing1 (); }
  int count = 0;
  public Swing1 () {
    setSize (200, 100); setLayout (new FlowLayout ());
    Button button = new Button ("Go"); add (button);
    Label out = new Label ("000", Label.CENTER); add (out);   
    button.addActionListener (new MyActionListener(this, out));
    setVisible (true);
  }
}
class MyActionListener implements ActionListener {
  private Swing1 parent;
  private Label out;
  public MyActionListener (Swing1 parent, Label out) { this.parent = parent; this.out = out; }
  public void actionPerformed (ActionEvent e) {
    parent.count += 1;      // accesses Swing1 count
    out.setText (String.format ("%03d", parent.count));     // accesses out local  to Swing1()
    out.repaint ();
  }
}
// **********
// Java Graphics 1.1
// Better bc it has an inner class
public class Swing2 extends Frame {
  public static void main (String[] args) { new Swing2 (); }
  int count = 0;
  public Swing2 () {
    setSize (200, 100); setLayout (new FlowLayout ());
    Button button = new Button ("Go"); add (button);
    Label out = new Label ("000", Label.CENTER); add (out);   
    button.addActionListener (
        new ActionListener() {  // inner class as argument to a method
            public void actionPerformed (ActionEvent e) {     // nested function inside Swing2 constructor
                count += 1;     // accesses count in  Swing2 class
                out.setText (String.format ("%03d", count));  // in Swing2()
                out.repaint ();
            }
        });
    setVisible (true);
  }
}
// ************
// Java Graphics 1.8
// another version of inner class with lambda function
// link between inner classes and closures
public class Swing3 extends Frame {
  public static void main (String[] args) { new Swing3 (); }
  int count = 0;
  public Swing3 () {
    setSize (200, 100); setLayout (new FlowLayout ());
    Button button = new Button ("Go"); add (button);
    Label out = new Label ("000", Label.CENTER); add (out);   
    button.addActionListener (
        e -> {        // no need to create new instance using lambda
            count += 1;
            out.setText (String.format ("%03d", count));
            out.repaint ();
        });
    setVisible (true);
  }
}
// **********
// java threads 1.0
class Run1 {
    public static void main (String[] args) {
        for (int i = 0; i < 5; i++) {
            new Thread (new MyRunnable (i)).start ();
        }
    }
}
class MyRunnable implements Runnable {
    private int x;
    public MyRunnable (int x) { this.x = x; }
    public void run () {
        while (true) 
            System.out.print (x);
    }
}
// 3331100000000000000000000000000022222222222222224444222...
// ***********
// Java Threads 1.1
class Run2 {
  public static void main (String[] args) {
    for (int i = 0; i < 5; i++) {
      int x = i;        // without this, throws same error as the case with lambda below, but for inner class
      new Thread (new Runnable () {     // nested class
          public void run () {
            while (true) 
              System.out.print (x);
         }
        }).start ();
    }
  }
}
// ***********
// Java Threads 1.8
// wth lambda
class Run3 {
  public static void main (String[] args) {
    for (int i = 0; i < 5; i++) {       // i is not effecctively final here, but is in x below, since x is declared once in the for loop
      int x = i;        // without this, compiler throws variables referenced from lambda must be effectively final
      new Thread (() -> {       // lambda
            while (true) 
              System.out.print (x);
          }).start ();
    }
  }
}
// *********
// PYTHON
// x=i is needed to create a new variable for each thread
// still interleaves threads, but not as nicely bc python
import threading
for i in range(5):
  def worker():
    x=i     // need this to work correctly (like java threads 1.0 output but not as nice) , but will still run without it except it produces all 4s
    while True: 
      print(i, end="")
  threading.Thread(target=worker).start()
// **********
// IN PERL
use threads;
my $i;
for ($i = 0; $i < 5; $i++) {        
  my $x = $i        // this needs added or else all 5s like in python example, weird bc i is not 5 in the for loop, but it is afterwards
  my $th = threads->create (sub {
    while (1) { print $i; } 
  });
  $th->detach();
}
sleep (1);
// *********
// java compiler supports inner classes, but the JVM does not, uses $ classes
for (int i = 0; i < 5; i++) {
  int x = i;
  new Thread (new Runnable () {
      public void run () {
        while (true) 
          System.out.print (x);
     }
    }).start ();
}
$ javac Run2.java 
$ javap -private 'Run2$1' 
// creates seperate $ classes
Compiled from "Run2.java"
final class Run2$1 implements java.lang.Runnable {  // impl is similar to java 1.0 example
  final int val$x;
  Run2$1(int);
  public void run();
}
// **********
// for Java 8, introducing lambdas, wanted to be useful for inner classes, see above button example
// to do this java created functional interfaces: can be used as an assignment target for a lambda expr or method reference
// a functional interface is an interface that has at most one public abstract method
// @FunctionalInterface, checks to see if it is
// *********
import java.util.function       // contains a lot of interfaces, java.awt contains older listeners
@FunctionalInterface
interface Function<T,R> { 
  public R apply (T x);     // interfaces do not define the method, create a structure for it
}
Function<Integer,Integer> f = new Function<> () {
  public Integer apply (Integer x) {        // defines impl
    return x + 1;
  }
};
// another way- can use this bc it is a functional interface, at most one public abstract methd
Function<Integer,Integer> f = x -> x + 1;       // compiler determines that it must be writing the apply method
// **********
// collections processing
// map accepts a function
package java.util.stream;
interface Stream<T> {
  ...
  // Returns a stream consisting of the results of applying
  // the given function to the elements of this stream
  <R> Stream<R> map (Function<? super T,? extends R> mapper);
  ...
}
public class Nested {
  public static void main (String[] args) {
    List<Integer> l = new ArrayList<> ();
    Stream<Integer> s = l.stream();
    l.add (1); l.add (2); l.add (3);
    s.map (x -> x + 1)
     .collect (Collectors.toList ())
     .forEach (x -> System.out.format ("%2d ", x));
  }
}
// 2 3 4
// **********
// legacy interface can't use lambda
// forced to use an inner class, lambdas can act as an alternative to them, but can only pass one method
@FunctionalInterface        // not a functional interface
interface MouseListener { /* from java.awt.event */
  void mouseClicked (MouseEvent e);
  void mouseEntered (MouseEvent e);
  void mouseExited (MouseEvent e);
  void mousePressed (MouseEvent e);
  void mouseReleased (MouseEvent e);
}
MouseListener.java:1: error: Unexpected @FunctionalInterface annotation
@FunctionalInterface
^
  MouseListener is not a functional interface
    multiple non-overriding abstract methods found in interface MouseListener

DISPATCH AND INHERITANCE
// Which toString()
// dynamic dispatch -> late binding
// in Java its always boxed object and virtual methods, unlike C++ below
class Animal              { public  String toString () { return "Animal"; } }       
class Bird extends Animal { public  String toString () { return "Bird"; } }
class Cat  extends Animal { public  String toString () { return "Cat"; } }
Animal[]  xs = { new Bird(), new Cat () };
for (Animal  x : xs)        // dynamic type, not static Animal type for x
    System.out.println (x.toString());         // bird, cat
//***********
// In Java, interface of function type
// each class inherits the interface
interface Fn {                 int apply (int x);                  }
class F implements Fn { public int apply (int x) { return x + 1; } }
class G implements Fn { public int apply (int x) { return x + 2; } }
class H implements Fn { public int apply (int x) { return x + 3; } }
Fn[] fs = { new F (), new G (), new H () };
for (int i = 0; i < fs.length; i++) {
  System.out.format ("fs[%d].apply(20)=%d\n", i, fs[i].apply(20));
}
/*
fs[0].apply(20)=21
fs[1].apply(20)=22
fs[2].apply(20)=23
*/
// ***********
// with anonymous inner classes
interface Fn { int apply (int x); }
Fn[] fs = new Fn[3];
for (int i = 0; i < fs.length; i++) {
  int j = i + 1;      // effectively final, to put into closure
  fs[i] = new Fn() { int apply (int x) { return j + x; } }      // anonymous inner class, implementing interface
}
for (int i = 0; i < fs.length; i++) {
  System.out.format ("fs[%d].apply(20)=%d\n", i, fs[i].apply(20));
}
/*
fs[0].apply(20)=21
fs[1].apply(20)=22
fs[2].apply(20)=23
*/
// ***********
// with lambda notation intead of inner class
interface Fn { int apply (int x); }
Fn[] fs = new Fn[3];
for (int i = 0; i < fs.length; i++) {
  int j = i + 1;      // effectively final
  fs[i] = x -> x + j;       // lambda
}
for (int i = 0; i < fs.length; i++) {
  System.out.format ("fs[%d].apply(20)=%d\n", i, fs[i].apply(20));
}
fs[0].apply(20)=21
fs[1].apply(20)=22
fs[2].apply(20)=23
// ***********
// delegation: variable that points to an object, object can be accessed
// inheritance: describe properties of function by layers of multiple classes
// **********
// recursive method
// static type A, dynamic type A
class A {
  int f (int x) {
    System.out.format ("A.f (%d)%n", x);
    return (x == 0) ? this.g () : this.f (x - 1);       // recursive with this inline base case
  }
  int g () { System.out.println ("A.g ()"); return 0; }
}
A x = new A ();
x.f (2);
/*
A.f (2)
A.f (1)
A.f (0)
A.g ()
$1 ==> 0        // prints result of f (which is g()) in jshell
*/
// ***********
// extend to B
// static type A, dynamic type B
class A {
  int f (int x) {
    System.out.format ("A.f (%d)%n", x);
    return (x == 0) ? this.g () : this.f (x - 1); 
  }
  int g () { System.out.println ("A.g ()"); return 0; }
}
class B extends A {         // B inherits f, g is overridden
  int g () { System.out.println ("B.g ()"); return 0; }
}
A x = new B ();     // Java is dynamic dispatch so uses the newer defined g
x.f (2);
/*              
A.f (2)
A.f (1)
A.f (0)
B.g ()
$1 ==> 0
*/
//***********
// abstract classes cannot be instantiated, must create a concrete subclass
// they are intended to be inherited
abstract class A {
  int f (int x) {
    System.out.format ("A.f (%d)%n", x);
    return (x == 0) ? this.g () : this.f (x - 1); 
  }
  int g () { System.out.println ("A.g ()"); return 0; }
}
class B extends A {
 
  int g () { System.out.println ("B.g ()"); return 0; }
}
A x = new A ();             // compiler error
// **********
// abstract methods must be overridden in any concrete subclass
abstract class A {
  int f (int x) {
    System.out.format ("A.f (%d)%n", x);
    return (x == 0) ? this.g () : this.f (x - 1); 
  }
  abstract int g ();        
}
class B extends A {
    // needs a definition for g here, must be overridden
}
// ************
// final methods in an abstract class cannot be overridden
abstract class A {
  final int f (int x) {
    System.out.format ("A.f (%d)%n", x);
    return (x == 0) ? this.g () : this.f (x - 1); 
  }
  abstract int g ();
}
class B extends A {
  int f (int x) { System.out.format ("B.f (%d)%n", x); return 0; }// tries to override, but throws error, because f is final
  int g () { System.out.println ("B.g ()"); return 0; }  
}
// ***********
// non final concrete methods can be overridden 
// also abstract methods can be overridden
//  both are hooks
abstract class A {      // same behavior if both the class is not abstract and g is not abstract (g is a concrete defined method)
  int f (int x) {
    System.out.format ("A.f (%d)%n", x);
    return (x == 0) ? this.g () : this.f (x - 1); 
  }
  abstract int g ();
}
class B extends A {
  int f (int x) { System.out.format ("B.f (%d)%n", x); return 0; }      // overrides concrete method in abstract class
  int g () { System.out.println ("B.g ()"); return 0; }             // overrides abstract method
}
A x = new B (); 
x.f (2);
// B.f (2)
// $1 ==> 0
// **********
// access A.f with this variable
// fails with this because see below
class A {
  int f (int x) {
    System.out.format ("A.f (%d)%n", x);
    return (x == 0) ? this.g () : this.f (x - 1); 
  }
  int g () { System.out.println ("A.g ()"); return 0; }
}
class B extends A {
  int f (int x) { System.out.format ("B.f (%d)%n", x); return  this.f(x); }
  int g () { System.out.println ("B.g ()"); return 0; }  
}
A x = new B (); 
x.f (2);                // calls B.f, causes inf recursion 
/*
B.f (2)
B.f (2)
B.f (2)
B.f (2)
... // infinite loop
*/
// ***********
// super allows A.f to be used
class A {
  int f (int x) {
    System.out.format ("A.f (%d)%n", x);
    return (x == 0) ? this.g () : this.f (x - 1);       // this is dynamically B, so back to B.f
  }
  int g () { System.out.println ("A.g ()"); return 0; }
}
class B extends A {
  int f (int x) { System.out.format ("B.f (%d)%n", x); return super.f(x); }     // super is A.f
  int g () { System.out.println ("B.g ()"); return 0; }  
}
A x = new B (); 
x.f (2);        // x is dynamically a B, super calls A.f
/*
B.f (2)               
A.f (2)               
B.f (1)               
A.f (1)
B.f (0)
 A.f (0)
 B.g ()  
 $1 ==> 0
 */
 // *************
 // interweaving of classes without inheritance, using delegation
 // Seperate classes, so recursion gets fixed on A
class A {
  int f (int x) {
    System.out.format ("A.f (%d)%n", x);
    return (x == 0) ? this.g () : this.f (x - 1);       // this will always refer to A, since B is not an A bc of no inheritance
  }
  int g () { System.out.println ("A.g ()"); return 0; }
}
class B {  
  A that = new A ();        // a seperate object from B, no single object of both class B and A 
  int f (int x) { System.out.format ("B.f (%d)%n", x); return that.f (x); }
  int g () { System.out.println ("B.g ()"); return 0; }
}
B x = new B (); 
x.f (2);
/*
B.f (2)             
A.f (2)
A.f (1)
A.f (0)
A.g () 
$1 ==> 0
*/
// ***********
// fix for proper interweaving, but this is not ideal, rather use inheritance
// both classes implement the same interface
// interface requires public
interface I { int f (int x); int g (); }
class A implements I { 
  I back = this; 
  public  int f (int x) {
    System.out.format ("A.f (%d)%n", x);
    return (x == 0) ? back.g () : back.f (x - 1); 
  }
   public int g () { System.out.println ("A.g ()"); return 0; }
}
class B implements I { 
    A a; 
    B () { a = new A (); a.back = this; } 
    public  int f (int x) { 
        System.out.format ("B.f (%d)%n", x);return a.f (x);
    }
    public int g () { System.out.println ("B.g ()"); return 0; }
}
B x = new B (); 
x.f (2);
/*
B.f (2)               
A.f (2)              
B.f (1)               
A.f (1)
B.f (0)
A.f (0) 
 B.g ()  
 $1 ==> 0
 */
 // ***********
 // more class-based inheritance
 // implement read() in subclass, inherit other methods
public abstract class InputStream implements Closeable {        // InputStream subclass must provide method that returns the next byte of input (read)
  public abstract int read() throws IOException;    // reads one byte, must override
  public int read (byte b[], int off, int len) throws IOException {   // reads a sequence of bytes, can override but not required  
    ... // calls read()
  }
  public long skip(long n) throws IOException {    // skip bytes of a certain length
    ... // calls read(byte b[], int off, int len) 
  }
  ...
}
// ***********
// example of above subclass that extends InputStream
// InputStream is an abstract class
public class DemoStream extends InputStream {
  int next = 0;
  public int read () throws IOException {       // must override no args form, called to read one byte at a time in other read call below
    int result = 32 + next;
    next = (next + 1) % (127 - 32);
    return result;
  }
  public static void main (String[] args) {
    byte[] buffer = new byte[50];
    InputStream is = new DemoStream ();
    for (int i = 0; i < 3; i++) {
      try { int numread = is.read (buffer, 0, buffer.length);       // uses inherited overloaded form that calls the newly implemented read()
            System.out.println (new String (buffer, 0, numread));
      } catch (IOException e) {}
} } }
/*
$ javac DemoStream.java && java DemoStream
 !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQ
RSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~ !"#$
%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUV
*/
// **********
// worksheet example
abstract class A {
  int f (int x) {		// recursive method
    System.out.format ("A.f (%d)%n", x);
    return (x == 0) ? g () : f (x - 1); 
  }
  abstract int g ();  
  void h () {
    System.out.println ("A.h ()"); 
  }
}
class B extends A {
  int g () { 
    System.out.println ("B.g ()"); 
    A r = this;
    r.h ();
    return 0;
  }
  void h () {
    System.out.println ("B.h ()"); 
    super.h ();		// calls A.h() using super
  }
}
public class Test {
  public static void main (String[] args) {
    A x = new B (); 
    x.f (3);	// starts in A, works its way down classes
  }
}
/*
A.f (3)
A.f (2)
A.f (1)
A.f (0)
B.g ()		// overrided g
B.h ()		// overrided h
A.h ()		// from super.() in B.h()
*/
// **********
// worksheet example
// like above but plain classes
class A {
  int f (int x) {
    System.out.format ("A.f (%d)%n", x);
    return (x == 0) ? g () : f (x - 1); 
  }
  int g () {
    System.out.println ("A.g ()"); 
    return 0;
  }
  void h () {
    System.out.println ("A.h ()"); 
  }
}
class B extends A {
  int f (int x) {
    System.out.format ("B.f (%d)%n", x);
    return super.f (x);
  }
  int g () { 
    System.out.println ("B.g ()"); 
    A r = this;
    r.h ();
    return 0;
  }
  void h () {
    System.out.println ("B.h ()"); 
    super.h ();
  }
}
public class Test {
  public static void main (String[] args) {
    A x = new B (); 
    x.f (3);
  }
}
/*
B.f (3)		// x is an A containing a B, call's B.f, returns super.f() which is A.f()
A.f (3)		
B.f (2)		// recursive call on original B object, so back to B
A.f (2)
B.f (1)
A.f (1)
B.f (0)
A.f (0)
B.g ()
B.h ()
A.h ()
*/
// **********
// worksheet example
class A {
  int f (int x) {
    System.out.format ("A.f (%d)%n", x);
    return (x == 0) ? g () : f (x - 1); 
  }
  int g () {
    System.out.println ("A.g ()"); 
    return 0;
  }
  void h () {
    System.out.println ("A.h ()"); 
  }
}
class B extends A {
  int f (int x) {
    System.out.format ("B.f (%d)%n", x);
    return this.f (x);
  }
  int g () { 
    System.out.println ("B.g ()"); 
    A r = this;
    r.h ();
    return 0;
  }
  void h () {
    System.out.println ("B.h ()"); 
    super.h ();
  }
}
public class Test {
  public static void main (String[] args) {
    A x = new B (); 
    x.f (3);
  }
}
// B.f(3) infinitely
// ***********
// more worksheet: composition and delgation
class A {
  int f (int x) {
    System.out.format ("A.f (%d)%n", x);
    if (x == 0) {
      return g ();
    } else {
      return f (x - 1);
    }
  }
  int g () {
    System.out.println ("A.g ()");
    return 0;
  }
}
class B {
  A a = new A ();
  int f (int x) {
    System.out.format ("B.f (%d)%n", x);
    return a.f (x);
  }
  int g () {
    System.out.println ("B.g ()");
    return 0;
  }
}
public class Test {
  public static void main (String[] args) {
    new B ().f (3);
  }
}
/*
B.f (3)
A.f (3)
A.f (2)
A.f (1)
A.f (0)
A.g ()
*/
//***********
interface I {
  int f (int x);
  int g ();
}
class A implements I {
  I back = this;
  public int f (int x) {
    System.out.format ("A.f (%d)%n", x);
    if (x == 0) {
      return back.g ();
    } else {
      return back.f (x - 1);
    }
  }
  public int g () {
    System.out.println ("A.g ()");
    return 0;
  }
}
class B implements I {
  A a;
  B () {
    a = new A ();
    a.back = this;
  }
  public int f (int x) {
    System.out.format ("B.f (%d)%n", x);
    return a.f (x);
  }
  public int g () {
    System.out.println ("B.g ()");
    return 0;
  }
}
public class Test {
  public static void main (String[] args) {
    new B ().f (3);
  }
}
/*
B.f (3)
A.f (3)
B.f (2)
A.f (2)
B.f (1)
A.f (1)
B.f (0)
A.f (0)
B.g ()
*/

PARAMETRIC POLYMORPHISM
// monomorphic linked list, like in C example
// Object creates a generic list using  subtype polymorphism
static class Node {
  Integer item;         // can replace Integer to Object for other types, lke void * in C
  Node    next;
} 
static Integer getLast (Node xs) {
  while (xs.next != null) {
    xs = xs.next;
  }
  return xs.item;
}
// **********
// Class cast exception, still better than undefined runnable program in C
static class Node    {
  Object  item;
  Node    next;
}
public static void main (String[] args) {
  Integer p = Integer.valueOf(2123456789);
  Node xs   = new Node();
  xs.next   = null;
  xs.item   = p;                      // store Integer
  Double q  = (Double) getLast(xs);   // ClassCastException
  System.out.printf ("d=%f\n", q);    // unsafe access
}
/*
$ javac Parametric2.java    // compiles fine
$ java Parametric2
java.lang.ClassCastException: Integer cannot be cast to Double      // runtime error bc cast is checked
at Parametric.main(Parametric2.java:10)
*/
// ***********
// example generic type <X> using parametric polymorphism, not the same as C++ templates
static Node<X> {
  X       item;
  Node<X> next;
}
 
static <X> X getLast (Node<X> xs) {
  while (xs.next != null) {
    xs = xs.next;
  }
  return xs.item;
}
// ***********
// example above modified to accept generics
static class Node<X> {
  X       item;
  Node<X> next;
}
public static void main (String[] args) {
  Integer p = Integer.valueOf(2123456789);
  Node<Integer> xs = new Node<>();
  xs.next   = null;
  xs.item   = p;                      // store Integer
  Double q  = (Double) getLast(xs);   // compiler error now bc xs is Node<Integer>
  System.out.printf ("d=%f\n", q);    // unsafe access
}
$ javac Parametric1.java        
error: incompatible types: Integer cannot be converted to Double
  Double q = (Double) getLast(xs);   // compiler error, no runtime, a little better
  // **********
// Java type parameters not stored at runtime: to maintain compatibility with legacy code
static class ArrayList<X> {
  X[] a;
  ArrayList(int n) {
    a = new X[n];       // fails here bc java doesn't know the type of X at runtime
  }
  void put (int i, X item) { a[i] = item; }
  X    get (int i)         { return a[i]; }
}
$ javac Parametric3.java
error: generic array creation
  a = new X[n];
  // **********
  // now only shows a warning
  static class ArrayList<X> {
  X[] a;
  ArrayList(int n) {
    a = (X[]) new Object[n];
  }
  void put (int i, X item) { a[i] = item; }
  X    get (int i)         { return a[i]; }
}
$ javac -Xlint:unchecked Parametric4.java
warning: [unchecked] unchecked cast
    a = (X[]) new Object[n];
// ***********
// ok to ignore, since array is empty
// X is compiled to just be an object bc java does type erasure
static class ArrayList<X> {
  X[] a;
  @SuppressWarnings("unchecked")        // uses annotation to ignore error
  ArrayList(int n) {
    a = (X[]) new Object[n];
  }
  void put (int i, X item) { a[i] = item; }
  X    get (int i)         { return a[i]; }
}
$ javac -Xlint:unchecked Parametric4.java
// works fine
// ************
// interplay of generic vs non-generic types
ArrayList<String> ss = new ArrayList<>(10);
ArrayList os = ss;      // alias to ss, of plain type
os.put (1, 2123456789);     // ok to put in
String s = ss.get (1);      // gets a number not a string, problem is seen here when really its at prev line, because the type is not checked for put 
/*
$ javac Parametric6.java
Note: Parametric6.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.
$ java Parametric6                     
ClassCastException: Integer cannot be cast to class String
  at Parametric.main(Parametric6.java:4)
*/
// ***********
// Java stores types with arrays, using arrays not ArrayList
String[] ss = new String[10];
Object[] os = ss;
os[1] = 2123456789;
String s = ss[1];
/*
$ javac Parametric7.java
// no warnings
$ java Parametric7                     
ArrayStoreException: Integer        // better error than above, because its flags the error at assignment due to arrays storing types, not later like above
   at Parametric.main(Parametric7.java:3)
*/
// ***********
// C++ List<T> is a template, only compiled when used, and needs instantiated to execute, like List<int>,  no duplication in source code but in executable
// in Java this would execute for any type T, one executable code for each class
// ML does not have duplication in either code or executable, ML is a MetaLanguage, mathematical logic based language

SUBTYPING
// subtype polymorphism: use a more specific type where a general one is expected, subset where superset is expected
// recall A, B extends A, C extends A example when upcast is always safe, downcast must be checked: subclassing
class A { int x; }
class B extends A { float y; }
class C extends A { char c; }
void f (B b) {
  A a = b;       // upcast always safe
}
void g (A a) {
  B b = (B) a;   // downcast must be checked
}
f (new B()); // OK
g (new C()); // ClassCastException
// ***********
// safe to use an instance of B when A is expected
// B is a subtype of A, in that every B is also an A B:<A, kinda like subset but be careful
// if  y:B and B<:A then y:A , this is upcast (even though B may add methods that A does not have)
A x = new A ();
B y = new B ();
x = y; // B ok when A expected
void aConsumer (A x) { ... }        // cast through method calls
aConsumer (y);    // B ok when A expected
B bProducer () { ... }
x = bProducer (); // B ok when A expected
// ***********
// <: is a partial order, like subset, but for types
// transitive, reflexive, etc.
// some langs have a top type where X<:Top for all X
// Object in Java is a top type, scala.Any ans scala.AnyRef (above all references) in scala
// ***********
// java arrays are covariant: if B <: A then B[] <: A[] 
// every assignment to object array is dynamically checked
// the choice is wither to make arrays invariant like scala or (covariant and dynamic check) like in java
// A has f() method and B has f() and g() method
public class Driver {
  public static void main (String[] args) {
    B[] bs = new B[] { new B (), new B () };
    A[] as = bs;      // OK, because covariant, not OK in scala bc scala arrays are invariant
    as[0] = new A (); // ArrayStoreException
    bs[0].g(); 		// g.B but not in A, unsafe access
  }
}
$ javac Driver.java 
$ java Driver
Exception in thread "main" java.lang.ArrayStoreException: A
  at Driver.main(Driver.java:5)
// ***********
// java didn't originally have parametric types, used Object
static void sort(Object[] xs) { ... }
String[] ss = ...;
sort(ss); // requires covariance
// **********
// sort in java API
static <X extends Comparable<? super X>> void sort(X[] xs) { ... }
// **********
// worsksheet example
interface I {
  void f ();
}
class A implements I { 
  public void f () { 
    System.out.println ("A"); 
  } 
}
class B extends A { 
  public void f () { 
    System.out.println ("B"); 
  } 
}
public class Test {
  public static void main (String[] args) { 
    I[] arr1 = new I[] { new A (), new B () };
    A[] arr2 = new A[] { new A (), new B () };
    A[] arr3 = new B[] { new B (), new B () };
    for (int n = 0; n < arr1.length; n++) {
      arr1[n].f ();
      arr1[n] = new A ();
    }
    for (int n = 0; n < arr2.length; n++) {
      arr2[n].f ();
      arr2[n] = new A ();
    }
    for (int n = 0; n < arr3.length; n++) {
      arr3[n].f ();
      arr3[n] = new A ();
    }
  }
}
/*
> java Test.java
A
B
A
B
B
Exception in thread "main" java.lang.ArrayStoreException: A	// can't store an A in a B
        at Test.main(Test.java:29)
*/
// **********
// worksheet example
public class Test {
  static class A           { int x; }
  static class B extends A { int y; }
  static B convert (A p) {
    B result = (B) p;		// compiler error thrown here, trying to upcast
    return result;
  }
  public static void main (String[] args) {
    A r = new A ();
    r.x = 5;
    B s = convert (r);
    System.out.println (s);
  }
}
/*
C:\Users\Benso\Programming\CSC_447_Prog_Lang_Concepts\CSC447Work>java Test
Exception in thread "main" java.lang.ClassCastException: class Test$A cannot be cast to 
	class Test$B (Test$A and Test$B are in unnamed module of loader 'app')
        at Test.convert(Test.java:5)
        at Test.main(Test.java:11)
*/

