//
// Created by General on 30.07.2020.
//

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

#include "../../MyPrint/MyPrint.h"

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

bool operator < (const Lang& lhs, const Lang& rhs)
{
    return lhs.name < rhs.name;
}

template <typename It>
void PrintRange(It range_begin, It range_end, char delim = ' ')
{
    bool isFirst = true;
    for(auto it = range_begin; it != range_end; ++it)
    {
        if (isFirst) {
            cout << *it;
            isFirst = false;
            continue;
        }
        cout << delim << *it;
    }
}

int main() {

    vector<string> langs = {
            "Python", "C++", "C", "Java", "C#"
    };
    vector<string> c_langs;
    // back_inserter pushes back new elems if it is needed.
    // vector c_langs's size raises along the programm
    copy_if(begin(langs), end(langs), back_inserter(c_langs),
            [](const string &lang) {
                return lang[0] == 'C';
            });
    PrintRange(begin(c_langs), end(c_langs));

//    set<int> a = {1, 3, 8};
//    set<int> b = {3, 7 ,8};
//    set<int> res;
    // the same idea
//    set_intersection(begin(a),end(a), begin(b), end(b), inserter(res, end(res)));
//    cout << endl;
//    PrintRange(begin(res), end(res));

    auto it_f = find_if(begin(langs), end(langs),
                      [](const string &lang) {
                          return lang[0] == 'C';
                      });
    // Vector's iterators could be substracted
    cout << endl << it_f - begin(langs) << endl;

    set<int> s = {1, 6, 8, 9};
    // compilation error
    // end(s) - begin(s);

    auto it_s = s.find(6);
    // OK!
    ++it_s;
    // Error: cant add literal "1" !!!
    // PrintRange(it_s + 1, end(s));
    // That it why next(it) exists.
    // next() DOESN'T change variable, returns next it
    PrintRange(next(it_s), end(s));

    return 0;

}
