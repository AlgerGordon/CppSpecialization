//
// Created by General on 13.05.2020.
//

#include <iostream>
using namespace std;

class Incognizable {
public:
    Incognizable(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }
private:
    int x, y;
};

//struct Incognizable {
//    int x = 0;
//    int y = 0;
//};

int main() {
    Incognizable a;
    Incognizable b = {};
    Incognizable c = {0};
    Incognizable d = {0, 1};
    return 0;
}