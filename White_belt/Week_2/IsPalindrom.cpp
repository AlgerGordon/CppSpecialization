//
// Created by General on 08.05.2020.
//

#include <iostream>
#include <string>

using namespace std;

bool IsPalindrom(const string s) {
    auto sz = s.size();
    auto mid = sz / 2;
    for(int ind = 0; ind < mid; ++ind ){
        if (s[ind] != s[sz - 1 - ind]) {
            return false;
        }
    }
    return true;
}


int main() {
    string s;
    cin >> s;
    cout << IsPalindrom(s);
}