#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "node.h"

#ifndef STACK_H
#define STACK_H

class Stack
{
private:
	node* top;

public:
	Stack();
	bool isEmpty();
	void push(int n);
	char pop();
	char getTop();
	void makeNull();
	~Stack();
};

#endif