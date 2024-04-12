#ifndef CUSTOM_QUEUE_H_
#define CUSTOM_QUEUE_H_

template<typename A>
class Queue{
	class node{
	public:
		A data;
		class node* next;
	};
	node * last;
	int max;
	int count = 0;
public:
	//생성자 & 파괴자
	Queue(int size); // size 만큼의 공간을 가진 큐 선언
	Queue(const Queue & q); // 복사 생성자
	~Queue(); // 파괴자
	//큐 수정 메서드
	void Add(A item); // 큐에 item을 삽입, 큐가 가득 차있으면 프로그램 종료
	A Remove(); // 선두에 있는 데이터를 출력 후 삭제, 큐가 비어있으면 프로그램 종료
	//큐 상태 리턴 메서드
	bool isEmpty() const {return(count == 0);} // 큐가 비어있으면 TRUE, 아니라면 FALSE
	bool isFull() const {return(count == max);} // 큐가 가득 차있으면 TRUE, 아니라면 FALSE
	int GetSize() const {return count;} // 큐의 현재 사이즈 리턴
	A GetFront(); // 선두에 있는 데이터 리턴, 큐가 비어있으면 프로그램 종료
	//프렌드 함수
	template<typename F>
	friend void CopyQueue(Queue<F> & source, Queue<F> & dest); // source 큐를 dest 큐로 복사
	
};

template<typename B>
class DeQueue{
	class node{
	public:
		B data;
		class node* next;
		class node* before;
	};
	int max;
	int count = 0;
	node * last;
	node * first;
public:
	// 생성자 & 파괴자
	DeQueue(int size);// size 만큼의 공간을 가진 덱 생성
	DeQueue(const DeQueue & dq); // 복사생성자
	~DeQueue(); // 파괴자
	// 덱 수정 메서드
	void FirstAdd(B item); // 선두에 item을 삽입, 큐가 가득 차있으면 프로그램 종료
	B FirstRemove(); // 선두에 있는 데이터를 리턴 후 삭제, 큐가 비어있으면 프로그램 종료
	void LastAdd(B item); // 후미에 item을 삽입, 큐가 가득 차있으면 프로그램 종료
	B LastRemove(); // 후미에 있는 데이터를 리턴 후 삭제, 큐가 비어있으면 프로그램 종료
	// 덱 상태 리턴 메서드
	bool isEmpty() const {return (count == 0);} // 큐가 비어있으면 TRUE, 아니라면 FALSE
	bool isFull() const {return (count == max);} // 큐가 가득 차있으면 TRUE, 아니라면 FALSE
	int GetSize() const {return count;} // 큐의 현재 사이즈 리턴
	B GetFirst(); // 선두에 있는 데이터 리턴, 큐가 비어있으면 프로그램 종료
	B GetLast(); // 후미에 있는 데이터 리턴, 큐가 비어있으면 프로그램 종료
};

#include "Custom_queue.hpp"
#endif
