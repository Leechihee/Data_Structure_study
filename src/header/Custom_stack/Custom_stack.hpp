#ifndef CUSTOM_STACK_HPP_
#define CUSTOM_STACK_HPP_

#include "Custom_stack.h"

namespace {using namespace std;}
//Stack Public Method
// 생성자 & 파괴자
template<typename A>
Stack<A>::Stack(int size) : max(size), count(0)
{
	head = new node;
	head->next = NULL;
}

template<typename A>
Stack<A>::Stack(const Stack & S) : max(S.max)
{
	head = new node;
	head->next = NULL;
	if(S.isEmpty())
		return;
	else
	{
		node* temp = S.head;
		for(int i=0;i<S.count;i++)
		{
			for(int j = S.count-i;j>0;j--)
				temp = temp->next;
			Push(temp->data);
			temp = S.head;
		}
	}
}

template<typename A>
Stack<A>::~Stack()
{
	while(!isEmpty())
		Pop();
}

// 스택 수정 메서드
template<typename A>
void Stack<A>::Push(const A & item)
{
	if(isFull())
	{
		cout << "스택이 가득 차있습니다.\n";
		return;
	}
	else if(isEmpty())
	{
		head->next = new node;
		head->next->data = item;
		head->next->next = NULL;
	}
	else
	{
		node * temp = head->next;
		head->next = new node;
		if(head->next == NULL)
			exit(-1);
		head->next->data = item;
		head->next->next = temp;
	}
	count++;
}

template<typename A>
A Stack<A>::Pop()
{
	A output;
	if(isEmpty())
	{
		cout << "스택이 비어있습니다.\n";
		exit(-1);
	}
	else
	{
		node* target = head->next;
		head->next = target->next;
		output = target->data;
		delete target;
		count--;
	}
	return output;
}

//스택 출력 메서드
template<typename A>
A Stack<A>::GetTop()
{
	if(isEmpty())
	{
		cout << "스택이 비어있습니다.\n";
		exit(-1);
	}
	else
		return head->next->data;
}

template<typename A>
int Stack<A>::FindItem(const A & item)
{
	if(isEmpty())
	{
		cout << "스택이 비어있습니다.\n";
		exit(-1);
	}
	else
	{
		int Count = 0;
		node* temp = head;
		for(int i = 0;i<count;i++)
		{
			temp = temp->next;
			if(temp->data == item) Count++;
		}
		return Count;
	}
}

//프렌드 함수
template<typename F>
void RecurseStack(Stack<F> & S)
{
	static int fc_call = 0;
	if(S.isEmpty())
		return;
	fc_call++;
	F temp = S.Pop();
	RecurseStack(S);
	cout << temp;
	S.Push(temp);
	fc_call--;
	if(fc_call == 0)
		cout << endl;
}
#endif
