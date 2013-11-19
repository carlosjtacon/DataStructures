#include "queue.h"
using namespace std;


Queue::Queue()
{
	makenull();
}
Queue::~Queue()
{
	node* tmp;
	while(!isEmpty())
	{
		tmp=_front;
		_front=_front->next;
		delete tmp;
	}
}

void Queue::enqueue(string s)	//Insert an element at the rear of the queue
{
	node* _current;
	_current= new node;
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

string Queue::dequeue()	//Delete the element at the front of queue (and return it)
{
	string rt=_front -> data;

	node* _current;

	if (!isEmpty())
	{
		_current=_front;
        _front=_front->next;
		delete _current;
	}
	return rt;
}

string Queue::front()	//Return the element at the front of the queue
{
	return _front -> data;
}

string Queue::rear()	//Return the element at the rear of the queue
{
	return _rear -> data;
}

void Queue::makenull()	//Make the queue to be an empty queue
{
	_front = NULL;
	_rear = _front;
}

bool Queue::isEmpty()	//Return true if the queue is empty, return false otherwise
{
	return (_front == NULL);
}

