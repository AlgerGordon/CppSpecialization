//
// Created by General on 08.05.2020.
//


#include <iostream>
#include <vector>
using namespace std;

vector<int> Reversed(const vector<int>& v) {
    vector<int> res = v;
    int sz = v.size();
    int med = sz / 2;
    if (!v.empty()) {
        for (int ind = 0; ind < med; ++ind) {
            res[ind] = v[sz - 1 - ind];
            res[sz - 1 - ind] = v[ind];
        }
    }
    return res;
}

int main() {
    vector<int> numbers = {1, 5, 3, 4};
    vector<int> res = Reversed(numbers);
    for (auto n : res){
        cout << n << " ";
    }
    return 0;
}