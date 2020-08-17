//
// Created by General on 14.08.2020.
//

// TestRunner improvement
// Ex: displaying error file and string
// Ex: displaying error arguments to avoid 1 != 0

// To perform preprocessing use g++ -E

#include <iostream>
#include <string>

using namespace std;

// Use MACROS when u use __FILE__, __LINE__ or # operator
// Isolate all arguments with brackets and use them only ones!

// DARK SIDE OF MACROSes

#define MAX(a, b) (a > b ? a : b)
// CLASSIC ISSUE
// int z = SQR(x++); will produce
// int z = ((x++) * (x++)); and undefined behavior
#define SQR(x) ((x) * (x))

// Better write template function for SQR
template<typename T>
T Sqr(T x) {
    return x * x;
}

int LogAndReturn(int x){
    cout << "x = " << x << endl;
    return x;
}

int main() {
    int x = 4;
    int y = 2;
    // If we have #define MAX(a, b) a > b ? a : b, then
    // It will work as
    // int z = x > y ? x : y + 5;
    // Will produce wrong output 4, not 9 as we thought
    // Fast fix is adding bracket
    // #define MAX(a, b) (a > b ? a : b)

    int z = MAX(x, y) + 5;  // it produces 9, but we've all ready fucked up
    cout << z << endl;

    // If we have #define SQR(x) (x * x), then
    // It will work as
    // int z1 = (x + 1 * x + 1) != x^2
    // Will produce wrong output 9, not 16 as we thought
    // Fast fix is adding bracket again
    // #define SQR(x) ((x) * (x))


    int z1 = SQR(x + 1); // produces 16, but we've all ready fucked up
    cout << z1 << endl;
    // better use template function
    z1 = Sqr(x + 1);
    cout << z1 << endl;
    // If we use LogAndReturn()
    z1 = SQR(LogAndReturn(3));
    cout << z1 << endl;
    // it will produce 2 TIMES output for x:
    // x = 3
    // x = 3
    // 9

    return 0;
}