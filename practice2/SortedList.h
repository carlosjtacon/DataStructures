#include "listnode.h"
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include "queue.h"
#include <sstream>

#ifndef SORTEDLIST_H
#define SORTEDLIST_H

class SortedList
{
private:
	listnode* header;

public:
	SortedList();	
	bool isEmpty();
	void insert(string input);
	void insertP(string input);
	int remove(char id);
	void remove(listnode* pos);
	string toString();
	~SortedList();
};

#endif