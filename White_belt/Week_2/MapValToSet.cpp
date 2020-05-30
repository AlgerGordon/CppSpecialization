//
// Created by General on 11.05.2020.
//


#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;


set<string> BuildMapValuesSet(const map<int, string>& m) {
    set<string> result;
    for (const auto& item : m) {
        result.insert(item.second);
    }
    return result;
}