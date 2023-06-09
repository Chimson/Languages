// class that implements an interface must define all methods
import benspackage.Interface;
class Person implements Interface {   // can implement more than one using comma
  String first;     // not in interface, but can add to it
  String last;
  public void print(String g) {   // implemented methods must be public
    System.out.println(g);
  }
}

class Dude implements Interface {
  public void print(String g) {
    System.out.println("--" + g);
  }
}
  
public class ImpInterfaceEx {
  public static void main(String args[]) {
    Person p = new Person();
    p.print("Hello");
    System.out.println(Person.BEN);   // ben defined in benspackage//Interface.java
    Interface i = new Person();
    i.print("Hello");     // access Person obj usng Interface ref, can't on any memb outside Interface
    Dude dude = new Dude();
    i = dude;   // works bc Dude also implements Interface
    i.print("Hello");  // can use same interface ref, set to another class obj that implements it
  }
}