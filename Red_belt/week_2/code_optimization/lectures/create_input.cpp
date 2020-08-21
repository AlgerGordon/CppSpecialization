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

    // This path start in an appropriate cmake-debug-build directory
    // Therefore I write absolute path or just a name

//    string output_path = "measure_input.txt";
//    cout << output_path << endl;
//    ofstream output(output_path);
//    for (int i = 0; i < 2; ++i) {
//        int x = 250000;
//        output << x << endl;
//        for (int ind = 0; ind < x; ++ind) {
//            if (output) {
//                output << to_string(rand()) << ' ';
//            }
//        }
//        output << endl;
//    }
//    output.close();

    string output_path = "..\\effective_iostream\\io_input.txt";
    cout << output_path << endl;
    ofstream output(output_path);
    for (int i = 0; i < 250000; ++i) {
        output << to_string(rand()) << endl;
    }
    output.close();
    return 0;
}