//
// Created by General on 02.06.2020.
//

#include <iostream>
#include <map>
#include <tuple>

using namespace std;

//enum class TaskStatus {
//    NEW,          // новая
//    IN_PROGRESS,  // в разработке
//    TESTING,      // на тестировании
//    DONE
//};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
//using TasksInfo = map<TaskStatus, int>;



class TeamTasks {
public:
    // Получить статистику по статусам задач конкретного разработчика
    const TasksInfo& GetPersonTasksInfo(const string& person) const{
        return storage.at(person);
    }

    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const string& person){
        if (storage[person].count(TaskStatus::NEW) == 0) {
            storage[person][TaskStatus::NEW] = 1;
        } else {
            storage[person][TaskStatus::NEW] += 1;
        }
    }

    // Обновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(
            const string& person, int task_count){
        if (storage.count(person) == 0) {
            return {{},{}};
        }
        int task_count_left = task_count, tmp_tasks_left;
        map<TaskStatus, int> status_to_updated;
        TasksInfo upd = {}, not_upd={};
        for (auto [status, value] : storage[person]) {
            if(status != TaskStatus::DONE) {
                status_to_updated[status] = min(task_count_left, value);
                tmp_tasks_left = max(value - task_count_left, 0);
                if (tmp_tasks_left > 0) {
                    not_upd[status] = tmp_tasks_left;
                }
                task_count_left = max(0, task_count_left - value);
            }
        }
        for (auto [status, updated] : status_to_updated) {
            storage[person][status] -= updated;
            if (storage[person][status] == 0) {
                storage[person].erase(status);
            }
            auto next_status = static_cast<TaskStatus>(static_cast<int>(status) + 1);
            if (storage[person].count(next_status) == 0) {
                storage[person][next_status] = 0;
            }
            storage[person][next_status] += updated;
            if (updated > 0) {
                upd[next_status] = updated;
            }
        }
        return tie(upd, not_upd);
    }
private:
    map<string, TasksInfo> storage;
};

void PrintTasksInfo(TasksInfo tasks_info) {
    cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
         ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
         ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
         ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main() {

    TeamTasks tasks;

    tasks.AddNewTask("test");
    tasks.AddNewTask("test");

    tasks.PerformPersonTasks("test",1);
    tasks.PerformPersonTasks("test",2);
    tasks.AddNewTask("test");
    PrintTasksInfo(tasks.GetPersonTasksInfo("test"));

    tasks.PerformPersonTasks("test",3);

    PrintTasksInfo(tasks.GetPersonTasksInfo("test"));


    return 0;
}