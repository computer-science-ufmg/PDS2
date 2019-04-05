#ifndef TASK_H
#define TASK_H

#include <list>
#include <vector>
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
	vector<Task*> tasks;

	Scheduler(int quantum, const vector<Task*> &tasks);
	~Scheduler();
	void check_incoming_tasks();
	void round_robin();
	bool tasks_unfinished();
	void display_result();
	static bool sort_by_arrival(Task* a, Task* b);
	static bool sort_by_id(Task* a, Task* b);
};

#endif
