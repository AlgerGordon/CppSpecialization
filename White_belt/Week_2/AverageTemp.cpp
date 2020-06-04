//
// Created by General on 10.05.2020.
//

#include <iostream>
#include <vector>
using namespace std;


int main() {
    int N, sum = 0;
    cin >> N;
    vector<int> temp(N);
    for (int ind = 0; ind < N; ++ind) {
        cin >> temp[ind];
        sum += temp[ind];
    }
    vector<int> grThanAv;
    for (int ind = 0;ind < N; ++ind) {
        if ( temp[ind] > sum / N) {
            grThanAv.push_back(ind);
        }
    }
    cout << grThanAv.size() << endl;
    for (auto t : grThanAv) {
        cout << t << " ";
    }
    return 0;
}

