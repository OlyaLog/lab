#include "TreeNode.h"

void TreeNode::addValue(int newValue)
{
	value = newValue;
}

void TreeNode::addLeft(TreeNode * newLeft)
{
	if (!newLeft)
		return;
	left = newLeft;
}

void TreeNode::addRight(TreeNode * newRight)
{
	if (!newRight)
		return;
	right = newRight;
}
