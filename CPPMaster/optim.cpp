// OPTIMIZATION EXAMPLES

// inlining a function replaces a function call with the body of the function
// loop unrolling computes two iterations at once, iterating half number of times

// Simple clock to measure speed of a program
#include <iostream>
#include <ctime>
using namespace std;
int main() {
    clock_t start, finish;
    double duration;
    start = clock();
    for (int i{ 0 }; i < 50; i++) {
        for (int j{ 0 }; j < 25; j++) {
            cout << ".";
        }
        cout << endl;
    }
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << "Time is " << duration << " seconds " << endl;
    cout << "CLOCKS_PER_SEC = " << CLOCKS_PER_SEC << endl;
    cout << "\n";
    return 0;
}
// *****
// macro to help use the clock
#define TIMEIS(start, finish) \
  duration = (double)(finish - start) / CLOCKS_PER_SEC; \
  cout << "Time is " << duration << " seconds\n" << endl;
// *****