#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "node.h"

#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class Queue
{

private:
	node<T>* _front;
	node<T>* _rear;

public:
	Queue();
	~Queue();
	void enqueue(T c);
	T dequeue();
	T front();
	T rear();
	void makenull();
	bool isEmpty();
};

#endif