#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "nodestring.h"

#ifndef QUEUESTRING_H
#define QUEUESTRING_H

class Queuestring
{

private:
	nodestring* _front;
	nodestring* _rear;

public:
	Queuestring();
	~Queuestring();
	void enqueue(string c);
	string dequeue();
	string front();
	string rear();
	void makenull();
	bool isEmpty();

};

#endif