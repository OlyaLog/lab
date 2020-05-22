#include "TreeNode.h"
#include "PlayField.h"
#include <iostream>
#include <vector>

using namespace std;

bool TreeNode::isTerminal(TreeNode treeNode) const
{
	return treeNode.field.checkFieldStatus() == PlayField::fsCrossesWin || treeNode.field.checkFieldStatus() == PlayField::fsNoughtsWin || treeNode.field.checkFieldStatus() == PlayField::fsDraw;
}

void TreeNode::addChild(TreeNode* child)
{
	assert(childCount(*this) < this->childQty());
	child->parent = this;
	this->children.push_back(child);
}

TreeNode& TreeNode::operator[](int pos) const
{
	return *children[pos];
}

int TreeNode::childCount(TreeNode treeNode) const
{
	return treeNode.children.size();
}

const PlayField& TreeNode::value(TreeNode treeNode) const
{
	return treeNode.field;
}

int TreeNode::childQty() const
{
	int childQ = PlayField::fieldSize * PlayField::fieldSize;
	if (this->parent != nullptr)
		childQ = this->parent->childQty() - 1;
	assert(childQ != this->field.getEmptyCells().size());
	return childQ;
}
