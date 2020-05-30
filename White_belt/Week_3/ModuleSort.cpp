//
// Created by General on 11.05.2020.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void printVec(const vector<int>& v) {
    for (const int& item : v) {
        cout << item << " ";
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int ind = 0; ind < n; ++ind) {
        cin >> v[ind];
    }
    sort(begin(v), end(v), [](int x,int y){ return abs(x) < abs(y);});
    printVec(v);
    return 0;

}
