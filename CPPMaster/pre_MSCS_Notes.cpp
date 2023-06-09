//	*********		Master Template	***********

//	Includes
{
	#include <iostream>     // input/output library, used for cout <<, cin >>, endl can be chained
	#include <climits>   // also can use <cfloat>,  sizeof(type or var) and precision of the data types for your compiler
  #include <vector>      // allows vector<type>
  #include <iomanip>  // for setprecision(num), provides defns for manipulators ised to format I/O
          setw(num);
	#include <cctype> //  functions for testing and converting character case, c is char
		isalpha(c); isalnum(c); isdigit(c); islower(c); isprint(c); ispunct(c); isupper(c); isspace(c);
        tolower(c); toupper(c); 
  #include <cstring>	// see below
  #include <cstdlib>      // functions convert strings to other types, 
       used for srand, rand() % max + min; random in [min, max],  RAND_MAX;
	#include <string>       // C++ string, in std namespace, default initialized to an empty string
	#include <ctime>       //    used for initial random seed srand (time(nullptr));
	#include <algorithm>  // random_shuffle ( (var.begin(), var.end() ); 
	#include <cmath>		// sqrt(num);	cbrt(num); pow(num1, num2); sin(num); cos(num); 
		ceil(num); floor(num); round(num); 
	#include <fstream> 	//  file streams
		std::fstream var{"myfile.txt", std::ios::in | std::ios::binary};
		std::ifstream var{"myfile.txt", std::ios::binary}; // std::ios::in is default
		var.open("myfile.txt", std::ios::binary);	// std::ios::in is default
		var.close(); var.is_open() var.eof(); std::getline(streamobj, string); in_file.get(c);	// also out_file.get(c);
		std::fstream var{"myfile.txt", std::ios::out | std::ios::binary};
		std::ofstream var{"myfile.txt", std::ios::binary} // std::ios::out is default
		std::ofstream var{"myfile.txt", std::ios::trunc}	// can also have below 2nd arguments
			{std::ios::app}, {std::ios::ate}
		streamobj.get(char); streamobj.put(char);
	#include <sstream>
		std::istringstream var{string}; std::ostringstream var{}; ostringobj.str(); std::stringstream var{string};
	#include <limits>	
		std::istringstream_var.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); 
  #include <memory>   // for smart pointers
    std::unique_ptr<Class> ptr = std::mare_unique<Class>()
}	
//  Variables/Objects, Types, Classes, Functions, and Pointers
{
	type var{init}; type var = init;	//initialization
	type var2{null};
	var = var2 // this is assignment not initialization
	using namespace std;    // standard namespace, otherwise use std::cout, cin, endl, boolalpha, noboolalpha
	// l-value = r-value 	// r-value is stored into into a temp value that gets destroyed after it is assigned to l=value
	var = num; 	// var is l-value, num is r-value 
	var2 = function(var1)		// var2 is l-value, function(var1) is r-value
	extern type var;    picks variable from somewhere else
    type var1 { }, var2 { };   var1 = var2 = 0; sets both 0, initialization is { } or ( ),
    types are int, float, double, bool, char, size_t 
    var = 16'000'000L; 3x10^9 is 3e19, assignment is =, L for long, LL for long long, U unsigned, F float 
    static, const, constexpr, enum, unsigned, long long, short used before type var { };
    static_cast<double>(var);   (double)var;    var is upgraded to double
    enum seqn {list with commas};
    seqn var {elem};    // enum makes var of type seenumqn
  #include <cctype> and #include <cstring>       //    any var here can be "string", may need std::     
    char var [size] {"string"}; strcpy( var, "string");  copys "string" into right of var
    strcat(var1, var2);  strlen(var);  cin.getline(var, 50); display full string with wtespc
    strcmp(var1, var2); // if = returns 0 ,if not its (pos or neg)
  #include<string>        // C++ strings (can use operators)       
    std::string var; string var {" "}; string var {" ", pickout}; 
    string var1 {var2}; string var (var, i_0, pickout); string var ( howmany, 'X');       
    string var1 = var2; var1 + var2; var[ ]; var.at(num), for (char c: var)
    var.substr(i_0, pickout); var.find(" " or ' ' or var, i_0 ); var.find(" " or ' '); var.rfind(" " or ' ', i_0 ); var.erase(i_0, howmany); var.clear();
    var.length( );  getline(cin, s1); getline(cin, s1, 'char to stop at');   
    string::npos; npos is nopos func output, var.insert(i_0, " "); var1.swap(var2); var.empty();
	
	// Pointer and Reference syntax
	type *var_ptr {nullptr}; type* var_ptr{nullptr}; type *var_ptr{&var};	*var_ptr; // dereference
	var_ptr + num; *(var_ptr + num); 
	var = new type; delete var_ptr; delete [] var_ptr; var_ptr = new type[numof];	// allocating num of types  on heap
	type var2{num}; type &var1{var2}; // var 1 "points" to var2, changing one changes both, var1 is an l-value	
	type &&var{num}; // var is an r-value 

	array_ptr; *array_ptr; array_ptr + num; array_ptr[ith]; *array_ptr[ith]; *(array_ptr + num); 	// same as next line since arrays are pointers
	array;       *array;      array + num;                             *array[ith];      *(array+num);		// array is address of first element
	var_ptr++; var_ptr--; var_ptr += num; var_ptr -= num; 	// and on *var_ptr
	//	can use aritmetic and comparison operators and on var_ptr and *var_ptr
	const type *var_ptr{&var}; type *const var_ptr{&var}; const type *const var_ptr{&var};	
	(*vector).at(num);

	//	Picture of memory:
	// heap							// "new" allocates memory here
	// stack:						// pop on pop off
		// other functions		// lose local pointers when pops off
		// main function			// any "new" allocated pointers will point to memory on heap, must "delete" deallocate any "new" pointers but not any local pointers from stack
}
//  Array and Vectors
{
    Arrays:  type array [size] {list};  array[select start at 0] = assign; array[rows][columns] { {row list}, . . . , {row list } };
		type function (const type array[], int size); // prototype, const stops changing actual array, need size, same for string
		
	vector <type> var (size, num);  vector <type> var { list }; vector <string> var {"string1", "string2"};
    	var[select]; var.at(select);   var.push_back(select) // places element at end
        var.size( ); var.clear( ); var.begin( ); var.end( );
        vector <vector<int>> var { {row}, . . . , {row} }; 
        var.push_back(another vector); var.at(select from row).at(select from column);
        var[row][column]; *(vector_ptr).at(num);
}
//  Operators (perform right to left if equal in ordering)
{
	+, - , * , / , %, exp(), ++num; num++; --num; num--; 	// arithmetic  (./ is /)
    ==, !=,  &&, ||, <, <=, >, >=, %=, <=>, /=	  // comparison and logic  (./= is /=) 
	:: // scope resolution operator  // num % 2 = remainder
}	
// Cout and Cin 
{
	==============
	double epsilon{1};		// approximation of machine epsilon
	do 
		epsilon /= 2;
	while( (1+ epsilon) != 1 );	
	epsilon *= 2;		// when it div by 2 the last time, they are equal and it breaks the loop
						  // this brings it back to the last time they are not equal, anything smaller would be =  
	cout<< setprecision(16) << boolalpha;
	cout << "C++ reports epsilon: " << numeric_limits<double>::epsilon()<< endl;
	cout << "approx epsilon = " << epsilon << ", " << "1 == 1 + epsilon : " <<  (1 == (1+epsilon) ) << endl;
	=============
	cout << numeric_limits<float>::min() << endl;	// need #include <limits>
	cout << numeric_limits<float>::max() << endl;
	cout << numeric_limits<double>::min() << endl;
	cout << numeric_limits<double>::max() << endl;
	cout << numeric_limits<long double>::min() << endl;
	cout << numeric_limits<long double>::max() << endl;
	float div;
	div = 1.0/3.0;
	cout << setprecision(40) 	// need #include <iomanip>
		   << "  123456789x123456789x123456789x" << endl;
	cout << div << endl;	// only shows 25, accurate up to 7 dec places
	double div_2;	// same for long double
	div_2 = 1.0/3.0;
	cout << setprecision(100)	// shows # of places after dec point
		   << "  123456789x123456789x123456789x123456789x123456789x" << endl;
	cout << div_2 << endl;	// only shows 54, accurate up to 16 dec places, not including ones place
	==============
	cout << boolalpha;      // displays true ot false instead of 1 or 0
	std::cerr << "Error";	// like cout for errors
	std::clog << "This is a log message";
	cin >> var;  // stores user input in var, automatic next line	// should use windows/linux terminal not IDE's for this to work
	cout << "\n" << var << endl;    // \n and endl are next line, "\t" is tab
	==============	
	std::cout << std::hex; // works for dec and is fixed for rest of program, must be an int
	std::cout << std::oct << var;
	std::cout << std::showbase << std::uppercase << std::showpos	// shows prefix 0octnum, 0xhexnum, uppercase letters in hex, fixed, can add no to remove
	std::cout.setf(std::ios:boolalpha);	// can use for showbase, uppercase, showpos, basefield 
	std::cout.unsetf(std::ios::scientific | std::ios::fixed);	//resets to default float, | is or
	std::cout << std::resetiosflags(std::ios::boolalpha);	// resets boolean output to default
	std::cout << std::resetiosflags(std::ios::basefield);	// can do for showbase, showpos, uppercase, floatfield
	==============
	// var must be at end, all other movements, justifications, fills before var but in any order
	std::cout << std::setw(num) std::left << << var;	// can do right, right is default 
	cout << setfill('char') << setw(num1) << var1 << setw(num2) << var2;	//fills remaining num1 spaces with char, also with var2
	==============
	std::cout << std::setw(num) << std::setfill(char) << "";		// displays num of chars 
	==============
	cout << "123456789x123456789x123456789x123456789x123456789x" << endl;
	cout << setfill('-');
	cout << setw(5) << left << "US"
		 << setw(10) << left << "Chicago"
		 << setw(15) << right << "8560000"
		 << setw(20) << right << "354.45" << endl;
	// Displays:  | are at the last digit of the var's left justified width
	// 123456789x123456789x123456789x123456789x123456789x
	// US--|Chicago--|--------8560000--------------354.45	
	==============
	// may need std::
	cout << var << setprecision(num);   // rounds var to number of digits
	cout << setprecision(num) 	// persists for other output
		 << fixed		// fixes number of digits after dec pt, based on precision
		 << showpos;	// displays+ 
	cout << setprecision(num) << scientific << uppercase;	// puts in sci notation
	cout << showpoint	// adds trailing 0s up to precision value, noshowpoint toggles back 
	=============
    char c { };       // add this to stop console from closing at the end of a program run outside an IDE 
    cout << "Press any character to quit: ";	// don't need this in IDE if use linux/win terminal
    cin >> c;
	=============
     char selection {};
	string title;
	cout << ">> ";  
	cin >> selection; // >> places a \n at the end
	cin.ignore();           // .ignore ignores the \n
	cout << "Enter the name of your recipe: ";	// skipping this error appears
	getline(cin, title);
	cout << title << endl;
     ==============
}
// Control (Procedural)
{ 
    break; continue;
	============
    if (expr1) {            //  (expr1); and no block or statement is do nothing if statement is true
        ;
    } else if (expr2) { 	// don't need an else or else if	
        ;
    } else 					
        ;
	============
    (expr ? stat1 : stat2 ); // execute stat1 when expr true, stat2 when false     // same as if
	============
    for (type var { }; expr; incrvar) {
        ;
    }           //  can add more vars with commas, 
	============
    for (auto elem : sequence) {        // automatically figures out type of elem within sequence
        ;
    }          //   sequence can be string, array, vector
	=============
    switch (var) {                
        case choice1: {     // choice1, choice2 are possible choices for var
            statement;
        }
	   break;              // can omit break to continue through 
        case choice2:   
            statement;
	   break;
        default:      
            statement;
    }
	============
    while (expr) {     //   expr must stay true 
         ;
    }
	============
    do {
        ;
    } while (expr) ;    // need ;
	=============
	type function(type var1, type var2) {		// can use void in type, no return needed for void, can add in pointers
		statements;										// can use const in var type
		return expr;		// expr evaluates to function type, breaks out of the function
	}	
	============
	type function(type, type);	// function prototype, used to be able to write function defn anywhere in .cpp file 
	int main() {					// can also include var1 and var2 in prototype
		function(var1, var2);	// print this function inside main for printing "Hello"
		return 0;					// can add more of the same function and their prototypes with different arg types (not return type) to overload
	}									// overloading uses same function names
	type function(type var1, type var2) {		// can use void in type, no return or arg needed for void, can add in pointers
		statements;										// can use const in var type
		return expr;		// expr evaluates to function type, breaks out of the function, can add in multiple returns
	}	
	============
  // pointer example
		type var{num};		
		type *var_pointer{nullptr}	// initialized to 0 location, can also initialize to &var, must be the same type
		var_pointer = &var 	// var pointer now points to the location of var or l-value
		cout << *var_pointer;		// dereferences the pointer, displays value in var
		*var_pointer = num2;		// assign num2 to var
	============
	type *function (type *var_ptr) {	 // call using function(&var) or function(var_ptr), &var is location of var
			expr of var_ptr;				// for arrays this is different, since the array name is the location of the first element
			return expr;					// returns a pointer
	}
	============
}
//  Useful Loops/Functions
{
	============     
	void display_matrix_indices(int n, int m) {	// displays them as a grid, same as below
		for (int i {0}; i < n; ++i ) {          
			for (int j {0}; j < m; ++j ) {
				cout << "("<< i << "," << j << ") ";
			} 
			cout << endl;
		}       
	}
	============     
	void display_matrix_indices(int n, int m) {
		int i{0}, j{};          
		while (i < n) {    
			j = 0;      // if this isn't here then j stays at 4 and fails inner loop condition
			while (j < m) {
				cout << "(" << i << "," << j << ") ";
				++j; 
			}   
			cout << endl;
			++i;
		}
	}
	============   
	int smallest_element(vector<int> vec) {		// finds the smallest in a vector of ints
		int smallest{vec[0]};					// can modify this function for largest
		for (unsigned int i{1} ; i < vec.size() ; ++i) { 
			if (vec[i] < smallest)	
				smallest = vec[i];
		}
		return smallest;
	}	
	============  
	bool find_int_in(const vector<int> &v, int target) {		// finds an integer in a vector of ints, returns true or false
		for (auto num: v)
			if (num == target)
				return true;
		return false;		
	}
	============
	void display_unique_pairs(unsigned int n, unsigned int m) {  // displays unique combination pairs of element indices , in a triangle  
		for (unsigned int i {0}; i < n; ++i ) {                  
			for (unsigned int j {i +1}; j < m; ++j ) {
				cout << "("<< i << "," << j << ") ";
			} 
		cout << endl;
		} 
	}	
	============      
	int main( ) {		// adds q press to quit in C strings
		char x {};
		do {           	
			// enter rest of program
			cout << "Enter q to quit: ";
			cin >> x;
		} while ( x != 'q');
	}
	============
	int main( ) {		// adds q press to quit in C++ strings, need #include <string>
		string input;
		do {           	
			// enter rest of program
			cout << "Enter q to quit: ";
			cin >> input;
		} while ( input != "q");
	}    
	============   
	void display_position_of_word(string text) {	// asks user to enter a word to find in text, finds the pos of first char when matches
		string word;           // finds entered word in obj and displays position    
		cout << "Enter a word to find: ";
		cin >> word;
		size_t position = text.find(word);
		if (position != string::npos)       //npos is nopos func output from .find
				cout << "Found " << word << " at position: " << position << endl;       
		else
				cout << "Sorry, " << word <<  " not found" << endl;
	}	
	============ 
	void counting_substrings(const string &word, const string &text) {		
		size_t position = text.find(word);	// word as a substring of text
		if (position != string::npos) {    //npos is nopos func output from .find
			++substring_counter;	// substring_counter is global in scope
			cout << text << " ";	// produces each text that word is found in
		}
	}
	============
	bool find_substring(const std::string &word_to_find, const std::string &target) {
		std::size_t found = target.find(word_to_find);	// same as above but as a boolean, without counting
		if (found == std::string::npos)					// returns false if nopos, true otherwise (found)
			return false;								// can call this function in an if condition
		else
			return true;
	}
	============
	string encryption(string message) {		// returns an encrypted message in a random encryption
		string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ "};
		string encryption = alphabet;
		random_shuffle( encryption.begin( ), encryption.end( ) );     // needs #include <algorithm> 
		cout << "encryption: " << encryption << endl;
		string encrypted_message;
		for (size_t i{0} ; i < message.length( ); ++i ) 
			encrypted_message += encryption.at(alphabet.find(message.at(i)));  
		return encrypted_message;
	}	   
	============   
	int subt_numbers(int, int = 10);			// illustrates function prototypes, allows functions to be called in any order
	int add_numbers(int, int);				// 10 is the default value, defaults on right-wise arguments
	int main() {											// function calls inside main program
		int actual1{}, actual2{}, difference{};	// sum is initialized to function is evaluation
		cout << "Enter two numbers to add and subtract: ";
		cin >> actual1 >> actual2;
		int sum = add_numbers(actual1, actual2);	
		difference = subt_numbers(actual1);		// actual2 is set to default 10
		cout << "sum = " << sum << ", and difference = " << difference << endl; 
		return 0;
	}	
	int subt_numbers(int formal1, int formal2) {	// can use void for type on function, good for cout statements
		return formal1 - formal2;
	}
	int add_numbers(int formal1, int formal2) {		//	functions operate on copies of actuals called formals
		return formal1+ formal2;							// actuals unchanged here
	}
	============
	void swap (int&, int&);		// Illustrates use of &ints, which accesses actual vars, can leave out vars in prototypes
	inline void print (const int &a);	// inline avoids overhead for simple functions, compiler may already do this
	int main() {		// This program swaps (x,y), prints safely with const, without copying actuals to formals
		int x {3}, y{4};
		print(x);
		swap(x, y);					// x,y initialized, function call inside main, prototypes before main		
		print(x);
	}	
	void swap (int &a, int &b) { 		// switches a and b, &a is the address of actual a
		int temp = a;				// &a allows function to access actual x and change it
		a = b;						// can add * to all a's and b;s (remove &'s) and its now in terms of pointers
		b = temp;
	}
	void print (const int &a) {  	// prints a without copying to formal, const avoids any pontential change to a in function
		cout << a << endl;		
	}
	=============
	void see();	
	int num1 {1};
	int main () {				// illustrates scope
		int num2 {2};
		{	
			int num3 {3};
			cout << "in block: " << num1 << ", " << num2 << ", " << num3 << endl;	// can't see num4
			see();
		}
		cout << "in main: " << num1 << ", " << num2 << endl;		// can't see num3, num4
		return 0;
	}
	void see() {
		int num4 {4};
		cout << "in function: " << num4 << ", " << num1 << endl; 	// can't see num2, num3
	}
	=============
	void change_global();	// static vs global
	void static_var ();
	int num1{1};	
	int main () {
		change_global();	// num1 is 2
		cout << "global num1 changed to " << num1 << endl;		
		change_global(); // num1 is 3
		cout << "global num1 changed to " << num1 << endl;
		static_var();	// num2 is 3 but not in this scope
		static_var();	// num2 is 4	
		return 0;
	}	
	void change_global() {
		num1 +=1 ;		// changes actual global num1 (since num1 is not passed in)
	}
	void static_var () {			
		static int num2 {2};	// static holds on to current num2 value, preserves for future calls
		num2 += 1;				// without static num2 is reinitialized to 2
		cout << "static num2 is changed in function to " << num2 << endl;	
	}	
	=============
	unsigned long long factorial (unsigned long long = 3);		// default is 3, can add more defaults always to right
	int counter {0}; 		// example of a global counter			// default is only in prototype
	int main() {
		unsigned long long result {factorial()};
		return 0;
	}
	unsigned long long factorial (unsigned long long n) {	// recursive function
		++counter;
		if (n == 0)
			return 1;
		return n * factorial(n-1);
	}
	=============
	void print_vector(const vector<auto> list) {		// prints a vector of anything, arg is a vector
		cout << "[";								// can put * on all lists to write in terms of pointers, add & inside function call
		for (auto elem : list) 
			cout << " " << elem;
		cout << " ]" << endl; 
	}
	=============
	int n{0};		// compares size of two vectors, picks smaller size
	if( names.size() < answers.size() ) 
		n = names.size();
	else if ( names.size() > answers.size() )
		n = answers.size();
	else	
		n = names.size();
	=============
	double mean_of_vector (vector<double> vec) {	// finds mean of vector of doubles
		double mean { }, sum { };
		for (auto elem : vec)
			sum += elem;
		mean = sum / vec.size( );   
		return mean;
	}
	==============
	void function (int *);	// illustrates how functions can pass * pointers and call & addresses
	int main() {
		int var{10};
		int *ptr{&var};	// points to var's address
		function(&var);	// don't need & if var is an array
		function(ptr);
		return 0;
	}
	void function (int *var_ptr) {	// 1st * is declaring a pointer or mem location, 2nd* is derefence, or going to location's value
		cout << *var_ptr << " is in location " << var_ptr << endl;		// this is actually pass by ref, in that it could change the actual var
	}	
	================
	void display_array_until(int *array, int sentinel) {		// displays each element in an array, seperated by a space, arg is a pointer
		while (*array != sentinel)		// the sentinel is the stopping point
			cout << *array++ << " ";	// ++ on array_ptr then *, although ++ > * in precedence
		cout << endl;						
	}
	int main() {
		int array [] {1, 2, 3, 4, 5, 6, 7, 7};
		int *array_ptr{array};	// normally need &, but don't since array
		display_array_until(array, 4);		//  can't use & since array is address of first elem, unlike other types
		display_array_until(array_ptr, 4);	// this also works
		return 0;					// can use display(array_ptr)
	}
	================
	void print_array_elements(const size_t size, int *const array_ptr) {		// displays without changing pointer or values ,arg is a pointer
		for (int i{0}; i < size; ++i)				// call using print_array_element(size, array_ptr); // don't need & since array
			cout << array_ptr[i] << endl;		// normally would derefence here, but don't need to since is an array
	}														// could clean this up to remove _ptr, since array name is a ptr?
	================
	int *largest(int * , int *);					// returns the location of the variable that contains the larger int
	int main() { 									// be careful not to return any local (sometimes called formal) var's location if you need the actual var's
		int num1{100}, num2{200};
		int *location_of_largest{nullptr};
		location_of_largest = largest(&num1, &num2);
		cout << "The location of num2 is: " << &num2 << endl;
		cout << "The location with the largest integer is: " << location_of_largest << endl;
		return 0;	
	}	
	int *largest(int *var1_ptr, int *var2_ptr) {
		if (*var1_ptr > *var2_ptr)
			return var1_ptr;		// returns pointers
		else
			return var2_ptr;
	}
	================
	void print_array_elements(int array[]); 	// function that accepts full array as arg, displays each elements, no pointers
	int main() { 
		int nums[] {40, 35, 60};
		print_array_elements(nums);
		return 0;	
	}	
	void print_array_elements(int array[]) {		//prints actual array, but wouldn't if another type
		for (int i{0}; i < 3; ++i)
			cout << array[i] << endl;
	}	
	=================
	void double_data(int *ptr) {
    *ptr *= 2;		// changes value ptr is pointing to permanently
	}
	int main() {
		int value {10};
		cout << value << endl;
		double_data(&value);
		cout << "Value: " << value << endl;
		double_data(&value);
		cout << "Value: " << value<< endl;
		return 0;
	}
	==================
	void display_vector( const vector<string> *const  list_ptr) {		// displays each member of a vector string using pointer 
		for (auto str: *list_ptr)												// illustrates const pointer and const vector
			cout << str << " ";													// call using display_vector(ptr) or display_vector(&vector)
	}
	==================
	void print_array_locations(int array[]); 	// prints locations of an array in a local function by not using pointers and passing the whole array
	int main() { 											// would not work with other types
		int nums[] {40, 35, 60};
		cout << "The locations are: " << endl;
		print_array_locations(nums);
		return 0;	
	}	
	void print_array_locations(int array[]) {		
		for (int i{0}; i < 3; ++i)
			cout << &array[i] << endl;
	}	
	=============
	int *allocate_array_init(size_t size, int fill) {		// allocates new array of storage on heap
    int *new_storage {nullptr}; 											// returns a pointer
    new_storage = new int[size];   						
    for (size_t i{0}; i < size; ++i)
      *(new_storage + i) = fill;
    return new_storage;
	}
	// delete [] new_storage;	// don't forget to deallocate any "new" memory from stack, avoid deallocating pointers that point to stack memory used by functions
	=============
	int square (int &n){		// illustrates r-value vs l-value, n is declared as a reference
		return n*n;
	}		
	int main () {
		int num{10};
		square(num);	
		square(5);		// can't do because 5 is not a reference (l-value)
	}
	=============
	void matrixindices_oneloop( int size1, int size2) {			// uses only one loop to produce the indices of a size2 x size1 matrix
		int k{-1};												// works the same as an above function				    
		int size_product{size1 * size2};					
		for (int i{0}; i < size_product; ++i ) {			
			if ( (i % size1) == 0 )  {									
				++k;
			}
			cout << "k = " << k << endl;
			cout << "i % size1 = " << i % size1 << endl; 
		}
	}
	=============
	void display_table_row(std::string city_name, int width2, long city_population, int width3, 	
		double city_cost, int width4, int width1, std::string country_name) {
			std::cout << std::setw(width1) << std::left << country_name		// displays one row at a time, with mixed left and right justifications
						<< std::setw(width2) << std::left << city_name			// can write as one long cout statement
						<< std::setw(width3) << std::right << city_population
						<< std::setw(width4) << std::right << city_cost << std::endl; 	// to do: make this input something so its not fixed at 4 column
	}
	=============
	void dashes(int width, char dash) {
		cout << setw(width) << setfill(dash) << dash << endl;
		cout << setfill(' ');	// resets setfill
	}
	=============
	void display_centered_title(std::string title, int display_width) {		// centers title based on width of whole table
		int title_length = title.length();
		std::cout << std::setw((display_width  - title_length )/ 2) << "" << title << std::endl;
	}
    =============
	int grade_string(string answer) {	// counts how many letters match comparing answer to key 	
		string key{"ABCDE"};
		int score{0};
		for (size_t i{0}; i < answer.length(); ++i) {
			(answer.at(i) == key.at(i) ? ++score : score = score);
		}
		return score;   
	}
	=============
     bool Movies::add_movie(std::string name, std::string rating, int watched) {  // using & in a loop
     for (const Movie &movie: movies) {  // movies is a Movies vector of Movie objects 
          if (movie.get_name() == name)   // checks if movie is in movies by name, if it is returns false
               return false;                                // if it isn't, adds movie to movies, returns true
     }             //  get_name, is a Movie method that returns name attribute
          Movie temp {name, rating, watched};
          movies.push_back(temp);
          return true;
     }
     =============
}
//  Object Oriented Control
{
 	=============
  class Class {	// lives outside main to be global in scope, but can be inside or local to main if necessary
    // can friend things from other classes, see below
    private: 	
      type attribute1;	// like vars // attribute is visible to any method defn, can initialize here, more efficient to use list below
      type attribute2;	// careful when using pointers here and calling a destructor too soon
    public:	// need this to be able to call methods in main, everything in class after is public	
    // can use private and protected, private is default	
    type method(type) {	     // set/get methods can be called anywhere to access private attributes
      method defn;
    }	
    type method2(type); // prototype here, implemented outside class below
    Class() 	// no args constructor, can do more overloaded constructors
      : attribute1{initial}, attribute2{initial} { // initialization list
    }
    ~Class () {	// will destroy member out of scope, including locals when the function is complete
    }
  };	
  Class::Class()	// constructor initialization list, add one for each constructor
    : attribute1{initial}, attribute2{initial} {
  }  		
  type Class::method2(type var) {	// can implement other things like constructors outside of class with Class::things notation
    // statements involving class attributes and var;
  }	
  Class &Class::operator=(const Class &rhs) {	// operator = is overloaded
  }	
  int main() {
    Class obj;
    obj.attribute{};	// can't access unless public
    type var{initial};
    obj.method2(var)	
  }
  =============
	// Class.h		// can also use .hpp
		#ifndef _CLASS_H_	// all 3 #'s avoid a duplicate file compiler error
		#define _CLASS_H_		// this forces the complier to read .h only once, if .h is included in multiple .cpp files
		// other necessary includes  // can also use #pragma once, instead of 3 #'s
		class Class {
			// declarations, public and private
			// attributes 
			// methods
				// prototypes or defns
			// constructor prototypes for those defined outside class defn	
			// constructors and destructors defns
		
		};
		#endif	
	// Class.cpp
		#include "Class.h"	// "" for your local files,  < > for system's 
		// other method defns not already defined in class defn (inside .h)
		type Class::method(type var) {
			// statements using var defined in main and
			// attributes in class defined in .h 	
		}	
		// other constructor and destructor defns that are outside class defn 
	// main.cpp		// using other .cpp and .h files to store methods for classes
		#include "Class.h"	// no methods or class declares necessary
		// other necessary includes and namespaces
		int main() {
			// main program, can call public Class attributes/methods with .
			type var;
		}	
	=============
	// 	class.h
		// add guards to top and bottom
		// #includes and using namespaces
		// Class declaration of attributes and function prototypes
		// non class function prototypes and global constants
	// 	class.cpp
		// #include "class.h"
		//	class function definitions
		// non class function definitions
	// 	main.cpp
		//	#include "class.h"
	=============
	// Directions to use other .cpps and .h in CodeLite:
		// go to workspace > project > src > New Class
			// enter Class in Name, _CLASS_H_ in block guard
		// get rid of auto generated stuff in .h file, except for # block guards
			// copy class declaration to .h
			// avoid using namespace std; in .h file, include<> that you need
		// in Account.cpp remove automated constructor and destructor
			// copy method defns, functions, constructors outside class defn
			// add in std:: or whatever namespace you need, avoid using namespace std;
		// in main.cpp // #include "Account.h"
			// build and run project 	//  .cpps are compiled and linked with .h to produce .exe	
	=============
}

//	Object Oriented Examples
{
	=============
  class Player {	//declaring a Class and initializing, no initializer list here so it is less efficient
    public:		// without this is private by default	
    string name {"Player"};	// attributes or objs, can be called in method without passed in as an argument
    int health {100};	
    int xp;	// without initializer it will hold garbage data
    void talk(string text_to_say) {  // can create method defn here or outside class defn
      cout << name << " says " << text_to_say << endl;  // checks the class's scope, then check's global  
    }			// name is visible to method, text_to_say initialized in main (could be global)
    bool is_dead();		// method/function prototype, will compile without a defn, but not linked
	};
	int main() {
    	Player ben;
		ben.xp = 12;
		ben.talk("Yes!"); 
		ben.health = 50;
		ben.name = {"Benson"};
  }
	=============
	// with the same Class as above defined, below in main:
     Player ben;
     Player hero;
     Player players[] {ben, hero};    // array of objects in Player Class
	vector<Player> player_vec {ben};  // vector of Players class, initialized to ben
	player_vec.push_back(hero);    // places hero on the end of player_vec
	=============
	// with the same Class as above defined, below in main:
	Player *enemy {nullptr};       // pointer to nowhere of Class Player
	enemy = new Player;     // allocates a new player, gives it a pointer
	(*enemy).name = "Enemy";	// dereference or access enemy name through pointer 
     enemy->xp = 15; // member of pointer operator, same as above line, but for xp method  // this->xp is "this" object pointer in debugger points to attribute
	enemy->talk("I will destroy you!");   
	delete enemy;   // deallocates the memory enemy location
	=============
	class Player {	// private vs public
	private:	// only accessible from other methods and friends of this class
		string name {"Player"};	// these attributes can't be accessed directly, only from within its class
		int health{100};	// no constructor initializer list here, so it is less efficent
		int xp;
	public:
		void talk(string text_to_say) { cout << name << " says " << text_to_say << endl;  }
		bool is_dead();		// name is accessible by talk, since it is in its class
		void attacked(int); // prototype, defn implemented below
	};
	void Player::attacked(int num) {	// implemented outside Class declaration
		health -= num;
	}
	int main() {
		Player ben;		//  ben.name = "Frank"; is error // default constructor, since one is not given 
		ben.talk("Hello there");  	//  cout << ben.health << endl; // is error
		ben.attacked(15);
		Player *mary = new Player;	// uses default constructor
		(*mary).talk("Hello");	// is ok, same as mary->talk("Hello"); 
		delete mary;	// mary->name = "Johnny"; // is error
		return 0;		// .talk is public so its ok, it can access private name, and validate changes to it
	}
	=============
	// Player.h				// simple example of declaration .h and implementation .cpp of class methods, used in main.cpp
		#ifndef _PLAYER_H_	// no constructors or destructor
		#define _PLAYER_H_
		class Player {
		private:			
			int health {100};	// better to use initializer list than this
		public:					// can also add constructos and destructor
			void attacked(int); // prototype, implemented below
		};	
		#endif // _PLAYER_H_	
	// Player.cpp
		#include "Player.h"
		void Player::attacked(int num) {	// implemented outside Class declaration
			health -= num;
		}
	// main.cpp
		#include <iostream>		// don't need this unless using cout, etc
		#include <Player.h>
		using namespace std;	// don't need this if you have std::
		int main() {
			Player Ben;
			Ben.attacked(45);
			return 0;
		}			
	=============
	class Player {	// constructors and destructors, can place this in .h file
	private:	
		string name {"Player"};	// not as efficient to initialize like this
		int health;	
		int xp;
	public:					// once these constuctors appear, c++ won'tuse default constructor 
		void attacked(int); // prototype, implemented below
		Player() { 		// 2 constuctors, add more for overloading, could add a 2 arg, 3 arg, etc. 
			cout << "No args constructor called"<< endl; // only to help see when they are called
			name = "none"; health = 100; xp = 0; // starts objects in a known state, unlike default constructor that has garbage
		}	// not as efficient to initialize with = like this
		Player(std::string); // prototype for outside class constructor below	
		~Player() { 	// destructor
			cout << "Destructor called for " << name << endl; 
		}		
	};	
	// constructor declared outside class defn, can be in Player.cpp
	Player::Player(std::string newname) { 	// can add more with name, health and,  xp args
		cout << "String arg constructor called"<< endl;
		name = newname;		// initializes to newname
		health = 100; xp = 0; // keeps any garnage data out
	}
	int main() {
		{
			Player adam;	// no args called // won't use default cnstructor if my no args constructor is removed and others stay
			Player ben("Ben");	// 2nd constuctor called, can call no args too
		}	// destructor called when object is out of scope, performed in reverse order within scope 
		Player *enemy = new Player; // no args constructor called
		delete enemy;	// destuctor called for pointers
		return 0;
	}
    =============
	class Player {	// constructors can place this in .h file
	private:		// with a delegation example but not a  singular defaulted construcotr
		std::string name;
		int health;		// more efficient to initialize below in the list than here
		int xp;
	public:					// once these constuctors appear, c++ won'tuse default constructor 
		// add methods, can also add them outside class or in Player.cpp, see above examples
		Player();	// overloaded constructors as prototypes
		Player(std:: string name);	
		Player(std::string name_val, int health_val, int xp_val);		
	};		// outside class declaration, no destructor, in Player.cpp
	Player::Player()	// constructor initialization list, no delegation for this one
		: name{"None"}, health{0}, xp{100} {	// order executed is not the same as this but in attributes
	}
	Player::Player(std::string name_val)	// delegates to 3 arg constructor
		:Player{name_val, 0, 0} { 
	}
	Player::Player(std::string name_val, int health_val, int xp_val)
		: name{name_val}, health{health_val}, xp{xp_val} {
			std::cout << "3 args called" << std::endl;
	} 	
	int main() {
		Player ben;	// properly initialized
		Player adam {"Adam"};
		return 0;
	}
	=============
	class Player {	// much more simple way to define constructors with 1, 2, or 3 args and initialize
	private:
		std::string name;
		int health;
		int xp;
	public:   // adds defaults   //  Player() {}; will cause a compiler error
		Player(std::string name_val ="None", int health_val = 0, int xp_val = 0);
	};		// no destructor, defaults in prototype
	Player::Player(std::string name_val, int health_val, int xp_val) 	// outside class, in Player.cpp
		: name{name_val}, health{health_val}, xp{xp_val} {	// initializition list
				cout << "Three-args constructor" << endl;
	}
	int main() {
		Player empty;
		Player ben {"Ben"};
		Player hero {"Hero", 100};
		Player villain {"Villain", 100, 55};
		return 0;
	}
	=============
	class Player {		// uses a user made copy constructor 
	private:			// without user copy constructor, c++ default copy constr is called that copies each member
		std::string name;
		int health;
		int xp;
	public:
		std::string get_name() { return name; }	// methods
		int get_health() { return health; }
		int get_xp() {return xp; } 
		Player(std::string name_val ="None", int health_val = 0, int xp_val = 0);	// constr w/defaults
		Player(const Player &source);   // copy constructor proto
		~Player() { cout << "Destructor called for: " << name << endl; }
	};	// constructor and function defns below need to be in Player.cpp
	Player::Player(std::string name_val, int health_val, int xp_val) // one constructor bc there are defaults above
		: name{name_val}, health{health_val}, xp{xp_val} {	
			cout << "Three-args constructor" << endl;
	}							// careful when copy constructors are copying pointer members, two pointers could point to one mem location, causing deallocation issues (shallow copy)
	Player::Player(const Player &source)	// copy constructor w/ initialization list but you can delegate to the constructor like in above example
		: name{source.name}, health{source.health}, xp{source.xp} { // copying is here, which is why you need const and & (or using pointers) in arg above, to avoid double copying
			cout << "Copy constructor - made copy of: " << source.name << endl; 
	}
	void display_player(Player p) { // p will be copied by copy constuctor above
		cout << "Name: " << p.get_name() << endl;	// function inputs an object and accesses its members through methods
		cout << "Health: " << p.get_health() << endl;
		cout << "XP: " << p.get_xp() << endl;  // copyting will also happen if this function would return something
	} 	// destructor is called when p goes out of scope (end of function)	
	int main() {    
		Player empty {"XXXXXX", 100, 50}; // not using defaults
		Player ben {"Ben", 100}	// workd because of the defaulted 3 args constructor
		Player my_new_object {empty};   // uses copy constructor
		display_player(empty);  // calls user copy constructor inside function (and destructor on local) for a local object copy		
		return 0;
	}	// destructor is called on empty and my_new_object
	=============
	class Deep {	// example of copy constructor on a pointer member, copying and deallocating properly 
	private:
		int *data;
	public:
		void set_data_value(int d) { *data = d; }
		int get_data_value() { return *data; }
		Deep(int d);
		Deep(const Deep &source);
		~Deep();
	};
	Deep::Deep(int d) {
		data = new int; // best way to copy pointer members bc it copies a value to a unique location (Deep)
		*data = d;  // avoids deallocation issues h\when calling a destructor at the end of a functions or any scope
	}
	Deep::Deep(const Deep &source)  // copy constructor delegates to above constructor
		: Deep {*source.data} {		// can also write this to force the value to copy to a unique location 
		cout << "Copy constructor  - deep copy" << endl;
	}
	Deep::~Deep() {
		delete data;
		cout << "Destructor freeing data" << endl;
	}
	void display_deep(Deep s) {
		cout << s.get_data_value() << endl;
	}
	int main() {
		Deep obj1 {100};  // obj1 memory is allocated and 100 is placed in that location
		display_deep(obj1);	// calls copy constructor at beginning, that delegates to obj creation constructor, that allocates new storage and places value in it, this is used as local in function and displayed 
		Deep obj2 {obj1};	// calls copy constructor that delagates to obj creation constructor, allocates a new location, places value in it
		obj2.set_data_value(1000);	// only changes obj2, not obj1 bc they are at unique locations
		return 0;
	}
	=============
	class Move {    // example of a move constructor, more efficient than a deep copy constructor for pointers
	private:        // moves rather than creates multiple deep copies (new locations, same value)
		int *data;
	public:
		void set_data_value(int d) { *data = d; }
		int get_data_value() { return *data; }
		Move(int d);    // normal creation constructor, for deep copying
		Move(Move &&source) noexcept;   // Move Constructor, && is rvalue ref
		~Move();
	};
	Move::Move(int d)  {
		data = new int;
		*data = d;      // deep copies create new addresses to hold the same value
		cout << "Constructor for: " << d << endl;   
	}
	Move::Move(Move &&source)  noexcept     // move constructor, only accepts r-values
	: data {source.data} {	// basically moves rather than copies temp/rvalues
		source.data = nullptr;	// nulls out temp variables (r-value) pointer, to avoid deep copying it
		cout << "Move constructor - moving resource: " << *data << endl;
	}
	Move::~Move() {
		if (data != nullptr) {  
			cout << "Destructor freeing data for: " << *data << endl;
		} else {
			cout << "Destructor freeing data for nullptr" << endl;
		}
		delete data;
	} 
	int main() {
		vector<Move> vec;            // Move{10} normal constructor creates a temp/rvalue obj    	    
		vec.push_back(Move{10});    // pushback function moves instead of copying a local Move{10} by using move constructor 
		vec.push_back(Move{20});		
		vec.push_back(Move{30});       
		return 0;
	}
	=============
     class Player{   // example of const correctness
          private:
          std::string name;
          int health;    // even if these attributes are public, const prevents access
          int xp;  
     public:                                                     // can be in prototype, all "getters" should be const
          std::string get_name() const{         // const method, need it even if method doesn't explicitly change attributes
               return name;                                // once defineed const, can't change attributes
          }
          void set_name(std::string name_val)   {
               name = name_val;
          }
     Player(std::string name_val ="none", int health_val = 100, int xp_val = 0) 	// simple constructor for 1,2, or 3 args
          : name{name_val}, health{health_val}, xp{xp_val} {	// initializition list
                    cout << "Three-args constructor" << endl;
          }
     };	
     void display_player_name(const Player &p) {  // compiler won't run this without get_name const added
          cout << p.get_name() << endl;    //  get_name needs a const, so that this function can be const
     }
     int main() {
          const Player villain {"Villain", 100, 55};    //villian.set_name should never work bc villian is const
          Player hero {"Hero", 100, 15};
          cout << villain.get_name() << endl;  
          display_player_name(villain);
          display_player_name(hero);  // if const isn't in get_name prototype then this won't compile either
          return 0;                                   // since p is const and get_name also needs const
     }
	=============
     class Player {      // using static members, for a counter, this is Player.h, need to add block guard around it
     private:                 // static members belong to whole class, not just a particular obj
          static int num_players;    // can't initialize static members here in .h, only has access to static vars
          std::string name;
          int health;
          int xp;
     public:
          std::string get_name() { return name; }
          int get_health() { return health; }
          int get_xp() {return xp; } 
          Player(std::string name_val ="None", int health_val = 0, int xp_val = 0);
          Player(const Player &source);  // copy constructor, delgated to above
          ~Player(); // destructor
          static int get_num_players();  // accesses above static variable
     };
     // #include "Player.h", this Player.cpp
     int Player::num_players {0};  // initialize static members here
     Player::Player(std::string name_val, int health_val, int xp_val) // defaulted in .h
          : name{name_val}, health{health_val}, xp{xp_val} {
               ++num_players; // all increments happening here, would have to add this to all overloaded constructors
     }
     Player::Player(const Player &source)       // copy constuctor, this is unecessary for this example since it is not used in main, but it shows delegation
          : Player {source.name, source.health, source.xp}  {  // delegating to above constructor
     }
     Player::~Player() { 
          --num_players;  // decrements on destructor call
     }
     int Player::get_num_players() {    // static function, declared in .h
          return num_players;  // num_players is static
     }
     // #include "Player.h"  // this is main.cpp
     void display_active_players() {              // accessing a static method
          cout << "Active players: " << Player::get_num_players() << endl;  // accesses static member
     }
     int main() {
          Player hero{"Hero"};     // no copying in main, but could add it and would still work
          display_active_players(); // 1
          {
               Player frank{"Frank"};
               display_active_players();  // 2
          }     // destructor called
          display_active_players(); // 1
          Player *enemy = new Player("Enemy", 100, 100);
          display_active_players(); // 2
          delete enemy;
          display_active_players();   // 1
          return 0;
     }
     =============
     struct City {		// example for using global struct, like a class but all public
		std::string name;   // need <iomanip>
		long population;
		double cost;
	};
	struct Country {
		std::string name;
		std::vector<City> cities;
	};
	struct Tours {
		std::string title;
		std::vector<Country> countries;
	};
	int main () {
		Tours tours
			{ "Tour Ticket Prices from Miami",
				{
					{
						"Chile", { 
							{ "Valdivia", 260000, 569.12 }, 
							{ "Santiago", 7040000, 520.00 },
						}
					},
					{ 
						"Argentina", { 
						{ "Buenos Aires", 3010000, 723.77 } 
						} 
					}
				}
			};
          std::cout << tours.title << std::endl;
          std::cout << tours.countries.at(0).name << std::endl;  // Chile
          std::cout << tours.countries.at(0).cities.at(0).name << std::endl;    // Valdiva
          std::cout << tours.countries.at(0).cities.at(0).population << std::endl;   // 260000
          std::cout << tours.countries.at(0).cities.at(0).cost << std::endl;    // 569.12 
		for (auto country : tours.countries) {
			for (auto city : country.cities) {
				std::cout << city.cost << std::endl;    // each cost
			}	
		}
		for (Country country : tours.countries) {
			for (size_t i = 0; i < country.cities.size(); ++i) {
			     std::cout << std::setw(15) << std::right << country.cities.at(i).population << std::endl; // each population
			}
		}		
		return 0;
	}   
     =============
     class Point {       // a non member function that is a friend to a class
          friend void ChangePrivate( Point & );   // brings in actual obj
     private:                
          int m_i;
     public:
          Point() 
               : m_i(0) {	// defaulted constructor, slightly different than above examples
          }
     };
     void ChangePrivate ( Point &i ) {  // non member function
          i.m_i++;            // accesses private attribute and changes it
     }    // ChangePrivate(Pointobj); in main
     ==============
     class B;       // A has a member function that is a friend to B
     class A {
     private:     
     public:      
          int Func1( B& b );    // accepts B members
     };
     class B {
          friend int A::Func1( B& );   // friends a function in A on B that can change members in B
     private:
          int _b;
     public:
          B()    
               : _b{0} {
          }              // A::Func1 is a friend function to class B
     };                //  A::Func1 has access to all members of B
     int A::Func1( B& b ) { // brings in actual b
          b._b += 10; }        // changes b attribute 
     int main() {   
          B bee;
          A ay;
          ay.Func1(bee);      // Funct1 is called from A, performed on B
          return 0;
     }
     ==============
     class YourClass {        // example of friend class, not transitive or symmetric
     friend class YourOtherClass;  // YourOtherClass can access YourCLass members
     private:
     int topSecret;
     public:
          YourClass() 
               : topSecret(0) {    // defaulted constructor
          }
     };
     class YourOtherClass {
     public:                       // & to bring in actual obj
     void change( YourClass& yc, int x ){ // function on YourClass
          yc.topSecret = x;}
     };
     int main() {
          YourClass yc1;
          YourOtherClass yoc1;
          yoc1.change( yc1, 5 );     // lives in YourOtherClass, accepts YourClass members
     }
     ==============
     // example of an outside function calling a method function that are similar in name but differ in # of args
     // create both classes appropriately, does not run, see ChallengeSolution Section 13
     void Movie::increment_watched() {
               ++watched;     // Movie attribute
     }
     bool Movies::increment_watched(std::string name) {
     for (Movie &movie: movies) {  // movies is a Movies obj, need & to change
          if (movie.get_n() == name) {  
               movie.increment_watched();
               return true;
          }
     }
     return false;
     }
     void increment_watched(Movies &movies, std::string name) {  // outside function
     if (movies.increment_watched(name)) {    // if increment_watched is successful
          std::cout << name << " watch incremented" <<  std::endl;
     } else {
          std::cout << name << " not found" <<  std::endl;
     }
     }
     int main() {
          // create Movies obj my_movies that is a vector of Movie objs
          // add in Movie big: ["Big", 0], "Big" is name, 0 is # of times watched
          increment_watched(my_movies,"Big");                    // OK
          return 0;
     }
     ==============
}
//	Operator Overloading
{
	==============
	class Mystring {		// example with pointer to var, but no var, passed into constructors
	private:					// this uses char arrays, where ptr name acts like the value, unlike int arrays where ptr is memory location of first element
		char *str;      
	public:
		Mystring();                                                         // No-args constructor
		Mystring(const char *s);                         // Overloaded contstructor              
		Mystring(const Mystring &source);        // Copy constructor
   		const char *get_str() const;
   		void display() const;
    		int get_length() const;
		~Mystring(); 	
	};
	const char *Mystring::get_str() const { 	// random two const getter method w/pointer not seen before
		return str; 
	}
 	int Mystring::get_length() const { 
		 return std::strlen(str); 
	}
	void Mystring::display() const {
    		std::cout << str << " : " << get_length() << std::endl;	// uses above method
	}
	Mystring::Mystring() 
    		: str{nullptr} {
    		str = new char[1];
    		*str = '\0';
	}
	Mystring::Mystring(const char *s)   	// overloaded constructor
		: str {nullptr} {        // if nullptr is passed in, start with a null char
			if (s==nullptr) {		// s is a pointer here to char array, so it acts like tis value
				str = new char[1];
				*str = '\0';		// s is dereferenced here to add \0 as its character
			} else {
				str = new char[std::strlen(s)+1];       // needs cstring, +1 for the hidden \0 null char in cstrings
				std::strcpy(str, s);    // copys value in pointed to by s  into where str points
			}
		}
	Mystring::Mystring(const Mystring &source) 	// deep copy constructor
		: str{nullptr} {
		str = new char[std::strlen(source.str )+ 1];    // str is the pointer attribute to new object, source value copied to it 
		std::strcpy(str, source.str);       // source.str is a pointer to a char string, but this copies its value into a new location str
	}
	Mystring::~Mystring() {	// destructor
		if (str == nullptr) {
			std::cout << "Calling destructor for Mystring : nullptr" << std::endl;
		} else {
			std::cout << "Calling destructor for Mystring : " << str << std::endl;
		}
		delete [] str;
	}
	int main() {
		Mystring ben;
		Mystring larry("Larry");		// "Larry" not a pointer but its value is added to what larry.str points to 
		Mystring stooge {larry}; 
	}
	==============					
	Mystring &Mystring::operator=(const Mystring &rhs) {     // overloaded operatior for above class, add prototype, deep copy assignment	// con only be implemented as a member function, not global
		std::cout << "Copy assignment" << std::endl;		// &Mystring's & is so that it returns a reference
		if (this == &rhs)       // "this" is the current obj (lhs), so if rhs turns out to be the same obj as this, this and rhs are pointers to char strings which is why you can use ==, normally can't do this
			return *this;       // returns "this" pointer, * is necessary because of &Mystring
		delete [] this->str;        // same as delete[] str; deallocates lhs obj's attribute
		str = new char[std::strlen(rhs.str) + 1];   // now allocates on heap
		std::strcpy(this->str, rhs.str);        // cstring method, rhs.str copied into this->str, char arrays so this works, unlike int arrays
		return *this;
	}	// prototype in class: 	  Mystring &operator=(const Mystring &rhs);
	int main() {						
		Mystring a{"Hello"};	// (deep copies to a new location, shallow does not),
		Mystring b;	// b is '\0' allocated on heap, this assignment is now a deep assignment and not the C++ default shallow assignment
		Mystring b = a;	// b->str which is '\0' 's location is deallocated, b is newly allocated on the heap, rhs.str coped into b, b and a have diff locations, like a deep copy
		b = "This is a test";        //	works because it is b is a pointer to a char array, unlike int arrays
	}	
	==============
	Mystring::Mystring( Mystring &&source) 		// move constructor and move assignment overloaded operator for above class, add prototype
		:str(source.str) {
			source.str = nullptr;	// source points to nothing
			std::cout << "Move constructor used" << std::endl;
	}
	Mystring &Mystring::operator=(Mystring &&rhs) {	// move assignment overloaded operator
		std::cout << "Using move assignment" << std::endl;	// && is a rvalue, unlike above with an lvalue
		if (this == &rhs) 	// checks if assigning to itself
			return *this;
		delete [] str;		// deallocates lhs's pointer str attribute
		str = rhs.str;		// sets it to rhs's 
		rhs.str = nullptr;		// forced rhs to point to nowhere to avoid mem leak
		return *this;		// returns obj's pointer dereferenced (value it points to), no delete here because it would destroy data
	}		// returns lhs set to rhs	// prototype:     Mystring &operator=(Mystring &&rhs);       
	int main() {
	     Mystring empty("blank");         // overloaded constructor from above class
		empty = "Funny";                    // overloaded constr then move assignment operator, rvalue here, above example is an lvalue
		vector<Mystring> stooges_vec;
    		stooges_vec.push_back("Larry");                // Move constructor is called
	}
	=============		// use with above class and appopriate above constuctors/assignment and destuctor
	bool Mystring::operator==(const Mystring &rhs) const {      // overloads ==	// 1st const is rhs, 2nd is lhs
		return (std::strcmp(str, rhs.str) == 0);    // strcmp is 0 if they're equal, !0 otherwise
	}			// 1 arg since == is binary  // proto:	   bool operator==(const Mystring &rhs) const;   
	Mystring Mystring::operator-() const {	// makes a mystring lowercase, noargs because - is unary
		char *buff= new char[std::strlen(str) + 1];	// buff points to allocated memory, str is a pointer atr to Mystring obj, +1 for '\0' char in str atr
		std::strcpy(buff, str);		// copys str into buff, via char pointers (does not likely work with other pointer types)
		for (size_t i=0; i<std::strlen(buff); i++)
			buff[i] = std::tolower(buff[i]);	// each char in buff string is made lowercase
		Mystring temp {buff};	// buff is copied into temp via deep copy constructor
		delete [] buff;	// buff is deallocated
		return temp;
	}		// proto: 	Mystring operator-() const;
	Mystring Mystring::operator+(const Mystring &rhs) const {	// concatenates or merges strings
		char *buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];	// +1 for '\0'
		std::strcpy(buff, str); 	// lhs str atr copied into buff
		std::strcat(buff, rhs.str);	//rhs.str is concatenated or merged on the end of buff
		Mystring temp {buff};	// temp is a deep copy of buff via deep copy constructor
		delete [] buff;
		return temp;
	}	// proto: Mystring operator+(const Mystring &rhs) const ; 
	int main() {		// need deep copy constructor bc its used inside overloaded operators
		Mystring larry{"Larry"};    // uses overloaded constructor
    		Mystring stooge = larry;    // copy constructor, not assignment since stooge wasn't initialized
		cout << (larry == stooge) << endl;   	// true
		Mystring larry2 = -larry;	// initialization of larry 2, which is "larry" all lowercase
		Mystring stooges = larry + "Moe";   // initialization of stooges and concatenates	//	"Larry" + moe would not work, but does below
		return 0;
	}
	=============	// same overloaded operators as above but as a global function (not a class method)
	bool operator==(const Mystring &lhs, const Mystring &rhs) {     // different than member overloaded operator bc it has 2 args not 1
		return (std::strcmp(lhs.str, rhs.str) == 0);	// can also do operator!=, just negate this line
	}						// each of these need to be made friends of the Mystring class, declared in the class's prototypes	// will also need the same constuctors as previous example
	Mystring operator-(const Mystring &obj) {	// main difference is in the args, above had no args, this one is 1, same idea for the others 
		char *buff = new char[std::strlen(obj.str) + 1];
		std::strcpy(buff, obj.str);
		for (size_t i=0; i<std::strlen(buff); i++) 
			buff[i] = std::tolower(buff[i]);
		Mystring temp {buff};
		delete [] buff;
		return temp;
	}		// example of prototype:	 friend Mystring operator-(const Mystring &obj);
	Mystring operator+(const Mystring &lhs, const Mystring &rhs) {
		char *buff = new char[std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
		std::strcpy(buff, lhs.str);
		std::strcat(buff, rhs.str);
		Mystring temp {buff};
		delete [] buff;
		return temp;
	}
	int main() {
		Mystring moe{"Moe"};	// overloaded constructor
		Mystring stooges = "Larry" + moe;	//  OK with global function but not as class method
		return 0;
	}
	=============
	class Money {
		friend Money operator+(const Money &lhs, const Money &rhs);	// friended global overloaded operator
	private:
		int dollars;
		int cents;
	public:
		Money(int total);
	};
	Money::Money(int total) 
		: dollars {total/100}, cents{total%100}  {
	}
	Money operator+(const Money &lhs, const Money &rhs) {	// global overloaded operator
		int total = (lhs.dollars + rhs.dollars) * 100;
		total += lhs.cents + rhs.cents;
		return Money{total};		// simple way to initialize and return an object
	}
	int main () {
		Money cash{34567};	// $345.67
		Money ben_cash(342);  // $3.42
		Money sum{0};
		sum = cash + ben_cash;
		Money{45};	// temp object, similar syntax in overloaded operator
		return 0;
	}
	=============	// overloaded << >>, can also use for string and file streams
	std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {	// overloaded << and >> operators, & in &os allows chaining of <<, similar idea for >>
		os << rhs.str;      // need to make these friends to the class to access this .str atribute,  in prototype declaration //  remember that .str is a char pointer, see  above (char points have unique syntax in when accessing value)
		return os;		// does not make sense to implement as member method since they require objs on left (obj << cout does not make sense)
	}		// const bc obj is being displayed, unlike >> where obj is being changed (no const)
	std::istream &operator>>(std::istream &in, Mystring &rhs) {	// stream>> obj	// &operator, bc we need to return a stream ref, similar above
		char *buff = new char[1000];	// allocates char array size 1000 space on heap
		in >> buff;	// places user input into buff
		rhs = Mystring{buff};      // rhs is overwritten by buff, uses move assignment and overloaded constructor
		delete [] buff;	// deallocates buff
		return in;	// returns stream as a ref (bc of the & in &operator)
	}	   // proto in Mystring:   friend std::istream &operator>>(std::istream &in, Mystring &rhs);    // similar for <<      
	int main() {		// add in above class and appropriate constructors
		Mystring curly, moe;	// no args constructor
		cin >> curly >> moe; 	// user enters in curly and moe
		cout << curly << moe;	// console displays curly and moe
		return 0;
	}
	=============		// more overloaded operators as class method for above class // add protos to class
	bool Mystring::operator<(const Mystring &rhs) const {		
		return (std::strcmp(str, rhs.str) < 0);		// compares if str < rhs.str by char order
	}	// proto:     bool operator<(const Mystring &rhs) const;               
	bool Mystring::operator>(const Mystring &rhs) const {
		return (std::strcmp(str, rhs.str) > 0);
	}
	Mystring &Mystring::operator+=(const Mystring &rhs)  {	// uses above overloaded +
		*this = *this + rhs;	// uses overloaded = and +
		return *this;
	}	// proto:		 Mystring &operator+=(const Mystring &rhs);
	Mystring Mystring::operator*(int n) const {
		Mystring temp;
		for (int i=1; i<= n; i++)
			temp = temp + *this;	// uses overloaded +
    		return temp;
	}	// proto:	    Mystring operator*(int n) const;                              
	Mystring &Mystring::operator*=(int n) {
    		*this = *this * n;	// uses overloaded * 
    		return *this;
	}    // proto:		    Mystring &operator*=(int n);          
	Mystring &Mystring::operator++()   {  // pre-increment, ++obj can also overload --, returns a ref &, unlike next one
		for (size_t i=0; i<std::strlen(str); i++)	// str is atrtibute to current obj
			str[i] = std::toupper(str[i]);   
		return *this;		// pointer to current obj, derefed
	}	// proto:		Mystring &operator++();    
	Mystring Mystring::operator++(int) { // post-increment, obj++	// nned int for post inc
		Mystring temp (*this);       // make a copy using copy constructor
		operator++();                    // call pre-increment - make sure you call preincrement!
		return temp;                     // return the old value, but still increments
	}	  // proto:  	Mystring operator++(int);   
	int main() {
		Mystring a {"frank"};
		Mystring b {"george"};
		cout << (a<b) << endl;         // true
		cout << (a>b) << endl;          // false
	     a += "-----";                      // frank-----
		Mystring s1;	// no args constructor
		Mystring s2{"12345"};	// overloaded constructor
		s1 = s2 * 3;	// 123451234512345
		s2 *= 5;	// 1234512345123451234512345
		++a;	// FRANK
		b++ // GEORGE
	}
	=============	// some of the overloaded operators above as a global function, needs friended to class, all can be called in the same way as seen in above examples int
	bool operator<(const Mystring &lhs, const Mystring &rhs) {	// have 2 args where above version (class method) has  1
    		return (std::strcmp(lhs.str, rhs.str) < 0);
	}	// proto:	    friend bool operator<(const Mystring &lhs, const Mystring &rhs) ;            
	Mystring &operator+=( Mystring &lhs, const Mystring &rhs) {
     	lhs =  lhs + rhs;		// uses *this instead of lhs above, similar for other global methods
 	    return lhs;	// uses overloaded +, =
	}	// proto:		  friend Mystring &operator+=( Mystring &lhs, const Mystring &rhs); 
	Mystring &operator++(Mystring &obj) {
		for (size_t i=0; i< std::strlen(obj.str); i++)
			obj.str[i] = std::toupper(obj.str[i]);
		return obj;	// compare to above
	}	//	proto:	friend Mystring &operator++(Mystring &obj);
	Mystring operator++(Mystring &obj, int) {
    		Mystring temp {obj};
    		++obj;      // make sure you call the pre-increment!
    		return temp;
	}	// proto:		friend Mystring operator++(Mystring &obj, int); 
	=============
}
//	Inheritance	(no multiple inheritance, beyond scope of course)
{
    =============	
     Account.h		// include structure for Savings_Account inheriting Account "is-a" or public inheritance
		// base class
	Account.cpp
		//	#include "Account.h"
	Savings_Account.h	
		//	#include "Account.h" 	// base class
	Savings_Account.cpp
		//	#include "Savings_Account.h"
	main.cpp	
		//	#include "Account.h"
		//	#include "Savings_Account.h"
    =============
    class Account {		//	Savings_Account inherits Account as "is a" or public inheritance
	public:
		double balance;
		std::string name;
		void deposit(double amount);		// need to add implementation of constructors/methods to run
		void withdraw(double amount);
		Account();	// no args constructor
		~Account();
	};
	class Savings_Account: public Account {   // inherits Account as "is a" class                 
	public:											// also has Account attributes balance and name
		double int_rate;
		Savings_Account();
		~Savings_Account();
		void deposit(double amount);    // its own version of deposit and withdrawal
		void withdraw(double amount);       // also inheits Account's deposit and withdrawal methods
	};
	int main() {
		Account acc{};
		Savings_Account sav_acc{};
		acc.deposit(2000);	// calls Account's method
		sav_acc.deposit(2000);	// calls Savings_Account method	
		Savings_Account *p_sav_acc{nullptr};	// works with pointers
		p_sav_acc = new Savings_Account();
		p_sav_acc->deposit(1000.0);
		delete p_sav_acc;
		return 0;		// similar calls for withdraw method
	}
	=============
	class Base {	// protected  members using inheritance  // friends have access to all three types
	public:	// private is written first in above OOP examples, then public
		int a{0};	// initialized at 0
		void display() { std::cout << a << ", " << b << ", " << c << endl; } // member method has access to all
	 	void change_c() {c = 300;}
	protected:      // new type, for base class objects this is like private members, not accessible in Derived class
		int b{0};		
	private:
		int c{0};
	};
	class Derived: public Base {        // public inheritance // friends of Derived have access to only what Derived has access to
	public:	// a is still public, b protected, c inherited but not accessible through Derived
		void access_base_members() {	// can access public and private members, inherited from Base, not protected
			a = 150;    // OK	// c = 300 would not be accessed in Derived, but could be through a method in Base, shown below
			b = 200;    // OK
			this->change_c();	// accesses c through Bases's public method that was inherited by Derived
		}
	};
	int main() {
		Base base;
		base.a = 100;   // OK  
		//    base.b = 200;  Compiler Error since private
		//    base.c = 300;   // Compiler Error since protected
		Derived d;
		d.a = 100;  // OK
		//    d.b = 200;  // Compiler Error since private
		//    d.c = 300;  // Compiler Error since protected
		d.access_base_members();		// can access private b in Derived class, through its own public method
		return 0;
	}
	=============
	class Base {    // Base constructors called, then Derived constructors, then Derived destructor, then Base destructor
	private:
		int value;
	public:
		Base() : value{0} { cout << "Base no-args constructor" << endl; }
		Base(int x) : value{x} { cout << "Base (int) overloaded constructor" << endl; }
		~Base(){ cout << "Base destructor" << endl; }
	};
	class Derived : public Base {
		using Base::Base;   // allows inheritance of non-special (no copy) base constructors
	private:
		int doubled_value;
	public:
		Derived() : doubled_value {0} { cout << "Derived no-args constructor " << endl; } 
		Derived(int x) : doubled_value {x*2}  { cout << "Derived (int) overloaded constructor" << endl; }
		~Derived() { cout << "Derived destructor " << endl; } 
	};
	int main() {
		// Derived d;    // if there are no Derived constructors present, the Base() is called, doubled_value is created by default constructor
		// Derived d {1000};  // without using Base::Base  // Base() is called, then Derived(int x) is called, but not Base(int x)
		// Derived d {1000};  // with using Base::Base and no Derived(int x),  it calls Base(int x) constructor but not Derived(int x) 	
		Derived d {1000};	// with using Base::Base and Derived(int x) present, it calls  Base() and Derived(int x)
		return 0;
	}
	=============
	class Derived : public Base {	// passing Base constructors properly to Derived Class, use same Base Class as above
	private: 
		int doubled_value;
	public:
		Derived()
			:  Base{}, doubled_value{0} {       // brings in Base() constructor in Derived's initialization list
				cout << "Derived no-args constructor " << endl; 
		}
		Derived(int x) 
			:  Base{x},  doubled_value{x * 2} { 	// brings in Base(int x) constructor 
				cout << "Derived (int) constructor" << endl; 
		}
	};
	int main() {
	//  Derived d;   // sets Base's value = 0, Derived's doubled_value = 0
		Derived d {1000};	// sets Base's value = 1000, Derived's doubled_value = 2000
		return 0;
	}
	=============
	class Base {    // Derived is inheriting Base's copy constructor and copy assignment=
	private:
		int value;
	public:
		Base()   // no args
			: value {0}  {  // can insert here // cout << "No Args Constructor" << endl;    // to help determine when they are called  
		}
		Base(int x)  // one arg
			: value {x} { 
		}
		Base(const Base &other)     // copy constructor
			: value {other.value} {   
		}
		Base &operator=(const Base &rhs)  { // overloaded =
			if (this == &rhs)   // checking self assignment (if locations are the same, return this's)
				return *this;
			value = rhs.value;
			return *this;
		} 
	};
	class Derived : public Base {
	private:
		int doubled_value;
	public:
		Derived() 
			: Base{}  {   // calls Base() no args in initialization list
		}
		Derived(int x) 
			: Base{x} , doubled_value {x * 2} { 
		}
		Derived(const Derived &other)
			: Base(other), doubled_value {other.doubled_value} {    // can do Base(other) since it is "is-a" inheritance, other's doubled value is sliced out in Base(other) call, then initialzed next
		}
		Derived &operator=(const Derived &rhs) {    // this(lhs) = rhs
			if (this == &rhs)   // if locations are the same, return this's location
				return *this;
			Base::operator=(rhs);   // use's base's overloaded assignment=   // called as a function(rhs)   // rhs is a Derived object which means it is also a Base object so it works
			doubled_value = rhs.doubled_value;      // rhs is sliced to leave only Base attribute in above copy assignment= call
			return *this;
		}					
	};
	int main() {
		//    Base b {100};   // Overloaded constructor
		//    Base b1 {b};    // Copy constructor   // b1 is a copy of b, via copy constructor  // basic demo of copy assignment and copy constructor
		//    b = b1;          //   Copy assignment
		Derived d {100};    // Overloaded constructor   // Base's value = 100, Derived's doubled_value = 200
		Derived d1 {d};     // Copy constructor     // d1 is constucted from d vis copy constuctor  
		d = d1;                // Copy assignment 
		return 0;
	}
	=============
	class Account {         // inherited class modifies a base class method
    		friend std::ostream &operator<<(std::ostream &os, const Account &account);  // friend's non-class overloaded operator, w/respect to Account
	protected:
		double balance;     // not accessible in a class derivied from this one (without a public method)
	public:
		Account();
		Account(double balance);            
		void deposit(double amount); 
		void withdraw(double amount);
	};
	Account::Account()  // no args constructor
		: Account(0.0) {    // delegating to one arg constructor below
	}      
	Account::Account(double balance)
		: balance(balance) { 
	}           
	void Account::deposit(double amount) {   
		balance += amount;
	}   
	void Account::withdraw(double amount) { // inherited without modification by Savings Account
		if (balance-amount >= 0)
			balance-=amount;
		else    
			std::cout << "Insufficient funds" << std::endl;
	}
	std::ostream &operator<<(std::ostream &os, const Account &account) {    // overloaded operator for Account only
		os <<  "Account balance: " << account.balance;
		return os;
	}
	class Savings_Account: public Account {     // public inheritance
		friend std::ostream &operator<<(std::ostream &os, const Savings_Account &account);      // friending overloaded operator w/respect to Savings_Account
	protected:
		double int_rate;    // not accessible in any further derived class from this (unless by public method)
	public:        // Withdraw is inherited from Account
		Savings_Account();
		Savings_Account(double balance, double int_rate);
		void deposit(double amount);
	};
	Savings_Account::Savings_Account(double balance, double int_rate)
		: Account(balance), int_rate{int_rate} {        
	}
	Savings_Account::Savings_Account()  // no args constructor
		: Savings_Account{0.0, 0.0} {       // delegates to above SA constructor
	}
	void Savings_Account::deposit(double amount) {      // this modify's deposit by int rate and calls Account's deposit method
		amount = amount + (amount * int_rate/100);
		Account::deposit(amount);   // applies inherited Account's deposit method 
	}
	std::ostream &operator<<(std::ostream &os, const Savings_Account &account) {    // this is overloaded specifically for SA, A version would not have interest rate
		os << "Savings account balance: " << account.balance << " Interest rate: " << account.int_rate;
		return os;
	}
	int main() {
		Savings_Account s1 {1000, 5.0}; 
		cout << s1 << endl;         // Savings Account balance: 1000, Interest rate: 5, overloaded << for Saving's, if used the << in Account.cpp, it would not show interest
		s1.deposit(1000);               // calls Saving's deposit, which also accesses Account's deposit method
		cout << s1 << endl;          // Savings Account balance: 2050, Interest rate: 5
		s1.withdraw(2000);             // calls inherited Account's withdraw method 
		cout << s1 << endl;          // Savings Account balance: 50, Interest rate: 5
		return 0;
	}
	=============
     class Account {
          friend std::ostream &operator<<(std::ostream &os, const Account &account);
     private:   
          static constexpr const char *def_name = "Unnamed Account";	// constants only available to the Account scope
          static constexpr double def_balance = 0.0;
     protected:
          std::string name;	// protected from further derived classes
          double balance;
     public:
          Account(std::string name = def_name, double balance = def_balance);	// defaulted using constants above
          // Account(std::string name = "Unamed Account", double balance = 0.0);	 // this can also work, if you don't like the static constants defined above
          bool deposit(double amount);
          bool withdraw(double amount);
          double get_balance() const;
     };
     Account::Account(std::string name, double balance) 	// defaulted in prototype
          : name{name}, balance{balance} {
     }
     bool Account::deposit(double amount) {
          if (amount < 0) 
               return false;
          else {
               balance += amount;
               return true;
          }
     }
     bool Account::withdraw(double amount) {
          if (balance-amount >=0) {
               balance-=amount;
               return true;
          } else
               return false;
     }
     double Account::get_balance() const {
          return balance;
     }
     std::ostream &operator<<(std::ostream &os, const Account &account) {	// friended to Account
          os << "[Account: " << account.name << ": " << account.balance << "]";
          return os;
     }
     class Savings_Account: public Account {		// public "is-a" inheritance
          friend std::ostream &operator<<(std::ostream &os, const Savings_Account &account);
     private:
          static constexpr const char *def_name = "Unnamed Savings Account";	// constants for Savings_Account, need c++ 11
          static constexpr double def_balance = 0.0;
          static constexpr double def_int_rate = 0.0;
     protected:
          double int_rate;	// protected from further derived classes (unless by public method)
     public:
          Savings_Account(std::string name = def_name, double balance =def_balance, double int_rate = def_int_rate);    	// defaulted with above constants
          bool deposit(double amount);	// to override Account's deposit
          // Inherits the Account::withdraw methods and attributes
     };
     Savings_Account::Savings_Account(std::string name, double balance, double int_rate)
          : Account {name, balance}, int_rate{int_rate} {	// sets Account's attributes, using its 2 arg constr, int_rate is Saving's accounts
     }
     bool Savings_Account::deposit(double amount) {
          amount += amount * (int_rate/100);	// modifies inherited deposit to add interest, static binding
          return Account::deposit(amount);	// calls Account's deposit method (which returns a bool), need Account:: otherwise its a recusrsion method
     }
     std::ostream &operator<<(std::ostream &os, const Savings_Account &account) {	// overloaded for Savings_Account
          os << "[Savings_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%]";
          return os;
     }
     void deposit(std::vector<Account> &accounts, double amount) {	// non class function that calls Account's deposit
          std::cout << "\n=== Depositing to Accounts =================================" << std::endl;
          for (auto &acc:accounts)  {
               if (acc.deposit(amount)) 	// executes Account's deposit method, that returns a bool tested in if
                    std::cout << "Deposited " << amount << " to " << acc << std::endl;
               else
                    std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
          }
     }
     void deposit(std::vector<Savings_Account> &accounts, double amount) {  // non-class function that calls Saving's deposit method
          std::cout << "\n=== Depositing to Savings Accounts===========================" << std::endl;
          for (auto &acc:accounts)  {
               if (acc.deposit(amount)) 
                    std::cout << "Deposited " << amount << " to " << acc << std::endl;
               else
                    std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
          }
     }
     int main{
          vector<Savings_Account> sav_accounts;
          sav_accounts.push_back(Savings_Account {} );		// all args are defaulted
          sav_accounts.push_back(Savings_Account {"Superman"} );		// balance and int_rate are defaulted
          sav_accounts.push_back(Savings_Account {"Batman", 2000} );
          sav_accounts.push_back(Savings_Account {"Wonderwoman", 5000, 5.0} );
          display(sav_accounts);
          deposit(sav_accounts, 1000);	// executes non-class deposit, which executes Saving's deposit method
          return 0;
     }
     // the challenge also has a Checking_Account class that inherits Account depoist method, modifies Account's withdrawal by adding fee
     // also has Trust Account that modifies Savings_Account withdrawal and deposit (from Account) methods
	=============
}
//   Polymorphism
{
     ============
     class Base {        // example of static binding, no polymorphism, greetings function only accepts Base class, so only calls Base class methods 
     public:
          void say_hello() const {
               std::cout << "Hello - I'm a Base class object" << std::endl;
          }
     };
     class Derived: public Base {
     public:
          void say_hello()  const {   
               std::cout << "Hello - I'm a Derived class object" << std::endl;
          }
     };
     void greetings(const Base &obj) {      // if pass in Derived, it would only call Base's say_hello (static binding)
          std::cout << "Greetings: ";
          obj.say_hello();
     }
     int main() {
          Derived d;
          d.say_hello();  // calling Derived's say_hello
          greetings(d);   // even though d is Derived, calls Base's say_hello since Greeting only accepts Bases
          Base *ptr = new Derived();     // ptr holds the address of Base obj, it can since Derived "is-a" Base
          ptr->say_hello();    // calls Base's say_hello, not derived's
          std::unique_ptr<Base> ptr1 = std::make_unique<Derived>();    // creates smart pointer, needs #include<memory>
          ptr1->say_hello();   // still calls Base's say_hello, even for smart pointers
          delete ptr; // deletes raw pointer, don't need to delete smart pointer ptr1
          return 0;
     }
     ============
     class Account {     // using Base class pointers, so that correct class methods are executed with virtual functions
     public:        // cannot use virtual with constructors
          virtual void withdraw(double amount) {    // only really need the virtual here, to call each class's own withdrawal, but best practice to add it to derived classes below
               std::cout << "In Account::withdraw" << std::endl;
          }                                      // must include virtual destructor if you have a virtual function, otherwise you'll have C++ problems
          virtual ~Account() {  }  // only really need virtual declared here for other derived classes to be virtual
     };
     class Checking: public Account  {
     public:
          virtual void withdraw(double amount) {
               std::cout << "In Checking::withdraw" << std::endl;
          }
          virtual ~Checking() {  }
     };
     class Savings: public Account  {
     public:
          virtual void withdraw(double amount) {
               std::cout << "In Savings::withdraw" << std::endl;
          }
          virtual ~Savings() {  }
     };
     class Trust: public Account  {
     public:
          virtual void withdraw(double amount) {
               std::cout << "In Trust::withdraw" << std::endl;
          }
          virtual ~Trust() {  }
     };
     int main() {
          Account *p1 = new Account();   // Base class pointers (Account is the Base), without virtual functions, this would only call Account's withdrawal
          Account *p2 = new Savings();
          Account *p3 = new Checking();
          Account *p4 = new Trust();
          Account *array [] = {p1,p2,p3,p4};
          for (auto i=0; i<4; ++i)       // could execute withdraw on any order and it will still select the class's correct withdraw method
               array[i]->withdraw(1000);
          std::vector<Account *> accounts {p1,p2,p3,p4};
          for (auto acc_ptr: accounts)
               acc_ptr->withdraw(1000);
          delete p1; delete p2;         // for p2 it calls Saving's destr then Account, since Savings are Accounts, same for other derived classes
          delete p3; delete p4;       // without virtual it may only call Account's destructor, potential memory leak
          return 0;
     }
     ============
     class Base {   // using override to help flag whether you have a static or dynamic function
     public:
          virtual void say_hello() const {    // check against cases below 
               std::cout << "Hello - I'm a Base class object" << std::endl;
          }
          virtual ~Base() {}
     };
     class Derived: public Base {
     public:
          // virtual void say_hello() override{  // error appears, override checks if it is dynamically bound or not            
          // virtual void say_hello() const{   // this is also properly dynamic bound            
          virtual void say_hello() const override{  // dynamically bound, and now override does not flag error, const is only important here bc it changes the signature, not anything to do with keeping constant
               std::cout << "Hello - I'm a Derived class object" << std::endl;
          }
          virtual ~Derived() {}
     };
     int main() {
          Base *p1 = new Base();      
          p1->say_hello();     // Base's say_hello()
          Derived *p2 = new Derived();        // statically bound is the default C++ compiler execution of functions, fixes method to directly to its class alone despite inheritance
          p2->say_hello();      // Derived::say_hello(), statically bound not dynamically bound since Derived *p2 and not Base *p2
          Base *p3 = new Derived();     // would call Base's and not Derived's say_hello without both derived and const
          p3->say_hello();          // properly dynamically bound, no error, with const override signature above 
          // add in delete pointers to avoid mem leak
          return 0;
     }
     ============
     class Base {        // using final, does not allow inheritance of a class or virtual function
     public:
          virtual void say_hello() final {      // does not allow Derived to call Base's method with the same signature  
               std::cout << "Hello - I'm a Base class object" << std::endl;
          }
     };
     class Derived final: public Base { // another class cannot be derived from Derived, can also apply to Base (if Derived is unneeded)
     public:
          virtual void say_hello() {    // compiler error: can't override
               std::cout << "Hello - I'm a Derived class object" << std::endl;
          }
     };
     int main() {
          Base *b1 = new Base();
          b1->say_hello(); 
          Base *d1 = new Derived();
          d1->say_hello();     // compiler error, since Base's say_hello() is final
          delete b1; delete d1;
          return 0;
     }
     ============
}
//	Reading/Writing Files
{	
    =============
	ifstream in_file{"myfile.txt"};	// a simple check open file statement
	if (!in_file.is_open()) {
		cerr << "Error opening file" << endl;
		return 1;
	}
	=============
    std::ifstream in_file;	// Reads from formatted test.txt file, need #include<fstream>
    std::string line;		// prepares a var to read line of txt file
    int num;    			//test.exe: string num, in one row or column	
    in_file.open("test.txt");   // works for Linux, must create test.txt in CodeLite project's src folder
    if (!in_file) {				// Win10 may need "../test.txt", looks up one dir from .exe file
        std::cerr << "Problem opening file" << std::endl;	
        return 1;   // can also use exit(1)
    }
    // std::cout << "File is good to go" << std::endl;
    in_file >> line >> num ;    // stores data from test.txt into vars
    in_file.close();
	=============
	std::ifstream in_file {"test.txt"};		//another way to read one line
    std::string line;						// test.txt: string, int, double
    int num;
    double total;
    if (in_file.is_open()) {
		in_file >> line >> num >> total;	//picks out two entries in file at a time
    } else {
		std::cerr << "Problem opening file" << std::endl;
      	return 1;		
	  }
    std::cout << line << num << total << std::endl;
    in_file.close();
	=============
	std::ifstream in_file;	// reads whole file formatted file by line
    std::string line;
    int num;
    in_file.open("test.txt");	// file has rows of: string num
    if (!in_file) {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }		// not at end of file					Does the same thing:
	while (!in_file.eof()){		// 					while (in_file >> line >> num >> total) {
		in_file >> line >> num;	// 						std::cout << line << num << std::endl; 	
		std::cout << line << num << std::endl;	  //}		
	}							
    in_file.close();
	=============
	std::ifstream in_file;		// reads all of an unformatted multiline file
    in_file.open("poem.txt");		
    if (!in_file) {
        std::cerr << "Problem opening file" << std::endl;
        return 1;											// unformatted by char
    }														// This loop will read char by char
    std::string line{};		// while you can get a line		// char c{};
    while (std::getline(in_file, line)) {					// while(in_file.get(c)) {		// in_file.get(c) is true
        std::cout << line << std::endl;						//		std::cout << c;
    }														// }
    in_file.close();										
	=============
	std::ifstream in_file{"../myfile.txt"};	 // mixes some of the methods above
	std::string line{};						// need to add read file check/error & file close
	while (!in_file.eof()) {	// while not at the end (bool)	
		std::getline(in_file, line);	// read a line
		std::cout << line << std::endl;	// display the line
	}
	=============
	ifstream in_file{"myfile.txt"};
	string files_string{};		// picks out anything seperated by a space, as a string, one at a time
	int files_string_cntr{0};	// still needs open file check and file close
	while (!in_file.eof()) {
		in_file >> files_string;	
		++files_string_cntr;	// counts number of strings in file
	}
	=============
	ifstream in_file{"myfile.txt"};		//picks out every other string from myfile.txt and 
	int counter{1};						// places odd #'d in answers vector, even in names
	vector<string> names{};				// still needs an open file check and file close
	vector<string> answers{};
	while (!in_file.eof()) {
		string line{};
		in_file >> line;		// better if used: in_file >> line1 >> line2, this removes the need for an even and odd counter	 
		if ( (counter % 2) != 0 ) {		// if counter is odd
			answers.push_back(line);
			++counter;
		} else { 
			names.push_back(line);
			++counter;
		}	
	} 
    =============
	//  std::ofstream out_file {"output.txt"};  // (CodeLite) creates output.txt in project folder > src or overwrites if exists
    std::ofstream out_file{"output.txt", std::ios::app};	// to append to existing file
    if (!out_file) {										// simple check output file script
        std::cerr << "Error creating file" << std::endl;
        return 1;
    }	
    =============
    std::ofstream out_file{"output.txt", std::ios::app};	// another check	
    if (out_file.is_open()) 
		std::cout << "File will open" << std::endl;
	else {											
        std::cerr << "Error creating file" << std::endl;
        return 1;
	}	
	=============
	// add above open output.txt file check  // asks user to add one line to output.txt
    std::ofstream out_file{"output.txt", std::ios::app};	// to append to existing file
	std::string line;
    std::cout << "Enter something to write to the file: ";
    std::getline(std::cin, line);   // from cin (console) into line
    out_file << line << std::endl;  
    out_file.close();
	=============
   	std::ifstream in_file {"poem.txt"};	// creates a copy of poem.txt called poem.out.txt 
    std::ofstream out_file{"poem_out.txt"};
    if (!in_file.is_open()) {
        std::cerr << "Error opening input file" << std::endl;
        return 1;
    }
     if (!out_file.is_open()) {
        std::cerr << "Error opening output file" << std::endl;
        return 1;
    }
    char c;
    while (in_file.get(c))	// while you can get a char
        out_file.put(c);	// write the char in out_file
    std::cout << "File copied" << std::endl;
    in_file.close();
    out_file.close();
	=============
	// add file checks like above	// another loop for copying whole file, line by line (formatted)
	std::ifstream in_file{"poem.txt"};
    std::ofstream out_file{"poem_out.txt"};
    std::string line{};
    while (std::getline(in_file, line))	// while you can get a file from in_file stream read into line
        out_file << line << std::endl;	// line is written through out_file stream (to poem_out.txt)
	// add "File copied" and close both streams
	=============
	//add file checks			// copies file line by line
	ifstream in_file{"poem.txt"};
    ofstream out_file{"poem_out.txt"};
	string line{};
	while (!in_file.eof()) {	// another form of while loop
		getline(in_file, line);
		out_file << line << endl;
	}	
	// add "File copied" and close both streams
	=============
	int num{};		// string stream 
    double total{}; //  pulls or reads from info string into other vars
    std::string name{};
    std::string info {"Moe 100 1234.5"};
    std::istringstream iss {info};
    iss >> name  >> num >>  total;
	=============
   	std::ostringstream oss {};	// write to empty string stream
    oss << name << num << total << std::endl;	//unformated write: namenumtotal 	
    std::cout << oss.str() << std::endl;    // access oss as a string
	=============
	int value{};		// data validation, continually checks until int is entered
    std::string entry {};
    bool done = false;
    do {
        std::cout << "Please enter an integer: ";
        std::cin >> entry;  // can enter anything here, since entry is a string
        std::istringstream validator {entry};
        if (validator >> value)  // if you can pull(read) an int from entry
            done = true;          // will pull the first int part of entry 
        else 
            std::cout << "Sorry, that's not an integer" << std::endl;		// needs include<limits>
        validator.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); // clears any non int portion leftover in buffer 
		std::string leftover {}; 		
        validator >> leftover;    
        std::cout << "leftover = " << leftover << std::endl; // produces whats left (non ints) in the valiator stream, should be empty bc of numeric_limits line
    } while (!done);
	=============
	int value{};	// same as above with stringstream obj, only one check
	std::string input{};
	std::cout << "Enter an integer: ";
	std::cin >> input;	// user input is placed into a string
	std::stringstream ss{input};
	if (ss >> value) {		// if you can extract(read) an integer from string input
		std::cout << "An integer was entered";
	else
		std::cout << "An integer was not entered";
	}
	=============
}
//	Pointer and reference examples		
{
	int *int_ptr{nullptr};		// 0x0 is location of nullptr, no location
	int_ptr = new int;	// allocates (to same location?) memory for an integer on heap at runtime, this storage does not have a var name
	cout << int_ptr << endl;		// memory location
	cout << *int_ptr << endl;	// derefence, displays garbage value at location
	*int_ptr = 100;	// assigns 100 to whatever int_ptr is pointing to 
	delete int_ptr;	// deallocates, or frees the allocated storage, make sure to do this to avoid memory leak
	=============	
	cout << "address is: " << (int *)0x91440 << endl;	// pointer to address 0x91440 (displays address)
	cout << "at 0x91440:" << *(int *)0x91440 << endl;	// value at memory address 0x91440
	cout << "0x91440 is deallocated" << endl;
	delete (int *)0x91440;
	==============	
	int size{num};
	int *array_ptr{nullptr};
	array_ptr = new int[size];		// allocates var array of size ints, address of the first integer is stored in var_ptr
	cout << array_ptr << endl;	//	memory location
	delete [] array_ptr;		// deallocates entire array
	===============
	int array [] {10, 20, 30};		// array and array_ptr are the same (only for arrays)
	int *array_ptr {array};		// did not need {&array}, but would if it was anything else
	cout << array << endl;	// 07xfe54 memory address of 1st element
	cout << array_ptr << endl;	//	07xfe54
	cout << (array_ptr + 1) << endl; // 07xfe58, moves 1*(type size) in memory
	cout << *array << endl;	// 	10
	cout << *array_ptr << endl; // 10
	cout << *(array + 1) << endl;	// 20	
	cout << *(array_ptr + 1) << endl; // 20
	cout << array[2] << endl; // 30
	cout << array_ptr[2] << endl;	// 30		
	================
	int array [] {10, 20, 30};		// array and array_ptr are the same, with different notations
	int *array_ptr {array};
	cout << array[1] << endl;	// 20
    cout << array_ptr[1] << endl;	// 20
    cout << *(array_ptr + 1) << endl;	// 20
    cout << *(array + 1) << endl;	// 20
	================	
    char name[]  {"BenHarki"};
    char *name_ptr1{nullptr};
    char *name_ptr2{nullptr};
    name_ptr1 = &name[1];   // location of e
    name_ptr2 = &name[6];   // location of k
	cout << name << endl; //(counts k not e all in between) then - 1
	cout << "There are " << (name_ptr2 - name_ptr1) - 1  << " characters between "<< name[1] << " and " << name[6] << endl;
	================	
    for (auto &str: names)  	// This will change actual variable (inside a function its only the local), without & it doesn't change anything
        str = "Funny";    
	for (auto const &str:names)   // prints names without risk of changing actuals, & makes more efficient by not using a copy
        cout << str << endl;            
	================		
	int num {100};	
  	int &ref {num};	// ref is like a pointer to num
  	ref = 200;		// changes both to 200
  	num = 300;		// changes both to 300
	int *ptr1{nullptr};
	ptr1 = new int;
	int *ptr2{ptr1}; // ptr2 has same location as ptr1
	*ptr2 = 400; // also changes deref of *ptr1, since they both point to the same place
	delete ptr1;	// careful not to use ptr2 after this, since it is still pointing to a deallocated location
  	================
	void l_function(int &var1) {	// can create one function handle, implemented twice as an overloaded function, to deal with both cases
		cout << "l-value is var1\n"	// accepts l values only
			<< "r-value is " << var1 << endl;
	}
	void r_function(int &&var2) {	// accepts r-values only
		cout << "r-value is " << var2 << endl;
	}
	int main() {
		int x{100};
		int &y = x; // y is like a pointer to x
		y = 200; // changes both x and y
		int var1{3};
		l_function(var1);
		// l_function(3);  // won't compile
		r_function(3);
		// r_function(var1);    // won't compile
		return 0;
	}
	===============
	char *ptr1 {nullptr};	// difference between char arrays and int arrays using ptrs
	ptr1 = new char[4];		// char array ptr is value, int array is memory location
	ptr1[0] = 'B'; ptr1[1] = 'e'; ptr1[2] = 'n'; ptr1[3] = '\0';	
	cout << &ptr1 << endl;	// 0x7ffe355b7588
	cout << ptr1 << endl;	// "Ben"
	int *ptr2 {nullptr};
	ptr2 = new int[2];
	ptr2[0] = 1; ptr2[1] = 2;
	cout << ptr2 << endl;	//	0x2665bd0
	cout << ptr2[0] << endl; //  1
	delete [] ptr1; delete [] ptr2;
	===============

}

#include <iostream>	
using namespace std;

int main( ) {	
  
	return 0;
}

// g++ -Wall -std=c++17 main.cpp -o test.exe 
// compiles in Windows cmd prompt, creates program names.exe
//	-o ben.exe			// changes main.exe to ben.exe
//	cls clears screen, cd change directory, dir check directory	
// ctrl-c to stop program in progress
