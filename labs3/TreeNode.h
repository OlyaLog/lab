#pragma once
#include <iostream>

using namespace std;

class TreeNode
{
public:
	TreeNode()
	{
		value = 0;
		left = nullptr;
		right = nullptr;
	}
	TreeNode(int newValue)
	{
		value = newValue;
		left = nullptr;
		right = nullptr;
	}
	int getValue() { return value; }
	TreeNode* getLeft() { return left; }
	TreeNode* getRight() { return right; }
	void addValue(int newValue);
	void addLeft(TreeNode* newLeft);
	void addRight(TreeNode* newRight);
	
private:
	int value;
	TreeNode* left;
	TreeNode* right;
};

