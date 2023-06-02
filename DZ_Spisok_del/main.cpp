
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
	// создание списка и задачи
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


	cout << "Добро пожаловать в программу \"Список дел\"" << endl << endl;

	bool exit = true;

	do
	{
		cout << "\nВы находитесь в главном меню " << endl << endl;
		cout << "Введите число для действия: " << endl;
		cout << "1 для показа списка дел " << endl;
		cout << "2 для добавления дела в список" << endl;
		cout << "3 для удаления дела." << endl;
		cout << "4 для редактирования дела " << endl;
		cout << "5 для поиска дела " << endl;
		cout << "0 для выхода из программы " << endl;

		int chose = -1;
		cin >> chose;

		bool list_is_filled = false;

		switch (chose)
		{
		case 0:
			cout << "Всего доброго " << endl;
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


