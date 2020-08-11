//
// Created by General on 12.07.2020.
//

#pragma once

#include <iostream>
#include <set>
#include <map>
#include <string>
#include <sstream>

using namespace std;


template <class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint);
void Assert(bool b, const string& hint);

class TestRunner {
public:
    template<class TestFunc>
    void RunTest(TestFunc func, const string &test_name);
    ~TestRunner();
private:
    int fail_count = 0;
};


template <class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint) {
    if (t != u) {
        ostringstream  os;
        os << "Assertion failed: " << t << " != " << u << " "
           << "Hint: " << hint;
        throw runtime_error(os.str());
    }
}

template<class TestFunc>
void TestRunner::RunTest(TestFunc func, const string &test_name) {
    try {
        func();
        cerr << test_name << " OK" << endl;
    } catch (runtime_error &e) {
        ++fail_count;
        cerr << test_name << " fail: " << e.what() << endl;
    }
}

