//
// Created by General on 02.08.2020.
//

// Task NameHistory-4

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

string GetNameByYear(const map<int,string>& names, int year)
{
    map<int, string,greater<>>::const_iterator it_ub = names.upper_bound(year);
    // O(logQ) because of binary_search in upper_bound
    string name{};
    if(it_ub != names.begin()){
        name = (--it_ub)->second;
    }
    return name;
    // O(logQ + L) {+L is because of coping strings}
}

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        first_name_hist[year] = first_name;
        // O(logQ + L) {+L is because of coping strings}
    }
    void ChangeLastName(int year, const string& last_name) {
        last_name_hist[year] = last_name;
        // O(logQ + L) {+L is because of coping strings}
    }
    string GetFullName(int cur_year) {
        string firstName = GetNameByYear(first_name_hist, cur_year);
        string lastName = GetNameByYear(last_name_hist, cur_year);

        if (firstName.empty() && lastName.empty()){
            return "Incognito";
        }
        if (!firstName.empty() && !lastName.empty()){
            return firstName + " " + lastName;
        }
        if (lastName.empty())  {
            return firstName + " with unknown last name";
        }
        if (firstName.empty()) {
            return lastName  + " with unknown first name";
        }
        return {};
        // O(logQ + L)
    }
private:
    map<int, string> first_name_hist;
    map<int, string> last_name_hist;
};

// O(Q * (L + logQ)) {because we have Q calls of functions, O(logQ + L) each}


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

