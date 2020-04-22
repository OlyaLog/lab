#include <iostream>
#include "BinaryTree.h"

using namespace std;

void createLeft(BinaryTree* binaryTree, int* begin, int start, int middle)
{
	if (middle < start)
		return;
	binaryTree->Insert(begin[middle]);
	createLeft(binaryTree, begin, start, --middle);
}

void createRight(BinaryTree* binaryTree, int* begin, int end, int middle)
{
	if (middle > end)
		return;
	binaryTree->Insert(begin[middle]);
	createRight(binaryTree, begin, end, ++middle);
}

void CreateMinimalBST(int* begin, int start, int end)
{
	int lenght = end - start + 1;
	int indexHead = start + (lenght / 2);
	BinaryTree* binaryTree = new BinaryTree(begin[indexHead]);
	createLeft(binaryTree, begin, start, --indexHead);
	createRight(binaryTree, begin, end, ++indexHead);
	for (int i = start; i < end; i++)
	{
		cout << binaryTree->Search(begin[i])->getValue() << endl;
	}
}

int main()
{
	int arr[] = {5, 6, 7, 8, 9, 10, 11, 12};
	int* beginArr = begin(arr);
	int start = 2;
	int end = 8;
	CreateMinimalBST(beginArr, start, end);
}
