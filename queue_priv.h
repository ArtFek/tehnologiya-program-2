#pragma once

#include "queue_base.h"

class Q_private :private Queue
{
public:
	void func(); 
	void copypriv(Queue &q1);
};
