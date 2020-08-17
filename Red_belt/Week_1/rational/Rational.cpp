//
// Created by General on 27.06.2020.
//

#include "Rational.h"

int GCD(int a, int b) {
    while (a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }
    return a + b;
}

bool operator != (const Rational& lhs, const Rational& rhs) {
    return (lhs.Numerator() * rhs.Denominator()) != (rhs.Numerator() * lhs.Denominator());
}

ostream& operator << (ostream& stream, const Rational& r) {
    stream << r.Numerator() << "/" << r.Denominator();
    return stream;
}

Rational::Rational(){
    numerator = 0; denominator = 1;
}

Rational::Rational(int new_numerator, int new_denominator) {
    if (new_denominator == 0) {
        throw invalid_argument("Zero denominator");
    }
    int gcd = GCD(abs(new_numerator), abs(new_denominator));
    int sign =  (new_numerator > 0) == (new_denominator > 0) ? 1 : -1;
    numerator = sign * abs(new_numerator) / gcd;
    denominator = (numerator == 0) ? 1 : abs(new_denominator) / gcd;
}

int Rational::Numerator() const{
    return numerator;
}

int Rational::Denominator() const{
    return denominator;
}
void Rational::SetNumerator(int new_numenator){
    numerator = new_numenator;
}
void Rational::SetDenominator(int new_denominator) {
    denominator = new_denominator;
}
