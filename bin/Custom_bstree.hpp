#ifndef CUSTOM_BSTREE_HPP_
#define CUSTOM_BSTREE_HPP_

#include <iostream>
#include <string>
#include "Custom_list.h"

namespace 
{
	using namespace std;
	const string Not_Find = "를 찾을 수 없습니다.";
}

// BStree private method
template<typename A>
typename BStree<A>::node* BStree<A>::moveNode(node* target ,A key)
{
	if(key < target->key)
		target = target->L_node;
	else
		target = target->R_node;
	return target;
}

template<typename A>
typename BStree<A>::node* BStree<A>::NodeSearch(const A Key)
{
	node* temp = root;
	while(temp != NULL)
	{
		if(Key == temp->key)
			return temp;
		else
			temp = moveNode(temp, Key);
	}
	throw Not_Find;
	return NULL;
}

// BStree public method
// 레코드 수정 메서드
template<typename A>
BStree<A>::BStree()
{
	root = NULL;
}

template<typename A>
BStree<A>::BStree(BStree & T)
{
	root = NULL;
	List<A> temp;
	T.TreeToList(temp, 'n');
	for(int i=1;i<=10;i++)
		Insert(temp[i]);
}

template<typename A>
BStree<A>::~BStree()
{
	AllDelete(root);
}

template<typename A>
void BStree<A>::Insert(const A Key)
{
	if(root == NULL)
	{
		root = new node;
		root->key = Key;
		root->L_node = NULL;
		root->R_node = NULL;
		return;
	}
	node* target = root,* parent = root;
	while(parent != NULL)
	{
		if(parent->key == Key)
		{
			cout << "Insert() : " << Key << " 중복이 있어 삽입을 거부합니다.\n";
			return;
		}
		target = moveNode(target,Key);
		if(target == NULL)
			break;
		else
			parent = moveNode(parent,Key);
	}
	target = new node;
	target->key = Key;
	target->L_node = NULL;
	target->R_node = NULL;
	if(Key < parent->key)
		parent->L_node = target;
	else
		parent->R_node = target;
}

template<typename A>
void BStree<A>::Delete(const A Key)
{
	node* target = root,* temp = NULL,* parent = root;
	try
	{
		target = NodeSearch(Key);
		while(parent->L_node != target && parent->R_node != target && target != root)
			parent = moveNode(parent,Key);
	}
	catch(string ERO_CORD)
	{
		cout << "Delete() : " << Key << ERO_CORD << endl;
		return;
	}
	if(target->L_node == NULL && target->R_node == NULL)
	{
		if(Key < parent->key)
			parent->L_node = NULL;
		else
			parent->R_node = NULL;
	}
	else if(target->L_node == NULL && target->R_node != NULL && target != root)
	{
		if(Key < parent->key)
			parent->L_node = target->R_node;
		else
			parent->R_node = target->R_node;
	}
	else if(target->R_node == NULL && target->L_node != NULL && target != root)
	{
		if(Key < parent->key)
			parent->L_node = target->L_node;
		else
			parent->R_node = target->L_node;
	}
	else
	{
		if(target->R_node == NULL)
		{
			parent = target->L_node;
			temp = parent;
			if(temp->R_node == NULL)
			{
				target->key = temp->key;
				target->L_node = temp->L_node;
				delete(temp);
				return;
			}
			else
			{
				while(temp->R_node != NULL)
					temp = temp->R_node;
				while(parent->R_node != temp)
					parent = parent->R_node;
				target->key = temp->key;
				parent->R_node = temp->R_node;
				target = temp;
			}
		}
		else
		{
			parent = target->R_node;
			temp = parent;
			if(temp->L_node == NULL)
			{
				target->key = temp->key;
				target->R_node = temp->R_node;
				delete(temp);
				return;
			}
			else
			{
				while(temp->L_node != NULL)
					temp = temp->L_node;
				while(parent->L_node != temp)
					parent = parent->L_node;
				target->key = temp->key;
				parent->L_node = temp->L_node;
				target = temp;
			}
		}
	}
	delete target;
}

template<typename A>
void BStree<A>::DeleteMin()
{
	Delete(Minimum());
}

void sum(int& num1, const int num2)
{
	num1 += num2;
}

template<typename A>
void BStree<A>::IncrementData(const int num)
{
	Preorder(*this, sum, num);
}

// 메서드 리턴 메서드
template<typename A>
bool BStree<A>::KeySearch(const A Key)
{
	node* temp = root;
	while(temp != NULL)
	{
		if(Key == temp->key)
			return true;
		else
			temp = moveNode(temp, Key);
	}
	cout << "KeySearch() : " << Key << "를 찾을 수 없습니다.\n";
	return false;
}

template<typename A>
A BStree<A>::Minimum()
{
	node* temp = root;
	while(temp->L_node != NULL)
		temp = temp->L_node;
	return temp->key;
}

template<typename A>
A BStree<A>::Maximum()
{
	node* temp = root;
	while(temp->R_node != NULL)
		temp = temp->R_node;
	return temp->key;
}

template<typename A>
int BStree<A>::Size()
{
	return Size_trigger(root);
}

template<typename A>
int BStree<A>::ComputeHeights()
{
	return ComputeHeights_trigger(root);
}

template<typename A>
void BStree<A>::TreeToList(List<A> & LIST, const char mode)
{
	TreeToList_trigger(root,LIST, mode);
}

template<typename A>
int equal(const A data, const A target, int mo);

template<typename A>
int equal(const A data, A target, int mo)
{
	static int Count = 0;
	int temp;
	if(mo == 1)
	{
		temp = Count;
		Count = 0;
		return temp;
	}
	if(data == target)
		Count++;
	return -1;
}

template<typename A>
int BStree<A>::CountData(const A Key)
{
	Preorder(*this, equal<A>, Key, 0);
	return equal(0,0,1);
}

template<typename A>
void BStree<A>::DescendingOrder()
{
	DescendingOrder_trigger(root);
}

template<typename A>
int BStree<A>::CountSemi()
{
	return CountSemi_trigger(root);
}

template<typename NODE>
int Size_trigger(NODE node)
{
	int size = 1;
	if(node == NULL)
		return 0;
	else
	{
		size += Size_trigger(node->L_node);
		size += Size_trigger(node->R_node);
	}
	return size;
}

template<typename A>
typename BStree<A>::node* BStree<A>::AllDelete(node* Node)
{
	if(Node != root)
	{
		if(Node->L_node != NULL)
			Node->L_node = AllDelete(Node->L_node);
		if(Node->R_node != NULL)
			Node->R_node = AllDelete(Node->R_node);
	}
	delete(Node);
	return NULL;
}

template<typename A>
int ComputeHeights_trigger(A node)
{
	int L_Heights = 0, R_Heights = 0;
	if(node->L_node == NULL)
		L_Heights = -1;
	else
		L_Heights = ComputeHeights_trigger(node->L_node);
	if(node->R_node == NULL)
		R_Heights = -1;
	else
		R_Heights = ComputeHeights_trigger(node->R_node);
	return (L_Heights<=R_Heights ? R_Heights : L_Heights) + 1;
}

template<typename A, typename B>
void TreeToList_trigger(A node, B& LIST, const char mode)
{
	if(node == NULL)
		return;
	else if(mode == 's')
	{
		TreeToList_trigger(node->L_node, LIST, mode);
		LIST.InsertEnd(node->key);
		TreeToList_trigger(node->R_node, LIST, mode);
	}
	else
	{
		LIST.InsertEnd(node->key);
		TreeToList_trigger(node->L_node, LIST, mode);
		TreeToList_trigger(node->R_node, LIST, mode);
	}
}

template<typename A>
void IncrementData_trigger(A Node,const int num)
{
	if(Node == NULL)
		return;
	Node->key += num;
	if(Node->L_node != NULL)
		IncrementData_trigger(Node->L_node, num);
	if(Node->R_node != NULL)
		IncrementData_trigger(Node->R_node, num);
}

template<typename A>
void DescendingOrder_trigger(A node)
{
	if(node == NULL)
		return;
	else
	{
		DescendingOrder_trigger(node->R_node);
		cout << node->key << " ";
		DescendingOrder_trigger(node->L_node);
	}
}

template<typename A>
int CountSemi_trigger(A node)
{
	if(node == NULL)
		return 0;
	int test = node->key, count = 0;
	if(node->L_node == NULL && node->R_node == NULL)
		return 0;
	else if(node->L_node == NULL || node->R_node == NULL)
		count = 1 + CountSemi_trigger(node->L_node) + CountSemi_trigger(node->R_node);
	else
		count = CountSemi_trigger(node->L_node) + CountSemi_trigger(node->R_node);
	return count;
}
#endif
