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

/* we need to include the implementation code in stack.cpp because we are using structures
and we only need to have the header file, but it is more clear to have the implemetation 
in other file even if we dont need it, this is the reason to include the .cpp */
#include "stack.cpp"

#endif