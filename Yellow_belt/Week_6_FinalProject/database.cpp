//
// Created by General on 11.08.2020.
//



#include "database.h"
#include "date.h"

using namespace std;

void Database::Add(const Date& date, const string& event) {
    if (storage_set.count(date) == 0) {
    } else if (storage_set[date].count(event) != 0){
        return;
    }
    storage_set[date].insert(event);
    dateToLastEvent[date] = event;
    storage[date].push_back(event);
}

pair<Date, string> Database::Last(const Date& date) const{
    auto it = storage.upper_bound(date);
    if (it == storage.begin()) {
        throw std::invalid_argument("No entries");
    }
    --it;
    return {it->first, it->second.back()};
}


void Database::Print(ostream& stream) const{
    for (auto const& item_db : storage){
        for (string const& event : item_db.second){
            stream << item_db.first << ' ' << event << std::endl;
        }
    }
}

