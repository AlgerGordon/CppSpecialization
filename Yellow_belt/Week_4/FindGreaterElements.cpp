//
// Created by General on 19.07.2020.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

template<typename T>
ostream &operator<<(ostream &os, const set<T> &my_set)
{
    for (const T &item : my_set) {
        os << item << " ";
    }
    return os;
}

template<typename T>
vector<T> FindGreaterElements(const set<T> &elements, const T &border) {
//    auto it = begin(elements);
//    while (it != end(elements) && *it <= border) {
//        ++it;
//    }
    auto greater_it = find_if(elements.begin(), elements.end(),[border](const T &x){return x > border;});
    return {greater_it, elements.end()};
}

int main() {
    for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
        cout << x << " ";
    }
    cout << endl;

    string to_find = "Python";
    cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
    return 0;
}
