//
// Created by General on 01.08.2020.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){
    int range_length = range_end - range_begin;
    if (range_length < 2) {
        return;
    }
    vector<typename RandomIt::value_type> elements(range_begin, range_end);
    RandomIt range_mid = elements.begin() + range_length / 2;
    MergeSort(elements.begin(), range_mid);
    MergeSort(range_mid, elements.end());
    merge(elements.begin(), range_mid, range_mid, elements.end(), range_begin);
};


int main() {
    vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
    MergeSort(begin(v), end(v));
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}