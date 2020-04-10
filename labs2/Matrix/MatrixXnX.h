#pragma once
#include <iostream>

using namespace std;

class MatrixXnX
{
public:
	MatrixXnX(const int iDim)
	{
		matrix = new int*[iDim];
		for (int i = 0; i < iDim; i++)
			matrix[i] = new int[iDim];
		for (int i = 0; i < iDim; i++)
			for (int j = 0; j < iDim; j++)
				matrix[i][j] = 0;
		lenght = iDim;
	}
	int lenght;
	int element(const int i, const int j) const;
	void setElement(const int i, const int j, const int value);
	void fillRandomElements(const int minVal, const int maxVal);
	int sumPrincipalDiag() const;
	int sumSecondaryDiag() const;
	int productPrincipalDiag() const;
	int productSecondaryDiag() const;
	int sumRow(const int iRow) const;
	int minColumn(const int iCol) const;
	int maxColumn(const int iCol) const;

private:
	int** matrix;
};