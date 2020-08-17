//
// Created by General on 14.08.2020.
//


#pragma once

#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include <test_runner.h>

using namespace std;

int GCD(int a, int b);

class Rational {
public:
    Rational();
    Rational(int new_numerator, int new_denominator);

    int Numerator() const;

    int Denominator() const;

    void SetNumerator(int new_numerator);

    void SetDenominator(int new_denominator);

private:
    int numerator;
    int denominator;
};

bool operator != (const Rational& lhs, const Rational& rhs);

ostream& operator << (ostream& stream, const Rational& r);

// Tests

void TestAll();
void TestConstructor();
void TestReduction();
void TestPositivity();
void TestNegativity();
void TestZeroNumerator();