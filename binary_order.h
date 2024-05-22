#ifndef BINARY_ORDER_H_
#define BINARY_ORDER_H_

#include "Custom_tree.h"
#include <typeinfo>

template<typename TYPE, template<typename>class TREE, typename FN>
void Preorder(TREE<TYPE> & tree, FN fn)
{
	if(typeid(TREE<TYPE>) == typeid(BinaryTree<TYPE>) || typeid(TREE<TYPE>) == typeid(BStree<TYPE>))
	{
		Preorder_trigger(tree.root, fn);
	}
}

template<typename NODE, typename FN>
void Preorder_trigger(NODE node, FN fn)
{
	if(node == NULL)
		return;
	else
	{
		fn(node->key);
		Preorder_trigger(node->L_node, fn);
		Preorder_trigger(node->R_node, fn);
	}
}

template<typename TYPE, template<typename>class TREE, typename FN, typename PM1>
void Preorder(TREE<TYPE> & tree, FN fn, PM1 pm1)
{
	if(typeid(TREE<TYPE>) == typeid(BinaryTree<TYPE>) || typeid(TREE<TYPE>) == typeid(BStree<TYPE>))
	{
		Preorder_trigger(tree.root, fn, pm1);
	}
}

template<typename NODE, typename FN, typename PM1>
void Preorder_trigger(NODE node, FN fn, PM1 pm1)
{
	if(node == NULL)
		return;
	else
	{
		fn(node->key, pm1);
		Preorder_trigger(node->L_node, fn, pm1);
		Preorder_trigger(node->R_node, fn, pm1);
	}
}

template<typename TYPE, template<typename>class TREE, typename FN, typename PM1, typename PM2>
void Preorder(TREE<TYPE> & tree, FN fn, PM1 pm1, PM2 pm2)
{
	if(typeid(TREE<TYPE>) == typeid(BinaryTree<TYPE>) || typeid(TREE<TYPE>) == typeid(BStree<TYPE>))
	{
		Preorder_trigger(tree.root, fn, pm1, pm2);
	}
}

template<typename NODE, typename FN, typename PM1,typename PM2>
void Preorder_trigger(NODE node, FN fn, PM1 pm1, PM2 pm2)
{
	if(node == NULL)
		return;
	else
	{
		fn(node->key, pm1, pm2);
		Preorder_trigger(node->L_node, fn, pm1, pm2);
		Preorder_trigger(node->R_node, fn, pm1, pm2);
	}
}

template<typename TYPE, template<typename>class TREE, typename FN>
void Inorder(TREE<TYPE> & tree, FN fn)
{
	if(typeid(TREE<TYPE>) == typeid(BinaryTree<TYPE>) || typeid(TREE<TYPE>) == typeid(BStree<TYPE>))
	{
		Inorder_trigger(tree.root, fn);
	}
}

template<typename NODE, typename FN>
void Inorder_trigger(NODE node, FN fn)
{
	if(node == NULL)
		return;
	else
	{
		Inorder_trigger(node->L_node, fn);
		fn(node->key);
		Inorder_trigger(node->R_node, fn);
	}
}

template<typename TYPE, template<typename>class TREE, typename FN>
void Postorder(TREE<TYPE> & tree, FN fn)
{
	if(typeid(TREE<TYPE>) == typeid(BinaryTree<TYPE>) || typeid(TREE<TYPE>) == typeid(BStree<TYPE>))
	{
		Postorder_trigger(tree.root, fn);
	}
}

template<typename NODE, typename FN>
void Postorder_trigger(NODE node, FN fn)
{
	if(node == NULL)
		return;
	else
	{
		Postorder_trigger(node->L_node, fn);
		Postorder_trigger(node->R_node, fn);
		fn(node->key);
	}
}
#endif
