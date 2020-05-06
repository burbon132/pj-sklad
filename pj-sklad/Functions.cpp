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
	for (int i = 1; i < lst.GetSize(); i++)
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
		for (int j = i; j < lst.GetSize() - 1; j++)
		{
			int O = lst[j].GetAmount();
			int O1 = lst[j + 1].GetAmount();
			if (O < O1)
			{
				lst.Swap(lst, j, j + 1);
			}
		}
	}
}

void Save2Disk(List& lst)
{
	string path;
	cout << "������� ���� � ���������� ����� � �������� ��� �����( %Name%.txt ) ��� ������ �������� ��� �����( %Name%.txt )(���� ����� �������� � ����� � ����������)" << endl;
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
	cout << "������� ���� � ���������� ����� � �������� �����( %Name%.txt ) ��� ������ �������� ����� ���� �� ����� � ����� � ����������)" << endl << endl;
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
		cout << "�������� ����� ������ ������� ����:" << endl << endl;
		cout << "1) ������� ����� ������ �������" << endl;
		cout << "2) ��������� ������ � �����" << endl;
		cout << "3) ����� �� ���������" << endl << endl;

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
			cout << "������� � ����� ������� �� ����������, �������� ������ �����" << endl;
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
		cout << "�������� ����� ������ ������� ����:" << endl << endl;
		cout << "1) �������� ����� �����" << endl;
		cout << "2) ������� ����� �� ��������" << endl;
		cout << "3) ������������� ������ �� ���������� ������" << endl;
		cout << "4) ���������� ������ � ����������� ������ ���������" << endl;
		cout << "5) ���������� ��� ������ �������� ������" << endl;
		cout << "6) ����� ��� ������������ ������" << endl;
		cout << "7) ��������� ������" << endl;
		cout << "8) ����������� ������ � ������" << endl;
		cout << "9) ������� ��� ������ �� ������" << endl;
		cout << "10) ������� � ������� ����" << endl << endl;

		cin >> MenuBtn;
		switch (MenuBtn)
		{
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
			cout << "����� ���������� ������� ��������?" << endl << endl; cin >> counter;
			system("cls");
			cout << "������� ������ ������:" << endl;
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);
			for (int i = 0; i < counter; i++)
			{
				cout << "����� ������: "; cin >> SectionNumber;
				cout << "�������� ������: "; cin >> Name;
				cout << "����: "; cin >>Price;
				cout << "����������: "; cin >> Amount;
				cout << "����� �� (��.��.����): "; cin >> day >> trash >> month >> trash >> year;
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
				cout << "�������� ������: "; cin >> DeleteName;
				DeleteByName(lst,DeleteName);
				cout << "\n����� ������" << endl;
				system("pause");
				system("cls");
				break;
			}
			else
			{
				system("cls");
				cout << "������ � ����� �����������" << endl;
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
				cout << "��������������" << endl;
				system("pause");
				system("cls");
				break;
			}
			else
			{
				system("cls");
				cout << "������ � ����� �����������" << endl;
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
				cout << "����� ���������� ������ ����������?" << endl;
				cin >> i;
				AmountCheck(lst,i);
				cout << "\n��������������" << endl;
				system("pause");
				system("cls");
				break;
			}
			else
			{
				system("cls");
				cout << "������ � ����� �����������" << endl;
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
				cout << "������� ����� ������" << endl;
				cin >> i;
				SectionCheck(lst,newlist, i);
				cout << "������ ��������� ������ �� ����(�� ��� ���������� / ����� ������ ��� ����������� ��� ����������)?" << endl;
				cin >> check; cout << endl;
				if (strcmp(check,"��"))
				{
					Save2Disk(newlist);
					cout << "���������" << endl;
				}
				system("pause");
				system("cls");
				break;
			}
			else
			{
				system("cls");
				cout << "������ � ����� �����������" << endl;
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
				cout << "������ � ����� �����������" << endl;
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
				cout << "���������" << endl;
				system("pause");
				system("cls");
				break;
			}
			else
			{
				system("cls");
				cout << "������ � ����� �����������" << endl;
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
				cout << "������ � ����� �����������" << endl;
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
				lst.clear();
				cout << "��������" << endl;
				system("pause");
				system("cls");
				break;
			}
			else
			{
				system("cls");
				cout << "������ � ����� �����������" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		case(10):
		{
			system("cls");
			sas = false;
			break;
		}
		default:
			system("cls");
			cout << "������� � ����� ������� �� ����������, �������� ������ �����" << endl;
			system("pause");
			system("cls");
			break;
		}

	}
}
