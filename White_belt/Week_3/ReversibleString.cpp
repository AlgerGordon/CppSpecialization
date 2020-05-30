//
// Created by General on 13.05.2020.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class ReversibleString {
public:
    ReversibleString(const string&  init_str = "") {
        data = init_str;
    }
    void Reverse() {
        reverse(data.begin(), data.end());
    }
    string ToString() const {
        return data;
    }
private:
    string data;
};


int main() {
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;

    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;

    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;

    return 0;
}