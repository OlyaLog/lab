#pragma once
#include "MatrixBase.h"
class Matrix3D :
	public MatrixBase
{
public:
	Matrix3D();
	static constexpr int size = 3;
	int element(unsigned i, unsigned j) const override { return matrix3D[i][j]; }
	int& element(unsigned i, unsigned j) override { return matrix3D[i][j]; }
private:
	int matrix3D[size][size];
};

