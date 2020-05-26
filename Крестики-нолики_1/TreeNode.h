#pragma once
#include "PlayField.h"

class TreeNode
{
public:
	TreeNode(PlayField newField, TreeNode* newTreeNode);
	~TreeNode();
	bool isTerminal() const;
	void addChild(TreeNode*);
	TreeNode& operator[] (int) const;
	int childCount() const;
	const PlayField& value() const;

private:
	TreeNode* parent;
	const PlayField field;
	int childQty() const;
	std::vector<TreeNode*> children;
};

