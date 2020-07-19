//
// Created by General on 19.07.2020.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(const string& s) {
    string::const_iterator it_begin = s.begin(), it_end;
    vector<string> res;
    do {
        it_end = find(it_begin, s.end(),' ');
        res.emplace_back(it_begin, it_end);
        it_begin = it_end != s.end() ? ++it_end : it_end;
    } while (it_begin != s.end());
    return res;
}

int main() {
    string s = "C Cpp Java Python";

    vector<string> words = SplitIntoWords(s);
    cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
        if (it != begin(words)) {
            cout << "/";
        }
        cout << *it;
    }
    cout << endl;

    return 0;
}
