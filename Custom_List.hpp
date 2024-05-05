#ifndef CUSTOM_LIST_HPP_
#define CUSTOM_LIST_HPP_

#include "Custom_list.h"

//List public method
// 생성자, 파괴자
template <typename T>
List<T>::List()
{
	count = 0;
	head = new node;
	head->next = NULL;
}

template <typename T>
List<T>::List(const List & L)
{
	if(L.isEmpty())
		List();
	else
	{
		count = L.count;
		head = new node;
		head->next = NULL;
		node* target = head,* copy;
		for(copy = L.head->next;copy->next != NULL;copy = copy->next)
		{
			target->next = new node;
			target = target->next;
			target->data = copy->data;
		}
		target->next = new node;
		target = target->next;
		target->data = copy->data;
		target->next = NULL;
	}
}

template<typename T>
List<T>::~List()
{
	while(!isEmpty())
		Delete(1);
}

// 리스트 수정 메서드
template <typename T>
void List<T>::Insert(int pos, T item)
{
	if(isEmpty())
	{
		node* temp = head;
		temp->next = new node;
		temp = temp->next;
		temp->next = NULL;
		temp->data = item;
		head->next = temp;
	}
	else if(count+1 < pos || pos <= 0)
	{
		cout << "Insert() : Index Erorr!\n";
		exit(-1);
	}
	else
	{
		node * target = head;
		node * temp;
		for(int i = 0;i<pos-1;i++)
			target = target->next;
		temp = target->next;
		target->next = new node;
		target = target->next;
		target->data = item;
		target->next = temp;
	}
	count++;
	return;
}

template <typename T>
void List<T>::Delete(int pos)
{
	if(isEmpty())
	{
		cout << "Delete() : 리스트가 비어있습니다.\n";
		exit(-1);
	}
	else if(count < pos || pos <= 0)
	{
		cout << "Delete() : Index Erorr!\n";
		exit(-1);
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

template<typename T>
void List<T>::Sort(int start, int end)
{
	if(isEmpty())
	{
		cout << "Sort() : 리스트가 비어있습니다.\n";
		exit(-1);
	}
	T pivot = ReturnData(end);
	int up = start, down = end-1;
	if(end-start == 2 && ReturnData(start) < ReturnData(end) && ReturnData(start+1) < ReturnData(end) && ReturnData(start) > ReturnData(start+1))
	{
		Insert(start+1,ReturnData(start));
		Insert(start,ReturnData(end));
		Delete(start+1);
		Delete(end);
		return;
	}
	while(up<down)
	{
		while(ReturnData(up) <= pivot && up < down) up++;
		while(ReturnData(down) >= pivot && down > up) down--;
		Insert(down,ReturnData(up));
		Insert(up,ReturnData(down+1));
		Delete(up+1);
		Delete(down+1);
	}
	if(ReturnData(up) > ReturnData(end))
	{
		Insert(end,ReturnData(up));
		Insert(up,ReturnData(end+1));
		Delete(up+1);
		Delete(end+1);
	}
	if(up - start >= 2) Sort(start,up);
	if(end - up+1 > 2) Sort(up+1,end);
}

template<typename T>
int List<T>::FindOrAdd(T item)
{
	int INDEX = FindData(item);
	if(INDEX > 0)
		return INDEX;
	else
	{
		cout << "새로 삽입합니다.\n";
		Insert(End()+1,item);
		return End();
	}
}

template<typename T>
void List<T>::Swap(int pos1, int pos2)
{
	if(isEmpty())
	{
		cout << "Swap() : 리스트가 비어있습니다\n";
		exit(-1);
	}
	else if(pos1 == pos2)
		return;
	else if(count < pos1 && count < pos2 && pos1 <= 0 && pos2 <= 0)
	{
		cout << "Swap() : INDEX ERORR\n";
		exit(-1);
	}
	else
	{
		Insert(pos1,ReturnData(pos2));
		Insert(pos2+1,ReturnData(pos1+1));
		Delete(pos1+1);
		Delete(pos2+1);
	}
}

template<typename T>
void List<T>::NodeSwap(int pos)
{
	if(isEmpty())
	{
		cout << "NodeSwap() : 리스트가 비어있습니다.\n";
		exit(-1);
	}
	else
	{
		node * before = head,* target,* Next,* temp;
		if(pos == 1)
		{
			target = before->next;
			Next = target->next;
			temp = target;
			target = Next;
			Next = temp;
			Next->next = target->next; 
			target->next = Next;
			before->next = target;
			return;
		}
		for(int i = Begin();i<=pos-2;i++)
			before = before->next;
		target = before->next->next;
		if(target->next == NULL)
		{
			Next = before->next;
			temp = target;
			target = Next;
			Next = temp;
			Next->next = target;
			target->next = NULL;
			before->next = Next;
		}
		else
		{
			before = before->next;
			Next = target->next;
			temp = target;
			target = Next;
			Next = temp;
			Next->next = target->next; 
			target->next = Next;
			before->next = target;
		}
	}
}

template<typename T>
void List<T>::nChenge(int pos,const List<T> & source)
{
	if(source.isEmpty())
	{
		cout << "nChenge() : source 리스트가 비어있습니다.\n";
		exit(-1);
	}
	if(Size() - pos > source.Size())
	{
		for(int i = pos;i<source.Size()+pos;i++)
		{
			T temp = source.ReturnData(i-pos+1);
			ReturnData(i) = temp;
		}
	}
	else
	{
		for(int i = pos;i<source.Size()+pos;i++)
		{
			int test = Size();
			if(i <=Size())
			{
				Insert(i,source.ReturnData(i-pos+1));
				Delete(i+1);
			}
			else
				Insert(i,source.ReturnData(i-pos+1));
		}
	}
}

// 리스트 출력 메서드
template<typename T>
void List<T>::show() const
{
	node* temp;
	for(temp = head->next;temp->next != NULL;temp = temp->next)
		cout << temp->data << " ";
	cout << temp->data;
}

template <typename T>
T& List<T>::ReturnData(int pos) const
{
	if(isEmpty())
	{
		cout << "ReturnData() : 리스트가 비어있습니다.";
		exit(-1);
	}
	else if(count < pos || pos <= 0)
	{
		cout << "ReturnData() : Index Erorr!\n";
		exit(-1);
	}
	else
	{
		node* target = head;
		for(int i = 0;i<pos;i++)
			target = target->next;
		return target->data;
	}
}

template<typename T>
int List<T>::FindData(T target) const
{
	int Target = target;
	if(isEmpty())
	{
		cout << "FindData() : 리스트가 비어있습니다.\n";
		exit(-1);
	}
	else
	{
		for(int i = Begin();i<=End();i++)
		{
			int temp = ReturnData(i);
			if(temp == target)
				return i;
		}
		cout << target << "을 찾을 수 없습니다.\n";
		return -1;
	}
}

template<typename T>
bool List<T>::isSorted() const
{
	if(isEmpty())
	{
		cout << "isSorted() : 리스트가 비어있습니다.\n";
		exit(-1);
	}
	else
	{
		int i;
		for(i = Begin();i<=End()-1;i++)
		{
			if(ReturnData(i) > ReturnData(i+1))
				return false;
		}
		if(ReturnData(i) < ReturnData(i-1))
			return false;
		return true;
	}
}

//List operator method
template<typename T> 
void List<T>::operator=(const List<T> & L)
{
	if(L.isEmpty())
	{
		cout << "operator=() : 리스트가 비어있습니다.\n";
		exit(-1);
	}
	while(!isEmpty())
		Delete(1);
	for(int i = 1;i<L.Size()+1;i++)
		Insert(i,L.ReturnData(i));
}

//List friend function
template<typename F>
List<F> ReverseCopy(const List<F> & L)
{
	typedef typename List<F>::node Node;
	List<F> Temp;
	if(L.isEmpty())
		return Temp;
	else
	{
		int endIndex = L.count+1;
		for(int i = 1;i<L.count+1;i++)
			Temp.Insert(i,L.ReturnData(endIndex-i));
		return Temp;
	}
}

template<typename F>
List<F> MergeAndSort(const List<F> & L1, const List<F> & L2)
{
	List<F> Temp;
	if(L1.isEmpty() && L2.isEmpty())
		return Temp;
	else if(!L1.isEmpty() && L2.isEmpty())
		Temp = L1;
	else if(L1.isEmpty() && !L2.isEmpty())
		Temp = L2;
	else
	{
		for(int i = 1;i<L1.count+1;i++)
			Temp.Insert(i,L1.ReturnData(i));
		for(int i = 1;i<L2.count+1;i++)
			Temp.Insert(i,L2.ReturnData(i));
	}
	Temp.Sort(Temp.Begin(),Temp.End());
	return Temp;
}

#endif
