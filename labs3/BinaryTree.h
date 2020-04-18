 #pragma once
#include <iostream>
#include "TreeNode.h"

using namespace std;

class BinaryTree
{
public:
	BinaryTree()
	{
		head = new TreeNode(0);
	}
	BinaryTree(int value)
	{
		head = new TreeNode(value);
	}
	~BinaryTree();
	void Insert(int value);
	TreeNode* Search(int value);
	
private:
	TreeNode* head;
	void Insert(int value, TreeNode* node);
	TreeNode* Search(int value, TreeNode* node);
};

