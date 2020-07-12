//
// Created by General on 27.06.2020.
//

#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        } catch (exception& e) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        } catch (...) {
            ++fail_count;
            cerr << "Unknown exception caught" << endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " unit tests failed. Terminate" << endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};

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

class Rational {
public:
    Rational(){
        numerator = 0; denominator = 1;
    }
    Rational(int new_numerator, int new_denominator) {
        if (new_denominator == 0) {
            throw invalid_argument("Zero denominator");
        }
        int gcd = GCD(abs(new_numerator), abs(new_denominator));
        int sign =  (new_numerator > 0) == (new_denominator > 0) ? 1 : -1;
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

bool operator !=(const Rational& lhs, const Rational& rhs) {
    return (lhs.Numerator() * rhs.Denominator()) != (rhs.Numerator() * lhs.Denominator());
}

ostream& operator<<(ostream& stream, const Rational& r) {
    stream << r.Numerator() << "/" << r.Denominator();
    return stream;
}

void TestConstructor() {
    Rational r;
    Assert(!(r.Numerator() != 0 || r.Denominator() != 1), "Incorrect Rational()");
}

void TestReduction() {
    Rational r(-15, -12);
    Assert(!(r.Numerator() != 5 || r.Denominator() != 4), "Reduction with negative");
    Rational r1(12, 128);
    Assert(!(r1.Numerator() != 3 ||r1.Denominator() != 32), "Reduction with positive");
    Rational r2(12,-9);
    Assert(!(r2.Numerator() != -4 || r2.Denominator() != 3), "Reduction with negative denominator");
    Rational r3(-21,49);
    Assert(!(r3.Numerator() != -3 || r3.Denominator() != 7), "Reduction with negative numerator");
}

void TestPositivity() {
    Rational r(-2, -3);
    Assert(!(r.Numerator() != 2 || r.Denominator() != 3), "Incorrect minus sign reduction");
    Rational r1(2, 3);
    Assert(!(r1.Numerator() !=2 || r1.Denominator() != 3), "Incorrect plus sign reduction");
}

void TestNegativity() {
    Rational r(4, -5);
    Assert(!(r.Numerator() != -4  || r.Denominator() != 5), "Incorrect negative fraction");
    Rational r1(-4, 5);
    Assert(!(r1.Numerator() != -4 || r1.Denominator() != 5), "Incorrect negative fraction");
}

void TestZeroNumerator() {
    Rational r(0,5);
    Assert(!(r.Numerator() != 0 || r.Denominator() != 1), "Zero numerator");
    Rational r1(0, -1);
    Assert(!(r1.Numerator() != 0 || r1.Denominator() != 1), "0/-1");
}

int main() {
    TestRunner runner;
    runner.RunTest(TestConstructor,"TestConstructor" );
    runner.RunTest(TestZeroNumerator,"TestZeroNumerator");
    runner.RunTest(TestReduction,"TestReduction");
    runner.RunTest(TestPositivity,"TestPositivity");
    runner.RunTest(TestNegativity,"TestNegativity");
    return 0;
}