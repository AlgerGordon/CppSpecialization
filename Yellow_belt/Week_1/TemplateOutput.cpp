//
// Created by General on 04.06.2020.
//

#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <utility>
using namespace std;

template <typename Collection>
string Join(const Collection& c, char d) {
    stringstream ss;
    bool is_first = true;
    for (const auto& item : c) {
        if (!is_first) {
            ss << d;
        }
        is_first = false;
        ss << item;
    }
    return ss.str();
}

template <typename First, typename Second>
ostream& operator<< (ostream& out, const pair<First, Second>& p) {
    return out << '(' << p.first << "," << p.second << ')';
}

template <typename T>
ostream& operator<< (ostream& out, const vector<T> v) {
    return out << '[' << Join(v, ',') << ']';
}

template <typename Key, typename Value>
ostream& operator<< (ostream& out, const map<Key, Value> &m) {
    return out << '{' << Join(m, ',') << '}';
}


int main() {
    vector<double> vi = {1.4, 2, 3};
    cout << vi << endl;
    map<int, double> m = {{1, 2.5}, {3, 4}};
    cout << m << endl;
    vector<vector<int>> v = {{1, 2}, {3, 4}};
    cout << v << endl;

    return 0;
}