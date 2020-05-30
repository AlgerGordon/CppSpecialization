//
// Created by General on 10.05.2020.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {
    int Q, day, month = 0, new_month_lenght;
    string operation_code, cur_task;
    const vector<int> MONTH_LENGTHS = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const int MONTH_COUNT = MONTH_LENGTHS.size();
    vector<vector<string>> monthly_tasks(MONTH_LENGTHS[month]), dump_output;


    cin >> Q;
    for (int com_ind = 0; com_ind < Q; ++com_ind) {
        cin >> operation_code;
        if (operation_code == "NEXT") {
            month = (month + 1) % MONTH_COUNT;
            new_month_lenght = MONTH_LENGTHS[month];
            for (int tmp_day = new_month_lenght; tmp_day < monthly_tasks.size(); ++tmp_day) {
                monthly_tasks[new_month_lenght - 1].insert(end(monthly_tasks[new_month_lenght - 1]), \
                                                        begin(monthly_tasks[tmp_day]), end(monthly_tasks[tmp_day]));
            }
            monthly_tasks.resize(new_month_lenght);
        } else {
            cin >> day;
            day -= 1;
            if (operation_code == "DUMP") {
                dump_output.push_back(monthly_tasks[day]);
            } else if (operation_code == "ADD") {
                cin >> cur_task;
                monthly_tasks[day].push_back(cur_task);
            }
        }
    }

    for (auto& cur_dump : dump_output){
        cout << cur_dump.size();
        for (auto& out_task : cur_dump) {
            cout << " " << out_task;
        }
        cout << endl;
    }
    return 0;
}