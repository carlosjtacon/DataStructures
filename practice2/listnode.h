#include "queue.h"
#include "string.h"

#ifndef LISTNODE_H
#define LISTNODE_H

struct listnode
{
	Queue<char*> data;
	listnode* next;
	listnode* prev;
};

#endif