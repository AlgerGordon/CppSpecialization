//
// Created by General on 11.05.2020.
//


#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;


int main() {
    int n , stop_count, bus;
    cin >> n;
    string stop;
    map<set<string>, int> route_to_bus;
    for (int operInd = 0; operInd < n; ++operInd) {
        cin >> stop_count;
        set<string> tmp_route;
        for (int stop_ind = 0; stop_ind < stop_count; ++stop_ind) {
            cin >> stop;
            tmp_route.insert(stop);
        }
        if (route_to_bus.count(tmp_route) == 0) {
            bus = route_to_bus.size() + 1;
            route_to_bus[tmp_route] = bus;
            cout << "New bus " << bus << endl;
        } else {
            cout << "Already exists for " << route_to_bus[tmp_route] << endl;
        }
    }
    return 0;
}