//
// Created by General on 21.08.2020.
//


#include <iostream>
#include <vector>
#include <profile.h>
#include <algorithm>

using namespace std;

const int NUMBER_COUNT = 1000000;
const int NUMBER = 7654321;
const int QUERY_COUNT = 10;

int main() {

    // use set.lower_bound() method, not std::lower_bound
    // method is faster
    vector<int> v;
    for (int i = 0; i < NUMBER_COUNT; ++i) {
        v.push_back(i * 10);
    }
    {
        LOG_DURATION("lower bound");
        for (int i = 0; i < QUERY_COUNT; ++i) {
            lower_bound(begin(v), end(v), NUMBER);
        }
    }
    {
        LOG_DURATION("find if");
        for (int i = 0; i < QUERY_COUNT; ++i) {
            find_if(begin(v), end(v), [&](int y) {
                return y >= NUMBER;
            });
        }
    }
    return 0;
}