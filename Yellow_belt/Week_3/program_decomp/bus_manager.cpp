//
// Created by General on 19.07.2020.
//

#include "bus_manager.h"


void BusManager::AddBus(const string& bus, const vector<string>& stops) {
    // Реализуйте этот метод
    this->buses_to_stops[bus] = stops;
    for (const string& stop : stops) {
        this->stops_to_buses[stop].push_back(bus);
    }
}

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
    // Реализуйте этот метод
    if (stops_to_buses.count(stop) == 0) {
        return BusesForStopResponse{vector<string>()};
    } else {
        return BusesForStopResponse{this->stops_to_buses.at(stop)};
    }
}

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
    // Реализуйте этот метод
    vector<pair<string, vector<string>>> result;

    if (buses_to_stops.count(bus) > 0) {
        for (const string& stop : buses_to_stops.at(bus)) {
            result.push_back(make_pair(stop, this->stops_to_buses.at(stop)));
        }
    }
    return StopsForBusResponse{bus, result};
}

AllBusesResponse BusManager::GetAllBuses() const {
    // Реализуйте этот метод
    return {this->buses_to_stops};
}
