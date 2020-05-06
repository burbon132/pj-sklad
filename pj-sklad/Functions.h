#pragma once
#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include "List.h"
#include "tovar.h"
#include <stdlib.h>
#include <Windows.h>
using namespace std;
void AmountCheck(List& lst, int Amount);
void SectionCheck(List& lst, List& newlst, int SectionNumber);
void SortList(List& lst);
void DeleteByName(List& lst, char* Name);
void CheckShelfLife(List& lst);
void Save2Disk(List& lst);
void Read4Disk(List& lst);
void MainInterface();
void OptionalInterface(List& lst);
#endif // !_FUNCTIONS_N_