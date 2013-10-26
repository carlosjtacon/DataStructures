#include "queue.h"
using namespace std;


Queue::Queue()
{
	_front = NULL;
	_rear = _front;
}
Queue::~Queue()
{
		/*destructor*/
}

void Queue::enqueue(char c)	//Insert an element at the rear of the queue
{
	_current= new queueNode;
	_current->next=NULL;

	if (_front==NULL)
	{
		_front=_current;
		_rear=_front;
	}
	else if (_front!=NULL)
	{
		_rear->next=_current;
		_rear=_current;
	}
}

char Queue::dequeue()	//Delete the element at the front of queue (and return it)
{
	if (_front!=NULL)
	{
		_current=_front;
		_front=_current->next;
	}
	return _current -> data;
}

char Queue::front()	//Return the element at the front of the queue
{
	return _front -> data;
}

char Queue::rear()	//Return the element at the rear of the queue
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
	return (_front == _rear);
}

