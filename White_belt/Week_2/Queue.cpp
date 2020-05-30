//
// Created by General on 10.05.2020.
//


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


int main() {
    int N, person_index;
    cin >> N;
    string operation_code;
    vector<bool> queue;
    vector<int> worry_count;
    for (int ind = 0; ind < N; ++ind) {
        cin >> operation_code;
        if (operation_code == "WORRY_COUNT") {
            worry_count.push_back(count(begin(queue), end(queue), true));
        } else {
            cin >> person_index;
            if (operation_code == "QUIET") {
                queue[person_index] = false;
            } else if (operation_code == "WORRY") {
                queue[person_index] = true;
            } else if (operation_code == "COME") {
                queue.resize(queue.size() + person_index, false);
            }
        }
    }
    for (auto wc : worry_count) {
        cout << wc << endl;

    }
    return 0;
}

