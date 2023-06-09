package benspackage; 


public class PersonTwo {   // needs to public to be imported in importpackage/Import.java
  String first;
  String last;
  public PersonTwo(String first, String last) {
    this.first = first;
    this.last = last;
  }
  public String toString() {
    return "Hello " + first + " " + last + " from PersonTwo ";       
  }
}


