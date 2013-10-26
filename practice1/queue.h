#include <stdlib.h>
#include <string.h>
#include <iostream>

#ifndef QUEUE_H
#define QUEUE_H

struct queueNode
{
	char data;
	queueNode* next;
};

class Queue
{

private:
	queueNode* _front;
	queueNode* _rear;

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