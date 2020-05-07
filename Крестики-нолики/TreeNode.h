#pragma once
#include <iostream>
#include <vector>
#include "PlayField.h"

using namespace std;

class TreeNode
{
public:
	TreeNode(PlayField newField, TreeNode* newTreeNode)
	{
		field = newField;
		treeNode = newTreeNode;
	};
	bool isTerminal(TreeNode);
	void addChild(TreeNode*, TreeNode*);
	TreeNode& operator[] (int);
	int childCount(TreeNode);
	const PlayField& value(TreeNode);
	int GetChild(TreeNode treeNode) { return childQty(treeNode); };
	
private:
	int childQty(TreeNode);
	vector<TreeNode*> children;
	TreeNode* treeNode = nullptr;
	PlayField field;
};
