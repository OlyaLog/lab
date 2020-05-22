#pragma once
#include <cassert>
#include <vector>

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
		CellPos(int i, int j)
		{
			assert(i >= 0 || j >= 0 || i <= fieldSize - 1 || j <= fieldSize - 1);
			x = i;
			y = j;
		}

		int GetPos() const { return x * fieldSize + y; }
		int GetX() const { return x; }
		int GetY() const { return y; }

	private:
		int x;
		int y;
	};

	Cells operator[] (CellPos) const;
	std::vector<CellPos> getEmptyCells() const;
	Status checkFieldStatus() const;
	PlayField makeMove(CellPos);

private:
	PlayField operator+ (CellPos);
	Cells cellsState[fieldSize * fieldSize]{ csEmpty, csEmpty, csEmpty, csEmpty, csEmpty, csEmpty, csEmpty, csEmpty, csEmpty };
	bool checkStatusWin(Cells) const;
	bool checkHorizontal(Cells) const;
	bool checkVertical(Cells) const;
	bool checkDiagonals(Cells) const;
};
