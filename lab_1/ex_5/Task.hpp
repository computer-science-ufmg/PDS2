#ifndef TASK_H
#define TASK_H

#include <list>
#include <map>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

struct Task{
	int id;
	int arrival;
	int duration;
	int end;
	bool in_queue;

	Task(int id, int arrival, int duration);
	void print();
};

struct Scheduler{
	int quantum;
	int total_tasks;
	int total_time;
	list<Task*> scheduler_queue;
	map<string, Task*> tasks;

	Scheduler(int quantum, const map<string, Task*> &tasks);
	void check_incoming_tasks();
	void round_robin();
	bool tasks_unfinished();
	void display_result();
};

#endif
