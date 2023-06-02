#pragma once
#include "Function.h"




void menu_add_task(List_Task& list_task, int& size)
{
	bool add_another_task = true;
	do
	{
		int chose_add;
		add_task(list_task, size);

		cout << "������ �������� ��� ���� ������?" << endl;
		cout << "���� ��, �� ������� ����� ����� ���� ���, �� ������� 0 " << endl;
		cin >> chose_add;

		if (!chose_add)
			add_another_task = false;
	} while (add_another_task);

}

void add_task(List_Task& list_task, int& size)
{
	List_Task new_task;
	new_task.tasks = new Task[size + 1];

	if (size > 0)
		for (int i = 0; i < size; i++)
			new_task.tasks[i] = list_task.tasks[i];

	add_title(new_task, size);
	add_priority(new_task, size);
	add_discription(new_task, size);
	add_year(new_task, size);
	add_month(new_task, size);
	add_day(new_task, size);
	add_hour(new_task, size);
	add_minutes(new_task, size);

	delete[] list_task.tasks;
	list_task.tasks = new_task.tasks;

	size++;

}

void add_title(List_Task& list_task, const int size)
{
	cout << "������� �������� ������ " << endl;
	cin.get();
	cin.getline(list_task.tasks[size].title, size_title);
}

void add_priority(List_Task& list_task, const int size)
{
	bool is_not_num = false;
	do
	{
		cout << "������� ��������� ������ ������. " << endl;
		cout << "��������� �����: " << endl;
		cout << "1 - ������� � ������ " << endl;
		cout << "2 - ������ �� ������� " << endl;
		cout << "3 - ������� �� ������ " << endl;
		cout << "4 - �� ������ � �� ������� " << endl;
		cin >> list_task.tasks[size].priority;
		if (list_task.tasks[size].priority < 1 && list_task.tasks[size].priority > 4)
		{
			cout << "������� �������� �������� ���������� ��� ��� " << endl;
			is_not_num = true;
		}

	} while (is_not_num);
}

void add_discription(List_Task& list_task, const int size)
{
	cout << "������� �������� ������ " << endl;
	cin.get();
	cin.getline(list_task.tasks[size].description, size_text);
}

void add_year(List_Task& list_task, const int size)
{
	int is_not_right = true;

	cout << "������� ����� ���������� ������ " << endl;
	do
	{
		cout << "������� ��� ������" << endl;
		cin >> list_task.tasks[size].time.tm_year;

		is_not_right = false;

		if (list_task.tasks[size].time.tm_year < 2023)
		{
			cout << "�� ������� ��� ������ 2023 ��� �������. ������� ������� ��� ��� �������. " << endl;
			is_not_right = true;
		}

	} while (is_not_right);
}

void add_year(List_Task& list_task, const int size, int year)
{
	bool is_not_right = true;
	do
	{
		cout << "������� ��� ������" << endl;
		cin >> year;

		is_not_right = false;

		if (year < 2023 || isdigit(year))
		{
			cout << "�� ������� ��� ������ 2023 ��� �������. ������� ������� ��� ��� �������. " << endl;
			is_not_right = true;
		}

	} while (is_not_right);

	for (int i = 0; i < size; i++)
		if (list_task.tasks[i].time.tm_year == year)
			print_task(list_task, i);
}

void add_month(List_Task& list_task, const int size)
{
	bool is_not_right = true;

	do
	{
		cout << "������� ����� ������ " << endl;
		cin >> list_task.tasks[size].time.tm_mon;

		is_not_right = false;

		if (list_task.tasks[size].time.tm_mon < 1 || list_task.tasks[size].time.tm_mon > 12 )
		{
			cout << "�� ������� �������� ����� ���������� ��� ���" << endl;
			is_not_right = true;
		}

	} while (is_not_right);
}

void add_month(List_Task& list_task, const int size, int month)
{
	bool is_not_right = true;

	do
	{
		cout << "������� ����� ������ " << endl;
		cin >> month;

		is_not_right = false;

		if (month < 1 || month > 12)
		{
			cout << "�� ������� �������� ����� ���������� ��� ���" << endl;
			is_not_right = true;
		}

	} while (is_not_right);

	for (int i = 0; i < size; i++)
		if (list_task.tasks[i].time.tm_mon == month)
			print_task(list_task, i);
}

void add_day(List_Task& list_task, const int size)
{
	bool is_not_right = true;

	if (list_task.tasks[size].time.tm_mon == 1 || list_task.tasks[size].time.tm_mon == 3
		|| list_task.tasks[size].time.tm_mon == 5 || list_task.tasks[size].time.tm_mon == 7 || list_task.tasks[size].time.tm_mon == 8
		|| list_task.tasks[size].time.tm_mon == 10 || list_task.tasks[size].time.tm_mon == 12)
	{
		do
		{
			cout << "������� ���� ������ �� 1 �� 31" << endl;
			cin >> list_task.tasks[size].time.tm_mday;
			is_not_right = false;

			if (list_task.tasks[size].time.tm_mday < 1 || list_task.tasks[size].time.tm_mday > 31)
			{
				cout << "�� ����� �������� ���� ���������� ������� ��� ��� " << endl;
				is_not_right = true;
			}

		} while (is_not_right);
	}

	else if (list_task.tasks[size].time.tm_mon == 2)
	{
		if (list_task.tasks[size].time.tm_year % 4 == 0 && list_task.tasks[size].time.tm_year % 100 != 0
			|| list_task.tasks[size].time.tm_year % 400 == 0)
		{
			do
			{
				cout << "������� ���� ������ �� 1 �� 29" << endl;
				cin >> list_task.tasks[size].time.tm_mday;

				is_not_right = false;

				if ((list_task.tasks[size].time.tm_mday < 1 || list_task.tasks[size].time.tm_mday > 29))
				{
					cout << "�� ����� �������� ���� ���������� ������� ��� ��� " << endl;
					is_not_right = true;
				}
			} while (is_not_right);
		}
		else
		{
			do
			{
				cout << "������� ���� ������ �� 1 �� 28" << endl;
				cin >> list_task.tasks[size].time.tm_mday;

				is_not_right = false;

				if ((list_task.tasks[size].time.tm_mday < 1 || list_task.tasks[size].time.tm_mday > 28))
				{
					cout << "�� ����� �������� ���� ���������� ������� ��� ��� " << endl;
					is_not_right = true;
				}
			} while (is_not_right);
		}
	}
	else
	{
		do
		{
			if (list_task.tasks[size].time.tm_mon == 4 || list_task.tasks[size].time.tm_mon == 6
				|| list_task.tasks[size].time.tm_mon == 9 || list_task.tasks[size].time.tm_mon == 11)
			{
				cout << "������� ���� ������ �� 1 �� 30" << endl;
				cin >> list_task.tasks[size].time.tm_mday;
				is_not_right = false;
			}
			if (list_task.tasks[size].time.tm_mday < 1 || list_task.tasks[size].time.tm_mday > 30 )
			{
				cout << "�� ����� �������� ���� ���������� ������� ��� ��� " << endl;
				is_not_right = true;
			}

		} while (is_not_right);
	}
}

void add_day(List_Task& list_task, const int size, int day)
{
	bool is_not_right = true;

	if (list_task.tasks[size].time.tm_mon == 1 || list_task.tasks[size].time.tm_mon == 3
		|| list_task.tasks[size].time.tm_mon == 5 || list_task.tasks[size].time.tm_mon == 7 || list_task.tasks[size].time.tm_mon == 8
		|| list_task.tasks[size].time.tm_mon == 10 || list_task.tasks[size].time.tm_mon == 12)
	{
		do
		{
			cout << "������� ���� ������ �� 1 �� 31" << endl;
			cin >> day;
			is_not_right = false;

			if (day < 1 || day > 31 )
			{
				cout << "�� ����� �������� ���� ���������� ������� ��� ��� " << endl;
				is_not_right = true;
			}

		} while (is_not_right);
	}

	else if (list_task.tasks[size].time.tm_mon == 2)
	{
		if (list_task.tasks[size].time.tm_year % 4 == 0 && list_task.tasks[size].time.tm_year % 100 != 0
			|| list_task.tasks[size].time.tm_year % 400 == 0)
		{
			do
			{
				cout << "������� ���� ������ �� 1 �� 29" << endl;
				cin >> day;

				is_not_right = false;

				if ((day < 1 || day > 29))
				{
					cout << "�� ����� �������� ���� ���������� ������� ��� ��� " << endl;
					is_not_right = true;
				}
			} while (is_not_right);
		}
		else
		{
			do
			{
				cout << "������� ���� ������ �� 1 �� 28" << endl;
				cin >> day;

				is_not_right = false;

				if ((day < 1 || day > 28) )
				{
					cout << "�� ����� �������� ���� ���������� ������� ��� ��� " << endl;
					is_not_right = true;
				}
			} while (is_not_right);
		}
	}
	else
	{
		do
		{
			if (list_task.tasks[size].time.tm_mon == 4 || list_task.tasks[size].time.tm_mon == 6
				|| list_task.tasks[size].time.tm_mon == 9 || list_task.tasks[size].time.tm_mon == 11)
			{
				cout << "������� ���� ������ �� 1 �� 30" << endl;
				cin >> day;
				is_not_right = false;
			}
			if (day < 1 || day > 30 )
			{
				cout << "�� ����� �������� ���� ���������� ������� ��� ��� " << endl;
				is_not_right = true;
			}

		} while (is_not_right);
	}

	for (int i = 0; i < size; i++)
		if (list_task.tasks[i].time.tm_mday == day)
			print_task(list_task, i);
}

void add_hour(List_Task& list_task, const int size)
{
	int is_not_right = true;

	do
	{
		cout << "������� ��� �� 0 �� 23 " << endl;
		cin >> list_task.tasks[size].time.tm_hour;

		is_not_right = false;

		if (list_task.tasks[size].time.tm_hour < 0 || list_task.tasks[size].time.tm_hour > 23)
		{
			cout << "������� �������� ����� ���������� ��� ��� " << endl;
			is_not_right = true;
		}
	} while (is_not_right);
}

void add_hour(List_Task& list_task, const int size, int hour)
{
	int is_not_right = true;

	do
	{
		cout << "������� ��� �� 0 �� 23 " << endl;
		cin >> hour;

		is_not_right = false;

		if (hour < 0 || hour > 23 )
		{
			cout << "������� �������� ����� ���������� ��� ��� " << endl;
			is_not_right = true;
		}
	} while (is_not_right);

	for (int i = 0; i < size; i++)
		if (list_task.tasks[i].time.tm_hour == hour)
			print_task(list_task, i);
}

void add_minutes(List_Task& list_task, const int size)
{
	bool is_not_right = true;

	do
	{
		cout << "������� ������ �� 0 �� 59 " << endl;
		cin >> list_task.tasks[size].time.tm_min;

		is_not_right = false;

		if (list_task.tasks[size].time.tm_min < 0 || list_task.tasks[size].time.tm_min > 59 )
		{
			cout << "������� �������� ����� ���������� ��� ��� " << endl;
			is_not_right = true;
		}
	} while (is_not_right);
}

void add_minutes(List_Task& list_task, const int size, int min)
{
	bool is_not_right = true;

	do
	{
		cout << "������� ������ �� 0 �� 59 " << endl;
		cin >> min;

		is_not_right = false;

		if (min < 0 || min > 59 )
		{
			cout << "������� �������� ����� ���������� ��� ��� " << endl;
			is_not_right = true;
		}
	} while (is_not_right);

	for (int i = 0; i < size; i++)
		if (list_task.tasks[i].time.tm_min == min)
			print_task(list_task, i);
}

void red_time(List_Task& list_task, const int size)
{
	add_year(list_task, size);
	add_month(list_task, size);
	add_day(list_task, size);
	add_hour(list_task, size);
	add_minutes(list_task, size);
}

void sort_print_list(List_Task& list_task, const int size)
{
	cout << "\n���� ����������� ������ ���\n";
	cout << "�������� ������� ���������� ������ ������\n";
	cout << "1 - �� ����\n";
	cout << "2 - �� �������\n";
	cout << "3 - �� ����\n";
	cout << "4 - �������� ���� ������\n";

	int chose;
	int year;
	int month;
	int day;
	cin >> chose;

	//cout << "�������� ������� ���������� ������ ������ �����\n";

	switch (chose)
	{
	case 1:
		cout << "������� ���� ��� ��������� ������ ��� �� ���������� ���� \n";
		cout << "������� ��� \n";
		cin >> year;
		cout << "������� ����� \n";
		cin >> month;
		cout << "������� ����\n";
		cin >> day;
		print_chose_task(list_task, size, year, month, day);
		break;
	case 2:
		cout << "������� ���� ��� ��������� ������ ��� �� ���������� ����� \n";
		cout << "������� ��� \n";
		cin >> year;
		cout << "������� ����� \n";
		cin >> month;
		print_chose_task(list_task, size, year, month);
		break;
	case 3:
		cout << "������� ���� ��� ��������� ������ ��� �� ���������� ��� \n";
		cout << "������� ��� \n";
		cin >> year;
		print_chose_task(list_task, size, year);
		break;
	case 4:
		print_list_task(list_task, size);
		break;
	default:
		break;
	}
}

void print_list_task(List_Task& list_task, const int size)
{
	if (size != 0)
	{
		int chose;
		cout << "����������� �� ���������� ����������? ���� �� �� ������� 1 ���� �� ������� ���������� �� ����� ����� \n";
		cin >> chose;

		if (chose == 1)
		{
			int j = 1;
			do
			{
				for (int i = 0; i < size; i++)
					if (list_task.tasks[i].priority == j)
						print_task(list_task, i);
				j++;

			} while (j < 5);
		}
		else
		{
			int j = 4;
			do
			{
				for (int i = 0; i < size; i++)
					if (list_task.tasks[i].priority == j)
						print_task(list_task, i);
				j--;
			} while (j > -1);
		}
	}
	else
	{
		cout << "����� �� ������� ";
	}

}

void print_task(List_Task& list_task, const int idx)
{
	cout << "-------------------------------" << endl;
	cout << "�������� " << list_task.tasks[idx].title << " " << endl;
	cout << "��������� " << list_task.tasks[idx].priority << " " << endl;
	cout << "�������� " << list_task.tasks[idx].description << " " << endl;
	cout << "����� ���������� ������ " << list_task.tasks[idx].time.tm_mday << "."
		<< list_task.tasks[idx].time.tm_mon << "." << list_task.tasks[idx].time.tm_year << " "
		<< list_task.tasks[idx].time.tm_hour << ":" << list_task.tasks[idx].time.tm_min << " " << endl;
	cout << "-------------------------------" << endl;
}

void print_chose_task(List_Task& list_task, const int size, int year, int month, int day)
{
	bool isNotFinde = true;

	for (int i = 0; i < size; i++)
	{
		if (list_task.tasks[i].time.tm_year == year && list_task.tasks[i].time.tm_mon == month
			&& list_task.tasks[i].time.tm_mday == day)
		{
			print_task(list_task, i);
			isNotFinde = false;
		}


	}
	if (isNotFinde)
	{
		cout << "����� ������ �� �������\n";
	}
}

void print_chose_task(List_Task& list_task, const int size, int year, int month)
{
	bool isNotFinde = true;

	for (int i = 0; i < size; i++)
	{
		if (list_task.tasks[i].time.tm_year == year && list_task.tasks[i].time.tm_mon == month)
		{
			print_task(list_task, i);
			isNotFinde = false;
		}

	}

	if (isNotFinde)
	{
		cout << "����� ������ �� �������\n";
	}
}

void print_chose_task(List_Task& list_task, const int size, int year)
{
	bool isNotFinde = true;

	for (int i = 0; i < size; i++)
	{
		if (list_task.tasks[i].time.tm_year == year)
		{
			print_task(list_task, i);
			isNotFinde = false;
		}
	}

	if (isNotFinde)
	{
		cout << "����� ������ �� �������\n";
	}
}

void menu_redax_task(List_Task& list_task, int& size)
{
	int chose_task = chose_task_for_redax(size);

	switch (chose_el_for_redax())
	{
	case 1:
		add_title(list_task, chose_task);
		break;
	case 2:
		add_priority(list_task, chose_task);
		break;
	case 3:
		add_discription(list_task, chose_task);
		break;
	case 4:
		red_time(list_task, chose_task);
		break;
	default:
		cout << "������� �������� �������� " << endl;
		break;
	}
}

int chose_task_for_redax(const int size)
{
	int chose_task;
	bool is_not_correct = false;

	do
	{
		cout << "�������� ������ ��� ������ ������ ����� ������ ������ �� 0 �� " << size - 1 << endl;
		cin >> chose_task;
		if ((chose_task < 0 || chose_task > size) || isdigit(chose_task))
		{
			cout << "����� ������ ���. ���������� ������� ������ ��� ��� ";
			is_not_correct = true;
		}
	} while (is_not_correct);
	return chose_task;
}

int chose_el_for_redax()
{
	bool is_not_correct = false;
	int res;

	do
	{
		cout << "�������� ������� ��� ���������� ������ ������ �����: " << endl;
		cout << "1 - �������� ������ " << endl;
		cout << "2 - ��������� ������ " << endl;
		cout << "3 - �������� ������ " << endl;
		cout << "4 - ����� ���������� ������ " << endl;
		cin >> res;

		is_not_correct = false;

		if ((res <= 0 || res > 4) || isdigit(res))
		{
			cout << "������� �������� �������� ���������� ��� ��� ";
			is_not_correct = true;
		}
	} while (is_not_correct);

	return res;
}

void delete_task(List_Task& list_task, int& size, int idx)
{
	List_Task new_task;
	new_task.tasks = new Task[size - 1];

	if (size > 0)
	{
		for (int i = 0; i < idx; i++)
			new_task.tasks[i] = list_task.tasks[i];

		for (int i = idx + 1; i < size; i++)
			new_task.tasks[i - 1] = list_task.tasks[i];

		delete[] list_task.tasks;
		list_task.tasks = new_task.tasks;

		size--;
		cout << "������ �������!\n";
	}
	
	if (size == 0)
	{
		cout << "����� ��� �������� ���: ";
	}

}

void menu_finde_task(List_Task& list_task, const int& size)
{
	int find = chose_el_for_redax();
	int res;

	switch (find)
	{
	case 1:
		cout << "������� ������ �������� ������ ��� ������ " << endl;
		finde_task_title_and_discript(list_task, size, find);

		break;
	case 2:
		cout << "������� ������ �������� ������ ��� ������ " << endl;
		finde_task_title_and_discript(list_task, size, find);

		break;
	case 3:
		cout << "������� ��������� ������ ��� ������ " << endl;
		finde_task_priority(list_task, size);
		break;
	case 4:
		cout << "�������� �� ������ �������� ������� ������ ������ ������ " << endl;
		cout << "1 - �� ���� " << endl;
		cout << "2 - �� ������ " << endl;
		cout << "3 - �� ��� " << endl;
		cout << "4 - �� ���� " << endl;
		cout << "5 - �� ������ " << endl;
		cin >> res;
		finde_task_time(list_task, size, res);

		break;
	default:
		break;
	}
}

void finde_task_title_and_discript(List_Task& list_task, const int& size, int chose)
{
	bool flag = false;

	if (chose == 1)
	{
		char buff[size_title];
		cin.get();
		cin.getline(buff, size_title);

		for (int i = 0; i < size; i++)
			if (strcmp(list_task.tasks[i].title, buff) == 0)
			{
				print_task(list_task, i);
				flag = true;
			}

		if (flag == false)
			cout << "����� ������ �� ������� " << endl;
	}
	if (chose == 2)
	{
		char buff[size_text];
		cin.get();
		cin.getline(buff, size_text);

		for (int i = 0; i < size; i++)
			if (strcmp(list_task.tasks[i].description, buff))
			{
				print_task(list_task, i);
				flag = true;
			}

		if (flag == false)
			cout << "����� ������ �� ������� " << endl;
	}


}

void finde_task_priority(List_Task& list_task, const int& size)
{
	int priority;
	cin >> priority;

	for (int i = 0; i < size; i++)
		if (list_task.tasks[i].priority == priority)
			print_task(list_task, i);

}

void finde_task_time(List_Task& list_task, const int& size, int chose)
{
	switch (chose)
	{
	case 1:
		add_year(list_task, size, chose);
		break;
	case 2:
		add_month(list_task, size, chose);
		break;
	case 3:
		add_day(list_task, size, chose);
		break;
	case 4:
		add_hour(list_task, size, chose);
		break;
	case 5:
		add_minutes(list_task, size, chose);
		break;
	default:
		break;
	}

}

