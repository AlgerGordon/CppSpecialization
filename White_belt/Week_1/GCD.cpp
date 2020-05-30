//
// Created by General on 03.05.2020.
//


#include <iostream>
#include <string>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    while (a>0 && b>0 ){
        if (a>b){
            a = a%b;
        }else{
            b = b%a;
        }
    }
    cout << a+b;
    return 0;
}
