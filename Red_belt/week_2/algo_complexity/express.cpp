#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <set>
using namespace std;

class RouteManager {
public:
    void AddRoute(int start, int finish) {
        reachable_lists_[start].insert(finish);
        reachable_lists_[finish].insert(start);
    }

    int FindNearestFinish(int start, int target) const {
        int result = abs(start - target);
        if (reachable_lists_.count(start) < 1) {
            return result;
        }
        const set<int>& reachable_stations = reachable_lists_.at(start);
        if (reachable_stations.count(target) > 0) {
            return 0;
        }
        auto it_lb = reachable_stations.lower_bound(target);
        if (it_lb != reachable_stations.end()) {
            result = min(abs(target - *it_lb), result);
        }
        if (it_lb != reachable_stations.begin()) {
            return min(abs(target - *prev(it_lb)), result);
        }
        return result;
    }

private:
    map<int, set<int>> reachable_lists_;
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    RouteManager routes;

    int query_count;
    cin >> query_count;

    for (int query_id = 0; query_id < query_count; ++query_id) {
        string query_type;
        cin >> query_type;
        int start, finish;
        cin >> start >> finish;
        if (query_type == "ADD") {
            routes.AddRoute(start, finish);
        } else if (query_type == "GO") {
            cout << routes.FindNearestFinish(start, finish) << "\n";
        }
    }

    return 0;
}
