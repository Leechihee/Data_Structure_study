#ifndef CUSTOM_STACK_H_
#define CUSTOM_STACK_H_

#include <iostream>

template<typename A>
class Stack{
	class node{
	public:
		A data;
		class node* next;
	};
	node * head;
	int max;
	int count;
public:
	//생성자 및 파괴자
	Stack(int); // 생성자 매개변수로 스택의 최대치를 지정
	Stack(const Stack &); // 복사 생성자
	~Stack(); // 파괴자
	// 스택 수정 메서드
	void Push(const A & item); // 스택에 item을 삽입
	A Pop(); // 스택탑에 있는 item 삭제 및 리턴
	// 스택 출력 메서드
	A GetTop(); // 스택탑에 있는 item 리턴
	int FindItem(const A & item); // 스택에 있는 item 개수를 리턴
	int Size() const {return count;} // 스택 count 리턴
	bool isEmpty() const {return(count==0);} // 스택이 비어있는지 확인, 비어있으면 true 아니라면 false
	bool isFull() const {return(count==max);} // 스택이 가득 차있는지 확인, 가득 차있으면 true 아니라면 false
	//프렌드 함수
	template<typename F>
	friend void RecurseStack(Stack<F> & S); //스택 S에 있는 데이터를 역순으로 출력
};

#include "Custom_stack.hpp"
#endif
