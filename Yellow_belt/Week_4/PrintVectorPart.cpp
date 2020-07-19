//
// Created by General on 19.07.2020.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &vec)
{
    for (const T &item : vec) {
        os << item << " ";
    }
    return os;
}

void PrintVectorPart(const vector<int> &numbers)
{
    vector<int>::const_iterator negative_it = find_if(numbers.begin(), numbers.end(),[](int x) { return x < 0; });
    for (auto it = negative_it; it != numbers.begin();) {
        cout << *(--it) << " ";
    }
}


int main() {
    PrintVectorPart({6, 1, 8, -5, 4});
    cout << endl;
    PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
    cout << endl;
    PrintVectorPart({6, 1, 8, 5, 4});
    cout << endl;
    return 0;
}