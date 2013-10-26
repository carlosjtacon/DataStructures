#include "stack.h"
using namespace std;

Stack()
{
	top=NULL;
}

bool isEmpty(){
	return (top == NULL);
}

void push(int n)
{
	node* tmp;
	tmp = new node;

	if (tmp==NULL)
		cout << "\nStack FULL";
	tmp->data = n;	
	tmp->link=top;

	top=tmp;
}

char pop(){

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
	top=tmp->link;

	delete tmp;
	return value;
}

~Stack(){

	if (top==NULL)
	
		return;

		node *tmp;
		while	(top!=NULL)
		{
			tmp=top;
			top=top->link;
			delete tmp;
		}
	}


