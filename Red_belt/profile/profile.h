//
// Created by General on 19.08.2020.
//

#pragma once

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

class LogDuration {
public:
    explicit LogDuration(const string& msg = "" )
            : message(msg + ": "), start(steady_clock::now()) {}
    ~LogDuration() {
        auto finish = steady_clock::now();
        auto duration = finish - start;
        cerr << message << duration_cast<milliseconds>(duration).count()
             << "ms" << endl;
    }
private:
    string message;
    steady_clock::time_point start;
};

#define UNIQ_ID_IMPL(lineno) __a_local_var##lineno
#define UNIQ_ID(lineno) UNIQ_ID_IMPL(lineno)

#define LOG_DURATION(message)                       \
    LogDuration UNIQ_ID(__LINE__){message}          \

