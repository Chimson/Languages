#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

#define CLOCK(t) high_resolution_clock::time_point t = high_resolution_clock::now()
#define PRINTTIME(start, stop, elapsed) \
	duration<double, nano> elapsed = duration_cast<nanoseconds>(stop-start); \
	cout << "time elapsed is " <<  elapsed.count() / 1000000 << " milliseconds\n" << endl;		// 1'000'000'000 ns = 100000 us = 1000 ms = 1 sec  

	
/*
class high_resolution_clock
	time_point now()  // 
class duration<rep, period>  
	count()		// returns number of ticks
duration_cast<chrono::types>
*/

void print_loop() {
	for (int i{ 0 }; i < 50; i++) {
		for (int j{ 0 }; j < 25; j++) {
				cout << ".";
		}
		cout << endl;
	}
}

void ctime() {
	clock_t start, finish;
	double duration;
	
	start = clock();
	print_loop();
	finish = clock();
	
	clock_t ticks = finish - start;
	cout << "# of clock ticks is " << (double) ticks << endl;
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "Time is " << duration << " seconds " << endl;
	cout << "CLOCKS_PER_SEC = " << CLOCKS_PER_SEC << endl;
	cout << "\n";
}


void cppchrono() {
	
	// ***** EXAMPLE 1 *****
	// CLOCK(start_0);		// CLOCK defines start0 variable
	
	// int sum{0};
	// for (int i{0}; i<10; i++) {
		// ++sum;
	// }
	// cout << "sum is " << sum << endl;

	// CLOCK(stop_0);
	// PRINTTIME(start_0, stop_0, elapsed_0);		// defines elapsed0 variable
	// **********************

	// ***** EXAMPLE 2 ***** 
	char s[] = "This string has many space (0x20) chars. ";
	
	CLOCK(start_1);	
	for(size_t i = 0; i < strlen(s); ++i) {
		if(s[i] == ' ')
			s[i] = '*';
	}

	CLOCK(stop_1);
	PRINTTIME(start_1, stop_1, elapsed_1);


	CLOCK(start_2);
	const size_t len = strlen(s);
	for(size_t i = 0; i < len; ++i) {		// or declare len next to i inside for loop
		if(s[i] == ' ')
			s[i] = '*';
	}
	CLOCK(stop_2);
	cout << "Optimized:" << endl;
	PRINTTIME(start_2, stop_2, elapsed_2);
	// **********************

}

int main() {

		// uses ctime.h
		// ctime();
    
		// cout << endl;
		
		// uses <chrono>
		cppchrono();
		
    return 0;
}