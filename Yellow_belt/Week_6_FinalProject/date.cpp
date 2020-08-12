//
// Created by General on 11.08.2020.
//


#include "date.h"

#include <iostream>
#include <iomanip>

using namespace std;

int Date::GetYear() const{
    return year;
}

int Date::GetMonth() const{
    return month;
}

int Date::GetDay() const{
    return day;
}

Date ParseDate(istream& input_stream) {
    int new_year, new_month, new_day;
    char c1, c2;
    input_stream >> new_year >> c1 >> new_month >> c2 >> new_day;
    if (input_stream && c1 == '-' && c2 == '-') { // or date_stream.eof();
        if (new_month > 12 || new_month < 1) {
            throw logic_error("Month value is invalid: " + std::to_string(new_month));
        }
        if (new_day > 31 || new_day < 1) {
            throw logic_error("Day value is invalid: " + std::to_string(new_day));
        }
        return {new_year, new_month, new_day};
    } else {
        throw logic_error("Wrong date format!");
    }
}


bool operator < (const Date& lhs, const Date& rhs){
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()}  <
           vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

ostream& operator << (ostream& stream, const Date& date) {
    stream << setw(4) << setfill('0') << date.GetYear() <<
           "-" << setw(2) << setfill('0') << date.GetMonth() <<
           "-" << setw(2) << setfill('0') << date.GetDay();
    return stream;
}
