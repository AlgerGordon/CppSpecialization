//
// Created by General on 15.05.2020.
//

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


int main() {

    ifstream input("input.txt");
    double a;

    cout << fixed << setprecision(3);
    if(input.is_open()){
        while (input >> a) {
            cout << a << endl;
        }
    }

    input.close();
    return 0;
}