//
// Created by General on 11.05.2020.
//

#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {

    int n;
    string str;
    cin >> n;
    set<string> uniqueStrs;
    for (int ind = 0; ind < n; ++ind) {
        cin >> str;
        uniqueStrs.insert(str);
    }
    cout << uniqueStrs.size() << endl;
    return 0;
}