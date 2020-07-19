//
// Created by General on 19.07.2020.
//

#pragma once

#include <map>
#include <vector>

using namespace std;

struct BusesForStopResponse {
    vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
    string bus;
    vector<pair<string, vector<string>>> stops_to_buses;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
    map<string, vector<string>> all_buses;
};


ostream& operator << (ostream& os, const AllBusesResponse& r);