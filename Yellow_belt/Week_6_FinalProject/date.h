//
// Created by General on 11.08.2020.
//

#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <vector>

using namespace std;

class Date {
public:
    Date (int new_year, int new_month, int new_day)
        : year(new_year), month(new_month), day(new_day){}

    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;
private:
    int year;
    int month;
    int day;
};

Date ParseDate(istream& input_date);

ostream& operator << (ostream& os, const Date& date);

bool operator < (const Date& lhs, const Date& rhs);