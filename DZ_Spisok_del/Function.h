#pragma once
#include <iostream>
#include <string.h>
#include <ctime>
#include <windows.h>

using namespace std;

const int size_title = 100;
const int size_text = 250;

// ��������� ������
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
// �������� ������
void add_task(List_Task& list_task, int& size);
// ���������� ��������� ������
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
// �������������� �������
void red_time(List_Task& list_task, const int size);
//
void sort_print_list(List_Task& list_task, const int size);
// ������ ������
void print_list_task(List_Task& list_task, const int size);
// ������ ������
void print_task(List_Task& list_task, const int idx);
// ������ ������ �� ���������� ����.
void print_chose_task(List_Task& list_task, const int size, int year, int month, int day);
//������ ������ �� ���������� ����.
void print_chose_task(List_Task& list_task, const int size, int year, int month);
//������ ������ �� ���������� ����.
void print_chose_task(List_Task& list_task, const int size, int year);
// �������������� ������
void menu_redax_task(List_Task& list_task, int& size);
// ����� ������
int chose_task_for_redax(const int size);
// ����� �������� ��� ���������������
int chose_el_for_redax();
//�������� ����
void delete_task(List_Task& list_task, int& size, int idx);
//���� ����� ����
void menu_finde_task(List_Task& list_task, const int& size);
//����� ���� �� ��������
void finde_task_title_and_discript(List_Task& list_task, const int& size, int chose);
// ����� ���� �� ���������� 
void finde_task_priority(List_Task& list_task, const int& size);
// ����� ���� �� �������
void finde_task_time(List_Task& list_task, const int& size, int chose);