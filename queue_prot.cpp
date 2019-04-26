#include "queue_prot.h"
#include <iostream>

using namespace std;

void Q_protected::copyprot(Queue &q1) { Queue::copy(q1); }

// всё как в private

void Q_protected::func()
{
	Data *tmp = getTail();
	int var = getVar();
	int res = 0;
	if (var % 2 != 0 && var > 1)
		tmp = tmp->prev;
	var = (var / 2) - 1;
	while (var > 0)
	{
		res += tmp->value;
		tmp = tmp->prev;
		tmp = tmp->prev;
		var--;
	}
	res += tmp->value;
	cout << "Сумма всех четных элементов res = " << res << endl;
	system("pause");
}