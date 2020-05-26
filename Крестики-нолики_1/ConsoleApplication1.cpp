#include <iostream>
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

int main()
{
	PlayField playField;
	TreeNode treeRoot = TreeNode(playField, nullptr);
	buildSubTree(treeRoot);
	Result total = { 0,0,0 };
	for (int i = 0; i < treeRoot.childCount(); i++)
	{
		Result result = { 0,0,0 };
		drawField(treeRoot[i].value());
		walkTree(treeRoot[i], result);
		cout << "Nought win: " << result.noughtWinCount << endl;
		cout << "Cross win: " << result.crossWinCount << endl;
		cout << "Drow: " << result.drawCount << endl;
		total += result;
	}
	cout << "Total: " << endl;
	cout << "Nought win: " << total.noughtWinCount << endl;
	cout << "Cross win: " << total.crossWinCount << endl;
	cout << "Drow: " << total.drawCount << endl;
}
