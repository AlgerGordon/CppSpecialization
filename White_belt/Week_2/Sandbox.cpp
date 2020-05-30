//
// Created by General on 08.05.2020.
//

#include <iostream>
#include <set>
#include <vector>

using namespace std;

void PrintSet(const set<string>& s){
    cout << "Size = " << s.size() << endl;
    for (auto& x : s) {
        cout << x <<endl;
    }
}

int main() {
    set<string> famous_persons;
    famous_persons.insert("Stroustrup");
    famous_persons.insert("Ritchi");
    famous_persons.insert("Igor");
    // PrintSet(famous_persons);

    famous_persons.erase("Igor");
    // PrintSet(famous_persons);

    set<string> month_names = {"January", "February", "March", "March"};
    set<string> other_month_names = { "March", "January", "February"};
    PrintSet(month_names);
    // cout << (month_names == other_month_names) << endl;

    cout << month_names.count("January") << endl;

    vector<string> v = {"a", "b", "a"};
    set<string> s(begin(v),end(v));
    PrintSet(s);

    return 0;
}