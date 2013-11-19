#include "queueString.h"
using namespace std;


QueueString::QueueString()
{
	makenull();
}
QueueString::~QueueString()
{
	nodeString* tmp;
	while(!isEmpty())
	{
		tmp=_front;
		_front=_front->next;
		delete tmp;
	}
}

void QueueString::enqueue(string s)	//Insert an element at the rear of the queue
{
	nodeString* _current;
	_current= new nodeString;
	_current->next=NULL;
	_current->data=s;

	if (isEmpty())
	{
		_front=_current;
		_rear=_current;
	}
	else if (!isEmpty())
	{
		_rear->next= _current;
		_rear=_current;
	}
}

string QueueString::dequeue()	//Delete the element at the front of queue (and return it)
{
	string rt=_front -> data;

	nodeString* _current;

	if (!isEmpty())
	{
		_current=_front;
        _front=_front->next;
		delete _current;
	}
	return rt;
}

string QueueString::front()	//Return the element at the front of the queue
{
	return _front -> data;
}

string QueueString::rear()	//Return the element at the rear of the queue
{
	return _rear -> data;
}

void QueueString::makenull()	//Make the queue to be an empty queue
{
	_front = NULL;
	_rear = _front;
}

bool QueueString::isEmpty()	//Return true if the queue is empty, return false otherwise
{
	return (_front == NULL);
}

