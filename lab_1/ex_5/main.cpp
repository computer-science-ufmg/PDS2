#include <iostream>
#include <sstream>
#include <map>
#include "Task.hpp"

using namespace std;

int main(){
  Scheduler *scheduler;
  map<string, Task*> tasks;
  int quantum, total_tasks, id, arrival, duration;
  cin >> quantum >> total_tasks;
  for(int i = 0; i < total_tasks; i++) {
    cin >> id >> arrival >> duration;
    ostringstream oss;
    oss << arrival << ':' << id;
    tasks[oss.str()] = new Task(id, arrival, duration);
  }
  scheduler = new Scheduler(quantum, tasks);
  scheduler->round_robin();
  scheduler->display_result();
  for(map<string, Task*>::iterator it = tasks.begin(); it != tasks.end(); ++it) {
    delete it->second;
  }
  delete scheduler;
  return 0;
}
