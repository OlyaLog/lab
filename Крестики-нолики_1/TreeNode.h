#pragma once
#include <vector>
#include "PlayField.h"

class TreeNode
{
public:
	TreeNode(PlayField newField, TreeNode* newTreeNode): parent(newTreeNode), field(newField){}
	~TreeNode();
	bool isTerminal() const;
	void addChild(TreeNode*);
	TreeNode& operator[] (int) const;
	int childCount() const;
	const PlayField& value() const;
	
private:
	const TreeNode* parent;
	const PlayField field;
	int childQty() const;
	std::vector<TreeNode*> children;
};
