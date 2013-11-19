#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "node.h"

#ifndef QUEUE_H
#define QUEUE_H

class Queue
{

private:
	node* _front;
	node* _rear;

public:
	Queue();
	~Queue();
	void enqueue(char c);
	char dequeue();
	char front();
	char rear();
	void makenull();
	bool isEmpty();

};

#endif