#pragma once
#include <vector>
#include "PlayField.h"

using namespace std;

class TreeNode
{
public:
	TreeNode(PlayField newField, TreeNode* newTreeNode)
	{
		node = new Node{ newTreeNode, newField };
	}
	bool isTerminal(TreeNode) const;
	void addChild(TreeNode*, TreeNode*);
	TreeNode& operator[] (int) const;
	int childCount(TreeNode);
	const PlayField& value(TreeNode);
	int GetChild(TreeNode treeNode) { return childQty(treeNode); };
	
private:
	struct Node
	{
		TreeNode* treeNode;
		const PlayField field;
	};
	Node* node;
	int childQty(TreeNode) const;
	vector<TreeNode*> children;
};
