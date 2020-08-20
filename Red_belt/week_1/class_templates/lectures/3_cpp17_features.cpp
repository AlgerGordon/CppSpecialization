//
// Created by General on 17.08.2020.
//


#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct Widget {
    // If you want to inexplicit type generation,
    // it is important to have template T class in constructor
    Widget(T value);
};

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

// Инстанцирующая функция !

template <typename Iterator>
IteratorRange<Iterator> MakeRange(Iterator begin, Iterator end) {
    return IteratorRange<Iterator>{begin, end};
};


int main() {

    Widget w_int(5);        // Widget<int>
    Widget w_char('a');     // Widget<char>

    // Pair have such constructor, see cpp.ref
    pair p(5, true);

    // Now because cpp17 feature with constructor using template type T
    // type generates automatically.
    // In cpp14 IteratorRange IS NOT A TYPE

    vector<int> v = {1, 2, 3, 4, 5};
    IteratorRange second_half_1 = MakeRange(
            v.begin() + v.size() / 2, v.end()
    );
    for (int x : second_half_1) {
        cout << x << ' ';
    }

    // Disadvantages

    vector<int> v_i;
    vector<double> v_d;
    // r_i and r_d has DIFFERENT types, but it is not obvious
    IteratorRange r_i(v_i.begin(), v_i.end());
    IteratorRange r_d(v_d.begin(), v_d.end());

    // First: explicid type
    vector<int> v1;
    // Second: constructor
    pair p1(1,'a');
    // Third: generating functions
    auto p2 = make_pair('a', false);


    return 0;
}