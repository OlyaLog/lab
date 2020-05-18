#pragma once
#include <vector>
#include "PlayField.h"

using namespace std;

class TreeNode
{
public:
	TreeNode(PlayField newField, TreeNode* newTreeNode): treeNode(newTreeNode), field(newField){}
	bool isTerminal(TreeNode) const;
	void addChild(TreeNode*, TreeNode*);
	TreeNode& operator[] (int) const;
	int childCount(TreeNode);
	const PlayField& value(TreeNode);
	int GetChild(TreeNode treeNode) { return childQty(treeNode); };
	
private:
	TreeNode* treeNode;
	const PlayField field;
	int childQty(TreeNode) const;
	vector<TreeNode*> children;
};
