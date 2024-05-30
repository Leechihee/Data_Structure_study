#ifndef CUSTOM_BINARYTREE_HPP_
#define CUSTOM_BINARYTREE_HPP_

#include <iostream>
#include "Custom_tree.h"

namespace 
{
	using namespace std;
	const char NOT_FIND[] = "를 찾을 수 없습니다.";
}

//BinaryTree private
template<typename B>
typename BinaryTree<B>::node* BinaryTree<B>::MoveNode(node* Node, char direction)
{
	if(direction == 'l' || direction == 'L')
		return Node->L_node;
	else
		return Node->R_node;
}

template<typename B>
typename BinaryTree<B>::node* BinaryTree<B>::ParentNodeSearch(node* Node, const B Key)
{
	node* target = NULL;
	if(root->key == Key)
		return Node;
	else if(Node == NULL)
		return 0;
	else
	{
		if(Node->L_node != NULL && Node->L_node->key == Key)
			return Node;
		else if(Node->R_node != NULL && Node->R_node->key == Key)
			return Node;
		else
		{
			if(Node->L_node != NULL)
				target = ParentNodeSearch(Node->L_node, Key);
			if(target == NULL && Node->R_node != NULL)
				target = ParentNodeSearch(Node->R_node, Key);
		}
		return target;
	}
}

//BinaryTree public method
// 생성자 & 파괴자
template<typename B>
BinaryTree<B>::BinaryTree()
{
	root = NULL;
}

template<typename B>
BinaryTree<B>::~BinaryTree()
{
	AllDelete(root);
}

template<typename B>
typename BinaryTree<B>::node* BinaryTree<B>::AllDelete(node* Node)
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

// 레코드 수정 메서드
template<typename B>
void BinaryTree<B>::Insert(const B Key)
{
	if(root == NULL)
	{
		root = new node;
		root->key = Key;
		root->L_node = NULL;
		root->R_node = NULL;
	}
	else
	{
		node* ancestor = root,* parent = root,* target = NULL;
		while(1)
		{
			if(parent->L_node == NULL || parent->R_node == NULL)
				break;
			else if(parent->L_node != NULL && parent->L_node->R_node == NULL)
				parent = parent->L_node;
			else if(parent->R_node != NULL && parent->R_node->R_node == NULL)
				parent = parent->R_node;
			else if(parent->R_node != NULL && parent->R_node->R_node != NULL)
			{
				ancestor = parent;
				parent = parent->L_node;
			}
			else
				parent = ancestor->R_node;
		}
		target = new node;
		target->key = Key;
		target->L_node = NULL;
		target->R_node = NULL;
		if(parent->L_node == NULL)
			parent->L_node = target;
		else
			parent->R_node = target;
	}
}

template<typename B>
void BinaryTree<B>::Delete(const B Key)
{
	node* parent = NULL,* target = NULL;
	try
	{
		parent = ParentNodeSearch(root, Key);
		if(parent == NULL)
			throw NOT_FIND;
	}
	catch(const char* ERO_CORD)
	{
		cout << "Delete() : "<< Key << ERO_CORD << endl;
		return;
	}
	char dir;
	if(parent->L_node != NULL && parent->L_node->key == Key)
	{
		target = parent->L_node;
		dir = 'l';
	}
	else if(parent->R_node != NULL && parent->R_node->key == Key)
	{
		target = parent->R_node;
		dir = 'r';
	}
	else
	{
		target = root;
		if(target->R_node != NULL)
			dir = 'r';
		else
			dir = 'l';
	}
	if(target->L_node == NULL && target->R_node == NULL)
	{
		if(dir == 'l')
			parent->L_node = NULL;
		else
			parent->R_node = NULL;
	}
	else if (target->L_node == NULL)
	{
		if(dir == 'l')
			parent->L_node = target->R_node;
		else
			parent->R_node = target->R_node;
	}
	else if (target->R_node == NULL)
	{
		if(dir == 'l')
			parent->L_node = target->L_node;
		else
			parent->R_node = target->L_node;
	}
	else
	{
		while(target->L_node != NULL && target->R_node != NULL)
		{
			if(target->L_node != NULL)
			{
				target->key = target->L_node->key;
				parent = target;
				target = parent->L_node;
				dir = 'l';
			}
			else
			{
				target->key = target->R_node->key;
				parent = target;
				target = parent->R_node;
				dir = 'r';
			}
		}
		if(dir == 'l')
			parent->L_node = NULL;
		else
			parent->R_node = NULL;
	}
	delete(target);
}

//레코드 리턴 메서드
template<typename B>
bool BinaryTree<B>::KeySearch(const B Key)
{
	return KeySearch_tigger(root, Key);
}

template<typename NODE, typename B>
bool KeySearch_tigger(NODE node, const B Key)
{
	bool L_find, R_find;
	if(node == NULL)
		return false;
	else if(node->key == Key)
		return true;
	else
	{
		L_find = KeySearch_tigger(node->L_node, Key);
		R_find = KeySearch_tigger(node->R_node, Key);
	}
	return (L_find || R_find) ? true : false;
}

template<typename B>
B BinaryTree<B>::Maximum()
{
	return Maximum_trigger(root);
}

template<typename B>
B Max(const B target1, const B target2)
{
	return (target1 < target2) ? target2 : target1;
}

template<typename NODE, typename B>
B Maximum_trigger(NODE node)
{
	if(node == NULL)
		return -1;
	else
		return Max(node->key,Max(Maximum_trigger(node->L_node), Maximum_trigger(node->R_node)));
}

template<typename B>
int BinaryTree<B>::Size()
{
	return Size_trigger(root);
}

#endif
