#pragma once
#ifndef _LIST_H_
#define _LIST_H_
#include "tovar.h"
class List
{
public:
	List();
	~List();

	void pop_front();

	void push_back(Tovar tovar, List& lst, int c);

	void clear();

	int GetSize() { return Size; }

	Tovar& operator[](const int index);

	void push_front(Tovar tovar);

	void removeAt(int index);

	void pop_back();

	void Swap(List& lst, int index1, int index2);

	void push_front_4_Read(Tovar& tovar);

private:
	class Node
	{
	public:
		Node* pNext;
		Tovar tovar;
		Node(Tovar tovar = Tovar(), Node* pNext = nullptr)
		{
			this->tovar = tovar;
			this->pNext = pNext;
		}
	};
	friend void SortList(List& lst);
	int Size;
	Node* head;
};
#endif // !_LIST_H_