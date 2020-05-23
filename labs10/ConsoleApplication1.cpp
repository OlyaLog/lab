#include "Matrix2D.h"
#include "Matrix3D.h"
#include <iostream>

using namespace std;

void main()
{
	Matrix2D matrix2a, matrix2b;
	Matrix3D matrix3a, matrix3b;
	cout << matrix2a << endl;
	cout << matrix2b << endl;
	matrix2a *= 5;
	cout << matrix2a << endl;
	matrix2a += matrix2b;
	cout << matrix2a << endl;
	cout << matrix3a << endl;
	cout << matrix3b << endl;
	matrix3a *= 5;
	cout << matrix3a << endl;;
	matrix3a += matrix3b;
	cout << matrix3a << endl;
}
