//
// Created by General on 01.08.2020.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


int main() {

    // If container has eponymous method with the same algo
    // then it is reasonable to USE class METHOD

    // While searching in unsorted vector use:
    // find(), find_if() or count()
    string str = "Sweety Pie";
    for (auto it = find(begin(str), end(str), ' ');
         it != end(str); it = find(next(it), end(str), ' ')) {
        cout << it - begin(str) << " ";
    }

    // Search in sorted vector using binary search
    // It works the same in sets and maps
    vector<int> v = {1, 4, 10, 7, 5, 6, 14};
    binary_search(v.begin(), v.end(), 3);
    lower_bound(v.begin(), v.end(), 7);
    upper_bound(v.begin(), v.end(), 6);
    // equal_range(v.begin(), v.end(), '7') is
    // the same make_pair(lower_bound(), upper_bound)
    // equal_range = [lower_bound, upper_bound)

    // Searching in sets
    // s.count(), s.found()
    // s.lower_bound() and so on
    // equal_range is useful for checking if element exists


    return 0;
}
