//
// Created by General on 16.05.2020.
//

#include <iostream>
#include <sstream>
#include <exception>
using namespace std;

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

int LCM(int a, int b) {
    return a * b / GCD(a,b);
}

class Rational {
public:
    Rational(){
        numerator = 0; denominator = 1;
    }
    Rational(int new_numerator, int new_denominator) {
        if (new_denominator == 0) {
            throw invalid_argument("Invalid argument");
        }
        int gcd = GCD(abs(new_numerator), abs(new_denominator));
        int sign =  (new_numerator > 0 == new_denominator > 0) ? 1 : -1;
        numerator = sign * abs(new_numerator) / gcd;
        denominator = (numerator == 0) ? 1 : abs(new_denominator) / gcd;
    }

    int Numerator() const{
        return numerator;
    }
    int Denominator() const{
        return denominator;
    }
    void SetNumerator(int new_numenator){
        numerator = new_numenator;
    }
    void SetDenominator(int new_denominator) {
        denominator = new_denominator;
    }
private:
    int numerator;
    int denominator;
};

bool operator==(const Rational& lhs, const Rational& rhs) {
    return (lhs.Numerator() * rhs.Denominator()) == (rhs.Numerator() * lhs.Denominator());
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
    int lcm = LCM(abs(lhs.Denominator()), abs(rhs.Denominator()));
    int num = lhs.Numerator()  * (lcm / lhs.Denominator())
              + rhs.Numerator()  * (lcm / rhs.Denominator());
    return {num, lcm};
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
    int lcm = LCM(abs(lhs.Denominator()), abs(rhs.Denominator()));
    int num = lhs.Numerator()  * (lcm / lhs.Denominator())
              - rhs.Numerator()  * (lcm / rhs.Denominator());
    return {num, lcm};
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    if (rhs.Numerator() == 0) {
        throw domain_error("Division by zero");
    }
    Rational tmp_1(lhs.Numerator(), rhs.Numerator());
    Rational tmp_2(rhs.Denominator(), lhs.Denominator());
    return {tmp_1.Numerator()*tmp_2.Numerator(),
            tmp_1.Denominator()*tmp_2.Denominator()};
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
    Rational tmp_1(lhs.Numerator(), rhs.Denominator());
    Rational tmp_2(rhs.Numerator(), lhs.Denominator());
    return {tmp_1.Numerator()*tmp_2.Numerator(),
            tmp_1.Denominator()*tmp_2.Denominator()};
}


istream& operator>>(istream& stream, Rational& rational) {
    int num, den;
    char delim;
    if (stream) {
        stream >> num >> delim >> den;
        if (stream && delim == '/') {
            Rational tmp(num, den);
            rational.SetNumerator(tmp.Numerator());
            rational.SetDenominator(tmp.Denominator());
        } else {
            throw invalid_argument("Invalid argument");
        }
    }
    return stream;
}

ostream& operator<<(ostream& stream, const Rational& rational) {
    stream << rational.Numerator() << "/" << rational.Denominator();
    return stream;
}

bool operator<(const Rational& lhs, const Rational& rhs) {
    return (lhs.Numerator() * rhs.Denominator()) < (rhs.Numerator() * lhs.Denominator());
}

char GetNextSymbol(istream& stream) {
    char operation_code;
    cin >> operation_code;
    if (!(operation_code == '+'
        || operation_code== '-'
        || operation_code == '/'
        || operation_code == '*')) {
        throw invalid_argument("Invalid argument");
    }
    return operation_code;
}

int main() {
    Rational r1, r2;
    try {
        cin >> r1;
        char operation_code = GetNextSymbol(cin);
        cin >> r2;
        Rational res;
        switch (operation_code) {
            case '+':
                res = r1 + r2;
                break;
            case '-':
                res = r1 - r2;
                break;
            case '/':
                res = r1 / r2;
                break;
            case '*':
                res = r1 * r2;
                break;
            default:
                throw invalid_argument("Invalid argument");
        }
        cout << res << endl;
    } catch (exception& ex) {
        cout << ex.what() <<endl;
    }
    return 0;
}