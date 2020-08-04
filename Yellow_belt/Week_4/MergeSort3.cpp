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
    RandomIt elements_one_third = elements.begin() + range_length / 3;
    MergeSort(elements.begin(), elements_one_third);
    RandomIt elements_two_third = elements.begin() + range_length * 2 / 3;
    MergeSort(elements_one_third, elements_two_third);
    MergeSort(elements_two_third, elements.end());
    vector<typename RandomIt::value_type> tmp_vec;
    merge(elements.begin(), elements_one_third, elements_one_third, elements_two_third, back_inserter(tmp_vec));
    merge(tmp_vec.begin(), tmp_vec.end(), elements_two_third, elements.end(), range_begin);
};


int main() {
    vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
    MergeSort(begin(v), end(v));
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}