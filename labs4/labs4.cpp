#include <iostream>
#include <ctime>

using namespace std;

static constexpr int Nsearch = 10000;
static constexpr int Nsort = 100;

int Search(int* array, int value)
{
	for (int i = 0; i < Nsearch; i++)
	{
		if (array[i] == value)
			return i;
	}
	return -1;
}

void QuickSort(int* begin, int start, int end)
{
	int middle = begin[(end + start) / 2];
	int left = start;
	int right = end;
	while (left < right)
	{
		while (begin[left] < middle)
			left++;
		while (middle < begin[right])
			right--;
		if (left <= right)
		{
			int count = begin[left];
			begin[left] = begin[right];
			begin[right] = count;
			left++;
			right--;
		}
	}
	if (start < right)
		QuickSort(begin, start, right);
	if (left < end)
		QuickSort(begin, left, end);
}

void QuickSort1(int* begin, int start, int end)
{
	int middle;
	int left = start;
	int right = end;
	while (left <= right)
	{
		middle = (left + right) / 2;
		while (begin[left] < begin[middle])
			left++;
		while (begin[middle] < begin[right])
			right--;
		if (left <= right)
		{
			int count = begin[left];
			begin[left] = begin[right];
			begin[right] = count;
			left++;
			right--;
		}
		if (start < right)
			left = start;
		else if (left < end)
		{
			right = end;
			start++;
		}
	}
}

int BSearch(int value, int* array, int left, int right)
{
	int middle;
	while (left <= right)
	{
		middle = (right + left)/ 2;
		if (value == array[middle])
			return middle;
		if (value < array[middle])
			right = middle - 1;
		else left = middle + 1;
	}
	return -1;
}

int BSearch1(int value, int* array, int left, int right)
{
	int middle = (left + right) / 2;
	if (value == array[middle])
		return middle;
	if (value < array[middle])
		right = middle - 1;
	else left = middle + 1;
	if (left <= right)
		BSearch1(value, array, left, right);
	else
		return -1;
}

int main()
{
	int arraySearch[Nsearch];
	for (int i = 0; i < Nsearch; i++)
		arraySearch[i] = rand() % 1999 - 999;
	int valueSearch;
	cout << "Value: ";
	cin >> valueSearch;
	srand(time(0));
	int search = Search(arraySearch, valueSearch);
	double timeSearch = clock() / 1000.0;
	if (search == -1)
		cout << "This value does not exist" << endl;
	else 
		cout << arraySearch[search] << endl;
	cout << "Runtime = " << timeSearch << endl;
	
	int arraySort[Nsort];
	for (int i = 0; i < Nsort; i++)
		arraySort[i] = rand() % 19 - 9;
	for (int i = 0; i < Nsort / 2; i++)
		cout << arraySort[i] << " ";
	cout << endl;
	int* beginArr = begin(arraySort);
	int start = 0;
	int end = Nsort - 1;
	QuickSort(beginArr, start, end);
	for (int i = 0; i < Nsort / 2; i++)
		cout << arraySort[i] << " ";
	cout << endl;

	for (int i = 0; i < Nsort; i++)
		arraySort[i] = rand() % 19 - 9;
	for (int i = 0; i < Nsort / 2 ; i++)
		cout << arraySort[i] << " ";
	cout << endl;
	int* beginArr1 = begin(arraySort);
	QuickSort1(beginArr1, start, end);
	for (int i = 0; i < Nsort / 2; i++)
		cout << arraySort[i] << " ";
	cout << endl;

	int valueBSearch;
	cout << "Value: ";
	cin >> valueBSearch;
	srand(time(nullptr));
	int bSearch = BSearch(valueBSearch, arraySort, start, end);
	double timeBSearch = clock() / 1000.0;
	if (bSearch == -1)
		cout << "This value does not exist" << endl;
	else
		cout << arraySort[bSearch] << endl;
	cout << "Runtime = " << timeBSearch << endl;

	srand(time(nullptr));
	int bSearch1 = BSearch1(valueBSearch, arraySort, start, end);
	double timeBSearch1 = clock() / 1000.0;
	if (bSearch1 == -1)
		cout << "This value does not exist" << endl;
	else
		cout << arraySort[bSearch1] << endl;
	cout << "Runtime = " << timeBSearch1 << endl;
}
