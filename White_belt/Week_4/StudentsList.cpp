//
// Created by General on 15.05.2020.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
    string first_name;
    string second_name;
    string birth_day;
    string birth_month;
    string birth_year;
};

int main() {

    int n;
    cin >> n;
    string first_name, second_name;
    vector<Student> students(n);

    for (int k = 0; k < n; ++k) {
        cin >> students[k].first_name >> students[k].second_name
                >> students[k].birth_day >> students[k].birth_month >> students[k].birth_year;
    }
    int m, students_number;
    string operation_code;
    cin >> m;
    for (int l = 0; l < m; ++l) {
        cin >> operation_code >> students_number;
        if ((students_number < 1) || (students_number > n)) {
            cout << "bad request" << endl;
            continue;
        }
        --students_number;
        if (operation_code == "name") {
            cout << students[students_number].first_name << " "
                 << students[students_number].second_name << endl;
        } else if (operation_code == "date") {
            cout << students[students_number].birth_day << '.'
                 << students[students_number].birth_month << '.'
                 << students[students_number].birth_year << endl;
        } else {
            cout << "bad request" << endl;
        }
    }



    return 0;
}
