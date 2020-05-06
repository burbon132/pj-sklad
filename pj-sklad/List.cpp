#include "List.h"

List::List()
{
	Size = 0;
	head = nullptr;
}

List::~List()
{
	clear();
}

void List::pop_front()
{
	Node* temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}

void List::push_back(Tovar tovar, List& lst)
{
	bool check = false;
	for (int i = 0; i < lst.GetSize(); i++)
	{
		if (strcmp(lst[i].GetName(), tovar.GetName()) == 0 && lst[i].GGetDay() == tovar.GGetDay() && lst[i].GGetMonth() == tovar.GGetMonth() && lst[i].GGetYear() == tovar.GGetYear())
		{
			lst[i].SetAmount(lst[i].GetAmount() + 1);
			check = true;
		}
	}
	if (check == false)
	{
		if (head == nullptr)
		{
			head = new Node(tovar);
		}
		else
		{
			Node* current = this->head;
			while (current->pNext != nullptr)
			{
				current = current->pNext;
			}
			current->pNext = new Node(tovar);
		}
		Size++;
	}
}

void List::push_front(Tovar tovar)
{
	head = new Node(tovar, head);
	Size++;
}

void List::push_front_4_Read(Tovar& tovar)
{
	head = new Node(tovar, head);
	Size++;
}

void List::clear()
{
	while (Size)
	{
		pop_front();
	}
}

void List::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		Size--;
	}
}

void List::pop_back()
{
	removeAt(Size - 1);
}

void List::Swap(List& lst, int index1, int index2)
{
	Tovar temp = lst[index1];
	lst[index1] = lst[index2];
	lst[index2] = temp;
}

Tovar& List::operator[](const int index)
{
	int counter = 0;
	Node* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->tovar;
		}
		current = current->pNext;
		counter++;
	}
}