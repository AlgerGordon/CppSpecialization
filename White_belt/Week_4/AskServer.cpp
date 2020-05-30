//
// Created by General on 16.05.2020.
//

#include <iostream>
#include <exception>
#include <string>
#include <ctime>
using namespace std;

string AskTimeServer() {
    srand(unsigned(std::time(0)));
    int random_variable = rand();
    if (random_variable % 3 == 0) {
        throw system_error(error_code());
    } else if (random_variable % 3 == 1) {
        throw runtime_error("Runtime error");
    } else {
        return "10:59:40";
    }

}

class TimeServer {
public:
    string GetCurrentTime() {
        try {
            last_fetched_time = AskTimeServer();
        } catch (const system_error& ex) {
        }
        return last_fetched_time;
    }
private:
    string last_fetched_time = "00:00:00";
};

int main() {
    // Меняя реализацию функции AskTimeServer, убедитесь, что это код работает корректно
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}
