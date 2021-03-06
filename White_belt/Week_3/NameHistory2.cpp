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
    string GetFullName(int cur_year, bool wo_history = true) {
        if ((first_name_hist.empty() ? true : cur_year < rbegin(first_name_hist)->first) \
            && (last_name_hist.empty() ? true : cur_year < rbegin(last_name_hist)->first)){
            return "Incognito";
        }
        if ((first_name_hist.empty() ? false : cur_year >= rbegin(first_name_hist)->first) \
            && (last_name_hist.empty() ? false : cur_year >= rbegin(last_name_hist)->first)){
            return PrintNames(first_name_hist, cur_year, wo_history) + " " \
                        + PrintNames(last_name_hist, cur_year, wo_history) ;
        }
        if (last_name_hist.empty() ? true : cur_year < rbegin(last_name_hist)->first)  {
            return PrintNames(first_name_hist, cur_year, wo_history) + " with unknown last name";
        }
        if ( first_name_hist.empty() ? true : cur_year < rbegin(first_name_hist)->first) {
            return PrintNames(last_name_hist, cur_year, wo_history) + " with unknown first name";
        }
        return PrintNames(last_name_hist, cur_year, wo_history) + " with unknown first name";
    }
    string GetFullNameWithHistory(int cur_year) {
        if ((first_name_hist.empty() ? false : cur_year >= rbegin(first_name_hist)->first) \
            && (last_name_hist.empty() ? false : cur_year >= rbegin(last_name_hist)->first)){
            string first_names = PrintNames(first_name_hist, cur_year);
            string last_names = PrintNames(last_name_hist, cur_year);
            return first_names + " " + last_names;
        } else {
            return GetFullName(cur_year, false);
        }
    }
private:
    map<int, string, greater<>> first_name_hist;
    map<int, string, greater<>> last_name_hist;
    string PrintNames(const map<int, string, greater<>>& m, int cur_year, bool wo_hist = false) {
        if (wo_hist) {
            return  m.lower_bound(cur_year)->second;
        }
        vector<string> unique_names;
        for(auto& item : m){
            if (item.first <= cur_year){
                unique_names.push_back(item.second);
            } else {
                continue;
            }
        }
        auto ip = unique(unique_names.begin(),unique_names.end());
        unique_names.resize(distance(unique_names.begin(), ip));
        string output_str = unique_names[0];
        if (unique_names.size() < 2) {
            return output_str;
        }
        output_str += " (";
        for (int ind = 1; ind < (unique_names.size()-1); ++ind) {
            output_str += (unique_names[ind] + ", ");
        }
        output_str += (unique_names.back() + ")");
        return output_str;
    }
};




int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeFirstName(1965, "Appolinaria");

    person.ChangeLastName(1965, "Sergeeva");
    person.ChangeLastName(1965, "Volkova");
    person.ChangeLastName(1965, "Volkova-Sergeeva");

    for (int year : {1964, 1965, 1966}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    return 0;
}




