
#include "Function.h"



int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int size = 0;

	FILE* file;
	fopen_s(&file, "size.txt", "r");
	if (file)
	{
		fscanf(file, "%d", &size);
		fclose(file);
	}
	// �������� ������ � ������
	List_Task list_task;

	list_task.tasks = new Task[size];
	if (size !=0)
	{
		fopen_s(&file, "data.dat", "rb");
		if (file)
		{
			fread(list_task.tasks, sizeof Task, size, file);
			fclose(file);
		}
	}


	cout << "����� ���������� � ��������� \"������ ���\"" << endl << endl;

	bool exit = true;

	do
	{
		cout << "\n�� ���������� � ������� ���� " << endl << endl;
		cout << "������� ����� ��� ��������: " << endl;
		cout << "1 ��� ������ ������ ��� " << endl;
		cout << "2 ��� ���������� ���� � ������" << endl;
		cout << "3 ��� �������� ����." << endl;
		cout << "4 ��� �������������� ���� " << endl;
		cout << "5 ��� ������ ���� " << endl;
		cout << "0 ��� ������ �� ��������� " << endl;

		int chose = -1;
		cin >> chose;

		bool list_is_filled = false;

		switch (chose)
		{
		case 0:
			cout << "����� ������� " << endl;
			fopen_s(&file, "size.txt", "w");
			if (file)
			{
				fprintf(file, "%d", size);
				fclose(file);
			}

			fopen_s(&file, "data.dat", "wb");
			if (file)
			{
				fwrite(list_task.tasks, sizeof Task, size, file);
				fclose(file);
			}
			delete[] list_task.tasks;
			exit = false;
			break;
		case 1:
			sort_print_list(list_task, size);
			break;
		case 2:
			menu_add_task(list_task, size);
			break;
		case 3:
			delete_task(list_task, size,chose_task_for_redax(size));
			break;
		case 4:
			menu_redax_task(list_task, size);
			break;
		case 5:
			menu_finde_task(list_task, size);
			break;
		default:
			break;
		}

	} while (exit);


	return 0;
}


