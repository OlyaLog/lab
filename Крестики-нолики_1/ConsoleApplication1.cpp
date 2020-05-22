﻿#include <iostream>
#include <string>
#include "TreeNode.h"

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

Result result;

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

void walkTree(TreeNode& treeNode);

void buildSubTree(TreeNode& treeNode)
{
	if (!treeNode.isTerminal())
	{
		walkTree(treeNode);
	}
	else
	{
		PlayField newField = treeNode.value();
		if (newField.checkFieldStatus() != PlayField::fsNormal)
		{
			switch (newField.checkFieldStatus())
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
	}
}

void walkTree(TreeNode& treeNode)
{
	for (int i = 0; i < PlayField::fieldSize; i++)
	{
		for (int j = 0; j < PlayField::fieldSize; j++)
		{
			PlayField newField = treeNode.value();
			PlayField::CellPos pos = PlayField::CellPos(i, j);
			for (auto empty: newField.getEmptyCells())
			{
				if (empty.GetPos() == pos.GetPos())
				{
					PlayField move = newField.makeMove(pos);
					TreeNode childNode = TreeNode(move, &treeNode);
					buildSubTree(childNode);
				}
			}
		}
	}
}

int main()
{
	Result total = {0,0,0};
	for (int i = 0; i < PlayField::fieldSize; i++)
	{
		for (int j = 0; j < PlayField::fieldSize; j++)
		{
			PlayField playField;
			playField.makeMove(PlayField::CellPos(i, j));
			drawField(playField);
			TreeNode treeRoot = TreeNode(playField, nullptr);
			buildSubTree(treeRoot);
			cout << "Nought win: " << result.noughtWinCount << endl;
			cout << "Cross win: " << result.crossWinCount << endl;
			cout << "Drow: " << result.drawCount << endl;
			total += result;
			result = { 0, 0,0 };
		}
	}
	cout << "Total: " << endl;
	cout << "Nought win: " << total.noughtWinCount << endl;
	cout << "Cross win: " << total.crossWinCount << endl;
	cout << "Drow: " << total.drawCount << endl;
}
