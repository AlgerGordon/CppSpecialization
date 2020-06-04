//
// Created by General on 04.06.2020.
//

#include <iostream>
#include <map>
#include <vector>
#include <exception>

using namespace std;

template<typename KeyType, typename ValueType>
ValueType& GetRefStrict(map<KeyType, ValueType>& m, const KeyType& required_key) {
    if (m.count(required_key) == 0) {
        throw runtime_error("");
    }
    return m[required_key];
}

int main() {

    map<int, string> m = {{0, "value"}};
    string& item = GetRefStrict(m, 0);
    item = "newvalue";
    cout << m[0] << endl; // выведет newvalue


    return 0;
}