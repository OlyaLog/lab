// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Matrix3x3.h"
#include "MatrixXnX.h"

using namespace std;

int main()
{
	Matrix3x3 matrix;
	matrix.fillRandomElements(-10, 10);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << matrix.element(i, j) <<" ";
		}
		cout << endl;
	}
	for (int i = 0; i < 3; i++)
	{
		cout << "Sum line "<< i + 1 <<" = " << matrix.sumRow(i) << endl;
		cout << "Min column "<< i + 1 <<" = " << matrix.minColumn(i) << endl;
		cout << "Max column " << i + 1 << " = " << matrix.maxColumn(i) << endl;
	}
	cout << "Sum principal diag = " << matrix.sumPrincipalDiag() << endl;
	cout << "Sum secondary diag = " << matrix.sumSecondaryDiag() << endl;
	cout << "Product principal diag = " << matrix.productPrincipalDiag() << endl;
	cout << "Product secondary diag = " << matrix.productSecondaryDiag() << endl;

	MatrixXnX matrix_xn(5);
	matrix_xn.fillRandomElements(-10, 10);
	for (int i = 0; i < matrix_xn.lenght; i++)
	{
		for (int j = 0; j < matrix_xn.lenght; j++)
		{
			cout << matrix_xn.element(i, j) << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < matrix_xn.lenght; i++)
	{
		cout << "Sum line " << i + 1 << " = " << matrix_xn.sumRow(i) << endl;
		cout << "Min column " << i + 1 << " = " << matrix_xn.minColumn(i) << endl;
		cout << "Max column " << i + 1 << " = " << matrix_xn.maxColumn(i) << endl;
	}
	cout << "Sum principal diag = " << matrix_xn.sumPrincipalDiag() << endl;
	cout << "Sum secondary diag = " << matrix_xn.sumSecondaryDiag() << endl;
	cout << "Product principal diag = " << matrix_xn.productPrincipalDiag() << endl;
	cout << "Product secondary diag = " << matrix_xn.productSecondaryDiag() << endl;
}
