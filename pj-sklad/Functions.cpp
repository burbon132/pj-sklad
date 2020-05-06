#include "Functions.h"

void AmountCheck(List& lst, int Amount)
{
	for (int i = 0; i < lst.GetSize(); i++) {
		if (lst[i].GetAmount() < Amount) {
			cout << lst[i];
		}
	}
}

void SectionCheck(List& lst, List& newlst, int SectionNumber)
{
	for (int i = 0; i < lst.GetSize(); i++)
	{
		if (lst[i].GetSectionNumber() == SectionNumber) {
			newlst.push_front(lst[i]);
		}
	}
	SortList(newlst);
	for (int i = 0; i < newlst.GetSize(); i++) {
		cout << newlst[i];
	}
}

void SortList(List& lst)
{
	int k = 0;
	for (int i = 0; i < lst.GetSize() - 1; i++)
	{
		for (int j = i; j < lst.GetSize() - 1; j++)
		{
			char* st1 = lst[j].GetName();
			char* st2 = lst[j + 1].GetName();
			if ((int)st1[0] > (int)st2[0])
			{
				lst.Swap(lst, j, j + 1);
			}
			if ((int)st1[0] == (int)st2[0])
			{
				while ((int)st1[k] == (int)st2[k])
				{
					k++;
				}
				if ((int)st1[k] > (int)st2[k]) {
					lst.Swap(lst, j, j + 1);
				}
			}
			k = 0;
		}
		k = 0;
	}
}

void DeleteByName(List& lst, char* Name)
{
	for (int i = 0; i < lst.GetSize(); i++)
	{
		if (strcmp(lst[i].GetName(), Name) == 0)
		{
			lst.removeAt(i);
		}
	}
}

void CheckShelfLife(List& lst)
{
	const time_t rawtime = time(NULL);
	struct tm* timeinfo;
	timeinfo = localtime(&rawtime);
	for (int i = 0; i < lst.GetSize(); i++)
	{
		if ((timeinfo->tm_year + 1900) * 10000 + (timeinfo->tm_mon + 1) * 100 + timeinfo->tm_mday > lst[i].GGetYear() * 10000 + lst[i].GGetMonth() * 100 + lst[i].GGetDay())
		{
			cout << lst[i];
		}
	}
	cout << endl;
}

void SortbyAmount(List& lst)
{
	for (int i = 0; i < lst.GetSize() - 1; i++)
	{
		for (int j = i + 1; j < lst.GetSize(); j++)
		{
			int O = lst[i].GetAmount();
			int O1 = lst[j].GetAmount();
			if (O < O1)
			{
				lst.Swap(lst, i, j);
			}
		}
	}
}

void Save2Disk(List& lst)
{
	string path;
	cout << "Введите название файла" << endl;
	cin >> path;
	ofstream fout;
	fout.open(path);
	for (int i = 0; i < lst.GetSize(); i++)
	{
		fout << lst[i].GetSectionNumber() << "\t";
		fout.write(lst[i].GetName(), strlen(lst[i].GetName()));
		if (strlen(lst[i].GetName()) < 8) {
			fout << "\t";
		}
		fout << "\t";
		fout << lst[i].GetPrice() <<"\t";
		fout << lst[i].GetAmount() << "\t";
		fout << lst[i].GGetDay() << ".";
		fout << lst[i].GGetMonth() << ".";
		fout << lst[i].GGetYear() << endl;
	}
	fout.close();
	cout << endl;
}

void Read4Disk(List& lst)
{
	cout << "Введите путь в конкретную папку и название файла с форматом" << endl << endl;
	string path;
	cin >> path;
	ifstream fin;
	fin.open(path);
	int i = 0, j = 0;;
	int SectionNumber;
	char* Name = new char;
	double Price;
	int	Amount;
	char tresh;
	int day;
	int month;
	int year;
	while (!fin.eof())
	{
		fin >> SectionNumber >> Name >> Price>> Amount >> day >> tresh >> month >> tresh >> year;
		if (strcmp(Name, "") == 0)
			break;
		lst.push_back(Tovar(SectionNumber, Name, Price, Amount, day, month, year, 1),lst,Amount);
	}
	fin.close();
	cout << endl;
}

void MainInterface()
{
	int MenuBtn;
	while (true)
	{
		cout << "__________________________________________" << endl;
		cout << "|| Выберите цифру нужной функции меню: \t||" << endl;
		cout << "|| 1) Создать новый список товаров\t||" << endl;
		cout << "|| 2) Загрузить список с диска\t\t||" << endl;
		cout << "|| 3) Выйти из программы\t\t||" << endl << endl;

		cin >> MenuBtn;
		switch (MenuBtn)
		{
		case(1):
		{
			system("cls");
			List lst;
			OptionalInterface(lst);
			break;
		}
		case(2):
		{
			system("cls");
			List lst;
			Read4Disk(lst);
			system("cls");
			OptionalInterface(lst);
			break;
		}
		case(3):
		{
			exit(1);
		}
		default:
			cout << "Функции с таким номером не существует, выберите другую цифру" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

void OptionalInterface(List& lst)
{
	system("cls");
	bool sas = true;
	int MenuBtn;
	while (sas)
	{
		cout << "__________________________________________________________" << endl;
		cout << "|| Выберите цифру нужной функции меню: \t\t\t||" << endl;
		cout << "|| 0) Перейти в главное меню\t\t\t\t||" << endl ;
		cout << "|| 1) Добавить новый товар\t\t\t\t||" << endl;
		cout << "|| 2) Удалить товар по названию\t\t\t\t||" << endl;
		cout << "|| 3) Отсортировать список по количеству товара\t\t||" << endl;
		cout << "|| 4) Определить товары с колечеством меньше заданного\t||" << endl;
		cout << "|| 5) Определить все товары заданной секции\t\t||" << endl;
		cout << "|| 6) Найти все просроченные товары\t\t\t||" << endl;
		cout << "|| 7) Сохранить список\t\t\t\t\t||" << endl;
		cout << "|| 8) Удалить все товары из списка\t\t\t||" << endl;
		cout << "|| 9) Просмотреть товары в списке\t\t\t||" << endl << endl;


		cin >> MenuBtn;
		switch (MenuBtn)
		{
		case(0):
		{
			system("cls");
			sas = false;
			break;
		}
		case(1):
		{
			system("cls");
			int counter;
			int SectionNumber;
			char* Name = new char;
			double Price;
			int	Amount;
			char trash;
			int day;
			int month;
			int year;
			cout << "Какое количество товаров добавить?" << endl << endl; cin >> counter;
			system("cls");
			cout << "Введите данные товара:" << endl;
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);
			for (int i = 0; i < counter; i++)
			{
				cout << "Номер секции: "; cin >> SectionNumber;
				cout << "Название товара: "; cin >> Name;
				cout << "Цена: "; cin >>Price;
				cout << "Количество: "; cin >> Amount;
				cout << "Годен до (дд.мм.гггг): "; cin >> day >> trash >> month >> trash >> year;
				lst.push_back(Tovar(SectionNumber, Name, Price, Amount, day, month, year, 0), lst, Amount);
				system("pause");
				system("cls");
			}
			SetConsoleCP(866);
			SetConsoleOutputCP(866);
			break;
		}
		case(2):
		{	
			if (lst.GetSize() != 0)
			{	
				system("cls");
				char* DeleteName = new char;
				SetConsoleCP(1251);
				SetConsoleOutputCP(1251);
				cout << "Название товара: "; cin >> DeleteName;
				DeleteByName(lst,DeleteName);
				SetConsoleCP(866);
				SetConsoleOutputCP(866);
				cout << "\nТовар удален" << endl;
				system("pause");
				system("cls");
				break;
			}
			else
			{
				system("cls");
				cout << "Товары в листе отсустввуют" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		case(3):
		{
			if (lst.GetSize() != 0)
			{
				system("cls");
				SortbyAmount(lst);
				cout << "Отсортированно" << endl;
				system("pause");
				system("cls");
				break;
			}
			else
			{
				system("cls");
				cout << "Товары в листе отсустввуют" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		case(4):
		{
			if (lst.GetSize() != 0)
			{
				system("cls");
				int i;
				cout << "Какое количество товара необходимо?" << endl;
				cin >> i;
				AmountCheck(lst,i);
				cout << "\nОтсортированно" << endl;
				system("pause");
				system("cls");
				break;
			}
			else
			{
				system("cls");
				cout << "Товары в листе отсустввуют" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		case(5):
		{
			if (lst.GetSize() != 0)
			{
				system("cls");
				List newlist;
				int i;
				char* check = new char;
				cout << "Введите номер секции" << endl;
				cin >> i;
				SectionCheck(lst,newlist, i);
				cout << "Хотите сохранить данные на диск(Да для сохранения / Любое другое для продолжения без сохранения)?" << endl;
				cin >> check; cout << endl;
				if (strcmp(check,"Да")==0)
				{
					Save2Disk(newlist);
					cout << "Сохранено" << endl;
				}
				system("pause");
				system("cls");
				break;
			}
			else
			{
				system("cls");
				cout << "Товары в листе отсустввуют" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		case(6):
		{
			if (lst.GetSize() != 0)
			{
				system("cls");
				CheckShelfLife(lst);
				system("pause");
				system("cls");
				break;
			}
			else
			{
				system("cls");
				cout << "Товары в листе отсустввуют" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		case(7):
		{
			if (lst.GetSize() != 0)
			{
				system("cls");
				Save2Disk(lst);
				system("cls");
				cout << "Сохранено" << endl;
				system("pause");
				system("cls");
				break;
			}
			else
			{
				system("cls");
				cout << "Товары в листе отсустввуют" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		case(8):
		{
			if (lst.GetSize() != 0)
			{
				system("cls");
				lst.clear();
				cout << "Очищенно" << endl;
				system("pause");
				system("cls");
				break;
			}
			else
			{
				system("cls");
				cout << "Товары в листе отсустввуют" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		case(9):
		{
			if (lst.GetSize() != 0)
			{
				system("cls");
				for (int i = 0; i < lst.GetSize(); i++) {
					cout << lst[i];
				}
				system("pause");
				system("cls");
				break;
			}
			else
			{
				system("cls");
				cout << "Товары в листе отсустввуют" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		default:
			system("cls");
			cout << "Функции с таким номером не существует, выберите другую цифру" << endl;
			system("pause");
			system("cls");
			break;
		}

	}
}
