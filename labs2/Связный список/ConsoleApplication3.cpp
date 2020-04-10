#include <iostream>

using namespace std;

struct List
{
	int data;
	List *next;
};

List *head;

void addList(int value)
{
	List *list = new List; 
	list->data = value;
	list->next = nullptr;
	if (head == nullptr)
		head = list;
	else
	{
		List *current = head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = list;
	}
}

void deleteDubl()
{
	List* current = head;
	while (current != nullptr)
	{
		List* nextcurrent = current->next;
		List* prevnext = current;
		while (nextcurrent != nullptr)
		{
			if (current ->data == nextcurrent->data)
			{
				if (nextcurrent->next != nullptr)
				{
					nextcurrent -> data = nextcurrent->next -> data;
					nextcurrent->next = nextcurrent->next->next;
					prevnext = prevnext->next;
				}
				else
				{
					nextcurrent = nullptr;
					prevnext->next = nullptr;
				}
			}
			else
			{
				nextcurrent = nextcurrent->next;
				prevnext = prevnext->next;
			}
		}
		current = current->next;
	}
	
}

int listLength ()
{
	List* current = head;
	int count = 0;
	while (current != nullptr)
	{
		count++;
		current = current->next;
	}
	return count;
}

void search(int k)
{
	List* current = head;
	int count = listLength();
	for (int i = count - 1; i > count - k; i--)
		current = current->next;
	cout << current->data << endl;
}

void printList()
{
	List *current = head;
	while (current != nullptr)
	{
		cout << current->data << endl;
		current = current->next;
	}
	cout << endl;
}

int main()
{
	for (int i = 0; i < 5; i++)
		addList(i);
	addList(4);
	addList(1);
	addList(3);
	printList();
	deleteDubl();
	printList();
	search(3);
}
