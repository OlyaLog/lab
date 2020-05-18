#include "TreeNode.h"
#include "PlayField.h"
#include <iostream>
#include <vector>

using namespace std;

bool TreeNode::isTerminal(TreeNode treeNode) const
{
	return childQty(treeNode) == 0 || treeNode.field.checkFieldStatus() != PlayField::fsNormal;
}

void TreeNode::addChild(TreeNode* treeNode, TreeNode* child)
{
	assert(childQty(*treeNode) != 0);
	child->treeNode = treeNode;
	TreeNode tree = *treeNode;
	tree.children.push_back(child);
}

TreeNode& TreeNode::operator[](int pos) const
{
	return *children[pos];
}

int TreeNode::childCount(TreeNode treeNode)
{
	return treeNode.children.size();
}

const PlayField& TreeNode::value(TreeNode treeNode)
{
	return treeNode.field;
}

int TreeNode::childQty(TreeNode treeNode) const
{
	return treeNode.field.getEmptyCells().size();
}
