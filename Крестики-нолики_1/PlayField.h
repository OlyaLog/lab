#pragma once
#include <vector>
#include <cassert>

using namespace std;

class PlayField
{
public:
	static constexpr int fieldSize = 3;
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
			assert(pos >= 0 || pos < fieldSize * fieldSize);
			return CellPos(pos / fieldSize, pos % fieldSize);
		}

		CellPos(int i, int j)
		{
			assert(i >= 0 || j >= 0 || i <= fieldSize - 1 || j <= fieldSize - 1);
			x = i;
			y = j;
		}

		int GetPos() { return x * fieldSize + y; }
		int GetX() { return x; }
		int GetY() { return y; }

	private:
		int x;
		int y;
	};

	Cells operator[] (CellPos) const;
	vector <CellPos> getEmptyCells();
	Status checkFieldStatus();
	PlayField makeMove(CellPos);
	Cells cellsState[fieldSize * fieldSize]{ csEmpty, csEmpty, csEmpty, csEmpty, csEmpty, csEmpty, csEmpty, csEmpty, csEmpty };

private:
	PlayField operator+ (CellPos);
	Cells newCell = csNought;
	bool checkStatusWin(Cells);
	bool checkHorizontal(Cells);
	bool checkVertical(Cells);
	bool checkDiagonals(Cells);
};