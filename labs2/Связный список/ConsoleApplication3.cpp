#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
	LinkedList* list = new LinkedList();
	for (int i = 0; i < 5; i++)
		list->addList(i);
	list->addList(4);
	list->addList(1);
	list->addList(3);
	list->printList();
	list->deleteDubl();
	list->printList();
	list->search(3);
}
