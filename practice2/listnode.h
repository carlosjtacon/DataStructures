#include "queue.h"

#ifndef LISTNODE_H
#define LISTNODE_H

struct listnode
{
	Queue data;
	*listnode next;
	*listnode prev;
};

#endif