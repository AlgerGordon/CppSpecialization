//
// Created by General on 24.06.2020.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    string bus;
    string stop;
    vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
    string operation_code;
    is >> operation_code;
    if (operation_code == "NEW_BUS") {
        q.type = QueryType::NewBus;
        is >> q.bus;
        int stop_count;
        is >> stop_count;
        q.stops.resize(stop_count);
        for (string &stop : q.stops) {
            is >> stop;
        }
        q.stop = "";
    } else if (operation_code == "BUSES_FOR_STOP") {
        q.type = QueryType::BusesForStop;
        is >> q.stop;
        q.bus = "";
        q.stops = {};
    }  else if (operation_code == "STOPS_FOR_BUS") {
        q.type = QueryType::StopsForBus;
        is >> q.bus;
        q.stop = "";
        q.stops = {};
    } else if (operation_code == "ALL_BUSES") {
        q.type = QueryType::AllBuses;
        q.bus = "";
        q.stop = "";
        q.stops = {};
    }
    return is;
}

struct BusesForStopResponse {
    vector<string> buses;
};

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

struct StopsForBusResponse {
    string bus;
    vector<pair<string, vector<string>>> stops_to_buses;
};

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

struct AllBusesResponse {
    map<string, vector<string>> all_buses;
};

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

class BusManager {
public:
    void AddBus(const string& bus, const vector<string>& stops) {
        // Реализуйте этот метод
        buses_to_stops[bus] = stops;
        for (const string& stop : stops) {
            stops_to_buses[stop].push_back(bus);
        }
    }

    BusesForStopResponse GetBusesForStop(const string& stop) const {
        // Реализуйте этот метод
        if (stops_to_buses.count(stop) == 0) {
            return BusesForStopResponse{vector<string>()};
        } else {
            return BusesForStopResponse{stops_to_buses.at(stop)};
        }
    }

    StopsForBusResponse GetStopsForBus(const string& bus) const {
        // Реализуйте этот метод
        vector<pair<string, vector<string>>> result;

        if (buses_to_stops.count(bus) > 0) {
            for (const string& stop : buses_to_stops.at(bus)) {
                result.push_back(make_pair(stop, stops_to_buses.at(stop)));
            }
        }
        return StopsForBusResponse{bus, result};
    }

    AllBusesResponse GetAllBuses() const {
        // Реализуйте этот метод
        return {buses_to_stops};
    }
private:
    map<string, vector<string>> buses_to_stops;
    map<string, vector<string>> stops_to_buses;
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
    int query_count;
    Query q;

    cin >> query_count;

    BusManager bm;
    for (int i = 0; i < query_count; ++i) {
        cin >> q;
        switch (q.type) {
            case QueryType::NewBus:
                bm.AddBus(q.bus, q.stops);
                break;
            case QueryType::BusesForStop:
                cout << bm.GetBusesForStop(q.stop) << endl;
                break;
            case QueryType::StopsForBus:
                cout << bm.GetStopsForBus(q.bus) << endl;
                break;
            case QueryType::AllBuses:
                cout << bm.GetAllBuses() << endl;
                break;
        }
    }

    return 0;
}