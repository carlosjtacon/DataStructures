#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

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
			return NULL;
		}
	
		node* tmp;
		tmp = new node;
		int n;

		tmp = top;
		n=tmp->data;
		top=tmp->link;

		delete tmp;
		return n;
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

};
