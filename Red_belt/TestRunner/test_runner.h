//
// Created by General on 12.07.2020.
//

#pragma once

#include <iostream>
#include <set>
#include <map>
#include <string>
#include <sstream>

#include "MyPrint.h"

using namespace std;

#define AS_KV(x) #x << " = " << x
#define RUN_TEST(tr, func) tr.RunTest(func, #func)
#define ASSERT_EQUAL(x, y) {                \
    ostringstream os;                       \
    os << #x << " != " << #y << ", "        \
        << __FILE__ << ":" << __LINE__;     \
    AssertEqual(x, y, os.str());            \
}
#define ASSERT(x, y) {                      \
    ostringstream os;                       \
    os << #x << " is false" << ", "         \
        << __FILE__ << ":" << __LINE__;     \
    Assert(x, os.str());                    \
}

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
    if (!(t == u)) {
        ostringstream  os;
        os << "Assertion failed: " << AS_KV(t) << " != " << AS_KV(u) << " "
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

