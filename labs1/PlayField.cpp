#include "PlayField.h"
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

vector < PlayField::CellPos > PlayField::getEmptyCells()
{
	vector<CellPos> emptyCell;
	for (int i = 0; i < 9; i++)
	{
		if (cellsState[i] == csEmpty)
		{
			CellPos cell = CellPos::GetCellPos(i);
			emptyCell.push_back(cell);
		}
	}
	return emptyCell;
}

PlayField PlayField::makeMove(CellPos cellPos)
{
	if (newCell == PlayField::csNought)
		newCell = PlayField::csCross;
	else newCell = PlayField::csNought;
	PlayField field = *this;
	assert(cellsState[cellPos.GetPos()] == csEmpty || checkFieldStatus() == fsNormal);
	field.cellsState[cellPos.GetPos()] = newCell;
	return field;
}

PlayField::Status PlayField::checkFieldStatus()
{
	for (int i = 0; i < 3; i++)
	{
		if (cellsState[i] == cellsState[i + 3] && cellsState[i] == cellsState[i + 6] && cellsState[i] != csEmpty)
		{
			if (cellsState[i] == csCross)
				return fsCrossesWin;
			return fsNoughtsWin;
		}
		if (cellsState[i * 3] == cellsState[1 + i * 3] && cellsState[i * 3] == cellsState[2 + i * 3] && cellsState[i * 3] != csEmpty)
		{
			if (cellsState[i] == csCross)
				return fsCrossesWin;
			return fsNoughtsWin;
		}
		if (i == 0 && cellsState[i] == cellsState[i+4] && cellsState[i] == cellsState[i+8] && cellsState[i] != csEmpty 
			|| i == 2 && cellsState[i] == cellsState[i + 2] && cellsState[i] == cellsState[i + 4] && cellsState[i] != csEmpty)
		{
			if (cellsState[i] == csCross)
				return fsCrossesWin;
			return fsNoughtsWin;
		}
	}
	if (getEmptyCells().empty())
		return fsDraw;
	int cross = 0;
	int nought = 0;
	for (int i = 0; i < 9; i++)
	{
		if (operator[](CellPos::GetCellPos(i)) == csCross)
			cross++;
		if (operator[](CellPos::GetCellPos(i)) == csNought)
			nought++;
	}
	if (abs(cross - nought) > 1)
		return fsInvalid;
	return fsNormal;
}

PlayField::Cells PlayField::operator[](CellPos cellPos)
{
	return cellsState[cellPos.GetPos()];
}

PlayField PlayField::operator+(CellPos cellPos)
{
	makeMove(cellPos);
	return *this;
}