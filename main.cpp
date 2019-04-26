#include <iostream>
#include "queue_base.h" 
#include "queue_priv.h"
#include "queue_prot.h"
#include "queue_publ.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	Queue q1;
	Queue copy;
	Queue res;
	int choise;
	bool exit = false;
	do
	{
		system("CLS");
		cout << "1) Добавить элемент в очередь" << endl;
		cout << "2) Извлечь элемент из очереди" << endl;
		cout << "3) Вывести очередь на экран" << endl;
		cout << "4) Подсчет суммы четных элементов" << endl;
		cout << "5) Скопировать очередь" << endl;
		cout << "6) Слияние копии и оригиналом" << endl;
		cout << "7) Выход из программы" << endl;
		cout << "Введите номер операции: ";
		cin >> choise;
		switch (choise)
		{
		case 1:
		{
			int val;
			cout << "Введите значение нового элемента: ";
			cin >> val;
			q1.push(val);
			exit = false; 
			break; 
		}
		case 2:
		{
			if (q1.getVar() == 0)
			{
				cout << "Очередь пуста!!!" << endl;
				system("pause");
			}
			else
			{
				q1.pop();
			}
			exit = false;
			break;
		}
		case 3:
		{
			if (q1.getVar() == 0) 			{
				cout << "Очередь пуста!!!" << endl;
				system("pause");
			}
			else
			{
				q1.pin();
			}
			exit = false;
			break;
		}
		case 4:
		{
			if (q1.getVar() == 0)
			{
				cout << "Очередь пуста!!!" << endl;
				system("pause");
			}
			else
			{
				cout << "Выберите модификатор наследования" << endl;
				cout << "1) private" << endl;
				cout << "2) protected" << endl;
				cout << "3) public" << endl;
				cout << "Ваш выбор: ";
				cin >> choise;
				switch (choise)
				{
				case 1:
				{
					Q_private q_p1;
					q_p1.copypriv(q1);
					q_p1.func();
					break;
				}
				case 2:
				{
					Q_protected q_p2;
					q_p2.copyprot(q1);
					q_p2.func();
					break;
				}
				case 3:
				{
					Q_public q_p3;
					q_p3.copy(q1);
					q_p3.func();
					break;
				}
				}
			}
			exit = false;
			break;
		}
		case 5:
		{
			if (q1.getVar() == 0)
			{
				cout << "Очередь пуста!!!" << endl;
				system("pause");
			}
			else
			{
				copy.copy(q1);
				copy.pin();
			}
			exit = false;
			break;
		}
		case 6:
		{
			if (q1.getVar() == 0 && copy.getVar() == 0)
			{
				cout << "Очереди пусты!!!" << endl;
				system("pause");
			}
			else
			{
				q1.merge(res, copy);
			}
			exit = false;
			break;
		}
		case 7:
		{
			exit = true;
			break;
		}
		default:
		{
			cout << "Введите корректный номер операции!" << endl;
			system("pasue");
			break;
		}
		}
	} while (exit == false); 
	return 0;
}
