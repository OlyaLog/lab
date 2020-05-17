#pragma once
#include <vector>
#include "PlayField.h"

using namespace std;

class TreeNode
{
public:
	TreeNode(PlayField* newField, TreeNode* newTreeNode)
	{
		field = newField;
		treeNode = newTreeNode;
	};
	bool isTerminal(TreeNode) const;
	void addChild(TreeNode*, TreeNode*);
	TreeNode& operator[] (int) const;
	int childCount(TreeNode);
	const PlayField& value(TreeNode);
	int GetChild(TreeNode treeNode) { return childQty(treeNode); };

private:
	int childQty(TreeNode) const;
	vector<TreeNode*> children;
	TreeNode* treeNode = nullptr;
	const PlayField* field;
};
