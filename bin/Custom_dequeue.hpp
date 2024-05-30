#ifndef CUSTOM_DEQUEUE_HPP_
#define CUSTOM_DEQUEUE_HPP_

#include <iostream>

namespace {using namespace std;}

//DeQueue Method..
//public method
// 생성자 & 파괴자
template<typename B>
DeQueue<B>::DeQueue(int size) : max(size)
{
	first = NULL;
	last = NULL;
}

template<typename B>
DeQueue<B>::DeQueue(const DeQueue & dq) : max(dq.max)
{
	if(dq.isEmpty())
	{
		cout << "덱이 비어있음.\n";
		exit(-1);
	}
	else
	{
		node * temp = dq.first;
		for(int i = 0;i<dq.GetSize();i++)
		{
			FirstAdd(temp->data);
			temp = temp->next;
		}
	}
}

template<typename B>
DeQueue<B>::~DeQueue()
{
	while(!isEmpty())
		FirstRemove();
}

// 덱 수정 메서드
template<typename B>
void DeQueue<B>::FirstAdd(B item)
{
	node * target;
	if(isFull())
	{
		cout << "덱이 가득 차있음.\n";
		exit(-1);
	}
	target = new node;
	target->data = item;
	target->before = NULL;
	if(isEmpty())
	{
		first = last = target;
		last->next = NULL;
		first->next = last->before = target;
	}
	else
	{
		target->next = first;
		first->before = target;
		first = target;
	}
	count++;
}

template<typename B>
B DeQueue<B>::FirstRemove()
{
	B output;
	if(isEmpty())
	{
		cout << "덱이 비어있음.\n";
		exit(-1);
	}
	node * target = first;
	output = target->data;
	first = target->next;
	node * temp = first;
	delete target;
	if(GetSize() != 1)
		first->before = NULL;
	count--;
	return output;
}

template<typename B>
void DeQueue<B>::LastAdd(B item)
{
	node * target;
	if(isFull())
	{
		cout << "덱이 가득 차있음.\n";
		exit(-1);
	}
	target = new node;
	target->data = item;
	target->next = NULL;
	if(isEmpty())
	{
		last = first = target;
		first->before = NULL;
		first->next = last->before = target;
	}
	else
	{
		target->before = last;
		last->next = target;
		last = target;
	}
	count++;
}

template<typename B>
B DeQueue<B>::LastRemove()
{
	B output;
	if(isEmpty())
	{
		cout << "덱이 비어있음.\n";
		exit(-1);
	}
	node * target = last;
	output = last->data;
	last = target->before;
	node * temp = last;
	delete target;
	if(GetSize() != 1)
		last->next = NULL;
	count--;
	return output;
}

// 덱 상태 리턴 메서드
template<typename B>
B DeQueue<B>::GetFirst()
{
	if(isEmpty())
	{
		cout << "덱이 비어있음.\n";
		exit(-1);
	}
	else
		return first->data;
}

template<typename B>
B DeQueue<B>::GetLast()
{
	if(isEmpty())
	{
		cout << "덱이 비어있음.\n";
		exit(-1);
	}
	else
		return last->data;
}

#endif
