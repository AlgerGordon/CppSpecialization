//
// Created by General on 10.05.2020.
//

//
// Created by General on 08.05.2020.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

map<char, int> BuildCharCounters(const string& str) {
    map<char, int> result;
    for (char c : str) {
        ++result[c];
    }
    return result;
}

int main() {
    int n;
    string first_word, second_word;
    cin >> n;
    for (int ind = 0; ind < n; ++ind) {
        cin >> first_word >> second_word;
        BuildCharCounters(first_word) == BuildCharCounters(second_word) ? \
                                cout << "YES" << endl : cout << "NO" << endl;
    }

    return 0;
}