#include "TreeNode.h"
#include "PlayField.h"
#include <iostream>
#include <vector>

using namespace std;

TreeNode::~TreeNode()
{
	for (unsigned int i = 0; i < this->children.size(); i++)
	{
		delete children[i];
	}
}

bool TreeNode::isTerminal() const
{
	return this->field.checkFieldStatus() == PlayField::fsCrossesWin || this->field.checkFieldStatus() == PlayField::fsNoughtsWin || this->field.checkFieldStatus() == PlayField::fsDraw;
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
	return this->children.size();
}

const PlayField& TreeNode::value() const
{
	return this->field;
}

int TreeNode::childQty() const
{
	if (!this->parent)
		return PlayField::fieldSize * PlayField::fieldSize;;
	return this->parent->childQty() - 1;
}
