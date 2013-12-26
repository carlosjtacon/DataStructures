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
	int size();
};

/* we need to include the implementation code in queue.cpp because we are using structures
and we only need to have the header file, but it is more clear to have the implemetation 
in other file even if we dont need it, this is the reason to include the .cpp */
#include "queue.cpp"

#endif