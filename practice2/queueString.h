#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "nodeString.h"

using namespace std;

#ifndef QUEUESTRING_H
#define QUEUESTRING_H

class QueueString
{

private:
	nodeString* _front;
	nodeString* _rear;

public:
	QueueString();
	~QueueString();
	void enqueue(string s);
	string dequeue();
	string front();
	string rear();
	void makenull();
	bool isEmpty();

};

#endif