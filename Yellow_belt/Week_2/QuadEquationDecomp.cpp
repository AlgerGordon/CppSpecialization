//
// Created by General on 03.05.2020.
//

#include <iostream>
#include <cmath>

using namespace std;

void SolveQuadraticEquation(double a, double b, double c) {
    double d;
    d = b * b - 4 * a * c;
    if (d > 0){
        cout << (-b + sqrt(d)) / (2 * a) << " " << (-b - sqrt(d)) / (2 * a);
    }else if(d == 0) {
        cout << -b / (2 * a);
    }
}

void SolveLinearEquation(double b, double c) {
    // b * x + c = 0
    if (b != 0) {
        cout << -c / b;
    }
}

int main(){
    double a, b, c;
    cin >> a >> b >> c;

    if (a != 0){
        SolveQuadraticEquation(a, b, c);
    }else {
        SolveLinearEquation(b, c);
    }

    return 0;
}
