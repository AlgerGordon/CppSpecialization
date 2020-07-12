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

bool IsPalindrom(const string& str) {
    auto sz = str.size();
    auto mid = sz / 2;
    for(int ind = 0; ind < mid; ++ind ){
        if (str[ind] != str[sz - 1 - ind]) {
            return false;
        }
    }
    return true;
}

void TestPalindrom() {
    Assert(IsPalindrom(""), "Empty string");
    Assert(IsPalindrom("a"), "One symbol");
    Assert(IsPalindrom("aa"), "Two symbols");
    Assert(IsPalindrom("wasitacaroracatisaw"), "Incorrect default case");
    Assert(!IsPalindrom("abca"), "Not to center");
    Assert(!IsPalindrom("  dered "), "Ignoring spaces");
    Assert(!IsPalindrom("a ba"), "Ignoring spaces in the word");
    Assert(IsPalindrom(" d e r e d "), "Test with spaces");
    Assert(!IsPalindrom("Abb"), "Ignoring first symbol");
    Assert(!IsPalindrom("AAb"), "Ignoring last symbol");
    Assert(!IsPalindrom("Madam"), "Wrong Register");
}

int main() {
    TestRunner runner;
    runner.RunTest(TestPalindrom, "TestPalindrom");
    return 0;
}