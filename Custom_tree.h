#ifndef CUSTOM_TREE_H_
#define CUSTOM_TREE_H_

#include "Custom_list.h"

template<typename A>
class BStree{ // Binary Search Tree
	class node{
	public:
		A key;
		class node* L_node;
		class node* R_node;
	};
	node * root;
	node* moveNode(node* target ,A key);
	node* AllDelete(node* Node);
	node* NodeSearch(const A Key);
public:
	// 생성자 & 파괴자
	BStree(); // 생성자
	BStree(BStree & T); // 복사생성자
	~BStree(); // 파괴자
	// 레코드 수정 메서드
	bool KeySearch(const A key); // key를 가진 레코드를 찾고 찾았다면 key값 리턴, 없다면 "Key를 찾을 수 없습니다" 출력
	void Insert(const A key); // key 값을 트리 안으로 삽입, 중복 키일 경우 삽입 거부
	void Delete(const A key); // key 값을 찾은 후 삭제, 없다면 "Key를 찾을 수 없습니다" 출력
	void DeleteMin(); // 해당 트리 값 중 가장 작은 값을 삭제
	void IncrementData(const int num); // 해당 트리 전체 키 값에 num 만큼 증가
	// 레코드 리턴 메서드
	A Minimum(); // 해당 트리 키 값 중 가장 작은 값을 리턴
	A Maximum(); // 해당 트리 키 값 중 가장 큰 값을 리턴
	int Size(); // 해당 트리 내부의 노드 개수를 리턴
	int ComputeHeights(); // 해당 트리 높이 계산
	void TreeToList(List<A> & cont, const char mode = 's'); // 매개변수로 전달된 리스트에 해당 트리 키 값을 삽입 / mode 미입력시 sort, 입력시 notsort
	int CountData(const A Key); // 해당 트리 키 값 중 매개변수 key와 같은 키 값 개수를 카운트 후 리턴
	void DescendingOrder(); // 해당 트리 키 값을 내림차순으로 출력
	int CountSemi(); // 해당 트리 노드 중 세미노드의 개수를 출력
	// 순회 함수
	template<typename TYPE, template<typename>class TREE, typename FN>
	friend void Preorder(TREE<TYPE> & tree, FN fn);
	template<typename TYPE, template<typename>class TREE, typename FN, typename PM1>
	friend void Preorder(TREE<TYPE> & tree, FN fn, PM1 pm1);
	template<typename TYPE, template<typename>class TREE, typename FN, typename PM1, typename PM2>
	friend void Preorder(TREE<TYPE> & tree, FN fn, PM1 pm1, PM2 pm2);
	template<typename TYPE, template<typename>class TREE, typename FN>
	friend void Inorder(TREE<TYPE> & tree, FN fn);
	template<typename TYPE, template<typename>class TREE, typename FN>
	friend void Postorder(TREE<TYPE> & tree, FN fn);
};

template<typename B>
class BinaryTree{
	class node{
	public:
		B key;
		class node* L_node;
		class node* R_node;
	};
	node* root;
	node* MoveNode(node* Node, char direction = 'l');
	node* ParentNodeSearch(node* Node, const B Key);
	node* AllDelete(node* Node);
public:
	// 생성자 & 파괴자
	BinaryTree(); // 생성자
	~BinaryTree(); // 파괴자
	// 레코드 수정 메서드
	void Insert(const B Key);
	void Delete(const B Key);
	// 레코드 리턴 메서드
	bool KeySearch(const B Key);
	B Maximum();
	int Size();
	// 순회 함수
	template<typename TYPE, template<typename>class TREE, typename FN>
	friend void Preorder(TREE<TYPE> & tree, FN fn);
};

#include "binary_order.h"
#include "Custom_bstree.hpp"
#include "Custom_binarytree.hpp"
#endif
