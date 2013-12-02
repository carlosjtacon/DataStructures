#include "queuestring.h"
#include "string.h"

#ifndef LISTNODE_H
#define LISTNODE_H

struct listnode
{
	Queuestring data;
	listnode* next;
	listnode* prev;
};

#endif