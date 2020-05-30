//
// Created by General on 03.05.2020.
//

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double A, B, C, D;
    cin >> A >> B >> C;

    if (A != 0){
        D = B*B - 4*A*C;
        if (D > 0){
            cout << (-B + sqrt(D))/(2*A) << " " << (-B - sqrt(D))/(2*A);
        }else if(D == 0){
            cout << -B/(2*A);
        }
    }else if (B != 0){
        cout << -C / B;
    }

    return 0;
}
