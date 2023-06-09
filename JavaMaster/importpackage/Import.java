// TO RUN, in parent dir:
// > javac importpackage\Import.java
// > java importpackage.Import 

package importpackage;
// import needs to be after package statement
import benspackage.*;         // imports whole package (only public classes) 
// import benspackage.Person;  //  would work for individual Person Class, if Person was Public 

class Import {
  public static void main(String args[]) {
    // Person ben = new Person("Ben", "Harki");   // Person is not Public in benspackage, so this doesn't work
		PersonTwo mags = new PersonTwo("Mags", "Harki");
		System.out.println(mags);
  }
}
