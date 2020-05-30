#pragma once
#include "TreeNode.h"

class XOPlayer
{
public:
	XOPlayer(TreeNode& newTreeNode, PlayField::Cells sel_player): treeNode(newTreeNode), player(sel_player){}
	PlayField::Cells selectPlayer() const;
	void makeMove(PlayField::CellPos iCell);
	void makeMove();
	PlayField currentState() const;
	PlayField::Status fieldStatus() const;
	const TreeNode& getCurrentTree() const;
	
private:
	const TreeNode& treeNode;
	TreeNode* move;
	const PlayField::Cells player;
};
