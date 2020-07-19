//
// Created by General on 19.07.2020.
//


#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Lang {
    string name;
    int age;
};

ostream& operator << (ostream& os, const Lang& lang)
{
    os << lang.name << " " << lang.age << endl;
    return os;
}

template <typename K, typename V>
ostream& operator << (ostream& os, pair<K,V> item)
{
    os << item.first << ' ' << item.second;
    return os;
}

bool operator < (const Lang& lhs, const Lang& rhs)
{
    return lhs.name < rhs.name;
}

template <typename It>
void PrintRange(It range_begin, It range_end)
{
    for(auto it = range_begin; it != range_end; ++it)
    {
        cout << *it << " ";
    }
}

int main() {
//    map<string, int> langs = {
//            {"Python", 26},
//            {"C++", 34},
//            {"C", 45},
//            {"Java", 22},
//            {"C#", 17}};
//    auto it = find_if(
//            begin(langs), end(langs),
//            [](const pair<string, int> lang) {
//                return lang.first == "C++";
//            });
//    PrintRange(langs.begin(), langs.end());
//    cout << "Function output" << endl;
//    PrintRange(langs.begin(), it);
//    cout << endl;
//    PrintRange(it, langs.end());

    vector<string> langs = {
            "Python", "C++", "C", "Java", "C#"
    };
    auto it = end(langs);
    while(it != begin(langs)) {
        --it;
        cout << *it << " ";
    }


    return 0;

}
