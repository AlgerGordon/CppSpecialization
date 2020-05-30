//
// Created by General on 03.05.2020.
//

#include <iostream>
using namespace std;

int main(){
    int A, B;
    cin >> A >> B;

    for (int n = (A + A%2); n < (B + 1); n+=2){
        cout << n << " ";
    }

    return 0;
}
