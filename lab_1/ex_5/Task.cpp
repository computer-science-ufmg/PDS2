#include "Task.hpp"

using namespace std;

Task::Task(int id, int arrival, int duration){
  this->id = id;
  this->arrival = arrival;
  this->duration = duration;
  this->in_queue = false;
}

void Task::print(){
  cout << "Task " << this->id << ", Duration: [" << this->arrival << ", " << this->end << ']' << endl;
}

Scheduler::Scheduler(int quantum, const map<string, Task*> &tasks){
  this->quantum = quantum;
  this->tasks = tasks;
  this->total_tasks = this->tasks.size();
  this->total_time = 0;
}

void Scheduler::check_incoming_tasks(){
  map<string, Task*>::iterator it;
  for (it = this->tasks.begin(); it != this->tasks.end(); ++it) {
    Task *task = it->second;
    if (!task->in_queue && task->arrival <= this->total_time && task->duration > 0) {
      // cout << "Task " << task->id << " arrived at time " << this->total_time << endl;
      this->scheduler_queue.push_back(task);
      task->in_queue = true;
    }
  }
}

void Scheduler::round_robin(){
  this->check_incoming_tasks();
  for (list<Task*>::iterator it = this->scheduler_queue.begin(); it != this->scheduler_queue.end(); ++it, this->scheduler_queue.pop_front()) {
    Task *task = *it;
    if(task->duration > this->quantum){
      task->duration -= this->quantum;
      this->total_time += this->quantum;
      // cout << "Task " << task->id << " ran for " << this->quantum << " stoping at " << this->total_time << ", " << task->duration << " remaining" << endl;
      this->check_incoming_tasks();
      this->scheduler_queue.push_back(task);
    }
    else{
      this->total_time += task->duration;
      // cout << "Task " << task->id << " ran for " << this->quantum << " and finished at " << this->total_time << endl;
      task->duration = 0;
      task->in_queue = false;
      task->end = this->total_time;
      this->check_incoming_tasks();
    }
  }
  if(this->tasks_unfinished()){
    this->total_time += this->quantum;
    this->round_robin();
  }
}

bool Scheduler::tasks_unfinished(){
  for (map<string, Task*>::iterator it = this->tasks.begin(); it != this->tasks.end(); ++it) {
    Task *task = it->second;
    if(task->duration > 0) return true;
  }
  return false;
}

void Scheduler::display_result(){
  map<string, Task*> ordered_tasks;
  for (map<string, Task*>::iterator it = this->tasks.begin(); it != this->tasks.end(); ++it) {
    ostringstream oss;
    oss << it->second->id;
    ordered_tasks[oss.str()] = it->second;
  }
  for (map<string, Task*>::iterator it = ordered_tasks.begin(); it != ordered_tasks.end(); ++it) {
    Task *task = it->second;
    task->print();
  }
}
