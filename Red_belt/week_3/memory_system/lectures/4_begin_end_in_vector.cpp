//
// Created by General on 29.08.2020.
//


#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
class SimpleVector {
public:
    explicit SimpleVector(size_t size) {
        data_ = new T[size];
        end_ = data_ + size;
    }
    ~SimpleVector() {
        delete [] data_;
    }
    T& operator[] (size_t index) {
        // it is the same with *(&date + index);
        return data_[index];
    }
    // we need "const T*" to prevent changes using smth like *i = 42 in loops
    const T* begin() const {
        return data_;
    }
    const T* end() const {
        return end_;
    }
    // we need this methods to perform sort() for example
    T* begin() {
        return data_;
    }
    T* end() {
        return end_;
    }

private:
    T* data_;
    T* end_;
};

template<typename T>
void Print(const SimpleVector<T>& v) {
    // It's important to mark begin() and end() as const
    // because here we work with CONSTANT SimpleVector reference
    //
    // for (const auto& x : v) equals to
    for (auto x = v.begin(); x != v.end(); ++x) {
        cout << *x << ' ';
    }
}

int main() {
    SimpleVector<int> sv(4);
    sv[0] = 5;
    sv[1] = 3;
    sv[2] = 4;
    sv[3] = -1;

    // with such begin() and end() we created ANALOGY TO ITERATORS for out class
    // and it WORKS. We CAN use POINTERS like ITERATORS
    sort(sv.begin(), sv.end());\
    // we added begin() and end() we CAN use range-based for
    for (int x : sv) {
        cout << x << ' ';
    }

    return 0;
}