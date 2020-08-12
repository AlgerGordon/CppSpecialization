//
// Created by General on 11.08.2020.
//


#pragma once

#include "date.h"

#include <string>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Database {
public:
    void Add(const Date& date, const std::string& event);

    template<typename UnaryPredicate>
    int RemoveIf(UnaryPredicate predicate){
        int nRemoved = 0;
        stack<pair<Date, vector<string>::iterator>> daysToUpdate;
        for (auto& [date, events] : storage) {
            const Date curDate = date;
            auto it = remove_if(events.begin(), events.end(),
                                [curDate, predicate](const string &event) {
                                    return predicate(curDate, event);
                                });
            int newRemoved = distance(it, events.end());
            if (newRemoved > 0) {
                daysToUpdate.push({curDate, it});
            }
            nRemoved += newRemoved;
            // events.erase(it, events.end());
        }

        while (!daysToUpdate.empty()){
            auto item = daysToUpdate.top();
            Date curDate = item.first;
            auto it = item.second;
            storage[curDate].erase(it, storage[curDate].end());
            daysToUpdate.pop();
            if (storage[curDate].empty()) {
                storage.erase(curDate);
                storage_set.erase(curDate);
            } else {
                storage_set[curDate] = {storage[curDate].begin(),
                                        storage[curDate].end()};
            }
        }
        return nRemoved;
    }

    template<typename UnaryPredicate>
    vector<pair<Date, string>> FindIf(UnaryPredicate predicate) const{
        vector<pair<Date, string>> res = {};
        for (auto& [date, events] : storage) {
            const Date curDate = date;
            auto it_begin = events.begin();
            auto it_end = events.end();
            do {
                it_begin = find_if(it_begin, it_end,
                                   [curDate, predicate](const string &event) {
                                       return predicate(curDate, event);
                                   });
                if (it_begin != it_end) {
                    res.emplace_back(make_pair(curDate, *it_begin));
                    ++it_begin;
                }
            } while (it_begin != events.end());
        }
        return res;
    }

    pair<Date, string> Last(const Date& date) const;

    void Print(ostream& stream) const;

private:
    map<Date, vector<string>>  storage;
    map<Date, set<string>> storage_set;
};