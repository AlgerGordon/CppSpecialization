//
// Created by General on 14.07.2020.
//

#include "PhoneNumber.h"
#include <iostream>
#include <sstream>

PhoneNumber::PhoneNumber(const string &international_number)
{
    istringstream ss(international_number);
    char delim;
    string str;
    ss >> delim;
    if (delim != '+')
    {
        throw invalid_argument("Number has to begin with \"+\"!");
    }
    if( !(getline(ss, country_code_,'-') && !country_code_.empty())){
        throw invalid_argument("Incorrect format!");
    }
    if( !(getline(ss, city_code_,'-') && !city_code_.empty())){
        throw invalid_argument("Incorrect format!");
    }
    if(!getline(ss, local_number_)){
        throw invalid_argument("Incorrect format!");
    }
}

string PhoneNumber::GetCountryCode() const
{
    return this->country_code_;
}

string PhoneNumber::GetCityCode() const
{
    return this->city_code_;
}

string PhoneNumber::GetLocalNumber() const
{
    return this->local_number_;
}

string PhoneNumber::GetInternationalNumber() const
{
    return {"+" + country_code_ + "-" + city_code_
        + "-" + local_number_};
}
