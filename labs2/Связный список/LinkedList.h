#pragma once
class LinkedList
{
public:
	struct List
	{
		int data;
		List *next;
	};

	List *head;
	void addList(int value);
	void deleteDubl();
	int listLength();
	void search(int k);
	void printList();
};

