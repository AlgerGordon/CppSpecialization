//
// Created by General on 08.05.2020.
//

#include <iostream>

using namespace std;

int Factorial(int n) {
    int fact = 1;
    for (int ind = 1; ind <= n; ++ind ){
        fact *= ind;
    }
    return fact;
}

int main() {
    int n;
    cin >> n;
    cout << Factorial(n);
}