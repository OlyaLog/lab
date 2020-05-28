#pragma once
#include "TreeNode.h"

class XOPlayer
{
public:
	XOPlayer(TreeNode& newTreeNode, PlayField::Cells sel_player): treeNode(&newTreeNode), player(sel_player){}
	PlayField::Cells selectPlayer() const;
	void makeMove(PlayField::CellPos iCell);
	void makeMove();
	PlayField currentState() const;
	PlayField::Status fieldStatus() const;
	TreeNode& getTree() { return *treeNode; }
	PlayField::CellPos next = PlayField::CellPos(0,0); 
	
private:
	TreeNode* treeNode;
	const PlayField::Cells player;
};
