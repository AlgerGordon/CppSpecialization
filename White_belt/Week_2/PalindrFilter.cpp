//
// Created by General on 08.05.2020.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;


bool IsPalindrom(const string s) {
    auto sz = s.size();
    auto mid = sz / 2;
    for(int ind = 0; ind <= mid; ++ind ){
        if (s[ind] != s[sz - 1 - ind]) {
            return false;
        }
    }
    return true;
}

vector<string> PalindromFilter(vector<string> words, int minLength) {
    vector<string> res = {};
    for( auto s : words) {
        if (IsPalindrom(s) && (s.size() >= minLength)) {
            res.push_back(s);
        }
    }
    return res;

}


int main() {
    vector<string> words = {"weew", "bro", "code"};
    for (auto s : PalindromFilter(words, 4)) {
        cout << s << " ";
    }

}