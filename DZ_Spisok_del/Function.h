#pragma once
#include <iostream>
#include <string.h>
#include <ctime>
#include <windows.h>

using namespace std;

const int size_title = 100;
const int size_text = 250;

// структура задачи
struct Tm
{
	int tm_year = 0;
	int tm_mon = 0;
	int tm_mday = 0;
	int tm_hour = 0;
	int tm_min = 0;
};

struct Task
{
	char title[size_title]{};
	int priority = 4;
	char description[size_text]{};
	Tm time;
};

struct List_Task
{
	Task* tasks;
};

void menu_add_task(List_Task& list_task, int& size);
// создание задачи
void add_task(List_Task& list_task, int& size);
// добавление элементов задачи
void add_title(List_Task& list_task, const int size);
void add_priority(List_Task& list_task, const int size);
void add_discription(List_Task& list_task, const int size);
void add_year(List_Task& list_task, const int size);
void add_year(List_Task& list_task, const int size, int year);
void add_month(List_Task& list_task, const int size);
void add_month(List_Task& list_task, const int size, int month);
void add_day(List_Task& list_task, const int size);
void add_day(List_Task& list_task, const int size, int day);
void add_hour(List_Task& list_task, const int size);
void add_hour(List_Task& list_task, const int size, int hour);
void add_minutes(List_Task& list_task, const int size);
void add_minutes(List_Task& list_task, const int size, int min);
// редактирование времени
void red_time(List_Task& list_task, const int size);
//
void sort_print_list(List_Task& list_task, const int size);
// печать списка
void print_list_task(List_Task& list_task, const int size);
// печать задачи
void print_task(List_Task& list_task, const int idx);
// печать задачи по конкретной дате.
void print_chose_task(List_Task& list_task, const int size, int year, int month, int day);
//печать задачи по конкретной дате.
void print_chose_task(List_Task& list_task, const int size, int year, int month);
//печать задачи по конкретной дате.
void print_chose_task(List_Task& list_task, const int size, int year);
// редактирование задачи
void menu_redax_task(List_Task& list_task, int& size);
// выбор задачи
int chose_task_for_redax(const int size);
// выбор элемента для редактиврования
int chose_el_for_redax();
//Удаление дела
void delete_task(List_Task& list_task, int& size, int idx);
//меню поиск дела
void menu_finde_task(List_Task& list_task, const int& size);
//поиск дела по названию
void finde_task_title_and_discript(List_Task& list_task, const int& size, int chose);
// поиск дела по приоритету 
void finde_task_priority(List_Task& list_task, const int& size);
// поиск дела по времени
void finde_task_time(List_Task& list_task, const int& size, int chose);