//
// Created by General on 29.08.2020.
//


#include <iostream>

using namespace std;

template<typename T>
class SimpleVector {
public:
    explicit SimpleVector(size_t size) {
        data_ = new T[size];
    }
    ~SimpleVector() {
        delete [] data_;
    }

private:
    T* data_;
};

int main() {
    SimpleVector<int> sv(5);
    return 0;
}