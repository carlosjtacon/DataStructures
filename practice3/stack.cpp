#include "stack.h"
using namespace std;

template <typename T>
Stack<T>::Stack()
{
	//constructor
	makeNull();
}

template <typename T>
Stack<T>::~Stack()
{
	//some like garbage collector
	if (top==NULL)
		return;

	node<T> *tmp;
	while	(top!=NULL)
	{
		tmp=top;
		top=top->next;
		delete tmp;
	}
}

template <typename T>
bool Stack<T>::isEmpty()
{
	//return true if is empty, if top is null then the stack isEmpty
	return (top == NULL);
}

template <typename T>
void Stack<T>::push(int n)
{
	//add an element to the stack
	node<T>* tmp;
	tmp = new node<T>;

	if (tmp==NULL)
	{
		cout << "\nStack FULL";
		return;
	}
	tmp->data = n;	
	tmp->next=top;

	top=tmp;
}

template <typename T>
T Stack<T>::pop()
{
	//take the element of the stack and delete it
	if (top==NULL)
	{
		cout <<"\nStack empty" ;
		return '\0';
	}

	node<T>* tmp;
	tmp = new node<T>;
	T value;

	tmp = top;
	value=tmp->data;
	top=tmp->next;

	delete tmp;
	return value;
}

template <typename T>
T Stack<T>::getTop()
{
	//return top content
	return top -> data;
}

template <typename T>
void Stack<T>::makeNull()
{
	//create a new empty stack
	top = NULL;
}


