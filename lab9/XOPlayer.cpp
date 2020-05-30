#include "XOPlayer.h"
#include <cassert>

PlayField::Cells XOPlayer::selectPlayer() const
{
	if (player == PlayField::csNought)
		return PlayField::csCross;
	return PlayField::csNought;
}

void XOPlayer::makeMove(PlayField::CellPos iCell)
{
	assert(currentState()[iCell] == PlayField::csEmpty || currentState().checkFieldStatus() == PlayField::fsNormal);
	for (int i = 0; i < getCurrentTree().childCount(); i++)
	{
		if (getCurrentTree()[i].value()[iCell] != PlayField::Cells::csEmpty)
		{
			move = &getCurrentTree()[i];
			break;
		}
	}
	
}

void XOPlayer::makeMove()
{
	assert(currentState()[next] == PlayField::csEmpty || currentState().checkFieldStatus() == PlayField::fsNormal);
	for (int i = 0; i < getCurrentTree().childCount(); i++)
	{
		if (getCurrentTree()[i].value()[next] != PlayField::Cells::csEmpty)
		{
			move = &getCurrentTree()[i];
			break;
		}
	}
}

PlayField XOPlayer::currentState() const
{
	if (move)
		return move->value();
	return treeNode.value();
}

PlayField::Status XOPlayer::fieldStatus() const
{
	return currentState().checkFieldStatus();
}

const TreeNode& XOPlayer::getCurrentTree() const
{
	if (move)
		return *move;
	return treeNode;
}
