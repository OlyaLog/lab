#include "Matrix3x3.h"
#include <iostream>

using namespace std;

int Matrix3x3::element(const int i, const int j) const
{
	return matrix[i][j];
}

void Matrix3x3::setElement(const int i, const int j, const int value)
{
	matrix[i][j] = value;
}

void Matrix3x3::fillRandomElements(const int minVal, const int maxVal)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			setElement(i, j, rand() % 20 - 10);
}

int Matrix3x3::sumPrincipalDiag() const
{
	return element(0, 0) + element(1, 1) + element(2, 2);
}

int Matrix3x3::sumSecondaryDiag() const
{
	return element(0,2) + element(1,1) + element(2,0);
}

int Matrix3x3::productPrincipalDiag() const
{
	return element(0, 0) * element(1, 1) * element(2, 2);
}

int Matrix3x3::productSecondaryDiag() const
{
	return element(0, 2) * element(1, 1) * element(2, 0);
}

int Matrix3x3::sumRow(const int iRow) const
{
	int sum = 0;
	for (int i = 0; i < 3; i++)
		sum += element(iRow, i);
	return sum;
}

int Matrix3x3::minColumn(const int iCol) const
{
	int min = element(0, iCol);
	for (int i = 1; i < 3; i++)
	{
		if (element(i, iCol) < min)
			min = element(i, iCol);
	}
	return min;
}

int Matrix3x3::maxColumn(const int iCol) const
{
	int max = element(0, iCol);
	for (int i = 1; i < 3; i++)
	{
		if (element(i, iCol) > max)
			max = element(i, iCol);
	}
	return max;
}
