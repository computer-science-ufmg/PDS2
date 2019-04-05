#include <iostream>
#include <vector>
#include "Task.hpp"

using namespace std;

int main(){
  Scheduler *scheduler;
  vector<Task*> tasks;
  int quantum, total_tasks, id, arrival, duration;
  cin >> quantum >> total_tasks;
  for(int i = 0; i < total_tasks; i++) {
    cin >> id >> arrival >> duration;
    tasks.push_back(new Task(id, arrival, duration));
  }
  scheduler = new Scheduler(quantum, tasks);
  scheduler->round_robin();
  scheduler->display_result();
  delete scheduler;
  return 0;
}
