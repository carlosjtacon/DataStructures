#include <iostream>
#include <stdlib.h>
#include <string.h>
//#include "stdafx.h"

using namespace std;
#define maxlen 80;

class stack
{
	char srt1[maxlen];
	int first;
public:
	void clear(void);
	char top(void);
	int empty(void);
	int full(void);
	void push(char chr);
	char pop(void);
};

void stack::clear(void)
{
	first=0;
}

char stack::top(void);
{
	return *str1[first];
}

int stack::empty(void)
{
	return (first==0);
}

int stack::full(void)
{
	return (first==maxlen-1);
}

void stack::push(char chr)
{
	str1[first++]=chr;
}

char stack::pop(void)
{
	return (str1[first--]);
}

int _tmain(int argc, _TCHAR* argv[])
{
	stack mystack;
	char str[11]="0123456789"

	mystack.clear();
	for (int i = 0; (int) i < strlen(str); ++i)
	{
		if (!mystack.full())
			mystack.push(str[i]);
		cout << "Pushing: " << str[i] << endl;
	}

	while(!mystack.empty())
	{
		cout << "Popping: " << mystack.pop();
	}

	return 0;
}