#pragma once
#include "MatrixBase.h"
#include <cassert>

class Matrix2D :
	public MatrixBase
{
public:
	Matrix2D();
	static constexpr int size = 2;
	int element(unsigned i, unsigned j) const override
	{
		assert(i >= 0 && i < size && j >= 0 && j < size);
		return matrix2D[i][j];
	}
	int& element(unsigned i, unsigned j) override
	{
		assert(i >= 0 && i < size && j >= 0 && j < size);
		return matrix2D[i][j];
	}
private:
	int matrix2D[size][size];
};

