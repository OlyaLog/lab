#pragma once
#include <iostream>

using namespace std;



class Matrix3x3
{
public:
	Matrix3x3()
	{
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				matrix[i][j] = 0;
	}
	static const int size = 3;
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
	int matrix[size][size];
};
