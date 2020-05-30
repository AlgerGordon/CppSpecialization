//
// Created by General on 15.05.2020.
//

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {

    ifstream input("C:\\Users\\General\\CLionProjects\\Coursera\\White_belt\\Week_4\\input.txt");
    int n, m, value, width = 10;
    input >> n >> m;
    if (input) {
        for (int k = 0; k < n; ++k) {
            for (int l = 0; l < m; ++l) {
                input >> value;
                input.ignore(1);
                cout << setw(width) << value;
                if ( l != (m -1)) {
                    cout << " ";
                }
            }
            if ( k != (n -1)) {
                cout << endl;
            }
        }

    }
    return 0;
}
