{// first package/module/class in Eclipse
	package first_package;
	public class Testing {		// Testing is the name of the Class file Testing.java
		public static void main(String[] args) {
			System.out.println("Hello World");
		}
	}
// run in console
	import stdlib.*;	// need this folder in the same directory as Testing.java
	public class Run_Console {	//must be same name as file
		public static void main (String[] args) {
			int a = Integer.parseInt(args[0]);	// contains value from command line
			StdOut.println ("Hello World "+ args[0]);	
		}
	}
	// see Run_Console.java in CSC_402 to compile/run in console
//-------
}

{//	basic info
	// every Java program is a class
	// name of file must match Class name
	// {} for blocks, ; ends statements
	// /* */  comments
	// method overloading is the same method definition (name, code, etc.) with different types and params 
// class modifiers
	// with no modifier classes are only accessible by classes in the same package
	public // class is accessible by any other class
// method, attribute, constuctor modifiers
	// no modifier: only in same package
	public  // code accessible for all classes
	private // code is only accessible within declared class through get/set methods (Encapsulation)
	protected	// same package and subclasses
	final  // cannot be modified
	static  // can be accessed without creating an object
			// static values in main (or in class and outside main) are global
//-------
}

{// variables, types, and operators
	// primitive types : 
	byte, short, int, long, float, double, boolean, char
	Type var;	// declare
	Type var = value;	// declare and assign
//-------
	// primitive types
	int x = 0;
	String s = "Ben";
	float num = 5.99f;
	float num = 1.33e4f;		// scientific
	char c = 'D';	// need ''
	boolean b = true;	// also for false
	final int num = 20;		// makes num constant		
//-------
	double dub = 1.23E4d;	// scientific and d forces it as a double
	dub = 1.0;	// automatically a double 
	dub = .33d;
	1.0/0.0; 	// infinity		// use .0 to ensure it is a double
	Math.sqrt(-1);	// NaN
	int x = StdRandom.uniform(10);	// random int everytime program is run
//-------
//	wrapper classes, needed for collection objects like ArrayList, etc.
	Byte, Short, Integer, Long, Float, Double, Boolean, Character
	myInt.intvalue()	// primitive int value from Integer class wrapper
//-------
	Integer myInt = 100;		// convert int to string to count number of digits
	String myStr = myInt.toString(); 
	System.out.println(myStr.length());	
//-------
	Integer.parseInt(str) // to convert strings to ints
	Double.parseDouble(num)		// converts num to double
//-------
	double a = 3.45;
	int x = (int) a;	// converts double a to int
	System.out.println(x);  
//-------
	// operators		// left assoc (l to r)
	=, +, -, *, /, %, ++, --    /// int/int drops fractional part
	+=, -=, ...		
	==, !=, >, <, >=, <=, &&, ||, !
//-------
	boolean a = true, b = false;
	(!a && b) || (a && !b)	// xor operation
//-------
	// escape chars
	\, \n, \r, \t, \b, \f  
//--------
}

{// i/o  
	StdOut.println	// needs stdlib; from class code
	System.out.println	// needs no imports
//-------
	String name = "Ben ";
	System.out.println(name + "Hello World");	// no space between
//-------
	int x = 3, y = 4;
	System.out.print(x);	// same line
	System.out.println(x+y);	// 7
	System.out.println(x + " + " + y);  // 3 + 4, first and last pluses are concat string rep of int
//-------
	import java.io.File;  // creates filename.txt in src folder
	import java.io.IOException;  
	public class Testing {
		public static void main(String[] args) {
			try {
				File myObj = new File("filename.txt");		// "C:\\Users\\...\\filename.txt" for win
				if (myObj.createNewFile()) {	
					System.out.println("File created: " + myObj.getName());
				} else {
					System.out.println("File already exists.");
				}
			} catch (IOException e) {	// throws an exception
				System.out.println("An error occurred.");
				e.printStackTrace();
			}
		}
	}
//-------
	import java.io.FileWriter;   // creates or overwrites file to write to
	import java.io.IOException;  
	public class Testing {
		public static void main(String[] args) {
			try {
				FileWriter myWriter = new FileWriter("filename.txt");
				myWriter.write("Files in Java might be tricky, but it is fun enough!");
				myWriter.close();
				System.out.println("Successfully wrote to the file.");
			} catch (IOException e) {
				System.out.println("An error occurred.");
				e.printStackTrace();
			}
		}
	}
//-------
	import java.io.File;  // reads entire txt line by line, each as a string
	import java.io.FileNotFoundException;  // Import this class to handle errors
	import java.util.Scanner; // Import the Scanner class to read text files
	public class Testing {
		public static void main(String[] args) {
			try {
				File myObj = new File("filename.txt");
				Scanner myReader = new Scanner(myObj);
				while (myReader.hasNextLine()) {
					String data = myReader.nextLine();	// reads line by line
					System.out.println(data);
				}
				myReader.close();
			} catch (FileNotFoundException e) {
				System.out.println("An error occurred.");
				e.printStackTrace();
			}
		}
	}	
//-------
	public class Testing {	// print format method
		public static void main(String[] args) {
			int i = 2;
			double r = Math.sqrt(i);
			System.out.format("The square root of %d is %f %n", i, r);	// %n is end line, %d is integer displayed as decimal 
			System.out.format("%2$f, %1$+020.10f", Math.PI, r);  	// 20 total chars, 0s in front, 10 dec places,
		}						//  1$ is the 1st argument index for ordering  // prints sqrt(2) then pi
	}
//-------
	import java.util.Scanner;  // Save user input as string
	public class Testing {
		public static void main(String[] args) {
			Scanner myObj = new Scanner(System.in);  // Create a Scanner object
			System.out.println("Enter username");
			String userName = myObj.nextLine();  // Read user input, saves as a string, also .nextInt(), .nextDouble()
			System.out.println("Username is: " + userName);  // Output user input
		}
	}
//-------
}

{// if/switch
	if (condition) {	// if block is one statement, do not need braces
		block;
	}
//-------
	if (condition) {
		block1;
	} else {
		block2;
	}
//-------
	if (condition1) {
		block1;
	} else if (condition2) {
		block2;
	} else {
		block3;
	}
//-------
	Type var = (condition)? block1 : block2;
//-------
	int num = 4;		// value of num matches value for cases
	switch(num){
		case 4:
			System.out.println("Hi");
			break;	// optional, breaks out of switch block
		default:	// optional, executes if no match on case
			System.out.println("Hello");
	}
//-------
	int x = 4;
	String num = (x < 3)? "Right!" : "Wrong";
//-------
}

{// loops
	while (condition) {		// don't need braces if block is only on statement
		block1;
	}
//-------
	do {
		block;
	} while (condition);	// block is executed at least once
//-------
	for (int i = 0; condition; i++) {
		block;
	}
//-------
	for (type var : array) {	// and also ArrayList, etc.
			block;
	}
//-------
	for (int i = 0; i < 10; i++) {	// illustrates break and continue, works in other loops
		if (i == 4) {
			break;	// breaks out of for loop
			//continue	// breaks i==4 interation, continues to rest
		}
			System.out.println(i);
	}
//-------
}

{// Math class
	Math.E; Math.PI;
	Math.max(num1,num2);
	.min(num1,num2); .sqrt(num); .abs(num);
	Math.random();	// in [0,1), multiply to get other intervals
	.abs(); .sin(); .cos(); .tan(); .asin();  // etc. // in radians
	.toDegrees(); .toRadians();
	.exp(); .log(); .pow(); .round();
//-------
	int num = (int)(Math.random()*101);	// random # between 1 and 100
//-------
}

{// enums
public Testing Main {	// an enum is a group of unchangable constants, can be used for switch cases
	enum Level {
		LOW,
		MEDIUM,
		HIGH
	}
	public static void main(String[] args) {
		Level myVar = Level.MEDIUM; 
		System.out.println(myVar);	// MEDIUM
	}
}
//-------
}

{// String
	str.length();
	.toUpperCase(); toLowerCase(); 
	str1.indexOf(str2);
	str1.concat(str2);	// concatenation
	"str1"+"str2";
//------
	String x = "10";
	int y = 20;
	System.out.println(x+y);	// 1020
//-------
	"Hi "+"Bob";	// concat, + has no space
//-------
	String t = "Hello World";	// iterates over chars in String, using array
	for (char c : t.toCharArray()) {
		System.out.println(c);
	}
//-------
}

{// array		// size cannot be modified
	Type[] var;	// declares array
	var = new Type[size];	// creates default array
	Type[] var2 = new Type[size];	// declares and assigns, new creates new reference
	var.length; 
//-------
	double[] a;	// declares an array
	a = new double[10];	// creates array of 0.0's length 10 by default, true for other types
	double x = a[3] + a[4];
	a = null;	// empty array
//-------
	double[] a = new double[10];	// can declare, create, and initialize in one statement
//-------
	double[] a = {0.3, 0.6, 0.99, 0.01, 0.5};	// copies contents of a into new array b (cannot do b = a)
	double[] b = new double[a.length];
	for (int i=0; i<a.length; i++) {
		b[i] = a[i];
		System.out.println(b[i]);
	}
//-------
	String[] names = {"Mags","Ben","Finn"};		// indexed vs for-each for loop with arrays
	names[2] = "Finnegan";	// indices start with 0
	for (int i = 0; i < names.length; i++){		// .length is the length of the array
		System.out.println(names[i]);
	}
	for (String name: names) {
		System.out.println(name);
	}
//-------
	int[][] myNumbers = { {1, 2, 3, 4}, {5, 6, 7} };	// 2D array, each inside can be of diff lengths
	int x = myNumbers[1][2];	// access a single number
	for (int i = 0; i < myNumbers.length; ++i) {	// access each element
		for(int j = 0; j < myNumbers[i].length; ++j) {
			System.out.println(myNumbers[i][j]);
		}
	}
//-------
	double[][] a;		// no way to refer to a specific column using an index
	a = new double [100][100];	// creates 2d array array of 0.0s
	a.length;	// num of rows
	a[2].length;	// num of cols;  can pick any row
//-------
	boolean [][] b = new boolean[10][10];	// 2d bool array defaulted to false
//-------
	public class Testing {		// declares an array and calls in one line
		public static void myfunction(int[] x) {
			System.out.println(x[1]);
		} 
		public static void main(String[] args) { 
			myfunction(new int[] {1,2,3});
		}
	}
//-------
	int x = 3;		// array pointer
	int y = 3;
	System.out.println(x==y);  // T, compares values
	int[] a = new int[] {1,2,3};
	int[] b = new int[] {1,2,3};
	System.out.println(a==b); // F, points to two diff locations
//-------
}

{// ArrayList		// size can be modified, of same type
					// better to use when adding or removing from ends, accessing random elements
	A_list.set(ind,item), .remove(ind), .clear(), 
	.size() 
//-------
	import java.util.ArrayList;
	public class Testing {
		public static void main(String[] args) {
			ArrayList<String> cars = new ArrayList<String>();
			cars.add("Volvo");
			cars.add("BMW");
			System.out.println(cars);
			cars.get(1);	// access an item in the list by index
			for (String i : cars) {	// for-each loop, can also write by index
				System.out.println(i);
			}
		}
	}
//-------
	import java.util.ArrayList;
	import java.util.Collections;  // Import the Collections class for .sort(A_list)
	public class Testing {
		public static void main(String[] args) {
			ArrayList<String> cars = new ArrayList<String>();
			cars.add("Volvo");
			cars.add("BMW");
			Collections.sort(cars);  // Sort cars
			for (String i : cars) {
				System.out.println(i);
			}
		}
	}
//-------
}

{// LinkedList		// better to use when looping through each element
//-------	
	import java.util.LinkedList;
	public class Main {
		public static void main(String[] args) {
			LinkedList<String> cars = new LinkedList<String>();
			cars.add("Volvo");
			cars.add("BMW");
			System.out.println(cars);
		}
	}
//-------
}

{// HashMap		// can also use a HashSet with unique items
hmap.get(key),.remove(key),.get(key),.size(),
//-------
	import java.util.HashMap;	// like dict in Python 
	public class Testing {
		public static void main(String[] args) {
			HashMap<String, String> capitalCities = new HashMap<String, String>();
			capitalCities.put("England", "London");		// (key,value) can also do (string,int)
			capitalCities.put("Germany", "Berlin");		// key is the index to the value
			System.out.println(capitalCities);
			System.out.println(capitalCities.get("England"));	// London
			for (String i : capitalCities.keySet()) {
				System.out.println(i);
			}
		}
	}
//-------
	import java.util.HashMap;	// like dict in Python 
	public class Testing {
		public static void main(String[] args) {
			HashMap<String, String> capitalCities = new HashMap<String, String>();
			capitalCities.put("England", "London");		// (key,value) can also do (string,int)
			capitalCities.put("Germany", "Berlin");		// key is the index to the value
			System.out.println(capitalCities);
			System.out.println(capitalCities.get("England"));	// London
			for (String i : capitalCities.keySet()) {
				System.out.println(i);	// prints keys England Germany
			}
			for (String i : capitalCities.values()) {
				System.out.println(i);	// prints values
			}
			for (String i : capitalCities.keySet()) {	// prints both
				System.out.println("key: " + i + " value: " + capitalCities.get(i));
			}
		}
	}
//-------
	import java.util.HashMap;	// set <key,value> as different types
	public class Testing {
		public static void main(String[] args) {
			HashMap<String, Integer> people = new HashMap<String, Integer>();	// <key,value>
			people.put("John", 32);
			people.put("Steve", 30);
			people.put("Angie", 33);
			for (String i : people.keySet()) {
			  System.out.println("key: " + i + " value: " + people.get(i));
			}
		}
	}	
//-------
}

{// Iterator		// used to loop through collections like ArrayList, HashSet, ...
//-------
	import java.util.ArrayList;	
	import java.util.Iterator;
	public class Testing {
		public static void main(String[] args) {
			ArrayList<String> cars = new ArrayList<String>();
			cars.add("Volvo");
			cars.add("BMW");
			cars.add("Ford");
			Iterator<String> it = cars.iterator();
			System.out.println(it.next());	// prints first item
			while(it.hasNext()) {
				System.out.println(it.next());	// loops through whole collection
			}
		}
	}
//-------
	import java.util.ArrayList;
	import java.util.Iterator;
	public class Testing {
		public static void main(String[] args) {
			ArrayList<Integer> numbers = new ArrayList<Integer>();
			numbers.add(12);
			numbers.add(8);
			numbers.add(2);
			Iterator<Integer> it = numbers.iterator();
			while(it.hasNext()) {
				Integer i = it.next();
				if(i < 10) {
					it.remove();	// would not work in for or for-each loops due to changing size 
				}
			}
			System.out.println(numbers);	// prints [12]
		}
	}
//-------
}

{// methods		
	public class Testing {		// method inside a main function  // Testing is file's Class
		static void myMethod() {	// definition of method	// static means belongs to Testing class // void is no return value
			System.out.println("Hello World");
		}
		public static void main(String[] args) {	// main function
			myMethod();		// method called in main
		}
	}
//-------
	public class Testing {		// no need for prototypes, method defined after called in main
		public static void main(String[] args) {	// main function
			int num = 4;
			myMethod(num);		// method called in main, defined below
		    myMethod(new int 10);
		}
		static void myMethod(int num) {		// method with one parameter
			System.out.println(num + 4);
		}
	}
//-------
	public class Testing {		// return method
		static int myMethod(int num) {	// int, since it returns an int
			return num + 4;
		}
		public static void main(String[] args) {	// main function
			int num = 4;
			System.out.println(myMethod(num));
			int x = myMethod(5);	// assigns to x
		}
	}
//-------
	public class Testing {	// recursive function, sums #s from 5 to 10
		public static void main(String[] args) {
			int result = sum(5, 10);
			System.out.println(result);
		}
		public static int sum(int start, int end) {
			if (end > start) {
				return end + sum(start, end - 1);
			} else {
				return end;
			}
		}
	}
//-------
    public class Testing {
		static int x = 5;	
		public static void myfunction() {
			System.out.println(x);	// accesses x inside function
		} 
		public static void main(String[] args) { 
			myfunction();
		}
	}
//-------
	public class Testing {	// recursive forward method that could be a while loop
		public static int numFives (double[] list) {
			int result = numFivesHelper (list, 0, 0);
			return result;
		}
		public static int numFivesHelper (double[] list, int i, int result) {
			if (i < list.length) {
				if (list[i] == 5) {
					result++;
				}
				System.out.println("result = " + result);
				result = numFivesHelper (list, i + 1, result); // iterates here, tail recursion
			}
			System.out.println("return, from i = " + i);
			return result;
		}
		public static void main(String[] args) { 
			double [] list = {2.0, 5.0, 5.0, 4.0};
			numFives(list);
			/*
				result = 0
				result = 1
				result = 2
				result = 2
				return, from i = 4
				return, from i = 3
				return, from i = 2
				return, from i = 1
				return, from i = 0
			*/
		}
	}
//-------
	public class Testing { // recursive backward
		public static int numFives (double[] list) {
			int result = numFivesHelper (list, 0);
			return result;
		}
		public static int numFivesHelper (double[] list, int i) {
			int result = 0;
			System.out.println("result = " + result);
			if (i < list.length) {
				result = numFivesHelper (list, i + 1); // leap of faith // result called on way back 
				if (list[i] == 5) {
					result++;
				}
				System.out.println("result = " + result);
			}
			System.out.println("return, from i = " + i);
			return result;
		}
		public static void main(String[] args) { 
			double [] list = {2.0, 5.0, 5.0, 4.0};
			numFives(list);
			/*
				result = 0
				result = 0
				result = 0
				result = 0
				result = 0
				return, from i = 4
				result = 0
				return, from i = 3
				result = 1
				return, from i = 2
				result = 2
				return, from i = 1
				result = 2
				return, from i = 0
			*/
		}
	}	
//-------
	public class TestingE {	//backwards and forwards recursive
		public static double sumUntil (double val, double[] list) {	
			double result = sumUntilHelper (val, list, 0);
			return result;
		}
		public static double sumUntilHelper (double val, double[] list, int i) {
			double result = 0; // after last call, this does not null out result
			if (i < list.length && list[i] != val) {
				System.out.println("result = " + result);
				result = sumUntilHelper (val, list, i + 1); 	// only iterates i first time through
				result = result + list[i];	// sums up on the back end of stack
				System.out.println("result = " + result);
			}
			System.out.println("return, from i = " + i);
			return result;
		}
		public static void main(String[] args) { 
			double [] list = { 11, 21, 31, 41, 5 };
			double result = sumUntil (5, list);
			StdOut.println ("result: " + result);
			/*
				result = 0.0
				result = 0.0
				result = 0.0
				result = 0.0
				return, from i = 4
				result = 41.0
				return, from i = 3
				result = 72.0
				return, from i = 2
				result = 93.0
				return, from i = 1
				result = 104.0
				return, from i = 0
				result: 104.0
			*/
		}
	}
//-------
	public class TestingE {		// pure recursive, factorial
		public static int f (int n) {	
			if (n <= 0) return 1;
			int nMinus1 = f (n-1);	// iterates, starts returning at n=0, multiplys back 
			return n * nMinus1;
		}
		public static void main(String[] args) { 
			StdOut.println(f(4));
		}
	}
//-------
}

{// class
	public class Testing {
		int atr = 3;		// creates a class Testing with a main method and atr/field
		public static void main(String[] args) {
			Testing obj = new Testing();	// default constructor
			System.out.println(obj.atr);	// accesses object's attribute
		}
	}
//-------
	public class Class {	// Two classes, seperate files, this one is saved as Class.java
		int x = 5;
	}
	class Testing {		// Testing.java  // contains main method for execution, main method must be in seperate .java file
		public static void main(String[] args) { 
			Class obj = new Class();		// can also call Class's public methods in its file (as long as it is applied to a Class object)
			System.out.println(obj.x);
		}
	}
//-------
	public class Testing {
		int atr1 = 3;		// creates a class Testing with a main method and atr/field
		final String name = "Ben";	// cannot change this attribute
		public static void main(String[] args) {
			Testing obj = new Testing();
			obj.atr1 = 4;	// can change this atr value
			System.out.println(obj.name);	// accesses object's attribute
		}
	}	
//-------
	public class Testing {	// public vs static class methods
		int x = 3;
		static void print() {
			System.out.println("Hello!");
		}
		public void print_p() {		// public: any other method in the class can call this method 
			System.out.println("Hi!");
		}
		public static void main(String[] args) {
			print();	// static methods can be called without creating an object
			Testing t = new Testing();
			t.print_p();	// public methods needs an object
		}
	}
//-------
	public class Testing {	// constructor
		int atr;	// initialize attributes
		public Testing() {	// no args constructor	// must not return
			atr = 3;
		}
		public method() {
			return new Testing();	// returns Testing obj
		}
		public static void main(String[] args) {
			Testing obj = new Testing();
			System.out.println(obj.atr);	// accesses object's attribute
		}
	}
//-------
	public class Testing {	// one constructor
		int atr1;
        int atr2;		
		public Testing(int num) {		
			atr1 = num;     
		    this.atr2 = num;		// this obj can also be used if naming issues
		}
		public static void main(String[] args) {
			Testing obj = new Testing(10);
			System.out.println(obj.atr);	// accesses object's attribute
		}
	}
//-------
	public class Person {	// saved in seperate file, shows get/set methods for accessing private attribute
		private String name; // private: error if obj.name is accessed directly
		public String getName() {  // allows access to atr
			return name;
		}
		public void setName(String newName) {
			this.name = newName;	// current object 
		}
	}
	public class Testing {
		public static void main(String[] args) {
			Person myObj = new Person();
			myObj.setName("John"); // Set the value of the name variable to "John"
			System.out.println(myObj.getName());
		}
	}
//-------
public class Fraction {
    private Integer numerator;
    private Integer denominator;
    public Fraction(Integer num, Integer den) {
        this.numerator = num;
        this.denominator = den;
    }
    public Fraction(Integer num) {  // overloaded constructor for ints
        this.numerator = num;
        this.denominator = 1;
    }
	public String toString() {  // helps in println function
		return numerator.toString() + "/" + denominator.toString();
	}
	public boolean equals(Fraction other) {  // obj1==obj2 is same object in memory, this is if the atrs are equal 
		Integer num1 = this.numerator * other.getDenominator();
		Integer num2 = this.denominator * other.getNumerator();
		if (num1 == num2)
			return true;
		else
			return false;
	}
    public Fraction add(Fraction other) {
        Integer newNum, newDen, common;
        newNum = other.getDenominator()*this.numerator + this.denominator*other.getNumerator();
        newDen = this.denominator * other.getDenominator();
        common = gcd(newNum,newDen);
        return new Fraction(newNum/common, newDen/common );
    }
    public Fraction add(Integer other) {  //overloaded method
        return add(new Fraction(other));  // calls overloaded constructor
    }
    public static void main(String[] args) {
        Fraction f1 = new Fraction(1,2);
        Fraction f2 = new Fraction(2,3);
        System.out.println(f1.add(1));
    }
}
//-------
}
















