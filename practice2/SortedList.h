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
	void remove(char id);
	void remove(listnode* pos);
	void printList();
	void printQ(Queue<char*> queue);
	~SortedList();
};

#endif