#pragma once

#include "queue_base.h"



class Q_protected :protected Queue
{
public:

	void func();
	void copyprot(Queue &q1);
};
