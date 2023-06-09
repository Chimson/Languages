// packages create a namespace
// any Class names won't collide with names stored elsewhere, unless imported 
// classes are not accessible by code outside its package, unless declared public
// can add more files to this package
package benspackage;  // any classes defined in this file belong to this package
class Person {
  String first;
  String last;
  Person(String first, String last) {
    this.first = first;
    this.last = last;
  }
  public String toString() {
    return "Hello " + first + " " + last;       
  }
}
class PackageClass {
  public static void main(String args[]) {
    Person ben = new Person("Ben", "Harki");
    System.out.println(ben);
  }
}

// place PackageClass.java in benspackage dir
// change to parent dir: 
// $ cd ..
// $ javac benspackage/PackageClass.java    // classes need to be in benspackage dir
// run:
// $ java benspackage.PackageClass          // run from parent dir of benspackage dir

// can also set the CLASSPATH variable or use the -classpath option running with $ java and $javac
