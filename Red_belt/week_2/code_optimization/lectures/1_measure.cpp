//
// Created by General on 19.08.2020.
//


#include <iostream>
#include <fstream>
#include <set>

#include <profile.h>

using namespace std;


int main() {
    LOG_DURATION("Total");

    // This path start in an appropriate cmake-debug-build directory
    // I have just copied it
    ifstream in("measure_input.txt");
    int element_count;
    in >> element_count;
    cout << element_count << endl;

    set<int> elements;
    {
        LOG_DURATION("Input");
        for (int i = 0; i < element_count; ++i) {
            int x;
            in >> x;
            elements.insert(x);
        }
    }


    int query_count;
    in >> query_count;

    int total_found = 0;
    {
        LOG_DURATION("Query");
        for (int i = 0; i < query_count; ++i) {
            int x;
            in >> x;
            if (elements.find(x) != elements.end()) {
                ++total_found;
            }
        }
    }
    cout << total_found << endl;

    return 0;
}