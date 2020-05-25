#pragma once
#include "MatrixBase.h"
#include <cassert>

class Matrix3D :
	public MatrixBase
{
public:
	Matrix3D();
	static constexpr int size = 3;
	int element(unsigned i, unsigned j) const override
	{
		assert(i >= 0 && i < size && j >= 0 && j < size);
		return matrix3D[i][j];
	}
	int& element(unsigned i, unsigned j) override
	{
		assert(i >= 0 && i < size && j >= 0 && j < size);
		return matrix3D[i][j];
	}
private:
	int matrix3D[size][size];
};

