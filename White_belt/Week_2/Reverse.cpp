//
// Created by General on 08.05.2020.
//

#include <iostream>
#include <vector>
using namespace std;

void Reverse(vector<int>& v) {
    int sz = v.size();
    int med = sz / 2;
    int tmp;
    if (!v.empty()) {
        for (int ind = 0; ind < med; ++ind) {
            tmp = v[ind];
            v[ind] = v[sz - 1 - ind];
            v[sz - 1 - ind] = tmp;
        }
    }
}

int main() {
    vector<int> numbers = {1, 5, 3, 4};
    Reverse(numbers);
    for (auto n : numbers){
        cout << n << " ";
    }
    return 0;
}