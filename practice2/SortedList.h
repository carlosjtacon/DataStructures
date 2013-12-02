#include "listnode.h"
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include "queue.h"

#ifndef SORTEDLIST_H
#define SORTEDLIST_H

class SortedList
{
private:
	listnode* header;

public:
	SortedList();	
	listnode* getHeader();
	bool isEmpty();
	void insert(string input);
	void insertP(string input);
	int remove(char id);
	void remove(listnode* pos);
	string toString();
	void printQ(Queue<string> queue);
	~SortedList();
};

#endif