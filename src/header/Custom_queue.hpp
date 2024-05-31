#ifndef CUSTOM_QUEUE_HPP_
#define CUSTOM_QUEUE_HPP_

#include <iostream>

namespace {using namespace std;}

//Queue Method..
//Queue public method
//생성자 & 파괴자
template<typename A>
Queue<A>::Queue(int size) : max(size)
{
	last = NULL;
}

template<typename A>
Queue<A>::Queue(const Queue & Q) : max(Q.max)
{
	if(Q.isEmpty())
	{
		cout << "큐가 비어있습니다.\n";
		exit(-1);
	}
	else
	{
		node * temp = Q.last->next;
		for(int i = 0;i<Q.count;i++)
		{
			Add(temp->data);
			temp = temp->next;
		}
	}
}

template<typename A>
Queue<A>::~Queue()
{
	while(!isEmpty())
		Remove();
}

template<typename A>
void Queue<A>::Add(A item)
{
	if(isFull())
	{
		cout << "큐 가득참.\n";
		exit(-1);
	}
	node * target;
	if(isEmpty())
	{
		target = new node;
		target->data = item;
		target->next = target;
		last = target;
	}
	else
	{
		target = new node;
		target->data = item;
		target->next = last->next;
		last->next = target;
		last = target;
	}
	count++;
	return;
}

template<typename A>
A Queue<A>::Remove()
{
	A output;
	if(isEmpty())
	{
		cout << "큐 비어있음.\n";
		exit(-1);
	}
 	else
 	{
		node * target = last->next;
		output = target->data;
		last->next = target->next;
		delete target;
	}
	count--;
	return output;
}

template<typename A>
A Queue<A>::GetFront()
{
	if(isEmpty())
	{
		cout << "큐가 비어있음\n";
		exit(-1);
	}
	else
	{
		return last->next->data;
	}
}

//Queue friend method
template<typename F>
void CopyQueue(Queue<F> & source, Queue<F> & dest)
{
	if(source.isEmpty())
	{
		cout << "소스 큐가 비어있음\n";
		exit(-1);
	}
	else
	{
		F temp;
		while(dest.GetSize() != source.GetSize())
		{
			temp = source.Remove();
			dest.Add(temp);
			source.Add(temp);
		}
	}
}

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
		cout << FirstRemove();
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
