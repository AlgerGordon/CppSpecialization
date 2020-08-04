//
// Created by General on 02.08.2020.
//

#include <iostream>
#include <string>

using namespace std;



int main() {

    int variable, NUMBER_OF_OPERATIONS;
    cin >> variable >> NUMBER_OF_OPERATIONS;
    if (NUMBER_OF_OPERATIONS == 0) {
        cout << to_string(variable) << endl;
        return 0;
    }
    string str = to_string(variable);
    str.insert(0, string(NUMBER_OF_OPERATIONS, '('));
    char operation;
    for (int i = 0; i < NUMBER_OF_OPERATIONS; i++){
        cin >> operation >> variable;
        str.push_back(')');
        str.push_back(' ');
        str.push_back(operation);
        str.push_back(' ');
        string str_var = to_string(variable);
        str.insert(str.end(), str_var.begin(), str_var.end());
    }
    cout << str << endl;

    return 0;
}