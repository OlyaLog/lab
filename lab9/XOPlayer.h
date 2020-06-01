#pragma once
#include "TreeNode.h"
#include <cassert>

class XOPlayer
{
public:
	XOPlayer(TreeNode& newTreeNode, PlayField::Cells sel_player): treeNode(newTreeNode), player(sel_player)
	{
		assert(player != PlayField::csEmpty);
	}
	PlayField::Cells selectPlayer() const;
	void makeMove(PlayField::CellPos iCell);
	void makeMove();
	const PlayField& currentState() const;
	PlayField::Status fieldStatus() const;
	const TreeNode& getCurrentTree() const;
	
private:
	const TreeNode& treeNode;
	TreeNode* move;
	const PlayField::Cells player;
};
