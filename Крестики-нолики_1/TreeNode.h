#pragma once
#include <vector>
#include "PlayField.h"

class TreeNode
{
public:
	TreeNode(PlayField newField, TreeNode* newTreeNode): parent(newTreeNode), field(newField){}
	~TreeNode()
	{
		this->children.clear();
	}
	bool isTerminal(TreeNode) const;
	void addChild(TreeNode*);
	TreeNode& operator[] (int) const;
	int childCount(TreeNode) const;
	const PlayField& value(TreeNode) const;
	
private:
	const TreeNode* parent;
	const PlayField field;
	int childQty() const;
	std::vector<TreeNode*> children;
};
