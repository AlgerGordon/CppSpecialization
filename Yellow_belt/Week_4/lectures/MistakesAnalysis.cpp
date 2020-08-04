//
// Created by General on 02.08.2020.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {

    // Video about mistakes

    set<int> s = {1, 2, 3, 4};
    // Compile error: "-" doesn't defined
    // cout << s.end() - s.begin() << endl;

    // Compile error: no match for iterator "+"
    // partial_sort(s.begin(), s.end(), s.begin()) << endl;

    // Compile error: assignment of read-only location
    // remove(s.begin(), s.end(), 0);

    vector<int> v1 = {1, 2, 7};
    vector<int> v2 = {3, 8};
    // Error: Iterators of DIFFERENT containers in functions
    // sort(v1.begin(), v2.end())

    // Error: Different type of iterators
    // sort(v1.begin(), v1.rend());

    return 0;
}
