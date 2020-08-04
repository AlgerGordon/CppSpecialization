//
// Created by General on 23.07.2020.
//

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
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



//    First video: container methods
//
//    vector<string> langs = {
//            "Python", "C++", "C", "Java", "C#"
//    };
//    auto it = find(langs.begin(), langs.end(),"C++");
//    langs.erase(it, langs.end());
//    langs.insert(langs.begin(),"C++");
//    PrintRange(langs.begin(), langs.end());

//    Second video: using iters in std algs
//
//    vector<string> langs = {
//            "Python", "C++", "C", "Java", "C#"
//    };
//    // False elements are moved to the beginning (they should remain)
//    // and returns it to first element to be removed.
//    // DOESN'T CHANGE CONTAINER SIZE !!!!!
//    auto it = remove_if(begin(langs), end(langs),
//                        [](const string &lang) {
//                            return lang[0] == 'C';
//                        });
//    langs.erase(it, end(langs))

//    langs = {
//            "Python", "C++", "C++", "Java", "C++"
//    };
    // Eliminates all except the first element from every consecutive group
    // of equivalent elements from the range [first, last) and returns
    // a past-the-end iterator for the new logical end of the range.
//    auto it = unique(begin(langs), end(langs));
//    langs.erase(it, end(langs));
//    PrintRange(begin(langs), end(langs));
//
//    auto it = min_element(begin(langs), end(langs));
//    cout << *it << endl;
//    auto p = minmax_element(begin(langs), end(langs));
//    cout << *p.first << ' ' << *p.second << endl;

//    set<string> langs_s = {
//            "Python", "C++", "C++", "java", "C++"
//    };
//    cout << all_of(begin(langs), end(langs),
//                   [](const string &lang) {
//                       return lang[0] >= 'A' && lang[0] <= 'Z';
//                   });

//    Third video: reverse_iterator
//
//    vector<string> langs = {
//            "Python", "C++", "C", "Java", "C#"
//    };
//
//    PrintRange(rbegin(langs), rend(langs));
//    cout << endl;
//    cout << *rbegin(langs) << endl;
//
//    auto it = rbegin(langs);
//    cout << *it << endl;
//    ++it;
//    cout << *it << endl;
//
//    auto it_f = find_if(rbegin(langs), rend(langs),
//                      [](const string &lang) {
//                          return lang[0] == 'C';
//                      });
//    cout << *it_f << endl;
//
//    sort(rbegin(langs), rend(langs));
//    PrintRange(begin(langs), end(langs));


//  Fourth video: set оf elements to be returned

    vector<string> langs = {
            "Python", "C++", "C", "Java", "C#"
    };

//    // Moves true elements in the beginning, returns first false element's iterator
//    partition(begin(langs), end(langs),
//              [](const string &lang) {
//                  return lang[0] == 'C';
//              });
//    PrintRange(begin(langs), end(langs));

    // The same idea with partition, but copies only necessary items.
    // DOESN'T CHANGE CONTAINER SIZE, turns false elements to '' (emptiness)
    // Return "end" iterator of the "new" container with spaces
    vector<string> c_langs(langs.size());  // C_LANGS !!!! not langs
    auto it_copy = copy_if(begin(langs), end(langs), begin(c_langs),
                      [](const string &lang) {
                          return lang[0] == 'C';
                      });
    PrintRange(begin(c_langs), end(c_langs), ',');
    c_langs.erase(it_copy, end(c_langs));
    cout << endl;
    PrintRange(begin(c_langs), end(c_langs), ',');

//    set<int> a = {1, 8 ,3};
//    set<int> b = {3, 6, 8};
//    vector<int> v(a.size());
//    auto it_set = set_intersection(begin(a), begin(b),
//                                   begin(b), end(b), begin(v));
//    PrintRange(begin(v), it_set);


    return 0;

}
