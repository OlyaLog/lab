#include <iostream>
#include <string>
#include "XOPlayer.h"

using namespace std;

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

void walkTree(TreeNode& treeNode)
{
	if (treeNode.isTerminal())
	{
		TreeNode::Result result;
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
		treeNode.addResult(result);
		return;
	}
	for (int i = 0; i < treeNode.childCount(); i++)
	{
		walkTree(treeNode[i]);
	}
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

int main()
{
	PlayField playField;
	TreeNode treeRoot;
	buildSubTree(treeRoot);
	walkTree(treeRoot);
	cout << "Select player (0 - O, 1 - X)" << endl;
	int sel_player;
	cin >> sel_player;
	XOPlayer player(treeRoot, (sel_player == 0 ? PlayField::csNought : PlayField::csCross));
	do 
	{
		if (sel_player == 0)
		{
			playerMove(player);
			if (player.fieldStatus() != PlayField::fsNormal)
				break;
			player.makeMove();
			drawField(player.currentState());
		}
		else
		{
			player.makeMove();
			drawField(player.currentState());
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
