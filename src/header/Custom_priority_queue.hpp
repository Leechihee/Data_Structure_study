#ifndef CUSTOM_PRIORITY_QUEUE_HPP_
#define CUSTOM_PRIORITY_QUEUE_HPP_

#include <iostream>
#include <malloc.h>

namespace{using namespace std;}

//Priority_Queue Private Method
template<typename C>
void Priority_Queue<C>::Swap(int index1, int index2)
{
	C temp = heap[index1];
	heap[index1] = heap[index2];
	heap[index2] = temp;
}

//Priority_Queue Public Method
// 생성자 & 파괴자
template<typename C>
Priority_Queue<C>::Priority_Queue(const int size) : max(size)
{
	heap = new C[size+1];
}

template<typename C>
Priority_Queue<C>::Priority_Queue(const Priority_Queue & PQ) : max(PQ.max), count(PQ.count)
{
	heap = new C[max+1];
	for(int i = 0;i<count;i++)
		heap[i] = PQ.heap[i];
}

template<typename C>
Priority_Queue<C>::~Priority_Queue()
{
	delete [] heap;
}

// 큐 수정 메서드
template<typename C>
void Priority_Queue<C>::Add(const C item)
{
	if(isFull())
	{
		cout << "큐가 가득 차있습니다.\n";
		return;
	}
	int child = count, parent = (child-1)/2, temp;
	heap[child] = item;
	while(heap[child] > heap[parent] && child != 0)
	{
		Swap(child, parent);
		child = parent;
		parent = (child-1)/2;
	}
	count++;
}

template<typename C>
C Priority_Queue<C>::Remove()
{
	if(isEmpty())
	{
		cout << "큐가 비어있습니다.\n";
		exit(-1);
	}
	C ret = heap[0];
	int index = 0, child = 1;
	heap[0] = heap[count-1];
	heap[count-1] = 0;
	while(child <= count && (heap[child] || heap[child+1]))
	{
		if(heap[child+1])
			child = (heap[child] < heap[child+1]) ? child+1 : child;
		if(heap[child] > heap[index])
			Swap(index, child);
		index = child;
		child = index*2+1;
	}
	count--;
	return ret;
}

template<typename C>
void Priority_Queue<C>::heapSort(C* arr,int size)
{
	Priority_Queue<C> temp(*this);
	delete(heap);
	heap = new C[max+1];
	if(max < size)
		size = max;
	count = size;
	for(int i = 0;i<size;i++)
		heap[i] = arr[i];
	int index = count-1, child = 2*index+1;
	int check = index;
	while(index >= 0)
	{
		if(child < count && (heap[child] || heap[child+1]) && (heap[check] < heap[child] || heap[check] < heap[child+1]))
		{
			child = (heap[child] < heap[child+1]) ? child+1 : child;
			Swap(check, child);
			check = child;
			child = 2*check+1;
			continue;
		}
		index--;
		check = index;
		child = 2*index+1;
	}
	for(int i = 0;i<size;i++)
		arr[i] = Remove();
	delete [] heap;
	*this = temp;
	return;
}
// 큐 상태 리턴 메서드

template<typename C>
bool Priority_Queue<C>::isFull() const
{
	return (count == max);
}

template<typename C>
bool Priority_Queue<C>::isEmpty() const
{
	return (count == 0);
}

template<typename C>
Priority_Queue<C> Priority_Queue<C>::operator=(const Priority_Queue & PQ)
{
	Priority_Queue<C> ret(PQ);
	return ret;
}
#endif
