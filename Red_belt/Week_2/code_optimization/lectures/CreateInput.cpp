//
// Created by General on 19.08.2020.
//


#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
    srand(time(nullptr));

    string output_path = "..\\lectures\\input.txt";
    ofstream output(output_path);
    for (int i = 0; i < 2; ++i) {
        int x = 250000;
        output << x << endl;
        for (int ind = 0; ind < x; ++ind) {
            if (output) {
                output << to_string(rand()) << ' ';
            }
        }
        output << endl;
    }
    output.close();
    return 0;
}