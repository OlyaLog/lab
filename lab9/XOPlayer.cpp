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
	assert(currentState().checkFieldStatus() == PlayField::fsNormal);
	double max = 0;
	int child = 0;
	for (int i = 0; i < getCurrentTree().childCount(); i++)
	{
		const double crossWin = getCurrentTree()[i].result.crossWinCount;
		const double noughtWin = getCurrentTree()[i].result.noughtWinCount;
		const double draw = getCurrentTree()[i].result.drawCount;
		if (selectPlayer() == PlayField::csCross)
		{
			const double count = (crossWin + draw) / (crossWin + noughtWin + draw);
			if (count > max)
			{
				max = count;
				child = i;
			}
		}
		else
		{
			const double count = (noughtWin + draw) / (crossWin + noughtWin + draw);
			if (count > max)
			{
				max = count;
				child = i;
			}
		}
	}
	move = &getCurrentTree()[child];
}

PlayField XOPlayer::currentState() const
{
	return getCurrentTree().value();
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
