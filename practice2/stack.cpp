#include "stack.h"
using namespace std;

template <typename T>
Stack<T>::Stack()
{
	makeNull();
}

template <typename T>
bool Stack<T>::isEmpty(){
	return (top == NULL);
}

template <typename T>
void Stack<T>::push(int n)
{
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
T Stack<T>::pop(){

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
	return top -> data;
}

template <typename T>
void Stack<T>::makeNull()
{
	top = NULL;
}

template <typename T>
Stack<T>::~Stack(){

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


