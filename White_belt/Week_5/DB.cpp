//
// Created by General on 28.05.2020.
//

// Реализуйте функции и методы классов и при необходимости добавьте свои
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <sstream>
#include <exception>
#include <iomanip>
using namespace std;

class Date {
public:
    Date (int new_year, int new_month, int new_day) {
        year = new_year;
        month = new_month;
        day = new_day;
    }
    int GetYear() const{
        return year;
    }
    int GetMonth() const{
        return month;
    }
    int GetDay() const{
        return day;
    }
private:
    int year;
    int month;
    int day;
};

Date ParseDate(const string& input_date) {
    int new_year, new_month, new_day;
    char c1, c2;
    string buf;
    stringstream stream(input_date);
    stream >> new_year >> c1 >> new_month >> c2 >> new_day;
    if (stream && c1 == '-' && c2 == '-' && !stream.rdbuf()->in_avail()) { // or date_stream.eof();
        if (new_month > 12 || new_month < 1) {
            throw logic_error("Month value is invalid: " + to_string(new_month));
        }
        if (new_day > 31 || new_day < 1) {
            throw logic_error("Day value is invalid: " + to_string(new_day));
        }
        return {new_year, new_month, new_day};
    } else {
        throw logic_error("Wrong date format: " + input_date);
    }
}


bool operator<(const Date& lhs, const Date& rhs){
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()}  <
            vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

ostream& operator<<(ostream& stream, const Date& date) {
    stream << setw(4) << setfill('0') << date.GetYear() <<
           "-" << setw(2) << setfill('0') << date.GetMonth() <<
           "-" << setw(2) << setfill('0') << date.GetDay();
    return stream;
}

class Database {
public:
    void AddEvent(const Date& date, const string& event){
        storage[date].insert(event);
    }
    bool DeleteEvent(const Date& date, const string& event){
        if (!storage.count(date) || !storage[date].count(event)){
            return false;
        }
        storage[date].erase(event);
        return true;
    }
    int  DeleteDate(const Date& date){
        if (!storage.count(date)){
            return 0;
        }
        const int res = storage[date].size();
        storage[date] = {};
        return res;
    }

    set<string> Find(const Date& date) const{
        if (storage.count(date)) {
            return  storage.at(date);
        } else {
            return {};
        }
    }

    void Print() const{
        for (auto const& item_db : storage){
            for (string const& event : item_db.second){
                cout << item_db.first << ' ' << event << endl;
            }
        }
    }

private:
    map<Date, set<string>>  storage;
};


int main() {
    Database db;
    Date new_date = {1,1,1};
    set<string> operations_set = {"Add", "Print", "Del", "Find", ""};
    string command, command_tale, operation_code;
    string input_date;
    string new_event;
    bool is_event_exists;
    stringstream command_stream("");

    try {
        while (getline(cin, command)) {
            // Считайте команды с потока ввода и обработайте каждую.
            if (command.empty()) {
                continue;
            }
            if (command == "Print") {
                db.Print();
            } else {
                command_stream << command << endl;
                getline(command_stream, operation_code, ' ');
                if (operations_set.count(operation_code) == 0) {
                    throw invalid_argument("Unknown command: " + operation_code);
                }
                getline(command_stream, command_tale);
                is_event_exists = command_tale.find(' ') != string::npos;
                command_stream << command_tale << endl;
                if (is_event_exists) {
                    getline(command_stream, input_date, ' ');
                } else {
                    getline(command_stream, input_date);
                }
                new_date = ParseDate(input_date);
                if (is_event_exists) {
                    getline(command_stream, new_event);
                    if (operation_code == "Del") {
                        if (db.DeleteEvent(new_date, new_event)) {
                            cout << "Deleted successfully" << endl;
                        } else {
                            cout << "Event not found" << endl;
                        }
                    } else if (operation_code == "Add") {
                        db.AddEvent(new_date, new_event);
                    }
                } else {
                    if (operation_code == "Del") {
                        cout << "Deleted " << db.DeleteDate(new_date) << " events" << endl;
                    } else if (operation_code == "Find") {
                        for (string const &event : db.Find(new_date)) {
                            cout << event << endl;
                        }
                    }
                }
            }
        }
    } catch (exception& ex) {
        cout << ex.what() << endl;
    }
    return 0;
}