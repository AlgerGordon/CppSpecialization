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

    T& operator[] (size_t index) {
        // it is the same with *(&date + index);
        return data_[index];
    }
private:
    T* data_;
};

void f() {
    int a = 43;
    int b = 71;
}

int main() {
    SimpleVector<int> sv(5);
    // segmentation fault with <string>
    // with int it doesn't fail, but prints random number
    cout << sv[12] << endl;
    for (int i = 0; i < 5; ++i) {
        sv[i] = 5 -i;
    }
    for (int i = 0; i < 5; ++i) {
        cout << sv[i] << '\n';
    }

//    int x = 5;
//    int* y = &x;
//    *y = 7;
//    cout << x << endl;

//    int a = 43;
//    int b = 71;
//    int c = 89;
//    cout << *(&b - 1) << ' ' << *(&b + 1) << endl;

    int c = 89;
    for (int i = 0; i < 20; ++i) {
        f();
        int x = *(&c - i);
        // output   14: 43
        //          15: 71
        // it means that f() stack frame
        // and vars a, b are 14 and 15 int's pointers away
        cout << i << ' ' << x << endl;
    }

    int* d = &c;
    int* e = d + 1;
    cout << d << endl << e << endl;
    // 0x62fde4
    // 0x62fde8
    // difference between d and e is 4 bytes- int's default size

    return 0;
}