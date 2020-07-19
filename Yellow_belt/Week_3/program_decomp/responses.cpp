//
// Created by General on 19.07.2020.
//

#include <iostream>
#include "responses.h"

using namespace std;

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
    if (r.buses.empty()) {
        os << "No stop";
    } else {
        for (const string& bus : r.buses) {
            os << bus << " ";
        }
    }
    return os;
}

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
    if (r.stops_to_buses.empty()) {
        os << "No bus";
    } else {
        bool first = true;
        for (const auto& stop_to_buses : r.stops_to_buses) {
            if (!first) {
                os << endl;
            }
            first = false;
            os << "Stop " << stop_to_buses.first << ": ";
            if (stop_to_buses.second.size() == 1) {
                os << "no interchange";
            } else {
                for (const string& other_bus : stop_to_buses.second) {
                    if (r.bus != other_bus) {
                        os << other_bus << " ";
                    }
                }
            }
        }
    }
    return os;
}


ostream& operator << (ostream& os, const AllBusesResponse& r) {
    if (r.all_buses.empty()) {
        os << "No buses";
    } else {
        bool first = true;
        for (const auto& bus_stop_item : r.all_buses) {
            if (!first) {
                os << endl;
            }
            first = false;
            os << "Bus " << bus_stop_item.first << ": ";
            for (const string& stop : bus_stop_item.second) {
                os << stop << " ";
            }
        }
    }
    return os;
}
