//
// Created by General on 12.05.2020.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class SortedStrings {
public:
    void AddString(const string& s) {
        sorted_strings.push_back(s);
    }
    vector<string> GetSortedStrings() {
        sort(begin(sorted_strings), end(sorted_strings));
        return sorted_strings;
    }
private:
    vector<string> sorted_strings;
};

void PrintSortedStrings(SortedStrings& strings) {
    for (const string& s : strings.GetSortedStrings()) {
        cout << s << " ";
    }
    cout << endl;
}

int main() {
    SortedStrings strings;

    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    PrintSortedStrings(strings);

    strings.AddString("second");
    PrintSortedStrings(strings);

    return 0;
}
