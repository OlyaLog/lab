#include "MatrixXnX.h"

int MatrixXnX::element(const int i, const int j) const
{
	return matrix[i][j];
}

void MatrixXnX::setElement(const int i, const int j, const int value)
{
	matrix[i][j] = value;
}

void MatrixXnX::fillRandomElements(const int minVal, const int maxVal)
{
	for (int i = 0; i < lenght; i++)
		for (int j = 0; j < lenght; j++)
			setElement(i, j, rand() % 20 - 10);
}

int MatrixXnX::sumPrincipalDiag() const
{
	int sum = 0;
	for (int i = 0; i < lenght; i++)
		sum += element(i, i);
	return sum;
}

int MatrixXnX::sumSecondaryDiag() const
{
	int sum = 0;
	for (int i = 0; i < lenght; i++)
		sum += element(i, lenght - 1 - i);
	return sum;
}

int MatrixXnX::productPrincipalDiag() const
{
	int product = 1;
	for (int i = 0; i < lenght; i++)
		product *= element(i, i);
	return product;
}

int MatrixXnX::productSecondaryDiag() const
{
	int product = 1;
	for (int i = 0; i < lenght; i++)
		product *= element(i, lenght - 1 - i);
	return product;
}

int MatrixXnX::sumRow(const int iRow) const
{
	int sum = 0;
	for (int i = 0; i < lenght; i++)
		sum += element(iRow, i);
	return sum;
}

int MatrixXnX::minColumn(const int iCol) const
{
	int min = element(0, iCol);
	for (int i = 1; i < lenght; i++)
	{
		if (element(i, iCol) < min)
			min = element(i, iCol);
	}
	return min;
}

int MatrixXnX::maxColumn(const int iCol) const
{
	int max = element(0, iCol);
	for (int i = 1; i < lenght; i++)
	{
		if (element(i, iCol) > max)
			max = element(i, iCol);
	}
	return max;
}
