//
// Created by General on 01.08.2020.
//

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;



int main(){
    unsigned int N;
    cin >> N;
    vector<unsigned int> v(N);
    iota(v.rbegin(), v.rend(), 1);
    do {
        for (auto item : v) {
            cout << item << ' ';
        }
        cout << endl;
    } while(prev_permutation(v.begin(), v.end()));


    return 0;
}