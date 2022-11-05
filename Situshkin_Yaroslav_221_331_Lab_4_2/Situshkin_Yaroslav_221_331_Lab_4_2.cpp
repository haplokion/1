// Situshkin_Yaroslav_221_331_Lab_4_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

//функция определения формата файла на вход подается путь и не изменяется, перебираются символы с конца до точки
void file_format(const string file_path_full)
{
	string tempstr = "";
	for (int i = file_path_full.length() - 1; i >= 0; i--)
	{
		tempstr = file_path_full[i] + tempstr;

		if (file_path_full[i] == '.')
		{
			break;
		}
	}
	cout << tempstr << endl;
}
//функция определения имени файла аргументом является путь не изменяется перебираются символы сначала до точки, удаляются и перебираются до символа \\ 
void file_name(const string file_path_full)
{
	string tempstr = "";
	int i = file_path_full.length() - 1;

	while (file_path_full[i] != '.')
	{
		i--;
	}


	while (i > 0 && file_path_full[i] != '\\')
	{
		tempstr = file_path_full[i] + tempstr;
		i--;
	}

	cout << tempstr << endl;
}

//определение пути файла, выводит аргумент
void file_path(const string file_path_full)
{
	cout << file_path_full << endl;
}

//выводит символы перед \\ 
void file_disk(const string file_path_full)
{
	for (int i = 0; i < file_path_full.find("\\") - 1; i++)
	{
		cout << file_path_full[i];

	}
	cout << endl;
}

//используем функцию рфайнд для поиска последнего момента вхождения подстроки в строку и по ней выводим путь
void file_rename(string file_path_full, string new_name)
{
	for (int i = 0; i < file_path_full.rfind("\\") + 1; i++) {
		cout << file_path_full[i];
	}

	cout << new_name;

	for (int i = file_path_full.rfind("."); i < file_path_full.length(); i++)
		cout << file_path_full[i];

	cout << endl;

}

//проверяем из опеном связан ли поток с нужным файлом, insert для вставки _копи после точки
void file_copy(const string file_path_full)
{
	string line; ifstream fin(file_path_full);
	if (fin.is_open()) {
		string copyFilePath = file_path_full;
		copyFilePath.insert(file_path_full.rfind("."), "_copy");
		ofstream fout(copyFilePath);
		//пока файл не пустой считываем построчно файл
		while (!fin.eof()) {
			getline(fin, line);
			fout << line << endl;
		}
		fin.close(), fout.close();
	}
	else { cout << "Неверное имя файла" << endl; }

}

int main()
{
	string new_name;
	char choice;

	while (1)
	{
		cout << "- Выход\n";
		cout << "1 - Формат файла\n";
		cout << "2 - Имя файла\n";
		cout << "3 - Путь файла\n";
		cout << "4 - Диск файла\n";
		cout << "5 - Переименовать файл\n";
		cout << "6 - Создать копию\n";

		string file_path_full;

		cin >> choice;
		switch (choice)
		{
		case '1':
		{
			cin >> file_path_full;
			file_format(file_path_full);
			break;
		}
		case '2':
		{
			cin >> file_path_full;
			file_name(file_path_full);
			break;
		}
		case '3':
		{
			cin >> file_path_full;
			file_path(file_path_full);
			break;
		}
		case '4':
		{
			cin >> file_path_full;
			file_disk(file_path_full);
			break;
		}
		case '5':
		{

			cin >> file_path_full;
			cin >> new_name;
			file_rename(file_path_full, new_name);
			break;
		}
		case '6':
		{
			cin >> file_path_full;
			file_copy(file_path_full);
			break;
		}
		case '-': {
			exit;
		}
		}
	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
