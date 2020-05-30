//
// Created by General on 10.05.2020.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


int main() {
    int n , stop_count;
    cin >> n;
    string operation_code;
    string bus, stop;
    map<string, vector<string>> bus_to_stops, stop_to_buses;
    for (int operInd = 0; operInd < n; ++operInd) {
        cin >> operation_code;
        if (operation_code == "ALL_BUSES") {
            if (bus_to_stops.empty()) {
                cout << "No buses" << endl;
            } else {
                for (const auto& item : bus_to_stops){
                    cout << "Bus " << item.first << ": ";
                    for (const string& tmp_stop : bus_to_stops[item.first]) {
                        cout << tmp_stop << " " ;
                    }
                    cout << endl;
                }
            }
        } else if (operation_code == "BUSES_FOR_STOP") {
            cin >> stop;
            if (stop_to_buses.count(stop) == 0) {
                cout << "No stop" << endl;
            } else {
                for (const string& item : stop_to_buses[stop]){
                    cout  << item << " ";
                }
                cout << endl;
            }
        } else {
            cin >> bus;
            if (operation_code == "STOPS_FOR_BUS") {
                if (bus_to_stops.count(bus) == 0) {
                    cout << "No bus" << endl;
                } else {
                    for (const auto &tmp_stop : bus_to_stops[bus]) {
                        cout << "Stop " << tmp_stop << ": ";
                        if (stop_to_buses[tmp_stop].size() < 2) {
                            cout << "no interchange" << endl;
                        } else {
                            for (const string& tmp_bus : stop_to_buses[tmp_stop]) {
                                if (tmp_bus == bus) continue;
                                cout << tmp_bus << " ";
                            }
                            cout << endl;
                        }
                    }
                }
            } else if ( operation_code == "NEW_BUS") {
                cin >> stop_count;
                for (int stop_ind = 0; stop_ind < stop_count; ++stop_ind) {
                    cin >> stop;
                    bus_to_stops[bus].push_back(stop);
                    stop_to_buses[stop].push_back(bus);
                }
            }
        }
    }


    return 0;
}