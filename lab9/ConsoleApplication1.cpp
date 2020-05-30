#include <iostream>
#include <string>
#include "XOPlayer.h"

using namespace std;

struct Result
{
	int noughtWinCount;
	int crossWinCount;
	int drawCount;

	Result& operator+=(const Result& ir)
	{
		noughtWinCount += ir.noughtWinCount;
		crossWinCount += ir.crossWinCount;
		drawCount += ir.drawCount;
		return *this;
	}
};

void drawCell(PlayField::Cells cell)
{
	switch (cell)
	{
	case PlayField::csNought:
		cout << " | O";
		break;
	case PlayField::csCross:
		cout << " | X";
		break;
	case PlayField::csEmpty:
		cout << " |  ";
		break;
	}
}

void drawField(PlayField playField)
{
	cout << " -------------" << endl;
	for (int i = 0; i < PlayField::fieldSize; i++)
	{
		for (int j = 0; j < PlayField::fieldSize; j++)
		{
			drawCell(playField[PlayField::CellPos(i, j)]);
		}
		cout << " | " << endl;
		cout << " -------------" << endl;
	}
}

void buildSubTree(TreeNode& treeNode)
{
	if (!treeNode.isTerminal())
	{
		const PlayField newField = treeNode.value();
		for (auto empty : newField.getEmptyCells())
		{
			PlayField move = newField;
			move.makeMove(empty);
			TreeNode* childNode = new TreeNode(move, &treeNode);
		}
	}
	for (int i = 0; i < treeNode.childCount(); i++)
			buildSubTree(treeNode[i]);
	
}

void walkTree(TreeNode& treeNode, Result& result)
{
	if (treeNode.childCount() == 0)
	{
		switch (treeNode.value().checkFieldStatus())
		{
		case PlayField::fsNoughtsWin:
			result.noughtWinCount++;
			break;
		case PlayField::fsCrossesWin:
			result.crossWinCount++;
			break;
		case PlayField::fsDraw:
			result.drawCount++;
			break;
		}
	}
	for (int i = 0; i < treeNode.childCount(); i++)
	{
		walkTree(treeNode[i], result);
	}
}

PlayField::CellPos nextMove (const TreeNode& treeNode, int child)
{
	for (int i = 0; i < PlayField::fieldSize; i++)
	{
		for (int j = 0; j < PlayField::fieldSize; j++)
		{
			if (treeNode.value()[PlayField::CellPos(i, j)] != treeNode[i].value()[PlayField::CellPos(i, j)])
				return PlayField::CellPos(i, j);
		}
	}
}

PlayField::CellPos maxWin(const TreeNode& treeRoot, PlayField::Cells cell)
{
	int max = 0;
	PlayField::CellPos next = PlayField::CellPos(0, 0);
	for (int i = 0; i < treeRoot.childCount(); i++)
	{
		Result result = { 0,0,0 };
		PlayField::CellPos next = PlayField::CellPos(0, 0);
		walkTree(treeRoot[i], result);
		if (cell == PlayField::csCross && result.crossWinCount > max)
		{
			max = result.crossWinCount;
			next = nextMove(treeRoot, i);
		}
		if (cell == PlayField::csNought && result.noughtWinCount > max)
		{
			max = result.crossWinCount;
			next = nextMove(treeRoot, i);
		}
	}
	return next;
}

void playerMove(XOPlayer& player)
{
	int x, y;
	cout << "Enter the line and column number (0-2)" << endl;
	cin >> x >> y;
	if (x < 0 || x > 2 || y < 0 || y > 2 || player.currentState()[PlayField::CellPos(x, y)] != PlayField::csEmpty)
	{
		cout << "Invalid number" << endl;
		playerMove(player);
	}
	player.makeMove(PlayField::CellPos(x, y));
	drawField(player.currentState());
}

void botMove(XOPlayer& player)
{
	player.setNext(maxWin(player.getCurrentTree(), player.selectPlayer()));
	player.makeMove();
	drawField(player.currentState());
}

int main()
{
	PlayField playField;
	TreeNode treeRoot;
	buildSubTree(treeRoot);
	cout << "Select player (0 - O, 1 - X)" << endl;
	int sel_player;
	cin >> sel_player;
	XOPlayer player(treeRoot, (sel_player == 0 ? PlayField::csCross : PlayField::csNought));
	do 
	{
		if (sel_player == 0)
		{
			playerMove(player);
			if (player.fieldStatus() != PlayField::fsNormal)
				break;
			botMove(player);
		}
		else
		{
			botMove(player);
			if (player.fieldStatus() != PlayField::fsNormal)
				break;
			playerMove(player);
		}
	} while (player.fieldStatus() == PlayField::fsNormal);
	switch (player.fieldStatus())
	{
	case PlayField::fsNoughtsWin:
		cout << "Noughts Win" << endl;
		break;
	case PlayField::fsCrossesWin:
		cout << "Crosses Win" << endl;
		break;
	case PlayField::fsDraw:
		cout << "Draw" << endl;
		break;
	}
}
