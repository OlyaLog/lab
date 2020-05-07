// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include "PlayField.h"
#include "TreeNode.h"
#include <string>

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
Result total;

void drawCell(PlayField:: Cells cell)
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
	for (int i = 0; i < PlayField::count; i++)
	{
		for (int j = 0; j < PlayField::count; j++)
		{
			drawCell(playField.cellsState[PlayField::CellPos(i, j).GetPos()]);
		}
		cout << " | " << endl;
		cout << " -------------" << endl;
	}
}

void walkTree(TreeNode treeNode, PlayField playField, PlayField::Cells newCell);

int buildTree(PlayField playField, TreeNode treeNode)
{
	if (!treeNode.isTerminal(treeNode))
	{
		if (treeNode.GetChild(treeNode) % 2 == 0)
			walkTree(treeNode, playField, PlayField::Cells::csNought);
		else walkTree(treeNode, playField, PlayField::Cells::csCross);
	}
	else
	{
		PlayField newField = treeNode.value(treeNode);
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
			return 0;
		}
	}
}

void walkTree(TreeNode treeNode, PlayField playField, PlayField::Cells newCell)
{
	for (int i = 0; i < 9; i++)
	{
		PlayField newField = treeNode.value(treeNode);
		if (newField.cellsState[i] == PlayField::Cells::csEmpty)
		{
			PlayField move = newField.makeMove(PlayField::CellPos::GetCellPos(i));
			TreeNode childNode = TreeNode(move, &treeNode);
			treeNode.addChild(&treeNode, &childNode);
			buildTree(newField, childNode);
		}
	}
}

int main()
{
	PlayField playField;
	for (int i = 0; i < PlayField::count * PlayField::count; i++)
	{
		playField.cellsState[i] = PlayField::csNought;
		drawField(playField);
		TreeNode treeRoot = TreeNode(playField, nullptr);
		buildTree(playField, treeRoot);
		cout << "Nought win: " << result.noughtWinCount << endl;
		cout << "Cross win: " << result.crossWinCount << endl;
		cout << "Drow: " << result.drawCount << endl;
		playField.cellsState[i] = PlayField::csEmpty;
		total += result;
		result = { 0, 0,0 };
	}
	cout << "Total: " << endl;
	cout << "Nought win: " << total.noughtWinCount << endl;
	cout << "Cross win: " << total.crossWinCount << endl;
	cout << "Drow: " << total.drawCount << endl;
}
