//
// Created by General on 12.05.2020.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;


class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        first_name_hist[year] = first_name;
        // добавить факт изменения имени на first_name в год year
    }
    void ChangeLastName(int year, const string& last_name) {
        last_name_hist[year] = last_name;
        // добавить факт изменения фамилии на last_name в год year
    }
    string GetFullName(int cur_year) {
        if ((first_name_hist.empty() ? true : cur_year < rbegin(first_name_hist)->first) \
            && (last_name_hist.empty() ? true : cur_year < rbegin(last_name_hist)->first)){
            return "Incognito";
        }
        if ((first_name_hist.empty() ? false : cur_year >= rbegin(first_name_hist)->first) \
            && (last_name_hist.empty() ? false : cur_year >= rbegin(last_name_hist)->first)){
            return first_name_hist.lower_bound(cur_year)->second + " " \
                        + last_name_hist.lower_bound(cur_year)->second;
        }
        if (last_name_hist.empty() ? true : cur_year < rbegin(last_name_hist)->first)  {
            return first_name_hist.lower_bound(cur_year)->second + " with unknown last name";
        }
        if ( first_name_hist.empty() ? true : cur_year < rbegin(first_name_hist)->first) {
            return last_name_hist.lower_bound(cur_year)->second  + " with unknown first name";
        }
    }
private:
    map<int, string, greater<>> first_name_hist;
    map<int, string, greater<>> last_name_hist;

};


int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    return 0;
}

