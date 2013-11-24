#include "queue.h"
using namespace std;

template <typename T>
Queue<T>::Queue()
{
	makenull();
}

template <typename T>
Queue<T>::~Queue()
{
	node<T>* tmp;
	while(!isEmpty())
	{
		tmp=_front;
		_front=_front->next;
		delete tmp;
	}
}

template <typename T>
void Queue<T>::enqueue(T c)	//Insert an element at the rear of the queue
{
	node<T>* _current;
	_current= new node<T>;
	_current->next=NULL;
	_current->data=c;

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

template <typename T>
T Queue<T>::dequeue()	//Delete the element at the front of queue (and return it)
{
	T rt=_front -> data;

	node<T>* _current;

	if (!isEmpty())
	{
		_current=_front;
        _front=_front->next;
		delete _current;
	}
	return rt;
}

template <typename T>
T Queue<T>::front()	//Return the element at the front of the queue
{
	return _front -> data;
}

template <typename T>
T Queue<T>::rear()	//Return the element at the rear of the queue
{
	return _rear -> data;
}

template <typename T>
void Queue<T>::makenull()	//Make the queue to be an empty queue
{
	_front = NULL;
	_rear = _front;
}

template <typename T>
bool Queue<T>::isEmpty()	//Return true if the queue is empty, return false otherwise
{
	return (_front == NULL);
}

