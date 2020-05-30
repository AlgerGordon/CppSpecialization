//
// Created by General on 15.05.2020.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;


void ReadFile(const string& path) {
    ifstream input(path);
    if (input) {
        string line;
        while (getline(input,line)) {
            cout << line << endl;
        }
    }
    input.close();
}


int main() {
    string input_path = "input.txt";
    ifstream input(input_path);
    if (input) {
        string line;
        while (getline(input,line)) {
            cout << line << endl;
        }
    }
    input.close();

//    string output_path = "output.txt";
//    ofstream output(output_path);
//    if (output && input) {
//        string line;
//        while (getline(input,line)) {
//            output << line << endl;
//        }
//    }
//    output.close();
//    input.close();
    return 0;
}