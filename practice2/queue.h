#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "node.h"

using namespace std;

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
	void enqueue(string s);
	string dequeue();
	string front();
	string rear();
	void makenull();
	bool isEmpty();

};

#endif