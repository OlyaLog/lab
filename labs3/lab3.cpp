#include <iostream>
#include "BinaryTree.h"

using namespace std;

BinaryTree* binaryTree;

void CreateMinimalBST(int* begin, int start, int end)
{
	int middle = (start + end) / 2;
	while (middle > start)
	{
		if (!binaryTree->Search(begin[--middle]))
			binaryTree->Insert(begin[middle]);
		CreateMinimalBST(begin, start, middle);
	}
	while (middle < end)
	{
		if (!binaryTree->Search(begin[++middle]))
			binaryTree->Insert(begin[middle]);
		CreateMinimalBST(begin, middle, end);
	}
}

int main()
{
	int arr[] = {5, 6, 7, 8, 9, 10, 11, 12};
	int* beginArr = begin(arr);
	int start = 2;
	int end = 7;
	binaryTree = new BinaryTree(beginArr[(start + end) / 2]);
	CreateMinimalBST(beginArr, start, end);
	for (int i = start; i <= end; i++)
	{
		cout << binaryTree->Search(beginArr[i])->getValue() << endl;
	}
}
