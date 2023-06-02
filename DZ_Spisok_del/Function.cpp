#pragma once
#include "Function.h"




void menu_add_task(List_Task& list_task, int& size)
{
	bool add_another_task = true;
	do
	{
		int chose_add;
		add_task(list_task, size);

		cout << "Хотите добавить ещё одну задачу?" << endl;
		cout << "Если да, то нажмите любую цифру если нет, то нажмите 0 " << endl;
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
	cout << "Введите название задачи " << endl;
	cin.get();
	cin.getline(list_task.tasks[size].title, size_title);
}

void add_priority(List_Task& list_task, const int size)
{
	bool is_not_num = false;
	do
	{
		cout << "Введите приоритет задачи числом. " << endl;
		cout << "Категории задач: " << endl;
		cout << "1 - срочная и важная " << endl;
		cout << "2 - важная не срочная " << endl;
		cout << "3 - срочная не важная " << endl;
		cout << "4 - не важная и не срочная " << endl;
		cin >> list_task.tasks[size].priority;
		if (list_task.tasks[size].priority < 1 && list_task.tasks[size].priority > 4)
		{
			cout << "Введено неверное значение попробуйте ещё раз " << endl;
			is_not_num = true;
		}

	} while (is_not_num);
}

void add_discription(List_Task& list_task, const int size)
{
	cout << "Введите описание задачи " << endl;
	cin.get();
	cin.getline(list_task.tasks[size].description, size_text);
}

void add_year(List_Task& list_task, const int size)
{
	int is_not_right = true;

	cout << "Введите время исполнение задачи " << endl;
	do
	{
		cout << "Введите год числом" << endl;
		cin >> list_task.tasks[size].time.tm_year;

		is_not_right = false;

		if (list_task.tasks[size].time.tm_year < 2023)
		{
			cout << "Вы указали год меньше 2023 или неверно. Введите текущий год или будущий. " << endl;
			is_not_right = true;
		}

	} while (is_not_right);
}

void add_year(List_Task& list_task, const int size, int year)
{
	bool is_not_right = true;
	do
	{
		cout << "Введите год числом" << endl;
		cin >> year;

		is_not_right = false;

		if (year < 2023 || isdigit(year))
		{
			cout << "Вы указали год меньше 2023 или неверно. Введите текущий год или будущий. " << endl;
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
		cout << "Введите месяц числом " << endl;
		cin >> list_task.tasks[size].time.tm_mon;

		is_not_right = false;

		if (list_task.tasks[size].time.tm_mon < 1 || list_task.tasks[size].time.tm_mon > 12 )
		{
			cout << "Вы указали неверный месяц попробуйте ещё раз" << endl;
			is_not_right = true;
		}

	} while (is_not_right);
}

void add_month(List_Task& list_task, const int size, int month)
{
	bool is_not_right = true;

	do
	{
		cout << "Введите месяц числом " << endl;
		cin >> month;

		is_not_right = false;

		if (month < 1 || month > 12)
		{
			cout << "Вы указали неверный месяц попробуйте ещё раз" << endl;
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
			cout << "Введите дату числом от 1 до 31" << endl;
			cin >> list_task.tasks[size].time.tm_mday;
			is_not_right = false;

			if (list_task.tasks[size].time.tm_mday < 1 || list_task.tasks[size].time.tm_mday > 31)
			{
				cout << "Вы ввели неверную дату попробуйте ввыести ещё раз " << endl;
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
				cout << "Введите дату числом от 1 до 29" << endl;
				cin >> list_task.tasks[size].time.tm_mday;

				is_not_right = false;

				if ((list_task.tasks[size].time.tm_mday < 1 || list_task.tasks[size].time.tm_mday > 29))
				{
					cout << "Вы ввели неверную дату попробуйте ввыести ещё раз " << endl;
					is_not_right = true;
				}
			} while (is_not_right);
		}
		else
		{
			do
			{
				cout << "Введите дату числом от 1 до 28" << endl;
				cin >> list_task.tasks[size].time.tm_mday;

				is_not_right = false;

				if ((list_task.tasks[size].time.tm_mday < 1 || list_task.tasks[size].time.tm_mday > 28))
				{
					cout << "Вы ввели неверную дату попробуйте вывести ещё раз " << endl;
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
				cout << "Введите дату числом от 1 до 30" << endl;
				cin >> list_task.tasks[size].time.tm_mday;
				is_not_right = false;
			}
			if (list_task.tasks[size].time.tm_mday < 1 || list_task.tasks[size].time.tm_mday > 30 )
			{
				cout << "Вы ввели неверную дату попробуйте ввыести ещё раз " << endl;
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
			cout << "Введите дату числом от 1 до 31" << endl;
			cin >> day;
			is_not_right = false;

			if (day < 1 || day > 31 )
			{
				cout << "Вы ввели неверную дату попробуйте ввыести ещё раз " << endl;
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
				cout << "Введите дату числом от 1 до 29" << endl;
				cin >> day;

				is_not_right = false;

				if ((day < 1 || day > 29))
				{
					cout << "Вы ввели неверную дату попробуйте ввыести ещё раз " << endl;
					is_not_right = true;
				}
			} while (is_not_right);
		}
		else
		{
			do
			{
				cout << "Введите дату числом от 1 до 28" << endl;
				cin >> day;

				is_not_right = false;

				if ((day < 1 || day > 28) )
				{
					cout << "Вы ввели неверную дату попробуйте вывести ещё раз " << endl;
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
				cout << "Введите дату числом от 1 до 30" << endl;
				cin >> day;
				is_not_right = false;
			}
			if (day < 1 || day > 30 )
			{
				cout << "Вы ввели неверную дату попробуйте ввыести ещё раз " << endl;
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
		cout << "Введите час от 0 до 23 " << endl;
		cin >> list_task.tasks[size].time.tm_hour;

		is_not_right = false;

		if (list_task.tasks[size].time.tm_hour < 0 || list_task.tasks[size].time.tm_hour > 23)
		{
			cout << "Введено неверное число попробуйте ещё раз " << endl;
			is_not_right = true;
		}
	} while (is_not_right);
}

void add_hour(List_Task& list_task, const int size, int hour)
{
	int is_not_right = true;

	do
	{
		cout << "Введите час от 0 до 23 " << endl;
		cin >> hour;

		is_not_right = false;

		if (hour < 0 || hour > 23 )
		{
			cout << "Введено неверное число попробуйте ещё раз " << endl;
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
		cout << "Введите минуты от 0 до 59 " << endl;
		cin >> list_task.tasks[size].time.tm_min;

		is_not_right = false;

		if (list_task.tasks[size].time.tm_min < 0 || list_task.tasks[size].time.tm_min > 59 )
		{
			cout << "Введено неверное число попробуйте ещё раз " << endl;
			is_not_right = true;
		}
	} while (is_not_right);
}

void add_minutes(List_Task& list_task, const int size, int min)
{
	bool is_not_right = true;

	do
	{
		cout << "Введите минуты от 0 до 59 " << endl;
		cin >> min;

		is_not_right = false;

		if (min < 0 || min > 59 )
		{
			cout << "Введено неверное число попробуйте ещё раз " << endl;
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
	cout << "\nМеню отображения списка дел\n";
	cout << "Выберете вариант сортировки списка числом\n";
	cout << "1 - по дням\n";
	cout << "2 - по месяцам\n";
	cout << "3 - по году\n";
	cout << "4 - показать весь список\n";

	int chose;
	int year;
	int month;
	int day;
	cin >> chose;

	//cout << "Выберете вариант сортировки списка указав число\n";

	switch (chose)
	{
	case 1:
		cout << "Укажите дату для просмотра списка дел за конкретный день \n";
		cout << "Укажите год \n";
		cin >> year;
		cout << "Укажите месяц \n";
		cin >> month;
		cout << "Укажите день\n";
		cin >> day;
		print_chose_task(list_task, size, year, month, day);
		break;
	case 2:
		cout << "Укажите дату для просмотра списка дел за конкретный месяц \n";
		cout << "Укажите год \n";
		cin >> year;
		cout << "Укажите месяц \n";
		cin >> month;
		print_chose_task(list_task, size, year, month);
		break;
	case 3:
		cout << "Укажите дату для просмотра списка дел за конкретный год \n";
		cout << "Укажите год \n";
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
		cout << "Сортировать по наивысшему приоритету? Если да то нажмите 1 если по низшему приоритету то любое число \n";
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
		cout << "Задач не найдено ";
	}

}

void print_task(List_Task& list_task, const int idx)
{
	cout << "-------------------------------" << endl;
	cout << "Название " << list_task.tasks[idx].title << " " << endl;
	cout << "Приоритет " << list_task.tasks[idx].priority << " " << endl;
	cout << "Описание " << list_task.tasks[idx].description << " " << endl;
	cout << "Время исполнения задачи " << list_task.tasks[idx].time.tm_mday << "."
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
		cout << "Такая задача не найдена\n";
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
		cout << "Такая задача не найдена\n";
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
		cout << "Такая задача не найдена\n";
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
		cout << "Введено неверное значение " << endl;
		break;
	}
}

int chose_task_for_redax(const int size)
{
	int chose_task;
	bool is_not_correct = false;

	do
	{
		cout << "Выберите задачу для работы указав номер задчаи считая от 0 до " << size - 1 << endl;
		cin >> chose_task;
		if ((chose_task < 0 || chose_task > size) || isdigit(chose_task))
		{
			cout << "Такой задачи нет. Попробуйте выбрать задачу ещё раз ";
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
		cout << "Выберите элемент для дальнейшей работы указав число: " << endl;
		cout << "1 - Название задачи " << endl;
		cout << "2 - Приоритет задачи " << endl;
		cout << "3 - Описание задачи " << endl;
		cout << "4 - Время исполнения задачи " << endl;
		cin >> res;

		is_not_correct = false;

		if ((res <= 0 || res > 4) || isdigit(res))
		{
			cout << "Введено неверное значение попробуйте ещё раз ";
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
		cout << "Задача удалена!\n";
	}
	
	if (size == 0)
	{
		cout << "Задач для удаления нет: ";
	}

}

void menu_finde_task(List_Task& list_task, const int& size)
{
	int find = chose_el_for_redax();
	int res;

	switch (find)
	{
	case 1:
		cout << "Введите точное название задачи для поиска " << endl;
		finde_task_title_and_discript(list_task, size, find);

		break;
	case 2:
		cout << "Введите точное описание задачи для поиска " << endl;
		finde_task_title_and_discript(list_task, size, find);

		break;
	case 3:
		cout << "Введите приоритет задачи для поиска " << endl;
		finde_task_priority(list_task, size);
		break;
	case 4:
		cout << "Выберете по какому критерию времени хотите искать задачу " << endl;
		cout << "1 - по году " << endl;
		cout << "2 - по месяцу " << endl;
		cout << "3 - по дню " << endl;
		cout << "4 - по часу " << endl;
		cout << "5 - по минуте " << endl;
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
			cout << "Такая задача не найдена " << endl;
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
			cout << "Такая задача не найдена " << endl;
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

