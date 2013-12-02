#include "listnode.h"
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include "Sortedlist.h"
#include "queuestring.h"

int main()
{
	SortedList list = SortedList();
	string str1 = "ala";
	string str2 = "ela";
	string str3 = "ila";
	string str4 = "ola";
	string str5 = "oco";
	list.insert(str1);
	list.insert(str2);
	list.insert(str3);
	list.insert(str4);
	list.insert(str5);
	list.printList();
	//list.remove('e');
	//list.printList();

	return 0;
}