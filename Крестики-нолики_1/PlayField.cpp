#include "PlayField.h"
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

vector < PlayField::CellPos > PlayField::getEmptyCells()
{
	vector<CellPos> emptyCell;
	for (int i = 0; i < fieldSize * fieldSize; i++)
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

bool PlayField::checkHorizontal(Cells cell)
{
	for (int i = 0; i < fieldSize; i++)
	{
		return cellsState[i * 3] == cellsState[1 + i * 3] && cellsState[i * 3] == cellsState[2 + i * 3] && cellsState[i * 3] == cell;
	}
}

bool PlayField::checkVertical(Cells cell)
{
	for (int i = 0; i < fieldSize; i++)
	{
		return cellsState[i] == cellsState[i + 3] && cellsState[i] == cellsState[i + 6] && cellsState[i] == cell;
	}
}

bool PlayField::checkDiagonals(Cells cell)
{
	return cellsState[0] == cellsState[fieldSize + 1] && cellsState[0] == cellsState[fieldSize * fieldSize - 1] && cellsState[0] == cell ||
		cellsState[fieldSize - 1] == cellsState[fieldSize + 1] && cellsState[fieldSize - 1] == cellsState[fieldSize * 2] && cellsState[fieldSize - 1] == cell;
}

bool PlayField::checkStatusWin(Cells cell)
{
	if (checkHorizontal(cell))
		return true;
	if (checkVertical(cell))
		return true;
	if (checkDiagonals(cell))
		return true;
}

PlayField::Status PlayField::checkFieldStatus()
{
	if (checkStatusWin(csCross))
		return fsCrossesWin;
	if (checkStatusWin(csNought))
		return fsNoughtsWin;
	if (getEmptyCells().empty())
		return fsDraw;
	int cross = 0;
	int nought = 0;
	for (int i = 0; i < fieldSize * fieldSize; i++)
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

PlayField::Cells PlayField::operator[](CellPos cellPos) const
{
	return cellsState[cellPos.GetPos()];
}

PlayField PlayField::operator+(CellPos cellPos)
{
	makeMove(cellPos);
	return *this;
}