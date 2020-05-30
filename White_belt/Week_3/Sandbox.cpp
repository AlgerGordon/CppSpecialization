//
// Created by General on 08.05.2020.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Lecture {
    string title = "C++";
    int duration = 0;
};

int ComputeDistance(const string& source, const string& destination) {
    return source.length() - destination.length();
}

class Route {
public:
    Route() {
        source = "Moscow";
        destination = "Saint Petersburg";
        UpdateLength();
        cout << "Default constructor" << endl;
    }
    Route(const string& new_source,
            const string& new_destination) {
        source = new_source;
        destination = new_destination;
        UpdateLength();
        cout << "Constructor" << endl;
    }
    ~Route() {
        cout << "Destructed" << endl;
//        for (auto& entry : compute_distance_log) {
//            cout << entry << endl;
//        }
    }
    string GetSource() const {
        return source;
    }
    string GetDestination() const {
        return destination;
    }
    int GetLength() const {
        return length;
    }
    void SetSource(const string& new_source) {
        source = new_source;
        UpdateLength();
    }
    void SetDestination(const string& new_destination) {
        destination = new_destination;
        UpdateLength();
    }

private:
    void UpdateLength() {
        length = ComputeDistance(source, destination);
        compute_distance_log.push_back(source + " - " + destination);
    }
    string source;
    string destination;
    int length;
    vector<string> compute_distance_log;
};

void PrintRoute(const Route& route) {
    cout << route.GetSource() << " - "
        <<  route.GetDestination() << endl;
}

void ReverseRoute(Route& route) {
    string old_source = route.GetSource();
    string old_destination = route.GetDestination();
    route.SetSource(old_destination);
    route.SetDestination(old_source);
}

void Worthless (Route route) {
    cout << 2 << endl;
}

Route GetRoute() {
    cout << 7 << endl;
    return {};
}

int main() {
//    cout << 1 << endl;
//    Route first_route;
//    if (false) {
//        cout << 2 << endl;
//        return 0;
//    }
//    cout << 3 << endl;
//    Route second_route;
//    cout << 4 << endl;

//    cout << 5 << endl;
//    Worthless({});
//    cout << 6 << endl;

//    Route route = GetRoute();
//    cout << 8 << endl;

    GetRoute();
    cout << 8 << endl;

    return 0;
}