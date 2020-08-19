//
// Created by General on 17.08.2020.
//


#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct PairOfStringAndInt {
    string first;
    int second;
};

template<typename T, typename U>
struct Pair {
    T first;
    U second;
};

template <typename Iterator>
struct IteratorRange{
    Iterator first, last;
    Iterator begin() const {
        return first;
    }
    Iterator end() const {
        return last;
    }
};

template <typename T>
IteratorRange<typename vector<T>::iterator> Head(vector<T>& v, size_t top) {
    return {
        v.begin(), next(v.begin(), min(top, v.size()))
    };
}

// IteratorRange IS NOT A CLASS, so we need IR<T>
template <typename T>
size_t RangeSize(IteratorRange<T> r) {
    return r.end() - r.begin();
}

int main() {

    // Inconvenient form
    PairOfStringAndInt si;
    si.first = "Hello";
    si.second = 5;

    // Pair<bool, char> is a DEFINED from a template CLASS.
    // It is called "инстанцирование"
    Pair<bool, char> bc;
    bc.first = true;
    bc.second = 'z';

    // Integrating users class in "for" loop video

    vector<int> v = {1, 2, 3, 4, 5};
    for (int& x : Head(v,3)) {
        ++x;
    }
    for (int& x : v) {
        cout << x << ' ';
    }

    // Difference between class template and class

    // vector is JUST a TEMPLATE, but vector<int> is a CLASS
    // Therefore, vector<int> and vector<double> ARE DIFFERENT CLASSES

    // Example with RangeSize!

    return 0;
}