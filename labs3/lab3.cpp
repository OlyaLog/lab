#include <iostream>
#include "BinaryTree.h"

using namespace std;

void CreateMinimalBST(int* begin, int start, int end)
{
	int lenght = end - start + 1;
	int indexHead = start + (lenght / 2);
	BinaryTree* binaryTree = new BinaryTree(begin[indexHead]);
	for (int i = indexHead - 1; i >= start; i--)
		binaryTree->Insert(begin[i]);
	for (int i = indexHead + 1; i <= end; i++)
		binaryTree->Insert(begin[i]);
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
