#pragma once
#include "MatrixBase.h"

class Matrix2D :
	public MatrixBase
{
public:
	Matrix2D();
	static constexpr int size = 2;
	int element(unsigned i, unsigned j) const override { return this->matrix2D[i][j]; }
	int& element(unsigned i, unsigned j) override { return this->matrix2D[i][j]; }
	
private:
	int matrix2D[size][size];
};