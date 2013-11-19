#include "stack.h"
using namespace std;

Stack::Stack()
{
	makeNull();
}

bool Stack::isEmpty(){
	return (top == NULL);
}

void Stack::push(int n)
{
	node* tmp;
	tmp = new node;

	if (tmp==NULL)
	{
		cout << "\nStack FULL";
		return;
	}
	tmp->data = n;	
	tmp->next=top;

	top=tmp;
}

char Stack::pop(){

	if (top==NULL)
	{
		cout <<"\nStack empty" ;
		return '\0';
	}

	node* tmp;
	tmp = new node;
	char value;

	tmp = top;
	value=tmp->data;
	top=tmp->next;

	delete tmp;
	return value;
}

char Stack::getTop()
{
	return top -> data;
}

void Stack::makeNull()
{
	top = NULL;
}

Stack::~Stack(){

	if (top==NULL)
	
		return;

		node *tmp;
		while	(top!=NULL)
		{
			tmp=top;
			top=top->next;
			delete tmp;
		}
	}


