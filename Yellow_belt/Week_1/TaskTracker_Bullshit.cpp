//
// Created by General on 02.06.2020.
//

#include <iostream>
#include <map>
#include <tuple>
#include <vector>

using namespace std;

enum class TaskStatus {
    NEW,          // новая
    IN_PROGRESS,  // в разработке
    TESTING,      // на тестировании
    DONE
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;



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
        map<TaskStatus, int> status_to_updated = storage[person];
        TasksInfo upd = {}, not_upd={};
        vector<int> vec{0, 1, 2};
        for(auto ind : vec) {
            auto status = static_cast<TaskStatus>(ind);
            auto next_status = static_cast<TaskStatus>(ind + 1);
            int value = status_to_updated[status];
            task_count_left = max(0, );
        }

        for (auto [status, updated] : status_to_updated) {


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

    tasks.AddNewTask("Ilia");
    for (int i = 0; i < 3; ++i) {
        tasks.AddNewTask("Ivan");
    }
    cout << "Ilia's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
    cout << "Ivan's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

    TasksInfo updated_tasks, untouched_tasks;

    tie(updated_tasks, untouched_tasks) =
            tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);

    tie(updated_tasks, untouched_tasks) =
            tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);


    return 0;
}