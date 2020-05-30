//
// Created by General on 08.05.2020.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination) {

    for (auto& s : source){
        destination.push_back(s);
    }
    source.clear();
}

int main() {
    vector<string> source = {"a", "b", "c"};
    vector<string> destination = {"z"};
    MoveStrings(source, destination);
    for (auto& s : destination){
        cout << s << " ";
    }
    return 0;
}