#pragma once

#include "data.h"

class Queue
{
	int var;
	Data *tail;
public:
	Queue();
	~Queue();

	void push(int val);
	void pop();
	void pin();
	void copy(Queue &q1);
	void merge(Queue &res, Queue &copy);
	int getVar();
	Data *getTail(); 
}; 
