#include "List.h"
#include <cstring>
#include <iostream>

using namespace std;

List::List()
{
	count = 0;
	head = new node;
	head->next = NULL;
}

List::List(const List & L)
{
	if(L.head == NULL)
		head == NULL;
	else
	{
		head = new node;
		head->next = NULL;
		node* target = head;
		for(node* copy = L.head->next;copy->next != NULL;copy = copy->next)
		{
			target->next = new node;
			target = target->next;
			strcpy(target->str,copy->str);
		}
		target->next = NULL;
	}
}

void List::Insert(int pos, char* item)
{
	if(isEmpty())
	{
		node* temp = head;
		temp->next = new node;
		temp = temp->next;
		temp->next = NULL;
		strcpy(temp->str,item);
		head->next = temp;
	}
	else if(count < pos || pos < 0)
	{
		cout << "Index Erorr!\n";
		return;
	}
	else
	{
		node * target = head;
		node * temp;
		for(int i = 0;i<pos;i++)
			target = target->next;
		temp = target->next;
		target->next = new node;
		target = target->next;
		strcpy(target->str,item);
		target->next = temp;
	}
	count++;
	return;
}

void List::Delete(int pos)
{
	if(isEmpty())
	{
		cout << "리스트가 비어있습니다.\n";
		return;
	}
	else if(count < pos || pos < 0)
	{
		cout << "Index Erorr!\n";
		return;
	}
	else
	{
		node* temp = head;
		node* target;
		for(int i = 0;i<pos-1;i++)
			temp = temp->next;
		target = temp->next;
		temp->next = target->next;
		count--;
		delete target;
	}
}

void List::show() const
{
	node* temp;
	for(temp = head;temp->next != NULL;temp = temp->next)
		cout << temp->str << endl;
	cout << temp->str << endl;
}

List::~List()
{
	while(count != 0)
		Delete(1);
}

void List::search(int pos, char* item) const
{
	if(pos > count)
		pos = count;
	node* temp = head;
	for(int i = 0;i<pos;i++)
	{
		temp=temp->next;
		if(!(strcmp(temp->str,item)))
		{
			cout << "Find " << item << endl;
			return;
		}
	}
	cout << "Not Find " << item << endl;
}
