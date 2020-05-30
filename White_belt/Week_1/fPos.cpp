//
// Created by General on 03.05.2020.
//

#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;

    cin >> s;
    size_t ind = s.find('f');
    if (ind!=std::string::npos){
        ind = s.find('f', ind+1);
        if (ind!=std::string::npos){
            cout << ind;
        }else {
            cout << "-1";
        }
    }else{
        cout << "-2";
    }

    return 0;
}