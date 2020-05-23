#include "MatrixBase.h"

void MatrixBase::operator*=(int iMult)
{
	for (int i = 0; i < m_size; i++)
		for (int j = 0; j < m_size; j++)
			this->element(i, j) *= iMult;
}

void MatrixBase::operator+=(MatrixBase & iAdd)
{
	for (int i = 0; i < m_size; i++)
		for (int j = 0; j < m_size; j++)
			this->element(i, j) += iAdd.element(i,j);
}

std::ostream & operator<<(std::ostream & stream, const MatrixBase & iMatrix)
{
	for (int i = 0; i < iMatrix.size(); i++)
	{
		stream << " ";
		for (int j = 0; j < iMatrix.size(); j++)
		{
			stream << iMatrix.element(i, j) << " ";
			if (iMatrix.element(i, j) < 10)
				stream << "  ";
			else if (iMatrix.element(i, j) > 9 && iMatrix.element(i, j) < 100)
				stream << " ";
		}
		stream << std::endl;
	}
	return stream;
}
