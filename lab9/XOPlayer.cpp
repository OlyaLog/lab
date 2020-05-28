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
	for (int i = 0; i < treeNode->childCount(); i++)
	{
		if (treeNode->operator[](i).value()[iCell] != PlayField::Cells::csEmpty)
		{
			treeNode = &treeNode->operator[](i);
			break;
		}
	}
}

void XOPlayer::makeMove()
{
	assert(currentState()[next] == PlayField::csEmpty || currentState().checkFieldStatus() == PlayField::fsNormal);
	for (int i = 0; i < treeNode->childCount(); i++)
	{
		if (treeNode->operator[](i).value()[next] != PlayField::Cells::csEmpty)
		{
			treeNode = &treeNode->operator[](i);
			break;
		}
	}
}

PlayField XOPlayer::currentState() const
{
	return treeNode->value();
}

PlayField::Status XOPlayer::fieldStatus() const
{
	return currentState().checkFieldStatus();
}
