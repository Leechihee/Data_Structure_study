#ifndef CUSTOM_LIST_H_
#define CUSTOM_LIST_H_

#include <iostream>
#include <string>

namespace {using namespace std;}

template <typename T>
class List{
	typedef struct Data{
		T data;
		struct Data* next;
	} node;
	node * head;
	int count;
// INDEX는 1부터 시작
public:
	T test(int pos);
	// 생성자, 파괴자
	List(); // 생성자
	List(const List & L); // 복사생성자
	~List(); // 파괴자
	// 리스트 수정 메서드
	void Insert(int pos,const T item); // pos 위치에 item 삽입 / 첫 삽입시 무조권 0부터 삽입
	void Delete(int pos); // pos 위치에 있는 데이터 삭제
	void Sort(int start, int end); // start에서 end까지 데이터를 오름차순으로 정렬
	int FindOrAdd(T item); // 리스트에 item 값이 있으면 인덱스 리턴, 아니라면 item 값 삽입
	void Swap(int pos1, int pos2); // pos1 위치와 pos2 위치를 서로 바꿈
	void NodeSwap(int pos); // pos와 pos 다음 노드의 위치를 스왑, pos가 마지막 노드라면 그 전 노드와 위치를 스왑
	void nChenge(int pos,const List & source); // pos 위치에서 source 리스트 크기까지 source 리스트로 바꿈
	// 리스트 출력 메서드
	void show() const; // 모든 정보 스크린 출력
	T& ReturnData(int pos) const; // pos 위치에 있는 리턴
	int FindData(T target) const; // targat 값을 저장 하고 있는 인덱스 리턴 없다면 -1 리턴
	bool isEmpty() const {return (count == 0);} // 리스트가 비어있는지 확인 / 비어있다면 TRUE 아니라면 FALSE 
	bool isSorted() const; // 리스트가 정렬되어있으면 true, 아니라면 false
	int Begin() const {return 1;} // 리스트 시작점 리턴
	int End() const {return count;} // 리스트 끝점 리턴
	int Size() const {return count;} // 리스트에 저장된 데이터 개수 출력
	// 연산자 오버로딩
	void operator=(const List<T> & L); // 복사생성자와 동일
	T& operator[](const int index); // index 접근 연산자
	//프렌드 함수;
	template<typename A> friend List<A> ReverseCopy(const List<A> & L); // 리스트에 저장된 데이터를 뒤집고 복사 후 리스트 리턴
	template<typename B> friend List<B> MergeAndSort(const List<B> & L1, const List<B> & L2); // 정렬된 두 리스트를 병합, 재정렬 후 리스트 리턴
};

#include "Custom_list.hpp"
#endif
