#pragma once
#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_
#include "List.h"
#include "tovar.h"
#include <stdlib.h>
#include <Windows.h>
using namespace std;
void AmountCheck(List& lst, int Amount);
void SectionCheck(List& lst, List& newlst, int SectionNumber);
void Eldest(List& lst, List& eldestlst);
void Junior(List& lst, List& juniorlst);
void SortList(List& lst);
void Save2Disk(List& lst);
void Read4Disk(List& lst);
void MainInterface();
void OptionalInterface(List& lst);
#endif // !_FUNCTIONS_N_