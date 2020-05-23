#include "Matrix3D.h"

Matrix3D::Matrix3D() : MatrixBase(size)
{
	int count = 1;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			matrix3D[i][j] = count;
			count++;
		}
	}
}