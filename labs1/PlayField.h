#pragma once
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class PlayField
{
public:
	static constexpr int count = 3;
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
			assert(pos >= 0 || pos < count * count);
			int i = 0;
			int j = 0;
			i = pos / count;
			j = pos % count;
			return CellPos(i, j);
		}

		CellPos(int i, int j)
		{
			assert(i >= 0 || j >= 0 || i < count || j < count);
			x = i;
			y = j;
			cellPos = x * count + y;
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
	Cells cellsState[count * count]{ csEmpty, csEmpty, csEmpty, csEmpty, csEmpty, csEmpty, csEmpty, csEmpty, csEmpty };

private:
	PlayField operator+ (CellPos);
	Cells newCell = csNought;
	bool checkStatusWin(Cells);
	bool checkHorizontal(Cells);
	bool checkVertical(Cells);
	bool checkDiagonals(Cells);
};