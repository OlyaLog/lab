#include "TreeNode.h"
#include <cassert>

TreeNode::TreeNode(PlayField newField, TreeNode* newTreeNode): parent(newTreeNode), field(newField)
{
	if (parent)
		parent->addChild(this);
}

TreeNode::~TreeNode()
{
	for (unsigned int i = 0; i < this->children.size(); i++)
		delete children[i];
}

bool TreeNode::isTerminal() const
{
	const PlayField::Status fieldStatus = field.checkFieldStatus();
	return fieldStatus == PlayField::fsCrossesWin || fieldStatus == PlayField::fsNoughtsWin || fieldStatus == PlayField::fsDraw;
}

void TreeNode::addChild(TreeNode* child)
{
	assert(this->childCount() < this->childQty());
	child->parent = this;
	this->children.push_back(child);
}

TreeNode& TreeNode::operator[](int pos) const
{
	return *children[pos];
}

int TreeNode::childCount() const
{
	return children.size();
}

const PlayField& TreeNode::value() const
{
	return field;
}

int TreeNode::childQty() const
{
	if (this->parent)
		return this->parent->childQty() - 1;
	return PlayField::fieldSize * PlayField::fieldSize;
}
