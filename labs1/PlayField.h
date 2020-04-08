#pragma once
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class PlayField
{
public:
	enum Cells
	{
		csEmpty,
		csCross,
		csNought
	};
	enum Status
	{
		fsInvalid,
		fsNormal,
		fsCrossesWin,
		fsNoughtsWin,
		fsDraw
	};

	class CellPos
	{
	public:
		static CellPos GetCellPos(int pos)
		{
			assert(pos >= 0 || pos <= 8);
			int i = 0;
			int j = 0;
			i = pos / 3;
			j = pos % 3;
			return CellPos(i, j);
		}

		CellPos(int i, int j)
		{
			assert(i >= 0 || j >= 0 || i <= 2 || j <= 2);
			x = i;
			y = j;
			cellPos = x * 3 + y;
		}

		int GetPos() { return cellPos; }
		int GetX() { return x; }
		int GetY() { return y; }

	private:
		int x;
		int y;
		int cellPos;
	};

	Cells operator[] (CellPos);
	vector <CellPos> getEmptyCells();
	Status checkFieldStatus();
	PlayField makeMove(CellPos);
	Cells cellsState[9]{ csEmpty,csEmpty,csEmpty,csEmpty,csEmpty,csEmpty,csEmpty,csEmpty,csEmpty };

private:
	PlayField operator+ (CellPos);
	Cells newCell = csNought;
};