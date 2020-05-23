#include "Matrix2D.h"

Matrix2D::Matrix2D(): MatrixBase(size)
{
	int count = 1;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			matrix2D[i][j] = count;
			count++;
		}
	}
}
