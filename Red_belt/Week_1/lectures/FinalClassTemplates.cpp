//
// Created by General on 17.08.2020.
//


#include <iostream>
#include <string>
#include <set>
#include <deque>
#include <vector>

using namespace std;

// Previously we had to work with vectors only
// Let's solve this problem

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

// Previously was:
//  template <typename T>
//  IteratorRange<typename vector<T>::iterator>
// Then :
//  template <typename Container>
//  IteratorRange<typename Container::iterator> Head(Container& v, size_t top) {
template <typename Container>
auto Head(Container& v, size_t top) {
    // compiler will generate type because of constructor with tt T
    // Now we know returned type and it is correct in sense of const_iterator
    // LETS ADD AUTO 1!1!!!1!
    return IteratorRange{
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

    set<int> nums = {5, 7, 12, 8, 10, 5, 6 , 1};

    for (int x : Head(nums,4)) {
        cout << x << ' ';
    }
    cout << endl;

    // We had an issue with const_iterator
    // in IteratorRange<typename Container::iterator>
    // It is solved because of auto and IteratorRange constructor
    const deque<int> nums2 = {5, 7, 12, 8, 10, 5, 6 , 1};

    for (int x : Head(nums2,4)) {
        cout << x << ' ';
    }
    cout << endl;


    return 0;
}