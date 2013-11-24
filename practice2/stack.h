#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "node.h"

#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack
{
private:
	node<T>* top;

public:
	Stack();
	bool isEmpty();
	void push(int n);
	T pop();
	T getTop();
	void makeNull();
	~Stack();
};

#endif