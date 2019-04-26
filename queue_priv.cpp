#include "queue_priv.h"
#include <iostream>

using namespace std;

void Q_private::copypriv(Queue &q1) { Queue::copy(q1); }
void Q_private::func()
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
