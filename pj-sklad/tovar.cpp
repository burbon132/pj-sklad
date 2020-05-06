#include "tovar.h"

Tovar::Tovar()
{
	this->SectionNumber = 0;
	strcpy(this->Name, "Unknown");
	this->Price = 0;
	this->Amount = 0;
	Tovar::ShelfLife::ShelfLife();
}

Tovar::Tovar(int SectionNumber, char* Name, double Price, int Amount, int day, int month, int year)
{
	this->Name = Name;
	this->SectionNumber = SectionNumber;
	this->Price = Price;
	this->Amount = Amount;
	BD.SetDay(day);
	BD.SetMonth(month);
	BD.SetYear(year);
}

Tovar::Tovar(int SectionNumber, char* Name, double Price, int Amount, int day, int month, int year, int q)
{
	char* arrN = new char[strlen(Name) + 1];
	for (int i = 0; i < strlen(Name) + 1; i++) { arrN[i] = Name[i]; }
	this->Name = arrN;
	this->SectionNumber = SectionNumber;
	this->Price = Price;
	this->Amount = Amount;
	BD.SetDay(day);
	BD.SetMonth(month);
	BD.SetYear(year);
}

Tovar::ShelfLife::ShelfLife()
{
	this->day = 1;
	this->month = 1;
	this->year = 1970;
}

Tovar::ShelfLife::ShelfLife(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

ostream& operator<<(ostream& out, Tovar& tovar)
{
	out << "Секция номер: "  << tovar.GetSectionNumber() << endl << tovar.GetName() << "\t" << tovar.GetPrice() << "\t" << tovar.GetAmount() << "\t" << tovar.BD.GetDay() << "." << tovar.BD.GetMonth() << "." << tovar.BD.GetYear() << endl << endl;
	return out;
}

void Tovar::SetName(char* Name)
{
	this->Name = Name;
}

void Tovar::SetAmount(int Amount)
{
	this->Amount = Amount;
}

void Tovar::SetPrice(double Price)
{
	this->Price = Price;
}

void Tovar::SetSectionNumber(int SectionNumber)
{
	this->SectionNumber = SectionNumber;
}

void Tovar::SSetDay(int day)
{
	this->BD.SetDay(day);
}

void Tovar::SSetMonth(int month)
{
	this->BD.SetDay(month);
}

void Tovar::SSetYear(int year)
{
	this->BD.SetDay(year);
}

void Tovar::ShelfLife::SetDay(int day)
{
	this->day = day;
}

void Tovar::ShelfLife::SetMonth(int month)
{
	this->month = month;
}

void Tovar::ShelfLife::SetYear(int year)
{
	this->year = year;
}

char* Tovar::GetName()
{
	return this->Name;
}

int Tovar::GetAmount()
{
	return this->Amount;
}

double Tovar::GetPrice()
{
	return this->Price;
}

int Tovar::GetSectionNumber()
{
	return this->SectionNumber;
}

int Tovar::GGetDay()
{
	return BD.GetDay();
}

int Tovar::GGetMonth()
{
	return BD.GetMonth();
}

int Tovar::GGetYear()
{
	return BD.GetYear();
}

int Tovar::ShelfLife::GetDay()
{
	return this->day;
}

int Tovar::ShelfLife::GetMonth()
{
	return this->month;
}

int Tovar::ShelfLife::GetYear()
{
	return this->year;
}
