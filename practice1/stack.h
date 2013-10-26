#include <stdlib.h>
#include <string.h>
#include <iostream>

#ifndef STACK_H
#define STACK_H

struct node
{
	char data;
	node *link;
};

class Stack
{
private:
	node* top;

public:
	Stack();
	bool isEmpty();
	void push(int n);
	char pop();
	~Stack();
};

#endif