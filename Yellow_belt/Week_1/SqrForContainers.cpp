//
// Created by General on 04.06.2020.
//

#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

// Предварительное объявление шаблонных функций
template <typename T>
T Sqr(T n);

template <typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second>& p);

template<typename T>
vector<T> Sqr(const vector<T>& v);

template<typename Key, typename Value>
map<Key, Value> Sqr(const map<Key, Value>& m);

// Объявляем шаблонные функции

template <typename T>
T Sqr(T n){
    return n * n;
}

template <typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second>& p) {
    return {Sqr(p.first), Sqr(p.second)};
}

template<typename T>
vector<T> Sqr(const vector<T>& v) {
    vector<T> res(v.size());
    for (size_t ind = 0; ind < v.size(); ++ind) {
        res[ind] = Sqr(v[ind]);
    }
    return res;
}

template<typename Key, typename Value>
map<Key, Value> Sqr(const map<Key, Value>& m) {
    map<Key, Value> res;
    for (const auto& [key, value] : m) {
        res[key] = Sqr(value);
    }
    return res;
}


int main() {

    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v)) {
        cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
            {4, {2, 2}},
            {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }
    return 0;
}