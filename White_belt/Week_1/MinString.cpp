//
// Created by General on 03.05.2020.
//

#include <iostream>
#include <string>


using namespace std;

int main(){
    string min, b;
    cin >> min;
    for (int i = 0; i < 2; ++i){
        cin >> b;
        min = min < b ? min : b;
    }
    cout << min;
    return 0;

}