//
// Created by General on 01.06.2020.
//

#include <iostream>
#include <vector>
using namespace std;


int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    int64_t sum = 0;
    for (int ind = 0; ind  < N; ++ind) {
        cin >> v[ind];
        sum += v[ind];
    }
    vector<int> above_average_indeces;
    auto average_temp = static_cast<int32_t>(sum / N);
    for (int ind = 0; ind  < N; ++ind) {
        if (v[ind] > average_temp) {
            above_average_indeces.push_back(ind);
        }
    }
    cout << above_average_indeces.size() << endl;
    for (auto t : above_average_indeces) {
        cout << t << " ";
    }
    return 0;
}
