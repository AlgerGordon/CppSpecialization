//
// Created by General on 03.05.2020.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {

    int N;
    cin >> N;
    vector<int> binPres;

    do {
        binPres.push_back(N % 2);
        N = N / 2;
    } while (N > 0);

    for (int l = (binPres.size() - 1); l >= 0; --l){
        cout << binPres[l];
    }

    return 0;
}
