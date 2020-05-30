#include "PlayField.h"
#include <cassert>

using namespace std;

PlayField::CellPos::CellPos(int i, int j)
{
	assert(i >= 0 && j >= 0 && i <= fieldSize - 1 && j <= fieldSize - 1);
	x = i;
	y = j;
}

vector<PlayField::CellPos> PlayField::getEmptyCells() const
{
	vector<CellPos> emptyCell;
	for (int i = 0; i < fieldSize; i++)
	{
		for (int j = 0; j < fieldSize; j++)
		{
			if (cellsState[CellPos(i,j).GetPos()] == csEmpty)
			{
				CellPos cell = CellPos(i,j);
				emptyCell.push_back(cell);
			}
		}
	}
	return emptyCell;
}

PlayField PlayField::makeMove(CellPos cellPos)
{
	return (*this)+cellPos;
}

bool PlayField::checkHorizontal(Cells cell) const
{
	for (int i = 0; i < fieldSize; i++)
	{
		if (cellsState[i * fieldSize] == cellsState[1 + i * fieldSize] && cellsState[i * fieldSize] == cellsState[2 + i * fieldSize] && cellsState[i * fieldSize] == cell)
			return true;
	}
	return false;
}

bool PlayField::checkVertical(Cells cell) const
{
	for (int i = 0; i < fieldSize; i++)
	{
		if (cellsState[i] == cellsState[i + fieldSize] && cellsState[i] == cellsState[i + 2 * fieldSize] && cellsState[i] == cell)
			return true;
	}
	return false;
}

bool PlayField::checkDiagonals(Cells cell) const
{
	return cellsState[0] == cellsState[fieldSize + 1] && cellsState[0] == cellsState[fieldSize * fieldSize - 1] && cellsState[0] == cell ||
		cellsState[fieldSize - 1] == cellsState[fieldSize + 1] && cellsState[fieldSize - 1] == cellsState[fieldSize * 2] && cellsState[fieldSize - 1] == cell;
}

bool PlayField::checkStatusWin(Cells cell) const
{
	if (checkHorizontal(cell))
		return true;
	if (checkVertical(cell))
		return true;
	if (checkDiagonals(cell))
		return true;
}

PlayField::Status PlayField::checkFieldStatus() const
{
	Status result = fsNormal;
	if (checkStatusWin(csCross))
		result = fsCrossesWin;
	if (checkStatusWin(csNought))
	{
		if (result == fsCrossesWin)
			return fsInvalid;
		return fsNoughtsWin;
	}
	if (getEmptyCells().empty() && result != fsCrossesWin)
		return fsDraw;
	int cross = 0;
	int nought = 0;
	for (int i = 0; i < fieldSize; i++)
	{
		for (int j = 0; j < fieldSize; j++)
		{
			if (operator[](CellPos(i,j)) == csCross)
				cross++;
			if (operator[](CellPos(i,j)) == csNought)
				nought++;
		}
	}
	if (nought - cross > 1 || cross - nought > 0)
		return fsInvalid;
	return result;
}

PlayField::Cells PlayField::operator[](CellPos cellPos) const
{
	return cellsState[cellPos.GetPos()];
}

PlayField PlayField::operator+(CellPos cellPos)
{
	assert(cellsState[cellPos.GetPos()] == csEmpty || checkFieldStatus() == fsNormal);
	Cells newCell;
	int cross = 0;
	int nought = 0;
	for (int i = 0; i < fieldSize; i++)
	{
		for (int j = 0; j < fieldSize; j++)
		{
			if (operator[](CellPos(i, j)) == csCross)
				cross++;
			if (operator[](CellPos(i, j)) == csNought)
				nought++;
		}
	}
	if (nought - cross == 1)
		newCell = csCross;
	else
		newCell = csNought;
	cellsState[cellPos.GetPos()] = newCell;
	return *this;
}
