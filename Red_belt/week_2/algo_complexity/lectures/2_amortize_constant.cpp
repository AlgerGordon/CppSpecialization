//
// Created by General on 21.08.2020.
//


#include <iostream>
#include <cstdint>
#include <queue>

using namespace std;

class EventManager {
public:
    void Add(uint64_t time){ // amortized O(1)
        Adjust(time);
        events.push(time); // O(1)
    }
    int Count(uint64_t time){   //  amortized O(1)
        Adjust(time);
        return events.size(); // O(1)
    }
private:
    queue<uint64_t> events;

    void Adjust(uint64_t time){ // amortized O(1)
        while (!events.empty() && events.front() <= (time - 300)){ //O(Q)
            events.pop();   // O(1)
        }
    }
};

int main() {

    return 0;
}