//
// Created by General on 10.09.2020.
//


#include <iostream>

using namespace std;

class A {
public:
    A() {
        cout << "constructed" << endl;
    }
    ~A() {
        cout << "destructed" << endl;
    }
};

int main() {
    int x = 5;
    int* px = &x;
    const int* cpx = &x;        // can't change *cpx
    int* const pxc = &x;        // can edit *pxc, but not pxc itself
    const int* const cpxc = &x; // can't change anything

    return 0;
}