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

Scheduler::Scheduler(int quantum, const vector<Task*> &tasks){
  this->quantum = quantum;
  this->tasks = tasks;
  sort(this->tasks.begin(), this->tasks.end(), this->sort_by_arrival);
  this->total_tasks = this->tasks.size();
  this->total_time = 0;
}

Scheduler::~Scheduler(){
  for(vector<Task*>::iterator it = this->tasks.begin(); it != this->tasks.end(); ++it) {
    Task* task = *it;
    delete task;
  }
}

void Scheduler::check_incoming_tasks(){
  for (vector<Task*>::iterator it = this->tasks.begin(); it != this->tasks.end(); ++it) {
    Task *task = *it;
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
    this->total_time++;
    this->round_robin();
  }
}

bool Scheduler::tasks_unfinished(){
  for (vector<Task*>::iterator it = this->tasks.begin(); it != this->tasks.end(); ++it) {
    Task *task = *it;
    if(task->duration > 0) return true;
  }
  return false;
}

void Scheduler::display_result(){
  sort(this->tasks.begin(), this->tasks.end(), this->sort_by_id);
  for (vector<Task*>::iterator it = this->tasks.begin(); it != this->tasks.end(); ++it) {
    Task *task = *it;
    task->print();
  }
}

bool Scheduler::sort_by_arrival(Task* a, Task* b){
  if(a->arrival == b->arrival){
    return a->id < b->id;
  }
  else {
    return a->arrival < b->arrival;
  }
}

bool Scheduler::sort_by_id(Task* a, Task* b){
  return a->id < b->id;
}
