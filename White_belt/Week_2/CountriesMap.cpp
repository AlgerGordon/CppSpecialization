//
// Created by General on 10.05.2020.
//


#include <iostream>
#include <string>
#include <map>
using namespace std;


int main() {
    int n;
    cin >> n;
    string operation_code, country, capital;
    string old_country_name, new_country_name;
    map<string, string> country_to_capital;
    for (int ind = 0; ind < n; ++ind) {
        cin >> operation_code;
        if (operation_code == "DUMP") {
            if (country_to_capital.empty()) {
                cout << "There are no countries in the world" << endl;
            } else {
                for (auto &item : country_to_capital) {
                    cout << item.first << "/" << item.second << " ";
                }
                cout << endl;
            }
        } else if (operation_code == "RENAME") {
            cin >> old_country_name >> new_country_name;
            if ((old_country_name == new_country_name) \
                    || (country_to_capital.count(old_country_name) == 0) \
                    || (country_to_capital.count(new_country_name) == 1)){
                cout << "Incorrect rename, skip" << endl;
            } else {
                country_to_capital[new_country_name] = country_to_capital[old_country_name];
                country_to_capital.erase(old_country_name);
                cout << "Country " << old_country_name << " with capital " \
                        << country_to_capital[new_country_name] << " has been renamed to " << new_country_name << endl;
            }
        } else  {
            cin >> country;
            if (operation_code == "ABOUT") {
                if (country_to_capital.count(country) == 0) {
                    cout << "Country " << country <<" doesn't exist" << endl;
                } else {
                    cout << "Country " << country << " has capital " << country_to_capital[country] << endl;
                }
            } else if (operation_code == "CHANGE_CAPITAL") {
                cin >> capital;
                if (country_to_capital.count(country) == 0) {
                    country_to_capital[country] = capital;
                    cout << "Introduce new country "<< country <<" with capital " << capital << endl;
                } else if (capital == country_to_capital[country]) {
                    cout << "Country " << country << " hasn't changed its capital" << endl;
                } else {
                    cout << "Country " << country << " has changed its capital from " \
                                << country_to_capital[country] << " to " << capital << endl;
                    country_to_capital[country] = capital;
                }
            }
        }
    }

    return 0;
}


