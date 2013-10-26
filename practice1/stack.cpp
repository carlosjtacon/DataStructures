#include "stack.h"
using namespace std;

Stack::Stack()
{
	top=NULL;
}

bool Stack::isEmpty(){
	return (top == NULL);
}

void Stack::push(int n)
{
	stackNode* tmp;
	tmp = new stackNode;

	if (tmp==NULL)
		cout << "\nStack FULL";
	tmp->data = n;	
	tmp->link=top;

	top=tmp;
}

char Stack::pop(){

	if (top==NULL)
	{
		cout <<"\nStack empty" ;
		return '\0';
	}

	stackNode* tmp;
	tmp = new stackNode;
	char value;

	tmp = top;
	value=tmp->data;
	top=tmp->link;

	delete tmp;
	return value;
}

Stack::~Stack(){

	if (top==NULL)
	
		return;

		stackNode *tmp;
		while	(top!=NULL)
		{
			tmp=top;
			top=top->link;
			delete tmp;
		}
	}


