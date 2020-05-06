#pragma once
#ifndef _TOVAR_H_
#define _TOVAR_H_
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <stdlib.h>
using namespace std;
struct Tovar
{
public:
	Tovar();
	Tovar(int SectionNumber, char* Name, double Price, int Amount, int day, int month, int year);
	Tovar(int SectionNumber, char* Name, double Price, int Amount, int day, int month, int year, int q);

	void SetName(char* Name);
	void SetAmount(int Amount);
	void SetPrice(double Price);
	void SetSectionNumber(int SectionNumber);
	void SSetDay(int day);
	void SSetMonth(int month);
	void SSetYear(int year);

	char*  GetName();
	int    GetAmount();
	double GetPrice();
	int	   GetSectionNumber();
	int	   GGetDay();
	int	   GGetMonth();
	int	   GGetYear();

	friend ostream& operator<<(ostream& out, Tovar& student);

protected:
	int SectionNumber;
	char*  Name = new char[15];
	int	   Amount;
	double Price;

	class ShelfLife
	{
	public:
		int	 GetDay();
		int	 GetMonth();
		int	 GetYear();

		void SetDay(int day);
		void SetMonth(int month);
		void SetYear(int year);

		ShelfLife();
		ShelfLife(int day, int month, int year);
	private:
		int day;
		int month;
		int year;
	};
	ShelfLife BD;
};
#endif  // !_TOVAR_H_