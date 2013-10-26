#include <stdlib.h>
#include <string.h>
#include <iostream>

#ifndef STACK_H
#define STACK_H

struct stackNode
{
	char data;
	stackNode *link;
};

class Stack
{
private:
	stackNode* top;

public:
	Stack();
	bool isEmpty();
	void push(int n);
	char pop();
	~Stack();
};

#endif