//
// Created by General on 29.08.2020.
//


#include <iostream>
#include <random>
using namespace std;

struct Widget {
    Widget() {
        cout << "constructor" << endl;
    }
    ~Widget() {
        cout << "destructor" << endl;
    }
};

int main() {

    int n;
    cin >> n;

    mt19937_64 random_gen;
    uint64_t sum = 0;
    for (int i = 0; i < n; ++i) {
        auto x = new uint64_t;
        * x = random_gen();
        // here we have memory_system leaking, if we dont use delete
        sum += *x;
        delete x;
    }
    cout << sum << endl;

    // NEW and DELETE for structs and classes

    // new calls the constructor
    Widget* w = new Widget;
    // destructor ISN'T CALLED WO DELETE
    // delete calls the destructor
    delete w;

    return 0;
}