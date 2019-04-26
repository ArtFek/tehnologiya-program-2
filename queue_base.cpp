#include "queue_base.h"
#include <iostream>

using namespace std;

Data *Queue::getTail() { return tail; }
int Queue::getVar() { return var; }

Queue::Queue()
{
	tail = NULL; 
	var = 0;
}

Queue::~Queue()
{
	Data *tmp;
	for (int i = 0; i < var; i++)
	{
		tmp = tail->prev;
		delete tail;
		tail = tmp;
	}
}


void Queue::push(int val)
{
	Data *tmp = new Data;
	tmp->prev = tail;
	tmp->value = val;
	tail = tmp;
	var++;
}

void Queue::pop()
{
	Data *tmp = new Data; þ
	tmp = tail;
	for (int i = 1; i < var; i++)
		tmp = tmp->prev;
	delete tmp;
	var--;
}

void Queue::pin()
{
	Data *tmp = tail;
	int *mass = new int[var];
	int i = var - 1;
	while (i > 0)
	{
		mass[i] = tmp->value;
		tmp = tmp->prev;
		i--;
	} 
	mass[i] = tmp->value;
	for (; i < var; i++)
		cout << mass[i] << " ";
	delete[] mass;
	cout << endl;
	system("pause");
}

void Queue::copy(Queue &q1)
{
	Data *tmp = q1.tail;
	int *mass = new int[q1.var];
	int i = var;
	while (i > 0) 
	{
		this->pop();
		i--;
	}
	i = q1.var - 1;
	while (i > 0)
	{
		mass[i] = tmp->value;
		tmp = tmp->prev;
		i--;
	}
	mass[i] = tmp->value;
	for (; i < q1.var; i++) 
		this->push(mass[i]);
	delete[] mass;
}

void Queue::merge(Queue &res, Queue &copy)
{
	int *mass_q1 = new int[var];
	int *mass_copy = new int[copy.var];
	Data *tmp_q = tail;
	Data *tmp_copy = copy.tail;
	int i1 = res.var;
	int i2 = copy.var - 1;
	while (i1 > 0)
	{
		res.pop();
		i1--;
	}
	i1 = var - 1;
	while (i1 > 0)
	{
		mass_q1[i1] = tmp_q->value;
		tmp_q = tmp_q->prev;
		i1--;
	} 
	mass_q1[i1] = tmp_q->value;
	while (i2 > 0)
	{
		mass_copy[i2] = tmp_copy->value;
		tmp_copy = tmp_copy->prev;
		i2--;
	}
	mass_copy[i2] = tmp_copy->value;
	for (; i1 < var; i1++)
		res.push(mass_q1[i1]);
	for (; i2 < copy.var; i2++)
		res.push(mass_copy[i2]);
	delete[] mass_copy;
	delete[] mass_q1;
	res.pin(); 
}

