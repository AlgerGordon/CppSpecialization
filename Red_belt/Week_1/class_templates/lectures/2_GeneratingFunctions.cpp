//
// Created by General on 17.08.2020.
//


#include <iostream>
#include <string>
#include <vector>

using namespace std;


template <typename Iterator>
class IteratorRange{
public:
    IteratorRange(Iterator f, Iterator l) : first(f), last(l){}
    Iterator begin() const {
        return first;
    }
    Iterator end() const {
        return last;
    }
private:
    Iterator first, last;
};

template <typename T>
IteratorRange<typename vector<T>::iterator> Head(vector<T>& v, size_t top) {
    return {
            v.begin(), next(v.begin(), min(top, v.size()))
    };
}

// Инстанцирующая функция !

template <typename Iterator>
IteratorRange<Iterator> MakeRange(Iterator begin, Iterator end) {
    return IteratorRange<Iterator>{begin, end};
};


// IteratorRange IS NOT A CLASS, so we need IR<T>
template <typename T>
size_t RangeSize(IteratorRange<T> r) {
    return r.end() - r.begin();
}

int main() {

    vector<int> v = {1, 2, 3, 4, 5};
    for (int& x : Head(v,3)) {
        ++x;
    }
    for (int& x : v) {
        cout << x << ' ';
    }
    cout << endl;
    cout << RangeSize(Head(v, 3));
    cout << endl;

    // It is done to avoid long type name IteratorRange<vector<int>::iterator>>
    // It is possible because of generating function
    auto second_half = MakeRange(
        v.begin() + v.size() / 2, v.end()
    );
    for (int x : second_half) {
        cout << x << ' ';
    }



    return 0;
}