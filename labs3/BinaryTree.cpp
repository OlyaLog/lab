#include "BinaryTree.h"

BinaryTree::~BinaryTree()
{
	head = nullptr;
}

void BinaryTree::Insert(int value)
{
	if (head == nullptr)
		head = new TreeNode(value);
	else
		Insert(value, this->head);
}

TreeNode* BinaryTree::Search(int value)
{
	if (head->getValue() == value)
		return head;
	Search(value, head);
}

void BinaryTree::Insert(int value, TreeNode * node)
{
	if (node->getValue() <= value)
	{
		if (node->getRight() != nullptr)
			Insert(value, node->getRight());
		else 
		{
			node->addRight(new TreeNode(value));
		}
	}
	else 
	{
		if (node->getLeft() != nullptr)
			Insert(value, node->getLeft());
		else 
		{
			node->addLeft(new TreeNode(value));
		}
	}
}

TreeNode* BinaryTree::Search(int value, TreeNode * node)
{
	if (node->getValue() == value)
		return node;
	if (node->getValue() < value)
	{
		if (node->getRight() != nullptr)
			Search(value, node->getRight());
	}
	else
	{
		if (node->getLeft() != nullptr)
			Search(value, node->getLeft());
	}
}
